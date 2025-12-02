
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <iomanip>

void kareselToplam(const std::vector<int>& A, std::vector<long long>& S) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        long long toplam = 0;
        for (int j = 0; j < n; j++) {
            toplam += A[j];
        }
        S[i] = toplam;
    }
}

void dogrusalToplam(const std::vector<int>& A, std::vector<long long>& S) {
    int n = A.size();
    S[0] = A[0];
    for (int i = 1; i < n; i++) {
        S[i] = S[i - 1] + A[i];
    }
}

int main() {
    std::vector<int> boyutlar = {1000, 5000, 10000, 50000, 100000};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    std::cout << std::left
              << std::setw(10) << "n"
              << std::setw(45) << "O(n^2) cozum (mikrosaniye / milisaniye)"
              << std::setw(45) << "O(n) cozum (mikrosaniye / milisaniye)"
              << std::endl;
    for (int n : boyutlar) {
        std::vector<int> A(n);
        for (int i = 0; i < n; i++) {
            A[i] = dist(gen);
        }
        std::vector<long long> S1(n), S2(n);
        auto start1 = std::chrono::high_resolution_clock::now();
        kareselToplam(A, S1);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto sure1_mikro= std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count();
        auto sure1_mili= std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count();

        auto start2 = std::chrono::high_resolution_clock::now();
        dogrusalToplam(A, S2);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto sure2_mikro= std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count();
        auto sure2_mili= std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count();

        std::cout << std::left
                    << std::setw(10) << n
                    << std::setw(45)
                    << (std::to_string(sure1_mikro) + " mikrosaniye / " + std::to_string(sure1_mili) + " milisaniye")
                    << std::setw(45)
                    << (std::to_string(sure2_mikro) + " mikrosaniye / " + std::to_string(sure2_mili) + " milisaniye")
                    << std::endl;
    }

    return 0;
}