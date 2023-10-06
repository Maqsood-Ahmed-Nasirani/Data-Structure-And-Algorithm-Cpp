#include <iostream>
using namespace std;

class student{

    public:
        student()
        {
            cout << "Copy constructor Invoked!" << endl;
        }

        student(string n, int a, bool g)
        {
            cout << "Parametrized constructor Invoked!\n";
            name = n;
            age = a;
            gender = g;
        }

        student(student &a)
        {
            cout << "Copy constructor Invoked!\n";
            name = a.name;
            age = a.age;
            gender = a.gender;
        }
        ~student()
        {
            cout << "Destructor Invoked\n";
        }

        bool operator == (student &a){
            if(name == a.name && age == a.age && gender == a.gender)
                return true;
            else 
                return false;
        }

        friend istream &operator>>(istream &input, student &a){
            input >> a.name;
            input >> a.age;
            input >> a.gender;
            return input;
        }

        friend ostream &operator<<(ostream &output, student &a){
            cout << a.name << " " << a.age << " " << a.gender << endl;
            return output;
        }

    private:
        string name;
        int age;
        bool gender;
};



int main(void)
{
    student a;
    student b("Maqsood", 19, 0);
    student c(b);
    student d("Abbas", 19, 0);

    if(b == d)
        cout << "same\n";
    else
        cout << "Not same!\n";

    cout << "Enter details: ";
    cin >> a;
    cout << a;

    return 0;
}
