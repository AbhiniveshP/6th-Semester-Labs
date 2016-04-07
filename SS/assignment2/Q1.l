%{
#include<stdio.h>
#include<stdlib.h>
%}

Octal [0-7]
Hexa [0-9a-fA-F]
None [g-zG-Z]
%%
{Octal}+ printf("This is an octal/hexadecimal number");
{Hexa}+ printf("This is a hexadecimal number");
({Hexa})*{None}+({Hexa})* printf("\nInvalid input");
%%
int main()
{
yylex();
return 0;
}

