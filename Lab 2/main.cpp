#include "common.h"
#include "singleLinkList.h"
#include "hString.h"
#include "IO.h"
#include "myAlgorithm.h"

int main() {
    std::cout << "--------简易文本编辑程序--------" << std::endl;

    while (true) {
        std::cout << "\n请选择您要进行的操作序号" << std::endl;
        std::cout << "1. 打开文件" << std::endl;
        std::cout << "2. 退出系统" << std::endl;

        int opt;
        std::cin >> opt;

        if (opt == 1) {
            linkList code;
            initList(code);
            if (readFile(code) == ERROR) {
                break;
            }

            outFile(code, 1, INT_MAX);

            bool exit = false;
            while (true) {
                if (exit) {
                    break;
                }

                std::cout << "\n请输入您要进行的操作编号" << std::endl;
                std::cout << "1. 输出指定范围的行" << std::endl;
                std::cout << "2. 行插入" << std::endl;
                std::cout << "3. 行删除" << std::endl;
                std::cout << "4. 行内文本插入" << std::endl;
                std::cout << "5. 行内文本删除" << std::endl;
                std::cout << "6. 文本查找" << std::endl;
                std::cout << "7. 文本文件保存" << std::endl;
                std::cout << "8. 检查括号是否匹配" << std::endl;
                std::cout << "0. 关闭该文件" << std::endl;

                int operation;
                std::cin.sync();
                std::cin >> operation;

                int lineNumber, cnt, status;
                myString insertCode, line, matchCode;
                switch (operation) {
                    case 1:
                        std::cout << "请输入您要开始显示的行号" << std::endl;
                        std::cin >> lineNumber;
                        std::cout << "请输入您要显示的行的数目" << std::endl;
                        std::cin >> cnt;

                        status = outFile(code, lineNumber, cnt);
                        if (status == ERROR) {
                            std::cerr << "输入有误， 请检查" << std::endl;
                        }
                        break;
                    case 2:
                        std::cout << "请输入您要插入的位置" << std::endl;
                        std::cin >> lineNumber;
                        std::cin.sync();
                        std::cout << "请输入您要插入的代码" << std::endl;

                        initString(insertCode);
                        std::cin.getline(insertCode->ch, MAXSTRLEN);
                        getStringLength(insertCode);

                        status = nodeInsert(code, lineNumber, insertCode);
                        if (status == ERROR) {
                            std::cerr << "输入有误， 请检查" << std::endl;
                        }
                        break;
                    case 3:
                        std::cout << "请输入您要开始删除的行的位置" << std::endl;
                        std::cin >> lineNumber;
                        std::cout << "请输入您要删除的行的数目" << std::endl;
                        std::cin >> cnt;

                        status = nodeDelete(code, lineNumber, cnt);
                        if (status == ERROR) {
                            std::cerr << "输入有误, 请检查" << std::endl;
                        }
                        break;
                    case 4:
                        std::cout << "请输入您要插入位置的行数" << std::endl;
                        std::cin >> lineNumber;
                        std::cout << "请输入您要插入的位置" << std::endl;
                        std::cin >> cnt;
                        std::cin.sync();
                        std::cout << "请输入您要插入的代码" << std::endl;

                        initString(insertCode);
                        std::cin.getline(insertCode->ch, MAXSTRLEN);
                        getStringLength(insertCode);

                        getElem(code, lineNumber, line);
                        charInsert(line, cnt, insertCode);
                        break;
                    case 5:
                        int charLoc;

                        std::cout << "请输入您要删除位置的行数" << std::endl;
                        std::cin >> lineNumber;
                        std::cout << "请输入您要删除的字符开始位置" << std::endl;
                        std::cin >> charLoc;
                        std::cout << "请输入您要删除的字符个数" << std::endl;
                        std::cin >> cnt;

                        getElem(code, lineNumber, line);
                        charDelete(line, charLoc, cnt);
                        break;
                    case 6:
                        std::cout << "请输入您要查找的行数" << std::endl;
                        std::cin >> lineNumber;
                        std::cin.sync();
                        std::cout << "请输入您要查询的子串" << std::endl;

                        initString(matchCode);
                        std::cin.getline(matchCode->ch, MAXSTRLEN);
                        getStringLength(matchCode);

                        getElem(code, lineNumber, line);

                        int matchLoc;
                        matchLoc = kmp(line, matchCode);

                        if (matchLoc == ERROR) {
                            std::cout << "该行代码中没有匹配的子串" << std::endl;
                        } else {
                            std::cout << "子串与改行代码第" << matchLoc << "个字符开始的子串匹配" << std::endl;
                        }

                        break;
                    case 7:
                        saveFile(code);
                        break;
                    case 8:
                        status = validParentheses(code);

                        if (status != OK) {
                            std::cout << "您输入的括号存在错误, 请检查" << std::endl;
                        } else {
                            std::cout << "括号完全匹配" << std::endl;
                        }
                        break;
                    case 0:
                        exit = true;
                        for (auto *p = code->next; p; p = p->next) {
                            destroyString(p->data);
                        }
                        destroyList(code);
                        break;
                    default:
                        std::cerr << "\n您的输入有误, 请重新输入" << std::endl;
                }
            }
        } else if (opt == 2) {
            break;
        } else {
            std::cerr << "\n您的输入有误, 请重新输入" << std::endl;
        }
    }

    return 0;
}