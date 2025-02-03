#include <iostream> //this is the input/output library. it is required to use cout & cin objects which are from istream and ostream classes.
#include <fstream> //this is the file library. it is used to read from files and write to files using ifstream & ofstream classes
#include <sstream> //this is the string stream library. it is used to split and parse strings using stringstream class.
#include <string> //this is the string library for string class.

using namespace std; //tells compiler to make all classes, objects and functions available from std.

//here I create a struct named Client with all data members representing the variables given in the dataset.
struct Client {
    int age;
    string job;
    string marital;
    string education;
    string defaulted; //could not use default since it is a keyword.
    int balance;
    string housing;
    string loan; 
    string contact;
    int day;
    string month;
    int duration;
    int campaign;
    int pdays;
    int previous;
    string poutcome;
    string y;

};

int main() {

    const int NUM_CLIENTS = 25;
    Client clients[NUM_CLIENTS];
}

