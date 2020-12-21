#include "return.h"

Return::Return(Expr* e)
    : Stmt(ID_RETURN), e(e){
    e->parent = this;
}

void Return::exec(Runtime& runtime){
    throw ReturnException( e->clone()->evalAndFree(runtime) );
}
