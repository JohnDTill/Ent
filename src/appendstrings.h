#ifndef APPENDSTRINGS_H
#define APPENDSTRINGS_H

#include "expr.h"

class AppendStrings : public Expr{
public:
    std::vector<Expr*> args;

private:
    const std::string delim = " + ";

public:
    AppendStrings(const std::vector<Expr*> args);
    virtual Expr* eval(Runtime& runtime) override;
    virtual Expr* clone() const override{ return new AppendStrings(makeClones<Expr>(args)); }
    virtual void deleteRecursive() override {
        for(Expr* e : args) e->deleteRecursive();
        delete this;
    }
    virtual std::string toString() const override{
        std::string str = args.front()->toString();
        for(std::vector<Expr*>::size_type i = 1; i < args.size(); i++)
            str += delim + args.at(i)->toString();
        return str;
    }
};

#endif // APPENDSTRINGS_H
