#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <string>
#include <vector>

struct Item {
    int id;
    std::string name;
    int quantity;
    double price;
};

class Inventory {
private:
    std::vector<Item> items;
    int nextId;

public:
    Inventory();

    void addItem(const std::string& name, int quantity, double price);
    bool updateItem(int id, const std::string& name, int quantity, double price);
    bool deleteItem(int id);
    Item* searchItem(int id);
    void displayItems() const;
};

#endif
#include "Inventory.hpp"
#include <iostream>
#include <iomanip>

Inventory::Inventory() : nextId(1) {}

void Inventory::addItem(const std::string& name, int quantity, double price) {
    items.push_back({nextId++, name, quantity, price});
}

bool Inventory::updateItem(int id, const std::string& name, int quantity, double price) {
    for (auto& item : items) {
        if (item.id == id) {
            item.name = name;
            item.quantity = quantity;
            item.price = price;
            return true;
        }
    }
    return false;
}

bool Inventory::deleteItem(int id) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->id == id) {
            items.erase(it);
            return true;
        }
    }
    return false;
}

Item* Inventory::searchItem(int id) {
    for (auto& item : items) {
        if (item.id == id) {
            return &item;
        }
    }
    return nullptr;
}

void Inventory::displayItems() const {
    std::cout << std::left << std::setw(5) << "ID"
              << std::setw(20) << "Name"
              << std::setw(10) << "Quantity"
              << std::setw(10) << "Price" << "\n";

    for (const auto& item : items) {
        std::cout << std::left << std::setw(5) << item.id
                  << std::setw(20) << item.name
                  << std::setw(10) << item.quantity
                  << std::setw(10) << item.price << "\n";
    }
}
#include "Inventory.hpp"
#include <iostream>

int main() {
    Inventory inventory;
    int choice;

    while (true) {
        std::cout << "\nInventory Management System\n";
        std::cout << "1. Add Item\n2. Update Item\n3. Delete Item\n4. Search Item\n5. Display All Items\n6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            int quantity;
            double price;
            std::cout << "Enter name, quantity, price: ";
            std::cin >> name >> quantity >> price;
            inventory.addItem(name, quantity, price);
        } else if (choice == 2) {
            int id, quantity;
            std::string name;
            double price;
            std::cout << "Enter ID to update: ";
            std::cin >> id;
            std::cout << "Enter new name, quantity, price: ";
            std::cin >> name >> quantity >> price;
            if (!inventory.updateItem(id, name, quantity, price))
                std::cout << "Item not found.\n";
        } else if (choice == 3) {
            int id;
            std::cout << "Enter ID to delete: ";
            std::cin >> id;
            if (!inventory.deleteItem(id))
                std::cout << "Item not found.\n";
        } else if (choice == 4) {
            int id;
            std::cout << "Enter ID to search: ";
            std::cin >> id;
            Item* item = inventory.searchItem(id);
            if (item) {
                std::cout << "Found: " << item->name << ", Qty: " << item->quantity << ", Price: " << item->price << "\n";
            } else {
                std::cout << "Item not found.\n";
            }
        } else if (choice == 5) {
            inventory.displayItems();
        } else if (choice == 6) {
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}




