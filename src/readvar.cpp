#include "readvar.h"

ReadVar::ReadVar(const std::string& name)
    : Expr(ID_READ_VAR), name(name){}

Expr* ReadVar::eval(Runtime& runtime){
    return runtime.findVar(name).expr->clone()->evalAndFree(runtime);
}
