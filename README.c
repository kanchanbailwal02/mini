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
void spass(int n)
{
FILE *fp,*fp1,*fp2,*fp3;
int opcode,address,word,cont,flag=1,flag2=0,arr[40],l,i=0,counter=0,r,length=0,byte,fetch=0,j=0;
char a[100],b[30],c[30],c1;
fp=fopen("intermediate.txt","r");
fp2=fopen("optab1.txt","r");
fp3=fopen("symtab.txt","r");
fp1=fopen("pro.txt","w");
start( fp,fp1, a);
for(;(fscanf(fp,"%s",a)!=EOF);)
{
    cont=0;
    fp2=fopen("optab1.txt","r");
  for(;(fscanf(fp2,"%s",b)!=EOF);)
  {
      if(strcmp(a,b)==0)
      {
                  fscanf(fp2,"%x",&opcode);
                  fscanf(fp2,"%x",&opcode);
                  fprintf(fp1,"%c",' ');
    			  fprintf(fp1,"%s",a);
    			  if(strcmp(a,"RSUB")==0)
    			  {
                  	fprintf(fp1,"%c",' ');
                  	fprintf(fp1,"%x",opcode);
                  	fprintf(fp1,"%s","0000");
    			  }
    			  else
    			  {
                    fscanf(fp,"%s",a);
                    fprintf(fp1,"%c",' ');
                    fprintf(fp1,"%s",a);
                     fp3=fopen("symtab.txt","r");
    			      	for(;(fscanf(fp3,"%s",c)!=EOF);)
    			      	   {
    			      	       if(strcmp(a,c)==0)
						       {
						       	fscanf(fp3,"%x",&address);
							  	break;
							    }
    			      		
    			      	    }fclose(fp3);
    			      	 fprintf(fp1,"%c",' ');
    			      	 fprintf(fp1,"%02x",opcode);
                         fprintf(fp1,"%x",address);
   
    
                  }
    			 fprintf(fp1,"%c",'\n');
    			 cont++;
    			 break;


      }

  }
     fclose(fp2);
      if((strcmp(a,"WORD")==0||strcmp(a,"BYTE")==0)&&cont==0)
      {
          cont++;
          fprintf(fp1,"%c",' ');
          fprintf(fp1,"%s",a);
          if(strcmp(a,"WORD")==0)
          {
          fscanf(fp,"%d",&word);
          fprintf(fp1,"%c",' ');
          fprintf(fp1,"%d",word);
          fprintf(fp1,"%c",' ');
          fprintf(fp1,"%06x",word);
          
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
                     fprintf(fp1,"%c",' ');
                     fprintf(fp1,"%s",a);

    			}
    			else if((strcmp(a,"C")==0))
    			{
    			    fscanf(fp,"%s",a);
    			    fprintf(fp1,"%c",' ');
                    fprintf(fp1,"%s",a);
                    fprintf(fp1,"%c",' ');
    				for(;(a[fetch]!='\0');)
                 	{
		              c1=a[fetch];
		              fetch++;
		              fprintf(fp1,"%x",c1);
	                }
    			
    			}
    	}
    			fprintf(fp1,"%c",'\n');          
      }
      else if((strcmp(a,"RESW")==0||strcmp(a,"RESB")==0)&&cont==0)
      {

                fprintf(fp1,"%c",' ');
    			fprintf(fp1,"%s",a);
    		    fprintf(fp1,"%c",' ');
    		    fscanf(fp,"%d",&word);
    		    fprintf(fp1,"%d",word);
                fprintf(fp1,"%c",'\n');
    		    cont++;

      }
      else if(cont==0)
      {
             fprintf(fp1,"%c",' ');
             fprintf(fp1,"%s",a);
      }


}
  fclose(fp1);
  fclose(fp3);
  fclose(fp);
   fp = fopen("pro.txt", "r");
    fp2 = fopen("oprog.txt", "w");
   	fprintf(fp2,"%c",'H');
   	fprintf(fp2,"%c",' ');
   	fprintf(fp2,"%c",'^');
   	fscanf(fp,"%s",a);
   	fprintf(fp2,"%s",a);
   	fscanf(fp,"%s",a);
	fprintf(fp2,"%c",'^');
    fscanf(fp,"%x",&byte);
    fprintf(fp2,"%06x",byte);
    fprintf(fp2,"%c",'^');
    n=n-byte;
    fprintf(fp2,"%06x",n);
    fprintf(fp2,"%c",'\n');
    fprintf(fp2,"%c",'T');
    fprintf(fp2,"%c",' ');
    fprintf(fp2,"%c",'^');
    fprintf(fp2,"%06x",byte);
    printf("\n");
    i=0;
	for(;(fscanf(fp,"%s",a)!=EOF);)
     {
     	cont=0;
     	printf("%s",a);
     	if(flag==1)
     	{
     	 sscanf(a,"%x",&word);
     	 flag=0;
        }
     	 fp3 = fopen("optab1.txt", "r");
         	for(;(fscanf(fp3,"%s",b)!=EOF);)
         	{
         			if(strcmp(a,b)==0)
                     {
                     	flag=1;
                     	if(flag2==1)
                     	{
                     		fprintf(fp2,"%06x",word);
                     	}
                     	flag2=0;
                     	cont++;
                     	length=length+3;
                     	if(strcmp(a,"RSUB")==0)
                     		{
                     			fscanf(fp,"%s",a);
                     		}
                     		else
                     		{
                     			fscanf(fp,"%s",a);
                     			fscanf(fp,"%s",a);
                     		}
                     	if(length<=30)
                     	{
                     		fprintf(fp2,"%c",'^');
                     		fprintf(fp2,"%s",a);
                     	}
                     	else
                     	{
                     		length=length-3;
                     		arr[i]=length;
                     		i++;
                     		length=0;
                     		fprintf(fp2,"%c",'\n');
                     		fprintf(fp2,"%c",'T');
                     		fprintf(fp2,"%c",' ');
                            fprintf(fp2,"%c",'^');
                            fprintf(fp2,"%06x",word);
                            fprintf(fp2,"%c",'^');
                            fprintf(fp2,"%s",a);
                     		length=length+3;
                     	}
                     	
                     } 
         	
			 }fclose(fp3);

      if((strcmp(a,"WORD")==0||strcmp(a,"BYTE")==0)&&cont==0)
      {
      	                 if(flag2==1)
                     	{
                     		fprintf(fp2,"%06x",word);
                     	}

      	flag=1;
      	cont++;
      	flag2=0;
      	if(strcmp(a,"WORD")==0)
      	{
      	   
		  fscanf(fp,"%s",a);
          length=length+3;
         }
		 
         else if(strcmp(a,"BYTE")==0)
         {      
         
                 fscanf(fp,"%s",a);
           	     fscanf(fp,"%s",b);
    			if(strcmp(a,"X")==0)
    			{
    				l=strlen(b);
    				l=l/2;
    			  length=length+l;
    				
    			}
    			else 
    			{
    				  
    				l=strlen(b);
    				length=length+l;
    			}
         }
             fscanf(fp,"%s",a);
             if(length<=30)
             {
             	fprintf(fp2,"%c",'^');
               fprintf(fp2,"%s",a);
             }
                          else
                     	{   length=length-l;
                     	    arr[i]=length;
                     	    i++;
                     	    length=0;
                     		fprintf(fp2,"%c",'\n');
                     		fprintf(fp2,"%c",'T');
                     		fprintf(fp2,"%c",' ');
                            fprintf(fp2,"%c",'^');
                            fprintf(fp2,"%06x",word);
                            fprintf(fp2,"%c",'^');
                            fprintf(fp2,"%s",a);
                            length=l+3;
                     	}
    			
      }
       if((strcmp(a,"RESW")==0||strcmp(a,"RESB")==0)&&cont==0)
      {                       
                                 
                                if(flag2>0)
                                {
                                 	
                                 	
                                }
      	                     else if(flag2==0)
      	                     {
      	                     	arr[i]=length;
      	                     	i++;
      	                       fprintf(fp2,"%c",'\n');
                     		   fprintf(fp2,"%c",'T');
                     		   fprintf(fp2,"%c",' ');
                               fprintf(fp2,"%c",'^');
      	                           flag2++;
      	                           length=0;
      	                     }
      	                       fscanf(fp,"%s",a);
      	                       flag=1;
      	                       printf("\n%x",word);
      	                       printf("\n");
      	                     
      }
     
	
    }
    arr[i]=length;
    fclose(fp);
    fclose(fp2);
    for(j=0;j<=i;j++)
    {
    	printf("\n%x",arr[j]);
    }
    fp=fopen("oprog.txt","r");
    fp2=fopen("final.txt","w");
    i=0;
    while(fscanf(fp,"%s",a)!=EOF)
    {
    	fprintf(fp2,"%s",a);
    	if(strcmp(a,"T")==0)
    	{   
    		fprintf(fp2,"%c",'^');
    		fprintf(fp2,"%x",arr[i]);
    		i++;
    	}
    	if(strcmp(a,"T")!=0&&strcmp(a,"H")!=0)
    	{
    		fprintf(fp2,"%c",'\n');
    	}
    }
    fprintf(fp2,"%s","E");
	fprintf(fp2,"%c",'^');
    fprintf(fp2,"%06x",byte);
    fclose(fp);
    fclose(fp2);
}
void start(FILE *fp,FILE *fp1,char a[30])
{
fscanf(fp,"%s",a);
fprintf(fp1,"%s",a);
fprintf(fp1,"%c",' ');
fscanf(fp,"%s",a);
fprintf(fp1,"%s",a);
fprintf(fp1,"%c",' ');
fscanf(fp,"%s",a);
fprintf(fp1,"%s",a);
fprintf(fp1,"%c",'\n');
}

