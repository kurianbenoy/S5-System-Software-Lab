#include<stdio.h>
#include<string.h>

void main()
{

FILE *f1,*f2,*f3;
int lc,sa,l,op1,o,len;
char m1[20],label[20],op[20],otp[20];
//read input files
f1=fopen("assembly.txt","r");
f3=fopen("symtab.txt","w");
fscanf(f1,"%s %s %d",label,m1,&op1);

// When opcode = "START"
if(strcmp(m1,"START")==0)
{
 sa=op1;
 lc=sa;
 printf("\t%s\t%s\t%d\n",label,m1,op1);
 }
// while opcode != END

else
lc=0;
fscanf(f1,"%s %s",label,m1);
// While not end of file, search assembly file
while(!feof(f1))
{
  fscanf(f1,"%s",op);
  printf("\n%d\t%s\t%s\t%s\n",lc,label,m1,op);
  if(strcmp(label,"-")!=0)
  {
    // Insert into symtab
    fprintf(f3,"\n%d\t%s\n",lc,label);
  }

  f2=fopen("optab1.txt","r");
  fscanf(f2,"%s %d",otp,&o);

  // Search OPTAB FOR OPCODE
  while(!feof(f2))
  {
    if(strcmp(m1,otp)==0)
    {
      lc=lc+3;
      break;
    }
    fscanf(f2,"%s %d",otp,&o);
  }
  
    fclose(f2);
  if(strcmp(m1,"WORD")==0)
    {
   lc=lc+3;
    }
  else if(strcmp(m1,"RESW")==0)
   {
    op1=atoi(op);
    lc=lc+(3*op1);
    }
  else if(strcmp(m1,"BYTE")==0)
    {
      if(op[0]=='X')
      lc=lc+1;
      else
      {
      len=strlen(op)-2;
      lc=lc+len;
      }
    }

  else if(strcmp(m1,"RESB")==0)
    {
     op1=atoi(op);
     lc=lc+op1;
     }
    fscanf(f1,"%s%s",label,m1);
    }

  if(strcmp(m1,"END")==0)
  {
  printf("Program length =\n%d",lc-sa);
  }
    fclose(f1);
    fclose(f3);
    }
