#include <iostream> //this is the input/output library. it is required to use cout & cin objects which are from istream and ostream classes.
#include <fstream> //this is the file library. it is used to read from files and write to files using ifstream & ofstream classes
#include <sstream> //this is the string stream library. it is used to split and parse strings using stringstream class.
#include <string> //this is the string library for string class.

using namespace std; //tells compiler to make all classes, objects and functions available from std.

//here I create multiple structs to where the last struct is nested with the previous 3. This is critical for menu options.
struct ClientData {
    int age;
    string job;
    string marital;
    string education;
};

struct ClientBankData {
    string defaulted; //could not use default since it is a keyword.
    int balance;
    string housing;
    string loan; 
};

struct CampaignData {    
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

struct ClientRecord { //this struct is nested with previous 3 structs.
    ClientData clientInfo;
    ClientBankData clientBankInfo;
    CampaignData campaignInfo; 
};

int main() { 
int capacity;
cout << "How many clients do you want to view?";
cin >> capacity; //capacity will determine the amount of data to access from the external file.

ClientRecord* clientFile = new ClientRecord[capacity]; //this declares a pointer named "clientFile" and assigns a dynamic array of structs.

ifstream file("bank_full.csv"); //this declares a ifstream class named "file" to open the external file bank_full.csv.
string line; //this declares a string class object named "line" to store values.
getline(file, line); //here I use the string function to store rows from the external file into "line". It's placement here is meant to skip the header before executing the for loop.

for (int i = 0; i < capacity; i++) { //this declares a for loop to read in capacity number rows from the external file.
    stringstream parse(line); //this declares a stringstream class named "parse" which splits values from rows stored in "line" variable into individual strings.
    string temporaryLine; //here I declare a string class object named "temporaryLine" to temporarily store values extracted.
    
    //here I use the getline() function to extract data from "parse" and store it into data members accordingly.
    getline(parse, clientFile[i].clientInfo.age, ';');
    getline(parse, clientFile[i].clientInfo.job, ';');
    getline(parse, clientFile[i].clientInfo.marital, ';');
    getline(parse, clientFile[i].clientInfo.education, ';');
    getline(parse, clientFile[i].clientBankInfo.defaulted, ';');
    getline(parse, clientFile[i].clientBankInfo.balance, ';');
    getline(parse, clientFile[i].clientBankInfo.housing, ';');
    getline(parse, clientFile[i].clientBankInfo.loan, ';');
    getline(parse, clientFile[i].campaignInfo.contact, ';');
    getline(parse, clientFile[i].campaignInfo.day, ';');
    getline(parse, clientFile[i].campaignInfo.month, ';');
    getline(parse, clientFile[i].campaignInfo.duration, ';');
    getline(parse, clientFile[i].campaignInfo.campaign, ';');
    getline(parse, clientFile[i].campaignInfo.pdays, ';');
    getline(parse, clientFile[i].campaignInfo.previous, ';');
    getline(parse, clientFile[i].campaignInfo.poutcome, ';');

}

file.close();

}
