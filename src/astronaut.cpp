#include <iostream>

#include "astronaut.h"

using namespace std;

Astronaut::Astronaut() {}

Astronaut::Astronaut(string cpf, string name, int age) {
    this->cpf = cpf;
    this->name = name;
    this->age = age;
    this->available = true;
    this->alive = true;
}

Astronaut::~Astronaut() {}

string Astronaut::getCpf() {
    return this->cpf;
}

void Astronaut::setCpf(string cpf) {
    this->cpf = cpf;
}

string Astronaut::getName() {
    return this->name;
}

void Astronaut::setName(string name) {
    this->name = name;
}

int Astronaut::getAge() {
    return this->age;
}

void Astronaut::setAge(int age) {
    this->age = age;
}

list<int>& Astronaut::getMissionsFlown() {
    return this->missionsFlown;
}

bool Astronaut::isAvailable() {
    return this->available;
}

void Astronaut::setAvailable(bool available) {
    this->available = available;
}

bool Astronaut::isAlive() {
    return this->alive;
}

void Astronaut::setAlive(bool alive) {
    this->alive = alive;
}

void Astronaut::addCodeFlight(int newCode) {
    if (!alive) {
        return;
    }

    for (int code : this->missionsFlown) {
        if (newCode == code) {
            return;
        }
    }

    missionsFlown.push_back(newCode);
}

void Astronaut::showCodeFlights() {;
    for (auto it = missionsFlown.begin(); it != missionsFlown.end(); it++) {
        cout << (it == missionsFlown.begin() ? "" : ", ") << *it;
    }

    if (missionsFlown.size() > 0) {
        cout << endl;
    }
}