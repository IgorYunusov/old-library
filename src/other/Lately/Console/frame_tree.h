/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						ULTRIMATE TREE CLASS-STL STYLE
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _FRAME_TREE_
#define _FRAME_TREE_

#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <map>
#include "tree.h"
#include "frame_tool.h"
#include "independent_method.h"

typedef std::map<std::string, ::tree<std::string>::pointer>::value_type map_var;
//typedef map<string, ::tree<string>::pointer>::const_iterator map_iter;

void frame_stdmaketree(tree<std::string>& tree)
{
	std::map<std::string, ::tree<std::string>::pointer> map;
	std::cout << std::endl << "RollRat Standard Treemaker Version 0.0.1110.11" << std::endl;

	char *command_input = (char *) malloc (256);
	for(;;) {
		std::cout << "> ";
		in_command(command_input);
		std::vector<std::string> vec_str_cmd;
		get_command_line(vec_str_cmd, command_input);
		if (vec_str_cmd[0] == "exit") {
			return;
		} else if (vec_str_cmd[0] == "help") {
			std::cout << "pl/pr [x] : left/right에 x를 삽입" << std::endl <<
					"mhl/mhr [x] : make_head_left/make_head_right후 x를 삽입" << std::endl <<
					"il/ir : left/right요소로 포인터 이동" << std::endl <<
					"idr/idl : left/right의 최하단요소로 포인터 이동" << std::endl <<
					"is : 모든 존재여부 확인(left, right, data, parent, ground)" << std::endl <<
					"esc : escape명령" << std::endl <<
					"gnd : gound명령" << std::endl <<
					"dsl/dsr/dsrl : data swap 도구" << std::endl <<
					"srl : 포인터 swap 도구" << std::endl <<
					"dlt/drt (s) : 트리를 때어내어 table에 넣는다.(s필수)" << std::endl <<
					"alt/art (s) : 때어낸 트리를 붙인다." << std::endl <<
					"dl/dr/al/ar : 트리를 때어내어 임시저장소에 저장하거나 붙인다." << std::endl <<
					"ts : this에 요소를 삽입한다." << std::endl <<
					"chkh : 테이블에 들어간 요소의 목록을 보여준다." << std::endl <<
					//"cald : 트리에 추상 깊이를 계산한다." << endl <<
					"chkd : left right this의 정보를 보여준다." << std::endl <<
					"in/post/pre : 중위, 후위, 전위로 순회한 결과를 보여준다." << std::endl <<
					"im [x] : x식을 분석합니다(트리 삭제후 이 트리를 대입함)." << std::endl;
		} else if (vec_str_cmd[0] == "pl") {
			if (vec_str_cmd.size() > 1) tree.push_left(vec_str_cmd[1]);
			else tree.push_left();
		} else if (vec_str_cmd[0] == "pr") {
			if (vec_str_cmd.size() > 1) tree.push_right(vec_str_cmd[1]);
			else tree.push_right();
		} else if (vec_str_cmd[0] == "mhl") {
			if (vec_str_cmd.size() > 1) tree.make_head_left(vec_str_cmd[1]);
			else tree.make_head_left();
		} else if (vec_str_cmd[0] == "mhr") {
			if (vec_str_cmd.size() > 1) tree.make_head_right(vec_str_cmd[1]);
			else tree.make_head_right();
		} else if (vec_str_cmd[0] == "il") {
			if(!tree.into_left())
				std::cout << "   Left does not exist." << std::endl;
		} else if (vec_str_cmd[0] == "ir") {
			if(!tree.into_right())
				std::cout << "   Right does not exist." << std::endl;
		} else if (vec_str_cmd[0] == "idl") {
			tree.into_deep_left();
		} else if (vec_str_cmd[0] == "idr") {
			tree.into_deep_right();
		} else if (vec_str_cmd[0] == "is") {
			std::cout << "   left   : " << (tree.is_left() ? "true" : "false") << std::endl <<
					"   right  : " << (tree.is_right() ? "true" : "false") << std::endl <<
					"   data   : " << (tree.is_data() ? "true" : "false") << std::endl <<
					"   parent : " << (tree.is_parent() ? "true" : "false") << std::endl <<
					"   ground : " << (tree.is_ground() ? "true" : "false") << std::endl;
		} else if (vec_str_cmd[0] == "esc") {
			tree.escape();
		} else if (vec_str_cmd[0] == "gnd") {
			tree.ground();
		} else if (vec_str_cmd[0] == "dsl") {
			std::cout << "   leftdata : " << tree.left() << std::endl;
			tree.dswap_left();
		} else if (vec_str_cmd[0] == "dsr") {
			std::cout << "   rightdata : " << tree.right() << std::endl;
			tree.dswap_right();
		} else if (vec_str_cmd[0] == "dsrl") {
			std::cout << "   leftdata : " << tree.left() << std::endl;
			std::cout << "   rightdata : " << tree.right() << std::endl;
			tree.dswap_rl();
		} else if (vec_str_cmd[0] == "srl") {
			tree.swap_rl();
		} else if (vec_str_cmd[0] == "dlt") {
			if (vec_str_cmd.size() > 1)
				if (tree.is_left()) map.insert(map_var(vec_str_cmd[1], tree.detach_left_tree()));
				else std::cout << "   Left does not exist." << std::endl;
			else std::cout << "이 명령은 하나의 인자를 필요로함." << std::endl;
		} else if (vec_str_cmd[0] == "drt") {
			if (vec_str_cmd.size() > 1)
				if (tree.is_right()) map.insert(map_var(vec_str_cmd[1], tree.detach_right_tree()));
				else std::cout << "   Right does not exist." << std::endl;
			else std::cout << "이 명령은 하나의 인자를 필요로함." << std::endl;
		} else if (vec_str_cmd[0] == "alt") {
			if (vec_str_cmd.size() > 1)
				tree.attach_left_tree(map[vec_str_cmd[1]]);
			else std::cout << "이 명령은 하나의 인자를 필요로함." << std::endl;
		} else if (vec_str_cmd[0] == "art") {
			if (vec_str_cmd.size() > 1)
				tree.attach_right_tree(map[vec_str_cmd[1]]);
			else std::cout << "이 명령은 하나의 인자를 필요로함." << std::endl;
		} else if (vec_str_cmd[0] == "dl") {
			tree.detach_left();
		} else if (vec_str_cmd[0] == "dr") {
			tree.detach_right();
		} else if (vec_str_cmd[0] == "al") {
			tree.attach_left();
		} else if (vec_str_cmd[0] == "ar") {
			tree.attach_right();
		} else if (vec_str_cmd[0] == "ts") {
			if (vec_str_cmd.size() > 1) *tree=vec_str_cmd[1];
			else std::cout << "이 명령은 하나의 인자를 필요로함." << std::endl;
		} else if (vec_str_cmd[0] == "chkh") {
			for (auto iter : map)
				std::cout << iter.first << ", " << iter.second->_Data << std::endl;
		} else if (vec_str_cmd[0] == "chkd") {
			if(tree.is_left()) std::cout <<	"   leftdata : " << tree.left() << std::endl;
			if(tree.is_right()) std::cout << "   rightdata : " << tree.right() << std::endl;
			if(tree.is_data()) std::cout <<	"   this : " << *tree << std::endl;
		} else if (vec_str_cmd[0] == "in") {
			std::string stream;
			inorder_travel([&stream](std::string str){stream.append(str + ' ');},tree.travel());
			std::cout << stream << std::endl;
		} else if (vec_str_cmd[0] == "post") {
			std::string stream;
			postorder_travel([&stream](std::string str){stream.append(str + ' ');},tree.travel());
			std::cout << stream << std::endl;
		} else if (vec_str_cmd[0] == "pre") {
			std::string stream;
			preorder_travel([&stream](std::string str){stream.append(str + ' ');},tree.travel());
			std::cout << stream << std::endl;
		} else if (vec_str_cmd[0] == "im") {
			linked_rvalue<priority_second> lr;
			if (vec_str_cmd.size() == 2)
				tree = lr.start(vec_str_cmd[1].c_str());
			else if (vec_str_cmd.size() > 2)
				std::cout << "입력값의 인자가 너무 많습니다. 공백이 포함된 식의 경우 큰따옴표로 감싸십시오." << std::endl;
			else
				std::cout << "식을 입력하십시오" << std::endl;
		}
	}
}

#endif