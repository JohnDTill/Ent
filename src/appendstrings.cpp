#include "appendstrings.h"

#include "ent_string.h"
#include <algorithm>

AppendStrings::AppendStrings(const std::vector<Expr*> args)
    : Expr(ID_APPEND_STRINGS), args(args){
    for(Expr* e : args) e->parent = this;
}

Expr* AppendStrings::eval(Runtime& runtime){
    std::vector<Expr*>::size_type i = args.size()-1;
    args[i] = args[i]->evalAndFree(runtime);

    while(i --> 0){
        args[i] = args[i]->evalAndFree(runtime);
        if(args.at(i)->class_id == ID_STRING && args.at(i+1)->class_id == ID_STRING){
            static_cast<String*>(args.at(i))->str += static_cast<String*>(args.at(i+1))->str;
            delete args.at(i+1);
            args[i+1] = nullptr;
        }
    }

    args.erase(std::remove(args.begin(), args.end(), nullptr), args.end());

    return args.size() == 1 ? args.front() : nullptr;
}
