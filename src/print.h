#ifndef PRINT_H
#define PRINT_H

#include "stmt.h"

class Print : public Stmt{
public:
    Expr* e;

public:
    Print(Expr* e);
    virtual void exec(Runtime& runtime) override;
    virtual Expr* clone() const override { return new Print(e->clone()); }
    virtual void deleteRecursive() override{
        e->deleteRecursive();
        delete this;
    }
    virtual std::string toString() const override { return "Print(" + e->toString() + ")"; }
};

#endif // PRINT_H
