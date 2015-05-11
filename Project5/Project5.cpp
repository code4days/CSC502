/**
* File Name: Project5.cpp
* Author: Rasheed El-Saleh
* Course: CSC 502
* Date: 03/29/2015
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

//ItemInfo struct to represent the items in the catalog map
struct ItemInfo {

    ItemInfo(const string &init_description = "N/A", const double &init_unit_price = 0.00,
             const double &init_unit_shipping_weight = 0.00)
            :description(init_description), unit_price(init_unit_price),
             unit_shipping_weight(init_unit_shipping_weight) { }

public:
    string description;
    double unit_price;
    double unit_shipping_weight;
};

//typedefs for Catalog and order entities to be used through out the program
typedef map<string, ItemInfo> Catalog;
typedef map<string, int> Order;

//auxiliary functions definitions
void readCatalog(Catalog &catalog, const string &fileName) throw(runtime_error);
void printCatalog(const Catalog &catalog);
ItemInfo getItemData(const Catalog &catalog, const string &sku);
void addItem(Order &order, const Catalog &catalog, const string &sku, int quantity) throw (logic_error);
void displayOrderItems(const Order &order, const Catalog &catalog);
void removeItem(Order &order, const string &sku, int quantity) throw(logic_error);
void displayOrderSummary(const Order &order, const Catalog &catalog);
void printDivider();

//operator<< overload
ostream &operator<<(ostream &out, const ItemInfo &c);

int main() {


    /**
     * Calling readCatalog and printCatalog
     */

    Catalog catalog;
    try {
        readCatalog(catalog,"CatalogData.txt");
        //readCatalog(catalog, "fff.txt");
    }
    catch(runtime_error &e) {
        cout << e.what() << endl;
    }

    printCatalog(catalog);

    /**
     * Calling getItemData
     */
    cout << endl;
    cout << "Product description for sku 93456A:  " << getItemData(catalog, "93456A").description << endl;
    cout << "Product description for sku ABC: " << getItemData(catalog, "ABC").description << endl;
    cout << endl;

    /**
     * Add and remove items then
     * Call displayOrderItems and displayOrderSummary
     */

    Order order;
    try {

        addItem(order,catalog, "4123BLU", 2);
        addItem(order, catalog, "93456A", 3);
        addItem(order, catalog, "93456A", 2);
        addItem(order, catalog, "93456C", 2);
        removeItem(order, "93456C", 1);
        addItem(order, catalog, "4123RED", 4);
        removeItem(order, "4123RED", 4);
        //removeItem(order, "ABC", 3);
    }
    catch(logic_error &e) {
        cout << e.what() << endl;
    }

    displayOrderItems(order, catalog);

    displayOrderSummary(order, catalog);

    return 0;
}

/**
 * function to read catalog items from file
 * throws a runtime error if the there's a problem reading the file
 */

void readCatalog(Catalog &catalog, const string &fileName) throw(runtime_error) {

    string tmp;
    string line;

    ifstream catalog_file(fileName);
    vector<string> tokens;
    vector<ItemInfo> ii;
    int counter = 0;

    if(catalog_file.good()) {
        while(getline(catalog_file, line)) {

            stringstream ss (line);

            while(getline(ss, tmp, ':')) {
                tokens.push_back(tmp);
        }

           catalog[tokens[0]] = ItemInfo(tokens[1], strtod(tokens[2].c_str(), NULL), strtod(tokens[3].c_str(), NULL));
           tokens.clear();
        }
        catalog_file.close();
    }
    else {
        throw runtime_error("Unable to open file");
    }

}

/**
 * overload of operator<< to print items of ItemInfo struct
 *
 */
ostream &operator<<(ostream &out, const ItemInfo &c) {
    return out << left << setw(56) << c.description <<  fixed << setprecision(2) << setw(13) << c.unit_price
           << setw(19) << c.unit_shipping_weight;
}

/**
 * funtion for printing a catalog
 * prints header then loops through catalog printing its content
 */
void printCatalog(const Catalog &catalog) {

    cout << left << setw(10) << "SKU";
    cout << left << setw(56) << "Description";
    cout << left << setw(13) << "Unit Price";
    cout << left << setw(19) << "Shipping Wt. (lbs.)" << endl;
    printDivider();

    for(auto it = catalog.cbegin(); it != catalog.cend(); ++it) {
        cout << left << setw(10) << it->first << it->second << endl;
    }
}


/**
 * function to find an item in a catalog by searching for the items sku
 * will return Item not found of the item doesn't exist
 */
ItemInfo getItemData(const Catalog &catalog, const string &sku) {

    if( catalog.find(sku) != catalog.end()) {

        return catalog.find(sku)->second;
    }
    else {
     return ItemInfo("Item not found");
    }
}

/**
 * function to add item to order, if item not found in catalog throw logic error
 */
void addItem(Order &order, const Catalog &catalog, const string &sku, int quantity) throw (logic_error){

    auto cat_it = catalog.find(sku);
    auto order_it = order.find(sku);
    //Catalog::const_iterator it = catalog.find(sku);

    if(cat_it != catalog.end()) {

        if(order_it != order.end()) {
            order[sku] += quantity;
        }
        else {
            order[sku] = quantity;
        }
    }
    else {
        throw logic_error("Item not found");
    }

}

/**
 * function to print all order items
 */
void displayOrderItems(const Order &order, const Catalog &catalog) {

    cout << left << setw(10) << "SKU";
    cout << left << setw(56) << "Description";
    cout << left << setw(10) << "Quantity" << endl;
    printDivider();

    for(auto it = order.cbegin(); it != order.cend(); ++it) {
        cout << left << setw(10) << it->first << setw(56) << getItemData(catalog, it->first).description << setw(10) << it->second << endl;
    }
    cout << endl;
}

/**
 * function to remove item from order if it exists in the order
 * will throw exception otherwise
 */
void removeItem(Order &order, const string &sku, int quantity) throw(logic_error) {
    //Order::iterator it = order.find(sku);
    auto it = order.find(sku);

    if( it != order.end()) {
        if(it->second > quantity) {

            order[sku] -= quantity;

        }
        else {
            order.erase(it);
        }
    }
    else {
        throw logic_error("Order not found");
    }
}

/**
 * function to print order summary
 */
void displayOrderSummary(const Order &order, const Catalog &catalog) {
    int totalItems = 0;
    double totalCost = 0.0;
    double totalWeight = 0.0;

    cout << "Order Summary" << endl;
    printDivider();

    cout << "Distinct item types: " << order.size() << endl;
    for(auto it = order.cbegin(); it != order.cend(); ++it) {
            totalItems += it->second;
            totalCost += getItemData(catalog, it->first).unit_price;
            //totalCost += catalog.find(it->first)->second.unit_price;
            totalWeight += getItemData(catalog, it->first).unit_shipping_weight;
            //totalWeight += catalog.find(it->first)->second.unit_shipping_weight;
    }
    cout << "Total number of items: " << totalItems << endl;
    cout << "Total cost: $" << totalCost << endl;
    cout << "Total weight: " << totalWeight << endl;

}

/**
 * function to print divider
 */
void printDivider() {
    cout << string(98, '=') << endl;
}