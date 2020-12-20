#include "print.h"

Print::Print(Expr* e)
    : Stmt(ID_PRINT), e(e){
    e->parent = this;
}

void Print::exec(Runtime& runtime){
    Expr* eval = e->clone()->evalAndFree(runtime);
    runtime.log( eval->toString() );
    eval->deleteRecursive();
}
