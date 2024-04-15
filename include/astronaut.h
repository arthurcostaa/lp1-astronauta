#ifndef ASTRONAUT_H
#define ASTRONAUT_H

#include <string>
#include <vector>

using namespace std;

class Astronaut {
private:
    string cpf;
    string name;
    vector<int> missionsFlown;
    int age;
    bool available;
    bool alive;

public:
    Astronaut();
    Astronaut(string cpf, string name, int age);
    ~Astronaut();

    string getCpf();
    void setCpf(string cpf);

    string getName();
    void setName(string name);

    int getAge();
    void setAge(int age);

    vector<int>& getMissionsFlown();

    bool isAvailable();
    void setAvailable(bool available);

    bool isAlive();
    void setAlive(bool alive);

    bool addCodeFlight(int newCode);

    void showCodeFlights();
};

#endif // ASTRONAUT_H