#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int convert(char aIP[])
{
	int lBitsSet = 0;
	int lTemp = 0;
	char *ptr = NULL;

	ptr = strtok(aIP, ".");

	while(NULL != ptr)
	{
		lTemp = atoi(ptr);
		while(lTemp)
		{
			lBitsSet += (lTemp & 1);
			lTemp >>=1;
		}
		ptr = strtok(NULL, ".");
	}

	return lBitsSet;
}
int main()
{
	char lIP[17];
	memset(lIP, '\0', sizeof(lIP));

	strcpy(lIP, "255.255.255.255");

	printf("BIts set in IP are [%d]\n", convert(lIP));
	return 0;
}
