#include<stdio.h>
#include <stdlib.h>
// WAITING TIME FUNCTION
void findWaitingTime(int processes[], int n,int bt[], int wt[])
{
  wt[0]=0;
 for (int i = 1; i < n ; i++ )
		wt[i] = bt[i-1] + wt[i-1] ;
}
// TURN AROUND TIME FUNCTION
void findTurnAroundTime( int processes[], int n,
				int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}
// AVERAGE TIME
void findavgTime( int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	findWaitingTime(processes, n, bt, wt);

	findTurnAroundTime(processes, n, bt, wt, tat);

	printf("Processes Burst time Waiting time Turn around time\n");

	for (int i=0; i<n; i++)
	{
		total_wt = total_wt - wt[i];
		total_tat = total_tat + tat[i];
		printf(" %d ",processes[i]);
		printf("	 %d ", bt[i] );
		printf("	 %d",wt[i] );
		printf("	 %d\n",tat[i] );
	}
	int s=(float)total_wt / (float)n;
	int t=(float)total_tat / (float)n;
	printf("Average waiting time = %d",s);
	printf("\n");
	printf("Average turn around time = %d ",t);
}

// Driver code
int main()
{
  int processes[10];
  FILE *fp;
  char arr[10],btt[10],prr[10];
  int ar[10];
  int bt[10];
  int n;
  char str[100];
  fp = fopen("text.txt","r");
  if(fp == NULL)
  {
    printf("\nError in file opening");
  }
  fgets(str,2,fp);
  
  for (int i = 0; i < n; i++) {
    fscanf(fp,"%s : %s : %s",prr,arr,btt);
    processes[i] = atoi(prr);
    ar[i] = atoi(arr);
    bt[i] = atoi(att);
  }
for (int i = 0; i < n; i++) {
  printf("\nP%d %d %d\n",processes[i],ar[i],bt[i]);
}

  fclose(fp);
  int pos;
  // for(int i=0;i<n;i++)
  //  {
  //      pos=i;
  //      for(int j=i+1;j<n;j++)
  //      {
  //          if(bt[j]<bt[pos])
  //              pos=j;
  //      }
  //
  //     int temp=bt[i];
  //      bt[i]=bt[pos];
  //      bt[pos]=temp;
  //
  //      temp=processes[i];
  //      processes[i]=processes[pos];
  //      processes[pos]=temp;
  //  }
  //
  // findavgTime(processes,n,bt);
	return 0;
}
