#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>

using namespace std;

struct Shipment;

//Global variables
string fileName = "shipping-data-small.csv";
list<Shipment> shipmentsL;
vector<Shipment> shipmentsV;

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

//This function should not be called. Use initialise() instead
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
        vector.push_back(s);
    }
}

//Calls to load data to list and vector
void initialise(){
    importData(fileName, shipmentsL);
    copyToVector(shipmentsL, shipmentsV);
}

void display(const Shipment &ship){
    cout << left << setw(5) << ship.id << endl;
}

void displayAll(const list<Shipment> &data){
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
    for(const Shipment& s: data){
        display(s);
    }
}

void displayAll(const vector<Shipment> &data){
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
    for(const Shipment& s: data){
        display(s);
    }
}

//TODO menu for linked list
void linkedListFeatures()
{
    displayAll(shipmentsL);
}

//TODO menu for vector
void vectorFeatures()
{

}

void menu()
{
    int input;
    cout << "Please choose an option" << endl;
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
        default:
        {
            cout << "Invalid input. Please try again" << endl;
            break;
        }
    }
}

int main()
{
    initialise();
    menu();
}
