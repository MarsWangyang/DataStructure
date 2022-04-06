#include <iostream>
using namespace std;

void Sort(int *arr, int cnt)
{
    int *minID;
    int *minScore;
    int *currentID;
    int *currentScore;

    for (int i = 0; i < 2 * (cnt - 1); i += 2)
    {
        minID = arr + i;
        minScore = arr + i + 1;
        for (int j = i + 2; j <= 2 * cnt - 1; j += 2)
        {
            currentID = arr + j;
            currentScore = arr + j + 1;
            if (*minScore > *currentScore)
            {
                minID = currentID;
                minScore = currentScore;
            }
        }
        int stdID = *minID;
        int stdScore = *minScore;
        while (minScore > arr + i + 1)
        {
            *minID = *(minID - 2);
            minID -= 2;
            *minScore = *(minScore - 2);
            minScore -= 2;
        }
        *(arr + i) = stdID;
        *(arr + i + 1) = stdScore;
    }
}

int main()
{
    int cnt, id, score;
    cin >> cnt;
    int student[cnt][2];
    int *arr = student[0];
    for (int i = 0; i < cnt; i++)
    {
        cin >> id >> score;
        student[i][0] = id;
        student[i][1] = score;
    }
    Sort(arr, cnt);
    int count = 0;
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
                cout << *(arr + i - 1) << endl;
            }
            else
            {
                for (int j = i; j <= i + count; j += 2)
                {
                    cout << *(arr + j - 1) << endl;
                }
            }
            count = 0;
        }
    }
    return 0;
}