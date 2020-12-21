#include "array.h"

Array::Array()
    : Expr(ID_ARRAY) {}

Array::Array(const std::vector<Expr*>& array)
    : Expr(ID_ARRAY), array(array){
    for(Expr* e : array) e->parent = this;
}
