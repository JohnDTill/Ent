#include "accessvar.h"

AccessVar::AccessVar(const std::string& name)
    : LValue(ID_ACCESS_VAR), name(name){}

Expr*& AccessVar::getLValue(Runtime& runtime) const{
    return runtime.findVar(name).expr;
}
