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

void incrementLockGuard(shared_ptr< int>value) {
    for (unsigned int i = 0; i < 1000000; i++) {
        // Create lock guard
        lock_guard<mutex> lock(mut);
        *value = *value + 1;
        // Lock guard unlocks after the end of the loop
    }
}

int main() {
    auto value = make_shared<int>(0);
    auto numberThreads = thread::hardware_concurrency();
    vector<thread> threads;
    for (unsigned int i = 0; i < numberThreads; i++) {
        // Change to either increment or incrementMutex or incrementLockGuard
        threads.push_back(thread(incrementLockGuard, value));
    }

    for (auto& thread : threads) {
        thread.join();
    }
    cout <<"Value = " << *value << endl;
}