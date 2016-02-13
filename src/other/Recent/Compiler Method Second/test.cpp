#include "parse_method.h"
#include "timer.h"
#include <iostream>
#include "inter_method.h"
#include <vector>
#include "variable_method.h"
#include "second_layer_priority.h"
#include "lexer.h"
#include "logic.h"
#include "arithmetic.h"

#include <malloc.h>
#include <setjmp.h>

int amain()
{
#include "kkk.h" 
	int _9d7138f16acc;
#include "kkk.h"
	int _9d7138f16acc;
#include "kkk.h"
	int _9d7138f16acc;
#include "kkk.h"
	scanf_s("%d", &_9d7138f16acc);
#include "kkk.h"
	for(_9d7138f16acc=0, 
#include "kkk.h"
		_9d7138f16acc=1; 
#include "kkk.h"
		_9d7138f16acc; 
		_9d7138f16acc /= 10, 
#include "kkk.h"
#include "kkk.h"
		_9d7138f16acc <<= 1)
#include "kkk.h"
		if(_9d7138f16acc & 1)
#include "kkk.h"
			_9d7138f16acc += 
#include "kkk.h"
			_9d7138f16acc;
#include "kkk.h"
#include "kkk.h"
	printf("%d", _9d7138f16acc);
	return 0;
}

int main()
{
using namespace std;

	//int binary;
	//int result;
	//int square;
	//scanf_s("%d", &binary);

	//// �Է� ���� 2������ 10������ ���� 10�� ������ �����մϴ�.
	//for(result=0, square=1; binary; binary /= 10, square <<= 1)

	//	// ���� �ڸ��� 1�̶�� �ڸ�����ŭ 2�� ������ ���� ���մϴ�.
	//	if(binary & 1)
	//		result += square;

	//printf("%d", result);


	parse_rvalue<priority_second_layer> pr;
    Timer<long double> timer;
    timer.start();
    //tree<string> ttree = pr.start("y+y*(y-z)*z+z");
	//tree<string> ttree = pr.start("(1-y)*(6-z)/(7-x)");
    //tree<string> ttree = pr.start("1+x&&y+2");
    //tree<string> ttree = pr.start("x+y*z+a*b+c*d+e*f+g");
    //tree<string> ttree = pr.start("a+(a&&b)+(a&&b&c)+(a&&b&c<d)+(a&&b&c<d<<e)+(a&&b&c<d<<e%f)"
    //                              "+(a&&b&c<d<<e%f+g)+(a&&b&c<d<<e%f+g*h)");
    //tree<string> ttree = pr.start("a*l&b%z==k+i&&z>>j");
    //tree<string> ttree = pr.start("((A >= 0) && (A < 9)) || ((A >= '0') && (A < '9'))");
    //tree<string> ttree = pr.start("3+4*(5+6)");
    tree<string> ttree = pr.start("a+a+a");
    //tree<string> ttree = pr.start("x+y");
    vector<string> a = _optimize_intercode_generator2(ttree);
    timer.finish();
    for (auto st : a)
        cout << st << endl;

    ttree.postorder_travel([](string str) {cout << str; }, ttree.travel());

    cout << endl;
	cout.precision(numeric_limits<long double>::digits10);
    cout << *timer << "ns" << endl << endl;
	//return 0;

////////////////////////////////////////////////////////////////////////////////
    
    // �߰� ��ȣ ó��
    //tree<string> ttree = pr.start("y+y*(y-z)*z+z");

    // ��ȣ �켱���� ó��
    //tree<string> ttree = pr.start("(1-y)*(6-z)/(7-x)");

    // second_layer Ȯ��
    //tree<string> ttree = pr.start("1+x&&y+2");

    // ���� ���� Ȯ��
    //tree<string> ttree = pr.start("x+y*z+a*b+c*d+e*f+g");
    
    // ���� �켱���� ��ġ Ȯ��
    //tree<string> ttree = pr.start("a+(a&&b)+(a&&b&c)+(a&&b&c<d)+(a&&b&c<d<<e)+(a&&b&c<d<<e%f)"
    //                              "+(a&&b&c<d<<e%f+g)+(a&&b&c<d<<e%f+g*h)");

    // ���� �켱���� ��ġ Ȯ��
    //tree<string> ttree = pr.start("a*l&b%z==k+i&&z>>j");

    // �߰��ڵ������ �ߺ����� ġȯ Ȯ��
    //tree<string> ttree = pr.start("a+a+a");

    // ���� �ʱ� Ȯ�� ����
    //tree<string> ttree = pr.start("x+y");

////////////////////////////////////////////////////////////////////////////////
    
    /*parse_variable pv;
    std::string parsinglot;
    for (std::string str : pv.parse_replacement2("p[a+b[a-b]+c[d-z[k]+a]]+k(a)", parsinglot))
        cout << str << endl;
    cout << endl;
    cout << parsinglot << endl;*/

////////////////////////////////////////////////////////////////////////////////

	//logic_method ab;
	//ab.add_variable('a');
	//ab.add_variable('b');
	//ab.add_variable('c');
	//ab.add_variable('d');
	//ab.add_variable('e');
	//ab.add_variable('f');
	//ab.add_variable('g');
	//ab.add_variable('h');
	//ab.add_variable('i');
	//ab.add_variable('j');
	//ab.add_variable('k');
	//ab.add_variable('l');
	//ab.add_variable('m');
	//ab.add_variable('n');
	//ab.add_variable('o');
	////ab.view_value_table("a'bcdefgh+ab'cdefgh+abc'defgh+abcd'efgh+abcde'fgh+abcdef'gh+abcdefg'h+abcdefgh'+abcdefgh+abcdefgh");
	//ab.view_value_table_file("(a'bcdefghij+ab'cdefghij+abc'defghij+abcd'efghij+abcde'fghij+abcdef'ghij+abcdefg'hij+abcdefgh'ij+abcdefghi'j+abcdefghij')"
	//	"(k'lmno+kl'mno+klm'no+klmn'o+klmno')",
	//	"c:\\asdf.txt");

////////////////////////////////////////////////////////////////////////////////

	/*arithmetic_method b;
	b.add_variable('x', M_PI_2 +1);
	b.add_variable('y', -1.3);

	cout.precision(numeric_limits<long double>::digits10);
	cout << b.get_value("(x+y)*sin(y+x)") << endl;*/

////////////////////////////////////////////////////////////////////////////////

    //Timer<long double> timer;
	arithmetic_method_postexpression amp;
	string str;
    timer.start();
	str = amp.get("((1-y)(6-z))/(7-x)");
	timer.finish();
	cout << str << endl;
	cout.precision(numeric_limits<long double>::digits10);
    cout << *timer << "ns" << endl << endl;

////////////////////////////////////////////////////////////////////////////////
	
    //Timer<long double> timer;
	arithmetic_method_intercode ami;
    timer.start();
	vector<string> vs = ami.get_intercode("(1-y)*(6-z)/(7-x)");
	timer.finish();
	for (auto st : vs)
	    cout << st << endl;

	cout.precision(numeric_limits<long double>::digits10);
    cout << *timer << "ns" << endl << endl;

    return 0;
}