//
//	rollrat Api Service string funtion
//

#pragma once
#if !defined(NULL)
#define NULL 0
#endif
char * itoa(int i)
{
	static char buf[21];
	char *p = buf + 19 + 1;
	if (i >= 0) {
		while (i != 0)
		{
			*--p = '0' + (i % 10);
			i /= 10;
		} 
		return p;
	}else{
		while (i != 0)
		{
			*--p = '0' - (i % 10);
			i /= 10;
		}
		*--p = '-';
	}
	return p;
}
int atoi(const char * intStr)
{
	if (intStr == NULL) 
		return 0;
	else{
		static int int_str;
		int mark = 1;
		while (*intStr != NULL && (*intStr == ' '))
			intStr++;
		if (*intStr == '-')
			mark = -1;
		intStr++;
		while(*intStr != NULL && '0' <= *intStr && *intStr <= '9')
		{
			int_str = (int_str * 10) + (*intStr - '0');
			intStr++;
		}
		return mark * int_str;
	}
}
int strlen(const char * pStr)
{
	const char * O_pStr = pStr;
	while(*O_pStr++){  }
	return (O_pStr - pStr - 1);
}
char * strtok(char * src, char * sep)
{
     static char * next = NULL;
     static int next_len;
     static int next_count;
     char * start = NULL;
     int i;
     if(src)
	 {
         next = src;
         next_len = strlen(next);
         next_count = 0;
     }
     start = next;
     while(*next) 
	 {
		 for(i = 0; i < strlen(sep); i++) 
		 {
             if(*next == *(sep + i)) 
			 {
                 if(next == start) 
				 {
                     start++;
                     continue;
                 }   
                 *next = 0;
                 next++;
                 next_count++;
                 return start;
             }   
         }   
         next++;
         next_count++;
     }   
     if(next_len == next_count++)
	 {
		 return start;
	 }
     return NULL;
}
char * ReadCharSplit(char * rCharText,char * fSplit,int Arrange)
{
	char * SplitData;
	int i = 0; 
	SplitData = strtok(rCharText,fSplit);
	while( i != Arrange)
	{
		SplitData = strtok(NULL,fSplit);
		i++;
	}
	return SplitData;
}

