/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   parse_method.h - [Private]

Project:

   Compiler Method Second

------
   AUTHOR: HyunJun Jeong  2015-02-17

***************************************************************************/

// �� ������ bitstream vera��Ʈ�� ����Ͽ� �ۼ��Ͽ���

#ifndef _PARSE_METHOD_
#define _PARSE_METHOD_

#include <string>
#include "tree.h"
#include "priority.h"
#include "second_layer_priority.h"

/*
    �Լ�, �ּ��ڵ� �� ������ �� �� ���� ������ ���Ե� ���
    ���� ġȯ�Ͻñ� �ٶ��ϴ�.
*/

template<class priority_type = priority_second_layer> class 
	parse_rvalue
{
	typedef parse_rvalue<priority_type> _Myparse;
	typedef tree<std::string> _Mytree;

	priority_type pf;
	_Mytree ps_tree;
	std::string temp;
	const char *ptr;

public:
	_Mytree start(const char *_S);

protected:
	bool is_char();
	bool is_operator();
	void skipws();

	// Parsing Module
	void var();
	void factor();
	void variable();
    
    bool get_inside_string();
};

////////////////////////////////////////////////////

template<class priority_type> 
tree<std::string> parse_rvalue<priority_type>::start(const char *_S)
{
	ptr = _S;
	var();
	return ps_tree;
}

////////////////////////////////////////////////////

template<class priority_type> 
bool parse_rvalue<priority_type>::is_char()
{
	return (
		isalnum(*ptr) ||
		*ptr == '.'  ||   // �Ҽ���
		*ptr == '\"' ||   // ���ڿ�
		*ptr == '\'' ||   // ����
		*ptr == '\\' ||   // �ּ�
		*ptr == '$' ||    // �������� ��밡��
		*ptr == '_' ||    // �������� ��밡��
		*ptr == '@'       // ������ ���Ұ���, ������� ġȯ �뵵�� ����� ��
	);
}

template<class priority_type> 
bool parse_rvalue<priority_type>::is_operator()
{
	if (!*ptr)
		return false;
	return strchr("+-*/&|^%<>!~=", *ptr);
}

template<class priority_type> 
void parse_rvalue<priority_type>::skipws()
{
	while (isspace(*ptr))
		ptr++;
}

template<class priority_type> 
void parse_rvalue<priority_type>::var()
{
	factor();
    skipws();
	
	//
	//	�����ڰ� ������ Ʈ���� �����ڸ� ����־���ϹǷ� 
	//	rvalue�� lvalue�� ���� ����, ������ �м��մϴ�
	//
	if (is_operator())
	{
		//
		//	�������� ���̴� ��Ȳ�� ���� �þ ��
		//	�ֽ��ϴ�. �̸� ����Ͽ� ������ ��ü�� �����ɴϴ�.
		//
		std::string optr;
		for (; is_operator(); ptr++)
			optr.push_back(*ptr);
		skipws();

		//
		//	���� ���� ��忡 �����ڰ� ���� ��� �װ��� �����ڸ�
		//	������˴ϴ�. �������� ��� lvalue�� �̹� ä���� 
		//	���¿����մϴ�.
		//
		if (!ps_tree.is_data()) {
			*ps_tree = optr;
        } else {
        RETRY:

            /*
               
            ���� ����� �����ڿ� �������� �ϴ� �����ڸ� ���� ���Ͽ�
            �켱������ �����ɴϴ�.

            x ::= ���� ����� ������
            y ::= �������� �ϴ� ������
            ��� �����ϸ�,

            (y > x) ->  1
            (y = x) ->  0
            (y < x) -> -1
            
            �� ���� ����մϴ�.

            */
            int save = pf(optr, *ps_tree);

			//
			//	���� Ʈ�� ������� �ִ� �����ڿ� ����
			//	�����ڸ� ���Ͽ� ������ ���մϴ�.
			//	�� �� �� ������ ������ �ٲپ� ��Ȱ��
			//	����ǥ������� ��ȯ�� �� �ֵ��� �մϴ�.
			//

			if(save > 0)
			{
				/*

				�� ������ ���� Ʈ�� ������� �ִ� �����ڰ�
				�������ϴ� �����ں��� ���� �켱 ������ ���� �� ����˴ϴ�.

				����, 3+y*z��� ������ ����� ���ؼ�

				�ϼ��� ����

				     +
				    / \
				   3   y

				����

				         +
				        / \
				       3   *
				          / \
				         y   z

				�� �ٲ���մϴ�. (y�� �����Ͱ� *�� �� �������� �̵���)

				�� ����� ������ ���� ������ ����˴ϴ�.

                �����ʿ� �����Ͱ� ���� ���
				1. ���� ��尡 y�� ����Ű�� �մϴ�.
				2. ���� ����� �����ʿ� �ش� �����ڸ� �ֽ��ϴ�.
				3. ���� ����� ���� ������ ����� ���� ���� �ٲߴϴ�.

                �����ʿ� �����Ͱ� �ִ� ���(���� �����͵� ���Ե�)
                1. ������ ��带 �ӽ������մϴ�.
                2. ������ ��忡 �ش� �����ڸ� �ֽ��ϴ�.
                3. ���� ��带 ������ ���� �̵���ŵ�ϴ�.
                4. ���� ����� ���ʿ� �ӽ������� ��带 �ֽ��ϴ�.

				*/
                if(!ps_tree.is_right()) {
				    ps_tree.into_right();
				    ps_tree.push_left(optr);

				    //
				    //	���� Ʈ�� ����� �����Ϳ� ���� ����� �����͸� �ٲߴϴ�.
				    //
				    ps_tree.dswap_left();
                } else {
                    ps_tree.detach_right();
                    ps_tree.push_right(optr);
                    ps_tree.into_right();
                    ps_tree.attach_left();
                }

			} else if (save < 0) {
                
                /*

                �� ������ ���� Ʈ�� ������� �ִ� �����ڰ�
                �������ϴ� �����ں��� ���� �켱 ������ ���� �� ����˴ϴ�.

                ����, ���� ��尡 ground�� �ִٸ�, 
                ������ ���� ������ ����ϴ�.

                ����, x*y+i�� ��� + < * �̹Ƿ�,

                    *
                   / \
                  x   y

                ����

                        +
                       / \
                      *   i
                     / \
                    x   y

                ���� ��ȯ�մϴ�.

                ���� ground�� ���� ������
                ���� �� ������ ���¸� �����Ƿ�,

                     ...    ...
                    /          \
                   *            *
                  / \          / \
                 x   y        x   y

                �������� ������ ���� escape�� �����մϴ�.

                */
                if(ps_tree.is_ground()) {
                    ps_tree.make_head_left();
                    *ps_tree = optr;
                } else {
                    ps_tree.escape();
                    goto RETRY;
                }

			} else {

                /*

                �� ������ ���� Ʈ�� ������� �ִ� �����ڿ�
                �������ϴ� �����ڰ� ���� �켱 ������ ���� �� ����˴ϴ�.

                ����, x+y-i����� �������� ǥ���� (x+y)-i�� �ǹǷ�

                     +
                    / \
                   x   y

                ����

                       -
                      / \
                     +   i
                    / \
                   x   y

                �� �Ǿ�� �մϴ�. (-�� �� ���� �����Ƿ� i-(x+y)��
                ������ �� ������ �̴� �߸��� ǥ���Դϴ�.)

                �� ����� �Ʒ��� ���� ������� ����˴ϴ�.

                escape���� ���� �� 

                i) ���� ��尡 ground�� ���
                1. ��带 �ӽ������ϰ� �� ��带 ����ϴ�.
                2. ��忡 �����ڸ� �ֽ��ϴ�.
                3. ����� ���ʿ� �ӽ������� ��带 �����մϴ�.

                ii) escape�� �������� �����Ͽ��ٸ�(�ڼ��� ������ escape�Լ� ����)
                1. ���� ��带 �ӽ������մϴ�.
                2. ���� ��忡 �����ڸ� �ֽ��ϴ�.
                3. ���� ��带 ���� ��带 ����Ű�� �մϴ�.
                4. ���ʿ� �ӽ������� ��带 �ֽ��ϴ�.

                iii) escape�� ���������� �����Ͽ��ٸ�
                1. ������ ��带 �ӽ������մϴ�.
                2. ������ ��忡 �����ڸ� �ֽ��ϴ�.
                3. ���� ��带 ������ ��带 ����Ű�� �մϴ�.
                4. ���ʿ� �ӽ������� ��带 �ֽ��ϴ�.

                */

                ps_tree.detach_this();
                if(ps_tree.last_detach() == 0) {
                    *ps_tree = optr;
                    ps_tree.attach_left();
                } else if(ps_tree.last_detach() == -1) { //} else if(!ps_tree.is_left()) {
                    ps_tree.push_left(optr);
                    ps_tree.into_left();
                    ps_tree.attach_left();
                } else if(ps_tree.last_detach() == 1) { //} else if(!ps_tree.is_right()) {
                    ps_tree.push_right(optr);
                    ps_tree.into_right();
                    ps_tree.attach_left();
                }

            }
        }
		var();
	}

}

template<class priority_type> 
void parse_rvalue<priority_type>::factor()
{
	skipws();
	if (*ptr == '(')
	{
		ptr++;
		_Myparse rvtemp;

		/*

		�� ������ ���� �� ���� ������ �����ϴ�.

			1. ���� ��忡 �����Ͱ� �����ϰ�, �����ʿ� �������� ���� ���.
			2. ���� ��忡 �����Ͱ� �������� ���� ���

		*/
		if (ps_tree.is_left() && !ps_tree.is_right())

			//
			//	���� ���� Ʈ�� ��带 �����ʿ��� ���Դϴ�.
			//
			ps_tree.attach_right_tree(rvtemp.start(ptr).travel());
		else if (!ps_tree.is_left())
				
			//
			//	���� ���� Ʈ�� ��带 ���ʿ��� ���Դϴ�.
			//
			ps_tree.attach_left_tree(rvtemp.start(ptr).travel());
		else
			;	// error

		//
		//	���� ���� Ʈ���ȿ��� ������ �����͸� �����ɴϴ�.
		//
		ptr = rvtemp.ptr;

		//
		//	��ȣ�� ���������� �����ִ��� Ȯ���մϴ�.
		//	�� �۾��� ���������� �̷������ �ʾҴٸ� ���α׷��� ������ ����
		//	���ɼ��� �ſ� Ů�ϴ�.
		//
		if (*ptr == ')')
			ptr++;
		else
			;	// error
	}
	else if(is_char()) 
	{
        //
        //  �� ������ ��ǻ� �������� �������� �� ���� ���� �ٸ� ������ ����
        //  �� ���� ��� ó����ŵ�ϴ�. �̷� ������ �������� �������� �������� �˻�
        //  �Ͽ����մϴ�.
        //
		variable();
		factor();
	}
}

template<class priority_type> 
void parse_rvalue<priority_type>::variable()
{
	for (; is_char();)
		temp.push_back(*ptr++);

    //
    //  Reference, Function �κ��� Ȯ���մϴ�.
    //
RETRY:
    skipws();
    if (*ptr == '(' || *ptr == '[') {
        get_inside_string();
        goto RETRY;
    }

	//
	//	�� ���� ���ʿ� �־�� �̹� �����Ͱ� �����ϸ�
	//	�����ʿ� �ֽ��ϴ�. 
	//	���� ǥ������� ��ȯ�ϱ� ���� ����->������ ������� �����մϴ�.
	//
	if (!ps_tree.is_left())
		ps_tree.push_left(temp);
	else if (!ps_tree.is_right())
		ps_tree.push_right(temp);
	temp.clear();
}

template<class priority_type> 
bool parse_rvalue<priority_type>::get_inside_string()
{
    //
    // ��ȣ�� ������ �������� ����
    //

    int indicate_inside = 0;

    for(; *ptr; (ptr)++)
    {
        temp.push_back(*ptr);

        switch(*ptr)
        {
        case '[':
        case '(':
        case '{':
            indicate_inside++;
            break;

        case ']':
        case ')':
        case '}':
            indicate_inside--;
            break;

        default:
            continue;
        }

        if (indicate_inside == 0) {
            ptr++;
            return true;
        }
    }

    return false;
}


#endif