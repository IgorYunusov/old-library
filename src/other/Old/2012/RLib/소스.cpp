#include "algorithm.h"
#include "xlry.h"
#include <iostream>
#include "floor.h"
#include <functional>
#include <typeinfo>
#include "expression.h"
#include <regex>
#include "integer.h"
#include "parse.h"
#include "vector.h"
#include "xstring.h"
#include "xalloc.h"
#include "cmlxnum.h"
#include "tree.h"
#include <stdlib.h>
#include "sprintf.h"
#include "string.h"
#include "complex.h"
#include "enc_dec.h"
#include "xfunction.h"
#include "xregex.h"
#include "xpoint.h"
#include "pStr.h"
#include <thread>
#include <stdarg.h>

template<class _Ty1> inline
	void _pswap(_Ty1& _Left, _Ty1& _Right)
	{ // pointer swap
	_Ty1 temp = _Left;
	*_Left = *_Right;
	*_Right = *temp;
	}

char *itoa(long val, char *buf, unsigned radix = 10)
		{ // itoa
		char *p, *f, temp;
		unsigned dig_val;
		p = buf;
		if(radix == 10 && val < 0)
			{ // check signal of number
			*p++ = '-';
			val = ((unsigned long)(-(long)(val)));
			}
		f = p;
		do {
			dig_val = ((unsigned)(val % radix));
			val /= radix;
			if(dig_val > 9)
				*p++ = ((char)(dig_val - 10 + 'a'));
			else
				*p++ = ((char)(dig_val + '0'));
		} while(val > 0);
		*p-- = '\0';
		return buf;
		}

using namespace std;

using namespace xlib;
//
//auto it = [&](_X_LIB quark<int> *bd, 
//		int creation) -> _X_LIB quark<int> *
//		{
//		for(int ccc = creation; ccc != 0; ccc--)
//			bd = bd->C_UL(ccc);
//		return bd;
//		};

int main()
{
	_X_LIB ptr<int> a;
	int *b;
	b = _X_LIB _Allocate<int> (5);
	a = a = b;
	//maain();

	_X_LIB _REGEX_MODULE<> fasdfas;
	cout << fasdfas._check_strchrl("1234564444546", '4', 4) << endl;

	_X_LIB shared_ptr<char> aqrsdf;

	aqrsdf.realloc(21);

	for(int i = 0; i <= 21; i++)
		aqrsdf[i] = 'a' + i;
	
	for(int i = 0; i <= 21; i++)
		cout << aqrsdf[i];
	cout << endl;
	aqrsdf.realloc(21);
	for(int i = 0; i <= 21; i++)
		cout << aqrsdf(i);

	char asdfqw4t[21] = "1324578912345678900a";
	char asdf[30] = "qwetradzxxvcsadrfaqwetwettqew";
	_X_LIB _ptr_change(asdf, asdfqw4t);

	cout << asdf << endl;
	cout << asdfqw4t;

	cout << _X_LIB _ptr_spect(asdfqw4t);

	cout << endl <<  _X_LIB _ptr_find_match_n(_X_LIB _ptr_find_match("asdasdfatqwtsdafdfa","dfa"), "dfa");
	
	int gb = 0;

	char adpf[10000];

	_X_LIB str_n<> charspa;

	charspa << "concepct" << "check" >> "fuckyou";

	char *sdf = "klqhwjekrlhlk";
	char *wtr = "asdftus";
	char qw[20], wq[20];

	_X_LIB Xor_(sdf, wtr, qw);
	cout << qw << endl;

	_X_LIB Xor_(qw, wtr, wq);
	cout << wq << endl;

	_X_LIB Right_(wq, 1);
	cout << wq << endl;

	_X_LIB Left_(wq, 1);
	cout << wq;


	cout << charspa();

	char *s;
	s = ftoa<char> (2.9);

	cout << s;

	int sizeofhta[21][21] = {0, };
	_X_LIB inc_num<> funci(0);
	//for(int fxi = 0; fxi <= 10; fxi++)
	//	_X_LIB func_tetragon(sizeofhta, 20, 20, funci, fxi);
	_X_LIB func_snail(sizeofhta, 10, 10, funci, 5);
	for(int jkf = 0; jkf <= 10; jkf++){
		for(int jfk = 0; jfk <= 10; jfk++)
			printf("%5d", sizeofhta[jkf][jfk]);
		putchar('\n');
	}

	char stress[21];

	itoa(-602104, stress);

	cout << stress;

	int sizeofhtaa[21][21] = {0, };
	_X_LIB inc_num<> funcia(0);
	//for(int fxi = 0; fxi <= 10; fxi++)
	//	_X_LIB func_tetragon(sizeofhta, 20, 20, funci, fxi);
	for(int jkf = 0; jkf <= 10; jkf++){
		for(int jfk = 0; jfk <= 10; jfk++)
			printf("%5d", sizeofhtaa[jkf][jfk]);
		putchar('\n');
	}

	putchar('\n');
	putchar('\n');

	char *fask = "54646";
	unsigned char sizof[31][31] = {0, };
	_X_LIB snail_sort(sizof, 30, 30, fask, 15);
	for(int jkf = 0; jkf <= 30; jkf++){
		for(int jfk = 0; jfk <= 30; jfk++)
			printf("%c", sizof[jkf][jfk]);
		putchar('\n');
	}

	_X_LIB tree<int> trree;
	(*trree) = 10;
	trree.left(20);
	trree.right(30);
	trree.visit_left();
	(*trree) = 5;
	trree.right(40);
	trree.leave();
	trree.right(40);
	_X_LIB _tree_swap_sr_tr(trree);
	cout << (*trree) << endl
		<< trree.left()->_data << endl 
		<< trree.right()->_data << endl;
	
	_X_LIB tree<int> trees;
	*trees = 10;
	trees.left(20);
	trees.visit_left();
	trees.left(30);
	trees.right(40);
	trees.visit_right();
	trees.right(60);
	trees.leave();
	trees.leave();
	trees.right(50);

	_X_LIB UInteger<> ecx;
	
	char *ati = _X_LIB fast_cast<char *> ("asdfasdf");

	cout << ati;

	for(int i = 0; i <= 5000; i++)
		{
		ecx += i * 2;
		cout << ecx << ' ';
		}

	cout << endl << _X_LIB replace_ch_n("aldskfhhkjdasdl", 'd', 'e');

	_X_LIB vector<int> i;
	for(int asf = 0; asf <= 10000; asf++)
		i.push_back(asf);
	i.sort();
	cout << endl << _X_LIB _vector_element_count(i.front(), 500);
	for(int asd = 0; asd <= 9999; asd++)
		cout << i.pop_back() << endl;
	i.remove();

	_X_LIB string<char> strs("string experiment");
	_X_LIB string<char> ret("exper");
	_X_LIB string<char> got("bowbo");
	cout << *strs << endl;
	strs < "asdfasdf" < "asdfdsf" < ret < got;
	cout << *strs << endl;
	strs.reverse();
	strs < "asfasdfsdfasdfqwer";
	cout << *strs << endl;
	strs < strs < strs;
	cout << *strs << endl;
	
	_X_LIB cmlx<int> ints;
	//cout << *ints() << endl;

	_X_LIB string<char> strss("stering experiment");
	_X_LIB string<char> rets("exper");
	_X_LIB string<char> gots("bowbo");
	strss.replace_test(rets, gots);
	cout << *strss << endl;

	_X_LIB link<int> ab;
	for(int at = 0; at <= 500000; at++)
		ab.push_back(at % 96 * at);

	_X_LIB link<int>::iterator iter;
	for(iter = ab.begin(); iter != ab.end(); iter++)
		cout << *iter << endl;

	char *T = "41566411aa";
	char *F = "664";
	
	_X_LIB array<int> itttt;
	for(int a = 0; a <= 1000; a++)
		itttt.push_back(a);

	_X_LIB array<int>::const_iterator itc;
	for(itc = itttt.begin(); itc != itttt.end(); itc++)
		cout << *itc << endl;

	cout << _X_LIB _Search_C(T, F, 10, 3);

	cin.get();
	volatile char atg = 0;
	atg = 0;

	_X_LIB floor<int> floor;
	_X_LIB floor<int>::iterator _mkd;
	_X_LIB quark<int> *_kdq;
	floor.Create_UL(2);
	_kdq = floor.Up_Left()->C_UL(0);
	for(int at = 0; at <= 10000; at++)
		_kdq = _kdq->C_UL(at);
	_X_LIB UL_Hetero(_kdq);
	_mkd.Set(floor.begin());
	for( _mkd = floor.begin(); _mkd._UL(); )
		cout << *_mkd << endl;
	
	//it(_kdq, 100000);
	for( _mkd = floor.begin(); _mkd._UL(); )
		cout << *_mkd << endl;

}