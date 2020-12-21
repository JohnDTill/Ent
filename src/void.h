#ifndef VOID_H
#define VOID_H

#include "expr.h"

class Void : public Expr{
public:
    Void();
    virtual Expr* clone() const{ return new Void(); }
    virtual void deleteRecursive(){ delete this; }
    virtual std::string toString() const{ return "Void"; }
};

#endif // VOID_H
