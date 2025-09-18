#include <chrono>
#include <iostream>
#include <fstream>

using namespace std;
using namespace std::chrono;


void do_work(int &n) {
    n=0;
    for (int i = 0; i < 1000000; i++) {
        ++n;
    }
}


int main()
    {
    // Create a file
    std::ofstream data("data.csv", std::ofstream::out);
        uint64_t total_ns = 0;
        int n = 0;
        for (int i = 0; i < 100; i++) {
            // Get start time
            auto start = std::chrono::system_clock::now();
            do_work(n);
            // Get end time
            auto end = std::chrono::system_clock::now();
            // Calculate duration
            auto duration = end - start;
            // write to file
            total_ns += duration.count();
            data << duration.count() << ",";
        }
        data.close();
        std::cout << "Mean: " << total_ns / 100 << "ns" <<std::endl;
        return 0;

    /*
     * Time taken Mean: 706674ns
     * CPU: AMD Ryzen 5 562U
     * Memory: 16GB 3200MT/s
    */
    }

