#include <stdio.h>
int main()
{
	int i,max,index;
	max = 0;
	int array[9];
	for(i=0;i < 9; i++)
	{
		scanf("%d\n",&array[i]);
		if (max<array[i])
		{
			max = array[i];
			index = i;
		}
	}
	printf("%d\n%d",max,index+1);
    return 0;
}