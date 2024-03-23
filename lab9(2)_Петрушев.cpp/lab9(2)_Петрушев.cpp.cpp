



#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int n = 3;
    int table[n][n] = { {1, -2, 3}, {4, 5, -6}, {7, 8, 9} };

    int sumGoodRows = 0;
    int sumBadDiagonal = 0;
    int countBadDiagonal = 0;

    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        bool badNumbers = false;
        for (int j = 0; j < n; j++) {
            if (table[i][j] < 0) {
                badNumbers = true;
                if (i == j) {
                    sumBadDiagonal += table[i][j];
                    countBadDiagonal++;
                }
            }
            else {
                rowSum += table[i][j];
            }
        }
        if (!badNumbers)
            sumGoodRows += rowSum;
    }

    double avgBadDiagonal = 0;
    if (countBadDiagonal > 0)
        avgBadDiagonal = (double)sumBadDiagonal / countBadDiagonal;

    cout << "Сума чисел в хороших рядках: " << sumGoodRows << endl;
    cout << "Середнє поганих чисел на діагоналі: " << avgBadDiagonal << endl;

    return 0;
}
