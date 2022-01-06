#include <iostream>
using namespace std;

void Sort(int *arr, int cnt)
{
    int *minScore;
    int *minID;
    int *currentScore;
    int *currentID;
    for (int i = 0; i < 2 * (cnt - 1); i += 2)
    {
        minID = arr + i;
        minScore = arr + i + 1;
        for (int j = i + 2; j < 2 * cnt - 1; j += 2)
        {
            currentID = arr + j;
            currentScore = arr + j + 1;
            if (*minScore > *currentScore)
            {
                minScore = currentScore;
                minID = currentID;
            }
        }
        int stdID = *minID;
        int stdScore = *minScore;
        while (minScore > arr + i + 1)
        {
            *minScore = *(minScore - 2);
            minScore -= 2;
            *minID = *(minID - 2);
            minID -= 2;
        }
        *(arr + i + 1) = stdScore;
        *(arr + i) = stdID;
    }
}

int main()
{
    int cnt;
    int count;
    int count = 0;
    int *arr;
    for (int i = 2 * cnt - 1; i >= 0; i -= 2)
    {
        if (i == 1)
        {
            if (*(arr + i) == *(arr + i + 2))
            {
                count = count;
            }
            else
            {
                count = 0;
            }
        }
        if (*(arr + i) == *(arr + i - 2) & i != 1)
        {
            count += 2;
        }
        else
        {
            if (count == 0)
            {
                cout << "" << endl;
            }
            else
            {
                for (int j = i; j <= i + count; j += 2)
                {
                    cout << "" << endl;
                }
            }
            count = 0;
        }
    }
}