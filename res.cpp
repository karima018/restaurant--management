
#include <bits/stdc++.h>
using namespace std;

struct FoodItem {
    string name;
    double price;
    int quantity;
};

bool adminLogin() {
    fstream adminFile;
    string username, password;
    cout << "Enter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    cin >> password;

    adminFile.open("admin.txt", ios::in);
    if (!adminFile.is_open()) {
        cout << "Error opening file for reading.\n";
        return false;
    }

    string fileUsername, filePassword;
    while (adminFile >> fileUsername >> filePassword) {
        if (fileUsername == username && filePassword == password) {
            adminFile.close();
            return true;
        }
    }
    adminFile.close();
    return false;
}

void addFoodItem(FoodItem foodItems[], int& count) {
    FoodItem newItem;
    cout << "Enter food item name: ";
    cin >> newItem.name;
    cout << "Enter price: ";
    cin >> newItem.price;
    cout << "Enter quantity: ";
    cin >> newItem.quantity;
    foodItems[count] = newItem;
    count++;
    cout << "Food item added successfully!" << endl;
}

void showAllItems(FoodItem foodItems[], int count) {
    if (count == 0) {
        cout << "No food items available!" << endl;
        return;
    }
    cout << "Food Items:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Name: " << foodItems[i].name << endl;
        cout << "Price: " << foodItems[i].price << endl;
        cout << "Quantity: " << foodItems[i].quantity << endl;
        cout << "-------------------------" << endl;
    }
}

void searchFoodItem(FoodItem foodItems[], int count) {
    string name;
    cout << "Enter name of food item to search: ";
    cin >> name;
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (foodItems[i].name == name) {
            cout << "Food item found!" << endl;
            cout << "Name: " << foodItems[i].name << endl;
            cout << "Price: " << foodItems[i].price << endl;
            cout << "Quantity: " << foodItems[i].quantity << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Food item not found!" << endl;
    }
}

int main() {
    const int MAX_ITEMS = 100;
    FoodItem foodItems[MAX_ITEMS];
    int count = 0;
    int choice;

    if (adminLogin()) {
        cout << "Login successful!\n";
        do {
            cout << "\nRestaurant Management System" << endl;
            cout << "1. Add Food Item" << endl;
            cout << "2. Show All Food Items" << endl;
            cout << "3. Search Food Item" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addFoodItem(foodItems, count);
                    break;
                case 2:
                    showAllItems(foodItems, count);
                    break;
                case 3:
                    searchFoodItem(foodItems, count);
                    break;
                case 4:
                    cout << "Exiting the system. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != 4);
    } else {
        cout << "Login failed. Please try again.\n";
    }

    return 0;
}
