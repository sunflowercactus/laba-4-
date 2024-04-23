#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;

class BankCredit {
private:
    string name;
    double amount;
    string currency;
    double interestRate;

public:
    BankCredit(const string& name, double amount, const string& currency, double interestRate)
        : name(name), amount(amount), currency(currency), interestRate(interestRate) {}

    friend ostream& operator<<(ostream& os, const BankCredit& credit) {
        os << "Name: " << credit.name << ", Amount: " << credit.amount << " " << credit.currency
            << ", Interest Rate: " << credit.interestRate << "%";
        return os;
    }

    bool operator<(const BankCredit& other) const {
        return amount < other.amount;
    }
};

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    deque<BankCredit> creditsDeque;

    string name, currency;
    double amount, interestRate;

    while (inputFile >> name >> amount >> currency >> interestRate) {
        BankCredit credit(name, amount, currency, interestRate);
        creditsDeque.push_back(credit);
    }
    outputFile << "Original Deque:" << endl;
    for (const BankCredit& credit : creditsDeque) {
        outputFile << credit << endl;
    }

    list<BankCredit> creditsList(creditsDeque.begin(), creditsDeque.end());
    sort(creditsDeque.begin(), creditsDeque.end());

    list<BankCredit> copiedCreditsList;
    copy(creditsDeque.begin(), creditsDeque.end(), back_inserter(copiedCreditsList));


    outputFile << "\nCopied List:" << endl;
    for (const BankCredit& credit : copiedCreditsList) {
        outputFile << credit << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
