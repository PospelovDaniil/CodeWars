#include <iostream>
#include <string>
#include <vector>

/**
 * A Simplistic TCP Finite State Machine (FSM)
 *
 * Automatons, or Finite State Machines (FSM), are extremely useful to programmers when it comes to software design.
 * You will be given a simplistic version of an FSM to code for a basic TCP session.
 * The outcome of this exercise will be to return the correct state of the TCP FSM based on the array of events given.
 *
 * The input array of events will consist of one or more of the following strings:
 * APP_PASSIVE_OPEN, APP_ACTIVE_OPEN, APP_SEND, APP_CLOSE, APP_TIMEOUT, RCV_SYN, RCV_ACK, RCV_SYN_ACK, RCV_FIN, RCV_FIN_ACK
 *
 * The states are as follows and should be returned in all capital letters as shown:
 * CLOSED, LISTEN, SYN_SENT, SYN_RCVD, ESTABLISHED, CLOSE_WAIT, LAST_ACK, FIN_WAIT_1, FIN_WAIT_2, CLOSING, TIME_WAIT
 *
 * The input will be an array of events. The initial state is CLOSED. Your job is to traverse the FSM as determined by the events,
 * and return the proper final state as a string, all caps, as shown above.
 * If an event is not applicable to the current state, your code will return "ERROR".
 *
 * CLOSED: APP_PASSIVE_OPEN -> LISTEN
 * CLOSED: APP_ACTIVE_OPEN  -> SYN_SENT
 * LISTEN: RCV_SYN          -> SYN_RCVD
 * LISTEN: APP_SEND         -> SYN_SENT
 * LISTEN: APP_CLOSE        -> CLOSED
 * SYN_RCVD: APP_CLOSE      -> FIN_WAIT_1
 * SYN_RCVD: RCV_ACK        -> ESTABLISHED
 * SYN_SENT: RCV_SYN        -> SYN_RCVD
 * SYN_SENT: RCV_SYN_ACK    -> ESTABLISHED
 * SYN_SENT: APP_CLOSE      -> CLOSED
 * ESTABLISHED: APP_CLOSE   -> FIN_WAIT_1
 * ESTABLISHED: RCV_FIN     -> CLOSE_WAIT
 * FIN_WAIT_1: RCV_FIN      -> CLOSING
 * FIN_WAIT_1: RCV_FIN_ACK  -> TIME_WAIT
 * FIN_WAIT_1: RCV_ACK      -> FIN_WAIT_2
 * CLOSING: RCV_ACK         -> TIME_WAIT
 * FIN_WAIT_2: RCV_FIN      -> TIME_WAIT
 * TIME_WAIT: APP_TIMEOUT   -> CLOSED
 * CLOSE_WAIT: APP_CLOSE    -> LAST_ACK
 * LAST_ACK: RCV_ACK        -> CLOSED
 */

std::string setState(std::string &state_owner, const std::string &new_state)
{
    if (state_owner == "CLOSED") {
        if (new_state == "APP_PASSIVE_OPEN") {
            return "LISTEN";
        }
        else if (new_state == "APP_ACTIVE_OPEN") {
            return "SYN_SENT";
        }
    }
    else if (state_owner == "LISTEN") {
        if (new_state == "RCV_SYN") {
            return "SYN_RCVD";
        }
        else if (new_state == "APP_SEND") {
            return "SYN_SENT";
        }
        else if (new_state == "APP_CLOSE") {
            return "CLOSED";
        }
    }
    else if (state_owner == "SYN_RCVD") {
        if (new_state == "APP_CLOSE") {
            return "FIN_WAIT_1";
        }
        else if (new_state == "RCV_ACK") {
            return "ESTABLISHED";
        }
    }
    else if (state_owner == "SYN_SENT") {
        if (new_state == "RCV_SYN") {
            return "SYN_RCVD";
        }
        else if (new_state == "RCV_SYN_ACK") {
            return "ESTABLISHED";
        }
        else if (new_state == "APP_CLOSE") {
            return "CLOSED";
        }
    }
    else if (state_owner == "ESTABLISHED") {
        if (new_state == "APP_CLOSE") {
            return "FIN_WAIT_1";
        }
        else if (new_state == "RCV_FIN") {
            return "CLOSE_WAIT";
        }
    }
    else if (state_owner == "FIN_WAIT_1") {
        if (new_state == "RCV_FIN") {
            return "CLOSING";
        }
        else if (new_state == "RCV_FIN_ACK") {
            return "TIME_WAIT";
        }
        else if (new_state == "RCV_ACK") {
            return "FIN_WAIT_2";
        }
    }
    else if (state_owner == "CLOSING") {
        if (new_state == "RCV_ACK") {
            return "TIME_WAIT";
        }
    }
    else if (state_owner == "FIN_WAIT_2") {
        if (new_state == "RCV_FIN") {
            return "TIME_WAIT";
        }
    }
    else if (state_owner == "TIME_WAIT") {
        if (new_state == "APP_TIMEOUT") {
            return "CLOSED";
        }
    }
    else if (state_owner == "CLOSE_WAIT") {
        if (new_state == "APP_CLOSE") {
            return "LAST_ACK";
        }
    }
    else if (state_owner == "LAST_ACK") {
        if (new_state == "RCV_ACK") {
            return "CLOSED";
        }
    }
    return "ERROR";
}

std::string traverse_TCP_states(const std::vector<std::string> &events)
{
    std::string state {"CLOSED"};

    for (const std::string &event: events) {
        state = setState(state, event);
        if (state == "ERROR") {
            return state;
        }
    }

    return state;
}

int main()
{
    using vs = std::vector<std::string>;

    vs test1 = {"APP_ACTIVE_OPEN", "RCV_SYN_ACK", "RCV_FIN"};
    vs test2 = {"APP_PASSIVE_OPEN", "RCV_SYN", "RCV_ACK"};
    vs test3 = {"APP_ACTIVE_OPEN", "RCV_SYN_ACK", "RCV_FIN", "APP_CLOSE"};
    vs test4 = {"APP_ACTIVE_OPEN"};
    vs test5 = {"APP_PASSIVE_OPEN", "RCV_SYN", "RCV_ACK", "APP_CLOSE", "APP_SEND"};

    std::cout << traverse_TCP_states(test1) << std::endl;
    std::cout << traverse_TCP_states(test2) << std::endl;
    std::cout << traverse_TCP_states(test3) << std::endl;
    std::cout << traverse_TCP_states(test4) << std::endl;
    std::cout << traverse_TCP_states(test5) << std::endl;
    return 0;
}
