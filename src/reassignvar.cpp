#include "reassignvar.h"

ReassignVar::ReassignVar(const std::string& name, Expr* rhs)
    : Stmt(ID_REASSIGN_VAR), name(name), rhs(rhs){
    rhs->parent = this;
}

void ReassignVar::exec(Runtime& runtime){
    Var& var = runtime.findVar(name);
    if(var.is_const) throw WriteToConstException(name);
    var.expr->deleteRecursive();
    var.expr = rhs->clone()->evalAndFree(runtime);
}
