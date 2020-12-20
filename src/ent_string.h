#ifndef ENT_STRING_H
#define ENT_STRING_H

#include "expr.h"
#include <string>

class String : public Expr{
public:
    std::string str;

public:
    String(const std::string& str);
    virtual Expr* clone() const{ return new String(str); }
    virtual void deleteRecursive(){
        delete this;
    }
    virtual std::string toString() const{ return '"' + str + '"'; }
};

#endif // ENT_STRING_H
