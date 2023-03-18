#include <cmath>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct InventoryRec {

  std::string name;
  int num;
  int qty;
};

// reads form txt file
vector<InventoryRec> readInv(string filename) {

  vector<InventoryRec> inventory;
  ifstream file(filename);

  if (file.is_open()) {
    string line;

    while (getline(file, line)) {
      stringstream ss(line);

      string name;
      int num, qty;
      getline(ss, name, ',');
      ss >> num;
      ss.ignore();
      ss >> qty;

      inventory.push_back({name, num, qty});
    }
    file.close();
  }
  return inventory;
}

// updates to File
void updateInv(vector<InventoryRec> &inventory, InventoryRec newItem) {

  for (auto &item : inventory) {
    if (item.name == newItem.name && item.num == newItem.num) {
      item.qty += newItem.qty;
      return;
    }
  }

  // If the item is not found in the inventory, add a new item
  inventory.push_back(newItem);
}

// addsItem
void addItem(string filename, string name, int num, int qty) {
  vector<InventoryRec> inventory = readInv(filename);

  InventoryRec newItem = {name, num, qty};

  updateInv(inventory, newItem);

  ofstream file(filename);
  if (file.is_open()) {
    for (auto &item : inventory) {
      file << item.name << "," << item.num << "," << item.qty << endl;
    }
    file.close();
    std::cout << "New item added and inventory updated successfully." << endl;
  } else {
    std::cout << "Unable to open file for writing." << endl;
  }
}
void displayInvFunction(vector<InventoryRec> &inventory) {

  std::cout << "Inventory of Burgertopia: \n";

  std::cout << "----------------------------------\n ";
  std::cout << left << setw(20) << "Name" << setw(10) << "Number" << setw(20)
            << "Quantity" << endl;
  std::cout << "----------------------------------\n ";
  for (auto &item : inventory) {
    std::cout << left << setw(20) << item.name << setw(10) << item.num
              << setw(10) << item.qty << endl;
  }
  std::cout << "----------------------------------\n ";
}

int main() {

  char loginres;
  cout << "Would you like to login as a customer or admin: (C or A): ";
  std::cin >> loginres;
  loginres = toupper(loginres);

  if (loginres == 'C') {
    std::cout << "Works";
    // add display menu function
    // add the buy function for customer
  } else if (loginres == 'A') {

    vector<InventoryRec> inventory = readInv("inventory.txt");

    displayInvFunction(inventory);
    // InventoryRec newItem = {"Banana", 456,5};//manually inserted test
    // updateInv(inventory, newItem);

    ofstream file("inventory.txt");
    if (file.is_open()) {
      for (auto &item : inventory) {
        file << item.name << "," << item.num << "," << item.qty << endl;
      }
    }

    char resAdmin;
    cout << "Would you like to add a new item to the Inventory or Would you "
            "like to buy more items to the Inventory? (A(add) or B(buy)):  ";
    cin >> resAdmin;
    resAdmin = toupper(resAdmin);
    string filename, nameLoc;
    int qtyL, numL;

    switch (resAdmin) {
      // add the new Item function into main
      // add the buyInventory function into main
    case 'A':

      std::cout << "Enter the file name";
      std::cin >> filename;

      std::cout << "Enter the name of the new item: ";
      std::cin >> nameLoc;

      std::cout
          << "Enter the Id number you would like to create for the new item";
      int num;
      std::cin >> numL;

      std::cout << " Enter the quantity of the new item in storage: ";
      std::cin >> qtyL;
      addItem(filename, nameLoc, numL, qtyL);
      break;
    case 'B':
      // buyInventory
      break;
    default:
      file.close();
    }
  }
}