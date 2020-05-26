%{
#include <cstdlib>
#include <iostream>

#include "parser.hpp"
#include "symbol_table.hpp"
%}


%option noyywrap
%%

"+" {return ADD;}
"-" {return SUB;}
"*" {return MULT;}
"/" {return DIV;}
"%" {return MOD;}
"(" {return OPENP;}
")" {return CLOSEP;}
"[" {return OPENB;}
"]" {return CLOSEB;}
";" {return DONE;}
"=" {return EQUALS;}
":=" {return GETS;}
"<" {return LT;}
"<=" {return LTQ;}
">" {return GT;}
">=" {return GTQ;}
"<>" {return NEQ;}
"&" {return AND;}
"|" {return OR;}
"~" {return NOT;}
"." {return DOT;}
"," {return COMMA;}
":" {return COLON;}
\n {symbol_table.upLineCount();}
"\r"|"\\r" {return CRETURN;}
"\b"|"\\b" {return BACKSPACE;}
"\f"|"\\f" {return FORMFEED;}
"\'" {return SQUOTE;}
"\"" {return DQUOTE;}
var|VAR {return VAR;}
chr|CHR {return CHR;}
array|ARRAY {return ARRAY;}
if|IF {return IF;}
elseif|ELSEIF {return ELSEIF;}
else|ELSE {return ELSE;}
record|RECORD {return RECORD;}
then|THEN {return THEN;}
write|WRITE {return WRITE;}
begin|BEGIN {return BEG;}
end|END {return END;}
of|OF {return OF;}
ref|REF {return REF;}
to|TO {return TO;}
ord|ORD {return ORD;}
repeat|REPEAT {return REPEAT;}
type|TYPE {return TYPE;}
const|CONST {return CONST;}
for|FOR {return FOR;}
pred|PRED {return PRED;}
return|RETURN {return RETURN;}
until|UNTIL {return UNTIL;}
do|DO {return DO;}
forward|FORWARD {return FORWARD;}
procedure|PROCEDURE {return PROCEDURE;}
stop|STOP {return STOP;}
downto|DOWNTO {return DOWNTO;}
function|FUNCTION {return FUNCTION;}
read|READ {return READ;}
succ|SUCC {return SUCC;}
while|WHILE {return WHILE;}

[a-zA-Z][a-zA-Z0-9_]* {yylval.str_val = strdup(yytext);return ID;}

[0][X][0-9a-fA-F]* {yylval.i_val = strtol(yytext,nullptr,0); return HEX;}
[0][0-7]+ {yylval.i_val = strtol(yytext,nullptr,0); return OCT;}
[0-9]*\.[0-9]* {yylval.i_val = atof(yytext);return INT;}
[0-9]+ {yylval.i_val = atof(yytext);return INT;}
\'\\n\' {yylval.str_val = strdup(yytext);return STRING;}
\'\\t\' {yylval.str_val = strdup(yytext);return STRING;}    
\"[a-zA-Z0-9~`!@'#$%^&*()_+=\-\[\]{}\\\/><,.:;| ]+\" {yylval.str_val = strdup(yytext); return STRING;}
\'[a-zA-Z0-9~`!@"#$%^&*()_+=\-\[\]{}\\\/><,.:;| ]\' {yylval.str_val = strdup(yytext); return STRING;}
\$.*$ {}
[ \t]+ {}
. {std::cout<<"unexepected token "<<yytext<<std::endl;}
%%