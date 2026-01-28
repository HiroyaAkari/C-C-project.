#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct User {
    string username;
    string password;
};

void registerUser();
bool loginUser();
void saveUser(const User& user);
bool userExists(const string& username);
vector<User> loadUsers();

int main() {
    int choice;
    
    while (true) {
        cout << "\n=== Registration System ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    cout << "\n✓ Login successful! Welcome!\n";
                } else {
                    cout << "\n✗ Invalid username or password.\n";
                }
                break;
            case 3:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }
    
    return 0;
}

void registerUser() {
    User newUser;
    
    cout << "\n--- Registration ---\n";
    cout << "Enter username: ";
    getline(cin, newUser.username);
    
    if (userExists(newUser.username)) {
        cout << "Username already taken!\n";
        return;
    }
    
    cout << "Enter password: ";
    getline(cin, newUser.password);
    
    if (newUser.username.empty() || newUser.password.empty()) {
        cout << "Username and password cannot be empty!\n";
        return;
    }
    
    saveUser(newUser);
    cout << "Registration successful!\n";
}

bool loginUser() {
    string username, password;
    
    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);
    
    vector<User> users = loadUsers();
    
    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            return true;
        }
    }
    return false;
}

void saveUser(const User& user) {
    ofstream file("users.txt", ios::app); 
    if (file.is_open()) {
        file << user.username << " " << user.password << endl;
    } else {
        cout << "Error saving user data!\n";
    }
}

bool userExists(const string& username) {
    vector<User> users = loadUsers();
    for (const auto& user : users) {
        if (user.username == username) {
            return true;
        }
    }
    return false;
}

vector<User> loadUsers() {
    vector<User> users;
    ifstream file("users.txt");
    User user;
    
    if (file.is_open()) {
        while (file >> user.username >> user.password) {
            users.push_back(user);
        }
        file.close();
    }
    return users;
}