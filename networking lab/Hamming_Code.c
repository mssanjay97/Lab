#include<stdio.h>
#include<math.h>
int main(){
	int n,i,j,k,ip,r,temp,p;
	int data[30],final[30],parity[10];
	printf("\nEnter Number of bits:");
	scanf("%d",&n);
	printf("\nEnter the data to be sent:");
	scanf("%d",&ip);
	for(i=n-1;i>=0;i--)
	{
		data[i]=ip%10;
		ip=ip/10;
	}
	for(r=1;r<n;r++)
		{
			if(n<=pow(2,r)-1-r){
			break;
		}
	}
	for(i=1;i<=n+r;i=i*2)
	{
		final[i]=-1;
	}
	for(i=1,j=0;i<=n+r;i++){
		if(final[i]!=-1){
			final[i]=data[j];
			j+=1;
		}
	}
	for(i=0;i<r;i++){
		p=pow(2,i);
		temp=0;
		for(j=p;j<=n+r;j=j+2*p){
			for(k=0;k<p && j+k<n+r ;k++){
				if(final[j+k]!=-1){
					temp=final[j+k]^temp;
				}
			}
		}
		parity[i]=temp;
	}
	for(i=1,j=0;i<=n+r;i++){
		if(final[i]==-1){
			final[i]=parity[j];
			j+=1;
		}
	}
	printf("Hamming Code=");
	for(i=1;i<=n+r;i++){
		printf("%d",final[i]);
	}
	printf("\n");
}
