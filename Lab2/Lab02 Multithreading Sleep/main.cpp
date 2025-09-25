#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

void task_one() {
    cout << "Task One Starting" << endl;
    cout << "Task one sleeping for 3 seconds" << endl;
    sleep_for(seconds(3));
    cout << "Task one awake" << endl;
    cout << "Task one sleeping for 5 seconds" << endl;
    sleep_for(seconds(5));
    cout << "Task one awake" << endl;
    cout << "Task one finished" << endl;
}

void task_two() {
    cout << "Task Two Starting" << endl;
    cout << "Task Two sleeping for 2 seconds" << endl;
    sleep_for(seconds(2));
    cout << "Task Two awake" << endl;
    cout << "Task Two sleeping for 10 seconds" << endl;
    sleep_for(seconds(10));
    cout << "Task Two awake" << endl;
    cout << "Task Two finished" << endl;
}

int main() {
    cout << "Start Task One" << endl;
    thread t1(task_one);
    cout << "Start Task Two" << endl;
    thread t2(task_two);
    cout << "Joining Task one" << endl;
    t1.join();
    cout << "joined Task one" << endl;
    cout << "Joining Task two" << endl;
    t2.join();
    cout << "joined Task two" << endl;
    cout << "Ending" << endl;
    return 0;
}