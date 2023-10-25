//
// Created by na2co on 2023/10/25.
//
#include "myAlgorithm.h"

int kmp(myString S, myString T) {
    int next[T->len + 1];
    next[0] = 0;

    int i = 0;
    int j = -1;
    next[0] = -1;

    while (i < T->len) {
        if (j == -1 || T->ch[i] == T->ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }

    i = 0;
    j = 0;

    while (i < S->len && j < T->len) {
        if (j == -1 || S->ch[i] == T->ch[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }

    if (j >= T->len) {
        return i - T->len + 1;
    } else {
        return ERROR;
    }
}

Status validParentheses(linkList L) {
    linkStack parentheses;
    initStack(parentheses);

    auto *p = L->next;

    while (p) {
        for (int i = 0; i < p->data->len; i++) {
            char c = p->data->ch[i];
            if (c == '(' || c == '[' || c == '{') {
                pushStack(parentheses, c);
            } else {
                if (c == ')') {
                    if (parentheses && topStack(parentheses) == '(') {
                        popStack(parentheses);
                    } else {
                        return ERROR;
                    }
                }
                if (c == '}') {
                    if (parentheses && topStack(parentheses) == '{') {
                        popStack(parentheses);
                    } else {
                        return ERROR;
                    }
                }
                if (c == ']') {
                    if (parentheses && topStack(parentheses) == '[') {
                        popStack(parentheses);
                    } else {
                        return ERROR;
                    }
                }
            }
        }
        p = p->next;
    }

    return !parentheses;
}