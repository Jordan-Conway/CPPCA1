#include <iostream>
#include <string>

using namespace std;

void menu();
void importData();
void linkedListFeatures();
void vectorFeatures();

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

//TODO read in data from file
void importData(){

}

//TODO menu for linked list
void linkedListFeatures(){

}

//TODO menu for vector
void vectorFeatures(){

}
