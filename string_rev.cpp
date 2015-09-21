#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *str ="Hello\0";
		
	printf("%s",str);
	
	char *temp;
	char *begin = str;
	char  *end = str;
	
	while(*end)
	{
		end++;
	}
	
	while(begin<end)
	{
		*temp = *begin;
		*begin = *end;
		*end = *temp;
		begin++;
		end--;
	}
	
	printf("%s",str);
}


