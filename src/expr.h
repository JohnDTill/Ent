#ifndef EXPR_H
#define EXPR_H

#include <cassert>
#include <string>
#include <list>
#include <vector>
#include "runtime.h"

enum ClassID{
    ID_ACCESS_ARRAY_ELEMENT,
    ID_ACCESS_VAR,
    ID_APPEND_STRINGS,
    ID_ARRAY,
    ID_ASSIGN_VAR,
    ID_BLOCK,
    ID_CALL,
    ID_EXPR_STMT,
    ID_FUNCTION,
    ID_PRINT,
    ID_READ_VAR,
    ID_REASSIGN_LVALUE,
    ID_REASSIGN_VAR,
    ID_RETURN,
    ID_STRING,
    ID_VOID,
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
    T* clone() const{
        Expr* cl = clone();
        assert(dynamic_cast<T*>(cl));
        return static_cast<T*>(cl);
    }

    template<typename T = Expr>
    static std::vector<T*> makeClones(const std::vector<T*>& exprs){
        std::vector<T*> clones(exprs.size());
        for(typename std::vector<T*>::size_type i = 0; i < exprs.size(); i++)
            clones[i] = static_cast<T*>(exprs.at(i)->clone());
        return clones;
    }
    virtual void deleteRecursive() = 0;
    virtual std::string toString() const = 0;
};

template<typename T>
inline T ent_cast(Expr* e){
    T cast = dynamic_cast<T>(e);
    if(!cast) throw TypeException();
    return cast;
}

#endif // EXPR_H
