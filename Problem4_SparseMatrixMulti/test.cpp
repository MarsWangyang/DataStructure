#include <iostream>
#include <vector>
using namespace std;

void SUM(int *sum, vector<int> *vec)
{
    *sum = 10;
    //cout << "vecPos: " << vecPos << endl;
    (*vec).push_back(20);

    //*vecPos->push_back(60);
}

int main()
{
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(11);
    int a = 0;
    int *itPos;
    cout << "a: " << a << endl;
    for (int i = 0; i == 0; i++)
    {
        itPos = &vec[0];

        cout << "vec: " << itPos << " " << &vec[0] << endl;
        cout << "vec1: " << itPos + 1 << " " << &vec[1] << endl;
    }
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    SUM(&a, &vec);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

    cout << "a change: " << a << endl;
}