#include <stdio.h>
#include <string.h>
#include <ctype.h>

main()
{
	char expr[200],x[30];
	char operators[30],delimeters[30],identifiers[30][30],keywords[30][30],comments[30][30];
	int constants[30],ascii[200]={0},identifier_length[30],comment_length[30];
	int length,num=0;
	int i,j=0,k=0,l=0,m=0,n=0,p=0,a=0,b=0,c=0,keywords_count=0;
	FILE *f;
	f=fopen("file.c","r");
	
	//printf("%s\n",buff);

	//scanf("%[^\n]s",expr);
	while(fgets(expr,300,(FILE*)f))
	{
		//printf("%s",expr);
	length = strlen(expr);

	for(i=0;i<length;i++)
		ascii[i] = (int)expr[i];

	for(i=0;i<length;i++)
	{
		if(expr[i]=='/')
		{
			i++;
			if(expr[i]=='/')
			{
				while(expr[i]!='\n')
				{
					comments[a][b]=expr[i];
					b++;
					i++;
				}
			}
			comment_length[a]=b;
			b=0;
			a++;
		

			else if(expr[i]=='*')
			{
				if(expr[i+1]=='/')break;
				else{
					if(expr[i]=='\n'){
						fgets(expr,300,(FILE*)f);
						length = str(length);
						i=0;
					}
					else{
						comments[a][b]=expr[i];
						b++;
						i++;
					}
				}
				
			}
			comment_length[a]=b;
			b=0;
			a++;
			}
		}
		if(isdigit(expr[i]))
		{
			while(isdigit(expr[i])) 
			{
				num = num*10 + ascii[i] - '0';
				i++;
			}
			constants[p]=num;
			p++;
			num=0;

		}

		if(isalpha(expr[i]))
		{
			while(isalpha(expr[i]) || isdigit(expr[i]) || expr[i]=='_')
			{
				identifiers[m][k]=expr[i];
				i++;
				k++;
			}
			identifier_length[m]=k;
			m++;
			k=0;
		}

		if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='/' || expr[i]=='=' || expr[i]=='^')
		{
			operators[l] = expr[i];
			l++;
		}

		if(expr[i]==';'||expr[i]==':'||expr[i]=='('||expr[i]==')'||expr[i]==','||expr[i]=='['||expr[i]==']'||expr[i]=='{'||expr[i]=='}')
		{
			delimeters[n] = expr[i];
			n++;
		}
	}
	}
	printf("\nKEYWORDS:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<30;j++)
			x[j]='\0';
		for(j=0;j<identifier_length[i];j++)
			x[j]=identifiers[i][j];
		if(!strcmp(x,"auto")||!strcmp(x,"break")||!strcmp(x,"case")||!strcmp(x,"char")||!strcmp(x,"const")||!strcmp(x,"continue")||!strcmp(x,"default")||!strcmp(x,"do")||!strcmp(x,"double")||!strcmp(x,"else")||!strcmp(x,"enum")||!strcmp(x,"extern")||!strcmp(x,"float")||!strcmp(x,"for")||!strcmp(x,"goto")||!strcmp(x,"if")||!strcmp(x,"int")||!strcmp(x,"long")||!strcmp(x,"register")||!strcmp(x,"return")||!strcmp(x,"short")||!strcmp(x,"signed")||!strcmp(x,"sizeof")||!strcmp(x,"static")||!strcmp(x,"struct")||!strcmp(x,"switch")||!strcmp(x,"typedef")||!strcmp(x,"union")||!strcmp(x,"unsigned")||!strcmp(x,"void")||!strcmp(x,"volatile")||!strcmp(x,"while")||!strcmp(x,"main")||!strcmp(x,"include"))
		{
			printf("%s\n",x);
			identifier_length[i]=0;
			keywords_count++;
		}
	}
	printf("Keywords - count : %d\n", keywords_count);
	printf("\nIDENTIFIERS:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<identifier_length[i];j++)
			printf("%c",identifiers[i][j]);
		if(j>0)
			printf("\n");
	}
	printf("Identifiers - count : %d\n", m-keywords_count);
	printf("\nCONSTANTS:\n");
	for(i=0;i<p;i++)
		printf("%d\n",constants[i]);
	printf("Constants - count : %d\n", p);
	printf("\nOPERATORS:\n");
	for(i=0;i<l;i++)
		printf("%c\n",operators[i]);
	printf("Operators - count : %d\n", l);
	printf("\nDELIMETERS:\n");
	for(i=0;i<n;i++)
		printf("%c\n",delimeters[i]);
	printf("Delimiters - count : %d\n", n);
	printf("\nCOMMENTS:\n");
	for(i=0;i<a;i++)
	{
		for(j=1;j<comment_length[i];j++)
			printf("%c",comments[i][j]);
		if(j>0)
			printf("\n");
	}
	printf("Comments - count : %d\n", a);

}