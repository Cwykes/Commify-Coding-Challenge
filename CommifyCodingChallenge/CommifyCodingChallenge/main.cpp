// CommifyCodingChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "CommifyCodingChallenge.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	//Objects declared from classes
	PricingRules OrderValues;
	Checkout Order;

	//Creates a loop that the program is run in
	bool Finish = false;
	while (Finish == false) {

		//Created variables for the users input
		char UserInput;
		char Option;

		cout << "\nEnter an item you would like to add to your basket (a,b,c,d): ";
		cin >> UserInput;

		//Uses the constant variable
		for (int i = 0; i < List; i++) {
			//if an item entered matches a value in the pre-determined item list
			if (OrderValues.GetItem(i) == UserInput) {

				Order.Scan(OrderValues.GetItem(i));

				while (true) {
					cout << "This item has been added to your basket, continue shopping? (y/n)";
					cin >> Option;

					if (Option == 'y') {
						break;
					}

					if (Option == 'n') {
						//Calls the calculation function that will add up the values of the items the user has entered including discounts
						Order.CalculateTotalPrice();
						Finish = true;
						break;
					}

				}

			}

		}

	}

}