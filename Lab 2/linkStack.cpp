//
// Created by na2co on 2023/10/25.
//

#include "linkStack.h"

Status initStack(linkStack &S) {
    S = nullptr;
    return OK;
}

Status pushStack(linkStack &top, sElemType e) {
    auto s = new stackNode;

    if (!s) {
        return ERROR;
    }

    s->data = e;
    s->next = top;
    top = s;

    return OK;
}

Status popStack(linkStack &top) {
    if (top == nullptr) {
        return ERROR;
    }

    auto p = top;
    top = top->next;

    delete p;
    return OK;
}

char topStack(linkStack top) {
    return top->data;
}