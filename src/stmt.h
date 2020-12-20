#ifndef STMT_H
#define STMT_H

#include "expr.h"

class Stmt : public Expr{
public:
    Stmt(const ClassID& class_id) : Expr(class_id){}
    virtual void exec(Runtime& runtime) = 0;
};

#endif // STMT_H
