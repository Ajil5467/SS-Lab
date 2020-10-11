#include<stdio.h>
#include<curses.h>
#include<string.h>


c
}
// display integer into character
arrlen = j;
printf("\n");
for (i = j; i >= 0; i--)
    printf("%c", hexadecimalnum[i]);
return 0;

}


void main() {
    FILE *f1,*f2,*f3,*fop;
    int loc,sa,l,op1,o,len, i;
    unsigned int x;
    char m1[20],la[20],op[20],otp[20];
    f1=fopen("input.txt","r");
    f3=fopen("symtab.txt","w");
    //fop=fopen("output.txt","w");
    fscanf(f1,"%s %s %x",la,m1,&x);
    if(strcmp(m1,"START")==0) {
        sa=(int) x;
        loc=sa;
        printf("\t%s\t%s\t%x\n",la,m1,x);
        //fprintf(fop,"\t%s\t%s\t%d\n",la,m1,op1);
    }
    else
        loc=0;
    fscanf(f1,"%s %s",la,m1);
    while(!feof(f1)) {
        fscanf(f1,"%s",op);
        //decToHexa(loc);
        printf("%x\t%s\t%s\t%s\n",loc,la,m1,op);
        //fprintf(fop, "\n");
        //for (i = arrlen; i >= 0; i--)
        //	fprintf(fop,"%c", hexadecimalnum[i]);
        //fprintf(fop,"\t%s\t%s\t%s\n",la,m1,op);
        if(strcmp(la,"-")!=0) {
            fprintf(f3,"\n%d\t%s\n",loc,la);
        }
        f2=fopen("optab.txt","r");
        fscanf(f2,"%s %d",otp,&o);
        while(!feof(f2)) {
            if(strcmp(m1,otp)==0) {
                loc=loc+3;
                break;
            }
            fscanf(f2,"%s %d",otp,&o);
        }
        fclose(f2);
        if(strcmp(m1,"WORD")==0) {
            loc=loc+3;
        }
        else if(strcmp(m1,"RESW")==0) {
            op1=atoi(op);
            loc=loc+(3*op1);
        }
        else if(strcmp(m1,"BYTE")==0) {
            if(op[0]=='X')
                loc=loc+1;
            else {
                len=strlen(op)-3;
                loc=loc+len;
            }
        }
        else if(strcmp(m1,"RESB")==0) {
            op1=atoi(op);
            //if(op1 == 4096)
            //	loc=loc+1000;
            //else
            loc = loc + op1;
        }
        fscanf(f1,"%s%s",la,m1);
    }
    if(strcmp(m1,"END")==0) {
        printf("\n\n Program length = \t");
        decToHexa(loc-sa);
        printf("\n\n");
    }
    fclose(f1);
    fclose(f3);
    getch();
}
