#include <iostream>
#include <vector>
using namespace std;

struct Book {
    int barcode;
    string title;
    int year;
    int rating;
};

vector<Book> books;

string getCategory(int rating){
    if(rating == 5) return "Excellent";
    else if(rating == 4) return "Very Good";
    else if(rating == 3) return "Good";
    else if(rating == 2) return "Fair";
    else if(rating == 1) return "Poor";
    else return "No Rating";
}

bool barcodeExists(int code){
    for(int i=0;i<books.size();i++){
        if(books[i].barcode == code)
            return true;
    }
    return false;
}

void addBook(){
    Book b;

    cout << "Enter Barcode: ";
    cin >> b.barcode;

    if(barcodeExists(b.barcode)){
        cout << "Barcode already exists!\n";
        return;
    }

    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, b.title);

    cout << "Enter Year: ";
    cin >> b.year;

    cout << "Enter Rating (0-5): ";
    cin >> b.rating;

    books.push_back(b);
    cout << "Book Added Successfully!\n";
}

void displayBooks(){
    cout << "\nBarcode\tTitle\tYear\tRating\tCategory\n";
    for(int i=0;i<books.size();i++){
        cout << books[i].barcode << "\t"
             << books[i].title << "\t"
             << books[i].year << "\t"
             << books[i].rating << "\t"
             << getCategory(books[i].rating) << endl;
    }
}

void deleteBook(){
    int code;
    cout << "Enter Barcode to delete: ";
    cin >> code;

    for(int i=0;i<books.size();i++){
        if(books[i].barcode == code){
            books.erase(books.begin()+i);
            cout << "Deleted Successfully!\n";
            return;
        }
    }

    cout << "Book not found!\n";
}

void editBook(){
    int code;
    cout << "Enter Barcode to edit: ";
    cin >> code;

    for(int i=0;i<books.size();i++){
        if(books[i].barcode == code){

            cin.ignore();
            cout << "Enter New Title: ";
            getline(cin, books[i].title);

            cout << "Enter New Year: ";
            cin >> books[i].year;

            cout << "Enter New Rating: ";
            cin >> books[i].rating;

            cout << "Updated Successfully!\n";
            return;
        }
    }

    cout << "Book not found!\n";
}

int main(){
    int choice;

    do{
        cout << "\n===== MENU =====\n";
        cout << "1. Add Book\n";
        cout << "2. Edit Book\n";
        cout << "3. Delete Book\n";
        cout << "4. Display Books\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1: addBook(); break;
            case 2: editBook(); break;
            case 3: deleteBook(); break;
            case 4: displayBooks(); break;
            case 5: cout<<"Goodbye!\n"; break;
            default: cout<<"Invalid choice!\n";
        }

    }while(choice != 5);

    return 0;
}