#include "space_command.h"
#include "space_agency.h"

using namespace std;

int main() {
    SpaceAgency* aeb = new SpaceAgency();

    aeb->run();

    delete aeb;

    return 0;
}