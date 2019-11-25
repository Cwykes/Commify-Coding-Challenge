#pragma once
#pragma once

#include <vector>
using namespace std;

const int List = 4;

//Class called PricingRules contains the prices and discounts and provides them to be worked out by the Checkout class
class PricingRules
{
public:
	char GetItem(int i);
	int GetPrice(int p);

	//Functions that calculate discounts
	int ApplyDiscount(int a, int b, int c, int d);

	void TwoFor45(int b);
	void ThreeFor150(int a);


private:

	//Lists of items and respective prices
	char ItemList[List] = { 'a','b','c','d'};
	int PriceList[List] = { 60,30,30,25};

	int DiscountApplyed = 0;
};

//Class called Checkout that contains the items the user wants to buy as well as functions for calculating the total price
class Checkout
{
public:
	//Adds the users value to the "Basket" vector
	void Scan(char item);
	//function to calculate the total price of the users entered items
	void CalculateTotalPrice();

	//From Pricing Rules class
	PricingRules Discount;
private:

	char Item;
	int Price;
	//Vectors containing the items the user entered as well as the discounts used to calculate the users total
	vector <char> Basket;
	vector <int> DiscountBasket;

	int Total;
};
