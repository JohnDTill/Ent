#include <assert.h>
#include <iostream>

#include "ent.h"

void helloWorld(){
    Stmt* asgn = new AssignVar(true, "x", new AppendStrings({new String("Hello "), new String("world!")}));
    Stmt* prnt = new Print( new ReadVar("x") );
    Stmt* body = new Block( {asgn, prnt} );
    Expr* f = new Function({}, body);
    Stmt* dec_f = new AssignVar(true, "f",  f);
    Stmt* call_f = new ExprStmt(new Call(new ReadVar("f"), {}));
    Stmt* stmt = new Block({dec_f, call_f});

    Runtime runtime;
    stmt->exec(runtime);
    stmt->deleteRecursive();
}

void arrayStuff(){
    Expr* array = new Array({new String("Hello"), new String("World"), new String("!")});
    Stmt* write = new AssignVar(false, "X", array);
    Stmt* print = new Print(new ReadVar("X"));
    Stmt* modify = new ReassignLValue(new AccessArrayElement(new AccessVar("X"), 2), new String("?"));
    Stmt* stmt = new Block({write, print, modify, print->clone<Stmt>()});

    Runtime runtime;
    stmt->exec(runtime);
    stmt->deleteRecursive();
}

int main(){
    helloWorld();
    arrayStuff();
}
