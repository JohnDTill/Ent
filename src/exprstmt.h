#ifndef EXPRSTMT_H
#define EXPRSTMT_H

#include "stmt.h"

class ExprStmt : public Stmt{
public:
    Expr* e;

public:
    ExprStmt(Expr* e);
    virtual void exec(Runtime& runtime) override;
    virtual Expr* clone() const override { return new ExprStmt(e->clone()); }
    virtual void deleteRecursive() override{
        e->deleteRecursive();
        delete this;
    }
    virtual std::string toString() const override { return "ExprStmt(" + e->toString() + ")"; }
};

#endif // EXPRSTMT_H
