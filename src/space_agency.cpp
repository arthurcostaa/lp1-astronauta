#include <iostream>
#include <string>

#include "astronaut.h"
#include "flight.h"
#include "space_agency.h"
#include "space_command.h"

using namespace std;

SpaceAgency::SpaceAgency() {
    this->spaceCommand = new SpaceCommand();
}

SpaceAgency::~SpaceAgency() {
    delete this->spaceCommand;
}

void SpaceAgency::showOptions() {
    cout << "1. Cadastrar astronauta" << endl;
    cout << "2. Cadastrar voo" << endl;
    cout << "3. Adicionar astronauta em um voo" << endl;
    cout << "4. Remover astronauta de um voo" << endl;
    cout << "5. Lançar um voo" << endl;
    cout << "6. Finalizar um voo" << endl;
    cout << "7. Explodir um voo" << endl;
    cout << "8. Mostrar todos os voos" << endl;
    cout << "9. Listar astronautas" << endl;
    cout << "10. Listar astronautas mortos" << endl;
    cout << "0. Encerrar programa" << endl;
}

void SpaceAgency::createAstronaut() {
    string cpf, name;
    int age;
    Astronaut* astronaut;

    cin.ignore();
    cout << "Digite o nome do astronauta: ";
    getline(cin, name);
    cout << "Digite o cpf do astronauta: ";
    cin >> cpf;
    cout << "Digite a idade do astronauta: ";
    cin >> age;

    astronaut = new Astronaut(cpf, name, age);

    if (spaceCommand->registerNewAstronaut(astronaut)) {
        cout << endl << "Astronauta registrado com sucesso." << endl << endl;
    } else {
        cout << endl << "Erro ao registrar astronauta." << endl << endl;
    }
}

void SpaceAgency::createFlight() {
    int code;
    Flight* flight;

    cout << "Digite o código do voo: ";
    cin >> code;

    flight = new Flight(code);

    if (spaceCommand->registerNewFlight(flight)) {
        cout << endl << "Voo registrado com sucesso." << endl << endl;
    } else {
        cout << endl << "Erro ao registrar voo." << endl << endl;
    }
}

void SpaceAgency::addAstronautToFlight() {
    int code;
    string cpf;

    cout << "Digite o código do voo: ";
    cin >> code;
    cout << "Digite o cpf do astronauta: ";
    cin >> cpf;

    if (spaceCommand->addAstronautToFlight(code, cpf)) {
        cout << endl << "Astronauta adicionado ao voo com sucesso." << endl << endl;
    } else {
        cout << endl << "Erro ao adicionar astronauta em voo." << endl << endl;
    }
}

void SpaceAgency::removeAstronatFromFlight() {
    int code;
    string cpf;

    cout << "Digite o código do voo: ";
    cin >> code;
    cout << "Digite o cpf do astronauta: ";
    cin >> cpf;

    if (spaceCommand->removeAstronautFromFlight(code, cpf)) {
        cout << endl << "Astronauta removido do voo com sucesso." << endl << endl;
    } else {
        cout << endl << "Erro ao remover astronauta do voo." << endl << endl;
    }
}

void SpaceAgency::launchFlight() {
    int code;

    cout << "Digite o código do voo: ";
    cin >> code;

    if (spaceCommand->lauchFlight(code)) {
        cout << endl << "Voo lançado com sucesso." << endl << endl;
    } else {
        cout << endl << "Erro ao lançar voo." << endl << endl;
    }
}

void SpaceAgency::finishFlight() {
    int code;

    cout << "Digite o código do voo: ";
    cin >> code;

    if (spaceCommand->finishFlight(code)) {
        cout << endl << "Voo finalizado com sucesso." << endl << endl;
    } else {
        cout << endl << "Erro ao finalizar voo." << endl << endl;
    }
}

void SpaceAgency::explodeFlight() {
    int code;

    cout << "Digite o código do voo: ";
    cin >> code;

    if (spaceCommand->explodeFlight(code)) {
        cout << endl << "Voo explodido com sucesso." << endl << endl;
    } else {
        cout << endl << "Erro ao explodir voo." << endl << endl;
    }
}

void SpaceAgency::run() {
    cout << "SEJA BEM-VINDO AO SISTEMA DE GERENCIAMENTO DE ASTRONAUTAS E VOOS ESPACIAIS" << endl << endl;

    int option;

    while (true) {
        showOptions();
        cout << endl << "Digite a opção desejada: ";
        cin >> option;

        switch (option) {
            case 0:
                cout << endl << "Encerrando o programa" << endl;
                return;
            case 1:
                createAstronaut();
                break;
            case 2:
                createFlight();
                break;
            case 3:
                addAstronautToFlight();
                break;
            case 4:
                removeAstronatFromFlight();
                break;
            case 5:
                launchFlight();
                break;
            case 6:
                finishFlight();
                break;
            case 7:
                explodeFlight();
                break;
            case 8:
                spaceCommand->showFlights();
                cout << endl;
                break;
            case 9:
                spaceCommand->showAstronauts();
                break;
            case 10:
                cout << endl;
                spaceCommand->showDeadAstronauts();
                cout << endl;
                break;
            default:
                cout << endl << "Opção inválida. Tente novamente." << endl << endl;
                break;
        }
    }
}