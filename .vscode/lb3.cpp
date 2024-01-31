#include<iostream>
#include <vector>
#include <conio.h>
using namespace std;


class Character {
protected:
    string name;
    int health;
    int power;
public:
    Character(string _name, int _health, int _power) : name(_name), health(_health), power(_power) {}


    string getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    int getPower() {
        return power;
    }
    bool isAlive() {
        return health > 0;
    }


    void takeDamage(int damage) {
        health -= damage;
    }


    bool attack(Character& target) {
        int damage = rand() % power + 1;
        cout << name << " attacks " << target.getName() << " for " << damage << " damage " << endl;
        target.takeDamage(damage);
        if (!target.isAlive()) {
            cout << "\n" << target.name << " is Defeated!\n\n";
        }
        return target.isAlive();
    }


};


class Hero : public Character {
public:
    Hero(string _name, int _health, int _power) : Character(_name, _health, _power) {}


    bool heroAttack(Character& target) {
        cout << name << " shouts a heroic battle cry!" << endl;
        return attack(target);
    }
};


class Monster : public Character {
public:
    Monster(string _name, int _health, int _power) : Character(_name, _health, _power) {}


    bool monsterAttack(Character& target) {
        cout << name << " growls menacingly!" << endl;
        return attack(target);
    }
};


void menu()
{
    cout << "1.Create heroes and monsters\n";
    cout << "2.Start fight\n";
    cout << "3.Info about monster/hero\n";
    cout << "4. Attack order\n";
    cout << "Esc - i dont wanna play anymor\n";


}


void create(vector<Hero>& heroes, vector<Monster>& monsters)
{
    int heros=0, mobs=0;
    string name;
    int health, power;
    if (heroes.empty() && monsters.empty()) {
        while (heros < 1 && mobs < 1)
        {
            cout << "Amount of heroes: ";cin >> heros;
            cout << "Amount of monsters: ";cin >> mobs;
        }


        for (int i = 1; i < heros + 1;i++)
        {
            cout << "Hero " << i << ":\n";
            cout << "Name: ";cin >> name;
            cout << "Health: ";cin >> health;
            cout << "Power: ";cin >> power;
            heroes.push_back(Hero(name, health, power));
        }
        for (int i = 1; i < mobs + 1;i++)
        {
            cout << "Monster " << i << ":\n";
            cout << "Name: ";cin >> name;
            cout << "Health: ";cin >> health;
            cout << "Power: ";cin >> power;
            monsters.push_back(Monster(name, health, power));
        }
    }
   
}


void heroFight(vector<Hero>& heroes, vector<Monster>& monsters)
{
    for (int i = 0; i < heroes.size(); i++) {
        if (!monsters.empty()) {
            int indexMonster = rand() % monsters.size();
            do
            {
                cout << heroes[i].getName() << ": \n";
                cout << "Choose monster to attack: \n";
                for (int i = 0; i < monsters.size();i++)
                {
                    cout << "Monster " << i << ": " << "\nName: " << monsters[i].getName() << "\nHP: " << monsters[i].getHealth() << "\nPower: " << monsters[i].getPower() << endl << endl;
                }
                cin >> indexMonster;
            } while (indexMonster < 0 || indexMonster > monsters.size());
           
            bool attack = !heroes[i].heroAttack(monsters[indexMonster]);
            if (attack) {
                monsters.erase(monsters.begin() + indexMonster);
            }


        }
    }
   
}


void monsterFight(vector<Hero>& heroes, vector<Monster>& monsters)
{
    for (int i = 0; i < monsters.size(); i++) {
        if (!heroes.empty()) {
            int heroIndex = rand() % heroes.size();
            bool attack = !monsters[i].monsterAttack(heroes[heroIndex]);
            if (attack) {
                heroes.erase(heroes.begin() + heroIndex);
            }
        }
    }
}


void fight(vector<Hero>& heroes, vector<Monster>& monsters, bool heroesFirst = true)
{
    while (!heroes.empty() && !monsters.empty()) {


        if (heroesFirst == true)
        {
            heroFight(heroes, monsters);
            monsterFight(heroes, monsters);
        }
        else
        {
            monsterFight(heroes, monsters);
            heroFight(heroes, monsters);
        }


    }


    if (heroes.empty()) {
        cout << "Monsters win!" << endl;
        for (int i = 0; i < monsters.size();i++) {
            monsters.pop_back();
        }
    }
    else {
        cout << "Heroes win!" << endl;
        for (int i = 0; i < heroes.size();i++) {
            heroes.pop_back();
        }
    }
}


void showChar(vector<Hero> heroes, vector<Monster> monsters) {
    char c;
    int index;
    cout << "To see information about hero or monster type 'h' for hero or 'm' for monster and their index: \n";
    cin >> c >> index;
    switch (c)
    {
    case 'h':
        if (index >= heroes.size() || index < 0) {
            cout << "there is no hero under that index.\n";
        }
        else
        {
            cout << "Name: " << heroes[index].getName() << endl;
            cout << "Health: " << heroes[index].getHealth() << endl;
            cout << "Power: " << heroes[index].getPower() << endl;
        }
        break;
    case 'm':
        if (index >= monsters.size() || index < 0) {
            cout << "there is no monster under that index.\n";
        }
        else
        {
            cout << "Name: " << monsters[index].getName() << endl;
            cout << "Health: " << monsters[index].getHealth() << endl;
            cout << "Power: " << monsters[index].getPower() << endl;
        }
    default:
        cout << "Unknown symbol";
        break;
    }
}


void chooseOrder(bool& order)
{
    char choose;
    do {
        cout << "1.Monsters\n";
        cout << "2.Heroes\n";
        choose = _getch();
    } while (choose < 31 && choose >32);
    switch (choose)
    {
    case '1':
        order = false;
        break;
    case '2':
        order = true;
        break;
    default:
        break;
    }
}
int main() {
    char symb;
    bool order = true;
    srand(static_cast<unsigned>(time(nullptr)));
    vector<Hero> heroes;
    vector<Monster>monsters;
    do {
        do {
            menu();
            symb = _getch();
        } while (symb < 31 && symb > 34 && symb != 27);
        switch (symb)
        {
        case '1':
            create(heroes, monsters);
            break;
        case '2':
            fight(heroes, monsters, order);
            break;
        case '3':
            showChar(heroes, monsters);
            break;
        case '4':
            chooseOrder(order);
            break;
        default:
            break;
        }
    }while (symb != 27);






    return 0;




}
