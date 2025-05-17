/******************************************************************************
# Author:            Ari P.
# Assignment:        Assignment 6
# Date:              May 17, 2025
# Description:       This program will accept coins from the user, then allow
                     them to purchase coffee or tea in the quantity of their
                     choice.
# Input:             coin (int), quantity (int), selection (char)
# Output:            balance (double), cost (double)
# Sources:           Assignment 6 specifications, zyBooks reference,
                     geeksforgeeks.org
#*****************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   // Declare and initialize constant variables for calculation
   const int NICKEL = 5;
   const int DIME = 10;
   const int QUARTER = 25;
   const double COST_COFFEE = 0.25;
   const double COST_TEA = 0.25;

   // Declare variables for input, output, and calculation
   int coin = 0;
   char selection = ' ';
   int quantity = 0;
   double cost = 0.00;
   double balance = 0.00;

   // Set floating point precision to 2 decimal places for output
   cout << fixed << setprecision(2);

   // Print a welcome message
   cout << "Welcome to the Coffee/Tea Vending Machine. We’ll take your coins \
and let you buy any amount of coffee or tea! Enter 0 to finish inserting \
change.";
   cout << endl << endl;

   // Enter main program loop
   do {
      // Get input from the user
      do {
         cout << "Enter a coin (5, 10, or 25): ";
         cin >> coin;
         // Perform input validation
         while (cin.fail() || (coin != NICKEL && coin != DIME && coin != \
QUARTER && coin != 0)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid option! Please try again." << endl;
            cout << "Enter a coin (5, 10, or 25): ";
            cin >> coin;
         }
         // Update accumulator
         balance += static_cast<double>(coin) / 100;
      } while (coin != 0);
      cout << endl;
      cout << "Your balance is $" << balance;
      cout << endl << endl;
      
      // Display options for the user to buy
      cout << "Here's our selection! Both drinks cost $0.25" << endl;
      cout << setfill('~') << setw(60) << "" << endl << setfill(' ');
      cout << setw(5) << left << "" << right << "* Coffee (C/c)" << endl;
      cout << setw(5) << left << "" << right << "* Tea (T/t)" << endl;
      cout << setw(5) << left << "" << right << "* Quit (Q/q)" << endl;
      cout << setfill('~') << setw(60) << "" << endl << setfill(' ');

      // Get the user's selection
      cout << "Enter your choice: ";
      cin >> selection;
      // Perform input validation
      while (cin.fail() || (selection != 'C' && selection != 'c' && selection \
!= 'T' && selection != 't' && selection != 'Q' && selection != 'q')) {
         cin.clear();
         cin.ignore(100, '\n');
         cout << "Invalid option! Please try again." << endl;
         cout << "Enter your choice: ";
         cin >> selection;
      }

      // Only continue if the user didn't quit
      if (selection != 'Q' && selection != 'q') {
         cout << "You've selected ";
         if (selection == 'C' || selection == 'c') {
            cout << "coffee.";
         }
         else {
            cout << "tea.";
         }
         cout << endl;
         // Get quantity from the user
         cout << "How many would you like? ";
         cin >> quantity;
         while (cin.fail() || quantity == 0) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid option! Please try again." << endl;
            cout << "How many would you like? ";
            cin >> quantity;
         }
         cout << endl;

         // Calculate the total cost
         if (selection == 'C' || selection == 'c') {
            cost = static_cast<double>(quantity) * COST_COFFEE;
         }
         else {
            cost = static_cast<double>(quantity) * COST_TEA;
         }

         // If the user doesn't have enough change, loop back so they can
         // enter more.
         if (balance - cost < 0.00) {
            cout << "Your total is $" << cost << endl;
            cout << "Your balance is $" << balance << endl;
            cout << "Not enough change! Please enter more coins!";
            cout << endl << endl;
         }
         else {
            balance -= cost;
            selection = 'Q';
         }
      }
   } while (selection != 'Q' && selection != 'q');

   // Display the user's total and new balance
   cout << "Your total is $" << cost << endl;
   cout << "Your new balance is $" << balance;
   cout << endl << endl;

   // Print a goodbye message
   cout << "Thank you for using the Coffee/Tea Vending Machine!" << endl;
   return 0;
}