
#include <iostream>
using namespace std;

int main() {
    int pin = 1234;  // current PIN
    int enteredPIN;
    int attempts = 0;
    const int maxAttempts = 3;

    // PIN check
    while (attempts < maxAttempts) {
        cout << "Enter your 4-digit PIN: ";
        cin >> enteredPIN;

        if (enteredPIN == pin) {
            cout << "PIN accepted. Access granted.\n";
            break;
        } else {
            attempts++;
            cout << "Incorrect PIN. Attempts left: " << (maxAttempts - attempts) << "\n";
        }
    }

    if (attempts == maxAttempts) {
        cout << "Too many incorrect attempts. Your account has been locked.\n";
        return 0;
    }

    // ATM menu
    double balance = 1000.00;
    int choice;
    double amount;

    while (true) {
        cout << "\n===== Simple ATM Menu =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Log Out\n";
        cout << "5. Change PIN\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nYour current balance is: $" << balance << endl;
        }
        else if (choice == 2) {
            cout << "\nEnter amount to deposit: $";
            cin >> amount;
            if (amount > 0) {
                balance += amount;
                cout << "Deposit successful. New balance: $" << balance << endl;
            } else {
                cout << "Invalid deposit amount!" << endl;
            }
        }
        else if (choice == 3) {
            cout << "\nEnter amount to withdraw: $";
            cin >> amount;
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                cout << "Withdrawal successful. New balance: $" << balance << endl;
            } else if (amount <= 0) {
                cout << "Invalid withdrawal amount!" << endl;
            } else {
                cout << "Insufficient funds!" << endl;
            }
        }
        else if (choice == 4) {
            cout << "\nYou have successfully logged out. Please take your card.\n";
            break;
        }
        else if (choice == 5) {
            int oldPIN, newPIN;

            cout << "\nEnter current PIN: ";
            cin >> oldPIN;

            if (oldPIN == pin) {
                cout << "Enter new 4-digit PIN: ";
                cin >> newPIN;

                if (newPIN >= 1000 && newPIN <= 9999) {
                    pin = newPIN;
                    cout << "PIN successfully changed.\n";
                } else {
                    cout << "Invalid PIN format. PIN must be a 4-digit number.\n";
                }
            } else {
                cout << "Incorrect current PIN. Cannot change PIN.\n";
            }
        }
        else {
            cout << "\nInvalid choice. Please try again.\n";
        }
    }

    return 0;
}
