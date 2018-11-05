#include<stdio.h>
#include<math.h>
int main()
{
int windowsize,sent=0,acknw,i,m,p;
int n=1;
printf("Enter no. of bits:"); scanf("%d",&m);
p=pow(2,m);
printf("The no. of Packets has transmitted are: %d\n",p); windowsize=pow(2,m-1);
printf("The Windowsize is: %d\n",windowsize); while(1)
{
while(n>0)
{
for(i=0;i<windowsize;i++)
{
printf("Frame %d has been transmitted\n",sent); sent++;
if(sent==windowsize)
break;
}
n=0;
}
printf("\n Please enter the Acknowledgement received:\n"); scanf("%d",&acknw);
if(acknw>windowsize)
{
printf("All previous packetsreceived"); break;
}
else
{
sent=acknw;
printf("Resend the %d packet",sent);
}
}
return 0;

}
