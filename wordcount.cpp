#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE *f;
int cword = 0;
int cchar = 0;	
int cline = 0;
int countw(char *file)
{
	f=fopen(file,"r");
	char ch;
	int aword=0;
	if(NULL==(f=fopen(file,"r")))
 {printf("file is NULL");}
 else
	while(!feof(f))
	{
		ch=fgetc(f);
		if((ch >= 'a'&&ch <= 'z')||(ch>='A'&&ch<='Z')||ch=='_')
		aword=1;
	else if (aword) {
				cword++;
				aword=0;
	}
	}fclose(f); printf("wordnum:%d ",cword);
}
int countc(char *file)
{
	f = fopen(file, "r");
	
	char a;
	if(NULL==(f=fopen(file,"r")))
    {printf("file is NULL");}
    else
	while (!feof(f))
	{
		a = fgetc(f);
		if (a != ' '&&a != '\n'&&a != '\t')
			cchar++;
	}
	cchar--;
	fclose(f);printf("charnum:%d ",cchar);

}
int countl(char *file)
{
	f = fopen(file, "r");

	char a;
	if(NULL==(f=fopen(file,"r")))
    {printf("file is NULL");}
    else
    while(1){
	{a = fgetc(f);
	}
    if(feof(f)) break;
	{
		
		if (a == '\n')
			cline++;
    }}

	fclose(f);printf("Linenum:%d ",cline);
	return 1;
}
int count_blankline(char *file)
{
	int ch_num = 0;
	int b_num = 0; 
	char ch;
	f = fopen(file, "r");
if(NULL==(f=fopen(file,"r")))
    {printf("file is NULL");}
    else
	while (!feof(f))
	{
		ch= fgetc(f);
		if (ch=='\n'){
			if (ch_num <= 1)
				b_num++;
			ch_num = 0;
		}
		else if (ch != ' '&&ch != '\t')
			ch_num++;
	}
	fclose(f);printf("blankline:%d  ",b_num);
}
int count_noteline(char *file)
{
int ch_num = 0;int note_num=0;
	char ch;
	f = fopen(file, "r");
if(NULL==(f=fopen(file,"r")))
    {printf("file is NULL");}
    else
	while (!feof(f))
	{
		ch= fgetc(f);
		if(ch=='\n'){if(ch_num==2) note_num++; ch_num=0;}
        else if(ch=='/') ch_num++;
        else if(ch_num==1){if(ch=='/') ch_num++;} 
		
} 	fclose(f);printf("noteline:%d  ",note_num);
} 
int count_codeline(char *file)
{int ch_num = 0;int code_num=0;
	char a; int flag=0; int flag_1=0;
	f = fopen(file, "r");
if(NULL==(f=fopen(file,"r")))
    {printf("file is NULL");}
    else
	while (!feof(f))
	{
		a=fgetc(f);
		
		if(flag==0){
		
		if(a=='\n'&&ch_num>1&&flag==0)
		{ code_num++; 
		 ch_num=0;	 }
        else if(a != ' '&&a != '\n'&&a != '\t'&&a!='/') ch_num++;
        else if(ch_num==1){if(a != ' '&&a != '\n'&&a != '\t'&&a!='/') ch_num++;} 
        else if(a=='/'){ flag_1=1;}
		else if(flag_1==1)
		{flag=1; code_num--;}}
        else if(flag==1){flag==0;
		}
        
    }fclose(f); printf("codeline:%d  ",code_num); 
}
int main(int argc, char* argv[])             
{
    FILE *fp;
    countw(argv[2]);countc(argv[2]);
   
    while(1)
    {
        if((fp=fopen(argv[2],"r"))==NULL)
        {  
        printf("FileNull\n\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
        continue;
        }
        else if(!strcmp(argv[1],"-w")) countw(argv[2]);                
           //printf("wordnum:%d",cword);
        else if(!strcmp(argv[1],"-c"))  countl(argv[2]);                
           // printf("CharNum:%d\n",cchar);
        else if(!strcmp(argv[1],"-l"))    
		      countl(argv[2]);            
    
        else if(!strcmp(argv[1],"-a"))                
    {     
          count_blankline(argv[2]); 
		  count_noteline(argv[2]);
		  count_codeline(argv[2]);
	}
		else
            printf("NullPoint\n");
        printf("\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
	}return 0;
}
