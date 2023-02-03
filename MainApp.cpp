#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void menu();
void importData();
void linkedListFeatures();
void vectorFeatures();

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

int main(){

    menu();
}

void menu(){
    int input;
    cout << "Please choose an option" << endl;
    cin >> input;

    switch(input){
        case 1: {
            linkedListFeatures();
            break;
        }
        case 2: {
            vectorFeatures();
            break;
        }
    }
}

Shipment parseLine(const string &line){
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
}

//TODO read in data from file
void importData(){

}

//TODO menu for linked list
void linkedListFeatures(){

}

//TODO menu for vector
void vectorFeatures(){

}
