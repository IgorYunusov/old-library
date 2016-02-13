#define _CRT_SECURE_NO_WARNINGS

#include "BigInteger.h"

#include "WStringBuilder.h"
#include "File.h"
#include "Displant.h"
#include "List.h"

#include <locale.h>
#include <tchar.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Sorting.h"

#include "DateTime.h"

#define _TIMER_OUTPUT
#include "Timer.h"

#include <cstdio>
#include <ctime>
#include "Interpolation.h"
#include "File.h"

#include "Base64.h"
#include <codecvt>

#include "Encoding.h"
#include "URLEncoding.h"

#include "WStringBuffer.h"

#include "Initialize.h"

#include <iostream>

#include "Regex.h"
#include "HashTable.h"

#include <regex>

#include "Vector.h"

#include "EquationTree.h"
#include "EquationIntercode.h"

#include "StringGenetic.h"
#include "Learning.h"

#include "VL\fraction.h"

using namespace Utility;
//
//#define void int
//
//#define five 5
//#define fix 6
//#define eleven 7
//#define MultipleTerminalSymbol *
//
//void main()
//{
//	int spuerStcak[five][fix][eleven] = {0,0,0,0,0,0,0,0,};
//	int __void = *reinterpret_cast<int *> (&spuerStcak);
//
//	for ( __void = __void & 0; false; __void + gets((char*)(void *)0))
//	{
//		(__void + fix)[*(spuerStcak + __void / five)][eleven / __void MultipleTerminalSymbol __void + eleven]
//			= (~__void + 2) / 0.123456f;
//	}
//
//	return void(__void);
//}

//int seed = 0;
//
//void seedgenerator()
//{
//	seed += 0x8538dcfb7617fe9full;
//	seedgenerator();
//}
//
//int get_random()
//{
//	try {
//		seedgenerator();
//	}catch (...){
//	}
//
//	return seed;
//}
//
//int main()
//{
//	printf("%d %d %d %d", get_random(), get_random(), get_random(), get_random());
//
//	return 0;
//}


		/*float diameter(float r)
		{
			long  t= *(long *)&r;
			t <<= 1;
			return *(float *)&t;
		}*/

size_t tsstrlen(const char* str)
{
	if (str[0] == 0) return 0;
	if (str[1] == 0) return 1;
	if (str[2] == 0) return 2;
	if (str[3] == 0) return 3;

	checker_type* trim = 
#ifdef _X64_MODE
				(checker_type *)(((checker_type)str & -8LL) + 8);
#else
				(checker_type *)(((checker_type)str & -4L) + 4);
#endif

#define _ZIF(n)  if( (trim[n] - _MAGIC) & ((_MAGIC) << 7) ) {trim += n; break;}

	while (true)
	{
	TRYRE:
		_ZIF( 0)_ZIF( 1)_ZIF( 2)_ZIF( 3)
		_ZIF( 4)_ZIF( 5)_ZIF( 6)_ZIF( 7)
		_ZIF( 8)_ZIF( 9)_ZIF(10)_ZIF(11)
		_ZIF(12)_ZIF(13)_ZIF(14)_ZIF(15)

		trim += 16;
	}

	if (!(trim[0] & ( 0xffUL << (8 * 0)))) return ((size_t)trim - (size_t)str) + 0;
	if (!(trim[0] & ( 0xffUL << (8 * 1)))) return ((size_t)trim - (size_t)str) + 1;
	if (!(trim[0] & ( 0xffUL << (8 * 2)))) return ((size_t)trim - (size_t)str) + 2;
	if (!(trim[0] & ( 0xffUL << (8 * 3)))) return ((size_t)trim - (size_t)str) + 3;
#ifdef _X64_MODE
	if (!(trim[0] & (0xffULL << (8 * 4)))) return ((size_t)trim - (size_t)str) + 4;
	if (!(trim[0] & (0xffULL << (8 * 5)))) return ((size_t)trim - (size_t)str) + 5;
	if (!(trim[0] & (0xffULL << (8 * 6)))) return ((size_t)trim - (size_t)str) + 6;
	if (!(trim[0] & (0xffULL << (8 * 7)))) return ((size_t)trim - (size_t)str) + 7;
#endif
	trim++; goto TRYRE;
}

int _tmain()
{
	_wsetlocale(LC_ALL, L"korean");

	std::locale::global(std::locale("kor"));
	std::wcout.imbue(std::locale("kor"));
	std::wcin.imbue(std::locale("kor"));

    Hopfield<4> hf5;

    hf5.AddPattern(new int64_t[4]{1,1,1,-1});
    hf5.AddPattern(new int64_t[4]{1,-1,1,-1});

   hf5.Transfer( hf5.Transfer(new int64_t[4]{1,1,-1,-1}));

   WString i = 123ws;

   LagrangeInterpolationInt<int64_t> lii;

lii.AddValue(1, 1);
lii.AddValue(2, 3);
lii.AddValue(3, 5);
lii.AddValue(4, 7);
lii.AddValue(5, 217341);

std::wcout << lii.GetInterpolation() << std::endl;
std::wcout << lii.GetInterpolation(true) << std::endl;

   basic_fraction<256> k("1");

	//std::cout << diameter(2.5f);
	//std::cout << diameter(2.5f);

	//std::wcout << WString(L"zl2cpJ3QgkHZyFGVg0CIhMXazlmcDBSdr92aph2Q").Substring(20);

	//int b[12] = { 0, };

	//printf("%d", a[1]);

	/*int k, i, j, t;

	t = 50;
	j = 100;

	for (k = 0, i = 0; i < sizeof(unsigned int) * 8; i++)
   if (j & (1 << i))
      k += t >> i;

	FILE* fp = fopen("c:\\rollrat\\sosu.txt", "w+");

	for (int i = 0; i < 600; i++)
	{
		fprintf(fp,"if (x %% %d)\n        break;\n    else ", i);
	}

	*/
	LagrangeInterpolationInt<long long> ipa;

	ipa.AddValue(4, 0);
	ipa.AddValue(6, 0);
	ipa.AddValue(9, 0);
	ipa.AddValue(11, 0);

	std::wcout << ipa.GetInterpolation();
	
	// 3%
	char text[] = "koromo";
	StringGeneticField<sizeof(text) / sizeof(text[0]) - 1, 10, 100, 100> sgf(text);

	do {
		//sgf.print_all();
		sgf.evolution();
	} while( !sgf.check_generation() );
	sgf.print_all();
	std::cout << std::endl << "Evolution Count: " << sgf.get_generation();


	//Line2 a = Line2(20,30,10,20).straight();

	auto cout_element = [] (const WString& str) {
		std::wcout << str;
	};

	auto tree_test = [&] (const wchar_t* fomula) {
		EquationTree<oprator_priority> pr;
		BinaryTree<WString> ttree = pr.start(fomula);
		
		ttree.postorder_travel(cout_element); std::wcout << std::endl;
		//ttree.preorder_travel([](const WString& str) {std::wcout << str; }); std::wcout << std::endl;
		//ttree.inorder_travel([](const WString& str) {std::wcout << str; }); std::wcout << std::endl;

		std::vector<WString> a = _intercode_generator2(ttree);
		for (auto st : a)
			std::wcout << st << std::endl;
		
		std::wcout << std::endl;
	};
	
	tree_test(L"y+y*(y-z)*z+z*sin(x-y)");
	tree_test(L"(1-y)*(6-z)/(7-x)");
	tree_test(L"1+x&&y+2");
	tree_test(L"a+(a&&b)+(a&&b&c)+(a&&b&c<d)+(a&&b&c<d<<e)+(a&&b&c<d<<e%f)"
              L"+(a&&b&c<d<<e%f+g)+(a&&b&c<d<<e%f+g*h)");
	tree_test(L"a*l&b%z==k+i&&z>>j");
	tree_test(L"(A >= 0 && A < 9) || (A >= '0' && A < '9')");
	tree_test(L"3+4*(5+6)");
	tree_test(L"a+a+a");
	tree_test(L"x+y");

	//testfind();

	//std::cout << slice("01%%23%%456",strlen("01%%23%%456"),0,2,2);

	//std::wcout <<WString("01%%23%%456").Slicing(2,0,2);
	
//	std::wcout << WString("123").PadCenter(5,L'l', false);
//	std::wcout << WString("rollrat lab software").RemoveReverse(0, 0);
//
//	
//std::wcout << WString("rollrat lab software").RemoveReverse(4); // -> "ware"
//std::wcout << WString("rollrat lab software").RemoveReverse(8, 4); // -> "rollrat software"

	//WString("ro||ll||rat").SplitReverse("||");

	//std::wcout << WString("[rollrat]").Slice(1, 7); ; // -> 1,234,567,890;
	//std::wcout << WString("[rollrat]").Slice(1, -1); ; // -> 1,234,567,890;
/*
	Initialize ini(L"c:\\rollrat\\f.txt");

	ini.Get("t", "t\=");
	*/
/*
	wchar_t* str = L"rollratrollrat";

	wchar_t* cst = wcsnstrn(str, wcslen(str), L"rat", 4);
*/
	// InsertLeft: 왼쪽부터 일정구간씩 띄어 문자(열) 삽입
	// InsertRight: 오른쪽부터 일정구간씩 띄어 문자(열) 삽입
	//WString wstr7(L"123456789");
	//std::wcout << wstr7.InsertLeft(3, L',') << std::endl;
	//// -> "123,456,789"
	//std::wcout << wstr7.InsertRight(3, L"sss") << std::endl;
	//// -> "123sss456sss789"

	/*LagrangeInterpolationInt<int> lil;

	lil.AddValue(2, 41);
	lil.AddValue(3, 73);
	lil.AddValue(4, 0);
	lil.AddValue(5, 23);

	std::wcout << lil.GetInterpolation();

	int x = 7;

	int y = 67 / 2 * x*x*x + -354 * x*x + 2331 / 2 * x + -1142;
*/

	/*BigInteger bi;

	bi.Add("5555");
	bi.Div("55");
*/

	/*for (int i = 0; i < 50; i++)
	{
		bi.Mul("2");
		std::cout << bi.get() << std::endl;
	}*/

	//WString(L"rollratrollrat").Contains(L"RAT", true);

	//size_t ta = sizeof(size_t);

	////std::wcout << WString("rolollrat").Replace("ol", "Q");
	//wchar_t t[] = L"rollratrollratr";

	//wcountch(t, L'r', t + sizeof(t) / 2 - 2);

	/*HashTable<int, WString, 2> ht;

	ht.Append(1, L"1");
	ht.Append(2, L"2");
	ht.Append(3, L"3");
	ht.Append(4, L"4");
	ht.Append(5, L"5");
	ht.Append(6, L"6");

	ht.Get(L"5");*/

	//size_t x = strlentx("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdf");

	//std::wcout << WString(L'a', 7);

	//bool x = WString(L"rollrat").EndsWith(L"rat");
	//size_t pos = WString(L"testtest").FindLast(L"est");

	/*wchar_t *a = WString(L"rollrat|rollrat*rollrat").Insert(1, L"t1").ToArray();

	std::wcout << a;*/
	//

	//std::wcout << WString(L"rollrat").StartsWith(L"ro");

	//std::wcout << WString(L"r[op]q").Between(L'[', L']');

	//WString(L"[0]][1[2]").Betweens(L'[', L']').Each([](const WString *a) { std::wcout << *a << std::endl; });

	////std::wcout << WString("rollrat");

	//std::wcout << URLEncoding::Encode(L"한국어");

	//std::wcout << WString(L"rollratrollrat").FindLast(L'r');

	//Encoding::AnsiToUnicode("rollrat", 7);

	

	//std::wcout<< std::endl << Base64::Base64Encode(L"베이스 육십사 및 라인브레이크 테스트");

std::wcout << WString("rollratrollrat").LineBreak(4);

   WString(L"012\r\n345678\n9abcde\nfghijklmnop\n").LineSplit().Each(
[&] (const WString* re) {
	std::wcout << *re << std::endl;
});

	WString::Lines wlines = WString(L"0123456789abcdefghijklmnop").LineSplit(10, L" ->> ", L" <<- ");
	wlines.Each([&] (const WString* re) {
		std::wcout << *re << std::endl;
	});

	//WString linet = WString(L"012346").LineBreak(9);

	////std::wcout << WString(L"ro").Hash();

	/*for (int i = 100000; i < 9999999; i++)
	{
		std::wcout << WString(i).Hash() << std::endl;
	}*/
	
	/*DateTime dt;
	std::wcout << dt.Format("yyyy년 MMMM dd일 dddd tt hh시 mm분 ss초", true) << std::endl;*/

	//std::wcout << WString(L"asdf asdfq qr").Title();
	
	/*WString spt(L"asdf123asdf123qwer123zxcv123a");
	WString::SplitsArray sa = spt.SplitReverse(L"123", 5);
	
	for ( size_t i = 0; i < sa.Size(); i++ )
		std::wcout << *sa[i] << std::endl;
*/

	/*std::wcout << URLEncoding::Encode(L"한국어/eng /初めまして。") << std::endl;
	std::wcout << URLEncoding::Decode(L"%ED%95%9C%EA%B5%AD%EC%96%B4%2Feng+%2F%E5%88%9D%E3%82"
									  L"%81%E3%81%BE%E3%81%97%E3%81%A6%E3%80%82");*/

	//std::wcout << Utility::URLEncoding::Encode(L"한국어 인코딩 테스트 ansi code test 日本語テスト");

	/*WString ws(L"rollratrollrat");
	ws.LastIndexOf(L"jlr");

	std::wcout << ws.Slice(1, -1);
	std::wcout << ws.Replace(L"r", L"");

	WString wss(L"0xffff");
	std::wcout << wss.ToHexDigit() << std::endl;


	WString titletest(L"roll rat start ma");
	std::wcout << titletest.Title() << std::endl;*/

	//std::wcout << WString(L"ollol").LastContains(L"l");

	//std::wcout << titletest.Count(L'm');

	//FileEnumerateW few(L"c:\\", FileEnumerateOption::SkipFileName);
	/*WStringBuilder sb;*/

	/*std::wcout << Base64::Base64Encode("encoding hello world");

	Base64::Base64ArrayType bat = Base64::Base64Decode(Base64::Base64Encode("rollrat"));
	std::wcout << (char *)bat.Array();*/

	/*int t = Encoding::ToUtf8Ch(WString(L"rollrat").Reference()[1]);
	std::wcout << t;*/

	char *strp[] = {"abce", "def", "ghi", "jklm", "asdf"};
	std::cout << sizeof(strp);

	WStringBuffer wsb;
	for (int i = 0; i < 200; i++)
	{
		wsb.Append(L"t123456tqw98er7a5sd4f65z4x65cv1c65sd4af");
		wsb.Append(L'Z');
	}

	std::wcout << wsb.ToString();

	FileIO::WriteFilew(L"C:\\rollrat\\734.txt", Base64::Base64Encode(FileIO::ReadByte(L"C:\\rollrat\\r.txt")));

	Base64::Base64ArrayType bat1 = Base64::Base64Decode(FileIO::ReadFileA(L"C:\\rollrat\\734.txt"));
	FileIO::WriteByte(L"C:\\rollrat\\734_tmp.txt", bat1.Array(), bat1.Size());

	//std::cout << Base64::Base64Decode("MjAxNTExMDgwMDAzMTgHMTQ0NjkwOTE1OTcxNQdibG9nB3JvbGxyYXQHNTI0Mjg4MDAHMgdkNjA0MjY2YjBmYmYzOWY0ZGFkYWI4ZDE1ZGU3ZTlhNw").Array();


	/*for (int i = 0; i <= 0xff; i++)
	{
		std::cout << "L\"%" << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << i << "\",";
	}*/

	// ??
	//wprintf(L"%s", URLEncoding::Encode(L"asdfasdf").Reference());
	std::wcout << URLEncoding::Encode(L"인간/사람/ /初めまして。/下石上臺.");
	std::wcout << URLEncoding::Decode(URLEncoding::Encode(L"/인간/사람/ /初めまして。/下石上臺."));

	std::wcout << (wchar_t *)Base64::Base64Decode(L"0Bw9rkWMVvJZCYVo4QVNtbzA4ZzQ").Array();

	//do
	//{
	//	sb.Append(few.GetFullName());
	//	sb.Append(L"\r\n");
	//	//std::wcout << few.GetFullName().Reference() << std::endl;
	//} while (few.NextFile());

	//FileIO::WriteFile(L"C:\\rollrat\\t.txt", sb.ToString());

	//FileEnumerateRecursionW ferw(L"C:", FileEnumerateOption::SkipDirectoryName);

	//ferw.start([&](const WString& ws) -> void 
	//{
	//	std::wcout << FileStringW::GetDirectory(ws).Reference() << std::endl; 
	//	//sb.Append(ws.Reference());
	//	//sb.Append(L"\r\n");
	//});

	//FileIO::WriteFile(L"C:\\rollrat\\t.txt", sb.ToString());

	/*FileIO::ReadFileByLines(L"C:\\rollrat\\t.txt", [&](const WString& ws) -> void 
	{
		std::wcout << ws.Reference() << std::endl;
	}, 2);*/

	/*std::wcout << HangulConverter::EngToHan3(L"jdskfsjgs ibjtqjgyv nfhgskfB").ToArray() << std::endl;
	std::wcout << HangulConverter::HanToEng3(L"인간은 무엇으로 사는가?").ToArray();

	List<int> l;

	l.Append(1);
	l.Append(2);
	l.Append(3);
	l.Append(4);
	l.Insert(1, 4);

	int *lr = l.ToArray();

	for (int i = 0; i < 5; i++)
		std::wcout << lr[i];*/

	//////////////////////////////////////////////////////////

	/*DateTime dt;

	std::wcout << dt.Format(L"yyyy년 MMMM dddd tt hh시 mm분 ss초", true) << std::endl;
	std::wcout << dt.Format(L"dddd/MMMM/yyyy TT hh:mm:ss") << std::endl;

	DateTime ds(2015, 1, 2);
	DateTime dy(2015, 1, 6);
	DateTime st = ds.Subtract(dy);
	
	std::wcout << st.Format(L"dd일 차이") << std::endl;*/

	/*WString ws(L"1234567890");
	std::wcout << ws + ws;*/
	
	/////////////////////////////////////////////////////////////////////

	//WString ref;
	//wchar_t tmp[256] = L"C:\\";
	//wchar_t *context = nullptr;

	//size_t addr_len = wcslen(tmp);

	//if (tmp[addr_len - 1] == L'\\' && addr_len != 3)
	//{
	//	addr_len -= 1;
	//	tmp[addr_len - 1] = 0;
	//}

	//WString addr(tmp);

	//WStringBuilder sb(1024 * 1024 * 8);
	//FileEnumerateRecursionW ferw(addr_len == 3 ? addr.Substring(0, 2) : addr, FileEnumerateOption::SkipDirectoryName);

	//ferw.start([&](const WString& ws) -> void
	//{
	//	sb.Append(FileStringW::GetFileName(ws).Reference());
	//	sb.Append(L"****", 4);
	//	/*DateTime dt(ferw.getdata().ftCreationTime);
	//	std::wcout << dt.Format(L"yyyy년 MMMM dd일 tt hh시 mm분 ss초", true) << std::endl;*/

	//});

	//FileIO::WriteFile(L"C:\\rollrat\\r.txt", sb.ToString().Replace(L"****", L"||||"));

	//WString* ws = sb.ToString().Split(L"*").Array();
	//size_t sz = sb.ToString().Len(L"*");

	//std::wcout << L"배열 요소 개수: " << sz << std::endl;
	//
	//Sorting<WString> sort(ws, sz);

	//for (int i = 0; i < sz; i++)
	//{
	//	//std::wcout << ws[i].Reference() << std::endl;
	//	// unicode save out
	//	wprintf(L"%s\n", ws[i].Reference());
	//}

	/////////////////////////////////////////////////////////////////////

	LagrangeInterpolation<long double> ip;

	ip.AddValue(1, 2);
	ip.AddValue(2, 3);
	ip.AddValue(3, 1);
	ip.AddValue(4, 4);
	//ip.AddValue(9, 4);
	//ip.AddValue(5, 4);
	//////ip.AddValue(10000, 5);


	/////*for (int i = 0; i < 10; i++)
	////{
	////	ip.AddValue(i, i-1);
	////}*/

	////FileIO::WriteFile(L"c:\\rollrat\\9asd.txt", ip.GetInterpolationNoCalc());
	//
	std::wcout << ip.GetInterpolationNoCalc() << std::endl;
	std::wcout << ip.GetInterpolation() << std::endl;
	
	// 1->2
	// 3->5
	// 4->4
	// 5->4
	// 9->4
	// 10000->5
	//int x = 9;

	//double j = 5.20969e-006*x*x*x*x*x+-0.0521979*x*x*x*x+1.01133*x*x*x+-6.57624*x*x+16.7449*x+-9.12781;

	/*for (int x = -50; x < 100; x++)
	{
		double k = 
			 (x - 1)*(x - 2)*(x - 3)*(x - 4)*(x - 5)*(x - 6)*(x - 7)*(x - 8)*(x - 9) / 
			((0 - 1)*(0 - 2)*(0 - 3)*(0 - 4)*(0 - 5)*(0 - 6)*(0 - 7)*(0 - 8)*(0 - 9)) * 0 + 
			 (x - 0)*(x - 2)*(x - 3)*(x - 4)*(x - 5)*(x - 6)*(x - 7)*(x - 8)*(x - 9) / 
			((1 - 0)*(1 - 2)*(1 - 3)*(1 - 4)*(1 - 5)*(1 - 6)*(1 - 7)*(1 - 8)*(1 - 9)) * 1 + 
			 (x - 0)*(x - 1)*(x - 3)*(x - 4)*(x - 5)*(x - 6)*(x - 7)*(x - 8)*(x - 9) / 
			((2 - 0)*(2 - 1)*(2 - 3)*(2 - 4)*(2 - 5)*(2 - 6)*(2 - 7)*(2 - 8)*(2 - 9)) * 2 + 
			 (x - 0)*(x - 1)*(x - 2)*(x - 4)*(x - 5)*(x - 6)*(x - 7)*(x - 8)*(x - 9) / 
			((3 - 0)*(3 - 1)*(3 - 2)*(3 - 4)*(3 - 5)*(3 - 6)*(3 - 7)*(3 - 8)*(3 - 9)) * 3 + 
			 (x - 0)*(x - 1)*(x - 2)*(x - 3)*(x - 5)*(x - 6)*(x - 7)*(x - 8)*(x - 9) / 
			((4 - 0)*(4 - 1)*(4 - 2)*(4 - 3)*(4 - 5)*(4 - 6)*(4 - 7)*(4 - 8)*(4 - 9)) * 4 + 
			 (x - 0)*(x - 1)*(x - 2)*(x - 3)*(x - 4)*(x - 6)*(x - 7)*(x - 8)*(x - 9) / 
			((5 - 0)*(5 - 1)*(5 - 2)*(5 - 3)*(5 - 4)*(5 - 6)*(5 - 7)*(5 - 8)*(5 - 9)) * 5 + 
			 (x - 0)*(x - 1)*(x - 2)*(x - 3)*(x - 4)*(x - 5)*(x - 7)*(x - 8)*(x - 9) / 
			((6 - 0)*(6 - 1)*(6 - 2)*(6 - 3)*(6 - 4)*(6 - 5)*(6 - 7)*(6 - 8)*(6 - 9)) * 6 + 
			 (x - 0)*(x - 1)*(x - 2)*(x - 3)*(x - 4)*(x - 5)*(x - 6)*(x - 8)*(x - 9) / 
			((7 - 0)*(7 - 1)*(7 - 2)*(7 - 3)*(7 - 4)*(7 - 5)*(7 - 6)*(7 - 8)*(7 - 9)) * 7 + 
			 (x - 0)*(x - 1)*(x - 2)*(x - 3)*(x - 4)*(x - 5)*(x - 6)*(x - 7)*(x - 9) / 
			((8 - 0)*(8 - 1)*(8 - 2)*(8 - 3)*(8 - 4)*(8 - 5)*(8 - 6)*(8 - 7)*(8 - 9)) * 8 + 
			 (x - 0)*(x - 1)*(x - 2)*(x - 3)*(x - 4)*(x - 5)*(x - 6)*(x - 7)*(x - 8) / 
			((9 - 0)*(9 - 1)*(9 - 2)*(9 - 3)*(9 - 4)*(9 - 5)*(9 - 6)*(9 - 7)*(9 - 8)) * 9;

		std::cout << x << std::endl;
	}*/

	
	return 0;
}