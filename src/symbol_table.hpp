#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Expression.hpp"
#include "Types.hpp"

class SymbolTable
{
  public:
    // using Expr = Expression*;
    using Exp = Expr*;
    using Ty = AbsType*;
    using STR = char*;
    SymbolTable() = default;
    int getLineCount();
    void upLineCount();
    Exp lookupConst(std::string);
    Exp backupConst(std::string);
    Exp lookupFunct(std::string);
    Exp lookupProc(std::string);
    Ty lookupType(std::string);
    void storeConst(std::string,Exp);
    void storeFunct(std::string,Exp);
    void storeProc(std::string,Exp);
    void storeType(std::string,Ty);
    std::string popReg();
    void pushReg(std::string);
    void enter_scope();
    void exit_scope();

  private:
    
    int lineCount = 1;
    std::vector<std::map<std::string,Exp>> ConstVars;
    std::vector<std::map<std::string,Exp>> FunctVars;
    std::vector<std::map<std::string,Exp>> ProcVars;
    std::vector<std::map<std::string,Ty>> TypeVars;
    void preload();
};

extern SymbolTable symbol_table;
#endif
