#include <iostream>
#include <string>
using namespace std;

// ----------- Exception Class ----------
class OutOfStockException : public runtime_error {
public:
    OutOfStockException(const string &msg): runtime_error(msg) {}
};

// ----------- Book Class ----------
class Book {
private:
    string title;
    string author;
    string isbn;
    int copies;
    int year;

public:
    // Constructors
    Book(): title("Unknown"), author("Unknown"), isbn("0000"), copies(0), year(0) {}
    Book(string t, string a, string i, int c, int y): title(t), author(a), isbn(i), copies(c), year(y) {}
    Book(const Book &b): title(b.title), author(b.author), isbn(b.isbn), copies(b.copies), year(b.year) {}

    // Destructor
    ~Book() {}

    // Getters
    string getTitle() const { return title; }
    int getCopies() const { return copies; }

    // Setters
    void setCopies(int c) { copies = c; }

    // Borrow a book
    void borrowBook() {
        if(copies <= 0) throw OutOfStockException("No copies available for " + title);
        copies--;
    }

    // Return a book
    void returnBook() { copies++; }

    // Display book info
    void display() const {
        cout << title << " | " << author << " | " << isbn << " | Copies: " << copies << " | Year: " << year << endl;
    }

    // Operator overloading to print a book
    friend ostream& operator<<(ostream &os, const Book &b) {
        os << b.title << " | " << b.author << " | " << b.isbn << " | Copies: " << b.copies;
        return os;
    }
};

// ----------- Inventory Class ----------
class Inventory {
private:
    Book *books; // dynamic array pointer
    int size;
    int capacity;

    // Grow the array if full
    void grow() {
        int newCap = (capacity == 0) ? 2 : capacity * 2;
        Book *temp = new Book[newCap];
        for(int i = 0; i < size; i++)
            *(temp + i) = *(books + i); // pointer arithmetic
        delete[] books;
        books = temp;
        capacity = newCap;
    }

public:
    Inventory(): books(nullptr), size(0), capacity(0) {}
    ~Inventory() { delete[] books; }

    // Add book - function overloading
    void addBook(const Book &b) {
        if(size >= capacity) grow();
        books[size++] = b;
    }
    void addBook(string t, string a, string i, int c, int y) {
        Book b(t, a, i, c, y);
        addBook(b);
    }

    // List all books
    void listBooks() {
        for(int i = 0; i < size; i++)
            cout << *(books + i) << endl;
    }

    // Borrow book
    void borrowBook(string title) {
        for(int i = 0; i < size; i++) {
            if((books + i)->getTitle() == title) {
                (books + i)->borrowBook();
                return;
            }
        }
        throw OutOfStockException("Book not found: " + title);
    }

    // Return book
    void returnBook(string title) {
        for(int i = 0; i < size; i++) {
            if((books + i)->getTitle() == title) {
                (books + i)->returnBook();
                return;
            }
        }
        cout << "Book not found to return: " << title << endl;
    }

    // Merge inventories using operator+
    Inventory operator+(const Inventory &other) {
        Inventory merged;
        for(int i = 0; i < size; i++) merged.addBook(books[i]);
        for(int i = 0; i < other.size; i++) merged.addBook(other.books[i]);
        return merged;
    }

    // 2D array demo (weekly borrow schedule)
    static void demoSchedule() {
        string schedule[7][2];
        for(int d = 0; d < 7; d++) {
            schedule[d][0] = "Morning: None";
            schedule[d][1] = "Evening: None";
        }
        schedule[0][0] = "Borrow: C++ Book";
        cout << "\nWeekly Borrow Schedule:\n";
        for(int d = 0; d < 7; d++)
            cout << "Day " << d + 1 << ": " << schedule[d][0] << " | " << schedule[d][1] << endl;
    }
};

// ----------- Person Base Class ----------
class Person {
protected:
    string name;
public:
    Person(string n = "Unknown"): name(n) {}
    virtual void showRole() { cout << name << " is a person." << endl; }
    virtual ~Person() {}
};

// ----------- User Class ----------
class User : public Person {
private:
    Inventory personalInventory;
public:
    User(string n = "User"): Person(n) {}
    Inventory& getInventory() { return personalInventory; }
    void showRole() override { cout << name << " (User) manages personal books." << endl; }
};

// ----------- Admin Class ----------
class Admin : public Person {
public:
    Admin(string n = "Admin"): Person(n) {}
    Inventory mergeInventories(Inventory &a, Inventory &b) { return a + b; }
    void showRole() override { cout << name << " (Admin) manages library." << endl; }
};

// ----------- Main Function ----------
int main() {
    cout << "Welcome to Simple LMS\n";

    User u("Alice");
    Admin a("LibraryAdmin");

    u.getInventory().addBook("C++ Basics", "John", "123", 5, 2023);
    u.getInventory().addBook("OOP Concepts", "Alice", "234", 3, 2022);

    cout << "\nUser Inventory:\n";
    u.getInventory().listBooks();

    // Borrow a book
    try {
        u.getInventory().borrowBook("C++ Basics");
        cout << "\nBorrowed 'C++ Basics'\n";
    } catch(const OutOfStockException &e) {
        cout << e.what() << endl;
    }

    u.getInventory().listBooks();

    // Merge demo
    Inventory lib1, lib2;
    lib1.addBook("Python", "Ann", "345", 4, 2023);
    lib2.addBook("Java", "Bob", "456", 2, 2021);
    Inventory merged = a.mergeInventories(lib1, lib2);
    cout << "\nMerged Inventory:\n";
    merged.listBooks();

    // 2D Array demo
    Inventory::demoSchedule();

    return 0;
}
