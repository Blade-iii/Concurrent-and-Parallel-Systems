#include <functional>
#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // Lambda
    auto add = [](int x, int y) {return x + y; };
    // Call the defined function
    auto x = add(10, 20);
    std::cout << "10+20" << x << std::endl;

    // Create function object
    function<int(int,int)> addFunc = [](int x, int y) {return x + y; };

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}