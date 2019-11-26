#include<stdio.h>


int initialize();
int p[10],a[10],b[10],pr[10],w[10],ta[10],t1;

void main()
 {
  int i,j,n,t,sum=0;
  float aw,at,sum1;
  printf("\n\nP  A  B  pr W  TAT\n\n");
  n=initialize();
 //sorting 
   for(i=0;i<n;i++)
    {
     for(j=i+1;j<n;j++)
      {
       if(pr[i]>pr[j])
    {
     t=a[i];
     a[i]=a[j];
     a[j]=t;

     t=b[i];
     b[i]=b[j];
     b[j]=t;

     t=p[i];
     p[i]=p[j];
     p[j]=t;
     
     t=pr[i];
     pr[i]=pr[j];
     pr[j]=t;
    }
      }
    }
t1=a[0];
 for(i=0;i<n;i++)
  {
  if (t1-a[i]<0)
    t1+=a[i]-t1;
   if(i==0)
    w[i]=0;
   else
    w[i]=t1-a[i];
   t1+=b[i];
  }
 for(i=0;i<n;i++)
  {
   ta[i]=b[i]+w[i];
  }
 for(i=0;i<n;i++)
 {
    printf("%d  %d  %d  %d %d  %d\n",p[i],a[i],b[i],pr[i],w[i],ta[i]);
 }
 //average calculator
printf("\n\nAverage waiting time is:");
 sum1=0.0;
  for(i=0;i<n;i++)
   {
    sum1+=w[i];
   }
 aw=sum1/n;
 printf("%f",aw);

 printf("\n\nAverage turn around time is:");
 sum1=0.0;
  for(i=0;i<n;i++)
   {
    sum1+=ta[i];
   }
 at=sum1/n;
 printf("%f",at);
 printf("\n\nThe Gantt chart is:\n\n");
 for(i=0;i<n;i++)
  {
   printf("|%d",p[i]);
    if(i==n-1)
     printf("|");
  }
  printf("\n");
}
//file reader
int initialize()
{
  int n,n1,n2,n3,n4,i=0;
  char ch='a';
  FILE *fp;
  fp=fopen("pr.txt","r");
  while(fscanf(fp,"%d:%d:%d:%d",&n1,&n2,&n3,&n4)!=EOF)
    {
     
       p[i]=n1;
     
       a[i]=n2;
     
       b[i]=n3;
       
       pr[i]=n4;
       
        i++;
    }
  return i;
} 

