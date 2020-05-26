#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "symbol_table.hpp"
#include "RegisterPool.hpp"
#include "OffSets.hpp"
#include "Expression.hpp"
// #include "Types.hpp"

struct  Statement{
    Statement() = default;
    virtual void emit() = 0;
};
struct BlockStm : Statement{
    std::vector<Statement*> lines;
    BlockStm():Statement(){}
    BlockStm(Statement* block, Statement* s):Statement(){
        if(block){
            std::clog<<"BlockStm Cast attemp"<<std::endl;
            BlockStm *temp = (BlockStm*)(block);
            std::clog<<"Cast Sucsess!"<<std::endl;
            lines = temp->lines;
        }else{
            std::clog<<"Null BlockStm inharited"<<std::endl;
        }
        if(s){
            lines.emplace_back(s);
        }else{
            std::cerr<<"Warning, null statment added"<<std::endl;
        }
    }
    void emit(){
        std::clog<<"#statment count: "<<lines.size()<<std::endl;
        for (auto &&i : lines){
            i->emit();
        }
    }
};
struct IDlist:Statement{
    std::vector<std::string> IDs;
    IDlist():Statement(){}
    IDlist(Statement* s, char* id):Statement(){
        if(s){
            auto temp = (IDlist*)(s);
            std::clog<<"ID_statement cast: "<< temp<<std::endl;
            IDs = temp->IDs;
            std::clog<<"ID_Constructor exit"<<std::endl;
        }   
        IDs.emplace_back(id);
    }   
    void emit(){
        std::cerr<<"#Hey, you just called emit on an idlist!!!"<<std::endl;
    }
};
struct LValList:Statement{
    std::vector<LValueExpr*> Lvals;
    LValList():Statement(){}
    LValList(LValList* s, LValueExpr* val):Statement(){
        if(s){
            Lvals = s->Lvals;
        }   
        Lvals.emplace_back(val);
    }  
    void emit(){
        std::cerr<<"#Hey, you just called emit on an LvalList!!!"<<std::endl;
    }
};       
struct PseudoConstructor{//this is a bull class meant to get around a circular import issue
    PseudoConstructor()=default;
    RecordExpr* makeRecord(std::string parentID, RecordType* typ){
        auto rec_expr = new RecordExpr(parentID,typ);
        // auto elements= rec_expr->elements;
        for (auto &&element : typ->elements){
            std::clog<<"\n  __Size__"<<typ->elements.size()<<"\n";
            std::clog<<"  Testing-->"<<typ->elements[0].first<<" "<<typ->elements[1].first<<"\n\n";
            std::string name = parentID + "." + element.first; //making a new name for the constant to be sorted
            std::clog<<"PseudoRecordDecl: "<<name<<", "<<element.second->name()<<std::endl;
            if(element.second->name()=="record"){
                auto rec_type = (RecordType*)(element.second);
                auto bull = new PseudoConstructor();
                auto newRecordExpr = bull->makeRecord(name,(RecordType*)(element.second));
                symbol_table.storeConst(name,newRecordExpr);
                rec_expr->insert(element.first,newRecordExpr);
            }else if(element.second->name() == "array"){
                auto arr_type = (ArrayType*)(element.second);
                auto bull = new PseudoConstructor();
                auto newArrayExpr = bull->makeArray(name,(ArrayType*)(element.second));
                symbol_table.storeConst(name,newArrayExpr);
                rec_expr->insert(element.first,newArrayExpr);
            }else{
                auto genExpr = new BlankExpr(element.second->name());
                symbol_table.storeConst(name,genExpr);
                rec_expr->insert(element.first,genExpr);
            }
        }
        return rec_expr;
    };
    ArrayExpr* makeArray(std::string parentID, ArrayType* typ){
        auto arr_expr = new ArrayExpr(parentID, typ);
        for (auto &&element : typ->elements){
            std::string name = parentID + "[" + element.first + "]"; //making a new name for the constant to be sorted
            std::clog<<"PseudoRecordDecl: "<<name<<", "<<element.second->name()<<std::endl;
            if(element.second->name()=="record"){
                auto rec_type = (RecordType*)(element.second);
                auto bull = new PseudoConstructor();
                auto newRecordExpr = bull->makeRecord(name,(RecordType*)(element.second));
                symbol_table.storeConst(name,newRecordExpr);
                arr_expr->insert(element.first,newRecordExpr);
            }else if(element.second->name() == "array"){
                auto arr_type = (ArrayType*)(element.second);
                auto bull = new PseudoConstructor();
                auto newArrayExpr = bull->makeArray(name,(ArrayType*)(element.second));
                symbol_table.storeConst(name,newArrayExpr);
                arr_expr->insert(element.first,newArrayExpr);
            }else{
                auto genExpr = new BlankExpr(element.second->name());
                symbol_table.storeConst(name,genExpr);
                arr_expr->insert(element.first,genExpr);
            }
        }
        return arr_expr;
    };
};
struct VarDeclStm:Statement{
    std::vector<std::string> IDs;
    AbsType *type;
    VarDeclStm():Statement(){}
    VarDeclStm(Statement* list, AbsType* t):Statement(){
        if(list){
            IDlist *temp = (IDlist*)(list);
            IDs = temp->IDs;        
            type = t;
            for (auto &&id : IDs){
                //need to load a blank expresion in the const table.
                if(t->name() == "record"){
                    auto rec_type = (RecordType*)(t);
                    std::clog<<"VAR_DECL_STM (record): "<<id<<std::endl;
                    auto bull = new PseudoConstructor();
                    auto rec_expr = bull->makeRecord(id, rec_type);                    
                    symbol_table.storeConst(id,rec_expr);
                }else if(t->name() == "array"){
                    auto arr_type = (ArrayType*)(t);
                    std::clog<<"VAR_DECL_STM (array): "<<id<<std::endl;
                    std::clog<<id<<" size:"<<type->size()<<"\n";
                    // globl_offsets.save(id);
                    auto bull = new PseudoConstructor();
                    std::clog<<"---of type: "<<arr_type->name()<<std::endl;
                    auto arr_expr = bull->makeArray(id, arr_type);
                    symbol_table.storeConst(id,arr_expr);
                }else{
                    std::clog<<"VAR_DECL_STM ("<<t->name()<<"): "<<id<<std::endl;
                    auto genExpr = new BlankExpr(t->name());
                    symbol_table.storeConst(id,genExpr);
                }
            }
        }
    };
    void emit(){
        std::cout<<"# VarDeclStm called "<<type->name()<<"\n";
        for (auto &&id : IDs){
            if(type->name()=="record"){
                auto rec_type = (RecordType*)(type);
                globl_offsets.save(id);
                int start = globl_offsets.lookup(id);
                std::cout<<"# record: "<<id<<" "<<type->name()<<" size:"<<type->size()<<" starting at: "<<start<<std::endl; 
                rec_type->setOffSets(id);
            }else if(type->name()=="array"){
                auto arr_type = (ArrayType*)(type);
                globl_offsets.save(id);
                arr_type->setOffSets(id);            
                int start = globl_offsets.lookup(id);
                std::cout<<"# array: "<<id<<" "<<type->name()<<" size:"<<type->size()<<" starting at: "<<start<<":"<<std::endl; 
            }else{
                globl_offsets.store(id,type->size());
                int offset =  globl_offsets.lookup(id);
                std::cout<<"# "<<id<<" "<<type->name()<<" "<<offset<<std::endl; 
            }
        }
    }
};

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//
// main block statements
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//

struct AssignStm : Statement{
    LValueExpr* Lvalue;
    Expr* expr;
    AssignStm(LValueExpr* l, Expr* e){Lvalue=l;expr=e;}
    void emitCopy(MultiType* master, MultiType* target, std::string masterOffset, std::string targetOffset){
        std::cout<<"# Emit Copy called; master:"<<masterOffset<<" target:"<<targetOffset<<"\n";
        for (auto iter_master = master->elements.cbegin(), iter_target = target->elements.cbegin(); iter_master !=master->elements.cend() || iter_target != target->elements.cend();++iter_master,++iter_target){
            if(iter_master->second->name()=="array" || iter_master->second->name()=="record"){
                //copy recursion
                auto master_ele_arr = (ArrayType*)(iter_master->second);
                auto target_ele_arr = (ArrayType*)(iter_target->second);
                emitCopy(master_ele_arr, target_ele_arr, masterOffset,targetOffset);
            }else{
                // get the two locations
                // loadword on master
                // saveword to target
                std::string tempReg = reg_pool.popReg();
                std::cout<<" # Saving the target offest registers word to destination\n";
                std::cout<<"lw "<<tempReg<<",("<<targetOffset<<")\n";
                std::cout<<"sw "<<tempReg<<",("<<masterOffset<<")\n";
                reg_pool.pushReg(tempReg);
                //Now, update the offset locations
                int updateSize = iter_master->second->size();
                std::cout<<" # updating the offest registers\n";
                std::cout<<"addi "<< targetOffset<<","<<targetOffset<<","<<updateSize<<'\n';
                std::cout<<"addi "<< masterOffset<<","<<masterOffset<<","<<updateSize<<'\n';
            }
        } 
    }
    void emit(){
        std::cout<<".text #Emit of AssignStm (2.0) "<<Lvalue->type()<<std::endl;
        if(Lvalue->type()=="ID"){
            std::string Lvalue_reg = Lvalue->emit();
            std::string expr_reg = expr->emit();
            if(expr->isLval){                    //finish                    //finish                    //finish
                //need to check for incomplete lvalues
                if(expr->type()=="ID"){
                    std::cout<<"lw "<<expr_reg<<",("<<expr_reg<<")\n";
                    std::cout<<"sw "<<expr_reg<<",("<<Lvalue_reg<<")\n";
                }else if(expr->type()=="record"){
                    //Error catching
                    auto emit_type = ((RecordExpr*)(expr))->emit_type;
                    if(emit_type->name()=="array" || emit_type->name()=="record"){
                        std::cout<<"ERROR: Assignment to ID of incomplete type:"<<emit_type->name()<<"\n";
                        return;
                    }
                    std::cout<<"lw "<<expr_reg<<",("<<expr_reg<<")\n";
                    std::cout<<"sw "<<expr_reg<<",("<<Lvalue_reg<<")\n";
                }else if(expr->type()=="array"){
                    auto emit_type = ((ArrayExpr*)(expr))->emit_type;
                    if(emit_type->name()=="array" || emit_type->name()=="record"){
                        std::cout<<"ERROR: Assignment to ID of incomplete type:"<<emit_type->name()<<"\n";
                        return;
                    }
                    std::cout<<"lw "<<expr_reg<<",("<<expr_reg<<")\n";
                    std::cout<<"sw "<<expr_reg<<",("<<Lvalue_reg<<")\n";
                }else{
                    std::cout<<"ERROR: Assignment to ID of LvalType:"<<expr->type()<<" attempted\n";
                }
            }
            else{
                if(expr->type()=="str"||expr->type()=="bool"){    
                    std::cout<<"lw "<<expr_reg<<",("<<expr_reg<<")\n";
                }
                std::cout<<"sw "<<expr_reg<<", ("<<Lvalue_reg<<")\n\n";
            }
            reg_pool.pushReg(expr_reg);
            reg_pool.pushReg(Lvalue_reg);


        }
        else if(Lvalue->type()=="array"){
            
            std::string Lvalue_reg = Lvalue->emit();
            std::string expr_reg = expr->emit();
            auto emit_type_l = ((ArrayExpr*)(Lvalue))->emit_type;
            AbsType* emit_type_r;
            if(expr->type()=="array"){emit_type_r=((ArrayExpr*)(expr))->emit_type;}
            else if(expr->type()=="record"){emit_type_r=((RecordExpr*)(expr))->emit_type;}
            // if emit type is complex
            if(emit_type_l->name()=="array"){
                if(emit_type_l->name()!=emit_type_r->name()){std::cout<<"Error: Incomplete resolution of types not equal;"<<emit_type_l->name()<<":"<<emit_type_l<<";"<<emit_type_r->name()<<":"<<emit_type_r<<'\n';return;}
                //Some how I need to emit a recursive copy statement
                auto left =(ArrayType*)(emit_type_l);
                auto right=(ArrayType*)(emit_type_r);
                std::cout<<"#"<<left->name()<<left->elements.size()<<"\n";
                std::cout<<"#"<<right->name()<<left->elements.size()<<"\n";
                emitCopy(left,right, Lvalue_reg,expr_reg);
            }
            else if(emit_type_l->name()=="record"){
                if(emit_type_l->name()!=emit_type_r->name()){std::cout<<"Error: Incomplete resolution of types not equal;"<<emit_type_l->name()<<":"<<emit_type_l<<";"<<emit_type_r->name()<<":"<<emit_type_r<<'\n';return;}
                emitCopy((RecordType*)(emit_type_l),(RecordType*)(emit_type_r), Lvalue_reg,expr_reg);
            }
            else{ // if emit type is primitive
                if(expr->type()=="str"||expr->type()=="bool"||expr->type()=="ID"){    
                    std::cout<<"lw "<<expr_reg<<",("<<expr_reg<<")\n";
                }
                std::cout<<"sw "<<expr_reg<<", ("<<Lvalue_reg<<")\n\n";
            }               
            reg_pool.pushReg(expr_reg);
            reg_pool.pushReg(Lvalue_reg);

        }else if(Lvalue->type()=="record"){
            std::string Lvalue_reg = Lvalue->emit();
            std::string expr_reg = expr->emit();
            auto emit_type_l = ((RecordExpr*)(Lvalue))->emit_type;
            AbsType* emit_type_r;
            if(expr->type()=="array"){emit_type_r=((ArrayExpr*)(expr))->emit_type;}
            else if(expr->type()=="record"){emit_type_r=((RecordExpr*)(expr))->emit_type;}
            
            // if emit type is complex
            if(emit_type_l->name()=="array"){
                if(emit_type_l->name()!=emit_type_r->name()){std::cout<<"Error: Incomplete resolution of types not equal;"<<emit_type_l<<":"<<emit_type_r<<'\n';return;}
                //Some how I need to emit a recursive copy statement
                emitCopy((RecordType*)(emit_type_l),(RecordType*)(emit_type_r), Lvalue_reg,expr_reg);
            }else if(emit_type_l->name()=="record"){
                if(emit_type_l->name()!=emit_type_r->name()){std::cout<<"Error: Incomplete resolution of types not equal;"<<emit_type_l<<":"<<emit_type_r<<'\n';return;}
                emitCopy((RecordType*)(emit_type_l),(RecordType*)(emit_type_r), Lvalue_reg,expr_reg);
            }
            else{ // if emit type is primitive
                if(expr->type()=="str"||expr->type()=="bool"||expr->type()=="ID"){    
                    std::cout<<"lw "<<expr_reg<<",("<<expr_reg<<")\n";
                }
                std::cout<<"sw "<<expr_reg<<", ("<<Lvalue_reg<<")\n\n";
            }               
            reg_pool.pushReg(expr_reg);
            reg_pool.pushReg(Lvalue_reg);
        }
    }
};

struct ElifStm : Statement{
    std::vector<std::pair<Expr*,Statement*>> elsePairs; //Condition + Code
    ElifStm():Statement(){}
    ElifStm(Statement* elifBlock, Expr* condition, Statement* block):Statement(){
        if(elifBlock){
            auto temp = (ElifStm*)(elifBlock);
            elsePairs = temp->elsePairs;
        }
        elsePairs.push_back(std::pair<Expr*,Statement*>(condition,block));
    }
    std::string chainEmit(std::string parentLabel, std::string exitLabel){
        auto nextLabel = parentLabel;
        std::cout<<"#emit ELIF block\n";
        for (auto &&pair : elsePairs){
            //label
            std::cout<<nextLabel<<":\n";
            auto con_reg = pair.first->emit();
            nextLabel = str_table.getIfLabel();
            //next branch
            std::cout<<"beq $zero,"<<con_reg<<","<<nextLabel<<std::endl;
            //code
            pair.second->emit();
            //jump to exit
            std::cout<<"j "<<exitLabel<<std::endl<<std::endl;            
        }
        return nextLabel;
        //label
        //next branch
        //code
        //jump to exit
    }
    void emit(){
        std::cout<<"WARNING! Emit on ElifStm called\n";
    }
};
struct IfStm : Statement{
    Expr* condition;
    Statement* ifCode;
    ElifStm* elifBlock;
    Statement* elseCode;
    IfStm(Expr* c, Statement* ifcode, ElifStm* elifblock, Statement* elsecode):Statement(){
        condition=c;
        ifCode=ifcode;
        if(elifblock){elifBlock=elifblock;}
        else{elifBlock=new ElifStm();}
        elseCode=elsecode;  //make sure to check if null
    }
    void emit(){    
        std::cout<<"#Emit IfStm\n"<<std::endl;
        //first branch
        auto firstLabel = str_table.getIfLabel();
        auto exitLabel = str_table.getIfLabel();
        auto con_reg = condition->emit();
        std::cout<<"beq $zero,"<<con_reg<<","<<firstLabel<<std::endl;
        //code
        ifCode->emit();
        //jump to exit
        std::cout<<"j "<<exitLabel<<std::endl;
        //elif
        auto nextlabel = elifBlock->chainEmit(firstLabel,exitLabel);
        //label
        std::cout<<nextlabel<<":\n";
        if(elseCode){
        //code
            elseCode->emit();
        //exit_label
        }
        std::cout<<exitLabel<<":\n";
    }
        //first branch
        //code
        //jump to exit

        //label_first
        //second branch
        //code
        //jump to exit

        //label_second
        //third branch
        //code
        //jump to exit

        //label_third
        //code
        //exit_label

        //////if else////////

        //first branch
        //code
        //jump to exit

        //first_label
        //code
        //exit_label
        
        ///// if //////

        //first branch
        //code
        //exit_label

};
struct WhileStm : Statement{
    Expr* condition;
    Statement* block;
    WhileStm(Expr* c, Statement* b):Statement(){
        condition = c; block = b;
    }
    void emit(){
        int index = str_table.getWhileIndex();
        std::string startLabel = "whileStart"+std::to_string(index);
        std::string exitLabel = "whileExit"+std::to_string(index);
        
        std::cout<<"\n#While Loop\n"<<startLabel<<":"<<std::endl;
        auto con_reg = condition->emit();
        std::cout<<"beq $zero,"<<con_reg<<","<<exitLabel<<std::endl;
        block->emit();
        std::cout<<"j "<<startLabel<<std::endl;
        std::cout<<exitLabel<<":"<<std::endl<<std::endl;

        reg_pool.pushReg(con_reg);
    }
};
struct RepeatStm : Statement{
    Expr* condition;
    Statement* block;
    RepeatStm(Statement* b, Expr* c):Statement(){
        block=b;condition=c;
    }
    void emit(){
        int index = str_table.getWhileIndex();
        std::string startLabel = "doWhileStart"+std::to_string(index);
        
        std::cout<<"\n#doWhile Loop\n"<<startLabel<<":"<<std::endl;
        block->emit();
        auto con_reg = condition->emit();
        std::cout<<"beq $zero,"<<con_reg<<","<<startLabel<<std::endl;

        reg_pool.pushReg(con_reg);
    }
};
struct ForStm : Statement{
    Expr* ID;
    Expr* start;
    Expr* stop;
    int direction;
    Statement* block;
    ForStm(Expr* ID, Expr* start, Expr* stop, int direction, Statement* block):Statement(){
        this->ID = ID;
        this->start = start;
        this->stop = stop;
        this->direction = direction;
        this->block = block;
    }
    void emit(){
        int index = str_table.getForIndex();

        std::string startLabel = "forStart"+std::to_string(index);
        std::string exitLabel = "forExit"+std::to_string(index);
        std::cout<<"\n#For Loop\n"<<std::endl;
        auto start_reg = start->emit();
        auto address_reg = ID->emit();
        auto iter_reg = reg_pool.popReg();
        std::cout<<"sw "<<start_reg<<",("<<address_reg<<")\n";
        reg_pool.pushReg(start_reg);
        auto stop_reg = stop->emit();
        if(direction == 1){
        std::cout<<"addi "<<stop_reg<<","<<stop_reg<<",1\n";
        }else if(direction == -1){
        std::cout<<"subi "<<stop_reg<<","<<stop_reg<<",1\n";
        }
        std::cout<<"lw "<< iter_reg <<" ("<<address_reg<<")\n";
        std::cout<<startLabel<<":"<<std::endl;
        std::cout<<"beq "<<stop_reg<<","<<iter_reg<<","<<exitLabel<<std::endl;
        block->emit();
        std::cout<<"addi "<<iter_reg<<","<<iter_reg<<","<< direction <<std::endl;
        std::cout<<"sw "<<iter_reg<<",("<<address_reg<<")\n";
        std::cout<<"j "<<startLabel<<std::endl;
        std::cout<<exitLabel<<":"<<std::endl<<std::endl;

        reg_pool.pushReg(stop_reg);
        reg_pool.pushReg(iter_reg);
    }
};
struct StopStm : Statement{
    StopStm():Statement(){}
    void emit(){
        exit(0);
    };
};
struct ReturnStm : Statement{};
struct ReadStm : Statement{
    Statement* IDList;
    ReadStm():Statement(){}
    ReadStm(Statement* ids):Statement(){IDList = ids;}
    void emit(){
        std::cout<<"#Read Stm"<<std::endl;
        auto Lvals = (LValList*)(IDList);
        for (auto &&Lval : Lvals->Lvals){
            std::string typ;
            auto Lval_reg = Lval->emit();
            if(Lval->type()=="ID"){
                auto temp = (IDexpresion*)(Lval);
                typ = (symbol_table.lookupConst(temp->ID))->type();
            }else if(Lval->type()=="array"){
                auto temp = (ArrayExpr*)(Lval);
                typ = temp->emit_type->name();
            }else if(Lval->type()=="record"){
                auto temp = (RecordExpr*)(Lval);
                typ = temp->emit_type->name();
            }
            if(typ=="char"){
                std::cout<<".text"<<std::endl;
                std::cout<<"li $v0, 12"<<std::endl;
                std::cout<<"syscall"<<std::endl;
                std::cout<<"sw $v0, ("<<Lval_reg<<")"<<std::endl<<std::endl;
            }else if(typ=="int"){
                std::cout<<".text"<<std::endl;
                std::cout<<"li $v0, 5"<<std::endl;
                std::cout<<"syscall"<<std::endl;
                std::cout<<"sw $v0, ("<<Lval_reg<<")"<<std::endl<<std::endl;
            }else{
                std::cout<<"Screw you! I'm not reading in a type:"<<typ<<std::endl<<std::endl;
            }
            reg_pool.pushReg(Lval_reg);
        }
    }
};
struct ProcedureStm : Statement{};
struct WriteStm:Statement{
    std::vector<Expr*> printArr;
    WriteStm():Statement(){}
    WriteStm(Statement* s, Expr* e):Statement(){
        if(s){
            auto temp = (WriteStm*)(s);
            printArr = temp->printArr;
        }
        printArr.emplace_back(e);
    }
    void emit(){
        for (auto &&expr : printArr){
            std::cout<<"#Write Stm:"<<expr->type()<<std::endl;
            auto exprReg = expr->emit();
            auto type = expr->type();
            if(expr->isLval){
                std::cout<<"lw "<<exprReg<<",("<<exprReg<<")\n";
                if(expr->type()=="ID"){
                    auto IDExpr = (IDexpresion*)(expr);
                    type = symbol_table.lookupConst(IDExpr->ID)->type();
                }else if(expr->type()=="record"){
                    auto recExpr = (RecordExpr*)(expr);
                    type = recExpr->emit_type->name();
                }else if(expr->type()=="array"){
                    auto arrExpr = (ArrayExpr*)(expr);
                    type = arrExpr->emit_type->name();
                }
            }
            //bool might be incorrect
            if(type=="str"){
                std::cout<<"li $v0, 4"<<std::endl;
            }else if(type=="chr"||type=="char"){
                std::cout<<"li $v0, 11"<<std::endl;
            }else{
                std::cout<<"li $v0, 1"<<std::endl;
            }
            std::cout<<"move $a0, "<<exprReg<<std::endl;
            std::cout<<"syscall"<<std::endl<<std::endl;
            reg_pool.pushReg(exprReg);
        }
        
    }
};