#ifndef READVAR_H
#define READVAR_H

#include "stmt.h"

class ReadVar : public Expr{
public:
    const std::string name;

public:
    ReadVar(const std::string& name);
    virtual Expr* eval(Runtime& runtime) override;
    virtual Expr* clone() const override { return new ReadVar(name); }
    virtual void deleteRecursive() override{ delete this; }
    virtual std::string toString() const override { return "ReadVar(" + name + ")"; }
};

#endif // READVAR_H
