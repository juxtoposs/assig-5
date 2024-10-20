#include <iostream>
#include <vector>
#include <iomanip> // for setting output formatting

using namespace std;

// Structure to hold product details
struct Product {
    int id;
    string name;
    int quantity;
    int sold;
};

// Function to display the inventory and sales report
void displayReport(const vector<Product>& products) {
    int totalSales = 0;
    cout << left << setw(12) << "Product ID" 
         << setw(12) << "Name" 
         << setw(12) << "Quantity" 
         << setw(18) << "Sold This Month" << endl;
    cout << "----------------------------------------------------------" << endl;

    // Loop through the products and display their information
    for (const auto& product : products) {
        cout << left << setw(12) << product.id 
             << setw(12) << product.name 
             << setw(12) << product.quantity 
             << setw(18) << product.sold << endl;
        totalSales += product.sold * 100; // Assuming each item sold for $100
    }

    cout << "----------------------------------------------------------" << endl;
    cout << "Total Sales: $" << totalSales << endl;
}

// Function to display remaining inventory for a specific product
void displayRemainingInventory(const Product& product) {
    cout << "Remaining Inventory for Product " << product.id << ": " 
         << (product.quantity - product.sold) << endl;
}

int main() {
    // Sample inventory
    vector<Product> products = {
        {101, "Laptops", 50, 30},
        {102, "Phones", 75, 50},
        // Add more products if needed
    };

    // Display the sales report
    displayReport(products);

    // Display remaining inventory for a specific product (e.g., product with id 101)
    displayRemainingInventory(products[0]);

    return 0;
}
