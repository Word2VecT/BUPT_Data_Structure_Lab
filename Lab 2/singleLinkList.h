//
// Created by na2co on 2023/10/21.
//

#ifndef LAB_2_SINGLELINKLIST_H
#define LAB_2_SINGLELINKLIST_H

#include "common.h"
#include "hString.h"

typedef myString elemType;

typedef struct linkNode {
    elemType data;
    struct linkNode* next;
}linkNode, *linkList;

Status initList(linkList &L);

void destroyList(linkList &L);

Status getElem(linkList L, int n, elemType &e);

Status nodeInsert(linkList L, int n, elemType e);

Status nodeDelete(linkList &L, int n, int cnt);

#endif //LAB_2_SINGLELINKLIST_H