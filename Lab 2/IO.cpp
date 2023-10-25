//
// Created by na2co on 2023/10/22.
//
#include "IO.h"

Status readFile(linkList &L) {
    std::cin.sync();
    std::cout << "请输入您要打开的文件名: " << std::endl;

    myString fileName;
    initString(fileName);
    std::cin.getline(fileName->ch, MAXSTRLEN);

    std::ifstream readF(fileName->ch);

    if (!readF) {
        std::cerr << "无法打开文件" << std::endl;
        destroyString(fileName);
        return ERROR;
    } else {
        std::cout << "成功打开文件 " << fileName->ch << std::endl;
    }

    linkList p = L;

    myString line;
    initString(line);

    while (readF.getline(line->ch, MAXSTRLEN)) {
        getStringLength(line);

        auto q = new linkNode;
        q->data = line;
        q->next = nullptr;
        p->next = q;
        p = q;

        initString(line);
    }

    destroyString(line);
    readF.close();
    destroyString(fileName);

    return OK;
}

Status saveFile(linkList L) {
    myString fileName;
    initString(fileName);

    std::cin.sync();
    std::cout << "请输入要保存的文件名" << std::endl;
    std::cin.getline(fileName->ch, MAXSTRLEN);

    std::ofstream saveF(fileName->ch);

    if (!saveF) {
        std::cerr << "无法创建文件" << std::endl;
        destroyString(fileName);
        return ERROR;
    } else {
        std::cout << "成功保存文件 " << fileName->ch << std::endl;
    }

    linkList p = L->next;
    while (p) {
        saveF << p->data->ch << std::endl;
        p = p->next;
    }

    saveF.close();
    destroyString(fileName);

    return OK;
}

Status outFile(linkList L, int n, int cnt) {
    linkList p = L;
    int i;

    for (i = 0; p && i < n; ++i) {
        p = p->next;
    }

    if (!p) {
        return ERROR;
    }

    for (int j = 0; p && j < cnt; ++j) {
        std::cout << i++ << ": " << p->data->ch << std::endl;
        p = p->next;
    }

    return OK;
}