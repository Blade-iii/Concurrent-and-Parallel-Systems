#include <iostream>
#include <functional>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // Lambda
    auto add = [](int x, int y) {return x + y; };
    // Call the defined function
    auto x = add(10, 12);
    std::cout << "10 + 12 = " << x << std::endl;

    // Create function object
    std::function<int(int,int)> addFunc = [](int x, int y) {return x + y; };
    x = addFunc(20,12);
    // Display
    std::cout << "20 + 12 = " << x << std::endl;

    int a = 5;
    int b = 10;
    // Define the values put into the function
    auto add_fixed = [a,b] {return a + b; };
    // Call function
    x = add_fixed();
    // Display
    std::cout << "5 + 10 = " << x << std::endl;

    a = 20;
    b = 30;
    // Call the function
    x = add_fixed();
    // Display - will come out 15 as the function is fixed
    std::cout << "20 + 30 = " << x << std::endl;

    // Call the reference and define
    auto add_reference = [&a, &b] {return a + b; };
    // Call function
    x = add_reference();
    std::cout << "20 + 30 = " << x << std::endl;

    // Change the values
    a = 30;
    b=5;
    x = add_reference();
    std::cout << "30 + 5 = " << x << std::endl;

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}