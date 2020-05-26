#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "OffSets.hpp"
#include "RegisterPool.hpp"
#include "Expression.hpp"


struct AbsType{
    AbsType() = default;
    virtual ~AbsType() = default;
    virtual std::string name() = 0;
    virtual int size() = 0;
};

struct PrimativeType: AbsType{
    std::string Name = "primitive";
    PrimativeType():AbsType(){}
    PrimativeType(std::string n):AbsType(){Name = n;}
    int size() { return 4; }
    std::string name() { return Name; }
};

struct IntType : AbsType{
    IntType():AbsType(){}
    int size() { return 4; }
    std::string name() { return "int"; }
};
struct CharType : AbsType{
    CharType():AbsType(){}
    int size() { return 4; }
    std::string name() { return "char"; }
};
struct BoolType : AbsType{
    BoolType():AbsType(){}
    int size() { return 4; }
    std::string name() { return "boolean"; }
};
struct StrType : AbsType{
    StrType():AbsType(){}
    int size() { return 0; }
    std::string name() { return "string"; }
};
struct MultiType: AbsType{
    std::vector<std::pair<std::string, AbsType*>> elements;
    AbsType* find(std::string id){
        for (auto &&element : elements){
            if(element.first==id){
                return element.second;
            }
        }
        std::cerr<<"Warning! Member "<<id<<" not found\n";
        std::cout<<"Error! Member "<<id<<" not found\n";
        return nullptr;
        
    }
    MultiType():AbsType(){}
    virtual int setOffSets(std::string){return 0;}
};
struct ArrayType : MultiType{
    AbsType* typ;
    int indexOffset;
    ArrayType():MultiType(){}
    ArrayType(int low, int high, AbsType* t):MultiType(){
        std::clog<<"ArrayType constructor(int) called\n";
        int l = low;
        indexOffset = low;
        typ = t;
        while(l!=(high+1)){
            elements.push_back(std::pair<std::string,AbsType*>(std::to_string(l),t));
            l+=1;
        }
    }//need 2 constructors, one for nums, one for letters.
    ArrayType(char low, char high, AbsType* t):MultiType(){
        std::clog<<"ArrayType constructor(char) called\n";
        char l = low;
        indexOffset = (int)l;
        typ = t;
        while(l!=(high+1)){
            elements.push_back(std::pair<std::string,AbsType*>(std::to_string(l),t));
            l+=1;
        }

    }
    int size(){
        int total = 0;
        for (auto &&e : elements){
            total += e.second->size();
        }
        return total;
    }
    int setOffSets(std::string parentID){
        for (auto &&element : elements){
            auto name = parentID + "[" + element.first+"]";
            if(element.second->name()=="record"){
                globl_offsets.save(parentID);
                std::cout<<"# record: "<<parentID<<", size:"<<element.second->size()<<std::endl; 
                auto rec_expr = (MultiType*)(element.second);
                rec_expr->setOffSets(name);
            }else if(element.second->name()=="array"){
                globl_offsets.save(parentID);
                std::cout<<"# array: "<<parentID<<", size:"<<element.second->size()<<std::endl; 
                auto arr_type = (MultiType*)(element.second);
                arr_type->setOffSets(name);
            }else{
                globl_offsets.store(name, element.second->size());
                int offset = globl_offsets.lookup(name);
                std::cout<<"# "<<name<<" "<<element.second->name()<<" "<<offset<<std::endl;
            }
        }
    }
    std::string name(){return "array";}
};
struct RecordType : MultiType{
    RecordType():MultiType(){}
    RecordType(std::vector<std::string> id_list, AbsType* typ):MultiType(){
        std::clog<<"RecordType constructor called\n";
        for (auto &&id : id_list){
            std::clog<<" "<<id<<" ";
            elements.push_back(std::pair<std::string,AbsType*>(id,typ));
        }
        std::clog<<" "<<typ->name()<<" type passed to constructor\n";
    }
    void insert(RecordType* r){
        for (auto && element : r->elements){
            std::clog<<" $insert id:"<<element.first<<", type:"<<element.second->name()<<"\n\n";
            elements.push_back(element);
        }
        std::clog<<"\nRollCall:\n";
        for (auto &&ele : elements)
        {
            std::clog<<"\tID"<<ele.first<<", type:"<<ele.second->name()<<"\n";
        }
    }
    int size(){
        int total = 0;
        for(auto &&element : elements){
            total += element.second->size();
        }
        return total;
    }
    int refOffset(std::string id){
        auto found = find(id);
        if(found){
            std::clog<<"Member successfully found:"<<id<<"\n";
            int total = 0;
            for(auto iter=elements.cbegin();iter!=elements.cend();++iter){
                if(iter->first==id){
                    return total;
                }
                total+=iter->second->size();
            }
        }else{
            std::cerr<<"Warning! Member "<<id<<" not found\n";
            std::cout<<"Error! Member "<<id<<" not found\n";
            return -1;
        }
    }
    int setOffSets(std::string parentID){
        globl_offsets.save(parentID);
        for (auto &&element : elements){
            auto name = parentID + "." + element.first;
            if(element.second->name()=="record"){
                std::cout<<"# record: "<<parentID<<", size:"<<element.second->size()<<std::endl; 
                auto rec_expr = (MultiType*)(element.second);
                rec_expr->setOffSets(name);
            }else if(element.second->name()=="array"){
                std::cout<<"# array: "<<parentID<<", size:"<<element.second->size()<<std::endl; 
                auto arr_type = (MultiType*)(element.second);
                arr_type->setOffSets(name);
            }else{
                globl_offsets.store(name, element.second->size());
                int offset = globl_offsets.lookup(name);
                std::cout<<"# "<<name<<" "<<element.second->name()<<" "<<offset<<std::endl;
            }
        }
    }
    std::string name(){return "record";}
};
