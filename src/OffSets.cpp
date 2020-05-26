#include "OffSets.hpp"
#include <string>

OffSets globl_offsets;

void OffSets::preload(){
    GloblOffSets.emplace_back();
}

void OffSets::store(std::string id, int size){
    //Find on top level - error if found
    auto top = GloblOffSets.rbegin();
    auto found = top->find(id);
    if(found != top->end())
    {
        std::clog <<"# "<< id << "var already has a memory location\n";
        return;
    }
    //Insert in top level
    top->emplace(id,OffSets::gp);
    OffSets::gp += size;
    // std::clog<<"      OFFSET UPDATE TO:"<<OffSets::gp<<"\n";
}   

int OffSets::lookup(std::string id){
    for(auto cur = GloblOffSets.rbegin();cur!=GloblOffSets.rend();cur++){
        auto found = cur->find(id);
        if(found != cur->end()){
            return found->second;
        }
    }
    std::cerr <<"# offset of "<< id << " not defined\n";
    return {};
}

void OffSets::save(std::string id){
    //Find on top level - error if found
    auto top = GloblOffSets.rbegin();
    auto found = top->find(id);
    if(found != top->end())
    {
        std::clog <<"# "<< id << "var already has a memory location\n";
        return;
    }
    //Insert in top level
    top->emplace(id,OffSets::gp);
    std::clog<<"_offset for "<<id<<" saved at "<<OffSets::gp<<"\n";
    return;
}