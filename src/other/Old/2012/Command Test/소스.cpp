#include <Windows.h>
//#include <tchar.h>
#include <iostream>
#include <queue>
#include <regex>
#include <stdio.h>
//#include "rsyna.h"
//#include "rlib.h"
#include "ranal.h"

using namespace rts;

int main()
{
	Matcher A(CLO"[0128][9]");
	StringT F(CLO"sdf");

	A.SetText(CLO"2345679");

	unsigned char Fa[] = "123-456-7859-123-456";
	//char * p= mystrtok(Fa, "-");
	//printf("%s\n", p);
	//std::cout << "asdfdsf";
	printf("%s\n", A.Match());
	//printf("%s\n", strtok(Fa, "123"));
	printf("%c", F.ForwardCH(Fa,'4'));
	//printf("%s", F.Trim("   asd   "));
	getchar();
	//System::Console::WriteLine("adsfds");
	return 0;
}

char * __cdecl strtok (
        char * string,
        const char * control
        )
{
        char *str;
        const char *ctrl = control;

        unsigned char map[32];
        int count;

        /* Clear control map */
        for (count = 0; count < 32; count++)
                map[count] = 0;

        /* Set bits in delimiter table */
		//구분 기호 테이블에 비트를 설정
        do {
                map[*ctrl >> 3] |= (1 << (*ctrl & 7));
        } while (*ctrl++);

        /* If string is NULL, set str to the saved
         * pointer (i.e., continue breaking tokens out of the string
         * from the last strtok call) */
		//문자열이 NULL 인 경우, 저장된 포인터 
		//(즉, 마지막 strtok 호출에서 문자열에서 토큰 무단 계속)에 str을 설정
        if (string)
                str = string;

        /* Find beginning of token (skip over leading delimiters). Note that
         * there is no token iff this loop sets str to point to the terminal
         * null (*str == '\0') */
		//토큰의 시작을 찾습니다.(최초의 구분기호를 건너뛰고).
		//노트 : 토큰은 없습니다. 만약 루프셋str이 종점null을 가리킨다면.(iff는 오타같다.)
		//(*str == '\0')
        while ( (map[*str >> 3] & (1 << (*str & 7))) && *str )
                str++;

        string = str;
		
        /* Find the end of the token. If it is not the end of the string,
         * put a null there. */
		//토큰의 끝을 찾아보세요. 이 문자열의 끝없는 경우가 null을 넣어.
        for ( ; *str ; str++ )
                if ( map[*str >> 3] & (1 << (*str & 7)) ) {
                        *str++ = '\0';
                        break;
                }

        /* Determine if a token has been found. */
		//토큰이 발견되었는지 확인합니다.
        if ( string == str )
            return NULL;
        else
            return string;
}