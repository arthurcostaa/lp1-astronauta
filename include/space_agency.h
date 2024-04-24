#ifndef SPACE_AGENGY_H
#define SPACE_AGENGY_H

#include "space_command.h"

class SpaceAgency {
private:
    SpaceCommand* spaceCommand;

    void showOptions();
    void createAstronaut();
    void createFlight();
    void addAstronautToFlight();
    void removeAstronatFromFlight();
    void launchFlight();
    void finishFlight();
    void explodeFlight();
public:
    SpaceAgency();
    ~SpaceAgency();

    void run();
};

#endif // SPACE_AGENGY_H