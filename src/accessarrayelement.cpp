#include "accessarrayelement.h"

#include "array.h"

AccessArrayElement::AccessArrayElement(LValue* lvalue, std::vector<Expr*>::size_type index)
    : LValue(ID_ACCESS_ARRAY_ELEMENT), lvalue(lvalue), index(index){
    lvalue->parent = this;
}

Expr*& AccessArrayElement::getLValue(Runtime& runtime) const{
    std::vector<Expr*>& array = ent_cast<Array*>(lvalue->getLValue(runtime))->array;
    if(index >= array.size()) throw ArrayOutOfBoundsException();
    return array.at(index);
}
