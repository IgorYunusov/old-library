#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <map>
#include "frame_tree.h"
#include "msconsole.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "RollRat Console Control™" << endl << 
			"Copyright (C) rollrat. All rights reserved." << endl << endl;
	
RE:
	cout << "# user name : ";

	string username;
	cin >> username;
	bool root = false;
	if(username == "administrator" || username == "admin") {
		string password;
		getch_c(password);

		// 관리자(제작자) 비밀번호 : 사람은무엇으로사는가
		if (password == "tkfkadmsandjtdmfhtksmsrk") {
			cout << " true" << endl << 
					"Hi, administrator." << endl << endl;
			root = true;
		} else {
			cout << " false" << endl << endl;
			goto RE;
		}
	} else {
		cout << "Hi, " << username << endl << endl;
	}

	/////////////////////////////////////////////////////////////////////////////
	// COMMAND LOOP
	/////////////////////////////////////////////////////////////////////////////

	char *command_input = (char *) malloc (256);
	for(;;) {
		out_rootcontext(username, root);
		in_command(command_input);
		vector<string> vec_str_cmd;
		get_command_line(vec_str_cmd, command_input);

			// 설명 : access 명령은 관리자(제작자)권한을 얻을 뿐만아니라
			// 이 프로젝트에 사용되는 거의 모든 프로그램의 접근 권한
			// 을 가지게됩니다. 부분 사용자 공개용 프로그램, 즉,
			// 베타 프로그램을 위하여 작성해 둔 부분이므로 이 구문
			// 을 삭제하거나 변경하지마십시오.
		if (vec_str_cmd[0] == "access") {
			if (vec_str_cmd.size() > 1) {
				if(vec_str_cmd[1] == "administrator") {
					if (root){
						cout << "이미 권한을 획득하였음." << endl;
					} else {
						goto RE;
					}
				} else {
					cout << "not found access dest <" << vec_str_cmd[1] << ">" << endl;
				}
			} else {
				cout << "> ";
				string emergence_get;
				cin >> emergence_get;
				if(emergence_get == "administrator")
					goto RE;
				else
					cout << "not found access dest <" << emergence_get << ">" << endl;
			}

			// 이 명령은 관리자(제작자)권한이 필요한 기능입니다.
			// 설명 : RCC의 기능 중 하나인 tree는 사용자에게 편리한 연산
			// 수식을 분석하거나, 관련 연산을 하기위하여 제작된 프로그램입니다.
		} else if (vec_str_cmd[0] == "tree" && root) {
			if(vec_str_cmd.size() <= 1) {
				cout << "이 명령어는 멀티라인을 사용할 수 없습니다." << endl;
			} else {
				tree<string> tree;
				if(vec_str_cmd[1] == "standard") {
					frame_stdmaketree(tree);
				}
			}

			// 설명 : system명령을 호출한다.
		} else if (vec_str_cmd[0] == "system") {
			if (vec_str_cmd.size() > 1) {
				system(vec_str_cmd[1].c_str());
			} else {
				cout << "> ";
				string emergence_get;
				cin >> emergence_get;
				system(emergence_get.c_str());
			}

			// 비공개 프로그램 실행
		} else if (vec_str_cmd[0] == "call" && root) {
			if (vec_str_cmd.size() > 1) {
				system((vec_str_cmd[1]  + " ef1287").c_str());
			} else {
				cout << "> ";
				string emergence_get;
				cin >> emergence_get;
				system((emergence_get  + " ef1287").c_str());
			}

			// 설명 : 콘솔창을 지웁니다.
		} else if (vec_str_cmd[0] == "cls") {
			cls();

			// 설명 : 프로그램 테스트용
		} else if (vec_str_cmd[0] == "test") {
			if(vec_str_cmd.size() > 1) {
				if (vec_str_cmd[1] == "argument") {
					for (int i = 0; i < vec_str_cmd.size(); i++)
						cout << vec_str_cmd[i] << endl;
				} else if (vec_str_cmd[1] == "multiline") {
					std::vector<std::string> _vec_str_cmd;
					for(;;) {
						std::cout << "> ";
						in_command(command_input);
						std::vector<std::string> vec_str_cmd_;
						get_command_line(vec_str_cmd_, command_input);
						if (vec_str_cmd_[0] == "//")
							break;
						_vec_str_cmd.push_back(command_input);
					}
					for (auto tmp : _vec_str_cmd)
						cout << tmp << ' ';
					cout << endl;
				} else {
					cout << vec_str_cmd[1] << "는 알 수 없는 옵션입니다." << endl;
				}
			} else {
				cout << "이 명령은 적어도 하나이상의 인자를 필요로합니다." << endl;
			}
		}
	}

	return 0;
}