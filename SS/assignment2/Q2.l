%{
#include<stdio.h>
%}
%%
[\n\t ''] {};
%%
int main()
{
yylex();
return 0;
}