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
		//���� ��ȣ ���̺� ��Ʈ�� ����
        do {
                map[*ctrl >> 3] |= (1 << (*ctrl & 7));
        } while (*ctrl++);

        /* If string is NULL, set str to the saved
         * pointer (i.e., continue breaking tokens out of the string
         * from the last strtok call) */
		//���ڿ��� NULL �� ���, ����� ������ 
		//(��, ������ strtok ȣ�⿡�� ���ڿ����� ��ū ���� ���)�� str�� ����
        if (string)
                str = string;

        /* Find beginning of token (skip over leading delimiters). Note that
         * there is no token iff this loop sets str to point to the terminal
         * null (*str == '\0') */
		//��ū�� ������ ã���ϴ�.(������ ���б�ȣ�� �ǳʶٰ�).
		//��Ʈ : ��ū�� �����ϴ�. ���� ������str�� ����null�� ����Ų�ٸ�.(iff�� ��Ÿ����.)
		//(*str == '\0')
        while ( (map[*str >> 3] & (1 << (*str & 7))) && *str )
                str++;

        string = str;
		
        /* Find the end of the token. If it is not the end of the string,
         * put a null there. */
		//��ū�� ���� ã�ƺ�����. �� ���ڿ��� ������ ��찡 null�� �־�.
        for ( ; *str ; str++ )
                if ( map[*str >> 3] & (1 << (*str & 7)) ) {
                        *str++ = '\0';
                        break;
                }

        /* Determine if a token has been found. */
		//��ū�� �߰ߵǾ����� Ȯ���մϴ�.
        if ( string == str )
            return NULL;
        else
            return string;
}