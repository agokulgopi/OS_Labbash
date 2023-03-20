#include<stdio.h>
#include<stdlib.h>
int ttime,i,j,temp;
int rrobin(int pname[],int btime[],int n);
int main()
{
	int pname[10],btime[10],pname2[10],btime2[10];
	int n,x,z;
	printf("enter the no of process:");
	scanf("%d",&n);
	printf("Enter the process name & burst time for the process:\n");
	for(i=1;i<=n;i++)
	{
		printf("Enter the process name:");
		scanf("%d",&pname2[i]);
		printf("\nEnter the burst time for the process %d:",pname2[i]);
		scanf("%d",&btime2[i]);
	}
	printf("PROCESS NAME\t\tBURST TIME");
	for(i=0;i<=n;i++)
	printf("%d\t\t\t%d\n",pname2[i],btime2[i]);
	z=1;
	while(z==1)
	{
		ttime=0;
		for(i=0;i<=n;i++)
		{
			pname[i]=pname2[i];
			btime[i]=btime2[i];
		}
		printf("\npress 1.roundrobin \n2.exit\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				rrobin(pname,btime,n);
				break;
			case 2:
				exit(0);
				break;
		}
		printf("\n\n if you want to continue press1:");
		scanf("%d",&z);
	}
}
int rrobin(int pname[],int btime[],int n)
{
	int tslice;
	j=0;
	printf("\n\t round robin scheduling....");
	printf("\nenter the time slice:");
	scanf("%d",&tslice);
	printf("\nprocess name\t remaining time \ttotal time");
	while(j<n)
	{
		for(i=0;i<=n;i++)
		{
			if(btime[i]>0)
			{
				if(btime[i]>=tslice)
				{
					ttime+=tslice;
					btime[i]=btime[i]-tslice;
					printf("\n %d\t\t\t%d\t\t\t%d",pname[i],btime[i],ttime);
					if(btime[i]==0)
					j++;
				}
				else
				{	
					ttime+=btime[i];
					btime[i]=0;
					printf("\n %d\t\t\t%d\t\t\t%d",pname[i],btime[i],ttime);
				}
			}
		}
	}
}
