#include <iostream>
#include <chrono>

void copyij(int **src, int **dst) {
    int i, j;
    for (i = 0; i < 2048; i++) {
        for (j = 0; j < 2048; j++) {
            dst[i][j] = src[i][j];
        }
    }
}

void copyji(int **src, int **dst) {
    int i, j;
    for (j = 0; j < 2048; j++) {
        for (i = 0; i < 2048; i++) {
            dst[i][j] = src[i][j];
        }
    }
}

int main() {
    int **src = new int*[2048];
    int **dst = new int*[2048];

    for (int i = 0; i < 2048; i++) {
        src[i] = new int[2048];
        dst[i] = new int[2048];
    }

    double copyij_t = 0, copyji_t = 0;

    for (int i = 0; i < 100; i++) {
        std::chrono::steady_clock::time_point copyij_t0 = std::chrono::steady_clock::now();
        copyij(src, dst);
        std::chrono::steady_clock::time_point copyij_t1 = std::chrono::steady_clock::now();

        std::chrono::steady_clock::time_point copyji_t0 = std::chrono::steady_clock::now();
        copyji(src, dst);
        std::chrono::steady_clock::time_point copyji_t1 = std::chrono::steady_clock::now();

        copyij_t += std::chrono::duration<double, std::milli>(copyij_t1 - copyij_t0).count();
        copyji_t += std::chrono::duration<double, std::milli>(copyji_t1 - copyji_t0).count();
    }

    std::cout << "copyij spend time: " << copyij_t / 100 << "ms" << std::endl;
    std::cout << "copyji spend time: " << copyji_t / 100 << "ms" << std::endl;

    for (int i = 0; i < 2048; i++) {
        delete[] src[i];
        delete[] dst[i];
    }
    delete[] src;
    delete[] dst;

    return 0;
}