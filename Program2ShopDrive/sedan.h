#ifndef SEDAN_H_INCLUDED
#define SEDAN_H_INCLUDED

#include "vehicle.h"

class Sedan : public Vehicle{

    /** Atributes **/
    private:
        string make;
        string model;
        int miles;
        double price;
        string isHybrid;

    public:
        Sedan(string Ma, string Mo, int mi, double pr, string is);

        Sedan();

        void setInformation(string Ma, string Mo, int Mi, double Pr, string Is);

        bool checkMake(string Ma);
        bool checkModel(string Mo);
        bool checkMiles(int Mi);
        bool checkPrice(int Pr);

        void printInformation();




};

#endif // SEDAN_H_INCLUDED
