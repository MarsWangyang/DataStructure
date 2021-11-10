
#include <iostream>
using namespace std;

void stableSelectionSort(int a[][2], int n)
{
    // Iterate through array elements
    for (int i = 0; i < n - 2; i += 2)
    {

        int min = i;
        for (int j = i + 2; j < n; j += 2)
            if (a[min][1] > a[j][1])
                min = j;

        // Move minimum element at current i.
        int idd = a[min][0];
        int key = a[min][1];
        while (min > i)
        {
            a[min][0] = a[min - 2][0];
            a[min][1] = a[min - 2][1];
            min -= 2;
        }
        a[i][0] = idd;
        a[i][1] = key;
    }
}

void printArray(int a[][2], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i][0] << " ";
    cout << endl;
}

int main()
{
    int cnt, id, score;
    cin >> cnt;
    int student[cnt][2];
    for (int i = 0; i < cnt; i++)
    {
        cin >> id >> score;
        student[i][0] = id;
        student[i][1] = score;
    }
    int n = 2 * cnt;
    stableSelectionSort(student, n);
    printArray(student, cnt);
    return 0;
}