#include "symbol_table.hpp"
#include "Statement.hpp"
#include "Types.hpp"
#include <iostream>
#include <memory>

SymbolTable symbol_table;

int SymbolTable::getLineCount(){return lineCount;}
void SymbolTable::upLineCount(){++lineCount;}

SymbolTable::Exp SymbolTable::lookupConst(std::string id){
  for(auto cur = ConstVars.rbegin();cur!=ConstVars.rend();cur++)
  {
    auto found = cur->find(id);
    if(found != cur->end())
    {
      return found->second;
    }
  }
  std::clog<<"_ " << id << " not defined"<<std::endl;
  return {};
}

SymbolTable::Exp SymbolTable::backupConst(std::string id){
  auto top = ConstVars.rbegin();
  for(auto cur = ConstVars.rbegin();cur!=ConstVars.rend();cur++)
  {
    auto found = cur->find(id);
    if(found == cur->end())
    {
      std::cerr<<"_ " << id << " dinamically created"<<std::endl;
      auto temp = new BlankExpr();
      top->emplace(id,temp);
      return temp;
    }
  }
  std::cerr<<"Back up unnecessary for "<<id<<"\n";
  return {};
}

void SymbolTable::storeConst(std::string id,Exp e){
  //Find on top level - error if found
  auto top = ConstVars.rbegin();
  auto found = top->find(id);
  if(found != top->end()){
    if(found->second->isConst){
      std::clog<<"_ "<< id << " already defined"<<std::endl;
      return;
    }
    std::clog<<"_ "<< id << " Var redefined as type " <<e->type()<<std::endl;
    //////temp code
    if(e->type()=="ID"){
      auto tempExpr = (IDexpresion*)(e);
      auto nextExpr = SymbolTable::lookupConst(tempExpr->ID);
      std::clog<<"_ "<<tempExpr->ID<<" also of type: "<<nextExpr->type()<<std::endl;
    }
    //////////
    top->erase(id);
  }
  //Insert in top level
  std::clog<<"_var "<<id<<": "<<e->type()<<" stored"<<std::endl;
  top->emplace(id,e);
}

SymbolTable::Exp SymbolTable::lookupFunct(std::string id){
  for(auto cur = FunctVars.rbegin();cur!=FunctVars.rend();cur++)
  {
    auto found = cur->find(id);
    if(found != cur->end())
    {
      return found->second;
    }
  }
  std::clog<<"_ "<< id << " not defined"<<std::endl;
  return {};
}

void SymbolTable::storeFunct(std::string id,Exp e){
  //Find on top level - error if found
  auto top = FunctVars.rbegin();
  auto found = top->find(id);
  if(found != top->end())
  {
    std::clog<<"_ "<< id << " already defined"<<std::endl;
    return;
  }
  //Insert in top level
  top->emplace(id,e);
}

SymbolTable::Exp SymbolTable::lookupProc(std::string id){
  for(auto cur = ProcVars.rbegin();cur!=ProcVars.rend();cur++)
  {
    auto found = cur->find(id);
    if(found != cur->end())
    {
      return found->second;
    }
  }
  std::clog<<"_ "<< id << " not defined"<<std::endl;
  return {};
}

void SymbolTable::storeProc(std::string id,Exp e){
  //Find on top level - error if found
  auto top = ProcVars.rbegin();
  auto found = top->find(id);
  if(found != top->end())
  {
    std::clog<<"# "<< id << " already defined"<<std::endl;
    return;
  }
  //Insert in top level
  top->emplace(id,e);
}

SymbolTable::Ty SymbolTable::lookupType(std::string id){
  for(auto cur = TypeVars.rbegin();cur!=TypeVars.rend();cur++)
  {
    auto found = cur->find(id);
    if(found != cur->end())
    {
      return found->second;
    }
  }
  std::clog<<"# "<< id << " not defined"<<std::endl;
  return {};
}

void SymbolTable::storeType(std::string id,Ty e){
  //Find on top level - error if found
  auto top = TypeVars.rbegin();
  auto found = top->find(id);
  if(found != top->end())
  {
    std::clog<<"_ "<< id << " Type redefined"<<std::endl;
    top->erase(id);
  }
  //Insert in top level
  top->emplace(id,e);
}


void SymbolTable::enter_scope(){
  ConstVars.emplace_back();
  FunctVars.emplace_back();
  ProcVars.emplace_back();
  TypeVars.emplace_back();
  preload();
}

void SymbolTable::exit_scope(){
  ConstVars.pop_back();
  FunctVars.pop_back();
  ProcVars.pop_back();
  TypeVars.pop_back();
}

void SymbolTable::preload(){
  auto t = new BoolLiteral(true);
  t->isConst=false;
  auto f = new BoolLiteral(false);
  f->isConst=false;
  storeConst("true",t);
  storeConst("false",f);
  auto top = TypeVars.rbegin();
  auto i = new IntType();
  top->emplace("integer",i);
  top->emplace("INTEGER",i);
  auto c = new CharType();
  top->emplace("char",c);
  top->emplace("CHAR",c);
  auto b = new BoolType();
  top->emplace("boolean",b);
  top->emplace("BOOLEAN",b);
  auto s = new StrType();
  top->emplace("string",s);
  top->emplace("STRING",s);
}