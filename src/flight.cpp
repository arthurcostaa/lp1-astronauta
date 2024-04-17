#include "flight.h"

Flight::Flight() {}

Flight::Flight(int code) {
    this->code = code;
    this->inPlanning = true;
    this->inProgress = false;
    this->exploded = false;
    this->finished = false;
}

Flight::~Flight() {}

int Flight::getCode() {
    return this->code;
}

void Flight::setCode(int code) {
    this->code = code;
}

list<Astronaut*>& Flight::getPassengers() {
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

bool Flight::isFinished() {
    return this->finished;
}

void Flight::setFinished(bool finished) {
    this->finished = finished;
}

int Flight::getNumPassengers() {
    return this->passengers.size();
}

bool Flight::addAstronaut(Astronaut* newAstronaut) {
    if (inPlanning) {
        if (!newAstronaut->isAlive()) {
            return false;
        }

        // Don't add an astronaut that is already in the flight
        // to avoid duplicated values
        for (Astronaut* a : passengers) {
            if (a->getCpf() == newAstronaut->getCpf()) {
                return false;
            }
        }

        passengers.push_back(newAstronaut);
        return true;
    }

    return false;
}

bool Flight::removeAstronaut(string cpf) {
    if (inPlanning) {
        for (Astronaut* a : passengers) {
            if (a->getCpf() == cpf) {
                passengers.remove(a);
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

        // All astronauts must be available and alive to lauch the rocket
        for (Astronaut* a : this->passengers) {
            if (!a->isAvailable() && !a->isAlive()) {
                return false;
            }
        }

        setInPlanning(false);
        setInProgress(true);

        for (Astronaut* a : this->passengers) {
            a->setAvailable(false);
        }

        return true;
    }

    return false;
}

bool Flight::explode() {
    if (inProgress) {
        setInProgress(false);
        setExploded(true);

        for (Astronaut* a : this->passengers) {
            a->setAlive(false);
            a->setAvailable(false);
        }

        return true;
    }

    return false;
}

bool Flight::finish() {
    if (inProgress) {
        setInProgress(false);
        setFinished(true);

        for (Astronaut* a : this->passengers) {
            a->addCodeFlight(this->getCode());
            a->setAvailable(true);
        }

        return true;
    }

    return false;
}