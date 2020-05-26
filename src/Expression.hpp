#pragma once
#include <string>
#include <iostream>
#include "StrTable.hpp"
#include "Types.hpp"
#include "RegisterPool.hpp"

struct Expr{
    Expr() = default;
    bool isConst = false; //used for constant folding
    bool isLval = false;
    bool isStatic = false; //used for the const var declaration
    virtual std::string emit() = 0;
    virtual bool isLiteral() {return false;} //used to determine how it is emitted
    virtual std::string type() = 0;
};

struct BlankExpr : Expr{
    std::string _type_="blank";
    BlankExpr(){}
    BlankExpr(std::string t){_type_=t;isConst = false;}
    std::string emit(){
        std::cerr<<"Warrning! PlaceHold Expr emit was called!!!";
        return "NO!!! Just NO!!!";
    }
    bool isLiteral() {return false;}
    std::string type(){
        return _type_;
    }
};

struct IntLiteral : Expr{
    int data = 0;
    IntLiteral(){data = 0;}
    IntLiteral(int d){isConst=true; data = d;}
    bool isLiteral(){return true;}
    std::string emit(){
        auto return_reg = reg_pool.popReg();
        std::cout<<".text # INT Literal Emit"<<std::endl;
        std::cout<<"li "<<return_reg<<", "<<data<<std::endl;
        return return_reg;
    }
    std::string type(){
        return "int";
    }
};

struct BoolLiteral : Expr{
    bool data = false;
    BoolLiteral(){data = false;}
    BoolLiteral(bool d){isConst=true;data = d;}
    bool isLiteral(){return true;}
    std::string emit(){
        auto return_reg = reg_pool.popReg();
        std::cout<<".text # Bool Literal Emit:"<<data<<std::endl;
        std::cout<<"li "<<return_reg<<", "<<data<<std::endl;
        return return_reg;
    }
    std::string type(){
        return "bool";
    }
};

struct CharLiteral : Expr{
    char data;
    CharLiteral(){}
    CharLiteral(char d){isConst=true; data = d;}
    CharLiteral(char* d){
        std::string str = d;
        if(str.length()>1){
            std::cerr<<"Warning! non len(str)>1 passed to charliteral\n";
            data = '!';
        }else{
            data = str[0];
        }
    }
    bool isLiteral(){return true;}
    std::string emit(){
        auto return_reg = reg_pool.popReg();
        std::cout<<".text #Char Literal Emit:"<<data<<std::endl;
        std::cout<<"li "<<return_reg<<", "<<std::to_string((int)data)<<std::endl;
        return return_reg;
    }
    std::string type(){
        return "char";
    }
};

struct StrLiteral : Expr{
    std::string data;
    StrLiteral():Expr(){
        std::cerr<<"is anyone there?"<<std::endl;
        isConst = true;
    }
    StrLiteral(char* d){
        std::clog<<"STRliteral constructor called: "<<data<<std::endl;
        isConst=true;
        std::string temp = d;
        if(d[0] == '\''){
            std::string t;
            for(int i = 1; i<temp.size()-1; ++i){t+=temp[i];}
            std::clog<<temp.size()<<"squote: "<<t<<std::endl;
            data = '"'+t+'"';
        }else{
            data = d;
        }
    }
    void save(){
        str_table.storeStr(data);
    }
    StrLiteral(char d){ //override for MakeChar
        std::string t;
        t.push_back(d);
        data = '"'+t+'"';
        std::clog<<"STRliteral (char) constructor called: "<<t<<":"<<data<<std::endl;
        str_table.storeStr(data);
    }
    std::string getData(){
        std::string temp;
        if(data[0] == '\"' || data[0] == '\''){
            for(int i = 1; i<data.size()-1; ++i){temp+=data[i];}
        }else{
            temp = data;
        }
        return temp;
    }
    std::string emit(){
        std::string label;
        if(str_table.ifStoredStr(data)){
            std::cout<<"#string already made: "<<data<<std::endl;
            label = str_table.lookupStr(data);
        }else{
            label = str_table.lookupStr(data);
            std::cout<< ".data"<<" #STR Assinment"<<std::endl;
            std::cout<<label<<":"<<" .asciiz "<<data<<std::endl;
        }
        std::string valueReg = reg_pool.popReg();
        std::cout<<".text "<<"#STR assignment" << std::endl;
        std::cout<<"la "<<valueReg<<", "<<label<<std::endl;
        return valueReg;
    }
    std::string type(){
        return "str";
    }
};

struct LValueExpr : Expr{
    std::string ID;
    LValueExpr():Expr(){isLval=true;}
    LValueExpr(std::string id):Expr(){ID = id;isLval=true;}
    std::string type() {return "LValuse";}
    std::string emit(){
        std::cerr<<"Warning! General LValueExpr was emitted!\n";
    }
};
struct IDexpresion : LValueExpr{
    IDexpresion():LValueExpr(){}
    IDexpresion(std::string id):LValueExpr(id){}
    std::string type(){return "ID";}
    std::string emit(){
        int location = globl_offsets.lookup(ID);
        std::cout<<"#ID moved to temp register"<<std::endl;
        std::string returnReg = reg_pool.popReg();
        std::cout<<"la "<<returnReg<<", "<<location<<"($gp)"<<std::endl;
        return returnReg;
    }
};
struct RecordExpr : LValueExpr{//Need to translate to an ID, function call, or member reference
    RecordType* typ;
    AbsType* emit_type;
    std::vector<std::pair<std::string, Expr*>> elements;
    std::vector<Expr*> references;
    RecordExpr():LValueExpr(){}
    RecordExpr(std::string id, AbsType* t):LValueExpr(id){
        if(t->name()!="record"){
            std::cerr<<"Warning! Type: "<<t->name()<<" passed to recordExpr constructor\n";
        }else{
            auto temp = (RecordType*)(t);
            typ = temp;
            emit_type=temp;
        }
    }
    void insert(std::string id, Expr* e){
        elements.push_back(std::pair<std::string, Expr*>(id,e));
    }
    void insertRef(Expr* e){
        references.push_back(e);
    }
    RecordExpr* deepCopy(){
        auto newRecord = new RecordExpr(ID, typ);
        for (auto &&ele : elements){
            newRecord->elements.push_back(ele);
        }
        return newRecord;
    }
    std::string type(){return "record";}
    std::string rootEmit(){
        int location = globl_offsets.lookup(ID);
        std::cout<<"#Record root offset moved to temp register"<<std::endl;
        std::string returnReg = reg_pool.popReg();
        std::cout<<"la "<<returnReg<<", "<<location<<"($gp)"<<std::endl;
        return returnReg;
    }
    std::string emit(){
        emit_type=typ;
        int refcounter=0;
        auto parentOffset = rootEmit();
        for (auto &&ref : references){
            if(emit_type->name()=="record"){
                auto ref_type = (RecordType*)(emit_type);
                std::cout<<" #Record member emit\n";
                if(ref->type()!="str"){
                    std::cout<<"Error member reference to record was not a Char\n Was insted of type:"<<ref->type()<<'\n';
                    return "$$";
                }
                auto strExpr = (StrLiteral*)(ref);
                int internalOffset = ref_type->refOffset(strExpr->getData());
                std::cout<<" # of member "<<strExpr->getData()<<'\n';
                std::cout<<"addi "<<parentOffset<<","<<parentOffset<<","<<internalOffset<<std::endl;
                emit_type = ref_type->find(strExpr->getData());
            ////////////////////////////
            }else if(emit_type->name()=="array"){
                std::cout<<" #Array member emit\n";
                auto arr_type = (ArrayType*)(emit_type);
                int internalOffset = arr_type->indexOffset;
                auto ref_type = arr_type->typ;
                int unitSize=ref_type->size();
                auto unitSizeReg = reg_pool.popReg();

                std::string ref_reg = ref->emit(); //this is load the potential lvals as words
                if(ref->isLval || ref->type()=="str"||ref->type()=="bool"){
                    std::cout<<"lw "<<ref_reg<<",("<<ref_reg<<")\n";
                }
                //logic to find the reference
                std::cout<<"li "<<unitSizeReg<<","<<unitSize<<std::endl;
                std::cout<<"subi "<<ref_reg<<","<<ref_reg<<","<<internalOffset<<"\n";
                std::cout<<"mult "<<ref_reg<<","<<unitSizeReg<<std::endl;
                std::cout<<"mflo "<<unitSizeReg<<std::endl;
                std::cout<<"add "<<parentOffset<<","<<unitSizeReg<<","<<parentOffset<<std::endl;
                reg_pool.pushReg(ref_reg);
                reg_pool.pushReg(unitSizeReg);
                emit_type = ref_type;
            ////////////////////////////
            }else{
                std::cout<<" # recursive lookup terminated at "<<refcounter<<" of type:"<<emit_type->name()<<"\n";
                break;
            }
            refcounter++;
            std::cout<<" #recurse ref:"<<refcounter<<" of type:"<<emit_type->name()<<"\n";
        }
        return parentOffset;
    }
};
struct ArrayExpr : LValueExpr{
    bool isLval = true;
    std::vector<std::pair<std::string, Expr*>> elements;
    std::vector<Expr*> references;
    ArrayType* typ;
    AbsType* emit_type;
    bool isConst = false; //used for constant folding
    ArrayExpr() : LValueExpr(){}
    ArrayExpr(std::string id, AbsType* t) : LValueExpr(id){
        if(t->name()!="array"){
            std::cerr<<"Warning! Type: "<<t->name()<<" passed to arrExpr constructor\n";
        }else{
            auto temp = (ArrayType*)(t);
            typ = temp;
            emit_type=temp;
        }
    };
    ArrayExpr* deepCopy(){
        auto newArray = new ArrayExpr(ID, typ);
        for (auto &&ele : elements){
            newArray->elements.push_back(ele);
        }
        return newArray;
    }
    void insert(std::string id, Expr* e){
        elements.push_back(std::pair<std::string, Expr*>(id,e));
    }
    std::string type(){
        return "array";
    }
    void insertRef(Expr* ref){
        references.push_back(ref);
    }
    std::string rootEmit(){
        int location = globl_offsets.lookup(ID);
        std::cout<<"#Array root offset moved to temp register"<<std::endl;
        std::string returnReg = reg_pool.popReg();
        std::cout<<"la "<<returnReg<<", "<<location<<"($gp)"<<std::endl;
        return returnReg;
    }

    std::string emit(){
        emit_type=typ;
        int refcounter=0;
        auto parentOffset = rootEmit();
        for (auto &&ref : references){
            if(emit_type->name()=="record"){
                auto ref_type = (RecordType*)(emit_type);
                std::cout<<" #Record member emit"<<std::endl;
                if(ref->type()!="str"){
                    std::cout<<"Error member reference to record was not a string\n Was insted of type:"<<ref->type()<<'\n';
                    return "$$";
                }
                auto strExpr = (StrLiteral*)(ref);
                int internalOffset = ref_type->refOffset(strExpr->getData());
                std::cout<<" # of member "<<strExpr->getData()<<'\n';
                std::cout<<"addi "<<parentOffset<<","<<parentOffset<<","<<internalOffset<<std::endl;
                emit_type = ref_type->find(strExpr->getData());
            ////////////////////////////
            }else if(emit_type->name()=="array"){
                std::cout<<" #Array member emit"<<std::endl;
                auto arr_type = (ArrayType*)(emit_type);
                int internalOffset = arr_type->indexOffset;
                auto ref_type = arr_type->typ;                
                int unitSize=ref_type->size();
                auto unitSizeReg = reg_pool.popReg();
                std::string ref_reg = ref->emit(); //this is load the potential lvals as words
                if(ref->isLval || ref->type()=="str"||ref->type()=="bool"){
                    std::cout<<"lw "<<ref_reg<<",("<<ref_reg<<")"<<std::endl;
                }

                //logic to find the reference
                std::cout<<"li "<<unitSizeReg<<","<<unitSize<<std::endl;
                std::cout<<"subi "<<ref_reg<<","<<ref_reg<<","<<internalOffset<<"\n";
                std::cout<<"mult "<<ref_reg<<","<<unitSizeReg<<std::endl;
                std::cout<<"mflo "<<unitSizeReg<<std::endl;
                std::cout<<"add "<<parentOffset<<","<<unitSizeReg<<","<<parentOffset<<std::endl;
                reg_pool.pushReg(ref_reg);
                reg_pool.pushReg(unitSizeReg);
                emit_type = ref_type;
            ////////////////////////////
            }else{
                std::cout<<" # recursive lookup terminated at "<<refcounter<<" of type:"<<emit_type->name()<<"\n";
                break;
            }
            refcounter++;
            std::cout<<" #recurse ref:"<<refcounter<<" of type:"<<emit_type->name()<<"\n";
        }
        return parentOffset;
    }

};

struct OrdExpr : Expr{
    Expr* param = nullptr;
    OrdExpr():Expr(){}
    OrdExpr(Expr* e):Expr(){
        param = e;
    }
    std::string type(){return "ord";}
    std::string emit(){
        if(param->type()=="char"){
            auto e = (CharLiteral*)(param);
            return e->emit();
        }
        std::cout<<"#Ord of nonliteral type: "<<param->type()<<std::endl;
        std::string returnReg = param->emit();
        std::cout<<"lw "<<returnReg<<", ("<<returnReg<<")\n";
        return returnReg;
    }
};

struct ChrExpr : Expr{
    Expr* param = nullptr;
    ChrExpr():Expr(){}
    ChrExpr(Expr* e):Expr(){
        param = e;
    }
    std::string type(){return "chr";}
    std::string emit(){
        if(param->type()=="int"){
            auto e = (IntLiteral*)(param);
            std::string reg = reg_pool.popReg();
            std::cout<<".text # chrExpr()"<<"\n";
            return param->emit();
        }
        std::cout<<"#Chr of nonliteral type: "<<param->type()<<std::endl;
        std::string returnReg = param->emit();
        std::cout<<"lw "<<returnReg<<", ("<<returnReg<<")\n";
        return returnReg;
    }
};

struct BinaryExpr : Expr { //This is still a virtual class, no default constructer
    Expr* left = nullptr;
    Expr* right = nullptr;
    BinaryExpr (Expr* a, Expr* b) {
        left = a;
        right = b;
        isFoldable();
    }
    bool isLiteral(){return false;}
    std::string emit (){
        return "Generic BinaryExpr emited, warring";
    }
    virtual std::string type(){
        return "BinaryExpr";
    }
    bool isFoldable(){
        if(left&&right){
            if(left->isConst && right->isConst){
                return true;
            }
        }
        return false;
    }
    int lnum(){
        if (left){
            if(left->isConst){
                IntLiteral* l=(IntLiteral*)(left);
                return l->data;
            }
        }
        std::cerr<<"WARNING: NON CONSTANT DATA MINED LEFT!"<<std::endl;
        return 0;
    }    
    int rnum(){
        if(right){
            if (right->isConst){
                IntLiteral* r=(IntLiteral*)(right);
                return r->data;
            }
        }
        std::cerr<<"WARNING: NON CONSTANT DATA MINED RIGHT!"<<std::endl;
        return 0;
    }
};

struct BoolExpr : BinaryExpr { //This is still a virtual class, no default constructer
    BoolExpr (Expr* a, Expr* b) : BinaryExpr(a,b) {}
    bool lnum(){
        if(left){
            if (left->isConst){
                IntLiteral* l=(IntLiteral*)(left);
                if(l->data == 0){return false;}
                if(l->data == 1){return true;}
                else{
                    std::cerr<<"Invalid Boolean logic"<<std::endl;
                }
            }
        }
        std::cerr<<"WARNING: NON CONSTANT DATA MINED!"<<std::endl;
        return false;
    }
    int rnum(){
        if(right){
            if (right->isConst){
                IntLiteral* r=(IntLiteral*)(right);
                if(r->data == 0){return false;}
                if(r->data == 1){return true;}
                else{
                    std::cerr<<"Invalid Boolean logic"<<std::endl;
                }
            }
        }
        std::cerr<<"WARNING: NON CONSTANT DATA MINED!"<<std::endl;
        return 0;
    }
};

struct AddExpr : BinaryExpr { //check constant folding some how
    AddExpr() = default;
    AddExpr(Expr* a, Expr*b ):BinaryExpr(a,b){}

    std::string emit (){
        // std::string returnReg = reg_pool.popReg();
        // the optimization can be made to save the result in on of the registers used of left and right
        std::string leftReg=left->emit();
        std::string rightReg = right->emit();
        std::cout<<".text # AddExpr emit"<<std::endl;
        if(left->isLval){//if not lval, 
            std::cout<<"lw "<<leftReg<<" ("<<leftReg<<")\n";
        }
        if(right->isLval){
            std::cout<<"lw "<<rightReg<<" ("<<rightReg<<")\n";
        }
        std::cout<<"add "<<leftReg<<","<<leftReg<<","<<rightReg<<std::endl;
        reg_pool.pushReg(rightReg);
        return leftReg;
    }
    std::string type(){
        return "+";
    }
};

struct SubExpr : BinaryExpr { //check constant folding some how
    SubExpr() = default;
    SubExpr(Expr* a, Expr*b ):BinaryExpr(a,b){}
    std::string emit (){
        // std::string returnReg = reg_pool.popReg();
        // the optimization can be made to save the result in on of the registers used of left and right
        std::string leftReg=left->emit();
        std::string rightReg = right->emit();
        std::cout<<".text # SUB Expr emit"<<std::endl;
        if(left->isLval){//if not lval, 
            std::cout<<"lw "<<leftReg<<" ("<<leftReg<<")\n";
        }
        if(right->isLval){
            std::cout<<"lw "<<rightReg<<" ("<<rightReg<<")\n";
        }
        std::cout<<"sub "<<rightReg<<","<<leftReg<<","<<rightReg<<std::endl;
        reg_pool.pushReg(leftReg);
        return rightReg;
        //return answer register.
    }
    std::string type(){
        return "-";
    }
};

struct MultExpr : BinaryExpr { //check constant folding some how
    MultExpr() = default;
    MultExpr(Expr* a, Expr*b ):BinaryExpr(a,b){}
    std::string emit (){
        // std::string returnReg = reg_pool.popReg();
        // the optimization can be made to save the result in on of the registers used of left and right
        std::string leftReg=left->emit();
        std::string rightReg = right->emit();
        std::cout<<".text # MULTI Expr emit"<<std::endl;
        if(left->isLval){//if not lval, 
            std::cout<<"lw "<<leftReg<<" ("<<leftReg<<")\n";
        }
        if(right->isLval){
            std::cout<<"lw "<<rightReg<<" ("<<rightReg<<")\n";
        }
        //emit add mips
        std::cout<<"mult "<<leftReg<<","<<rightReg<<std::endl;
        std::cout<<"mflo "<<rightReg<<std::endl;
        reg_pool.pushReg(leftReg);
        return rightReg;
        //return answer register.
    }
    std::string type(){
        return "*";
    }
};

struct DivExpr : BinaryExpr { //check constant folding some how
    DivExpr() = default;
    DivExpr(Expr* a, Expr*b ):BinaryExpr(a,b){}
    std::string emit (){
        // std::string returnReg = reg_pool.popReg();
        // the optimization can be made to save the result in on of the registers used of left and right
        std::string leftReg=left->emit();
        std::string rightReg = right->emit();
        std::cout<<".text # DIV Expr emit"<<std::endl;
        if(left->isLval){//if not lval, 
            std::cout<<"lw "<<leftReg<<" ("<<leftReg<<")\n";
        }
        if(right->isLval){
            std::cout<<"lw "<<rightReg<<" ("<<rightReg<<")\n";
        }
        //emit add mips
        std::cout<<"div "<<leftReg<<","<<rightReg<<std::endl;
        std::cout<<"mflo "<<rightReg<<std::endl;
        reg_pool.pushReg(leftReg);
        return rightReg;
        //return answer register.
    }
    std::string type(){
        return "/";
    }
};

struct ModExpr : BinaryExpr { //check constant folding some how
    ModExpr() = default;
    ModExpr(Expr* a, Expr*b ):BinaryExpr(a,b){}
    std::string emit (){
        // std::string returnReg = reg_pool.popReg();
        // the optimization can be made to save the result in on of the registers used of left and right
        std::string leftReg=left->emit();
        std::string rightReg = right->emit();
        std::cout<<".text # MOD Expr emit"<<std::endl;
        if(left->isLval){//if not lval, 
            std::cout<<"lw "<<leftReg<<" ("<<leftReg<<")\n";
        }
        if(right->isLval){
            std::cout<<"lw "<<rightReg<<" ("<<rightReg<<")\n";
        }
        std::cout<<"div "<<leftReg<<","<<rightReg<<std::endl;
        std::cout<<"mfhi "<<rightReg<<std::endl;
        reg_pool.pushReg(leftReg);
        return rightReg;
        //return answer register.
    }
    std::string type(){
        return "%";
    }
};

struct OrExpr : BoolExpr{
    OrExpr() = default;
    OrExpr(Expr* a, Expr* b):BoolExpr(a,b){}
    std::string emit (){
        // std::string returnReg = reg_pool.popReg();
        // the optimization can be made to save the result in on of the registers used of left and right
        std::string leftReg=left->emit();
        std::string rightReg = right->emit();
        std::cout<<".text # OR Expr emit"<<std::endl;
        if(left->isLval){//if not lval, 
            std::cout<<"lw "<<leftReg<<" ("<<leftReg<<")\n";
        }
        if(right->isLval){
            std::cout<<"lw "<<rightReg<<" ("<<rightReg<<")\n";
        }
        //emit add mips
        std::cout<<"or "<<leftReg<<","<<leftReg<<","<<rightReg<<std::endl;
        reg_pool.pushReg(rightReg);
        return leftReg;
        //return answer register.
    }
    std::string type(){
        return "or";
    }
};

struct AndExpr : BoolExpr{
    AndExpr() = default;
    AndExpr(Expr* a, Expr* b):BoolExpr(a,b){}
    std::string emit (){
        // std::string returnReg = reg_pool.popReg();
        // the optimization can be made to save the result in on of the registers used of left and right
        std::string leftReg=left->emit();
        std::string rightReg = right->emit();
        std::cout<<".text # AND Expr emit"<<std::endl;
        if(left->isLval){//if not lval, 
            std::cout<<"lw "<<leftReg<<" ("<<leftReg<<")\n";
        }
        if(right->isLval){
            std::cout<<"lw "<<rightReg<<" ("<<rightReg<<")\n";
        }
        std::cout<<"and "<<leftReg<<","<<leftReg<<","<<rightReg<<std::endl;
        reg_pool.pushReg(rightReg);
        return leftReg;
    }
    std::string type(){
        return "and";
    }
};

struct NotExpr : BoolExpr{
    NotExpr() = default;
    NotExpr(Expr* a):BoolExpr(a, nullptr){}
    bool isFoldable(){
        if(left){
            if(left->isLiteral()){
                return true;
            }
        }
        return false;
    }
    std::string emit (){
        // std::string returnReg = reg_pool.popReg();
        // the optimization can be made to save the result in on of the registers used of left and right
        std::string leftReg=left->emit();
        std::cout<<".text # NOT Expr emit"<<std::endl;
        if(left->isLval){//if not lval, 
            std::cout<<"lw "<<leftReg<<" ("<<leftReg<<")\n";
        }
        //emit add mips
        std::cout<<"not "<<leftReg<<","<<leftReg<<std::endl;
        return leftReg;
        //return answer register.
    }
    std::string type(){
        return "!";
    }
};

struct EqualsExpr : BinaryExpr{
    EqualsExpr() = default;
    EqualsExpr(Expr* a, Expr* b):BinaryExpr(a,b){}
    std::string emit (){
        // std::string returnReg = reg_pool.popReg();
        // the optimization can be made to save the result in on of the registers used of left and right
        std::string leftReg=left->emit();
        std::string rightReg = right->emit();
        std::cout<<".text # EQUALS Expr emit"<<std::endl;
        if(left->isLval){//if not lval, 
            std::cout<<"lw "<<leftReg<<" ("<<leftReg<<")\n";
        }
        if(right->isLval){
            std::cout<<"lw "<<rightReg<<" ("<<rightReg<<")\n";
        }
        std::cout<<"seq "<<leftReg<<","<<leftReg<<","<<rightReg<<std::endl;
        reg_pool.pushReg(rightReg);
        return leftReg;
        //return answer register.
    }
    std::string type(){
        return "EQ";
    }
};

struct NEQExpr : BinaryExpr{
    NEQExpr() = default;
    NEQExpr(Expr* a, Expr* b):BinaryExpr(a,b){}
    std::string emit (){
        // std::string returnReg = reg_pool.popReg();
        // the optimization can be made to save the result in on of the registers used of left and right
        std::string leftReg=left->emit();
        std::string rightReg = right->emit();
        std::cout<<".text # NOTEQUAL Expr emit"<<std::endl;
        if(left->isLval){//if not lval, 
            std::cout<<"lw "<<leftReg<<" ("<<leftReg<<")\n";
        }
        if(right->isLval){
            std::cout<<"lw "<<rightReg<<" ("<<rightReg<<")\n";
        }
        std::cout<<"sne "<<leftReg<<","<<leftReg<<","<<rightReg<<std::endl;
        reg_pool.pushReg(rightReg);
        return leftReg;
        //return answer register.
    }
    std::string type(){
        return "NEQ";
    }
};

struct LTExpr : BinaryExpr{
    LTExpr() = default;
    LTExpr(Expr* a, Expr* b):BinaryExpr(a,b){}
    std::string emit (){
        // std::string returnReg = reg_pool.popReg();
        // the optimization can be made to save the result in on of the registers used of left and right
        std::string leftReg=left->emit();
        std::string rightReg = right->emit();
        std::cout<<".text # LessThan Expr emit"<<std::endl;
        if(left->isLval){//if not lval, 
            std::cout<<"lw "<<leftReg<<" ("<<leftReg<<")\n";
        }
        if(right->isLval){
            std::cout<<"lw "<<rightReg<<" ("<<rightReg<<")\n";
        }
        std::cout<<"slt "<<leftReg<<","<<leftReg<<","<<rightReg<<std::endl;
        reg_pool.pushReg(rightReg);
        return leftReg;
        //return answer register.
    }
    std::string type(){
        return "LT";
    }
};

struct GTExpr : BinaryExpr{
    GTExpr() = default;
    GTExpr(Expr* a, Expr* b):BinaryExpr(a,b){}
    std::string emit (){
        // std::string returnReg = reg_pool.popReg();
        // the optimization can be made to save the result in on of the registers used of left and right
        std::string leftReg=left->emit();
        std::string rightReg = right->emit();
        std::cout<<".text # GraterThan Expr emit"<<std::endl;
        if(left->isLval){//if not lval, 
            std::cout<<"lw "<<leftReg<<" ("<<leftReg<<")\n";
        }
        if(right->isLval){
            std::cout<<"lw "<<rightReg<<" ("<<rightReg<<")\n";
        }
        std::cout<<"sgt "<<leftReg<<","<<leftReg<<","<<rightReg<<std::endl;
        reg_pool.pushReg(rightReg);
        return leftReg;
        //return answer register.
    }
    std::string type(){
        return "GT";
    }
};

struct LTQExpr : BinaryExpr{
    LTQExpr() = default;
    LTQExpr(Expr* a, Expr* b):BinaryExpr(a,b){}
    std::string emit (){
        // std::string returnReg = reg_pool.popReg();
        // the optimization can be made to save the result in on of the registers used of left and right
        std::string leftReg=left->emit();
        std::string rightReg = right->emit();
        std::cout<<".text # LessThenEqual Expr emit"<<std::endl;
        if(left->isLval){//if not lval, 
            std::cout<<"lw "<<leftReg<<" ("<<leftReg<<")\n";
        }
        if(right->isLval){
            std::cout<<"lw "<<rightReg<<" ("<<rightReg<<")\n";
        }
        std::cout<<"sge "<<leftReg<<","<<rightReg<<","<<leftReg<<std::endl;
        reg_pool.pushReg(rightReg);
        return leftReg;
        //return answer register.
    }
    std::string type(){
        return "LTQ";
    }
};

struct GTQExpr : BinaryExpr{
    GTQExpr() = default;
    GTQExpr(Expr* a, Expr* b):BinaryExpr(a,b){}
    std::string emit (){
        // std::string returnReg = reg_pool.popReg();
        // the optimization can be made to save the result in on of the registers used of left and right
        std::string leftReg=left->emit();
        std::string rightReg = right->emit();
        std::cout<<".text # GreaterThenEqual Expr emit"<<std::endl;
        if(left->isLval){//if not lval, 
            std::cout<<"lw "<<leftReg<<" ("<<leftReg<<")\n";
        }
        if(right->isLval){
            std::cout<<"lw "<<rightReg<<" ("<<rightReg<<")\n";
        }
        std::cout<<"sge "<<leftReg<<","<<leftReg<<","<<rightReg<<std::endl;
        reg_pool.pushReg(rightReg);
        return leftReg;
        //return answer register.
    }
    std::string type(){
        return "GTQ";
    }
};