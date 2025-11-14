#include <fmt/chrono.h>
#include <fmt/format.h>

typedef enum {
    state_opend = 0,
    state_closed = 1,
    state_down = 2,
    state_up = 3,
    state_stop_down = 4,
    state_stop_up = 5
} state_t;
state_t state = state_up;  // initial state

typedef enum {
    event_btn_remote = 0,
    event_limit_sw_down = 1,
    event_limit_sw_up = 2
} event_t;
event_t event;

state_t transition_table[][] = {{}};

auto main(int argc, char** argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    int current_state = 5;
    int trans[] = {2,0,1,0,0,0,0};
    int automat[6][3] = {{2,0,0},{5,1,1},{4,1,2},{2,3,3},{5,4,4},{0,5,3}};
    fmt::print("Aktueller State: {}\n", current_state);
    for (int i = 0; i < (sizeof(trans)/sizeof(trans[0])); i++){
        fmt::print("Action: {}\n", trans[i]);
        current_state = automat[current_state][trans[i]];
        fmt::print("Neuer State: {}\n", current_state);

    }
    return 0; /* exit gracefully*/
}
