#include<stdio.h>
void findavgtime(int process[],int n,int brt[],int art[])
{
int wt[10],tat[10],t,total_tat=0,total_wt=0,i,sum_burst=0;//wt:waiting time,tat:turnaround time
float avg_wt=0,avg_tat=0;
wt[0]=0;//waiting time of first process is zero
for(t=1;t<n;t++)
{	sum_burst=sum_burst+brt[t-1];//sumburst is the total time taken to complete a process 
	wt[t]=sum_burst+art[t]+1;
       total_wt=total_wt-wt[t];
	

}

for(i=0;i<n;i++)
{
	tat[i]=wt[i]+brt[i];
	total_tat=total_tat+tat[i];
}
printf("\nprocess\t waitingtime\t turntime\t\n");
for(i=0;i<n;i++)
{
	printf("%d\t%d\t%d\t\n",process[i],wt[i],tat[i]);
}

	
avg_wt=(float)total_wt/(float)n;
avg_tat=(float)total_tat/(float)n;
printf("average waiting time and turnaround time is %f %f\n",avg_wt,avg_tat);
}
//main program
void main()


{

int prr,arr,btt;
int process[10],art[10],brt[10];//arrays to store process numbers,arrival time,burs ttime
char str[100];
int k=0,i=0,j,n=0,temp=0,pos,t=0,te=0;
FILE *fpt=fopen("fcfs.txt","r");
	printf("process arrtime bursttime\n");
	//the following loop will read the data from a file using file pointer fp and store datas to corresponding array
	while(fscanf(fpt,"%d:%d:%d",&prr,&arr,&btt)!=EOF)
	{
	process[i]=prr;
	art[i]=arr;
	brt[i]=att;
	printf("%d %d %d\n",process[i],art[i],brt[i]);
	i++;
	n++;
	}

printf ("%d\n",n);
//sort the processes by their arrival time order
for(k=0;k<n;k++)
 {

 	 for(j=k+1;j<=n;j++)
	{

		
		if(art[k]>=art[j])
	
		{	
  			te=art[k];
  			art[k]=art[j];
  			art[j]=te;
  			
			t=process[k];
 			process[k]=process[j];
   			process[j]=t;
  			
			te=brt[k];
  			brt[k]=brt[j];
  			brt[j]=te;
		}
	}

 }
printf("process arrtime bursttime\n");
for(i=0;i<n;i++)
{
	printf("%d %d %d\n",process[i],art[i],brt[i]);
}
printf ("gantt chart\n");
for(i=0;i<n;i++)
	{
		printf("|%d|",process[i]);
	}
findavgtime(process,n,brt,art);//call the function to find average waiting time and average turnaround time

}






