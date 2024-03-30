#include <iostream>
#include <chrono>

int main()
{
    const int size = 1000000000;

    srand(static_cast<unsigned>(time(nullptr)));
    int* arr = new int[size];

    long long sum = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 + 1;
        sum += arr[i];
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Sum: " << sum << std::endl;

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

    delete[] arr;
}