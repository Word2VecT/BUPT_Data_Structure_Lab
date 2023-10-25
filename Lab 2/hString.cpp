//
// Created by na2co on 2023/10/21.
//
#include "hString.h"

Status initString(myString &S) {
    S = new hString;
    S->ch = new char[MAXSTRLEN + 5];

    if (!S->ch) {
        return ERROR;
    }
    return OK;
}

void destroyString(myString &S) {
    delete S->ch;
    delete S;
}

void getStringLength(myString &S) {
    int i;
    for (i = 0; S->ch[i] != '\0'; ++i) {};
    S->len = i;
}

Status charInsert(myString &S, int n, myString insertS) {
    if (S->len + insertS->len > MAXSTRLEN) {
        return ERROR;
    }

    S->ch[S->len + insertS->len] = '\0';
    for (int i = S->len - 1; i >= n - 1; --i) {
        S->ch[i + insertS->len] = S->ch[i];
    }
    for (int i = 0; i < insertS->len; ++i) {
        S->ch[i + n - 1] = insertS->ch[i];
    }
    S->len += insertS->len;

    return OK;
}

Status charDelete(myString &S, int n, int cnt) {
    if (n > S->len) {
        return ERROR;
    }

    cnt = std::min(cnt, S->len - n + 1);
    for (int i = n + cnt - 1; i < S->len; ++i) {
        S->ch[i - cnt] = S->ch[i];
    }
    S->len -= cnt;
    S->ch[S->len] = '\0';

    return OK;
}