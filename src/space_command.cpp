#include <iostream>
#include <string>

#include "space_command.h"

using namespace std;

SpaceCommand::SpaceCommand() {}

SpaceCommand::~SpaceCommand() {
    for (int i = 0; i < (int) this->astronauts.size(); i++) {
        delete this->astronauts[i];
    }

    for (int i = 0; i < (int) this->flights.size(); i++) {
        delete this->flights[i];
    }
}

vector<Astronaut*> SpaceCommand::getAstronauts() {
    return this->astronauts;
}

void SpaceCommand::setAstronauts(vector<Astronaut*> astronauts) {
    this->astronauts = astronauts;
}

vector<Flight*> SpaceCommand::getFlights() {
    return this->flights;
}

void SpaceCommand::setFlights(vector<Flight*> flights) {
    this->flights = flights;
}

Astronaut* SpaceCommand::createAstronaut() {
    string name, cpf;
    int age;

    cout << "Nome: ";
    cin >> name;
    cout << "CPF: ";
    cin >> cpf;
    cout << "Idade: ";
    cin >> age;

    Astronaut* astronat = new Astronaut(cpf, name, age);
    return astronat;
}

void SpaceCommand::registerNewAstronaut() {
    Astronaut* astronaut = createAstronaut();
    this->astronauts.push_back(astronaut);
}

Flight* SpaceCommand::createFlight() {
    int code;

    cout << "Código: ";
    cin >> code;

    Flight* flight = new Flight(code);

    return flight;
}

void SpaceCommand::registerNewFlight() {
    Flight* flight = createFlight();
    this->flights.push_back(flight);
}

void SpaceCommand::addAstronautToFlight() {
    Astronaut* astronaut = nullptr;
    Flight* flight = nullptr;
    string cpf;
    int code;

    cout << "Digite o código do voo: " << endl;
    cin >> code;
    cout << "Digite o CPF do astronauta: ";
    cin >> cpf;

    for (Flight* f : flights) {
        if (f->getCode() == code) {
            flight = f;
            break;
        }
    }
    if (flight == nullptr) {
        cout << "ERRO. Não há voo com esse código." << endl;
        return;
    }

    for (Astronaut* a : astronauts) {
        if (a->getCpf() == cpf) {
            astronaut = a;
            break;
        }
    }
    if (astronaut == nullptr) {
        cout << "ERRO. Não há astronauta com esse CPF." << endl;
        return;
    }

    if (flight->addAstronaut(astronaut)) {
        cout << "Astronauta " << astronaut->getName()
             << " (" << astronaut->getCpf() << ") "
             << "adicionado com sucesso no voo "
             << flight->getCode() << "." << endl;
    } else {
        cout << "NÃO foi possível adicionar o astronauta no voo"
             << flight->getCode() << "." << endl;
    }
}

void SpaceCommand::showOptions() {
    cout << "========================================" << endl;
    cout << "1. Cadastrar novo voo" << endl;
    cout << "2. Cadastrar novo astronauta" << endl;
    cout << "3. Adicionar astronauta em um voo (por CPF)" << endl;
    cout << "0. Encerrar programa" << endl;
    cout << "========================================" << endl;
    cout << "Digite a opção desejada: ";
}

void SpaceCommand::menu() {
    int option;

    while (true) {
        showOptions();
        cin >> option;

        switch (option) {
            case 0:
                cout << "Programa encerrado." << endl;
                return;
            case 1:
                this->registerNewFlight();
                break;
            case 2:
                this->registerNewAstronaut();
                break;
            case 3:
                this->addAstronautToFlight();
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    }
}