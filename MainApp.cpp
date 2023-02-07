#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Shipment;

//Global variables
string fileName = "shipping-data-small.csv";
list<Shipment> shipmentsL;
vector<Shipment> shipmentsV;

//TODO sort linkedlist by customer ratings
//TODO Set features
//TODO Map features
//TODO Document on Containers

struct Shipment
{
    int id;
    char warehouseBlock;
    string shipMode;
    int customerCareCalls;
    int customerRating;
    int cost;
    int priorPurchases;
    string importance;
    char gender;
    int discount;
    int weight;
    int arrivedOnTime;
};

Shipment parseLine(const string &line)
{
    Shipment ship;
    string temp;
    stringstream ss(line);

    getline(ss, temp, ',');
    ship.id = stoi(temp);

    getline(ss, temp, ',');
    ship.warehouseBlock = temp.at(0);

    getline(ss, ship.shipMode, ',');

    getline(ss, temp, ',');
    ship.customerCareCalls = stoi(temp);

    getline(ss, temp, ',');
    ship.customerRating = stoi(temp);

    getline(ss, temp, ',');
    ship.cost = stoi(temp);

    getline(ss, temp, ',');
    ship.priorPurchases = stoi(temp);

    getline(ss, ship.importance, ',');

    getline(ss, temp, ',');
    ship.gender = temp.at(0);

    getline(ss, temp, ',');
    ship.discount = stoi(temp);

    getline(ss, temp, ',');
    ship.weight = stoi(temp);

    getline(ss, temp, ',');
    ship.arrivedOnTime = stoi(temp);

    return ship;
}

//Loads all data from file to list
void importData(const string &name, list<Shipment> &data)
{
    ifstream fin(name);

    if(fin.good())
    {
        string line;
        getline(fin, line);
        while(getline(fin, line)){
            Shipment ship = parseLine(line);
            data.push_back(ship);
        }
        fin.close();
    }
    else
    {
        cout << "Error opening file" << endl;
    }
}

//Copies all data from list to vector
void copyToVector(const list<Shipment> &list, vector<Shipment> vector){
    for(const Shipment &s: list){
        vector.clear();
        vector.push_back(s);
    }
}

//Calls to load data to list and vector
void loadData()
{
    importData(fileName, shipmentsL);
    copyToVector(shipmentsL, shipmentsV);
}

void display(const Shipment &ship)
{
    cout << left << setw(5) << ship.id
         << setw(20) << ship.warehouseBlock
         << setw(10) << ship.shipMode
         << setw(25) << ship.customerCareCalls
         << setw(20) << ship.customerRating
         << setw(10) << ship.cost
         << setw(20) << ship.priorPurchases
         << setw(15) << ship.importance
         << setw(8) << ship.gender
         << setw(15) << ship.discount
         << setw(10) << ship.weight
         << setw(15) << ship.arrivedOnTime
         << endl;
}

void displayHeadings(){
    cout << left << setw(5) << "ID"
         << setw(20) << "Warehouse Block"
         << setw(10) << "Mode"
         << setw(25) << "Customer Care Calls"
         << setw(20) << "Customer Rating"
         << setw(10) << "Cost"
         << setw(20) << "Prior Purchases"
         << setw(15) << "Importance"
         << setw(8) << "Gender"
         << setw(15) << "Discount"
         << setw(10) << "Weight"
         << setw(15) << "Arrived on time"
         << endl;
}

//TODO stop line wrapping
void displayAll(const list<Shipment> &data)
{
    displayHeadings();
    for(const Shipment& s: data){
        display(s);
    }
}

void displayAll(const vector<Shipment> &data)
{
    displayHeadings();
    for(const Shipment& s: data){
        display(s);
    }
}

Shipment getFirst(const list<Shipment> &data)
{
    return data.front();
}

Shipment getLast(const list<Shipment> &data)
{
    return data.back();
}

void getById(const list<Shipment> &data){
    bool found = false;
    int id;

    cout << "Enter an id to search for" << endl;

    cin >> id;

    for(const Shipment& s: data)
    {
        if(s.id == id)
        {
            display(s);
            found = true;
            break;
        }
    }
    if(!found)
    {
        cout << "No shipment found with that ID" << endl;
    }
}

void getByIndex(const vector<Shipment> &data){
    bool found = false;
    int index;

    cout << "Enter an index" << endl;

    cin >> index;

    display(data.at(index));
}



void deleteFirst(list<Shipment> &data)
{
    data.pop_front();
}

void deleteLast(list<Shipment> &data)
{
    data.pop_back();
}

void deleteAtIndex(list<Shipment> &data){
    bool deleted = false;
    int index;

    cout << "Enter the index to delete";

    cin >> index;

    for(list<Shipment>::iterator iter = data.begin();iter != data.end(); iter++)
    {
        if(distance(data.begin(), iter) == index)
        {
            data.erase(iter);
            deleted = true;
            break;
        }
    }
    if(deleted)
    {
        cout << "Deletion Successful" << endl;
    }
    else{
        cout << "Could not delete at index " << index << endl;
    }
}

Shipment createShipment(){
    int id;
    char block;
    string shipMode;
    int careCalls;
    int rating;
    int cost;
    int purchases;
    string importance;
    char gender;
    int discount;
    int weight;
    char onTime;

    Shipment ship;

    cout << "Enter the shipment id" << endl;
    cin >> id;
    cout << "Enter the warehouse block" << endl;
    cin >> block;
    cout << "Enter the shipping method" << endl;
    cin >> shipMode;
    cout << "Enter the number of care calls" << endl;
    cin >> careCalls;
    cout << "Enter the customer rating" << endl;
    cin >> rating;
    cout << "Enter the cost of the item" << endl;
    cin >> cost;
    cout << "Enter the number of prior purchases" << endl;
    cin >> purchases;
    cout << "Enter the gender of the customer" << endl;
    cin >> gender;
    cout << "Enter the discount offered" << endl;
    cin >> discount;
    cout << "Enter the weight of the item in grammes" << endl;
    cin >> weight;
    cout << "Did the item arrive on time? (Y/N)" << endl;
    cin >> onTime;

    ship.id = id;
    ship.warehouseBlock = block;
    ship.shipMode = shipMode;
    ship.customerCareCalls = careCalls;
    ship.customerRating = rating;
    ship.cost = cost;
    ship.priorPurchases = purchases;
    ship.gender = gender;
    ship.discount = discount;
    ship.weight = weight;
    ship.arrivedOnTime = onTime;

    return ship;
}

void addAtIndex(list<Shipment> &data)
{
    bool added = false;
    int index;
    const Shipment ship = createShipment();

    cout << "Enter the index to enter the shipment at" << endl;

    cin >> index;

    for(list<Shipment>::iterator iter = data.begin();iter != data.end(); iter++)
    {
        if(distance(data.begin(), iter) == index)
        {
            data.insert(iter, ship);
            added = true;
            break;
        }
    }
    if(added)
    {
        cout << "Addition Successful" << endl;
    }
    else{
        cout << "Could not add at index " << index << endl;
    }
}

bool isLessThan2(const Shipment& ship)
{
    return ship.customerRating < 2;
}

int countRatings(list<Shipment> &data)
{
    int count = count_if(data.begin(), data.end(), isLessThan2);

    return count;
}

bool compareCost(const Shipment &s1, const Shipment &s2)
{
    return s1.cost < s2.cost;
}

bool compareId(const Shipment &s1, const Shipment &s2)
{
    return s1.id < s2.id;
}

void sortByCost(vector<Shipment> &data)
{
    sort(data.begin(), data.end(), compareCost);
    cout << "Vector Sorted" << endl;
}

void sortById(vector<Shipment> &data)
{
    sort(data.begin(), data.end(), compareId);
    cout << "Vector Sorted" << endl;
}

void linkedListFeatures()
{
    bool loop = true;
    int input;
    while(loop){
        cout << "Please choose an option" << endl;
        cout << "1. Display All" << endl;
        cout << "2. Get first item" << endl;
        cout << "3. Get last item" << endl;
        cout << "4. Search by id" << endl;
        cout << "5. Delete first item" << endl;
        cout << "6. Delete last item" << endl;
        cout << "7. Delete item at index" << endl;
        cout << "8. Add item at index" << endl;
        cout << "9. Count customer ratings less than 2";
        cout << "0. Go back" << endl;

        cin >> input;

        switch(input){
            case 1: displayAll(shipmentsL); break;
            case 2: display(getFirst(shipmentsL)); break;
            case 3: display(getLast(shipmentsL)); break;
            case 4: getById(shipmentsL); break;
            case 5: deleteFirst(shipmentsL); break;
            case 6: deleteLast(shipmentsL); break;
            case 7: deleteAtIndex(shipmentsL); break;
            case 8: addAtIndex(shipmentsL); break;
            case 9: cout << "There are " << countRatings(shipmentsL) << " ratings less than 2" << endl;
            case 0: loop = false; break;
            default: cout << "Invalid input. Please try again" << endl;
        }
    }
}

void vectorFeatures()
{
    bool loop = true;
    int input;
    while(loop){
        cout << "Please choose an option" << endl;
        cout << "1. Update vector" << endl;
        cout << "2. Display All" << endl;
        cout << "3. Get item by index" << endl;
        cout << "4. Sort vector by cost" << endl;
        cout << "5. Sort vector by id" << endl;
        cout << "0. Go back" << endl;

        cin >> input;

        switch(input){
            case 1: copyToVector(shipmentsL, shipmentsV); break;
            case 2: displayAll(shipmentsV); break;
            case 3: getByIndex(shipmentsV); break;
            case 4: sortByCost(shipmentsV); break;
            case 5: sortById(shipmentsV); break;
            case 0: loop = false; break;
            default: cout << "Invalid input. Please try again" << endl;
        }
    }
}

void menu()
{
    bool loop = true;
    int input;

    while(loop){
        cout << "Please choose an option" << endl;
        cout << "1. Linked List features" << endl;
        cout << "2. Vector features" << endl;
        cout << "0. Quit" << endl;
        cin >> input;

        switch(input)
        {
            case 1:
            {
                linkedListFeatures();
                break;
            }
            case 2:
            {
                vectorFeatures();
                break;
            }
            case 0:
            {
                loop = false;
                break;
            }
            default:
            {
                cout << "Invalid input. Please try again" << endl;
                break;
            }
        }
    }

}

int main()
{
    loadData();
    menu();
}
