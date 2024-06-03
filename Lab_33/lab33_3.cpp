#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Library {
private:
    string bookTitle;
    string author;
    int pages;
    double price;

public:
    Library() : bookTitle(""), author(""), pages(0), price(0.0) {}
    Library(const string& title, const string& auth, int p, double pr) : bookTitle(title), author(auth), pages(p), price(pr) {}

    string getAuthor() const {
        return author;
    }

    double getPrice() const {
        return price;
    }

    // Custom sort function to sort books by author and starting with 'A'
    void customSort(Library books[], int size) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (books[j].author > books[j + 1].author) {
                    swap(books[j], books[j + 1]);
                }
            }
        }

        ofstream outFile("sorted_books.txt");
        if (outFile.is_open()) {
            for (int i = 0; i < size; ++i) {
                if (books[i].author[0] == 'A') {
                    outFile << "Title: " << books[i].bookTitle << ", Author: " << books[i].author << ", Pages: " << books[i].pages << ", Price: " << books[i].price << endl;
                }
            }
            outFile.close();
        } else {
            cerr << "Unable to open file!" << endl;
        }
    }

    void deleteMostExpensive(Library books[], int& size) {
        if (size == 0) return;

        int maxIndex = 0;
        double maxPrice = books[0].price;
        for (int i = 1; i < size; ++i) {
            if (books[i].price > maxPrice) {
                maxPrice = books[i].price;
                maxIndex = i;
            }
        }

        for (int i = maxIndex; i < size - 1; ++i) {
            books[i] = books[i + 1];
        }
        size--;
    }

    double costPerPage() const {
        if (pages == 0) return 0;
        return price / pages;
    }
};

int main() {
    const int numBooks = 4;
    Library books[numBooks] = {
        Library("Harry Potter", "Rowling", 360, 26.00),
        Library("Mermaid", "Andersen", 240, 14.75),
        Library("Don Quixote", "Cervantes", 420, 30.20),
        Library("Hitchhiker`s guide to the galaxy", "Adams", 290, 24.50)
    };

    cout << "Books sorted by author and starting with 'A':" << endl;
    books[0].customSort(books, numBooks);

    int size = numBooks;
    books[0].deleteMostExpensive(books, size);
    cout << "Books after deleting the most expensive one:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Title: " << books[i].getAuthor() << ", Price: " << books[i].getPrice() << endl;
    }

    cout << "Cost per page of Book1: $" << books[0].costPerPage() << endl;

    return 0;
}

