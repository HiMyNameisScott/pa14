/// @file pa14.cpp
/// @author Scott T. Koss 
/// @date 20-25-2022
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief A small chore/todo program
/// @note  Time taken to develop approximately 4 hours. 

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void get_data(vector<string> &data, ifstream &inFile);
void add_chores(vector<string> &data);
void how_many(vector<string> &data);
void print_chores(vector<string> &data);
void delete_chores(vector<string> &data);
void run_program(vector<string> &data);


int main() {

    vector<string> data;            // Stores data from file.
    ifstream inFile;                // Opens in file stream
    ofstream outFile;               // Opens outfile stream should we want to save to file
    inFile.open("chores.txt");      // Declares chores.txt as infile
    outFile.open("chores2.txt");    // Decalres chores2.txt as outfile

    get_data(data, inFile);
    run_program(data);

    inFile.close();                 // closes infile
    outFile.close();                // closes outfile
    return 0;
    
}

/// @brief Appends data from chores.txt to vector data
/// @param data vector to append to
/// @param inFile opened file
void get_data(vector<string> &data, ifstream &inFile){
    string line;                    // Used to store line to append to Array
    if(inFile.is_open()){
        cout << "is open" << endl;
    while(getline(inFile, line)) {
        data.push_back(line);
    }
    }
}

/// @brief adds chores to data
/// @param data vector
void add_chores(vector<string> &data){
    string chore;                   // Used to store chore to add to data
    cout << "What chore would you like to add? " << endl;
    cin >> chore;
    data.push_back(chore);
    cout << "Added " <<  chore  << " to chores list." << endl;
    cout << " " << endl;
}

/// @brief returns how many chores are left in the list
/// @param data vector
void how_many(vector<string> &data){
    cout << " " << endl;
    cout << "Number of chores left: "<< data.size() << endl;
    cout << " " << endl;
}

/// @brief prints remaining chores in a list format
/// @param data vector
void print_chores(vector<string> &data){
    int j = 0;                         // iterator to help figure out which item to remove/delete
    for (auto s : data){
        cout << j << ") " << s << endl;
        ++j;
    }
    cout << " " << endl;
    }

/// @brief used to delete a chore from the data
/// @param data vector
void delete_chores(vector<string> &data){
    int to_delete;                  // used with data.begin() to delete item
    print_chores(data);
    cout << "=====================================================" << endl;
    cout << "Which item would you like to delete? " << endl;;
    cin >> to_delete;
    data.erase(data.begin() + to_delete);
}

/// @brief Runs our program, and allows us to select different options
/// @param data vector
void run_program(vector<string> &data){
    int input;                  // stores menu selection
    while(input != 0){
        cout <<"=====================================================" << endl;
        cout <<"===Select an option that you would like to perform===" << endl;
        cout <<"1) Print Chores: "      << endl;
        cout <<"2) Add Chores: "        << endl;
        cout <<"3) Delete Chores: "     << endl;
        cout <<"4) Remaining Chores: "  << endl;
        cout <<"0) Exit Program: "      << endl;
        cout <<"=====================================================" << endl;
        cout << " " << endl;
        cin >> input; 

        switch(input) {         // case statement used to pick menu items
            case 1:
                print_chores(data);
                break;
            case 2:
                add_chores(data);
                break;
            case 3:
                delete_chores(data);
                break;
            case 4:
                how_many(data);
                break;
            default :
                cout << "Default" << endl;
        }
    }
}