// CommifyCodingChallenge.cpp
#include "CommifyCodingChallenge.h"
#include <iostream>
#include <vector>
using namespace std;
//function to compare the list of items to the users list by returning each value
char PricingRules::GetItem(int i)
{
	return ItemList[i];
}

//function to compare the users list to the prices by returning each value
int PricingRules::GetPrice(int p)
{
	return PriceList[p];
}

//This function works out the price of all the values as well as calling the necessary functions to work out the discounts the user may have
int PricingRules::ApplyDiscount(int a, int b, int c, int d) {

	ThreeFor150(a);
	TwoFor45(b);
	DiscountApplyed = DiscountApplyed + c * PriceList[2];
	DiscountApplyed = DiscountApplyed + d * PriceList[3];

	return DiscountApplyed;
}

void PricingRules::ThreeFor150(int a) {
	while (a != 0) {
		//if a is divisable by 3 then calculates the discount needed in this case it is 3 lots of "a" for 150
		if (a % 3 == 0) {
			for (int i = a; i > 0; i = i - 3) {
				DiscountApplyed = DiscountApplyed + 150;
				a = a - 3;
			}
		}
		else {
			DiscountApplyed = DiscountApplyed + PriceList[0];
			a--;
		}
	}
}
//Works out the two for 45 discount on item b
void PricingRules::TwoFor45(int b) {
	while (b != 0) {
		//if b is divisable by 2 (even number), works out whether the basket is due for this discount and then adds the relevent amount to the total while making sure the number of "b" doesnt get added 
		if (b % 2 == 0)
		{
			for (int i = b; i > 0; i = i - 2) {
				DiscountApplyed = DiscountApplyed + 45;
				b = b - 2;
			}
		}
		else {
			DiscountApplyed = DiscountApplyed + PriceList[1];
			b--;
		}
	}
}

//Adds items to the basket vector
void Checkout::Scan(char x)
{
	Basket.push_back(x);
}
//This function calculates the total price of all the items the user has selected which includes the discounts
void Checkout::CalculateTotalPrice() {
	for (int i = 0; i < 4; i++) {
		DiscountBasket.push_back(0);
	}
	//for loop and switch/case to search through the entered items and determine the number of each items so the discounts can be calculated
	for (int i = 0; i < Basket.size(); i++) {
		switch (Basket[i])
		{
		case 'a':
			DiscountBasket.at(0) = DiscountBasket.at(0) + 1;
			break;
		case 'b':
			DiscountBasket.at(1) = DiscountBasket.at(1) + 1;
			break;
		case 'c':
			DiscountBasket.at(2) = DiscountBasket.at(2) + 1;
			break;
		case 'd':
			DiscountBasket.at(3) = DiscountBasket.at(3) + 1;
			break;
		default:
			break;
		}
	}
	//works out the total price of all the items as well as the discounts
	Total = Total + Discount.ApplyDiscount(DiscountBasket[0], DiscountBasket[1], DiscountBasket[2], DiscountBasket[3]);

	cout << "The total price of your order is : " << Total << endl;
}