#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string USER_DB = "users.txt";

// Function to check if username exists
bool usernameExists(const string &username) {
    ifstream file(USER_DB);
    string u, p;
    while (file >> u >> p) {
        if (u == username) return true;
    }
    return false;
}

// Register Function
void registerUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Validation
    if (username.empty() || password.empty()) {
        cout << "Username or password cannot be empty!\n";
        return;
    }

    // Check duplicate username
    if (usernameExists(username)) {
        cout << "Username already exists. Try another.\n";
        return;
    }

    // Store user credentials
    ofstream file(USER_DB, ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

// Login Function
void loginUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file(USER_DB);
    string u, p;
    while (file >> u >> p) {
        if (u == username && p == password) {
            cout << "Login successful!\n";
            return;
        }
    }

    cout << "Invalid username or password.\n";
}

// Main Menu
int main() {
    int choice;

    while (true) {
        cout << "\n--- LOGIN SYSTEM ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser();     break;
            case 3: cout << "Exiting..."; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
