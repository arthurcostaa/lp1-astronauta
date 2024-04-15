#ifndef SPACE_COMMAND_H
#define SPACE_COMMAND_H

#include <vector>

#include "astronaut.h"
#include "flight.h"

class SpaceCommand {
private:
    vector<Astronaut*> astronauts;
    vector<Flight*> flights;

    Astronaut* createAstronaut();
    Flight* createFlight();
    void showOptions();
public:
    SpaceCommand();
    ~SpaceCommand();

    vector<Astronaut*> getAstronauts();
    void setAstronauts(vector<Astronaut*> astronauts);

    vector<Flight*> getFlights();
    void setFlights(vector<Flight*> flights);

    void registerNewAstronaut();

    void registerNewFlight();

    void addAstronautToFlight();

    void menu();
};

#endif // SPACE_COMMAND_H