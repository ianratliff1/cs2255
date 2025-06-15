#include <iostream>
#include <iomanip>

using namespace std;

void sortScores (int *, int);
double calcAverage (int *, int);

int main() {

    // Define variables:
    int numScores, *scoresPointer = nullptr;
    double average;

    cout << "---TEST SCORE SORT & AVERAGE---\n\n";

    // Prompt for number of test scores, do not accept less than 0 for numScores
    do {
        cout << "Enter the number of test scores: ";
        cin >> numScores;
        if (numScores < 1)
            cout << "⚠️ Please enter a valid quantity of test scores\n";
    } while (numScores < 1);


    scoresPointer = new int [numScores]; // Dynamically allocate array of size numScores in memory

    // Prompt for test scores, do not accept negative numbers
    for (int i=0; i < numScores; i++) {
        do {
            cout << "Enter test score " << (i + 1) << " of " << numScores << ": ";
            cin >> *(scoresPointer + i);
            if (*(scoresPointer + i) < 0)
                cout << "⚠️ Please enter a valid test score\n";
        } while (*(scoresPointer + i) < 0);
    }

    // Call sortScores function to sort scoresPointer elements in ascending order:
    sortScores(scoresPointer, numScores);

    cout << "\nHere are the test scores in ascending order:\n";

    for (int i=0; i < numScores; i++) {
        cout << *(scoresPointer + i) << " ";
    }

    // Call the calcAverage function to calculate the average:
    average = calcAverage(scoresPointer, numScores);

    cout << showpoint << fixed << setprecision(2); // 2 decimal places
    cout << "\n\nTest score average: " << average << endl << endl;

    return 0;
}

void sortScores (int * scores, int numScores) {
    // Selection sort algorithm
    int minIndex, minValue;
    for (int start = 0; start < (numScores - 1); start++) {
        minIndex = start;
        minValue = *(scores + start);
        for (int i = start + 1; i < numScores; i++) {
            if (*(scores + i) < minValue) {
                minValue = *(scores + i);
                minIndex = i;
            }
        }
        swap(*(scores + minIndex), *(scores + start));
    }
}

double calcAverage (int * scores, int size) {
    int total = 0;
    double average;
    for (int i = 0; i < size; i++)
        total += *(scores + i);
    average = (static_cast<double> (total) / size); // promote operands to doubles
    return average;
}