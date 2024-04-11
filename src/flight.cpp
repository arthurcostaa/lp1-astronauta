#include "flight.h"

Flight::Flight() {}

Flight::Flight(int code) {
    this->code = code;
    this->inPlanning = true;
    this->inProgress = false;
    this->exploded = false;
}

Flight::~Flight() {}

int Flight::getCode() {
    return this->code;
}

void Flight::setCode(int code) {
    this->code = code;
}

vector<Astronaut*> Flight::getPassengers() {
    return this->passengers;
}

bool Flight::isInPlanning() {
    return this->inPlanning;
}

void Flight::setInPlanning(bool inPlanning) {
    this->inPlanning = inPlanning;
}

bool Flight::isInProgress() {
    return this->inProgress;
}

void Flight::setInProgress(bool inProgress) {
    this->inProgress = inProgress;
}

bool Flight::isExploded() {
    return this->exploded;
}

void Flight::setExploded(bool exploded) {
    this->exploded = exploded;
}

int Flight::getNumPassengers() {
    return this->passengers.size();
}

bool Flight::addAstronaut(Astronaut* astronaut) {
    if (inPlanning) {
        passengers.push_back(astronaut);
        return true;
    }

    return false;
}

bool Flight::removeAstronaut(string cpf) {
    if (inPlanning) {
        for (int i = 0; i < (int) passengers.size(); i++) {
            if (passengers[i]->getCpf() == cpf) {
                passengers.erase(passengers.begin() + i);
                return true;
            }
        }
    }

    return false;
}

bool Flight::launch() {
    if (inPlanning) {
        if (this->getNumPassengers() < 1) {
            return false;
        }

        for (Astronaut* passenger : this->passengers) {
            if (!passenger->isAvailable()) {
                return false;
            }
        }

        this->inPlanning = false;
        this->inProgress = true;

        for (Astronaut* passenger : this->passengers) {
            passenger->setAvailable(false);
        }

        return true;
    }

    return false;
}