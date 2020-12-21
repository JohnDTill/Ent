#include "assignvar.h"

AssignVar::AssignVar(bool is_const, const std::string& name, Expr* rhs)
    : Stmt(ID_ASSIGN_VAR), is_const(is_const), name(name), rhs(rhs){
    rhs->parent = this;
}

void AssignVar::exec(Runtime& runtime){
    runtime.assignVar(is_const, name, rhs->clone()->evalAndFree(runtime));
}

