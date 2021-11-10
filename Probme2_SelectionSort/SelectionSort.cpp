#include <iostream>
using namespace std;

void Sort(int *array, int cnt)
{
    int *minID;
    int *minScore;
    int *currentScore;
    int *currentID;
    for (int i = 0; i < 2 * (cnt - 1); i += 2)
    {
        minID = array + i;
        minScore = array + 1 + i;
        for (int j = i + 2; j < 2 * cnt; j += 2)
        {
            currentScore = array + 1 + j;
            currentID = array + j;

            if (*minScore > *currentScore)
            {
                minScore = currentScore;
                minID = currentID;
            }
        }
        int stuScore = *minScore;
        int stuID = *minID;
        while (minScore > array + i + 1)
        {
            *minID = *(minID - 2);
            minID -= 2;
            *minScore = *(minScore - 2);
            minScore -= 2;
        }
        *(array + i) = stuID;
        *(array + i + 1) = stuScore;
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
    int *checkpoint = arr;
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
            checkpoint = arr + i;
            count = 0;
        }
    }
    return 0;
}
