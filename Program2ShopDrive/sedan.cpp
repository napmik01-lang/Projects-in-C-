#include "sedan.h"

Sedan::Sedan(string Ma, string Mo, int mi, double pr, string is) {

            make = Ma;
            model = Mo;
            miles = mi;
            price = pr;
            isHybrid = is;
}

Sedan::Sedan() {}





        void Sedan::setInformation(string Ma, string Mo, int Mi, double Pr, string Is) { // Sets up data in objects
            make = Ma;
            model = Mo;
            miles = Mi;
            price = Pr;
            isHybrid = Is;
        }

        bool Sedan::checkMake(string Ma) { // Check Sedan for  Make
            if (make == Ma) {

                return true;
            }
            else {

                return false;
            }
        }

        bool Sedan::checkModel(string Mo) { // Check Sedan for Model
            if (model == Mo) {

                return true;
            }
            else {

                return false;
            }
        }

        bool Sedan::checkMiles(int Mi) { // Check Sedan for Miles
            if (miles <= Mi) {

                return true;
            }
            else {

                return false;
            }
        }

        bool Sedan::checkPrice(int Pr) { // Check Sedan for Price
            if (price <= Pr) {

                return true;
            }
            else {

                return false;
            }
        }


        void Sedan::printInformation() { // prints applicable information
            cout << "Make: " << make << endl;
            cout << "Model: " << model << endl;
            cout << "Miles: " << miles << endl;
            cout << "Price: $" << price << endl;
            cout << "Hybrid: " << isHybrid << endl;
        }