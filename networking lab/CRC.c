#include <stdio.h>
#include <string.h>
int main()
{
 int i,j,divbit,databit,count=0;
 char data[100], div[30],temp[30],quot[100],rem[30],div1[30];
 printf("Enter the number of bits in the data :");
 scanf("%d",&databit);
 printf("Enter data: ");
 scanf("%s",data);
 printf("Enter the number of bits in the divisor:");
 scanf("%d",&divbit);
 printf("Enter divisor: ");
 scanf("%s",div);
 strcpy(div1,div);
 for(i=0;i<divbit-1;i++)
 {
	data[databit+i]='0';
 }
 for(i=0;i<divbit;i++)
	temp[i]=data[i];
 for(i=0;i<databit;i++)
 {
	quot[i]=temp[0];
	if(quot[i]=='0')
		for(j=0;j<divbit;j++)
			div[j]='0';
	else
		for(j=0;j<divbit;j++)
			div[j]=div1[j];
	for(j=divbit-1;j>0;j--)
		{
			if(temp[j]==div[j])
				rem[j-1]='0';
			else
				rem[j-1]='1';
		}
	rem[divbit-1]=data[i+divbit];
	strcpy(temp,rem);
 }
 strcpy(rem,temp);
 printf("\nRemainder is ");
 for(i=0;i<divbit-1;i++)
	printf("%c",rem[i]);
 printf("\nCRC code is: ");
 for(i=0;i<databit;i++)
	printf("%c",data[i]);
 for(i=0;i<divbit-1;i++)
 	printf("%c",rem[i]);

 return 0;
}
