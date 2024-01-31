#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Book {
public:
    Book(string title, string author, int year) : title(title), author(author), year(year) {}


    void displayInfo() const {
        cout << "Книга: " << title << ", Автор: " << author << ", Рік: " << year <<endl;
    }
    void setTitle(string title){this->title = title;}
    void setAuthor(string author){this->author = author;}
    void setYear(int year){this->year = year;}
    // Оператор порівняння за назвою книги
    bool operator<(const Book& other) const {
        return title < other.title;
    }


private:
    string title;
    string author;
    int year;
};


void redact(Book &book)
{
    string newTitle,newAuthor;
    int newYear;
    cout<<"Enter new title: ";cin>>newTitle;
    book.setTitle(newTitle);
    cout<<"Enter new author: ";cin>>newAuthor;
    book.setAuthor(newAuthor);
    cout<<"Enter new year: ";cin>>newYear;
    book.setYear(newYear);
}


void displayLibrary(vector<Book>library)
{
    std::cout << "Інформація про книги в бібліотеці:" << endl;
    for (const auto& book : library) {
        book.displayInfo();
    }
}


void deleteBook(vector<Book>&library, int index)
{
    if(index>=0&&index<library.size())
    {
        library.erase(library.begin()+index);
    }
    else cout<<"Book not found\n";
}
int main() {
    vector<Book> library;
   
    library.push_back(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.push_back(Book("1984", "George Orwell", 1949));
    library.push_back(Book("The Catcher in the Rye", "J.D. Salinger", 1951));
   
    displayLibrary(library);
    redact(library[1]);
    displayLibrary(library);
    deleteBook(library,1);
    displayLibrary(library);
   
    // Використовуємо std::sort для сортування за назвою книги
    sort(library.begin(), library.end());


    cout << "\nБібліотека після сортування за назвою книги:" << endl;
    displayLibrary(library);


    return 0;
}
