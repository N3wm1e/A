#include <iostream>
#include <map>
#include<vector>
#include <string>
using namespace std;
int main() {
    // Створення словника для зберігання середніх балів студентів
    map<string, double> studentGrades;
    vector<string>searchJournal;
    // Додавання даних до словника
    studentGrades["Анна"] = 4.5;
    studentGrades["Борис"] = 3.8;
    studentGrades["Катерина"] = 4.2;
    studentGrades["Дмитро"] = 4.0;


    // Вивід даних про студентів
    cout << "Інформація про студентів:" << endl;
    for (const auto& student : studentGrades) {
        cout << student.first << ": " << student.second << endl;
    }


    // Пошук і вивід середнього балу для певного студента
    string searchStudent;
    for(int i = 0; i< 5;i++)
    {
        cout << "\nВведіть ім'я студента для пошуку середнього балу: ";
        cin >> searchStudent;
        searchJournal.push_back(searchStudent);
        auto it = studentGrades.find(searchStudent);
        if (it != studentGrades.end()) {
            cout << "Середній бал студента " << searchStudent << ": " << it->second << endl;
        } else {
            cout << "Студент з іменем " << searchStudent << " не знайдений." << endl;
        }
    }


    cout<<"Пошуковий журнал запитів користувача: "<<endl;
    for(auto&res:searchJournal)
    {
        cout<<res<<endl;
    }


    return 0;
}
