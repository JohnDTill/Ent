#ifndef ACCESSVAR_H
#define ACCESSVAR_H

#include "lvalue.h"
#include <string>

class AccessVar : public LValue{
public:
    const std::string name;

public:
    AccessVar(const std::string& name);
    virtual Expr*& getLValue(Runtime& runtime) const override;
    virtual Expr* clone() const override{ return new AccessVar(name); }
    virtual void deleteRecursive() override { delete this; }
    virtual std::string toString() const override{
        return name;
    }
};

#endif // ACCESSVAR_H
