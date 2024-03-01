#include <stdio.h>
int main()
{
	int one,two,three,four,five,six;
	scanf("%d\n",&one);
	scanf("%d",&two);
	three = one*(two%100%10);
	four =((two%100-two%100%10)/10)*one;
	five =((two-two%100)/100)*one;
	printf("%d\n",three);
	printf("%d\n",four);
	printf("%d\n",five);
	printf("%d",three+10*four+100*five);		
	return 0;
}