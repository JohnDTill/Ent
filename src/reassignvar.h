#ifndef REASSIGNVAR_H
#define REASSIGNVAR_H

#include "stmt.h"

class ReassignVar : public Stmt{
public:
    const std::string name;
    Expr* rhs;

public:
    ReassignVar(const std::string& name, Expr* rhs);
    virtual void exec(Runtime& runtime) override;
    virtual Expr* clone() const override { return new ReassignVar(name, rhs->clone()); }
    virtual void deleteRecursive() override{
        rhs->deleteRecursive();
        delete this;
    }
    virtual std::string toString() const override { return "ReassignVar(" + name + ", " + rhs->toString() + ")"; }
};

#endif // REASSIGNVAR_H
