#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>
using namespace  std;

mutex mut;

void increment(shared_ptr< int>value) {
    for (unsigned int i = 0; i < 1000000; i++) {
        *value = *value + 1;
    }
}

void incrementMutex(shared_ptr< int>value) {
    for (unsigned int i = 0; i < 1000000; i++) {
        // Acquire  the lock
        mut.lock();
        *value = *value + 1;
        mut.unlock();
    }
}

int main() {
    auto value = make_shared<int>(0);
    auto numberThreads = thread::hardware_concurrency();
    vector<thread> threads;
    for (unsigned int i = 0; i < numberThreads; i++) {
        // Change to either increment or incrementMutex
        threads.push_back(thread(incrementMutex, value));
    }

    for (auto& thread : threads) {
        thread.join();
    }
    cout <<"Value = " << *value << endl;
}