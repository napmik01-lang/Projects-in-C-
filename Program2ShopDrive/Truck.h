#ifndef TRUCK_H_INCLUDED
#define TRUCK_H_INCLUDED

#include "vehicle.h"

class Truck : public Vehicle {

    /** Atributes **/
    private:
        string make;
        string model;
        int miles;
        double price;
        string engine;

    public:
        Truck(string Ma, string Mo, int Mi, int Pr, string Eng);

        Truck();

        void setInformation(string Ma, string Mo, int Mi, int Pr, string Eng);

        bool checkMake(string Ma);
        bool checkModel(string Mo);
        bool checkMiles(int Mi);
        bool checkPrice(int Pr);

        void printInformation();




};

#endif // TRUCK_H_INCLUDED
