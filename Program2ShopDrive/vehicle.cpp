#include "vehicle.h"

Vehicle::Vehicle(string Ma, string Mo, int mi, double pr) {

            make = Ma;
            model = Mo;
            miles = mi;
            price = pr;

}

Vehicle::Vehicle() {}





        void Vehicle::setInformation(string Ma, string Mo, int Mi, double Pr) { // Sets up data for later (non-Sedan or Truck)
            make = Ma;
            model = Mo;
            miles = Mi;
            price = Pr;
        }


        void Vehicle::printInformation() { // prints applicable information
            cout << "Make: " << make << endl;
            cout << "Model: " << model << endl;
            cout << "Miles: " << miles << endl;
            cout << "Price: " << price << endl;
        }