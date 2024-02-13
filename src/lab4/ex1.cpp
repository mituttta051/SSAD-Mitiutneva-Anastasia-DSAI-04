#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Account {
private:
    int accountNumber;
    double balance;
    string ownerName;
public:
    Account() = default;
    Account(int accountNumber, double balance, string ownerName) {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->ownerName = ownerName;
    }
    Account(Account& a) = delete;
    Account& operator= (const Account&) = delete;
    void deposit(double money) {
        balance += money;
    }
    void withdraw(double money) {
        if (balance - money < 0) {
            balance = 0;
        } else {
            balance -= money;
        }
    }
    double getBalance() const {
        return this->balance;
    }
    int getAccountNumber() const {
        return this->accountNumber;
    }
    string getOwnerName() const {
        return this->ownerName;
    }
    void setBalance(double balance) {
        this->balance = balance;
    }
};

class SavingAccount : public Account {
private:
    double interestRate;
public:
    SavingAccount(int accountNumber, double balance, string ownerName, double interestRate) : Account(accountNumber, balance, ownerName) {
        this->interestRate = interestRate;
    }
    void calculateInterest() {
        setBalance(this->getBalance()*interestRate);
    };
    double getInterestRate() const {
        return interestRate;
    };
};
int main() {
    // Usage example
    SavingAccount savings(123456, 1000.0, "John Doe", 2.5);
    savings.deposit(500.0);
    savings.withdraw(200.0);
    savings.calculateInterest();

    cout << "Account Number: " << savings.getAccountNumber() << endl;
    cout << "Owner's Name: " << savings.getOwnerName() << endl;
    cout << "Current Balance: " << savings.getBalance() << endl;
    cout << "Interest Rate: " << savings.getInterestRate() << "%" << endl;

    return 0;
}