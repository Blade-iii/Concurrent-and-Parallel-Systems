#include <iostream>
#include <thread>
using namespace std;

void  hello_world() {
    cout << "Thread id: " <<  this_thread::get_id() << endl;
}

int main() {
    thread t1(hello_world);
    t1.join();
    return 0;
}