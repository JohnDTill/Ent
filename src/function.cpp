#include "function.h"

Function::Function(const std::vector<std::string>& parameter_names, Stmt* stmt)
    : Expr(ID_FUNCTION), parameter_names(parameter_names), stmt(stmt){
    stmt->parent = this;
}
