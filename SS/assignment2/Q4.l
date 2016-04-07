%{
#include<stdio.h>
int key = 0;
%}
%%
[a-z]         {if((yytext[0]+key)>122) printf("%c",yytext[0]-(26-key)); else printf("%c",yytext[0]+key);}
[A-Z]         {if((yytext[0]+key)>90) printf("%c",yytext[0]-(26-key)); else printf("%c",yytext[0]+key);}
.              ECHO;
%%

int main()
{
printf("Enter a key:");
scanf("%d", &key);
yylex();
return 0;
}