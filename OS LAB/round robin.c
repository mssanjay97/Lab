#include<stdio.h>
int main()
{   int flip;
  int time,remain,flag=0,ts;
  float sum_wait=0,sum_turnaround=0;
  int i,j,n;
  int at[10],bt[10],rt[10];
  printf("enter totl number of processes:");
  scanf("%d",&n);
  remain=n;
  for(i=0;i<n;i++)
  {
    printf("\nEnter burst time:");
    scanf("%d",&bt[i]);
    printf("\nEnter arrival time:");
    scanf("%d",&at[i]);
    rt[i]=bt[i];
  }
  for(i=0;i<n;i++)
  {
      for(j=i+1;j<n;j++)
      {
          if(at[i]>at[j])
          {
              flip=at[i];
              at[i]=at[j];
              at[j]=flip;
              flip=bt[i];
              bt[i]=bt[j];
              bt[j]=flip;
              flip=rt[i];
              rt[i]=rt[j];
              rt[j]=flip;
          }
      }

  }
  printf("Enter time quanta:");
  scanf("%d",&ts);
  printf("\n\nProcess\t TURNAROUND time \tWAIT time\n\n");
  for(time=0,i=0;remain!=0;)
  {
    if(rt[i]<=ts && rt[i]>0)
    {
      time+=rt[i];
      rt[i]=0;
      flag=1;
    }
    else if(rt[i]>0)
    {
      rt[i]-=ts;
      time+=ts;
    }
    if(rt[i]==0 && flag==1)
    {
      remain--;
      printf("%d\t%d\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
      sum_wait+=time-at[i]-bt[i];
      sum_turnaround+=time-at[i];
      flag=0;
    }
    if(i==n-1)
      i=0;
    else if(at[i+1]<=time)
      i++;
    else
      i=0;
  }
  printf("\nAvg sum_wait = %f\n",sum_wait/n);
  printf("Avg sum_turnaround = %f",sum_turnaround/n);
  return 0;
}
