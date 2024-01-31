#include <iostream>
#include <list>
#include <string>
#include <iomanip>
using namespace std;
class Joke {
public:
    Joke(string text) : text(text), votes(0), totalRating(0) {}


    void tellJoke() const {
        cout << "Жарт: " << text << std::endl;
        cout << "Оцінка: " << fixed << setprecision(2) << getAverageRating() << " (Голосів: " << votes << ")" << endl;
    }


    void rateJoke(int rating) {
        if (rating >= 1 && rating <= 5) {
            votes++;
            totalRating += rating;
        } else {
            cout << "Оцінка повинна бути від 1 до 5!" << endl;
        }
    }


    double getAverageRating() const {
        return (votes > 0) ? static_cast<double>(totalRating) / votes : 0.0;
    }


private:
    std::string text;
    int votes;
    int totalRating;
};


int main() {
    std::list<Joke> jokeList;
    int users = 1;
    // Додавання жартів до списку
    jokeList.push_back(Joke("Чому програмісти так погано сплять?"));
    jokeList.push_back(Joke("Тому що вони давно звикли до багів!"));
    jokeList.push_back(Joke("Що робить програміст після розставання?"));
    jokeList.push_back(Joke("Переходить на інший репозиторій!"));


    std::cout << "Ласкаво просимо до програми для оцінювання жартів!" << std::endl;


    // Оцінювання жартів
    bool firstUser = true;
    for (auto& joke : jokeList) {
        joke.tellJoke();
        int userRating;
        for(int i = 1;i<=users;i++)
        {


            cout<<"Користувач "<<i<<endl;
            if(firstUser)
            {
                do{
                cout<<"Оберіть кількість користувачів для голосування: ";
                cin>>users;
                }while(users<1);
                firstUser = false;
            }
            cout << "Ваша оцінка (1-5): ";
            cin >> userRating;
            if(userRating < 1)cout<<"Користувач "<<i<<" вирішив не голосувати\n";
            else joke.rateJoke(userRating);
        }
    }


    cout << "\nЖарти з високим рейтингом:" << endl;
    for (const auto& joke : jokeList) {
        if (joke.getAverageRating() >= 4.0) {
            joke.tellJoke();
        }
    }


    return 0;
}
