//
// Created by na2co on 2023/11/26.
//

#include "HuffmanTree.h"

void Select(HuffmanTree &HT, int n, int &s1, int &s2) {
    s1 = 0;
    s2 = 0;

    int i;
    for (i = 1; i <= n && !s1; i++) {
        if (!HT[i].parent) {
            s1 = i;
        }
    }
    for (; i <= n && !s2; i++) {
        if (!HT[i].parent) {
            s2 = i;
        }
    }
    if (HT[s2].weight < HT[s1].weight) {
        std::swap(s1, s2);
    }
    for (; i <= n; i++) {
        if (!HT[i].parent) {
            if (HT[i].weight < HT[s1].weight) {
                s2 = s1;
                s1 = i;
            } else if (HT[i].weight < HT[s2].weight) {
                s2 = i;
            }
        }
    }
}

Status BuildHT(HuffmanTree &HT, int *w, int n) {
    if (n <= 1) {
        HT = nullptr;
        return ERROR;
    }
    int m = 2 * n - 1;
    HT = new HTNode[m + 1];

    int i;
    HuffmanTree p;
    for (p = HT + 1, i = 1, w += 1; i <= n; ++i, ++p, ++w) {
        *p = {*w, 0, 0, 0};
    }
    for (; i <= m; ++i, ++p) {
        *p = {0, 0, 0, 0};
    }

    int s1, s2;
    for (i = n + 1; i <= m; i++) {
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }

    return OK;
}

Status HuffmanCoding(HuffmanTree HT, int n, HuffmanCode &HC) {
    HC = new char *[n + 1];
    char *cd = new char[n];
    cd[n - 1] = '\0';

    for (int i = 1; i <= n; ++i) {
        int start = n - 1;
        for (int c = i, f = HT[i].parent; f; c = f, f = HT[f].parent) {
            cd[--start] = HT[f].lchild == c ? '0' : '1';
        }
        HC[i] = new char[n - start];
        strcpy(HC[i], cd + start);
    }

    delete[] cd;

    return OK;
}

Status HuffmanEncode(std::unordered_map<char, std::string> char2Code) {
    std::ofstream saveEncodedFile("CodeFile");
    std::ifstream readFile("ToBeTran");

    if (!readFile) {
        std::cerr << "无法读取文件 ToBeTran" << std::endl;
        return ERROR;
    }

    if (!saveEncodedFile) {
        std::cerr << "无法创建文件 CodeFile" << std::endl;
        return ERROR;
    }

    char byte;
    while (readFile.get(byte)) {
        if (byte == ' ' || byte == '\n') {
            saveEncodedFile << byte;
        } else {
            saveEncodedFile << char2Code[byte];
        }
    }

    saveEncodedFile.close();
    readFile.close();

    return OK;
}

Status HuffmanDecode(std::unordered_map<std::string, char> code2Char) {
    std::ifstream readEncodeFile("CodeFile");
    std::ofstream saveDecodeFile("TextFile");

    if (!readEncodeFile) {
        std::cerr << "无法读取文件 CodeFire" << std::endl;
        return ERROR;
    }
    if (!saveDecodeFile) {
        std::cerr << "无法创建文件 TextFile" << std::endl;
        return ERROR;
    }

    std::string code;
    char byte;
    while (readEncodeFile.get(byte)) {
        if (byte == ' ' || byte == '\n') {
            saveDecodeFile << byte;
        } else {
            code.push_back(byte);
            if (code2Char.count(code)) {
                std::cout << code << std::endl;
                saveDecodeFile << code2Char[code];
                code.clear();
            }
        }
    }

    readEncodeFile.close();
    saveDecodeFile.close();

    return OK;
}