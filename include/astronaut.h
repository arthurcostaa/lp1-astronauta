#ifndef ASTRONAUT_H
#define ASTRONAUT_H

#include <string>
#include <list>

using namespace std;

class Astronaut {
private:
    string cpf;
    string name;
    list<int> missionsFlown;
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

    list<int>& getMissionsFlown();

    bool isAvailable();
    void setAvailable(bool available);

    bool isAlive();
    void setAlive(bool alive);

    void addCodeFlight(int newCode);

    void showCodeFlights();

    friend ostream& operator<<(ostream &o, Astronaut* const a);
};

#endif // ASTRONAUT_H