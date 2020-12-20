#include <assert.h>
#include <iostream>

#include "ent.h"

int main(){
    Stmt* asgn = new AssignVar(true, "x", new AppendStrings({new String("Hello "), new String("world!")}));
    Stmt* prnt = new Print( new ReadVar("x") );
    Stmt* stmt = new Block( {asgn, prnt} );
    Runtime runtime;
    stmt->exec(runtime);
    stmt->deleteRecursive();

    assert(Expr::all_exprs.empty());
}
