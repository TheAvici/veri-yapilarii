#include "RoundRobinScheduler.h"

int main() {
    RoundRobinScheduler rr;
    rr.addProcess("P1", 5);
    rr.addProcess("P2", 8);
    rr.addProcess("P3", 3);

    rr.run(2);

    return 0;
}
