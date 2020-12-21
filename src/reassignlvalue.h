#ifndef REASSIGNLVALUE_H
#define REASSIGNLVALUE_H

#include "stmt.h"
class LValue;

class ReassignLValue : public Stmt{
public:
    LValue* lvalue;
    Expr* rhs;

public:
    ReassignLValue(LValue* lvalue, Expr* rhs);
    virtual void exec(Runtime& runtime) override;
    virtual Expr* clone() const override;
    virtual void deleteRecursive() override;
    virtual std::string toString() const override;
};

#endif // REASSIGNLVALUE_H
