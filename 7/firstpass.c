#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXCHAR 1000
void main()
{

  FILE *p,*fsym,*fop,*fl;
  char label[100],opcode[100],operand[100],c,optab[100];
  int value,locctr,sa=0,otp,op1,len;

  p = fopen("input.txt","r");
  fsym = fopen("symtab.txt","w");
  fl = fopen("length.txt","w");
  fscanf(p,"%s  %s %d",label,opcode,&value);
  //   while (fgets(str, MAXCHAR, p) != NULL)
//   {
// 		fscanf(p, "%s %s %d", label, opcode,&value);
// 		printf("%s %s %d\n",label,opcode,value);
// 		if(strcmp(opcode,"START")==0)
// 		{
// 			locctr = value;
// 			// locctr = value;
// 		}
// 		else
// 			locctr = 0;  
// Unsuccesful method to read each file

  if(strcmp(opcode,"START") == 0)
  {
	  sa = value;
	  locctr = sa;
	  printf("\t%s\t%s\t%d\n",label,opcode,value);
  }
  else
	  locctr=0;
	fscanf(p,"%s%s",label,opcode);

// While not end of file, search assembly file
while(!feof(p))
{
	fscanf(p,"%s",operand);
  printf("\n%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
  if(strcmp(label,"-") != 0)
  {
    // Insert into symtab
     fprintf(fsym,"\n%d\t%s\n",locctr,label);
  }

  fop=fopen("optab1.txt","r");
   // Search OPTAB FOR OPCODE
  while(!feof(fop))
  {
    fscanf(fop,"%s %d",optab,&otp);
    // printf("    %s %s",opcode,optab);
    if(strcmp(opcode,optab)==0)
    {
      locctr=locctr+3;
      break;
    }
  }
  fclose(fop);
  
  if(strcmp(opcode,"WORD")==0)
    {
       locctr=locctr+3;
    }
  else if(strcmp(opcode,"RESW")==0)
   {
      op1=atoi(optab);
      locctr=locctr+(3*op1);
    }
  else if(strcmp(opcode,"BYTE")==0)
    {
      if(optab[0]=='X')
      locctr=locctr+1;
      else
      {
      len=strlen(optab)-2;
      locctr=locctr+len;
      }
    }

  else if(strcmp(opcode,"RESB")==0)
    {
     op1=atoi(optab);
     locctr=locctr+op1;
     }
    fscanf(p,"%s%s",label,opcode);
}

  if(strcmp(opcode,"END")==0)
  {
    printf("Program length =\n%d",locctr-sa);
    fprintf(fl,"%d",locctr-sa);
  }

  fclose(p);
  fclose(fsym);

}
