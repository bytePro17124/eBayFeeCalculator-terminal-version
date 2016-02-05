#include <iostream>
#include <cmath>
#include <string>
#include <limits> 

float calculate_Ebay_Fees(const float& finalprice, const float& shippingprice);
float calculate_Paypal_Fees(const float& finalprice, const float& shippingprice);
char getYorN(const std::string&);

const float EBAYCUT = .10;


int main () {
	
	using namespace std;
	
	float final_sale_price(0), shipping_price(0), shipping_cost(0), ebay_fees(0), paypal_fees(0);
	bool go = true;
	char option = '0';
	
	while (go) {
		
		cout << "What is the final price of your item? -> ";
		cin >> final_sale_price;
		cout << "How much did you charge for Shipping? -> ";
		cin >> shipping_price;
		cout << "What did shipping actually cost? -> ";
		cin >> shipping_cost;
		
		ebay_fees = calculate_Ebay_Fees(final_sale_price, shipping_price);
		paypal_fees = calculate_Paypal_Fees(final_sale_price, shipping_price);
		
		cout << "\n ->Amount Buyer Paid: " << final_sale_price + shipping_price << endl;
		
		cout << " ->Shipping you Paid: -" << shipping_cost << endl;
		
		cout << " ->Total eBay and PP fees: -" << ebay_fees + paypal_fees << endl;
		
		cout << " ->Profit Made: ** $" << (final_sale_price + shipping_price) - (ebay_fees + paypal_fees + shipping_cost) << " **\n\n";

		option = getYorN("Enter another Item? (y/n) -> ");
		if (option == 'Y') go = true;
		if (option == 'N') go = false;
		
	}
	
	cout << "\n keep on selling, keep on smelling\n\nGoodbye!\n\n";
}


float calculate_Ebay_Fees(const float& finalprice, const float& shippingprice) {
	float ebayfees;
	if (finalprice+shippingprice <= 7500){
		ebayfees = (finalprice + shippingprice) * EBAYCUT;
	} else {
		ebayfees = (7500) * EBAYCUT;
	}
	
	return ebayfees;
}

float calculate_Paypal_Fees(const float& finalprice, const float& shippingprice) {
	
	float paypalfees = .30  + ((finalprice + shippingprice) * .03);

	return paypalfees;
}

char getYorN(const std::string& message) {
    char tmp;
    do
    {
        std::cout << message;
        std::cin >> tmp;
        tmp = toupper(tmp);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!(tmp == 'Y' || tmp == 'N'))
            std::cout << "Invalid, Try again (only takes 'Y', 'N', 'y', or 'n')\n";

    } while (!(tmp == 'Y' || tmp == 'N'));
    return tmp;
}