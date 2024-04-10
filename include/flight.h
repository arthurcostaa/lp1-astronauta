#ifndef FLIGHT_H
#define FLIGHT_H

#include "astronaut.h"

class Flight {
private:
    int code;
    Astronaut* passengers;
    int numPassengers;
    bool inPlanning;
    bool inProgress;
    bool exploded;

public:
    Flight();
    Flight(int code, Astronaut* passengers);
    ~Flight();

    int getCode();
    void setCode(int code);

    Astronaut* getPassengers();
    void setPassengers(Astronaut* passengers);

    int getNumPassengers();

    bool isInPlanning();
    void setInPlanning(bool inPlanning);

    bool isInProgress();
    void setInProgress(bool inProgress);

    bool isExploded();
    void setExploded(bool exploded);
};

#endif // FLIGHT_H