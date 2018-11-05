
#include<stdio.h>
#include<math.h>
int main()
{
int windowsize,sent=0,acknw,i,m,p;
printf("Enter no. of bits: ");
scanf("%d",&m);
p=pow(2,m);
printf("The no. of Packets that has transmitted are: %d\n",p); windowsize=pow(2,m)-1;
printf("The Windowsize is: %d\n",windowsize); while(1)
{
for(i=0;i<windowsize;i++)
{
printf("Frame %d has been transmitted\n",sent); sent++;
if(sent==windowsize)
break;
}
printf("\n Please enter the last Acknowledgement received:\n"); scanf("%d",&acknw);
if(acknw==windowsize)
break;
else
sent=acknw;
}
return 0;
}
