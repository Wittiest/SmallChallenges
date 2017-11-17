#include "main.h"

// Constructor for the Person class.
Person::Person()
{
    age = 0;
    gender = "default";
    yearlyIncome = 0;
    return;
}

// Print the Person class.
void Person::Print()
{
    cout << "Age = " << this->age
         << ", gender = " << this->gender
         << ", yearly income = " << this->yearlyIncome
         << endl;
    return;
}

// Set the age, gender, and yearlyIncome of a Person.
void Person::SetData(int a, string gen, int income)
{
    this->age = a;
    this->gender = gen;
    this->yearlyIncome = income;
    return;
}

// Get the age of a Person.
int Person::GetAge()
{
    return this->age;
}
// Get the gender of the person
string Person::GetGender()
{
    return this->gender;
}

int Person::GetIncome()
{
    return this->yearlyIncome;
}