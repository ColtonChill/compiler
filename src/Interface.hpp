#ifndef allDaClass_HPP
#define allDaClass_HPP

#include <memory>
#include <string>
#include <vector>
#include "symbol_table.hpp"
#include "Statement.hpp"
#include "Types.hpp"

// std::vector<Literal> literalMem;
// std::vector<BinaryExpr> binaryExprMem;
// std::vector<AddExpr> addExprMem;
// std::vector<Expr*> mem;

namespace c{    
    // @Note to self, There is nothing handled bool to ints
    void EmitMain(Statement* varBlock, Statement* functionBlock, Statement* mainBlock){
        //fuction hack
        std::string tempStr;
        if(functionBlock){
            tempStr = str_table.lookupStr("\"This program contains a function/procedure feature, This functionality is not yet implemented. Sorry for the inconvenience.\"\n");
        }
        //////////
        std::clog<<std::endl<<"#Emit Main tripped"<<std::endl;

        auto trueExpr = symbol_table.lookupConst("true");
        auto falseExpr = symbol_table.lookupConst("false");
        globl_offsets.store("true",4);
        globl_offsets.store("false",4);
        int trueOffset = globl_offsets.lookup("true");
        int falseOffset = globl_offsets.lookup("false");
        
        // std::clog<<"true is of type: "<<trueExpr->type()<<std::endl;
        // std::clog<<"false is of type: "<<falseExpr->type()<<std::endl;
        //////////////////////////////
        
        auto t = (BoolLiteral*)(trueExpr);
        auto f = (BoolLiteral*)(falseExpr);

        std::cout<<".data\n";
        str_table.printTable();
        std::cout<<".text #bool key words\n";
        std::cout<<"li $t0,"<<t->data<<std::endl;
        std::cout<<"sw $t0,"<<trueOffset<<"($gp) #True"<<std::endl;
        std::cout<<"li $t0,"<<f->data<<std::endl;
        std::cout<<"sw $t0,"<<falseOffset<<"($gp) #False"<<std::endl<<std::endl;
        

        if(varBlock){
            std::cout<<"#_VarBlock"<<std::endl;
            varBlock->emit();
        }
        if(functionBlock){
            std::cout<<"#_FunctionCopout"<<std::endl;
            std::cout<<".globl main\nmain:\n";
            auto strReg = reg_pool.popReg();
            std::cout<<"la "<<strReg<<", "<<tempStr<<std::endl;
            std::cout<<"li $v0, 4"<<std::endl;
            std::cout<<"move $a0, "<<strReg<<std::endl;
            std::cout<<"syscall"<<std::endl;
            std::cout<<"exit_main:\n";
            functionBlock->emit();
        }else
        if(mainBlock){
            std::cout<<"#_MainBLOCK"<<std::endl;
            std::cout<<".globl main\nmain:\n";
            mainBlock->emit();
            std::cout<<"exit_main:\n";
        }
        return;
    }
    
    Statement* MakeMain(Statement* block, Statement* s){
        return new BlockStm(block,s);
    }

    //\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//
    //Control statements
    //\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//
    Statement* MakeStop(){
        std::clog<<"Made stop"<<std::endl;
        return new StopStm();
    }
    Statement* MakeIf(Expr* condition, Statement* ifCode, Statement* elifBlock, Statement* elseCode){
        return new IfStm(condition,ifCode,(ElifStm*)(elifBlock),elseCode);
    }
    Statement* MakeElif(Statement* elifBlock, Expr* condition, Statement* block){
        return new ElifStm(elifBlock, condition, block);
    } 
    Statement* MakeFor(Expr* ID, Expr* start, int direction, Expr* stop, Statement* block){
        std::clog<<"MakeFor"<<std::endl;
        return new ForStm(ID, start, stop, direction, block);
    }
    Statement* MakeRepeat(Statement* block, Expr* condition){
        return new RepeatStm(block,condition);
    }

    //\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//
    //Binary expresions
    //\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//
    Expr* MakeOr(Expr* a, Expr* b){
        std::clog<<"MakeOR: "<< a->isConst<<":"<< b->isConst <<std::endl;
        auto temp = new OrExpr(a,b);
        if(temp->isFoldable()){
            bool l = temp->lnum() | temp->rnum();
            auto temp = new BoolLiteral(l);
            std::clog<<"isFoldable passed: "<<l<<std::endl;
            return temp;
        }
        return temp;
    }
    Expr* MakeAnd(Expr* a, Expr* b){
        std::clog<<"MakeAnd: "<< a->isConst<<":"<< b->isConst <<std::endl;
        auto temp = new AndExpr(a,b);
        if(temp->isFoldable()){
            bool l = temp->lnum() | temp->rnum();
            auto temp = new BoolLiteral(l);
            std::clog<<"Foldable passed: "<<l<<std::endl;
            return temp;
        }
        return temp;
    }
    Expr* MakeNot(Expr* a){
        std::clog<<"MakeNot: "<< a->isConst<<std::endl;
        auto temp = new NotExpr(a);
        if(temp->isFoldable()){
            bool l = !temp->lnum();
            auto temp = new BoolLiteral(l);
            std::clog<<"Foldable passed: "<<l<<std::endl;
            return temp;
        }
        return temp;
    }
    Expr* MakeLT(Expr* a, Expr* b){
        std::clog<<"MakeLT: "<< a->isConst<<":"<< b->isConst <<std::endl;
        auto temp = new LTExpr(a,b);
        if(temp->isFoldable()){
            bool l = temp->lnum() < temp->rnum();
            auto temp = new BoolLiteral(l);
            std::clog<<"Foldable passed: "<<l<<std::endl;
            return temp;
        }
        return temp;
    }
    Expr* MakeGT(Expr* a, Expr* b){
        std::clog<<"MakeGT: "<< a->isConst<<":"<< b->isConst <<std::endl;
        auto temp = new GTExpr(a,b);
        if(temp->isFoldable()){
            bool l = temp->lnum() > temp->rnum();
            auto temp = new BoolLiteral(l);
            std::clog<<"Foldable passed: "<<l<<std::endl;
            return temp;
        }
        return temp;
    }
    Expr* MakeLTQ(Expr* a, Expr* b){
        std::clog<<"MakeLTQ: "<< a->isConst<<":"<< b->isConst <<std::endl;
        auto temp = new LTQExpr(a,b);
        if(temp->isFoldable()){
            bool l = temp->lnum() <= temp->rnum();
            auto temp = new BoolLiteral(l);
            std::clog<<"Foldable passed: "<<l<<std::endl;
            return temp;
        }
        return temp;
    }
    Expr* MakeGTQ(Expr* a, Expr* b){
        std::clog<<"MakeGTQ: "<< a->isConst<<":"<< b->isConst <<std::endl;
        auto temp = new GTQExpr(a,b);
        if(temp->isFoldable()){
            bool l = temp->lnum() >= temp->rnum();
            auto temp = new BoolLiteral(l);
            std::clog<<"Foldable passed: "<<l<<std::endl;
            return temp;
        }
        return temp;
    }
    Expr* MakeEquals(Expr* a, Expr* b){
        std::clog<<"MakeEquals: "<< a->isConst<<":"<< b->isConst <<std::endl;
        auto temp = new EqualsExpr(a,b);
        if(temp->isFoldable()){
            std::clog<<"D: "<<temp->lnum()<<"="<<temp->rnum()<<std::endl;
            bool l = temp->lnum() == temp->rnum();
            auto temp = new BoolLiteral(l);
            std::clog<<"isFoldable passed: "<<l<<std::endl;
            return temp;
        }
        return temp;
    }    
    Expr* MakeNEQ(Expr* a, Expr* b){
        std::clog<<"MakeNEQ: "<< a->isConst<<":"<< b->isConst <<std::endl;
        auto temp = new NEQExpr(a,b);
        if(temp->isFoldable()){
            bool l = temp->lnum() != temp->rnum();
            auto temp = new BoolLiteral(l);
            std::clog<<"isFoldable passed: "<<l<<std::endl;
            return temp;
        }
        return temp;
    }
    //\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//
    //Arithmetic
    //\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//
    Expr* MakeAdd(Expr* a, Expr* b){    
        std::clog<<"MakeAdd: "<< a->isConst<<":"<< b->isConst <<std::endl;
        auto temp = new AddExpr(a,b);
        if(temp->isFoldable()){
            int l = temp->lnum()+temp->rnum();
            auto temp = new IntLiteral(l);
            std::clog<<"isFoldable passed: "<<l<<std::endl;
            return temp;
        }
        std::clog<<"Non zipped add: "<<!(temp->isConst)<<std::endl;
        return temp;
    }
    Expr* MakeSub(Expr* a, Expr* b){
        std::clog<<"MakeSub"<<std::endl;
        auto temp = new SubExpr(a,b);
        if(temp->isFoldable()){
            int l = temp->lnum()-temp->rnum();
            auto temp = new IntLiteral(l);
            std::clog<<"isFoldable passed: "<<l<<std::endl;
            return temp;
        }
        std::clog<<"Non zipped sub: "<<!(temp->isConst)<<std::endl;
        return temp;
    }
    Expr* MakeMult(Expr* a, Expr* b){
        std::clog<<"MakeMult"<<std::endl;
        auto temp = new MultExpr(a,b);
        if(temp->isFoldable()){
            int l = temp->lnum()*temp->rnum();
            auto temp = new IntLiteral(l);
            std::clog<<"isFoldable passed: "<<l<<std::endl;
            return temp;
        }
        std::clog<<"Non zipped mult: "<<!(temp->isConst)<<std::endl;
        return temp;
    }
    Expr* MakeNegative(Expr* a){
        std::clog<<"MakeNegative"<<std::endl;
        auto n = new IntLiteral(-1);
        auto temp = new MultExpr(a,n);
        if(temp->isFoldable()){
            int l = temp->lnum()*temp->rnum();
            auto temp = new IntLiteral(l);
            std::clog<<"isFoldable passed: "<<l<<std::endl;
            return temp;
        }
        std::clog<<"Temp: "<<temp->isConst<<std::endl;
        return temp;
    }
    Expr* MakeDiv(Expr* a, Expr* b){
        std::clog<<"MakeDiv"<<std::endl;
        auto temp = new DivExpr(a,b);
        if(temp->isFoldable()){
            int l = temp->lnum()/temp->rnum();
            auto temp = new IntLiteral(l);
            std::clog<<"isFoldable passed: "<<l<<std::endl;
            return temp;
        }
        std::clog<<"Temp: "<<temp->isConst<<std::endl;
        return temp;
    }
    Expr* MakeMod(Expr* a, Expr* b){
        std::clog<<"MakeMod"<<std::endl;
        auto temp = new ModExpr(a,b);
        if(temp->isFoldable()){
            int l = temp->lnum()%temp->rnum();
            auto temp = new IntLiteral(l);
            std::clog<<"isFoldable passed: "<<l<<std::endl;
            return temp;
        }
        std::clog<<"Temp: "<<temp->isConst<<std::endl;
        return temp;
    }

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//
// literals
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//


    Expr* MakeInt (int num){  
        std::clog<<"Number made: "<<num<<std::endl;
        auto temp = new IntLiteral(num);
        temp->isConst=true;
        return temp;
    }    
    Expr* MakeStr (char* s){
        std::clog<<"MakeStr:"<<s<<std::endl;
        std::string tempStr = s;
        if(tempStr.size()<=3){
            return new CharLiteral(tempStr[1]);
        // }else if(tempStr.size()<=4&&tempStr[1]=='\\'){
        //     return new CharLiteral(tempStr[1]+tempStr[2]);
        }else{
            std::clog<<"#String made: "<<s<<std::endl;
            auto temp = new StrLiteral(s);
            temp->save();
            return temp;
        }
    }


//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//
// Make Statements
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//

    Statement* MakeWrite(Statement* s, Expr* e){
        std::clog<<"MakeWrite: "<<e<<std::endl;
        try{std::clog<<" Type: "<<e<<std::endl;}
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        // auto ref_exp = (ArrayRefExpr*)(e);
        // std::clog<<" Temp pointer: "<<ref_exp->ref_type<<"\n";
        return new WriteStm(s, e);
    }
    Statement* MakeRead(Statement* Lvals){
        auto temp = (LValList*)(Lvals);
        std::clog<<"MakeRead: "<<std::endl;    
        return new ReadStm(Lvals);
    }
    Statement* MakeVarDecl(Statement* Block, Statement* IDlist, AbsType* t){
        BlockStm *mainBlock = (BlockStm*)(Block);
        VarDeclStm *varDecl = new VarDeclStm(IDlist,t);
        return new BlockStm(mainBlock, varDecl);
    }


    //LValues
    Statement* MakeLvalList(Statement* LvalList, Expr* val){
        auto Lval = (LValueExpr*)(val);
        auto List = (LValList*)(LvalList);
        return new LValList(List, Lval);
    }
    Statement* MakeIDList(Statement* idlist, char* id){
        return new IDlist(idlist, id);
    }
    Expr* MakeRecordMember(Expr* LValue, char* member){
        // std::clog<<"MakeMember called\n";
        // if(LValue->type()=="ID"){
        //     auto ID_expr = (IDexpresion*)(LValue);
        //     auto pointedExpr = symbol_table.lookupConst(ID_expr->ID);
        //     std::clog<<"Rec_member: ID_expr made: "<<ID_expr->ID<<" of type " <<pointedExpr->type()<<std::endl;
        //     if(pointedExpr->type()=="record"){
        //         auto rec_expr = (RecordExpr*)(pointedExpr);
        //         std::clog<<"ID Translated to record of len(elements):"<<rec_expr->elements.size()<<std::endl;
        //         auto newRecord = rec_expr->deepCopy();
        //         newRecord->insertRef(member);
        //         return newRecord;
        //     }else{
        //         std::clog<<"Translated ID expr was not record, was: "<<pointedExpr->type()<<std::endl;
        //     }
        //     return nullptr;
        if(LValue->type()=="array"){
            auto arr_expr = (ArrayExpr*)(LValue);
            std::clog<<"Array of ref len "<<arr_expr->references.size()<<" inherited"<<std::endl;
            arr_expr->insertRef( new StrLiteral(member));
            std::clog<<" ref len updated to "<<arr_expr->references.size()<<std::endl;
            return arr_expr;
        }else if(LValue->type()=="record"){
            auto rec_expr = (RecordExpr*)(LValue);
            std::clog<<"Record of len(ref):"<<rec_expr->references.size()<<" inherited"<<std::endl;
            rec_expr->insertRef( new StrLiteral(member));
            std::clog<<" ref len updated to "<<rec_expr->references.size()<<std::endl;
            return rec_expr;
        }else{
            std::cerr<<"Error: Type "<<LValue->type()<<" Passed to makeRecordmember"<<std::endl;
        }
        // auto ID_expr = (IDexpresion*)(e);
        // auto pointedExpr = symbol_table.lookupConst(ID_expr->ID);
        // std::cerr<<"Rec_member: ID_expr made: "<<ID_expr->ID<<" of type " <<pointedExpr->type()<<std::endl;
        
        // if(pointedExpr->type()=="record"){
        //     auto rec_expr = (RecordExpr*)(pointedExpr);
        //     std::cerr<<"ID Translated it Record of size "<<rec_expr->elements.size()<<std::endl;
        //     auto found = rec_expr->elements.find(member);
        //     if(found!=rec_expr->elements.end()){
        //         std::cerr<<"Member successfully found\n";
        //         return new IDexpresion(ID_expr->ID+"."+std::string(member));
        //     }else{
        //         std::cerr<<"Warring! Member not found\n";
        //     }
        // }else if(pointedExpr->{
        //     std::cerr<<"Translated ID expr was not record, was: "<<pointedExpr->type()<<std::endl;
        // }
        // // symbol_table.storeConst(id,idExp);
        // return nullptr;
    }
    Expr* MakeArrayReference(Expr* Lvalue, Expr* reference){
        std::clog<<"MakeReference called\n";
        // if(Lvalue->type()=="ID"){
        //     auto ID_expr = (IDexpresion*)(Lvalue);
        //     auto pointedExpr = symbol_table.lookupConst(ID_expr->ID);
        //     std::clog<<"Arr_Ref: ID_expr made: "<<ID_expr->ID<<" of type " <<pointedExpr->type()<<std::endl;
            
        //     if(pointedExpr->type()=="array"){
        //         auto arr_expr = (ArrayExpr*)(pointedExpr);
        //         std::clog<<"ID Translated to array of len "<<arr_expr->elements.size()<<std::endl;
        //         auto newArray = arr_expr->deepCopy();
        //         newArray->insertRef(reference);
        //         return newArray;
        //     }else{
        //         std::clog<<"Translated ID expr was not array, was: "<<pointedExpr->type()<<std::endl;
        //     }
        //     // symbol_table.storeConst(id,idExp);
        //     return nullptr;
        if(Lvalue->type()=="array"){
            auto arr_expr = (ArrayExpr*)(Lvalue);
            std::clog<<"Array of ref len "<<arr_expr->references.size()<<" inherited"<<std::endl;
            arr_expr->insertRef(reference);
            std::clog<<" ref len updated to "<<arr_expr->references.size()<<std::endl;
            return arr_expr;
        }else if(Lvalue->type()=="record"){
            auto rec_expr = (RecordExpr*)(Lvalue);
            std::clog<<"Array of ref len "<<rec_expr->references.size()<<" inherited"<<std::endl;
            rec_expr->insertRef(reference);
            std::clog<<" ref len updated to "<<rec_expr->references.size()<<std::endl;
            return rec_expr;
        }else{
            std::cerr<<"Error: Type "<<Lvalue->type()<<" Passed to makeArrayReference"<<std::endl;
        }
    }
   
    void SaveConst (char* id, Expr* e){
        e->isStatic=true;
        std::clog<<"Const "<<id<<" Saved as "<<e->type()<<std::endl;
        if(e->type()=="ID"){
            auto idExpr = (IDexpresion*)(e);
            auto nextExpr = symbol_table.lookupConst(idExpr->ID);
            std::clog<<"Const translated as "<<nextExpr->type()<<std::endl;
        }
        symbol_table.storeConst(id,e);
    };
    Statement* MakeVarAssignment (Expr* LValue, Expr* e){//LValue
        std::clog<<"MakeVarAssignment\n"<<" LValue:"<<LValue->type()<<e;
        if(e){std::clog<<" expr:"<<e->type();}
        std::clog<<"\n";
        auto l_val = (LValueExpr*)(LValue);
        if(l_val->type()=="ID" && e->isConst){ //Im not smart enough to figure out how you could store a not determined id with an expr
            symbol_table.storeConst(l_val->ID,e);
        }
        return new AssignStm(l_val,e);
    }

    Statement* MakeWhileStm(Expr* condition, Statement* block){
        return new WhileStm(condition, block);
    }

    Expr* MakeID(char* id){
        std::clog<<"MakeID\n";
        auto e = symbol_table.lookupConst(id);
        if(!e){e=symbol_table.backupConst(id);globl_offsets.store(id,4);}
        if(e->isStatic){
            if(e->type()=="int"){
                auto temp = (IntLiteral*)(e);
                std::clog<<"ID_to_const made: "<<id<<" with data: "<<temp->data<<std::endl;
            }else{
                std::clog<<"ID_to_const made: "<<id<<std::endl;
            }
            return e;
        }
        else if(e->type()=="record"){
            std::clog<<"Record_expr made: "<<id<<" of type " <<e->type()<<"\n";
            auto temp = ((RecordExpr*)(e))->deepCopy();
            std::clog<<" of ref len: "<<temp->references.size()<<"\n";
            return temp;
        }else if(e->type()=="array"){
            std::clog<<"Array_expr made: "<<id<<" of type " <<e->type()<<"\n";
            auto temp = ((ArrayExpr*)(e))->deepCopy();
            std::clog<<" of ref len: "<<temp->references.size()<<"\n";
            return temp;
        } else {
            std::clog<<"ID_expr made: "<<id<<" of type " <<e->type()<<"\n";
            auto idExp = new IDexpresion(id);
            return idExp;
        }
    }

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//
// Type Interfacing
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//

    void SaveType(char* id, AbsType* t){
        // std::clog<<"saved: "<<t<<std::endl;
        // std::cout<<"saved type: "<<t->name()<<std::endl;
        symbol_table.storeType(id,t);
        // delete(e);
    }
    AbsType* LoadType(char* id){
        // std::cout<<"Table: "<<symbol_table.lookupType(id)<<std::endl;
        return symbol_table.lookupType(id);
    }
    AbsType* MakeRecord(AbsType* recordList, AbsType* record){
        //note this is making as many record elements as there are ID's in the list
        if(recordList){
            std::clog<<"makeRecord (Summed) of sizes->"<<recordList->size()<<":"<<record->size()<<"\n";
            auto parentRecord = (RecordType*)(recordList);
            auto childRecord = (RecordType*)(record);
            parentRecord->insert(childRecord);
            return parentRecord;
        }else{
            std::clog<<"makeRecord (hollow) of sizes->"<<record->size()<<"\n";
            return record;
        }
    }
    AbsType* MakeRecord(Statement* id_list, AbsType* typ){
        //note this is making as many record elements as there are ID's in the list
        std::clog<<"makeRecord(small) of type:"<<typ->name()<<"\n";
        auto ids = (IDlist*)(id_list);
        // std::clog<<"ID list cast passed\n";
        return new RecordType(ids->IDs,typ);
    }

    AbsType* MakeArray(Expr* lBound, Expr* uBound, AbsType* t){
        //temp to cast these things down to INT or CHAR
        // std::clog<<"MakeArray\n";
        if(lBound->type()!=uBound->type()){
            std::cerr<<"ERROR: Bounds of incompatible types "<<lBound->type()<<":"<<uBound->type()<<std::endl;
            return nullptr;
        }
        if(!lBound->isLiteral()&&lBound->type()!="str"){
            std::cerr<<"ERROR: Lower Bound not literal, of type: "<<lBound->type()<<std::endl;
            return nullptr;
        }
        if(!uBound->isLiteral()&&uBound->type()!="str"){
            std::cerr<<"ERROR: Upper Bound not literal, of type: "<<uBound->type()<<std::endl;
            return nullptr;
        }
        if(lBound->type()=="int"){
            std::clog<<" of type int\n";
            auto lowInt = (IntLiteral*)(lBound);
            auto highInt = (IntLiteral*)(uBound);
            return new ArrayType(lowInt->data,highInt->data,t);
        }
        if(lBound->type()=="char"){
            std::clog<<" of type char\n";
            auto lowInt = (CharLiteral*)(lBound);
            auto highInt = (CharLiteral*)(uBound);
            // if(lowInt->data.size()>1){
            //     std::clog<<"ERROR: string must be one char long:"<<lowInt->data<<std::endl;
            //     return nullptr;
            // }
            // if(highInt->data.size()>1){
            //     std::clog<<"ERROR: string must be one char long:"<<highInt->data<<std::endl;
            //     return nullptr;
            // }
            char l = lowInt->data;
            char h = highInt->data;
            // std::clog<<"passed with bounds"<<l<<":"<<h<<std::endl;
            return new ArrayType(l,h,t);
        }
        std::cerr<<"ERROR: Bounds were not of type int or str: "<<lBound->type()<<":"<<lBound->type()<<std::endl;
        return nullptr;
    }



//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//
// Make Statements
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/\\//
    Expr* MakeOrd (Expr* e){  
        std::clog<<"Ord Expr literal: "<<e->type()<<std::endl;
        return new OrdExpr(e);
        // if(e->isLiteral()){
        //     if(e->type()=="str"){
        //         std::clog<<"literal ord attempted"<<std::endl;
        //         auto temp = (StrLiteral*)(e);
        //         std::clog<<"char made: "<<temp->data<<std::endl;
        //         if(temp->data.size()<4){
        //             int t = temp->data.front();
        //             std::clog<<"Number made: "<<t<<std::endl;
        //             return new IntLiteral(t);
        //         }else{
        //             std::clog<<"String was given, not a char"<<std::endl;
        //             return nullptr;
        //         }
        //     }
        // }else{
        //     std::clog<<"Ord Expr litteral: "<<e->type()<<std::endl;
        //     return new OrdExpr(e);
        // }
    }

    Expr* MakeChr (Expr* e){//will need to make general
        std::clog<<"Chr Expr Literal: "<<e->type();
        return new ChrExpr(e);
    }
    
    Expr* MakePred(Expr* e){
        return new SubExpr(e,new IntLiteral(1));
    }

    Expr* MakeSucc(Expr* e){
        return new AddExpr(e,new IntLiteral(1));
    }
}
#endif