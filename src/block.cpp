#include "block.h"

Block::Block(std::vector<Stmt*> stmts)
    : Stmt(ID_BLOCK), stmts(stmts){
    for(Stmt* stmt : stmts) stmt->parent = this;
}

void Block::exec(Runtime& runtime){
    for(Stmt* stmt : stmts) stmt->exec(runtime);
}
