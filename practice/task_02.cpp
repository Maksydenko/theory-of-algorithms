#include <iostream>
using namespace std;

struct Node {
	string product;
	double price;
	Node* p;
};

Node* add(Node** top, int d, string product, double price);
Node* del(Node** top);

Node* add(Node** pend, int d, string product, double price) {
	Node* pv = new Node;
	pv->product = product;
	pv->price = price;
	pv->p = NULL;
	if (*pend)
		(*pend)->p = pv;
	*pend = pv;
	return pv;
}

Node* del(Node** pbeg) {
	Node* temp = *pbeg;
	Node* pv = *pbeg;
	*pbeg = (*pbeg)->p;
	delete pv;
	return temp;
}

int main() {
	string products[10]{ "Oranges", "Lemons", "Melons", "Apples", "Tomatoes", "Carrots", "Strawberries", "Cucumbers", "Cabbage", "Kiwi" };
	double prices[10]{ 1.5, 1, 1, 0.5, 3, 1, 7, 2, 1, 3 };
	Node* pend = NULL;
	Node* pbeg = add(&pend, 1, products[0], prices[0]);
	cout << "The client buys products of 2 kilograms. The cashier scans them:\n";
	cout << pbeg->product << " which costs " << pbeg->price << "$/kg\n";

	for (int i = 1; i < 6; i++)	{
		cout << products[i] << " which costs " << prices[i] << "$/kg\n";
		add(&pend, i, products[i], prices[i]);
	}
	cout << "\nThe buyer received such a check:\n";
	Node* pv = pbeg;
	double sum;

	while (pv) {
		double paid = pv->price * 2;
		sum = sum + paid;
		cout << pv->product << ": " << paid << "$\n";
		pv = pv->p;
	}
	cout << "Total: " << sum << "$";
	return 0;
}
