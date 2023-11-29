#include "common.h"
#include "HuffmanTree.h"

int main() {
    HuffmanTree HT;
    HuffmanCode HC;
    int *w;
    char *cha;
    int n;
    std::unordered_map<char, std::string> char2Code;
    std::unordered_map<std::string, char> code2Char;

    std::ofstream saveFile("hfmTree");

    std::cout << "请输入字符个数，不包括空格和回车" << std::endl;
    std::cin >> n;
    std::cout << "请输入字符，以空格隔开" << std::endl;
    cha = new char[n + 1];
    for (int i = 1; i <= n; i++) {
        std::cin >> cha[i];
    }
    std::cout << "请输入每个字符对应的权重，以空格隔开" << std::endl;
    w = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        std::cin >> w[i];
    }

    if (BuildHT(HT, w, n) == ERROR) {
        std::cerr << "创建哈夫曼树失败" << std::endl;
        return ERROR;
    }
    if (HuffmanCoding(HT, n, HC) == ERROR) {
        std::cerr << "构建哈夫曼树失败" << std::endl;
        return ERROR;
    }

    for (int i = 1; i <= n; i++) {
        char2Code[cha[i]] = HC[i];
        code2Char[HC[i]] = cha[i];
    }

    delete []HT;
    for (int i = 1; i <= n; i++) {
        delete []HC[i];
    }
    delete []HC;

    if (!saveFile) {
        std::cerr << "无法创建文件 hfmTree" << std::endl;
        return ERROR;
    }

    for (const auto& c : char2Code) {
        std::cout << c.first << ' ' << c.second << std::endl;
        saveFile << c.first << ' ' << c.second << std::endl;
    }
    std::cout << "成功保存至 hfmTree" << std::endl;

    saveFile.close();
    delete[] w;
    delete[] cha;

    std::cin.sync();
    std::cout << "下面对报文 ToBeTran 进行编码，按回车继续" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    if (HuffmanEncode(char2Code) == ERROR) {
        std::cerr << "编码失败" << std::endl;
        return ERROR;
    }
    std::cout << "编码成功" << std::endl;

    std::cin.sync();
    std::cout << "下面对密文 CodeFile 进行解码，按回车继续" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (HuffmanDecode(code2Char) == ERROR) {
        std::cerr << "解码失败" << std::endl;
        return ERROR;
    }
    std::cout << "解码成功" << std::endl;
}