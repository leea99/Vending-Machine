#include <iostream>
#include <string>
#include <iomanip>  
using namespace std;

struct Candy 
{
	string name[5];
	double price[5];
	int stock[5];	
};

void fillCart(Candy&);
void displayItems(Candy);
void customerInfo(Candy, int *, int *);
double displayBill(Candy, int *, int *);
double payBill(double);
void changeDue(double, double);
void inventory(Candy, int *, int *);

int main()
{
    Candy candyCart; //The structure
    int item, amount; //item = num selected | amount = amount the customer wants
    double total, amountPaid; //total = total that needs to be paid | amountPaid = amount the customer paid
    char repeat;

    fillCart(candyCart);
    displayItems(candyCart);
    
    do
	{
    customerInfo(candyCart, &item, &amount);
    inventory(candyCart, &item, &amount);
    total = displayBill(candyCart, &item, &amount);
    amountPaid = payBill(total);
    changeDue(total, amountPaid);
    
    cout << "Would you like to make another purchase? Type y for yes" << endl;
    cin >> repeat;
    cout << endl;
	}
	while (repeat == 'y' || repeat == 'Y');
	
	system("pause");
    return 0;
}

void fillCart(Candy &candyCart)   //This functions loads the candy type, price, and intial stock
{
	candyCart.name[0] = "Kit Kats";
	candyCart.name[1] = "Milky Ways";
	candyCart.name[2] = "M&M's";
	candyCart.name[3] = "Skittles";
	candyCart.name[4] = "Snickers";
	
	candyCart.price[0] = 1.00;
	candyCart.price[1] = 1.25;
	candyCart.price[2] = 1.00;
	candyCart.price[3] = .75;
	candyCart.price[4] = 1.00;
	
	candyCart.stock[0] = 8;
	candyCart.stock[1] = 10;
	candyCart.stock[2] = 7;
	candyCart.stock[3] = 4;
	candyCart.stock[4] = 7;
}

void displayItems (Candy candyCart) //Displays the items for sale
{
	const int MAX = 4;
	int i;
	
	cout << "Welcome to the Candy Cart!" << endl << "The items for sale are: " << endl;
	cout << setprecision(2) << fixed;
	
	for(i = 0; i <= MAX; i++)  //Displays the items for sale and their prices
	{
	cout << candyCart.name[i] << "..... $" << candyCart.price[i] << endl;	
	}
	
	cout << endl;	
}

void customerInfo(Candy candyCart, int *item, int *amount)  //Asks the user what they would like to buy and how much
{
	cout << "What would you like to buy? Type:" << endl;
	cout << "1 for Kit-Kat" << endl << "2 for Milky Way" << endl;
	cout << "3 for M&Ms" << endl << "4 for Skittles" << endl << "5 for Snickers" << endl;
	cin >> *item;
	while (*item < 1 || *item > 5)
	{
	cout <<	"Please enter an option listed" << endl;
	cin >> *item;
	}
	
	cout << endl << "How many would you like?" << endl;
	cin >> *amount;
	while (*amount < 1)
	{
		cout << "Please enter a number greater than zero" << endl;
		cin >> *amount;
	}
	
}

double displayBill(Candy candyCart, int *item, int *amount)  //Calculates and displays the users bill
{
	double total;
	
	if (*item == 1)
		total = candyCart.price[0] * *amount;
	else if (*item == 2)
		total = candyCart.price[1] * *amount;
	else if (*item == 3)
		total = candyCart.price[2] * *amount;
	else if (*item == 4)
		total = candyCart.price[3] * *amount;	
	else
		total = candyCart.price[4] * *amount;
		
	cout << "Your total is : $" << total << endl << endl;
	return total;
}

double payBill(double total) //Shows how much the user will have to pay
{
	double amountPaid;
	
	cout << "Please enter your payment amount:" << endl;
	cin >> amountPaid;
	cout << endl;	
	
	while (amountPaid < total)
	{
		cout <<"Your payment must be at least as much as the total" << endl;
		cin >> amountPaid;
		cout << endl;
	}
	return amountPaid;
}

void changeDue(double total, double amountPaid) //Displays the change due to the customer
{
	double change;
	
	change = amountPaid - total;
	cout << "Your change is: $" << change << endl; 
}

void inventory (Candy candyCart, int *item, int *amount)
{
	int originalStock = candyCart.stock[0];				//Variables hold copy of stock incase the user enters an amount that would be below the current stock
	int originalStock1 = candyCart.stock[1];
	int originalStock2 = candyCart.stock[2];
	int originalStock3 = candyCart.stock[3];
	int originalStock4 = candyCart.stock[4];
	
	if (*item == 1)
	{
		candyCart.stock[0] = candyCart.stock[0] - *amount;				//Gets the stock that would remain after the users purchases
		
		if (candyCart.stock[0] < 0)										//Prevents the user from buying more items than there are stock
		{			
			cout << endl << "This would put us out of stock." << endl;
			cout << "There is currently " << candyCart.stock[0] + *amount << " " << candyCart.name[0] << " in stock. ";
			
			while (candyCart.stock[0] < 0)
			{
				cout << "Please enter a number less than or equal to the stock." << endl;
				cin >> *amount;
				cout << endl;
				
				candyCart.stock[0] = originalStock - *amount;
			}
		}
	}

	else if (*item == 2)
	{
		candyCart.stock[1] = candyCart.stock[1] - *amount;				//Gets the stock that would remain after the users purchases
		
		if (candyCart.stock[1] < 0)										//Prevents the user from buying more items than there are stock
		{			
			cout << endl << "This would put us out of stock." << endl;
			cout << "There is currently " << candyCart.stock[1] + *amount << " " << candyCart.name[1] << " in stock. ";
			
			while (candyCart.stock[1] < 0)
			{
				cout << "Please enter a number less than or equal to the stock." << endl;
				cin >> *amount;
				cout << endl;
				
				candyCart.stock[1] = originalStock1 - *amount;
			}
		}
	}
	else if (*item == 3)
	{
		candyCart.stock[2] = candyCart.stock[2] - *amount;				//Gets the stock that would remain after the users purchases
		
		if (candyCart.stock[2] < 0)										//Prevents the user from buying more items than there are stock
		{			
			cout << endl << "This would put us out of stock." << endl;
			cout << "There is currently " << candyCart.stock[2] + *amount << " " << candyCart.name[2] << " in stock. ";
			
			while (candyCart.stock[2] < 0)
			{
				cout << "Please enter a number less than or equal to the stock." << endl;
				cin >> *amount;
				cout << endl;
				
				candyCart.stock[2] = originalStock2 - *amount;
			}
		}
	}
	else if (*item == 4)
	{
		candyCart.stock[3] = candyCart.stock[3] - *amount;				//Gets the stock that would remain after the users purchases
		
		if (candyCart.stock[3] < 0)										//Prevents the user from buying more items than there are stock
		{			
			cout << endl << "This would put us out of stock." << endl;
			cout << "There is currently " << candyCart.stock[3] + *amount << " " << candyCart.name[3] << " in stock. ";
			
			while (candyCart.stock[3] < 0)
			{
				cout << "Please enter a number less than or equal to the stock." << endl;
				cin >> *amount;
				cout << endl;
				
				candyCart.stock[3] = originalStock3 - *amount;
			}
		}
	}
	else
	{
		candyCart.stock[4] = candyCart.stock[4] - *amount;				//Gets the stock that would remain after the users purchases
		
		if (candyCart.stock[4] < 0)										//Prevents the user from buying more items than there are stock
		{			
			cout << endl << "This would put us out of stock." << endl;
			cout << "There is currently " << candyCart.stock[4] + *amount << " " << candyCart.name[4] << " in stock. ";
			
			while (candyCart.stock[4] < 0)
			{
				cout << "Please enter a number less than or equal to the stock." << endl;
				cin >> *amount;
				cout << endl;
				
				candyCart.stock[4] = originalStock4 - *amount;
			}
		}
	}
}





