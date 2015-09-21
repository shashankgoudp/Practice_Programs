#include<stdio.h>
#include<string.h>
void strrevervse(char str[])
{
	int strlength = strlen(str);
	int i;
	char temp;
	while(i<strlength)
	{
		temp = str[i];
		str[i] = str[strlength-1];
		strlength--;
		i++;
	
	}
	
	printf("reversed string is %s\n",str);
	
	
}



int main()
{
	char *str = "hello";
	strrevervse(str);
	
	
}
