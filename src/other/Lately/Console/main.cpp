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
	cout << "RollRat Console Control��" << endl << 
			"Copyright (C) rollrat. All rights reserved." << endl << endl;
	
RE:
	cout << "# user name : ";

	string username;
	cin >> username;
	bool root = false;
	if(username == "administrator" || username == "admin") {
		string password;
		getch_c(password);

		// ������(������) ��й�ȣ : ������������λ�°�
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

			// ���� : access ����� ������(������)������ ���� �Ӹ��ƴ϶�
			// �� ������Ʈ�� ���Ǵ� ���� ��� ���α׷��� ���� ����
			// �� �����Ե˴ϴ�. �κ� ����� ������ ���α׷�, ��,
			// ��Ÿ ���α׷��� ���Ͽ� �ۼ��� �� �κ��̹Ƿ� �� ����
			// �� �����ϰų� �����������ʽÿ�.
		if (vec_str_cmd[0] == "access") {
			if (vec_str_cmd.size() > 1) {
				if(vec_str_cmd[1] == "administrator") {
					if (root){
						cout << "�̹� ������ ȹ���Ͽ���." << endl;
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

			// �� ����� ������(������)������ �ʿ��� ����Դϴ�.
			// ���� : RCC�� ��� �� �ϳ��� tree�� ����ڿ��� ���� ����
			// ������ �м��ϰų�, ���� ������ �ϱ����Ͽ� ���۵� ���α׷��Դϴ�.
		} else if (vec_str_cmd[0] == "tree" && root) {
			if(vec_str_cmd.size() <= 1) {
				cout << "�� ��ɾ�� ��Ƽ������ ����� �� �����ϴ�." << endl;
			} else {
				tree<string> tree;
				if(vec_str_cmd[1] == "standard") {
					frame_stdmaketree(tree);
				}
			}

			// ���� : system����� ȣ���Ѵ�.
		} else if (vec_str_cmd[0] == "system") {
			if (vec_str_cmd.size() > 1) {
				system(vec_str_cmd[1].c_str());
			} else {
				cout << "> ";
				string emergence_get;
				cin >> emergence_get;
				system(emergence_get.c_str());
			}

			// ����� ���α׷� ����
		} else if (vec_str_cmd[0] == "call" && root) {
			if (vec_str_cmd.size() > 1) {
				system((vec_str_cmd[1]  + " ef1287").c_str());
			} else {
				cout << "> ";
				string emergence_get;
				cin >> emergence_get;
				system((emergence_get  + " ef1287").c_str());
			}

			// ���� : �ܼ�â�� ����ϴ�.
		} else if (vec_str_cmd[0] == "cls") {
			cls();

			// ���� : ���α׷� �׽�Ʈ��
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
					cout << vec_str_cmd[1] << "�� �� �� ���� �ɼ��Դϴ�." << endl;
				}
			} else {
				cout << "�� ����� ��� �ϳ��̻��� ���ڸ� �ʿ���մϴ�." << endl;
			}
		}
	}

	return 0;
}