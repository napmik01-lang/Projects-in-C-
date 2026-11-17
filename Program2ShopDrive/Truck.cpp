#include "Truck.h"

Truck::Truck(string Ma, string Mo, int Mi, int Pr, string Eng) {

            make = Ma;
            model = Mo;
            miles = Mi;
            price = Pr;
            engine = Eng;
}

Truck::Truck() {}





        void Truck::setInformation(string Ma, string Mo, int Mi, int Pr, string Eng) { // Sets up data in objects
            make = Ma;
            model = Mo;
            miles = Mi;
            price = Pr;
            engine = Eng;
        }

        bool Truck::checkMake(string Ma) { // Check Truck for Make
            if (make == Ma) {

                return true;
            }
            else {

                return false;
            }
        }

        bool Truck::checkModel(string Mo) {// Check Truck for Model
            if (model == Mo) {

                return true;
            }
            else {

                return false;
            }
        }

        bool Truck::checkMiles(int Mi) {// Check Truck for Miles
            if (miles <= Mi) {

                return true;
            }
            else {

                return false;
            }
        }

        bool Truck::checkPrice(int Pr) { // Check Truck for Price
            if (price <= Pr) {

                return true;
            }
            else {

                return false;
            }
        }

        void Truck::printInformation() { // prints applicable information
            cout << "Make: " << make << endl;
            cout << "Model: " << model << endl;
            cout << "Miles: " << miles << endl;
            cout << "Price: $" << price << endl;
            cout << "Engine: " << engine << endl;
        }