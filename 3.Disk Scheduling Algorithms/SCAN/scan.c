# include<stdio.h>
int total;
void tot()
{
printf("the total head movement is %d\n",total);
}
//driver code
void main()
{
int nc,n,a[10],i,temp,j,ch,cu,t,cur,curr;
printf("enter no of cyllinders\n");
scanf("%d",&nc);
printf("enter no of requests\n");
scanf("%d",&n);
printf("enter current head position\n");
scanf("%d",&cur);
printf("enter requests\n");
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);//read request into an array
}
total=0;
		for(t=0;t<n;t++);
		    a[t]=cur;//add current head position into request array
	
		for(i=0;i<n;i++)//sort the array in ascending order
		{
		   for(j=i+1;j<=n;j++)
		   {
          if(a[j]<a[i])
			    {
			        temp=a[j];
			        a[j]=a[i];
			        a[i]=temp;
			    }
		  }
		}
		for(i=0;i<=n;i++)
		{	
			if(cur==a[i])//find the position of cur in request array
				{
					t=i;
					break;
				}
		}
		for(i=t+1;i<=n;i++)//add the headmovement from t+1 th location to final head
		{
			if(cur>a[i])
				total+=cur-a[i];
			else
				total+=a[i]-cur;
			cur=a[i];
		}
		total=total+nc-1-cur;//nc-1 is the last number of cyllinder
 		cur=nc-1;//the current request is set to last cyllinder
		for(i=t-1;i>=0;i--)//add the headmovement from t-1 th cyllinder to starting cyllinder(0)
		{
			if(cur>a[i])
				total+=cur-a[i];
			else
				total+=a[i]-cur;
			cur=a[i];
		}
		tot();//to find total headmovement

	}


