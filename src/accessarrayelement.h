#ifndef ACCESSARRAYELEMENT_H
#define ACCESSARRAYELEMENT_H

#include "lvalue.h"

class AccessArrayElement : public LValue{
public:
    LValue* lvalue;
    std::vector<Expr*>::size_type index;

public:
    AccessArrayElement(LValue* lvalue, std::vector<Expr*>::size_type index);
    virtual Expr*& getLValue(Runtime& runtime) const override;
    virtual Expr* clone() const override{ return new AccessArrayElement(lvalue->clone<LValue>(), index); }
    virtual void deleteRecursive() override {
        lvalue->deleteRecursive();
        delete this;
    }
    virtual std::string toString() const override{
        return lvalue->toString() + '[' + std::to_string(index) + ']';
    }
};

#endif // ACCESSARRAYELEMENT_H
