#ifndef BLOCK_H
#define BLOCK_H

#include "stmt.h"

class Block : public Stmt{
public:
    std::vector<Stmt*> stmts;

public:
    Block(std::vector<Stmt*> stmts);
    virtual void exec(Runtime& runtime) override;
    virtual Expr* clone() const override { return new Block(makeClones<Stmt>(stmts)); }
    virtual void deleteRecursive() override{
        for(Stmt* stmt : stmts) stmt->deleteRecursive();
        delete this;
    }
    virtual std::string toString() const override { return "BLOCK"; }
};

#endif // BLOCK_H
