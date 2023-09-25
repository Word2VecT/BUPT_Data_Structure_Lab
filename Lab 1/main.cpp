#include "common.h"

typedef struct {
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
    int age;
} INFO; // definition

int save(INFO* student) {
    std::ofstream saveDat("input.dat");

    if (!saveDat) {
        std::cerr << "无法创建文件" << std::endl;
        return 1;
    }

    for (int i = 0; i < STUDENT_NUM; i++) {
        saveDat << student[i].id << ' ' << student[i].name << ' ' << student[i].age << std::endl;
    }

    saveDat.close();

    return 0;
} // TASK 2

int readAndSave() {
    std::ifstream readDat("input.dat");
    INFO temp[MAX_STUDENT_NUM];

    if (!readDat) {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }

    for (auto & stu : temp) {
        readDat >> stu.id >> stu.name >> stu.age;
    }

    readDat.close();

    std::ofstream saveDat("output.dat");

    if (!saveDat) {
        std::cerr << "无法创建文件" << std::endl;
        return 1;
    }

    for (int i = STUDENT_NUM - 1; i >= 0; i--) {
        saveDat << temp[i].id << ' ' << temp[i].name << ' ' << temp[i].age << std::endl;
    }

    saveDat.close();

    return 0;
} // TASK 3

int main() {
    INFO student[MAX_STUDENT_NUM];
    int opt;

    std::cout << "\n1. 读取学生信息 (五名)" << std::endl;
    std::cout << "2. 保存数据" << std::endl;
    std::cout << "3. 读取数据并反向存入" << std::endl;
    std::cout << "4. 退出" << std::endl;

    while (true) {
        std::cout << "\n请选择您要进行的操作: ";
        std::cin >> opt;

        switch (opt) {
            case 1:
                std::cout << "请依次输入学号，姓名，年龄 (以空格隔开)" << std::endl;
                for (int i = 0; i < STUDENT_NUM; i++) {
                    std::cin >> student[i].id >> student[i].name >> student[i].age;
                } // TASK 1
                break;
            case 2:
                save(student);
                break;
            case 3:
                readAndSave();
                break;
            case 4:
                return 0;
            default:
                std::cout << "无效操作，请重新输入" << std::endl;
        }
    }
}