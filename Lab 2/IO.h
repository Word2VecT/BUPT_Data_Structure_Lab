//
// Created by na2co on 2023/10/24.
//

#ifndef LAB_2_IO_H
#define LAB_2_IO_H

#include "common.h"
#include "hString.h"
#include "singleLinkList.h"

Status readFile(linkList &L);

Status saveFile(linkList L);

Status outFile(linkList L, int n, int cnt);

#endif //LAB_2_IO_H