#include "ent_string.h"

String::String(const std::string& str)
    : Expr(ID_STRING), str(str){}
