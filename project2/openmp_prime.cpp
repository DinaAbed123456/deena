
#include <iostream>
#include <cmath>
#include <chrono>
#include <omp.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    const int N = 100000000;
    int total_primes = 0;

    auto start = std::chrono::high_resolution_clock::now();

    #pragma omp parallel for reduction(+:total_primes)
    for (int i = 1; i <= N; ++i) {
        if (is_prime(i)) {
            total_primes++;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Total prime numbers up to " << N << ": " << total_primes << std::endl;
    std::cout << "Execution time with OpenMP: " << duration.count() << " seconds\n";

    return 0;
}
