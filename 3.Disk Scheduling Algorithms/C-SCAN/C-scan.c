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
    int nc,n,a[10],i,temp,j,ch,t,curr;
    printf("enter no of cyllinders\n");
    scanf("%d",&nc);
    printf("enter no of requests\n");
    scanf("%d",&n);

    scanf("%d",&a[i]);//read the requests into array
}
total=0;
for(i=0; i<n; i++);
a[i]=curr;//add the current head position to request array
for(i=0; i<=n; i++) //sort the array in the increasing order of cyllinder number
{
    for(j=i+1; j<=n; j++)
    {
        if(a[j]<a[i])
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
}
for(i=0; i<=n; i++)
{   //find the position of current head in the sorted array
    if(curr==a[i])
    {
        t=i;
        break;
    }
}
for(i=t+1; i<=n; i++) //add the head movement from t+1 th position to last request
{
    if(curr>a[i])
        total+=curr-a[i];
    else
        total+=a[i]-curr;
    curr=a[i];
}
total+=nc-1-curr+nc-1;// nc-1 is the last cyllinder number
curr=0;
for(i=0; i<=t-1; i++) //add the head movement from 0th position to t-1 th position
{
    if(curr>a[i])
        total+=curr-a[i];
    else
        total+=a[i]-curr;
    curr=a[i];
}
tot();//total head movement
}
