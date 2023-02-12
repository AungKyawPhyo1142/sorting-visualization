#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void printStars(int a[], int n, string name)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ": ";
        for (int j = 0; j < a[i]; j++)
        {
            cout << " \033[0;32m*\033[0;37m ";
        }
        cout << "\n";
    }
    cout << "\nCongrats, your array is sorted using \033[0;35m" << name << "\033[0;37m!" << endl;
}

void printCurrentStars(int a[], int n, int i, int j)
{
    for (int k = 0; k < n; k++)
    {
        if (k == i || k == j)
        {
            cout << a[k] << ": \033[0;34m";
        }
        else
        {
            cout << a[k] << ": \033[0;37m";
        }
        for (int l = 0; l < a[k]; l++)
        {
            cout << "* ";
        }
        cout << "\033[0;37m" << endl;
    }
}

void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            system("clear");
            printCurrentStars(a, n, i, j);
            this_thread::sleep_for(chrono::milliseconds(800));
        }
    }
    system("clear");
    printStars(a, n, "Bubble Sort");
}

void selectionSort(int a[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min = i; // current min

        for (int j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
            system("clear");
            printCurrentStars(a, n, i, j);
            this_thread::sleep_for(chrono::milliseconds(800));
        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    system("clear");
    printStars(a, n, "Selection Sort");
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            system("clear");
            printCurrentStars(a, n, i, j);
            this_thread::sleep_for(chrono::milliseconds(800));
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    system("clear");
    printStars(a, n, "Insertion Sort");
}

int main()
{
    system("clear");

    int menu;
    char choice;

    int n;

    do
    {
        cout << "\n(1)Bubble Sort\n(2)Selection Sort\n(3)Insertion Sort: ";
        cin >> menu;

        cout << "\nSize of an array: ";
        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++)
        {
            cout << "Element [" << (i + 1) << "]: ";
            cin >> a[i];
        }

        if (menu == 1)
        {
            BubbleSort(a, n);
        }
        else if (menu == 2)
        {
            selectionSort(a, n);
        }
        else
        {
            insertionSort(a, n);
        }

        cout << "\nAgain?\n(y/n): ";
        cin >> choice;

    } while (choice == 'y');

    cout << "\n\n";
    return 0;
}
