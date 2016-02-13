
#ifndef _STRMCH_
#define _STRMCH_

#include <string.h>

int strmch_rk(char first[], char last[])
{
	int first_len = strlen(first), last_len = strlen(last), t = 1, l1 = 0, l2 = 0;
	for(int i = 0; i < last_len - 1; i++)
		t = (t * 0xff) % 123;
	for(int i = 0; i < last_len; i++)
		l1 = (l1 * 0xff + first[i]) % 123, l2 = (l2 * 0xff + last[i]) % 123;
	for(int i = 0, j = 0; i <= first_len - last_len; i++){
		if(l1 == l2 && !strncmp(first + i, last, last_len))
			return i;
		j = (l1 - first[i] * t) % 123;
		if(j < 0)
			j += 123;
		l1 = (j * 0xff + first[i + last_len]) % 123;}
	return (-1);
}

int strmch_mp(char first[], char last[])
{
	int t[0xff];
	int first_len = strlen(first), last_len = strlen(last);
	*t = -1;
	for(int i = 1, j = -1; i < last_len; i++){
		while(j >= 0 && last[j + 1] != last[i])
			j = t[j];
		if(last[j + 1] == last[i])
			j++;
		t[i] = j;}
	for(int i = 0, j = -1; i < first_len; i++){
		while(j >= 0 && last[j + 1] != first[i])
			j = t[j];
		if(last[j + 1] == first[i])
			j++;
		if(j == last_len - 1)
			return i - last_len + 1;}
	return (-1);
}

#endif