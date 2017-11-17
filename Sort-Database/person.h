#ifndef PERSON_H
#define PERSON_H

using namespace std;
// Define a Person class, including age, gender, and yearlyIncome.
class Person
{
    public:
        Person();
        void Print();
        void SetData(int a, string gen, int income);
        int GetAge();
		string GetGender();
		int GetIncome();
    private:
        int age;
        string gender;
        int yearlyIncome;
};

#endif