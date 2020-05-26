#include "RegisterPool.hpp"
#include <string>

RegisterPool reg_pool;

void RegisterPool::preload(){
    pool.emplace_back();
    pushReg("$s7");
    pushReg("$s6");
    pushReg("$s5");
    pushReg("$s4");
    pushReg("$s3");
    pushReg("$s2");
    pushReg("$s1");
    pushReg("$s0");
    pushReg("$t9");
    pushReg("$t8");
    pushReg("$t7");
    pushReg("$t6");
    pushReg("$t5");
    pushReg("$t4");
    pushReg("$t3");
    pushReg("$t2");
    pushReg("$t1");
    pushReg("$t0");
}

RegisterPool::STR RegisterPool::popReg(){
    if(pool.size()<1){
        std::cerr<<"#Empty Register pool drawn from"<<std::endl;
        return nullptr;
    }else{
        // std::cerr<<"alright, here's you register"<<std::endl;
        STR temp = pool.back();
        pool.pop_back();
        return temp;
    }
    
}

void RegisterPool::pushReg(RegisterPool::STR reg){
    // std::cout<<"  #_Regerister "<<reg<<" released\n";
    pool.emplace_back(reg);
}