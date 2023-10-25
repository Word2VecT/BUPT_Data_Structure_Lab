//
// Created by na2co on 2023/10/21.
//

#ifndef LAB_2_HSTRING_H
#define LAB_2_HSTRING_H

#include "common.h"

typedef struct {
    char* ch;
    int len;
} hString, *myString;

Status initString(myString &S);

void destroyString(myString &S);

void getStringLength(myString &S);

Status charInsert(myString &S, int n, myString insertS);

Status charDelete(myString &S, int n, int cnt);

#endif //LAB_2_HSTRING_H