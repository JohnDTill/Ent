#include "exprstmt.h"

#include <iostream>

ExprStmt::ExprStmt(Expr* e)
    : Stmt(ID_EXPR_STMT), e(e){
    e->parent = this;
}

void ExprStmt::exec(Runtime& runtime){
    e->clone()->evalAndFree(runtime)->deleteRecursive();
}
