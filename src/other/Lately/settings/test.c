#include "md5.h"
#include <string.h>
#include <stdio.h>
#include "core.h"

static md5_byte_t *md5_test(const char * x)
{
	md5_state_t state;
	md5_byte_t digest[16];
	//char hex_output[16*2 + 1];
	//int di;
	md5_init(&state);
	md5_append(&state, (const md5_byte_t *)x, strlen(x));
	md5_finish(&state, digest);
	/*for (di = 0; di < 16; di++)
		printf("%02x", digest[di]);*/
	/*for (di = 0; di < 16; di++)
	    sprintf_s(hex_output + di * 2, sizeof(hex_output), "%02x", digest[di]);*/
	return digest;
}

int main()
{
	char *tx = "    rollrat";
	//printf("%s", md5_test(""));
	
	printf("%s\n",tx);
	slc_remove_ws(&tx);
	printf("%s",tx);
	{
		char *_temp = slc_alloc(3);
		_temp[0] = '\s';
	}
	return 0;
}