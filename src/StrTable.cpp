#include "StrTable.hpp"
#include <string>
#include <vector>
#include <map>
#include <iostream>

StringTable str_table;

bool StringTable::ifStoredStr(StringTable::STR s){
  auto found = StrTable.find(s);
  if(found != StrTable.end()){
    return true;
  }
  std::clog <<"# "<< s << " not defined\n";
  return false;
}

void StringTable::storeStr(StringTable::STR s){
    //Find on top level - error if found
    auto found = StrTable.find(s);
    if(found != StrTable.end()){
      std::clog <<"# "<< s << "str already defined in label table\n";
      return;
    }
    //Insert in top level
    std::string label = "str" + std::to_string(StringTable::strCounter);
    StringTable::strCounter++;
    StrTable.emplace(s,label);
}

StringTable::STR StringTable::lookupStr(std::string s){
  for(int i = 0;i<2;++i){
      auto found = StrTable.find(s);
      if(found != StrTable.end()){
        return found->second;
      }
    StringTable::storeStr(s);
  }
  std::clog<<"String Failed to be added to the table"<<std::endl;
  return {};
}

void StringTable::printTable(){
  for (auto &&ele : StrTable){
    std::cout<<ele.second<<":"<<" .asciiz "<<ele.first<<std::endl;
  }  
}

int StringTable::getWhileIndex(){
  whileCounter++;
  return whileCounter;
}

int StringTable::getForIndex(){
  forCounter++;
  return forCounter;
}

StringTable::STR StringTable::getIfLabel(){
  ifCounter++;
  return "if_Label_"+std::to_string(ifCounter);
}