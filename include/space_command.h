#ifndef SPACE_COMMAND_H
#define SPACE_COMMAND_H

#include <list>

#include "astronaut.h"
#include "flight.h"

class SpaceCommand {
private:
    list<Astronaut*> astronauts;
    list<Flight*> flights;

    void showAstronautsOfFlight(Flight* f);

public:
    SpaceCommand();
    ~SpaceCommand();

    list<Astronaut*> getAstronauts();
    void setAstronauts(list<Astronaut*> astronauts);

    list<Flight*> getFlights();
    void setFlights(list<Flight*> flights);

    bool registerNewAstronaut(Astronaut* newAstronat);

    bool registerNewFlight(Flight* newFlight);

    bool addAstronautToFlight(int flightCode, string cpf);

    bool removeAstronautFromFlight(int flightCode, string cpf);

    bool lauchFlight(int flightCode);

    bool explodeFlight(int flightCode);

    bool finishFlight(int flightCode);

    void showFlights();

    void showDeadAstronauts();
};

#endif // SPACE_COMMAND_H