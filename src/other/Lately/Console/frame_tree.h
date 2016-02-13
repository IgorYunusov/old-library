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
			std::cout << "pl/pr [x] : left/right�� x�� ����" << std::endl <<
					"mhl/mhr [x] : make_head_left/make_head_right�� x�� ����" << std::endl <<
					"il/ir : left/right��ҷ� ������ �̵�" << std::endl <<
					"idr/idl : left/right�� ���ϴܿ�ҷ� ������ �̵�" << std::endl <<
					"is : ��� ���翩�� Ȯ��(left, right, data, parent, ground)" << std::endl <<
					"esc : escape���" << std::endl <<
					"gnd : gound���" << std::endl <<
					"dsl/dsr/dsrl : data swap ����" << std::endl <<
					"srl : ������ swap ����" << std::endl <<
					"dlt/drt (s) : Ʈ���� ����� table�� �ִ´�.(s�ʼ�)" << std::endl <<
					"alt/art (s) : ��� Ʈ���� ���δ�." << std::endl <<
					"dl/dr/al/ar : Ʈ���� ����� �ӽ�����ҿ� �����ϰų� ���δ�." << std::endl <<
					"ts : this�� ��Ҹ� �����Ѵ�." << std::endl <<
					"chkh : ���̺� �� ����� ����� �����ش�." << std::endl <<
					//"cald : Ʈ���� �߻� ���̸� ����Ѵ�." << endl <<
					"chkd : left right this�� ������ �����ش�." << std::endl <<
					"in/post/pre : ����, ����, ������ ��ȸ�� ����� �����ش�." << std::endl <<
					"im [x] : x���� �м��մϴ�(Ʈ�� ������ �� Ʈ���� ������)." << std::endl;
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
			else std::cout << "�� ����� �ϳ��� ���ڸ� �ʿ����." << std::endl;
		} else if (vec_str_cmd[0] == "drt") {
			if (vec_str_cmd.size() > 1)
				if (tree.is_right()) map.insert(map_var(vec_str_cmd[1], tree.detach_right_tree()));
				else std::cout << "   Right does not exist." << std::endl;
			else std::cout << "�� ����� �ϳ��� ���ڸ� �ʿ����." << std::endl;
		} else if (vec_str_cmd[0] == "alt") {
			if (vec_str_cmd.size() > 1)
				tree.attach_left_tree(map[vec_str_cmd[1]]);
			else std::cout << "�� ����� �ϳ��� ���ڸ� �ʿ����." << std::endl;
		} else if (vec_str_cmd[0] == "art") {
			if (vec_str_cmd.size() > 1)
				tree.attach_right_tree(map[vec_str_cmd[1]]);
			else std::cout << "�� ����� �ϳ��� ���ڸ� �ʿ����." << std::endl;
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
			else std::cout << "�� ����� �ϳ��� ���ڸ� �ʿ����." << std::endl;
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
				std::cout << "�Է°��� ���ڰ� �ʹ� �����ϴ�. ������ ���Ե� ���� ��� ū����ǥ�� ���νʽÿ�." << std::endl;
			else
				std::cout << "���� �Է��Ͻʽÿ�" << std::endl;
		}
	}
}

#endif