#include<stdio.h>
int main()
{	//initialization of variable
	int ch,m,n,x,start,i,j,pos,min,a[15],count;
	count=0;
	
	//recieving inputs
	printf("\nEnter the number of cylinders :");
	scanf("%d",&m);
	printf("\nEnter the number of requests :");
	scanf("%d",&n);
	printf("\nEnter current position :");
	scanf("%d",&start);
	
	//reading tracklist
	printf("\nEnter the request queue :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>=m)	
		{
			printf("\ninvalid input");
			scanf("%d",&a[i]);
		}
	}
	
	
	do
	{
		printf("\n\nDISK SCHEDULING ALGORITHMS\n1. FCFS\n2. SCAN\n3.C-SCAN");
		printf("\nEnter choice :");
		scanf("%d",&ch);
		count=0;
		x=start;
		switch(ch)
		{
			case 1:printf("\nFCFS :\n");
				printf("Scheduling services the request in the order that  follows:\n%d\t",start);
				for(i=0;i<n;i++)	//finding total count(head movement)
				{
					x-=a[i];
					if(x<0)
					x=-x;
					count+=x;
					x=a[i];
					printf("%d\t",x);
				}
				printf("\nTotal Head Movement :%d Cylinders",count);
				break;
				
				
			case 2:printf("\nSCAN :\n");
				printf("Scheduling services the request in the order that follows:\n");
				count=0;
				pos=0;
				
				//sorting 
				for(i=0;i<n;i++)
				for(j=0;j<n-i-1;j++)
				if(a[j]>a[j+1])
				{
					x=a[j];
					a[j]=a[j+1];
					a[j+1]=x;
				}
				
				
				for(i=0;i<n;i++)
					if(a[i]<start)	
					pos++;
				for(i=0;i<pos;i++)
					for(j=0;j<pos-i-1;j++)
					if(a[j]<a[j+1])
					{
						x=a[j];
						a[j]=a[j+1];
						a[j+1]=x;
					}
				x=start;
				printf("%d\t",x);
				for(i=0;i<pos;i++)
				{
					count+=abs(a[i]-x);
					x=a[i];
					printf("%d\t",x);
				}
				count+=abs(x-0);
				x=0;
				printf("%d\t",x);
				for(i=pos;i<n;i++)
				{
					count+=abs(a[i]-x);
					x=a[i];
					printf("%d\t",x);
				}
				printf("\nTotal Head Movement: %d Cylinders",count);
				break;
				
				
			case 3:printf("\nC-SCAN :\n");
				printf("Scheduling Services the request in the order that follows:\n%d\t",start);
				count=0;
				pos=0;
				//sorting
				for(i=0;i<n;i++)
					for(j=0;j<n-i-1;j++)
					if(a[j]>a[j+1])
					{
						x=a[j];
						a[j]=a[j+1];
						a[j+1]=x;
					}
				for(i=0;i<n;i++)
					if(a[i]<start)
						pos++;
					x=start;
				for(i=pos;i<n;i++)
				{
					count+=abs(x-a[i]);
					x=a[i];
					printf("%d\t",x);
				}
				count+=abs(m-1-x);
				x=0;
				printf("%d\t%d\t",m-1,0);
				for(i=0;i<pos;i++)
				{
					count+=abs(x-a[i]);
					x=a[i];
					printf("%d\t",x);
				}
				printf("\nTotal Head movement: %d Cylinders",count);
				break;
		}
		printf("\nDo you want to continue(1 to continue) :");
		scanf("%d",&ch);
		}while(ch==1);
}
