/*done by M.S.SANJAY 15BCE0517*/
#include<stdio.h>
void main()
{
    int bt[100],p[100],wt[100],tat[100],i,j,n,pp,t;
    float tot=0;
    float awt,awtt;
    printf("enter the total number of processes:");
    scanf("%d",&n);
    printf("enter burst time for all process");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }

    for(i=0;i<n;i++)
    {
        pp=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pp])
                pp=j;
        }

        t=bt[i];
        bt[i]=bt[pp];
        bt[pp]=t;

        t=p[i];
        p[i]=p[pp];
        p[pp]=t;
    }

    wt[0]=0;


    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        tot+=wt[i];
    }

    awt=tot/n;
    tot=0;

    printf("\nprocess   burst time   waiting time   turnaround time\n");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        tot+=tat[i];
        printf("\n%d\t  %d\t\t    %d\t%d",p[i],bt[i],wt[i],tat[i]);
    }


    awtt=tot/n;
    printf("\n\nAverage Waiting Time=%f",awt);
    printf("\nAverage Turnaround Time=%f\n",awtt);
}
