// GCC4.9, VSC++2013에서의 컴파일이 확인되었음.

#include "ls_core.h"
#include "lsmc_core.h"

using namespace std;


#ifndef _DEBUG
int main(int argc, char * argv[])
#else
int main()
#endif
{
//	int  *ptr =0;
//	ptr = 0; 
//	init(0);
//	int const *const ** not_ptr =0;
//
//
//	void (*fp)();
//unsigned char buf[] =  "\xeb\x1e\x59\xb8\x04\x00\x00\x00\xbb\x01\x00\x00\x00\xba\x0f\x00\x00\x00\xcd\x80\xb8\x01\x00\x00\x00\xbb\x00\x00\x00\x00\xcd\x80\xe8\xdd\xff\xff\xff\x48\x65\x6c\x6c\x6f\x2c\x20\x57\x6f\x72\x6c\x64\x21\x0a\x00";;
//char const * p = reinterpret_cast<char const *>(&buf);
//std::copy(p, p + sizeof(char const *), reinterpret_cast<char*>(&fp));
//
//// now fp contains the same value as &buf
//((void(*)())fp)();
//

#ifndef _DEBUG
	if (argc != 3)
	{
		cout << "T : <target> <save>" << endl;
		return 0;
	}
	ifstream inf(argv[1], ios::in);
#else
	string redfile;
	cout << "openfilename : " << endl;
	cin >> redfile;
	ifstream inf(redfile, ios::in);
#endif

	if (inf.fail()) {
		cerr << "Unable to open file for reading!" << endl;
		return 1;
	}

	vector<string> str;
	int a = 0;

	while(!inf.eof())
	{
		char size_f[256];
		inf.getline(size_f, 256);
		str.push_back(size_f);
		a++;
	}

	inf.close();

	cout << "Lines : " << a << endl;
	
#ifndef _DEBUG
	ofstream onf(argv[2], ios::out);
#else
	string wrtfile;
	cout << "savefilename : " << endl;
	cin >> wrtfile;
	ofstream onf(wrtfile, ios::out);
#endif
	DWORD bytessize = 0;

	// CODING
		LINK lnk = Analyze(str, 0);
		vector<string> lnk_tmp = Optimization(lnk.assembly);
		vector<string> ty = lnk_tmp;
		vector<BYTE> ty1 = Link(lnk);
	// END CODING

	cout << "최적화 전 코드"<< endl;
	for(auto t : lnk.assembly)
	{
		cout << t << endl;
	}
	cout << "최적화 후 코드"<< endl;
	for(auto t : ty)
	{
		cout << t << endl;
	}

//#ifdef _DEBUG
//	onf << "최적화전 " << '\n';
//	for(auto tx : ty)
//	{
//		onf << tx << '\n';
//#ifdef _DEBUG
//		cout << tx << ' ';
//#endif
//		bytessize++;
//	}
//
//	cout << endl << "최적화전 바이트 : " << bytessize;
//	cout << endl;
//
//	onf << '\n' << "최적화후 " << '\n';
//#endif

	bytessize = 0;
	
	for(auto tx : ty1)
	{
		onf << tx;
#ifdef _DEBUG
		cout << tx << ' ';
#endif
		bytessize++;
	}
	
#ifdef _DEBUG
	cout << endl << "최적화후 바이트 : " << bytessize;
	cout << endl;
#endif
	
	onf.close();
	
	// END ANALYZE
	cout << "Complete" << endl << "Bytes : " << bytessize << endl;

	return 0;
}