
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void firstpass();
void spass(int );
void start(FILE *,FILE *,char []);
void main()
{
	firstpass();
}


void firstpass()
{
FILE *fp,*fp1,*fp2,*fp3;
int lcounter=0,cont=0,byte,l,n=0;
char a[10],b[20],c;
fp=fopen("input.txt","r");
fp1=fopen("intermediate.txt","w");
fp2=fopen("optab.txt","r");
fp3=fopen("symtab.txt","w");
fscanf(fp,"%s",a);
fprintf(fp1,"%s",a);
fprintf(fp1,"%c",' ');
fscanf(fp,"%s",a);
fprintf(fp1,"%s",a);
fprintf(fp1,"%c",' ');
fscanf(fp,"%x",&lcounter);
printf("%x",lcounter);
fprintf(fp1,"%x",lcounter);
fprintf(fp1,"%c",'\n');
fprintf(fp1,"%x",lcounter);
fprintf(fp1,"%c",' ');
for(;(fscanf(fp,"%s",a)!=EOF);)
{
    cont=0;		 
      if((strcmp(a,"WORD")==0|| strcmp(a,"BYTE")==0)&&cont==0)
      {
          cont++;
          fprintf(fp1,"%c",' ');
          fprintf(fp1,"%s",a);
          if(strcmp(a,"WORD")==0)
          {
          fscanf(fp,"%s",a);
          lcounter=lcounter+3;
          fprintf(fp1,"%c",' ');
          fprintf(fp1,"%s",a);
          }
          else
          {      fprintf(fp1,"%c",' ');
                 fscanf(fp,"%s",a);
                 fprintf(fp1,"%c",' ');
                 fprintf(fp1,"%s",a);
                if(strcmp(a,"X")==0)
    			{
    			     fscanf(fp,"%s",a);
    			     fprintf(fp1,"%c",' ');
                     fprintf(fp1,"%s",a);
    				 l=strlen(a);
    				 l=l/2;
    				 lcounter=lcounter+l;

    			}
    			else if((strcmp(a,"C")==0))
    			{
    			    fscanf(fp,"%s",a);
    			    fprintf(fp1,"%c",' ');
                    fprintf(fp1,"%s",a);
    				l=strlen(a);
    				lcounter=lcounter+l;
    			}
    	}
    			fprintf(fp1,"%c",'\n');
    			fprintf(fp1,"%x",lcounter);
                fprintf(fp1,"%c",' ');
          
      }
      else if((strcmp(a,"RESW")==0||strcmp(a,"RESB")==0)&&cont==0)
      {

                fprintf(fp1,"%c",' ');
    			fprintf(fp1,"%s",a);
    		    fprintf(fp1,"%c",' ');
    		    fscanf(fp,"%d",&byte);
    		    fprintf(fp1,"%d",byte);
                fprintf(fp1,"%c",'\n');
                if(strcmp(a,"RESW")==0)
    		    byte=3*byte;
    		   lcounter=lcounter+byte;
    		   cont++;
    		   fprintf(fp1,"%x",lcounter);
               fprintf(fp1,"%c",' ');

      }
         fp2=fopen("optab.txt","r");
  for(;(fscanf(fp2,"%s",b)!=EOF);)
  {
      if(strcmp(a,b)==0&&cont==0)
      {
                  lcounter=lcounter+3;
                  fprintf(fp1,"%c",' ');
    			  fprintf(fp1,"%s",a);
    			  if(strcmp(a,"RSUB")==0)
    			  {
    			  	
    			  }
    			  else
    			  {
                    fscanf(fp,"%s",a);
                    fprintf(fp1,"%c",' ');
                    fprintf(fp1,"%s",a);
    		      }
    			 fprintf(fp1,"%c",'\n');
    			 fprintf(fp1,"%x",lcounter);
                 fprintf(fp1,"%c",' ');
    			cont++;

      }

  }
     fclose(fp2);
      if((strcmp(a,"END")==0)&&cont==0)
      {
      	        n=lcounter;
      	        fprintf(fp1,"%s",a);
    		    fprintf(fp1,"%c",' ');
    		    fscanf(fp,"%s",a);
                fprintf(fp1,"%s",a);
                cont++;
      	
      }
      else if(cont==0)
      {

             fprintf(fp1,"%s",a);
    		 fprintf(fp3,"%s",a);
    		 fprintf(fp3,"%c",' ');
    		 n=lcounter-n;
    		 fprintf(fp3,"%04x",lcounter);
    		 fprintf(fp3,"%c",'\n');
      }


}
fclose(fp1);
fclose(fp3);
fclose(fp);
spass(n);
}
