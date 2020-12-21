#include "call.h"

#include "return.h"
#include "void.h"

Call::Call(Expr* fun, const std::vector<Expr*> args)
    : Expr(ID_CALL), fun(fun), args(args){
    fun->parent = this;
    for(Expr* arg : args) arg->parent = this;
}

Expr* Call::eval(Runtime& runtime){
    //Don't clone f since function will return a value
    Function* f = ent_cast<Function*>(fun->evalAndFree(runtime));
    if(f->parameter_names.size() != args.size()) throw ArityException();
    runtime.addScope();
    for(std::vector<Expr*>::size_type i = 0; i < args.size(); i++)
        runtime.assignVar(false, f->parameter_names.at(i), args.at(i)->clone()->evalAndFree(runtime));

    try{
        f->stmt->exec(runtime);
    }catch(const ReturnException& ret){
        f->deleteRecursive();
        runtime.removeScope();
        return ret.e;
    }

    f->deleteRecursive();
    runtime.removeScope();
    return new Void();
}
