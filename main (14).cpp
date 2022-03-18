#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Student{

    std::string name;
    std::string surname;
    int album_number;
    std::vector<float> grades;
public:
    Student(){}

    Student(std::string n, std::string s, std::vector<float> g){
        name = n;
        surname = s;
        album_number = 0;
        grades = g;
    }

    void set_name(std::string n){ //setter
        name = n;
    }

    std::string get_name(){ //getter
        return name;
    }

    void set_surname(std::string s){ //setter
        surname = s;
    }

    std::string get_surname(){ //getter
        return surname;
    }

    void set_album_number(int a){ //setter
        if(a >= 10000 && a <= 999999)
            album_number = a;
    }

    int get_album_number(){ //getter
        return album_number;
    }

    void summary(){
        cout << "Student " << album_number << endl;
        cout << "\tName: " << name << endl;
        cout << "\tSurname: " << surname << endl;
        cout << "\tGrades: " << endl;
        for(int i = 0;i<grades.size();i++)
            cout << "\t\t" << grades[i] << endl;
        cout << endl;
    }

    float calculate_grade(){
        std::cout << "calculating grade for " << name << std::endl;
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return sum / grades.size();
    }

    bool add_grade(float grade){
        if(grade >= 2.0 && grade <= 5.0){
            grades.push_back(grade);
            return true;
        }
        return false;
    }

};



int main()
{

    Student student3;

    student3.set_name("tutkucan");
    std::cout << "student name is " << student3.get_name() << std::endl;
    Student student2{"mami", "es", {0.0,1.1}};
    student3.add_grade(4.5);
    student3.add_grade(3.5);


    float ave = student3.calculate_grade();

    std::cout << "ave grade is " << ave << std::endl;
    student2.summary();
    student3.summary();
    return 0;
}
