/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						INTER METHOD
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _INTER_METHOD_
#define _INTER_METHOD_

#include "tree.h"
#include <hash_map>
#include <vector>
#include <stack>
#include <string>
#include <Windows.h>

		// INTERCODE GENERATOR for linked_rvalue with optimize
std::vector<std::string> _optimize_intercode_generator2(tree<std::string>& tree, int count_start = 0)
	{
	std::stack<std::string> var;
	std::vector<std::string> tdup1, tdup2, code;

    // ������ ������ ���� ����
	int count = count_start;

    /*

    �Ҽ����� ���Ե� ��� ���ڿ� ��ġ�մϴ�.

    */
	auto is_number=[](std::string cptr)->bool
		{
		for (const char *ptr = cptr.c_str(); 
			('0' <= *ptr && *ptr <= '9') || *ptr == '.'; ptr++)
			if(!*(ptr+1))
				return true;
		return false;
		};
    
	traversal::postorder_travel([&](std::string str)
		{
            
        /*

        �߰��ڵ� ������ ù ��° �ܰ�� ���� ó������ ����� ����
        �������� ���� ����, ������ ���� ������ ó���մϴ�.

        */
		if(::strchr("+-*/&^|%<>!~=", str[0]))
			{

            /*

            ����� ���� �� ���ο� ������ ����ϴ�.
            �� �������� ���ο� ������ ���� ���ÿ� ����˴ϴ�.

            */
			std::string rvalue("$t" + std::to_string(count) + "_=");

            /*

            ���ÿ� �ƹ� �͵� ������ �����ڿ��� lvalue�� �������� �ʴ� �� �̹Ƿ� 
            Ʈ�� ������������ ������ ���� �� �Դϴ�.
            �� ��� ����ڰ� ������ �߸��Է��Ͽ��� ���ɼ��� �����ϴ�.

            1. ���ÿ��� 2���� ������ �����ɴϴ�.
            2. �������� ������, ���ʿ� ���� ������ ������� �ֽ��ϴ�.
            3. ���� �������� ������� ���� ������ ���ÿ� �ֽ��ϴ�.
            4. ����, ����ȭ ���� ��Ұ� �����Ѵٸ�, �ش� ��Ҹ� ����ȭ�ϰ�,
               ����ȭ�� ���� ���ÿ� �ֽ��ϴ�.

            */
			if (!var.empty())
				{
				bool second_number = is_number(var.top());
				std::string temp = var.top();
				var.pop();
				if (!var.empty()) {
                    
                    /*

                    number <operator> number�� ������ ��� ������ �����ϹǷ�,
                    ���� �����Ͽ� �߰��ڵ带 ����ȭ�մϴ�.

                    */
					if(is_number(var.top()) && second_number) {
						long long v1 = std::stoll(temp), v2 = std::stoll(var.top()), v3=0;
						switch(*str.c_str()) {
						case '+': v3 = v2 + v1; break;
						case '-': v3 = v2 - v1; break;
						case '*': v3 = v2 * v1; break;
						case '/': v3 = v2 / v1; break;
						case '&': v3 = v2 & v1; break;
						case '^': v3 = v2 ^ v1; break;
						case '|': v3 = v2 | v1; break;
						case '%': v3 = v2 % v1; break;
						default:

                            //
                            //  �˷����� ���� �������� ���
                            //
							goto JUST_EXCUATE;
						}
						var.push(std::to_string(v3));
					} else {
			JUST_EXCUATE:
						rvalue.append(var.top()+str+temp);
						var.pop();
						code.push_back(rvalue);
						var.push("$t" + std::to_string(count) + "_");
						count += 1;
						}
				} else 
					goto _LABEL_ERROR;
				}
			else 
                {
		_LABEL_ERROR:
				MessageBox(0, TEXT("Input value is incorrect. Please enter a valid expression."), 
                    TEXT("Compiler Method V1.5, _optimize_intercode_generator2"), MB_OK | MB_ICONERROR);
                exit(0);
                }
			}
		else

            /*

            ó�� ���� ���� �����ϰ�� ����ȭ ��Ұ� ���� �� �����Ƿ�
            �ϴ�, ���ÿ� ������ �Ӵϴ�.

            ���� ���ڰ� �ƴ� ��� ������ ����ϹǷ� �ش� ������ �����ϴ� ������ �����
            �ش� ������ ���ÿ� �ֽ��ϴ�.

            */
			if(is_number(str))
				var.push(str);
			else {
				bool t = false;

                /*

                �ߺ��Ǵ� ������ �ִ��� Ȯ���մϴ�.

                ����, �ߺ��Ǵ� ������ ���� ��� �ش� ������ ���ÿ� �ְ�, �� ������ ����ġ��,
                ���� ��� ���ο� ������ �����ϴ� ������ �����մϴ�.

                */
				for(int i = 0; i < tdup1.size(); i++)
					if(tdup2[i] == str) {

                        //
                        //  ���͸� �����鼭 �ϳ��� �߰ߵȴٸ� �ش� ������ ���� �ʿ䰡 �����Ƿ�
                        //  ���� ������ ���ÿ� �ֽ��ϴ�.
                        //
						var.push(tdup1[i]);
						t = true;
						break;
					}

				if(!t) {

                    /*

                    $t~~_�� ���� ���´� ù ������ $�� ���� �� ó���� ���� ������ �ʴ� ���ڶ� ����� ���̸�,
                    ������ ������ _�� $t�� ������ ���ڸ��� ���� ��� strcmp�� true�� ������ ������ ��찡 ���ܼ� �Դϴ�.
                    ����, �����ڿ� ������ �������� �ʾұ� ������ �������� �ڿ� ���� ���̷�
                    �ش� ����� ����Ͽ����ϴ�.

                    */
					std::string rvalue("$t" + std::to_string(count) + "_=" + str);

                    //
                    //  ���ڿ� ���������� ������ ���ÿ� �ֽ��ϴ�.
                    //
					var.push("$t" + std::to_string(count) + "_");

                    //
                    //  ������ �ߺ��� Ȯ���ϱ� ���� tdup1�� ����
                    //
					tdup1.push_back(var.top());
					tdup2.push_back(str);

					code.push_back(rvalue);
					count += 1;
				}
            }
        }
		, tree.travel());
	if (code.empty())
		code.push_back(var.top());
	return code;
	}

#endif