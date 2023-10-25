//
// Created by na2co on 2023/10/25.
//

#ifndef LAB_2_LINKSTACK_H
#define LAB_2_LINKSTACK_H

#include "common.h"

typedef char sElemType;

typedef struct stackNode {
    sElemType data;
    struct stackNode *next;
} stackNode, *linkStack;

Status initStack(linkStack &S);

Status pushStack(linkStack &top, sElemType e);

Status popStack(linkStack &top);

char topStack(linkStack top);

#endif //LAB_2_LINKSTACK_H