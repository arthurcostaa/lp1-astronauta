#ifndef FLIGHT_H
#define FLIGHT_H

#include <vector>

#include "astronaut.h"

class Flight {
private:
    int code;
    vector<Astronaut*> passengers;
    bool inPlanning;
    bool inProgress;
    bool exploded;

public:
    Flight();
    Flight(int code);
    ~Flight();

    int getCode();
    void setCode(int code);

    vector<Astronaut*> getPassengers();

    bool isInPlanning();
    void setInPlanning(bool inPlanning);

    bool isInProgress();
    void setInProgress(bool inProgress);

    bool isExploded();
    void setExploded(bool exploded);

    int getNumPassengers();

    bool addAstronaut(Astronaut* astronaut);

    bool removeAstronaut(string cpf);

    bool launch();

    bool explode();
};

#endif // FLIGHT_H