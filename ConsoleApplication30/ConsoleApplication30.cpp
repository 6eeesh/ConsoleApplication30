#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int day; // Represents the day in the date.
    int month; // Represents the month in the date.
    int year; // Represents the year in the date.

public:
    Date() : day(1), month(1), year(1900) {}// Default constructor setting initial date to 01/01/1900.
};

class Student {
private:
    string last_name; // Holds the student's last name.
    string first_name; // Holds the student's first name.
    string middle_name; // Holds the student's middle name.
    Date birth_date; // Stores the student's birth date.
    string home_address; // Holds the student's home address.
    string phone_number; // Holds the student's phone number.
    int* gradesMath; // Dynamic array to store math grades.
    int* gradesPhysicalEducation; // Dynamic array to store physical education grades.
    int* gradesChemistry; // Dynamic array to store chemistry grades.
    int maxGrades; // Maximum number of grades that can be stored.

public:
    Student(string first, string last, int max) : first_name(first), last_name(last), maxGrades(max)
        // Constructor initializing student information and dynamic arrays for grades.
    {
        gradesMath = new int[max]();
        gradesPhysicalEducation = new int[max]();
        gradesChemistry = new int[max]();
    }

    void SetBirthDate(const Date& date) {
        birth_date = date; // Sets the student's birth date.
    }

    Date GetBirthDate() const {
        return birth_date; // Retrieves the student's birth date.
    }

    void SetHomeAddress(const string& address) {
        home_address = address; // Sets the student's home address.
    }

    string GetHomeAddress() const {
        return home_address; // Retrieves the student's home address.
    }

    void SetPhoneNumber(const string& phone) {
        phone_number = phone; // Sets the student's phone number.
    }

    string GetPhoneNumber() const {
        return phone_number; // Retrieves the student's phone number.
    }

    void SetLastName(const string& last) {
        last_name = last; // Sets the student's last name.
    }

    string GetLastName() const {
        return last_name; // Retrieves the student's last name.
    }

    void AddMathGrade(int subject_index, int grade) {
        if (subject_index >= 0 && subject_index < maxGrades) {
            gradesMath[subject_index] = grade; // Sets the math grade for a specific subject index.
        }
    }

    int GetMathGrade(int subject_index) const {
        if (subject_index >= 0 && subject_index < maxGrades) {
            return gradesMath[subject_index]; // Retrieves the math grade for a specific subject index.
        }
        return -1; // Returns -1 if the subject index is out of range.
    }

    void AddPhysicalEducationGrade(int subject_index, int grade) {
        if (subject_index >= 0 && subject_index < maxGrades) {
            gradesPhysicalEducation[subject_index] = grade; // Sets the physical education grade for a specific subject index.
        }
    }

    int GetPhysicalEducationGrade(int subject_index) const {
        if (subject_index >= 0 && subject_index < maxGrades) {
            return gradesPhysicalEducation[subject_index]; // Retrieves the physical education grade for a specific subject index.
        }
        return -1; // Returns -1 if the subject index is out of range.
    }

    void AddChemistryGrade(int subject_index, int grade) {
        if (subject_index >= 0 && subject_index < maxGrades) {
            gradesChemistry[subject_index] = grade; // Sets the chemistry grade for a specific subject index.
        }
    }

    int GetChemistryGrade(int subject_index) const {
        if (subject_index >= 0 && subject_index < maxGrades) {
            return gradesChemistry[subject_index]; // Retrieves the chemistry grade for a specific subject index.
        }
        return -1; // Returns -1 if the subject index is out of range.
    }

    void ShowStudentInfo() const {// Displays the student's information, including name, birth date, address, phone number, and grades in different subjects.
        cout << "Фамилия: " << last_name << endl;
        cout << "Имя: " << first_name << endl;
        cout << "Отчество: " << middle_name << endl;
        cout << "Дата рождения: " << birth_date << endl;
        cout << "Домашний адрес: " << home_address << endl;
        cout << "Телефонный номер: " << phone_number << endl;

        cout << "Оценки по математике: ";
        for (int i = 0; i < maxGrades; i++) {
            cout << gradesMath[i] << " ";
        }
        cout << endl;

        cout << "Оценки по физкультуре: ";
        for (int i = 0; i < maxGrades; i++) {
            cout << gradesPhysicalEducation[i] << " ";
        }
        cout << endl;

        cout << "Оценки по химии: ";
        for (int i = 0; i < maxGrades; i++) {
            cout << gradesChemistry[i] << " ";
        }
        cout << endl;
    }


    ~Student() {
        // Destructor to release dynamically allocated memory for grades arrays.
        delete[] gradesMath;
        delete[] gradesPhysicalEducation;
        delete[] gradesChemistry;
    }
};

int main() {
    setlocale(LC_ALL, "");
    int maxGrades = 99;

    Student student("Антон", "Васильев", maxGrades);

    student.SetBirthDate(Date(1900, 1, 1));
    student.SetHomeAddress("ул. Добровольского, 123");
    student.SetPhoneNumber("+38(097)264-18-54");

    student.AddMathGrade(0, 95);
    student.AddMathGrade(1, 88);

    student.AddPhysicalEducationGrade(0, 85);
    student.AddPhysicalEducationGrade(1, 90);

    student.AddChemistryGrade(0, 75);
    student.AddChemistryGrade(1, 80);

    student.ShowStudentInfo();

    student.SetLastName("Петров");
    student.SetPhoneNumber("+38(097)234-13-24");

    cout << "Измененная фамилия: " << student.GetLastName() << endl;
    cout << "Измененный телефонный номер: " << student.GetPhoneNumber() << endl;

    return 0;
}
