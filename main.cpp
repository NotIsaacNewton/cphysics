#include "Universe.h"
#include "Object.h"

using namespace std;

int main() {
    Universe universe{"verlet"};
    Object object{universe};
    universe.simulate();
    return 0;
}
