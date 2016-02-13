#include "parse_method.h"
#include "timer.h"
#include <iostream>
#include "inter_method.h"
#include <vector>
#include "variable_method.h"
#include "second_layer_priority.h"

#include <malloc.h>

int main()
{
using namespace std;
	parse_rvalue<priority_second_layer> pr;
    Timer<long double> timer;
    timer.start();
    //tree<string> ttree = pr.start("y+y*(y-z)*z+z");
    //tree<string> ttree = pr.start("(1-y)*(6-z)/(7-x)");
    //tree<string> ttree = pr.start("1+x&&y+2");
    //tree<string> ttree = pr.start("x+y*z+a*b+c*d+e*f+g");
    tree<string> ttree = pr.start("a+(a&&b)+(a&&b&c)+(a&&b&c<d)+(a&&b&c<d<<e)+(a&&b&c<d<<e%f)"
                                  "+(a&&b&c<d<<e%f+g)+(a&&b&c<d<<e%f+g*h)");
    //tree<string> ttree = pr.start("a*l&b%z==k+i&&z>>j");
    //tree<string> ttree = pr.start("a+a+a");
    //tree<string> ttree = pr.start("x+y");
    vector<string> a = _optimize_intercode_generator2(ttree);
    timer.finish();
    for (auto st : a)
        cout << st << endl;
    cout << endl;
	cout.precision(numeric_limits<long double>::digits10);
    cout << *timer << "ns";
	return 0;

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

    return 0;
}