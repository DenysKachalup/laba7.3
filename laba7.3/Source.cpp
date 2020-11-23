#include <iostream>
#include <iomanip>
#include <time.h>
#include<Windows.h>
using namespace std;

void Creat(int** mas, const int row,const int col, const int Low, const int High)
{
    int b;
    cout << "   A" << endl;
    for (int i = 0; i < row; i++)
        for (int k = 0; k < col; k++)
        {
            b = Low + rand() % (High - Low + 1);
            mas[i][k] = b;
        }
}
void print(int** a, const int row, const int col)
{
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}
int ElmNul(int** a, const int row, const int col, int k)
{
    int k_zero;
    for (int i = 0; i < row; i++) {
        k_zero = 0;
        for (int j = 0; j < col; j++)
            if (a[i][j] == 0)
            {
                k_zero++;
                break;
            }
        if (k_zero > 0)
        {
            for (int w = 0; w < col; w++)
                if (a[i][w] < 0)
                    k++;
        }

    }
        return k;
}
bool Max(int** a, const int i, const int k, const int col)
{
    for (int q = 0; q < col; q++)
        if (a[i][q] > a[i][k])
            return false;
    return true;
}
bool Min(int** a, const int i, const int k, const int row)
{
    for (int q = 0; q < row; q++)
        if (a[q][k] > a[i][k])
            return false;
    return true;
}
void Saddle(int** a, const int row, const int col)
{
    int No = 0;
    cout << "Сідлові точки: max in row & min in col " << endl<<endl;
    cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
    for(int i=0;i<row;i++)
        for(int k=0;k<col;k++)
            if (Max(a, i, k, col) && Min(a, i, k, row))
            {
                cout << setw(4) << ++No << setw(6) << i << setw(6) << k << endl;
            }

}
int main()
{
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));

    int L = -20;
    int H = 20;

    int row; cout << "Row: "; cin >> row;
    int col; cout << "Col: "; cin >> col;

    int** mas = new int* [row];
    for (int i = 0; i < row; i++)
        mas[i] = new int[col];


    Creat(mas, row,col, L, H);
    print(mas,row,col);
    
    
    int q=ElmNul(mas, row, col,0);
    
    cout << endl << endl;
    
    cout <<"Кількість від'ємних чисел,де в рядку є NULL  : "<< q << endl<<endl;

    Saddle(mas, row, col);

    for (int i = 0; i < row; i++)
        delete[] mas[i];
    delete[] mas;
    return 0;
}