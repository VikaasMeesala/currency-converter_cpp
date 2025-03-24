#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <limits> // Include the limits header

using namespace std;

// Function to display the available currencies and their codes
void displayCurrencies(const map<string, double>& exchangeRates) {
    cout << "Available Currencies:\n";
    for (const auto& pair : exchangeRates) {
        cout << pair.first << endl;
    }
    cout << endl;
}

// Function to get the currency code from the user
string getCurrencyCode(const map<string, double>& exchangeRates, const string& prompt) {
    string currencyCode;
    while (true) {
        cout << prompt;
        cin >> currencyCode;
        if (exchangeRates.find(currencyCode) != exchangeRates.end()) {
            return currencyCode;
        } else {
            cout << "Invalid currency code. Please try again.\n";
        }
    }
}

// Function to get the amount from the user
double getAmount(const string& prompt) {
    double amount;
    while (true) {
        cout << prompt;
        if (cin >> amount) {
            if (amount >= 0) {
                return amount;
            } else {
                cout << "Amount must be non-negative.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); // Use std::numeric_limits
            }
        } else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); // Use std::numeric_limits
        }
    }
}

// Function to perform the currency conversion
double convertCurrency(double amount, double fromRate, double toRate) {
    return (amount / fromRate) * toRate;
}

int main() {
    // Define the exchange rates (replace with real-time data for better accuracy)
    map<string, double> exchangeRates = {
        {"USD", 1.0},    // US Dollar (base currency)
        {"EUR", 0.92},   // Euro
        {"GBP", 0.80},   // British Pound
        {"JPY", 145.0},  // Japanese Yen
        {"INR", 83.0},   // Indian Rupee
        {"CAD", 1.35},   // Canadian Dollar
        // Add more currencies as needed
    };

    cout << "Currency Converter\n";
    displayCurrencies(exchangeRates);

    string fromCurrency = getCurrencyCode(exchangeRates, "Enter the source currency code: ");
    string toCurrency = getCurrencyCode(exchangeRates, "Enter the target currency code: ");
    double amount = getAmount("Enter the amount to convert: ");

    double convertedAmount = convertCurrency(amount, exchangeRates[fromCurrency], exchangeRates[toCurrency]);

    cout << fixed << setprecision(2); // Set output to 2 decimal places
    cout << amount << " " << fromCurrency << " is equal to " << convertedAmount << " " << toCurrency << endl;

    return 0;
}

