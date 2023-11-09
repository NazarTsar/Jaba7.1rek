#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);
void RecursiveSort(int** a, const int rowCount, const int colCount, int column);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -41;
    int High = 23;
    int rowCount = 7;
    int colCount = 9;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);
    RecursiveSort(a, rowCount, colCount, 0);  // Сортуємо за першим стовпчиком
    RecursiveSort(a, rowCount, colCount, 1);  // Сортуємо за другим стовпчиком
    RecursiveSort(a, rowCount, colCount, 2);  // Сортуємо за третім стовпчиком
    Print(a, rowCount, colCount);
    int S = 0;
    int k = 0;
    Calc(a, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Change(int** a, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int j = 0; j < colCount; j++)
    {
        tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (a[i][j] % 2 == 0 && !(a[i][j] % 7 == 0))
            {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
}

void RecursiveSort(int** a, const int rowCount, const int colCount, int column)
{
    for (int i = 0; i < rowCount - 1; i++)
    {
        for (int j = 0; j < rowCount - i - 1; j++)
        {
            if (a[j][column] > a[j + 1][column])
            {
                Change(a, j, j + 1, colCount);
            }
        }
    }
}
