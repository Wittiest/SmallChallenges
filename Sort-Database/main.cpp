#include "main.h"

// Get a filename from program arguments, then make a Person for each line in the file.
bool ReadPeopleFromFile(int argc, char* argv[], vector<Person> &people)
{
    Person tmpPrsn;
    ifstream inFS;
    int tmpAge = 0;
    string tmpGender = "";
    int tmpYI = 0;

    if (argc != 2) {
        cout << "\nUsage: [EXECUTABLE FILE] [TEXT DATA FILE], e.g. myprog.exe dev_people.txt" << endl;
        return true; // indicates error
    }

    cout << "Opening file " << argv[1] << ".\n";
    inFS.open(argv[1]); // Try to open file
    if (!inFS.is_open()) {
        cout << "Could not open file " << argv[1] << ".\n";
        return true; // indicates error
    }
    
    while (!inFS.eof()) {
        inFS >> tmpAge;
        inFS >> tmpGender;
        inFS >> tmpYI;
        tmpPrsn.SetData(tmpAge, tmpGender, tmpYI);
        tmpPrsn.Print();
        people.push_back(tmpPrsn);
    }
    inFS.close();
    cout << "Finished reading file." << endl;
    
    return false; // indicates no error
}

// Ask user to enter age range, yearly income range, and gender preference
void GetUserInput(int &ageLowerRange, int &ageUpperRange, string &gender,
    int &yILowerRange, int &yIUpperRange)
{
    cout<<"\nEnter lower range of age: ";
    cin >> ageLowerRange;
    
    cout << "Enter upper range of age: ";
    cin >> ageUpperRange;

    do {
        cout << "Enter gender (male, female, or any): ";
        cin >> gender;
    } while (gender != "male" && gender != "female" && gender != "any");

    cout << "Enter lower range of yearly income: ";
    cin >> yILowerRange;

    cout << "Enter upper range of yearly income: ";
    cin >> yIUpperRange;

    return;
}

// Return people within the given age range.
vector<Person> GetPeopleInAgeRange(vector<Person> ppl, int lowerRange, int upperRange)
{
    vector<Person> pplInAgeRange;
    int age = 0;

    for (unsigned int i = 0; i < ppl.size(); ++i) {
        age = ppl.at(i).GetAge();
        if ((age >= lowerRange) && (age <= upperRange)) {
            pplInAgeRange.push_back(ppl.at(i));
        }
    }
    
    return pplInAgeRange;
}

// Return people with the given gender
vector<Person> GetPeopleWithSpecificGender(vector<Person> ppl, string gender)
{
    if (gender != "any")
    {
        vector<Person> pplOfGender;

        for (unsigned int i = 0; i < ppl.size(); ++i) {
            if (ppl.at(i).GetGender() == gender) {
                pplOfGender.push_back(ppl.at(i));
            }
        }

        return pplOfGender;
    }
    return ppl;
}

// Return people within given income range
vector<Person> GetPeopleInIncomeRange(vector<Person> ppl, int yILowerRange, int yIUpperRange)
{
    vector<Person> pplInIncomeRange;
    int income = 0;

    for (unsigned int i = 0; i < ppl.size(); ++i) {
        income = ppl.at(i).GetIncome();
        if ((income >= yILowerRange) && (income <= yIUpperRange)) {
            pplInIncomeRange.push_back(ppl.at(i));
        }
    }
    
    return pplInIncomeRange;
}
int main(int argc, char* argv[])
{
    vector <Person> people;
    bool hadError = false;
    int ageLowerRange = 0;
    int ageUpperRange = 0;
    string gender = "";
    int yILowerRange = 0;
    int yIUpperRange = 0;
    
    hadError = ReadPeopleFromFile(argc, argv, people);
    if( hadError ) {
        return 1; // indicates error
    }
    
    GetUserInput(ageLowerRange, ageUpperRange, gender, yILowerRange, yIUpperRange);
    people = GetPeopleInAgeRange(people, ageLowerRange, ageUpperRange);
    people = GetPeopleWithSpecificGender(people, gender);
    people = GetPeopleInIncomeRange(people, yILowerRange, yIUpperRange);
    
    cout << "\nNumber of potential customers = " << people.size() << endl;
    
    return 0;
}
