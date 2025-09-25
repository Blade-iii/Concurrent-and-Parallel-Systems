#include <iostream>
#include <thread>

using namespace std;

int main() {
    // Create thread using lambda expression
    thread t([] {cout << "Hello" << endl; });
    // Join thread
    t.join();

    return 0;
}