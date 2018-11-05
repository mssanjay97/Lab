/*DONE BY M.S.SANJAY 15BCE0517*/
#include<stdio.h>

void main()
{
    int n,bt[100],wt[100],tat[100],i,j;
    float awt=0;
    float atat=0;
    printf("enter the total number of processes:");
    scanf("%d",&n);
    printf("enter burst time for all process");
    for(i=0;i<n;i++)
    {

        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }

    printf("\nprocess   burst time   waiting time   turnaround time\n");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        awt+=wt[i];
        atat+=tat[i];
        printf("\n%d   %d   %d   %d",i+1,bt[i],wt[i],tat[i]);
    }
    awt/=n;
    atat/=n;
    printf("\naverage waiting time=%f",awt);
    printf("\naverage turnaround time=%f",atat);
}
