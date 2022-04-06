#include <iostream>
using namespace std;

typedef struct
{
    float coef;
    int expon;
} polynomial;

int Compare(int expon1, int expon2)
{
    if (expon1 < expon2)
    {
        return -1;
    }
    else if (expon1 == expon2)
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
    int cntA, cntB;
    cin >> cntA;
    polynomial *p1 = new polynomial[cntA];
    int startA = 0;
    int finishA = cntA - 1;
    for (int i = 0; i < cntA; i++)
    {
        cin >> p1[i].coef >> p1[i].expon;
    }
    cin >> cntB;
    polynomial *p2 = new polynomial[cntB];
    int startB = 0;
    int finishB = cntB - 1;
    for (int i = 0; i < cntB; i++)
    {
        cin >> p2[i].coef >> p2[i].expon;
    }

    polynomial *out = new polynomial[cntA + cntB + 1];
    int startC = 0;
    for (int i = 0; i <= cntA + cntB; i++)
    {
        out[i].expon = 0;
        out[i].coef = 0;
    }
    while (startA <= finishA && startB <= finishB)
    {
        switch (Compare(p1[startA].expon, p2[startB].expon))
        {
        case -1:
            out[startC].expon = p2[startB].expon;
            out[startC].coef = p2[startB].coef;
            startB++;
            startC++;
            break;
        case 0:
            if ((p1[startA].coef + p2[startB].coef) != 0)
            {
                out[startC].coef = p1[startA].coef + p2[startB].coef;
                out[startC].expon = p1[startA].expon;
            }
            startA++;
            startB++;
            startC++;
            break;
        case 1:
            out[startC].expon = p1[startA].expon;
            out[startC].coef = p1[startA].coef;
            startA++;
            startC++;
        }
    }

    for (; startA < finishA; startA++)
    {
        if (p1[startA].coef != 0)
        {
            out[startC].expon = p1[startA].expon;
            out[startC].coef = p1[startA].coef;
            startC++;
        }
    }

    for (; startB < finishB; startB++)
    {
        if (p2[startB].coef != 0)
        {
            out[startC].expon = p2[startB].expon;
            out[startC].coef = p2[startB].coef;
            startC++;
        }
    }

    for (int i = 0; i < startC; i++)
    {
        if (out[i].coef == 0)
        {
        }
        else if (out[i + 1].expon == -1)
        {
            cout << out[i].coef << " " << out[i].expon;
        }
        else
        {
            cout << out[i].coef << " " << out[i].expon << " ";
        }
    }
    delete[] p1;
    delete[] p2;
    delete[] out;
    return 0;
}