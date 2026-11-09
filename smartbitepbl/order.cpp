
#include "order.h"

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

struct CartItem
{
    Dish dish;
    int quantity;
};

void runOrderModule(
    const vector<Menu>& menus,
    const vector<Dish>& dishes,
    int restaurantId,
    const string& serviceName
)
{
    vector<Dish> availableDishes =
        getRestaurantMenu(menus, dishes, restaurantId);

    if (availableDishes.empty())
    {
        cout << "\nNo dishes available at this restaurant.\n";
        return;
    }

    vector<CartItem> cart;

    int choice;
    int quantity;

    cout << "\n========== SMARTBITE ORDER ==========\n";
    cout << "Service: " << serviceName << "\n";

    cout << "\n-------------- MENU -----------------\n";

    cout << fixed << setprecision(2);

    for (size_t i = 0; i < availableDishes.size(); i++)
    {
        cout << "Dish ID: " << availableDishes[i].id
             << " | " << availableDishes[i].name
             << " | Rs. " << availableDishes[i].price
             << " | "
             << (availableDishes[i].vegetarian ? "Veg" : "Non-Veg")
             << "\n";
    }

    cout << "\nEnter 0 when you finish ordering.\n";

    while (true)
    {
        cout << "\nEnter Dish ID: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 0)
            break;

        int dishIndex = -1;

        for (size_t i = 0; i < availableDishes.size(); i++)
        {
            if (availableDishes[i].id == choice)
            {
                dishIndex = static_cast<int>(i);
                break;
            }
        }

        if (dishIndex == -1)
        {
            cout << "Invalid Dish ID. Please try again.\n";
            continue;
        }

        cout << "Enter quantity: ";

        if (!(cin >> quantity))
        {
            cout << "Invalid quantity. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (quantity <= 0)
        {
            cout << "Quantity must be greater than zero.\n";
            continue;
        }

        bool alreadyAdded = false;

        for (size_t i = 0; i < cart.size(); i++)
        {
            if (cart[i].dish.id == choice)
            {
                cart[i].quantity += quantity;
                alreadyAdded = true;
                break;
            }
        }

        if (!alreadyAdded)
        {
            CartItem item;
            item.dish = availableDishes[dishIndex];
            item.quantity = quantity;

            cart.push_back(item);
        }

        cout << "Item added to cart successfully!\n";
    }

    if (cart.empty())
    {
        cout << "\nNo items ordered.\n";
        return;
    }

    // Generate bill
    double grandTotal = 0;

    static int orderNumber = 1001;

    cout << "\n========== SMARTBITE BILL ==========\n";
    cout << "Order Number: " << orderNumber++ << "\n";
    cout << "Service: " << serviceName << "\n";

    cout << "\n"
         << left << setw(20) << "Dish"
         << right << setw(8) << "Qty"
         << setw(12) << "Price"
         << setw(12) << "Total" << "\n";

    cout << "------------------------------------------------\n";

    for (size_t i = 0; i < cart.size(); i++)
    {
        double itemTotal =
            cart[i].dish.price * cart[i].quantity;

        grandTotal += itemTotal;

        cout << left << setw(20) << cart[i].dish.name
             << right << setw(8) << cart[i].quantity
             << setw(12) << cart[i].dish.price
             << setw(12) << itemTotal << "\n";
    }

    cout << "------------------------------------------------\n";

    cout << right << setw(40) << "Grand Total: Rs. "
         << grandTotal << "\n";

    cout << "\nTHANK YOU FOR ORDERING WITH SMARTBITE!\n";
    cout << "We hope you enjoy your meal!\n";
    cout << "====================================\n";
}
