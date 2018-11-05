#include<stdio.h>
#include<conio.h>
void main()
{
char frame[100],str[50];
char flag='z';
char esc='x';
int i,j,k=0,n;
frame[k++]='z';

printf("Enter String \n");

gets(str);

for(j=0;j<strlen(str);j++)
      {
    if(str[j]!=flag&&str[j]!=esc)
    {
        frame[k++]=str[j];
    }
    else{
        frame[k++]='x';
        frame[k++]=str[j];
    }
      }


frame[k++]='z';
frame[k++]='\0';

printf("\nByte stuffing at sender side:\n\n");

for(i=0;i<k;i++)
  {
printf("%c",frame[i]);
  }

printf("\nByte stuffing at receiver side\n\n");

for(i=0;i<k;i++)
  {
if(frame[i]=='x'|| frame[i]=='z')
     {
i++;
     }
printf("%c",frame[i]);
  }

}
