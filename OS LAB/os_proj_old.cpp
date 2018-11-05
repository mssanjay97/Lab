#include<iostream>
using namespace std;
#include<omp.h>
#define max 100
 int mycolour=0;//0 for black 1 for white
    int flag[max];
    int colour[max];
    int number[max];

int maxim(int num,int colourc)
{
 int i,j,high;
high=0;

     for(j=0;(j<max);j++)
     {
        if((number[j]>high)&&(colour[j]==colourc))
        high=number[j];
     }

    return (high+1);

}
int main() {
    int i,j;

    for(i=0;i<max;i++)
    {
        flag[i]=0;//initial
        number[i]=0;//process not arrived so priority 0;

    }
    //entry section


    for(i=0;i<max;i++)
    {

        colour[i]=-1;

    }
//assign  priority number to each process
    #pragma omp parallel for private(j)
    {
    for(i=0;i<100;i++)
    {  flag[i]=1;
    colour[i]=mycolour;
    number[i]=maxim(i,colour[i]);
    flag[i]=0;
       for(j=0;j<max;j++)
        {
            while(flag[j]);
            if (colour[j]==colour[i])
            while(number[j]!=0 && number[j]<number[i] && colour[i]==colour[j]);
            else
            while(number[j]!=0 &&colour[i]==mycolour &&colour[j]!=colour[i]);


        }
         //critical section
 cout<<"\nProcess "<<i<<" executing in critical section\n";
    //exit section
            if(colour[i]==1)
             mycolour=0;
            else
            mycolour=1;
            number[i]=0;

    }

    }
    return 0;
}
