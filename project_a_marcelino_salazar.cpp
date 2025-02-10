#include <iostream> //this is the input/output library. it is required to use cout & cin objects which are from istream and ostream classes.
#include <fstream> //this is the file library. it is used to read from files and write to files using ifstream & ofstream classes
#include <sstream> //this is the string stream library. it is used to split and parse strings using stringstream class.
#include <string> //this is the string library for string class.

using namespace std; //tells compiler to make all classes, objects and functions available from std.

class Clients { //here I added a class to hold structs
public:
//here I create multiple structs to where the last struct is nested with the previous 3. This is critical for menu options.
    struct ClientData {
        int id;
        int age;
        string job;
        string marital;
        string education;

        void print() const {
            cout << "ID Number: " << id << endl;
            cout << "Age: " << age << endl;
            cout << "Occupation: " << job << endl;
            cout << "Marital Status: " << marital << endl;
            cout << "Education: " << education << endl;
            cout << "-----------------------" << endl;
        }
    };

    struct ClientBankData {
        string defaulted; //could not use default since it is a keyword.
        int balance;
        string housing;
        string loan;
        
        void print() const {
            cout << "Default record: " << defaulted << endl;
            cout << "Average yearly balance: " << balance << endl;
            cout << "Housing Loans: " << housing << endl;
            cout << "Personal Loans: " << loan << endl;
            cout << "-----------------------" << endl;
        }
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

        void print() const {
            cout << "Current Result: " << y << endl;
            cout << "Contact Type: " << contact << endl;
            cout << "Last day of the week contacted: " << day << endl;
            cout << "Last month contacted: " << month << endl;
            cout << "Call duration (sec): " << duration << endl;
            cout << "Days since last day contacted: " << pdays << endl;
            cout << "Number of contacts: " << previous << endl;
            cout << "Previous Result: " << poutcome << endl;
            cout << "-----------------------" << endl;
        }
    };

    struct ClientRecord { //this struct is nested with previous 3 structs.
        ClientData clientInfo;
        ClientBankData clientBankInfo;
        CampaignData campaignInfo;
        
        void print() const {
            cout << "Client Information: " << endl;
            cout << "" << endl;
            clientInfo.print();
            cout << "Client Bank Information: " << endl;
            cout << "" << endl;
            clientBankInfo.print();
            cout << "Campaign Information: " << endl;
            cout << "" << endl;
            campaignInfo.print();
        }
    };

private:
    ClientRecord* clientFile; //this declares a pointer named "clientFile".
    int capacity;

public:
    Clients(int cap) : capacity(cap) {
        clientFile = new ClientRecord[capacity]; //assigns a dynamic array of structs.
        loadfile();
    }

    ~Clients() { //this destructor deallocates memory from the dynnamic array to prevent memory leaks.
        delete[] clientFile;
    }

    void loadfile() {
        ifstream file("bank_full.csv"); //this declares a ifstream class named "file" to open the external file bank_full.csv.

    string line; //this declares a string class object named "line" to store values.
    getline(file, line); //here I use the string function to store rows from the external file into "line". It's placement here is meant to skip the header before executing the for loop.

    for (int i = 0; i < capacity && getline(file, line); i++) { //this declares a for loop to read in capacity number rows from the external file.
        stringstream parse(line); //this declares a stringstream class named "parse" which splits values from rows stored in "line" variable into individual strings.
        string temporaryLine; //here I declare a string class object named "temporaryLine" to convert strings into integers.
        
        //here I use the getline() function to extract data from "parse" and store it into data members accordingly. I used stoi() function to convert strings into integers where needed.
        getline(parse, temporaryLine, ';'); 
        clientFile[i].clientInfo.age = stoi(temporaryLine);
        getline(parse, clientFile[i].clientInfo.job, ';');
        getline(parse, clientFile[i].clientInfo.marital, ';');
        getline(parse, clientFile[i].clientInfo.education, ';');
        getline(parse, clientFile[i].clientBankInfo.defaulted, ';');
        getline(parse, temporaryLine, ';');
        clientFile[i].clientBankInfo.balance = stoi(temporaryLine);
        getline(parse, clientFile[i].clientBankInfo.housing, ';');
        getline(parse, clientFile[i].clientBankInfo.loan, ';');
        getline(parse, clientFile[i].campaignInfo.contact, ';');
        getline(parse, temporaryLine, ';'); 
        clientFile[i].campaignInfo.day = stoi(temporaryLine);
        getline(parse, clientFile[i].campaignInfo.month, ';');
        getline(parse, temporaryLine, ';'); 
        clientFile[i].campaignInfo.duration = stoi(temporaryLine);
        getline(parse, temporaryLine, ';'); 
        clientFile[i].campaignInfo.campaign = stoi(temporaryLine);
        getline(parse, temporaryLine, ';'); 
        clientFile[i].campaignInfo.pdays = stoi(temporaryLine);
        getline(parse, temporaryLine, ';'); 
        clientFile[i].campaignInfo.previous = stoi(temporaryLine);
        getline(parse, clientFile[i].campaignInfo.poutcome, ';');
    }
    file.close();
}
};


int main() { 
int capacity;
cout << "How many clients do you want to view? ";
cin >> capacity; //capacity will determine the amount of data to access from the external file.
cout << "-----------------------" << endl;
}

for (int i = 0; i < capacity; i++) {
    clientFile[i].print();

}

return 0;

}
