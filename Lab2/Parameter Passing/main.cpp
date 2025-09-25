#include <iostream>
#include <random>
#include <thread>

using namespace std;

constexpr size_t num_threads = 5s;

void task(size_t n , int val) {
    cout << "Thread:" << n << " Random Value:" << val << endl;
}

int main() {
    // C++ version of creating random
    std::random_device rd;
    default_random_engine g(rd());

    vector<thread> threads;
    for (size_t i = 0; i < num_threads; i++)
        threads.emplace_back(task, i, g());

    // Use c++ ranged loop to join the threads
    for (auto &thread  : threads)
        thread.join();

    return 0;
}