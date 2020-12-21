#ifndef RETURN_H
#define RETURN_H

#include "stmt.h"

struct ReturnException : public std::exception{
public:
    Expr* e;
    ReturnException(Expr* e)
        : e(e){}
};

class Return : public Stmt{
public:
    Expr* e;

public:
    Return(Expr* e);
    virtual void exec(Runtime& runtime) override;
    virtual Expr* clone() const override { return new Return(e->clone()); }
    virtual void deleteRecursive() override{
        e->deleteRecursive();
        delete this;
    }
    virtual std::string toString() const override { return "Return(" + e->toString() + ")"; }
};

#endif // RETURN_H
