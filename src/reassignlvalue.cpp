#include "reassignlvalue.h"

#include <lvalue.h>

ReassignLValue::ReassignLValue(LValue* lvalue, Expr* rhs)
    : Stmt(ID_REASSIGN_LVALUE), lvalue(lvalue), rhs(rhs) {
    lvalue->parent = this;
    rhs->parent = this;
}

void ReassignLValue::exec(Runtime& runtime){
    Expr*& target = lvalue->getLValue(runtime);
    target->deleteRecursive();
    target = rhs->clone()->evalAndFree(runtime);
}

Expr* ReassignLValue::clone() const {
    return new ReassignLValue(lvalue->clone<LValue>(), rhs->clone());
}

void ReassignLValue::deleteRecursive(){
    lvalue->deleteRecursive();
    rhs->deleteRecursive();
    delete this;
}

std::string ReassignLValue::toString() const {
    return "ReassignVar(" + lvalue->toString() + ", " + rhs->toString() + ")";
}
