#ifndef LVALUE_H
#define LVALUE_H

#include "expr.h"

class LValue : public Expr{
public:
    LValue(const ClassID& class_id) : Expr(class_id){}
    virtual Expr*& getLValue(Runtime& runtime) const = 0;
};

#endif // LVALUE_H
