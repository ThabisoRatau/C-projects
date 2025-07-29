#include <iostream>
#include <string>
#include <map>

using namespace std;

// Structure to represent a user account
struct Account {
    string accountNumber;
    string pin;
    double balance;
};

// Map to store user accounts
map<string, Account> accounts;

// Function to create a new account
void createAccount() {
    Account newAccount;
    cout << "Enter account number: ";
    cin >> newAccount.accountNumber;
    cout << "Enter PIN: ";
    cin >> newAccount.pin;
    newAccount.balance = 0.0;
    accounts[newAccount.accountNumber] = newAccount;
    cout << "Account created successfully!" << endl;
}

// Function to login to an existing account
bool login(string& accountNumber, string& pin) {
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter PIN: ";
    cin >> pin;

    // Check if account exists and PIN is correct
    if (accounts.find(accountNumber) != accounts.end() && accounts[accountNumber].pin == pin) {
        return true;
    } else {
        cout << "Invalid account number or PIN." << endl;
        return false;
    }
}

// Function to deposit money
void deposit(string accountNumber) {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    // Validate amount
    if (amount > 0) {
        accounts[accountNumber].balance += amount;
        cout << "Deposit successful. New balance: " << accounts[accountNumber].balance << endl;
    } else {
        cout << "Invalid amount." << endl;
    }
}

// Function to withdraw money
void withdraw(string accountNumber) {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    // Validate amount and check balance
    if (amount > 0 && accounts[accountNumber].balance >= amount) {
        accounts[accountNumber].balance -= amount;
        cout << "Withdrawal successful. New balance: " << accounts[accountNumber].balance << endl;
    } else if (amount > accounts[accountNumber].balance) {
        cout << "Insufficient balance." << endl;
    } else {
        cout << "Invalid amount." << endl;
    }
}

// Function to check balance
void checkBalance(string accountNumber) {
    cout << "Your balance: " << accounts[accountNumber].balance << endl;
}

// Function to change PIN
void changePin(string accountNumber) {
    string newPin;
    cout << "Enter new PIN: ";
    cin >> newPin;
    accounts[accountNumber].pin = newPin;
    cout << "PIN changed successfully!" << endl;
}

int main() {
    // Create a sample account
    Account sampleAccount;
    sampleAccount.accountNumber = "12345";
    sampleAccount.pin = "1234";
    sampleAccount.balance = 1000.0;
    accounts[sampleAccount.accountNumber] = sampleAccount;

    string accountNumber;
    string pin;
    int choice;

    while (true) {
        cout << "ATM Simulator/Banking System" << endl;
        cout << "1. Login" << endl;
        cout << "2. Create account" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (login(accountNumber, pin)) {
                    while (true) {
                        cout << "Account Menu" << endl;
                        cout << "1. Deposit" << endl;
                        cout << "2. Withdraw" << endl;
                        cout << "3. Check balance" << endl;
                        cout << "4. Change PIN" << endl;
                        cout << "5. Logout" << endl;
                        cout << "Enter your choice: ";
                        cin >> choice;

                        switch (choice) {
                            case 1:
                                deposit(accountNumber);
                                break;
                            case 2:
                                withdraw(accountNumber);
                                break;
                            case 3:
                                checkBalance(accountNumber);
                                break;
                            case 4:
                                changePin(accountNumber);
                                break;
                            case 5:
                                cout << "Logged out successfully!" << endl;
                                return main();
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                        }
                    }
                }
                break;
            case 2:
                createAccount();
                break;
            case 3:
                return
