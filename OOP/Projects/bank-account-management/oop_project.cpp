// C++ console-based basic Bank Account Management System using OOP and file handling

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Account {
private:
    string accountHolder;
    string password;
    double balance;
    int accountID;
    static int nextID;

public:
    Account() {
        accountHolder = "Unknown";
        password = "";
        balance = 0.0;
        accountID = nextID;
        nextID++;
    }

    Account(string holder, string pass, double initialBalance) {
        accountHolder = holder;
        password = pass;
        balance = initialBalance;
        accountID = nextID;
        nextID++;
    }

    bool verifyPassword(string pass) {
        return password == pass;
    }

    double getBalance() {
        return balance;
    }

    int getAccountID() {
        return accountID;
    }

    string getAccountHolder() {
        return accountHolder;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Invalid deposit.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            cout << "Invalid withdrawal.\n";
        }
    }

    friend ostream& operator<<(ostream& os, Account& account) {
        os << account.getAccountID() << " " << account.getAccountHolder() << " " << account.password << " " << account.getBalance() << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Account& account) {
        is >> account.accountID >> account.accountHolder >> account.password >> account.balance;
        return is;
    }
};

int Account::nextID = 1;

void registerAccount() {
    string holder, pass;
    double initialBalance;

    cout << "Enter name: ";
    cin >> holder;
    cout << "Enter password: ";
    cin >> pass;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    Account newAccount(holder, pass, initialBalance);

    ofstream outFile("accounts.txt", ios::app);
    outFile << newAccount;
    cout << "Account created! ID: " << newAccount.getAccountID() << endl;
}

bool verifyAccount(int id, string password) {
    ifstream inFile("accounts.txt");
    Account account;
    while (inFile >> account) {
        if (account.getAccountID() == id && account.verifyPassword(password)) {
            return true;
        }
    }
    return false;
}

void deleteAccount(int id, string password) {
    ifstream inFile("accounts.txt");
    ofstream outFile("temp.txt");
    Account account;
    bool accountFound = false;

    char confirmation;
    cout << "Are you sure you want to delete this account? (y/n): ";
    cin >> confirmation;

    if (confirmation == 'y' || confirmation == 'Y') {
        while (inFile >> account) {
            if (account.getAccountID() != id || account.verifyPassword(password) == false) {
                outFile << account;
            } else {
                accountFound = true;
            }
        }

        inFile.close();
        outFile.close();

        if (accountFound) {
            remove("accounts.txt");
            rename("temp.txt", "accounts.txt");
            cout << "Account deleted successfully.\n";
        } else {
            cout << "Account not found.\n";
            remove("temp.txt");
        }
    } else {
        cout << "Account deletion cancelled.\n";
        remove("temp.txt");
    }
}

void updateAccountFile(Account updatedAccount) {
    ifstream inFile("accounts.txt");
    ofstream outFile("temp.txt");
    Account account;

    while (inFile >> account) {
        if (account.getAccountID() == updatedAccount.getAccountID()) {
            outFile << updatedAccount;
        } else {
            outFile << account;
        }
    }

    inFile.close();
    outFile.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
}

void performTransaction(Account& account) {
    int choice;
    cout << "1. Deposit Money\n2. Withdraw Money\nEnter your choice: ";
    cin >> choice;

    double amount;
    if (choice == 1) {
        cout << "Enter amount to deposit: ";
        cin >> amount;
        account.deposit(amount);
        cout << "Deposited successfully.\n";
    } else if (choice == 2) {
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        account.withdraw(amount);
        cout << "Withdrawn successfully.\n";
    } else {
        cout << "Invalid choice.\n";
    }

    updateAccountFile(account);
}

void displayAccountDetails(Account account) {
    cout << "Account ID: " << account.getAccountID() << "\nAccount Holder: " << account.getAccountHolder() << "\nBalance: " << account.getBalance() << endl;
}

void loginAccount() {
    int id;
    string password;

    cout << "Enter your Account ID: ";
    cin >> id;
    cout << "Enter your password: ";
    cin >> password;

    ifstream inFile("accounts.txt");
    Account loggedInAccount;
    bool loggedIn = false;

    while (inFile >> loggedInAccount) {
        if (loggedInAccount.getAccountID() == id && loggedInAccount.verifyPassword(password)) {
            loggedIn = true;
            break;
        }
    }

    inFile.close();

    if (loggedIn) {
        cout << "Login successful!\n";

        int loginChoice;
        do {
            cout << "\n--- Submenu ---\n";
            cout << "1. Perform Transactions\n";
            cout << "2. Display Account Details\n";
            cout << "3. Delete Account\n";
            cout << "4. Logout\n";
            cout << "Enter your choice: ";
            cin >> loginChoice;

            string enteredPassword;
            cout << "Enter your password to confirm: ";
            cin >> enteredPassword;

            if (enteredPassword == password) {
                if (loginChoice == 1) {
                    performTransaction(loggedInAccount);
                } else if (loginChoice == 2) {
                    displayAccountDetails(loggedInAccount);
                } else if (loginChoice == 3) {
                    deleteAccount(id, password);
                    loggedIn = false;
                } else if (loginChoice == 4) {
                    cout << "Logging out...\n";
                    loggedIn = false;
                } else {
                    cout << "Invalid choice.\n";
                }
            } else {
                cout << "Incorrect password.\n";
            }
        } while (loggedIn);
    } else {
        cout << "Invalid Account ID or Password.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Register Account\n";
        cout << "2. Login Account\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            registerAccount();
        } else if (choice == 2) {
            loginAccount();
        } else if (choice == 3) {
            cout << "Thank you! Goodbye.\n";
        } else {
            cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}
