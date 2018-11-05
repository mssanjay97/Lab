//SANJAY M.S.
//15BCE0517
#include<stdio.h>
void main()
{
float fcfstime,sjftime,prioritytime;
int flip;
float awt=0,att=0;
int n,b[10],w[10],t[10];
int i,j,pn[10],p[10];
printf("PRE EMPTIVE SCHEDULING ALGORITHMS\n\n");
printf("How many processes do u what?\n");
scanf("%d",&n);
printf("\nEnter burst time and priority for %d processes\n",n);
for(i=0;i<n;i++)
{printf("\nENTER BURST TIME:");
scanf("%d",&b[i]);
pn[i]=i+1;
printf("\nENTER PRIORITY TIME:");
scanf("%d",&p[i]);
}
w[0]=0;
int time=b[0];
for(i=1;i<n;i++)
{
w[i]=time;
time=time+b[i];
awt+=w[i];
}
awt=awt/n;
for(i=0;i<n;i++)
{
t[i]=b[i]+w[i];
att+=t[i];
}
att=att/n;
printf("For fcfs scheduling the output is\n");
printf("PROCESS'S NUMBER\t\tBURST TIME\t\tWAITING TIME\t\tTURNAROUND TIME\n");
for(i=0;i<n;i++)
{

printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,b[i],w[i],t[i]);

}

printf("AVERAGE WAITING TIME IS=%f \t\t AVERAGE TURNARoUND TIME=%f \n",awt,att);

fcfstime=att;
att=0;awt=0;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if (p[j]<p[i])
{
flip=b[j];
b[j]=b[i];
b[i]=flip;
flip=pn[i];
pn[i]=pn[j];
pn[j]=flip;
flip=p[i];
p[i]=p[j];
p[j]=flip;
}

}
}

w[0]=0;
time=b[0];
for(i=1;i<n;i++)
{
w[i]=time;
time=time+b[i];
awt+=w[i];
}
awt=awt/n;
for(i=0;i<n;i++)
{
t[i]=b[i]+w[i];
att+=t[i];
}
att=att/n;
printf("for priority scheduling the output is\n");
printf("PROCESS'S NUMBER\t\tBURST TIME\t\tWAITING TIME\t\tTURNAROUND TIME\n");
for(i=0;i<n;i++)
{

printf("%d\t\t%d\t\t%d\t\t%d\n",pn[i],b[i],w[i],t[i]);

}
printf("AVERAGE WAITING TIME IS=%f \t\t AVERAGE TURNARoUND TIME=%f \n",awt,att);
prioritytime=att;
att=0;awt=0;

for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if (b[j]<b[i])
{
flip=b[j];
b[j]=b[i];
b[i]=flip;
flip=pn[i];
pn[i]=pn[j];
pn[j]=flip;

}

}
}

w[0]=0;
 time=b[0];
for(i=1;i<n;i++)
{
w[i]=time;
time=time+b[i];
awt+=w[i];
}
awt=awt/n;


for(i=0;i<n;i++)
{
t[i]=b[i]+w[i];
att+=t[i];
}
att=att/n;
printf("For shortest job first the output is\n");
printf("PROCESS'S NUMBER\t\tBURST TIME\t\tWAITING TIME\t\tTURNAROUND TIME\n");
for(i=0;i<n;i++)
{
printf("%d\t\t%d\t\t%d\t\t%d\n",pn[i],b[i],w[i],t[i]);
}
printf("AVERAGE WAITING TIME IS=%f \t\t AVERAGE TURNARoUND TIME=%f \n",awt,att);
sjftime=att;
if(prioritytime<sjftime&&prioritytime<fcfstime)
    printf("PRIORITY ALGORITHM IS BEST IN THIS CASE");
else if (sjftime<fcfstime&&sjftime<prioritytime)
    printf("SHORTEST JOB FIRST ALGORITHM IS BEST IN THIS CASE");
else
    printf("FIRST COME FIRST SERVE ALGORITHM IS BEST IN THIS CASE");
}
