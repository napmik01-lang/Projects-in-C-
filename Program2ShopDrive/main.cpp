#include <iostream>

#include "vehicle.h"
#include "sedan.h"
#include "Truck.h"



using namespace std;



int main()
{
    Vehicle vehicle[3]; // Base Class
    Sedan Sedan[3]; // Class for Sedans
    Truck Truck[3]; // Class for Trucks

    int whichTest; // Variable to determine search type
    string checkTest; // Variable For Make and Model checks
    int integerCheckTest; // Variable for Miles and Price checks


    Sedan[0].setInformation("Toyota", "Camry", 35348, 20597.00, "yes"); // Sets information for Sedans
    Sedan[1].setInformation("Lexus", "ES", 55609, 4693.00, "yes");
    Sedan[2].setInformation("Honda", "Accord", 22987, 11768.00, "no");

    Truck[0].setInformation("Toyota", "Tundra", 34271, 68058.00, "V6"); // Sets information for Trucks
    Truck[1].setInformation("Ford", "F-150", 55609, 9785.00, "V8");
    Truck[2].setInformation("Nissan", "Titan", 33990, 2677.00, "V6");

        cout << "*************Search Menu *************" << endl; // print out selection options
        cout << "Search Make . . . . . . . . . .Press 1" << endl;
        cout << "Search Model. . . . . . . . . .Press 2" << endl;
        cout << "Search Miles. . . . . . . . . .Press 3" << endl;
        cout << "Search Price. . . . . . . . . .Press 4" << endl;

        cout << endl;

        cout << "Select option: "; // prompt for search type

        cin >> whichTest;

        cout << endl;

        cout << "Enter Search Text: "; // prompt for check type
        if (whichTest == 1 || whichTest == 2) {
            cin >> checkTest; // String Variable for Make and Model
        }
        else {
            cin >> integerCheckTest; // Integer Variable for Miles and Price
        }
        if (whichTest == 1) { // Check for Miles
            for (int i = 0; i < 3; i++) {
                if (Sedan[i].checkMake(checkTest) == true){ // Sedan Check
                    Sedan[i].printInformation();
                    cout << endl;
                }
            }

            for (int i = 0; i < 3; i++) {
                if (Truck[i].checkMake(checkTest) == true){ // Truck Check
                    Truck[i].printInformation();
                    cout << endl;
                }
            }
        }
        else if (whichTest == 2) {  // Check for Model
            for (int i = 0; i < 3; i++) {
                if (Sedan[i].checkModel(checkTest) == true){ // Sedan Check
                    Sedan[i].printInformation();
                    cout << endl;
                }
            }

            for (int i = 0; i < 3; i++) {
                if (Truck[i].checkModel(checkTest) == true){// Truck Check
                    Truck[i].printInformation();
                    cout << endl;
                }
            }
        }
        else if (whichTest == 3) {  // Check for Miles
            for (int i = 0; i < 3; i++) {
                if (Sedan[i].checkMiles(integerCheckTest) == true){ // Sedan Check
                    Sedan[i].printInformation();
                    cout << endl;
                }
            }

            for (int i = 0; i < 3; i++) {
                if (Truck[i].checkMiles(integerCheckTest) == true){// Truck Check
                    Truck[i].printInformation();
                    cout << endl;
                }
            }
        }
        else if (whichTest == 4) {  // Check for Price
            for (int i = 0; i < 3; i++) {
                if (Sedan[i].checkPrice(integerCheckTest) == true){ // Sedan Check
                    Sedan[i].printInformation();
                    cout << endl;
                }
            }

            for (int i = 0; i < 3; i++) {
                if (Truck[i].checkPrice(integerCheckTest) == true){// Truck Check
                    Truck[i].printInformation();
                    cout << endl;
                }
            }
        }






/**
    checkTest = Sedan[0].checkMake("Toyota");
        cout << checkTest << endl;
    checkTest = Sedan[0].checkModel("Camry");
        cout << checkTest << endl;
    checkTest = Sedan[0].checkMiles(35348);
        cout << checkTest << endl;
    checkTest = Sedan[0].checkPrice(20597.00);
        cout << checkTest << endl;


    checkTest = Truck[0].checkMake("Toyota");
        cout << checkTest << endl;
    checkTest = Truck[0].checkModel("Camry");
        cout << checkTest << endl;
    checkTest = Truck[0].checkMiles(35348);
        cout << checkTest << endl;
    checkTest = Truck[0].checkPrice(20597.00);
        cout << checkTest << endl;

    for (int i = 0; i < 3; i++) {

         Sedan[i].printInformation();
         cout << endl;

    }



    for (int i = 0; i < 3; i++) {

         Truck[i].printInformation();
         cout << endl;


    }


**/
    return 0;
}
