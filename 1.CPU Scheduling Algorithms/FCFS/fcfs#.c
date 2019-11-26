 #include<stdio.h>
void main()
{
int n,a[10],b[10],t[10],w[10],g[10],i,m;
char inFilename[30];
float att=0,awt=0;
            for(i=0;i<10;i++)
            {
                        a[i]=0; b[i]=0; w[i]=0; g[i]=0;
            }
	char inFileName[10] = "a1.txt";

  FILE *inFile; 
  inFile = fopen(inFileName, "r");

  fscanf(inFile, "%d %d %d", &b[0], &b[1], &b[2]); 
  fscanf(inFile, "\n%d %d %d", &a[0], &a[1], &a[2]); 
    printf("\nBurst Time= %d %d %d",b[0],b[1],b[2]);
    printf("\nArrival Time= %d %d %d",a[0],a[1],a[2]);

    g[0]=0;
             for(i=0;i<3;i++)
                   g[i+1]=g[i]+b[i];
             for(i=0;i<3;i++)
            {     
w[i]=g[i]-a[i];
                        t[i]=g[i+1]-a[i];
                        awt=awt+w[i];
                        att=att+t[i]; 
            }
     awt =awt/3;
            att=att/3;
            printf("\n\tprocess\twaiting time\tturn arround time\n");
            for(i=0;i<3;i++)
            {
                        printf("\tp%d\t\t%d\t\t%d\n",i,w[i],t[i]);
            }
printf("the average waiting time is %f\n",awt);
printf("the average turn around time is %f\n",att);
}
