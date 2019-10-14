# include<stdio.h>
# include<stdlib.h>
int total;
void tot()
{
printf("the total head movement is %d\n",total);
}
//driver code
void main()
{
int nc,n,a[10],i,temp,j,ch,cu,t;
printf("enter no of cyllinders\n");
scanf("%d",&nc);
printf("enter no of requests\n");
scanf("%d",&n);
printf("enter current head position\n");
scanf("%d",&cu);
printf("enter requests\n");

for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);//read the request into array
}
total=0;
		for(i=0;i<n;i++)//add the head movement from current position to cyllinder in the request array
		{
			if(cu>a[i])
				total=total+cu-a[i];
			else
				total=total+a[i]-cu;
      cu=a[i];//set current position to currently accessed request.
		}
		tot();//function for print total seek time
}
	
