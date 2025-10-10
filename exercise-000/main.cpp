#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

void changeValueByParameter(int value){
    value = 99;
    fmt::print("Value: {}\n", value);
    return;
}

void changeValueByPointer(int* ptr){
    *ptr = 77;
    fmt::print("Value ptr: {}\n", *ptr);
    return;
}

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);

    //Teil 1
    int x = 10;
    int* p = &x;
    fmt::println("x Wert: {}, Adresse: {}\n", x, fmt::ptr(&x));
    fmt::println("p Wert: {}, Adresse: {}\n", *p, fmt::ptr(p));
    *p = 42;
    fmt::println("x Wert: {}, p Adresse: {}\n", x, fmt::ptr(p));
    
    //Teil 2
    double* ptr = new double;
    *ptr = 3.1415;
    fmt::print("Wert: {}, Adresse: {}\n", *ptr, fmt::ptr(ptr));
    delete ptr;

    //Teil 3
    int y = 5;
    fmt::print("y1: {}\n", y);
    changeValueByParameter(y);
    fmt::print("y2: {}\n", y);
    changeValueByPointer(&y);
    fmt::print("y3: {}\n", y);

    return 0; /* exit gracefully*/

}

