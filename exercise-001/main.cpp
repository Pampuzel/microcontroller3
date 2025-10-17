#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int globalVar = 1;
int beliebigerWert = 2004857;
int Nullwert = 0;
int keinWert;
static int statisch = 1;
const int konstant = 2;


void foo() { fmt::print("Hello from foo!\\n"); }
int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */

    //Teil 1
    fmt::println("Hello, {}!\n", tea::PROJECT_NAME);
    fmt::println("globalVar {}, {}", globalVar, fmt::ptr(&globalVar));
    fmt::println("beliebigerWert {}, {}", beliebigerWert, fmt::ptr(&beliebigerWert));
    fmt::println("Nullwert {}, {}", Nullwert, fmt::ptr(&Nullwert));
    fmt::println("keinWert {}, {}", keinWert, fmt::ptr(&keinWert));
    fmt::println("statisch {}, {}", statisch, fmt::ptr(&statisch));
    fmt::println("konstant {}, {}", konstant, fmt::ptr(&konstant));

    //Teil 2
    int localVar = 2;
    static int localstatisch = 1;
    const int localkonstant = 2;
    fmt::println("localVar {}, {}", localVar, fmt::ptr(&localVar));
    fmt::println("localstatisch {}, {}", statisch, fmt::ptr(&localstatisch));
    fmt::println("localkonstant {}, {}", konstant, fmt::ptr(&localkonstant));

    //Teil 3
    int* heapVar = new int(3);
    fmt::println("heapVar {}, {}", fmt::ptr(&heapVar), fmt::ptr(heapVar));
    delete heapVar;

    //Teil 4
    fmt::print("Adresse von foo: {}\n", fmt::ptr(&foo));
    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
