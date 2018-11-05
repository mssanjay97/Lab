#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
int a[20],b[30],i,j,k,count,n;
printf("enter length of frame-");
scanf("%d",&n);
printf("enter frame-");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
i=0;
j=0;
while(i<n)
{
if(a[i]==1)
{count=1;

b[j]=a[i];
for(k=i+1;a[k]==1 && k<n && count<5;k++)
{
j++;
b[j]=a[k];
count++;
if(count==5)
{
j++;
b[j]=0;
}
i=k;
}}
else
{
b[j]=a[i];
}
i++;
j++;
}

printf("After stuffing the frame is:");
printf("01111110");
for(i=0;i<j;i++)
printf("%d",b[i]);
printf("01111110");

}
