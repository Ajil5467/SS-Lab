


#include <stdio.h>
struct file
{
        int all[10];
        int max[10];
        int need[10];
        int flag;
} f[10];
//source code
void main()
{
        int fl;
        int i, j, k, p, b, n, r, g, cnt=0, id, newr;
        int avail[10],seq[10];
        printf("\nEnter number of processes: ");
        scanf("%d",&n);
        printf("Enter number of resources: ");
        scanf("%d",&r);
        for(i=0; i<n; i++) //Entering details of all processes
        {
                printf("Enter details for P%d",i);
                printf("\nEnter allocation\t: \t");
                for(j=0; j<r; j++)
                        scanf("%d",&f[i].all[j]);
                printf("Enter Max\t\t: \t");
                for(j=0; j<r; j++)
                        scanf("%d",&f[i].max[j]);
                f[i].flag=0;
        }
        printf("\nEnter Available Resources\t: \t");
        for(i=0; i<r; i++)
                scanf("%d",&avail[i]);
        printf("\nEnter New Request Details : "); //New request
        printf("\nEnter pid \t : \t");
        scanf("%d",&id);
        printf("Enter Request for Resources \t: \t");
        for(i=0; i<r; i++)
        {
                scanf("%d",&newr);
                f[id].all[i] += newr; //allocation = allocation + new request
                avail[i]=avail[i]-newr;// available = available - new request
        }
        for(i=0; i<n; i++)
        {
                for(j=0; j<r; j++)
                {
                        f[i].need[j] = f[i].max[j]-f[i].all[j]; //need = max - allocation
                        if(f[i].need[j]<0)
                                f[i].need[j]=0;
                }
        }
        cnt=0;
        fl=0;
        while(cnt!=n)
        {
                g=0;
                for(j=0; j<n; j++)
                {
                        if(f[j].flag==0)
                        {
                                b=0;
                                for(p=0; p<r; p++)
                                {
                                        if(avail[p]>=f[j].need[p]) //check whether need less than availability (need <= work)
                                                b=b+1;
                                        else
                                                b=b-1;
                                }
                                if(b==r)
                                {
                                        printf("\nP%d is visited",j); //Printing the visited processes
                                        seq[fl++]=j;
                                        f[j].flag=1;
                                        for(k=0; k<r; k++)
                                                avail[k]=avail[k]+f[j].all[k]; // available = available + allocation
                                        cnt=cnt+1;
                                        printf("(");
                                        for(k=0; k<r; k++)
                                                printf(" %d",avail[k]);
                                        printf(")");
                                        g=1;
                                }
                        }
                }
                if(g==0) //Unsafe state
                {
                        printf("\n REQUEST NOT GRANTED- DEADLOCK OCCURRED");
                        printf("\n SYSTEM IS IN UNSAFE STATE");
                        goto y;
                }
        }
        printf("\nSYSTEM IS IN SAFE STATE"); //Safe state
        printf("\nThe Safe Sequence is : (");
        for(i=0; i<fl; i++)
                printf("P%d ",seq[i]);
        printf(")\n");
y: printf("\nProcess\t\tAllocation\tMax\t\t   Need\n");
        for(i=0; i<n; i++)
        {
                printf("P%d\t",i);
                for(j=0; j<r; j++)
                        printf(" %d\t",f[i].all[j]);
                for(j=0; j<r; j++)
                        printf(" %d\t",f[i].max[j]);
                for(j=0; j<r; j++)
                        printf(" %d\t",f[i].need[j]);
                printf("\n");
        }
}
