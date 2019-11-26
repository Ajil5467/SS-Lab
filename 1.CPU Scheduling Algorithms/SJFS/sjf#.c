#include<stdio.h>
#include<string.h>
void main()
{
    int et[20],at[10],n,i,j,temp,st[10],ft[10],wt[10],ta[10],pn[10];
    int totwt=0,totta=0;
    
    float awt,ata;
    char t[10];
    
    char inFileName[10] = "a2.txt";

  FILE *inFile; 
  inFile = fopen(inFileName, "r");
  fscanf(inFile, "%d %d %d", &pn[0], &pn[1], &pn[2]);
  fscanf(inFile, "%d %d %d", &et[0], &et[1], &et[2]); 
  fscanf(inFile, "\n%d %d %d", &at[0], &at[1], &at[2]);
    printf("\nprocess no:= %d %d %d",pn[0],pn[1],pn[2]); 
    printf("\nBurst Time= %d %d %d",et[0],et[1],et[2]);
    printf("\nArrival Time= %d %d %d",at[0],at[1],at[2]);

    
    
    
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
        {
            if(et[i]<et[j])
            {
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=et[i];
                et[i]=et[j];
                et[j]=temp;
               
            }
        }
    for(i=0; i<3; i++)
    {
        if(i==0)
            st[i]=at[i];
        else
            st[i]=ft[i-1];
        wt[i]=st[i]-at[i];
        ft[i]=st[i]+et[i];
        ta[i]=ft[i]-at[i];
        totwt+=wt[i];
        totta+=ta[i];
    }
    awt=(float)totwt/3;
    ata=(float)totta/3;
    printf("\nPname\tarrivaltime\texecutiontime\twaitingtime\ttatime");
    for(i=0; i<3; i++)
        printf("\n%5d\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],et[i],wt[i],ta[i]);
    printf("\nAverage waiting time is:%f",awt);
    printf("\nAverage turnaroundtime is:%f",ata);
    
}

