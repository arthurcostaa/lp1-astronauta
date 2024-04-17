#include <iostream>
#include <string>

#include "space_command.h"

using namespace std;

SpaceCommand::SpaceCommand() {}

SpaceCommand::~SpaceCommand() {
    for (Astronaut* t : this->astronauts) {
        delete t;
    }

    for (Flight* f : this->flights) {
        delete f;
    }
}

list<Astronaut*> SpaceCommand::getAstronauts() {
    return this->astronauts;
}

void SpaceCommand::setAstronauts(list<Astronaut*> astronauts) {
    this->astronauts = astronauts;
}

list<Flight*> SpaceCommand::getFlights() {
    return this->flights;
}

void SpaceCommand::setFlights(list<Flight*> flights) {
    this->flights = flights;
}

bool SpaceCommand::registerNewAstronaut(Astronaut* newAstronat) {
    for (Astronaut* a : this->astronauts) {
        if (a->getCpf() == newAstronat->getCpf()) {
            return false;
        }
    }

    if (!newAstronat->isAlive() || !newAstronat->isAvailable()) {
        return false;
    }

    this->astronauts.push_back(newAstronat);
    return true;
}

bool SpaceCommand::registerNewFlight(Flight* newFlight) {
    for (Flight* f : this->flights) {
        if (f->getCode() == newFlight->getCode()) {
            return false;
        }
    }

    if (newFlight->isInProgress() || newFlight->isFinished() || newFlight->isExploded()) {
        return false;
    }

    this->flights.push_back(newFlight);
    return true;
}

bool SpaceCommand::addAstronautToFlight(int flightCode, string cpf) {
    bool flightNotFound = true, astronautNotFound = true;
    Flight* flight;
    Astronaut* astronaut;

    for (Flight* f : this->flights) {
        if (f->getCode() == flightCode) {
            flightNotFound = false;
            flight = f;
        }
    }

    if (flightNotFound) {
        return false;
    }

    for (Astronaut* a : this->astronauts) {
        if (a->getCpf() == cpf) {
            astronautNotFound = false;
            astronaut = a;
        }
    }

    if (astronautNotFound) {
        return false;
    }

    return flight->addAstronaut(astronaut);
}

bool SpaceCommand::removeAstronautFromFlight(int flightCode, string cpf) {
    bool flightNotFound = true, astronautNotFound = true;
    Flight* flight;

    for (Flight* f : this->flights) {
        if (f->getCode() == flightCode) {
            flightNotFound = false;
            flight = f;
        }
    }

    if (flightNotFound) {
        return false;
    }

    for (Astronaut* a : this->astronauts) {
        if (a->getCpf() == cpf) {
            astronautNotFound = false;
        }
    }

    if (astronautNotFound) {
        return false;
    }

    return flight->removeAstronaut(cpf);
}

bool SpaceCommand::lauchFlight(int flightCode) {
    bool flightNotFound = true;
    Flight* flight;

    for (Flight* f : this->flights) {
        if (f->getCode() == flightCode) {
            flightNotFound = false;
            flight = f;
        }
    }

    if (flightNotFound) {
        return false;
    }

    return flight->launch();
}

bool SpaceCommand::explodeFlight(int flightCode) {
    bool flightNotFound = true;
    Flight* flight;

    for (Flight* f : this->flights) {
        if (f->getCode() == flightCode) {
            flightNotFound = false;
            flight = f;
        }
    }

    if (flightNotFound) {
        return false;
    }

    return flight->explode();
}

bool SpaceCommand::finishFlight(int flightCode) {
    bool flightNotFound = true;
    Flight* flight;

    for (Flight* f : this->flights) {
        if (f->getCode() == flightCode) {
            flightNotFound = false;
            flight = f;
        }
    }

    if (flightNotFound) {
        return false;
    }

    return flight->finish();
}