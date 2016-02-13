#define _CRT_SECURE_NO_WARNINGS

#include "inter_method.h"
#include <iostream>
#include "pmc.h"
#include <numeric>
#include "independent_method.h"
#include "assembly_method.h"
#include "rasm.h"
#include <bitset>
#include "private_timer.h"
inline char * enc_c(char s)
{ // encryption character
	char ret[4][4];
	char sret[16], buf;
	int i, f, z = 0;
	for (i = 0; i < 4; i++)
		for (f = 0; f < 4; f++)
			ret[i][f] = s;
	for (f = 0; f < 4; f++)
		for (i = 0; i < 4; i++)
			ret[i][f] ^= (i << 4) | (i + 0xA);
	for (i = 0; i < 4; i++)
		for (f = 0; f < 4; f++)
			ret[i][f] ^= 0x30 | (f + 0x2);
	buf = ret[1][3];
	ret[1][3] = ret[2][2];
	ret[2][2] = buf;
	buf = ret[1][0];
	for (f = 0; f < 3; f++)
		ret[1][f] = ret[1][f + 1];
	ret[1][4] = buf;
	buf = ret[2][0];
	for (f = 0; f < 3; f++)
		ret[2][f] = ret[2][f + 1];
	ret[2][4] = buf;
	buf = ret[2][0];
	for (f = 0; f < 3; f++)
		ret[2][f] = ret[2][f + 1];
	ret[2][4] = buf;
	for (f = 0; f < 4; f++)
		for (i = 0; i < 4; i++, z++)
			sret[z] = ret[i][f];
	return sret;
}
inline char dec_c(char *s)
{ // decryption character
	char sret = 0;
	char ret[4][4], buf;
	int i, f, z = 0;
	for (i = 0; i < 4; i++)
		for (f = 0; f < 4; f++, z++)
			ret[i][f] = s[z];
	buf = ret[1][3];
	for (f = 3; f > 0; f--)
		ret[1][f] = ret[1][f - 1];
	ret[1][0] = buf;
	buf = ret[2][3];
	for (f = 3; f > 0; f--)
		ret[2][f] = ret[2][f - 1];
	ret[2][0] = buf;
	buf = ret[2][3];
	for (f = 3; f > 0; f--)
		ret[2][f] = ret[2][f - 1];
	ret[2][0] = buf;
	buf = ret[1][3];
	ret[1][3] = ret[2][2];
	ret[2][2] = buf;
	for (i = 0; i < 4; i++)
		for (f = 0; f < 4; f++)
			ret[i][f] ^= 0x30 | (0x5 - f);
	for (f = 0; f < 4; f++)
		for (i = 0, z = 3; i < 4; i++, z--)
			ret[i][f] ^= (z << 4) | (z + 0xA);
	return ret[0][3];
}
void rasm_test(std::vector<BYTE> xtarr)
{
	HANDLE mem_handle = CreateFileMapping( 
			INVALID_HANDLE_VALUE, 
			NULL, 
			PAGE_EXECUTE_READWRITE, 
			0,  
			xtarr.size(), 
			NULL);
	
	void * function = (void *)(MapViewOfFile(
			mem_handle,
			FILE_MAP_ALL_ACCESS | FILE_MAP_EXECUTE,
			0,
			0,
			xtarr.size()));
	BYTE* byteset= new BYTE[xtarr.size()], *ptr=byteset;
	//std::copy(xtarr.begin(), xtarr.end(), byteset);
	auto begin = xtarr.begin();
	for (; begin != xtarr.end(); ++ptr, ++begin) {
		//std::bitset<8> y(*begin);
		//std::cout << y;
		*ptr = *begin;
	}
	memcpy(function, byteset, xtarr.size());
	for (int x = 0; x < 100000 ; x++)
	{
		int xy = ((int(_stdcall*)(int))function)(1);
	}
	//return function;
}
int main()
{
	std::cout << dec_c(enc_c('s'));
	//std::numeric_limits<double>::quiet_NaN();
	/*int i = 2;

	std::cout << (i * 4 | 3) << std::endl;*/

	/*tree<char *> x;

	*x = "";

	x.push_left("1");
	x.into_left();

	x.push_left("2");
	x.into_left();
	x.push_left("3");
	x.push_right("4");
	x.into_right();
	x.push_right("5");

	x.ground();


	String<> _xtest;

	postorder_travel(
		[&](const char *str) { _xtest.Append(str); }, 
		x.travel(), 
		x.travel());
	
	std::cout << _xtest.c_str() << std::endl;
	*/

	//condition1<> T;
	/*std::cout << 
		<< std::endl;*/

	//std::vector<String<>> x;
	/*std::cout << 
		T.pnt_assembly
			(
				T.start("(ch != 'A') && ((ch == '\\0') || (('a' <= ch) && (ch <= 'z')))")
			).c_str() 
		<< std::endl << std::endl;*/

	//rvalue<> tx;

	//tree<String<>> ty = tx.start("((t + 3) / (3 + 4)) * ((t + 3) / (3 + 4))");//"i + (f * y)");//"sin(t + (3 * (3 - 1)))");

	//String<> _tmp;

	//std::cout << tx.pnt_assembly(ty).c_str() << std::endl;

	/*regular_transform0<> rt;
	String<> t = rt.transform0("4/4+3");
	regular_transform0<> rtn;
	t = rtn.transform0(t.c_str());

	t.c_str()[t.Length() - 1] = 0;
	t.c_str()++;*/

	/*int i = 0;

	i = 5 * 4 / 2;

	std::cout << md5("4*3/2+4*3-5/3").c_str() << std::endl;*/
	/*rvalue<> rv;

	std::cout << rv.pnt_assembly(rv.start(t.c_str())).c_str() << std::endl;

	std::cout << t.c_str() << std::endl;*/

	////////////////////////////////////////////////////////////////////////////////////////////

	//tree<int> tx;
	//*tx = 1;
	//tx.push_left(2);
	//tx.push_right(3);

	//tx.swap_rl();
	//tx.make_head_left(4);

	////tree<int> txxt(tx.dettach_left_tree());

	////std::cout << tx.dettach_left_tree()->_Data;

	////tx.attach_left_tree(tx.dettach_left_tree());

	//tx.detach_left();
	//tx.attach_left();

	//std::cout << (&tx)->_Left->operator*();
	////std::cout << (&tx)->_Right->operator*();
	//std::cout << (&tx)->_Left->_Left->operator*();
	//std::cout << (&tx)->_Left->_Right->operator*();
	//std::cout << (&tx)->operator*();

	////////////////////////////////////////////////////////////////////////////////////////////

	//Timer<double> timer1;
	//linked_rvalue<> lr;
	//timer1.start();
	//tree<std::string> ttree = lr.start("3*4^(5-3)+2*x^2-4");
	//timer1.finish();
	//String<> _ret;
	//postorder_travel([&](std::string str) { _ret.Append(str.c_str()); }, ttree.travel());
	//std::cout.precision(std::numeric_limits<double>::digits10);
	//std::cout << "3*4^(5-3)+2*x^2-4" << std::endl
	//	<< _ret.c_str() << std::endl << std::endl << *timer1
	//	//<< "Compiling..." << std::endl
	//	//<< rvt.pnt_assembly(ttree).c_str() << std::endl << std::endl
	//	;
	//std::vector<std::string> a = _intercode_generator(ttree);
	//
	//for(auto st : a)
	//{
	//	std::cout << st << std::endl;
	//}

	////////////////////////////////////////////////////////////////////////////////////////////
	_asm {
		imul ebx, ebx, 2
	}
	Timer<double> timer1;
	std::cout.precision(std::numeric_limits<double>::digits10);
	timer1.start();
	OPTION op;
	linked_rvalue<priority_second> lr;
	tree<std::string> ttree = lr.start("x+2");
	std::string _ret;
	//postorder_travel([&](std::string str) { _ret.append(str); }, ttree.travel());
	/*std::cout << "(5+3)*4-3+x^2+3*x^2" << std::endl <<
		_ret <<std::endl << std::endl;*/
	std::vector<std::string> a = _optimize_intercode_generator2(ttree);
	/*for(auto st : a)
		std::cout << st << std::endl;*/
	std::vector<std::string> b = _assembly_x86_macrostyle2(a);
	//std::cout << std::endl;
	/*for(auto st : b)
		std::cout << st << std::endl;*/
	rasm_test(assemble_code(b,op));
	timer1.finish();
	std::cout << std::endl <<*timer1;
	return 0;

	//_status87
	////////////////////////////////////////////////////////////////////////////////////////////

	/*HANDLE mem_handle = CreateFileMapping( 
			INVALID_HANDLE_VALUE, 
			NULL, 
			PAGE_EXECUTE_READWRITE, 
			0,  
			5, 
			NULL);

	void * function = (void *)(MapViewOfFile( 
			mem_handle, 
			FILE_MAP_ALL_ACCESS | FILE_MAP_EXECUTE, 
			0, 
			0, 
			5));
	memcpy(function, new char [5]{ 1, 45, 0, 0, 0 }, sizeof(new char [5]{ 0, 1, 0, 0, 0 }));
	memcpy(function, "\xff\xd8\x0\x0\x0", 10);*/

//	((void(*)())function)();

	////////////////////////////////////////////////////////////////////////////////////////////
	
	//std::vector<std::string> sst;
	//sst.push_back("nop");
	//sst.push_back("pusha");
	////sst.push_back("mov eax, 939");
	//sst.push_back("add ecx, 55");
	//sst.push_back("cmp ebx, eax");
	//sst.push_back("mul eax, 2");
	//sst.push_back("xor eax, eax");
	//sst.push_back("jmp 123456");
	//sst.push_back("popa");
	//sst.push_back("ret");
	//std::vector<BYTE> xtarr = s_assemble32(sst);
	////std::copy(xtarr.begin(), xtarr.end(), byteset);
	//BYTE* byteset= new BYTE[xtarr.size()], *ptr=byteset;
	//auto begin = xtarr.begin();
	//for (; begin != xtarr.end(); ++ptr, ++begin)
	//	*ptr = *begin;
	//for(auto st : xtarr)
	//{
	//	std::cout << std::hex << (int)st << " ";
	//}

	//memcpy(function, byteset, xtarr.size());
	//((void(*)())function)();

	////////////////////////////////////////////////////////////////////////////////////////////

	//Timer<double> timer;
	//String<> pt;
	////pt.Append("4*3/2+4-3*2");
	////pt.Append("4/(x-y)*(x+(z*y-3+c)*y)");3*4^(5-3)+2*x^2-4
	//pt.Append("3*4^(5-3)+2*x^2-4");
	//timer.start();
	//String<> t = make_regular(pt.c_str());
	//rvalue<> rvt;
	//tree<String<>> xttree = rvt.start(t.c_str());
	//timer.finish();
	//String<> __ret;
	//postorder_travel([&](String<> str) { __ret.Append(str); }, xttree.travel());
	//std::cout.precision(std::numeric_limits<double>::digits10);
	//std::cout << pt.c_str() << std::endl
	//	<< t.c_str() << std::endl
	//	<< __ret.c_str() << std::endl << std::endl << *timer
	//	//<< "Compiling..." << std::endl
	//	//<< rvt.pnt_assembly(ttree).c_str() << std::endl << std::endl
	//	;
	//urray<String<>> ur = _intercode_generator(xttree);
	//for(int i = 0; i < ur.size(); i++)
	//	std::cout << ur(i).c_str() << std::endl;

	////////////////////////////////////////////////////////////////////////////////////////////

	//String<> pt;
	////pt.Append("4*3/2+4-3*2");
	//pt.Append("4*3-3");
	//perpect_rvalue<> rvt;
	//tree<String<>> ttree = rvt.start(pt.c_str());
	//String<> _ret;
	//postorder_travel([&](String<> str) { _ret.Append(str); }, ttree.travel(), ttree.travel());
	//std::cout << pt.c_str() << std::endl
	//	<< _ret.c_str() << std::endl << std::endl
	//	//<< "Compiling..." << std::endl
	//	//<< rvt.pnt_assembly(ttree).c_str() << std::endl << std::endl
	//	;
	//urray<String<>> ur = _intercode_generator(ttree);
	//for(int i = 0; i < ur.size(); i++)
	//	std::cout << ur(i).c_str() << std::endl;

	////////////////////////////////////////////////////////////////////////////////////////////

	/*char *f = "emiyamulzomdao";
	int i = 9;
	printf("%c", 9[f]);

	char *fy[] = { "emiya", "mulzom", "dao" };
	int xf = 0;
	printf("%c", 1[2[fy]]);*/


	/*postorder_travel(
			[&](String<> str) 
		{ 
			_tmp.Append(str);
			_tmp.Append(" ");
		}
		, ty.travel(), ty.travel());

	std::cout << _tmp.c_str() << std::endl;*/

	//std::cout <<
	//	tx.pnt_assembly
	//	(
	//		tx.start("(t + 3) / (3 + 4)")
	//	).c_str()
	//	<< std::endl;

	//String<> _Tmp1("asd||rowefl||sdlcxr||wtlwt)");
	//urray<String<>> atd = _Tmp1.Split("||");
	////_Tmp1.Split("||");
	//
	//	for (int i = 0; i < atd.size(); i++)
	//	{
	//		std::cout << atd[i].c_str() << std::endl;
	//	}

	//urray<String<>> reslut1;

	//reslut1.Add(*new String<>("rollrat"));
	//reslut1.Add(*new String<>("rollrat1"));
	//reslut1.Add(*new String<>("rollrat2"));
	//reslut1.Add(*new String<>("rollrat3"));

	//for (int i = 0; i < reslut1.size(); i++)
	//	{
	//		std::cout << reslut1[i].c_str() << std::endl;
	//	}

	//std::cout << Replace("rollrat123sdf123qwerasd", "123", "321") << std::endl;
	//
	//std::cout << T.pnt_assembly(T.start("ch == 'A'")).c_str() << std::endl << std::endl;
	

	/*String<> _xtest;
	tree<String<>> x = T.start("('a' <= ch) && (ch <= 'z')");
	postorder_travel(
		[&](const String<> str) { _xtest.Append(str); }, 
		x.travel(), 
		x.travel());
	std::cout << _xtest.c_str();*/

/*
	tree<char *>::in_order_iterator xT(x._iterator());

	std::cout << *xT << std::endl;
	xT++;
	std::cout << *xT << std::endl;
	xT++;
	std::cout << *xT << std::endl;
*/
}

#include <stdio.h>
 
const char *전역변수;
 
int var();
int t1();
int factor();
void error();
int tx1;
int t2();
 
int var()
{
    int 임시 = t1();
    while((*전역변수 == '+') || (*전역변수 == '-'))
        if(*전역변수 == '+') 
        {
            전역변수++;
            임시 += t1();
        }
        else if(*전역변수 == '-')
        {
            전역변수++;
            임시 -= t1(); 
        }
    return 임시;
}
 
int t1()
{
    int 임시 = t2();
    while(*전역변수 == '*' || *전역변수 == '/')
        switch(*전역변수)
        {
        case '*':
            전역변수++;
            임시 *= t2();
            break;
        case '/':
            전역변수++;
            임시 /= t2();
            break;
        }
    return 임시;
}

int t2()
{
    int 임시 = factor();
    while(*전역변수 == '^')
        switch(*전역변수)
		{
		case '^':
			전역변수++;
            임시 ^= factor();
            break;
		}
    return 임시;
}
 
int factor()
{
    int 임시 = 0;
    if (*전역변수 == '(')
    {
        전역변수++;
        임시 = var();
        if (*전역변수 == ')')
        {
            전역변수++;
            return 임시;
        }
    }
    else if(('0' <= *전역변수) && (*전역변수 <= '9'))
    {
        while(true)
            if('0' <= *전역변수 && *전역변수 <= '9') 
            {
                임시 *= 10;
                임시 += *전역변수 - '0';
                전역변수++;
            }
            else
                break;
        return 임시;
    }
	else if(*전역변수 == 'x') 
	{
        전역변수++;
		return tx1;
	}
    else
        error();
}
 
void error()
{
    
}
 
int maain()
{
    int 결과값;
    char *식 = "x+2";
	tx1 = 1;
    전역변수 = 식;
	Timer<double> timer1;
	//linked_rvalue<> lr;
	timer1.start();
	//tree<std::string> ttree = lr.start("3*4^(5-3)+2*x^2-4");
	for (int x = 0; x < 100000 ; x++)
	{
		
	 전역변수 = 식;
		결과값 = var();
	}
	timer1.finish();
    printf("결과 = %d\n", 결과값);
	std::cout.precision(std::numeric_limits<double>::digits10);
	std::cout << *timer1;
    return 0;
}