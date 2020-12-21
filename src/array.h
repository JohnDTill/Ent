#ifndef ARRAY_H
#define ARRAY_H

#include "expr.h"

class Array : public Expr{
public:
    std::vector<Expr*> array;

public:
    Array();
    Array(const std::vector<Expr*>& array);
    virtual Expr* clone() const{ return new Array(makeClones(array)); }
    virtual void deleteRecursive(){
        for(Expr* e : array) e->deleteRecursive();
        delete this;
    }
    virtual std::string toString() const{
        if(array.empty()) return "[]";

        std::string str = '[' + array.front()->toString();
        for(std::vector<Expr*>::size_type i = 1; i < array.size(); i++)
            str += ", " + array.at(i)->toString();
        return str + ']';
    }
};

#endif // ARRAY_H
