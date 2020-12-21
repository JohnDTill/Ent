#ifndef CALL_H
#define CALL_H

#include "function.h"

class Call : public Expr{
public:
    Expr* fun;
    std::vector<Expr*> args;

private:
    const std::string delim = " + ";

public:
    Call(Expr* fun, const std::vector<Expr*> args);
    virtual Expr* eval(Runtime& runtime) override;
    virtual Expr* clone() const override{ return new Call(fun->clone(), makeClones<Expr>(args)); }
    virtual void deleteRecursive() override {
        fun->deleteRecursive();
        for(Expr* arg : args) arg->deleteRecursive();
        delete this;
    }
    virtual std::string toString() const override{
        std::string str = fun->toString() + "(";
        if(args.size()){
            str += args.front()->toString();
            for(std::vector<Expr*>::size_type i = 1; i < args.size(); i++)
                str += delim + args.at(i)->toString();
        }
        return str + ')';
    }
};

#endif // CALL_H
