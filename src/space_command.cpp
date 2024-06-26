#include <iostream>
#include <string>

#include "space_command.h"

using namespace std;

SpaceCommand::~SpaceCommand() {
    for (Astronaut* a : this->astronauts) {
        delete a;
    }

    astronauts.clear();

    for (Flight* f : this->flights) {
        delete f;
    }

    flights.clear();
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

void SpaceCommand::showAstronautsOfFlight(Flight* f) {
    for (Astronaut* a : f->getPassengers()) {
        cout << "  - " << a << endl;
    }
}

void SpaceCommand::showFlights() {
    for (Flight* f : this->flights) {
        cout << "CÓDIGO DO VOO: " << f->getCode() << endl;

        cout << "STATUS: ";
        if (f->isInPlanning()) {
            cout << "Em plajenamento" << endl;
        } else if (f->isInProgress()) {
            cout << "Em andamento" << endl;
        } else if (f->isFinished()) {
            cout << "Voo finalizado com sucesso" << endl;
        } else if (f->isExploded()) {
            cout << "Voo finalizado sem sucesso (explosão)" << endl;
        }

        cout << "PARTICIPANTES:" << endl;
        showAstronautsOfFlight(f);
        cout << endl;
    }
}

void SpaceCommand::showAstronauts() {
    if (astronauts.size() < 1) {
        cout << endl << "Não há astronautas cadastrados." << endl << endl;
        return;
    }

    cout << endl << "LISTA DE ASTRONAUTAS:" << endl << endl;

    for (Astronaut* a : this->astronauts) {
        cout << "* " << a << endl;
    }

    cout << endl;
}

void SpaceCommand::showDeadAstronauts() {
    int total = 0;

    for (Astronaut* a : this->astronauts) {
        if (!a->isAlive()) {
            total++;
            cout << a << " participou dos voos: ";
            a->showCodeFlights();
        }
    }

    cout << total << " astronautas morreram." << endl;
}