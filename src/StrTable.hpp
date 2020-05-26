#ifndef STR_TABLE_HPP
#define STR_TABLE_HPP

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <memory>


class StringTable{
    public:
        using STR = std::string;
        StringTable() = default;
        std::string lookupStr(STR);
        bool ifStoredStr(STR);
        void storeStr(std::string);
        int getWhileIndex();
        int getForIndex();
        STR getIfLabel();
        void printTable();

    private:
        std::map<std::string,std::string> StrTable;
        int strCounter = 0;
        int whileCounter = 0;
        int forCounter = 0;
        int ifCounter = 0;
};

extern StringTable str_table;
#endif
