#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include <iostream>

using namespace std;

class Vehicle {

    /** Atributes **/
    private:
        string make;
        string model;
        int miles;
        double price;

    public:
        Vehicle(string Ma, string Mo, int mi, double pr);

        Vehicle();

        void setInformation(string Ma, string Mo, int Mi, double Pr);



        void printInformation();




};

#endif // VEHICLE_H_INCLUDED
