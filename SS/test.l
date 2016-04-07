%{
int count1=0;
int count2=0;
%}
%%
"a"I"e"I"i"I"o"I"u" {printf("%s is vowel",yytext);count1++;}
[a-zA-Z] {printf("%s is constonant",yytext);count2++;}
.I\n {ECHO;}
%%
main()
{
yylex();
printf("%d Vowel =%d constonant=",count1,count2);
}