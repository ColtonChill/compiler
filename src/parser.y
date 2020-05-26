%{
#include <iostream>
#include <map>

#include "Expression.hpp"
#include "Statement.hpp"
#include "Types.hpp"
#include "symbol_table.hpp"
#include "Interface.hpp"
// #include "functions.hpp"

extern int yylex();
void yyerror(const char*);
%}
%code requires{
    #include "Expression.hpp"
    #include "Statement.hpp"
    #include "Types.hpp"
}

%union
{
int i_val;
char char_val;
char* str_val;
AbsType* type_val;
Expr* expr_val;
Statement* stm_val;
}
%error-verbose

%token ID
%token OCT
%token HEX
%token STRING

%token ADD
%token SUB
%token MULT
%token DIV
%token MOD
%token OPENP
%token CLOSEP
%token OPENB
%token CLOSEB
%token DONE
%token INT
%token GETS
%token EQUALS
%token LT
%token LTQ
%token GT
%token GTQ
%token NEQ
%token AND
%token OR
%token NOT
%token DOT
%token COMMA
%token COLON

%token CRETURN
%token BACKSPACE
%token FORMFEED
%token SQUOTE
%token DQUOTE

%token VAR
%token CHR
%token ARRAY
%token IF
%token ELSEIF
%token ELSE
%token RECORD
%token THEN
%token WRITE
%token BEG
%token END
%token OF
%token REF
%token TO
%token ORD
%token REPEAT
%token TYPE
%token CONST
%token FOR
%token PRED
%token RETURN
%token UNTIL
%token DO
%token FORWARD
%token PROCEDURE
%token STOP
%token DOWNTO
%token FUNCTION
%token READ
%token SUCC
%token WHILE

%right NOT SUB 
%left ADD MULT DIV MOD
%nonassoc EQUALS LT LTQ GT GTQ NEQ OR AND


%type <i_val> INT
%type <i_val> HEX
%type <i_val> OCT
%type <stm_val> VarDecl
%type <stm_val> VarList
%type <stm_val> DefinitionBlock
%type <stm_val> VarOption
%type <stm_val> MainBlock
%type <stm_val> CodeBlock
%type <stm_val> CodeOpt
%type <stm_val> SomeStatement
%type <stm_val> Assignment
%type <stm_val> StopStatement
%type <stm_val> WhileStatement
%type <stm_val> ReadStatement
%type <stm_val> WriteStatement
%type <stm_val> IfStatement
%type <stm_val> ElifBlock
%type <stm_val> ElseBlock
%type <stm_val> ForStatement
%type <i_val> ToDownto
%type <stm_val> RepeatStatement
%type <stm_val> WriteOpt
%type <expr_val> Expression
%type <expr_val> Term
%type <expr_val> Factor
%type <stm_val> IDList
%type <stm_val> LvalList
%type <stm_val> ExtraID
%type <stm_val> ExtraLval
%type <str_val> ID
%type <str_val> STRING
%type <i_val> TypeList
%type <type_val> Type
%type <type_val> SimpleType
%type <type_val> RecordType
%type <type_val> RecordList
%type <type_val> Record
%type <type_val> ArrayType
%type <i_val> ExtraTerm
%type <expr_val> LValue
%%

daProgram : ConstDecl TypeDecl VarDecl DefinitionBlock MainBlock DOT{c::EmitMain($3,$4,$5);} 
          ;
ConstDecl : CONST ConstList {}
          | {}
          ;
ConstList : ConstList ID EQUALS Expression DONE{c::SaveConst($2,$4);}
          | {}
          ;
TypeDecl : TYPE TypeList {}
         | {}
         ;
TypeList : TypeList ID EQUALS Type DONE {c::SaveType($2,$4);}
         | {}
         ;
VarDecl : VAR VarList {$$ = $2;}
        | {$$ = nullptr;}
        ;
VarList : VarList IDList COLON Type DONE {$$ = c::MakeVarDecl($1,$2,$4);}
        | {$$ = nullptr;} 
        ;
DefinitionBlock : DefinitionBlock ProcedureDecl{$$ = c::MakeStop();}
                | DefinitionBlock FunctionDecl{$$ = c::MakeStop();}
                | {$$ = nullptr;}
                ;
ProcedureDecl : PROCEDURE ID OPENP Parameters CLOSEP DONE FORWARD DONE {}
              | PROCEDURE ID OPENP Parameters CLOSEP DONE VarDecl MainBlock DONE {}
              ;
FunctionDecl : FUNCTION ID OPENP Parameters CLOSEP COLON Type DONE FORWARD DONE {}
             | FUNCTION ID OPENP Parameters CLOSEP COLON Type DONE VarDecl MainBlock DONE{}
             ;
Type : SimpleType {$$ = $1;}
     | RecordType {$$ = $1;}
     | ArrayType {$$ = $1;}
     ;
SimpleType : ID {$$ = c::LoadType($1);}
           ;
RecordType : RECORD RecordList END{$$=$2;}
           ;
RecordList : RecordList Record{$$ = c::MakeRecord($1,$2);}
           | {$$ = nullptr;}
           ;
Record : IDList COLON Type DONE {$$ = c::MakeRecord($1,$3);}
       ;
ArrayType : ARRAY OPENB Expression COLON Expression CLOSEB OF Type {$$ = c::MakeArray($3,$5,$8);}
          ;
Parameters : Parameters SemiOpt Parameter{}
           | {}
           ;
Parameter : VarOption IDList COLON Type{c::MakeVarDecl($1,$2,$4);}
          ;
VarOption : REF {$$ = nullptr;}
          | VAR {$$ = nullptr;}
          | {$$ = nullptr;}
          ;
MainBlock : BEG SemiOpt CodeBlock END{$$ = $3;}
          | {}
          ;
CodeBlock : CodeOpt SomeStatement SemiOpt {$$ = c::MakeMain($1,$2);}//Dont forget intermitent ";"
          ;
SemiOpt : DONE {}
        | {}
        ;
CodeOpt : CodeOpt SomeStatement DONE {$$ = c::MakeMain($1,$2);}
        | {$$ = nullptr;}
        ;
SomeStatement : Assignment {$$ = $1;}
              | IfStatement {$$ = $1;}
              | WhileStatement {$$ = $1;}
              | RepeatStatement {$$ = $1;}
              | ForStatement {$$ = $1;}
              | StopStatement {$$ = $1;}
              | ReturnStatement {}
              | ReadStatement {$$ = $1;}
              | WriteStatement {$$ = $1;}
              | ProcedureCall {}
              ;
Assignment : LValue GETS Expression{$$ = c::MakeVarAssignment($1,$3);}
           ;
IfStatement : IF Expression THEN CodeBlock ElifBlock ElseBlock END{$$ = c::MakeIf($2,$4,$5,$6);}
            ;
ElifBlock : ElifBlock ELSEIF Expression THEN CodeBlock {$$ = c::MakeElif($1,$3,$5);}
          | {$$ = nullptr;}
          ;
ElseBlock : ELSE CodeBlock {$$=$2;}
          | {$$ = nullptr;}
          ;
WhileStatement : WHILE Expression DO CodeBlock END {$$ = c::MakeWhileStm($2,$4);}
               ;
RepeatStatement : REPEAT CodeBlock UNTIL Expression {$$ = c::MakeRepeat($2,$4);}
                ;
ForStatement : FOR LValue GETS Expression ToDownto Expression DO CodeBlock END {$$ = c::MakeFor($2,$4,$5,$6,$8);}
             ;
ToDownto : TO {$$ = 1;} 
         | DOWNTO {$$ = -1;}
         ;
StopStatement : STOP {$$ = c::MakeStop();}
              ;
ReturnStatement : RETURN Expression {}
                | RETURN {}
                ;
ReadStatement : READ OPENP LvalList CLOSEP{$$ = c::MakeRead($3);}
              ;
WriteStatement : WRITE OPENP WriteOpt Expression CLOSEP{$$ = c::MakeWrite($3,$4);}
               ;
WriteOpt : WriteOpt Expression COMMA {$$ = c::MakeWrite($1, $2);}
         | {$$ = nullptr;}
         ;
ProcedureCall : ID OPENP ExpressionList CLOSEP {}
              ;
ExpressionList : ExtraTerm Expression {}
               | {}
               ;
ExtraTerm : ExtraTerm Expression COMMA {}
          | {}
          ;
IDList : ExtraID ID {$$ = c::MakeIDList($1,$2);}
       ;
ExtraID : ExtraID ID COMMA  {$$ = c::MakeIDList($1,$2);}
        | {$$ = nullptr;}
        ;
LvalList : ExtraLval LValue {$$ = c::MakeLvalList($1,$2);}
       ;
ExtraLval : ExtraLval LValue COMMA  {$$ = c::MakeLvalList($1,$2);}
          | {$$ = nullptr;}
          ;
LValue : LValue DOT ID {$$=c::MakeRecordMember($1,$3);}
       | LValue OPENB Expression CLOSEB {$$ = c::MakeArrayReference($1,$3);}
       | ID {$$ = c::MakeID($1);}
       ;
Expression : Expression OR Expression {$$ = c::MakeOr($1,$3);}
           | Expression AND Expression {$$ = c::MakeAnd($1,$3);}
           | NOT Expression {$$ = c::MakeNot($2);}
           | Expression EQUALS Expression {$$ = c::MakeEquals($1,$3);}
           | Expression NEQ Expression {$$ = c::MakeNEQ($1,$3);}
           | Expression LTQ Expression {$$ = c::MakeLTQ($1,$3);}
           | Expression GTQ Expression {$$ = c::MakeGTQ($1,$3);}
           | Expression LT Expression {$$ = c::MakeLT($1,$3);}
           | Expression GT Expression {$$ = c::MakeGT($1,$3);}
           | Expression SUB Term {$$ = c::MakeSub($1,$3);}
           | Expression ADD Term {$$ = c::MakeAdd($1,$3);}
           | Term {$$ = $1;}
           | CHR OPENP Expression CLOSEP {$$ = c::MakeChr($3);}
           | ORD OPENP Expression CLOSEP {$$ = c::MakeOrd($3);}
           | PRED OPENP Expression CLOSEP {$$=c::MakePred($3);}
           | SUCC OPENP Expression CLOSEP {$$=c::MakeSucc($3);}
           ;
Term : Term MOD Factor {$$ = c::MakeMod($1,$3);}
     | Term DIV Factor {$$ = c::MakeDiv($1,$3);}
     | Term MULT Factor {$$ = c::MakeMult($1,$3);}
     | SUB Factor {$$ = c::MakeNegative($2);}
     | Factor {$$ = $1;}
     ;
Factor : OPENP Expression CLOSEP {$$ = $2;}
       | LValue {$$ = $1;}
       | INT {$$ = c::MakeInt($1);}
       | STRING {$$ = c::MakeStr($1);}
       | ProcedureCall {$$ = nullptr; std::cerr<<"That's a funciton call!"<<std::endl;}
       ;


%%

void yyerror(const char* msg)
{
  std::cerr << "line " << symbol_table.getLineCount() << ": "<< msg << std::endl;
}