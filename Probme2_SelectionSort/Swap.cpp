#include <iostream>
using namespace std;

void Swap(int *x, int *y)
{
    if (*x != *y)
    {
        *x = *x ^ *y;
        *y = *x ^ *y;
        *x = *x ^ *y;
    }
}

int main()
{

    int a[][2] = {{1, 2}, {3, 4}};
    int *arr = &a[0][0];
    cout << "length/size: " << sizeof(arr) << endl;
    Swap((arr), (arr + 2));

    cout << "-------" << endl;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << a[i][j] << " ";
        }
    }

    return 0;
}