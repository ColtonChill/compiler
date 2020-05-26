#ifndef REG_POOL_HPP
#define REG_POOL_HPP

#include <string>
#include <vector>
#include <iostream>
#include <memory>


struct RegisterPool{
    public:
        using STR = std::string;
        RegisterPool() = default;
        void pushReg(STR);
        STR popReg();
        void preload();
        void exit_scope(){}
    private:
        std::vector<STR> pool;
};

extern RegisterPool reg_pool;

#endif