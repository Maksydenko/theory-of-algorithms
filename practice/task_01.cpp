#include <iostream>
using namespace std;

struct Node
{
	string product;
	double price;
	Node* p;
};

void push(Node** top, string product);
void push(Node** top, double price);
void pop(Node** top);

void push(Node** top, string product, double price)
{
	Node* pv = new Node;
	pv->product = product;
	pv->price = price;
	pv->p = *top;
	*top = pv;
}

void pop(Node** top)
{
	Node* pv = *top;
	*top = (*top)->p;
	delete pv;
}

int main()
{
	Node* top;
	top = NULL;
	string products[10]{ "oranges", "lemons", "melons", "apples", "tomatoes", "carrots", "strawberries", "cucumbers", "cabbage", "kiwi" };
	double prices[10]{ 1.5, 1, 1, 0.5, 3, 1, 7, 2, 1, 3 };
	cout << "The store orders products for 100 kilograms:\n";

	for (int i = 0; i < 10; i++)
	{
		cout << "Put in the truck " << products[i] << " which costs " << prices[i] << "$/kg\n";
		push(&top, products[i], prices[i]);
	}
	Node* pv = top;
	cout << "\nGrocery being taken out of the truck:\n";
	double sum;

	while (top)
	{
		double paid = top->price * 100;
		sum = sum + paid;
		cout << "They take from it " << top->product << ". The store pays for it " << paid << "$\n";
		pop(&top);
	}
	cout << "Total: " << sum << "$";
	return 0;
}

