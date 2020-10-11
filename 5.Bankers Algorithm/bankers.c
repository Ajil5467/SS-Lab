#include<stdio.h>


struct file
{
    int all[10];
    int max[10];
    int need[10];
    int flag;
} f[10];




}
for(i=0; i<n; i++)
{
    for(j=0; j<r; j++)
    {
        f[i].need[j] = f[i].max[j]-f[i].all[j];
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
                if(avail[p]>=f[j].need[p])

                    b=b+1;
                else
                    b=b-1;
            }
            if(b==r)
            {
                printf("\nP%d is visited",j);

                seq[fl++]=j;
                f[j].flag=1;
                for(k=0; k<r; k++)
                    avail[k]=avail[k]+f[j].all[k];
                cnt=cnt+1;
                printf("(");
                for(k=0; k<r; k++)
                    printf(" %d",avail[k]);
                printf(")");
                g=1;
            }
        }
    }
    if(g==0)
        //Unsafe state
    {   printf("\n REQUEST NOT GRANTED- DEADLOCK OCCURRED");
        printf("\n SYSTEM IS IN UNSAFE STATE");
        goto y;
    }
}
printf("\nSYSTEM IS IN SAFE STATE");
//Safe state
printf("\nThe Safe Sequence is : (");
for(i=0; i<fl; i++)
    printf("P%d ",seq[i]);
printf(")\n");
y:
printf("\n\Process\t\t\Allocation\t\t  Max\t\t  Need\n");
for(i=0; i<n; i++)
{
    printf("P%d\t",i);
    printf("\t");
    for(j=0; j<r; j++)
        printf(" %d",f[i].all[j]);
    printf("\t\t\t");

    for(j=0; j<r; j++)
        printf(" %d",f[i].max[j]);
    printf("\t\t");

    for(j=0; j<r; j++)
        printf(" %d",f[i].need[j]);

    printf("\n");
}
}
