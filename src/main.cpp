#include <assert.h>
#include <iostream>

#include "ent.h"

int main(){
    Stmt* asgn = new AssignVar(true, "x", new AppendStrings({new String("Hello "), new String("world!")}));
    Stmt* prnt = new Print( new ReadVar("x") );
    Stmt* body = new Block( {asgn, prnt} );
    Expr* f = new Function({}, body);
    Stmt* dec_f = new AssignVar(true, "f",  f);
    Stmt* call_f = new ExprStmt(new Call(new ReadVar("f"), {}));
    Stmt* stmt = new Block({dec_f, call_f});

    Runtime runtime;
    stmt->exec(runtime);
    runtime.removeScope();
    stmt->deleteRecursive();

    assert(Expr::all_exprs.empty());
}
