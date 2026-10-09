#include <iostream>
#include <string>
using namespace std;
// Calculates the total price for a given quantity.
double calculateTotal(double unitPrice, int quantity)
{
    return unitPrice * quantity;
}

int main()
{
    // Product information
    const string productName = "Notebook";
    const double unitPrice = 45.50;
    const int quantity = 3;

    // Calculate the purchase total.
    const double totalCost = calculateTotal(unitPrice, quantity);

    // Display the purchase summary.
    cout << "=== Purchase Summary ===\n";
    cout << "Product: " << productName << '\n';
    cout << "Unit price: " << unitPrice << '\n';
    cout << "Quantity: " << quantity << '\n';
    cout << "Total cost: " << totalCost << '\n';

    return 0;
}