//
// Created by na2co on 2023/10/21.
//
#include "singleLinkList.h"

Status initList(linkList &L) {
    L = new linkNode;

    if (!L) {
        return ERROR;
    }

    L->next = nullptr;

    return OK;
}

void destroyList(linkList &L) {
    linkNode *p, *next;
    p = L;

    while (p) {
        next = p->next;
        delete p;
        p = next;
    }
    L = nullptr;
}

Status getElem(linkList L, int n, elemType &e) {
    linkNode *p = L;
    int i;

    for (i = 0; p && i < n; ++i) {
        p = p->next;
    }

    if (!p || i != n) {
        return ERROR;
    }

    e = p->data;

    return OK;
}

Status nodeInsert(linkList L, int n, elemType e) {
    linkNode *p = L;
    auto *q = new linkNode;
    int i;

    for (i = 0; p && i < n - 1; ++i) {
        p = p->next;
    }

    if (!p || i != n - 1) {
        return ERROR;
    }

    q->data = e;
    q->next = p->next;
    p->next = q;

    return OK;
}

Status nodeDelete(linkList &L, int n, int cnt) {
    linkNode *p = L;
    linkNode *q;
    int i;

    for (i = 0; p && i < n - 1; i++) {
        p = p->next;
    }

    if (!p || i != n - 1) {
        return ERROR;
    }

    for (i = 0; p->next && i < cnt; i++) {
        q = p->next;
        p->next = q->next;
        delete q;
    }

    return OK;
}