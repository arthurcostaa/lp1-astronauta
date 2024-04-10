#ifndef ASTRONAUT_H
#define ASTRONAUT_H

#include <string>

using namespace std;

class Astronaut {
private:
    string cpf;
    string name;
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

    bool isAvailable();
    void setAvailable(bool available);

    bool isAlive();
    void setAlive(bool alive);
};

#endif // ASTRONAUT_H