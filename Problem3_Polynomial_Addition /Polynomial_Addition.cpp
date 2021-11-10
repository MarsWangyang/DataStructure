#include <iostream>
using namespace std;

typedef struct
{
    float coef;
    int expon;
} polynomial;

int Compare(int arr1Expon, int arr2Expon)
{
    if (arr1Expon < arr2Expon)
    {
        return -1;
    }
    else if (arr1Expon == arr2Expon)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int count = 2;
    int num1, num2;
    polynomial *arr1, *arr2;
    cin >> num1;
    int startA = 0, finishA = num1 - 1;
    arr1 = new polynomial[num1];
    for (int j = 0; j < num1; j++)
    {
        cin >> arr1[j].coef >> arr1[j].expon;
    }
    cin >> num2;
    int startB = 0, finishB = num2 - 1;
    arr2 = new polynomial[num2];
    for (int j = 0; j < num2; j++)
    {
        cin >> arr2[j].coef >> arr2[j].expon;
    }

    polynomial *out;
    out = new polynomial[num1 + num2 + 1];
    int startC = 0;
    for (int ini = 0; ini <= num1 + num2; ini++)
    {
        out[ini].coef = 0;
        out[ini].expon = 0;
    }

    while (startA <= finishA && startB <= finishB)
    {
        switch (Compare(arr1[startA].expon, arr2[startB].expon))
        {
        case -1:
            out[startC].expon = arr2[startB].expon;
            out[startC].coef = arr2[startB].coef;
            // delete arr2[startB];
            startB++;
            startC++;
            break;
        case 0:
            if (arr1[startA].coef + arr2[startB].coef != 0)
            {
                out[startC].expon = arr1[startA].expon;
                out[startC].coef = arr1[startA].coef + arr2[startB].coef;
            }

            // delete arr1[startA];
            // delete arr2[startB];
            startA++;
            startB++;
            startC++;
            break;
        case 1:
            out[startC].expon = arr1[startA].expon;
            out[startC].coef = arr1[startA].coef;
            //delete arr1;
            startA++;
            startC++;
        }
    }

    //做完剩下沒人可以比的

    for (; startA <= finishA; startA++)
    {
        if (arr1[startA].coef != 0)
        {
            out[startC].expon = arr1[startA].expon;
            out[startC].coef = arr1[startA].coef;
            startC++;
        }
    }

    for (; startB <= finishB; startB++)
    {
        if (arr2[startB].coef != 0)
        {
            out[startC].expon = arr2[startB].expon;
            out[startC].coef = arr2[startB].coef;
            startC++;
        }
    }

    //output
    for (int i = 0; i < num1 + num2; i++)
    {
        if (/*out[i].expon == 0.1 ||*/ out[i].coef == 0)
        {
        }
        else if (out[i + 1].expon == -1)
        {

            cout << out[i].coef << " " << out[i].expon;
            break;
        }
        else
        {
            cout << out[i].coef << " " << out[i].expon << " ";
        }
    }

    delete[] arr1;
    delete[] arr2;
    delete[] out;
    return 0;
}
