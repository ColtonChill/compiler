#ifndef OFF_SETS_HPP
#define OFF_SETS_HPP

#include <vector>
#include <iostream>
#include <map>
#include <memory>
#include <string>

struct OffSets{
    public:
        void preload();
        void store(std::string, int);
        int lookup(std::string);
        void save(std::string);
        
    private:
        std::vector<std::map<std::string, int>> GloblOffSets;
        // std::vector<std::string> scope_names;
        // std::vector<int> stored_offsets;
        int gp = 0;
};

extern OffSets globl_offsets;
#endif