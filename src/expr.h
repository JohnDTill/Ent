#ifndef EXPR_H
#define EXPR_H

#include <string>
#include <list>
#include <vector>
#include "runtime.h"

enum ClassID{
    ID_APPEND_STRINGS,
    ID_ASSIGN_VAR,
    ID_BLOCK,
    ID_PRINT,
    ID_READ_VAR,
    ID_REASSIGN_VAR,
    ID_STRING,
};

class Expr{
public:
    static std::list<Expr*> all_exprs;

public:
    Expr* parent = nullptr; //Assuming a tree structure w/ 1 parent
    const ClassID class_id;

public:
    Expr(const ClassID& class_id) : class_id(class_id){ all_exprs.push_back(this); }
    virtual ~Expr(){ all_exprs.remove(this); }
    virtual Expr* eval(Runtime&) {return nullptr;}
    Expr* evalAndFree(Runtime& runtime){
        if(Expr* e = eval(runtime)){
            delete this;
            return e;
        }else{
            return this;
        }
    }
    virtual Expr* clone() const = 0;

    template<typename T>
    static std::vector<T*> makeClones(const std::vector<T*>& exprs){
        std::vector<T*> clones(exprs.size());
        for(typename std::vector<T*>::size_type i = 0; i < exprs.size(); i++)
            clones[i] = static_cast<T*>(exprs.at(i)->clone());
        return clones;
    }
    virtual void deleteRecursive() = 0;
    virtual std::string toString() const = 0;
};

#endif // EXPR_H
