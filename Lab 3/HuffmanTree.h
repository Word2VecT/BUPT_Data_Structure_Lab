//
// Created by na2co on 2023/11/26.
//

#ifndef LAB_3_HUFFMANTREE_H
#define LAB_3_HUFFMANTREE_H

#include "common.h"

typedef struct {
    int weight;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;

typedef char **HuffmanCode;

void Select(HuffmanTree &HT, int n, int &s1, int &s2);

Status BuildHT(HuffmanTree &HT, int *w, int n);

Status HuffmanCoding(HuffmanTree HT, int n, HuffmanCode &HC);

Status HuffmanEncode(std::unordered_map<char, std::string> char2Code);

Status HuffmanDecode(std::unordered_map<std::string, char> code2Char);

#endif //LAB_3_HUFFMANTREE_H