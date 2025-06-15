#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool passwordIsValid(const char[]);

int main() {
    const int SIZE = 100;
    char password[SIZE];

    cout << "Enter your password or leave blank to exit: ";
    cin.getline(password, SIZE);

    // Exit if empty input
    if (strlen(password) == 0) {
        cout << "No password entered. Exiting program.\n";
        return 0;
    }

    while (!passwordIsValid(password)) {
        // cout << "⛔️ Password does not meet the complexity requirements, please try again.\n";
        cout << "Enter your password or leave blank to exit: ";
        cin.getline(password, SIZE);

        if (strlen(password) == 0) {
            cout << "No password entered. Exiting program.\n";
            return 0;
        }
    }

    cout << "✅ Password meets all complexity requirements.\n";
    return 0;
}

bool passwordIsValid(const char password[]) {
    bool hasUpper = false, hasLower = false, hasDigit = false;
    int length = strlen(password);

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = true;
        if (islower(password[i])) hasLower = true;
        if (isdigit(password[i])) hasDigit = true;
    }

    if (length < 6) cout << "➡️ Password must be at least 6 characters long.\n";
    if (!hasUpper) cout << "➡️ Password must contain at least one uppercase letter.\n";
    if (!hasLower) cout << "➡️ Password must contain at least one lowercase letter.\n";
    if (!hasDigit) cout << "➡️ Password must contain at least one digit.\n";

    return hasUpper && hasLower && hasDigit;
}
