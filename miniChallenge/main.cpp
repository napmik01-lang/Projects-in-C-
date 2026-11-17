#include <iostream>

#include <stack>

using namespace std;
void decimalToBinary(int number);

int main() {
   int num;
   cout << "Enter a number: "; // text
   cin >> num; // take in number
   decomalToBinary(num); // cal funct
   return 0;
}

void decimalToBinary(int number) {
   stack<int> stack; // create stack

   while(number > 0) { // until decimal number is converted
      int rem = number % 2; //take remainder
      number = number / 2; // divide by 2
      stack.push(rem); // push to stack

   } // once decimal number is converted into binary numbers
   while(!stack.empty()) { // until stack is empty
      int item; // define var
      item = stack.top(); // pull item from top
      stack.pop(); // delete top item
      cout << item; // print item
   }
}