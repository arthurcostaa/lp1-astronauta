#include "flight.h"

Flight::Flight() {}

Flight::Flight(int code, Astronaut* passengers) {
    this->code = code;
    this->passengers = passengers;
    this->numPassengers = 0;
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

Astronaut* Flight::getPassengers() {
    return this->passengers;
}

void Flight::setPassengers(Astronaut* passengers) {
    this->passengers = passengers;
}

int Flight::getNumPassengers() {
    return this->numPassengers;
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