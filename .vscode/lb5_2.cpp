#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<std::string> favoriteFruits;
    char order;
    cout << "Ласкаво просимо до гри 'Сортування фруктів'!" << endl;
    cout << "Введіть свої улюблені фрукти (введіть 'кінець', щоб завершити введення):" << endl;


    std::string fruit;
    while (true) {
        cout << "Фрукт: ";
        cin >> fruit;


        // Перевірка на вихід з гри
        if (fruit == "кінець") {
            break;
        }


        favoriteFruits.push_back(fruit);
    }
    do{
       cout<<"Виберіть порядок сортування фруктів:";
       cout<<"1 - за алфавітом"<<endl;
       cout<<"2 - проти алфавіту"<<endl;
       cin>>order;
    }while(order<49&&order>50);
   
   
    // Сортування фруктів за алфавітом
    switch(order)
    {
        case '1':
            sort(favoriteFruits.begin(), favoriteFruits.end());
        break;
       
        case '2':
            sort(favoriteFruits.rbegin(), favoriteFruits.rend());
        break;
       
        default:
            cout<<"unknown symbol";
            exit(1);
        break;
    }




    cout << "\nВаші улюблені фрукти в алфавітному порядку:" << endl;
    for (const auto& favoriteFruit : favoriteFruits) {
        cout << favoriteFruit << endl;
       
    }


    cout << "Гра завершена. Дякуємо за участь!" << endl;


    return 0;
}
