#include <iostream>
using namespace std;

int main()
{
    int test[5] = {5, 6, 7, 8, 9};

    cout << "value of test[0]: " << test[0] << endl;
    cout << "address of test[0]: " << &test[0] << endl;
    cout << "value of test: " << test << endl;
    cout << "which means the value of *test: " << *test << endl;

    int cnt, id, score;
    int student[1001][2];
    int *array = student[0];
    cout << "請輸入筆數： ";
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> id >> score;
        student[i][0] = id;
        student[i][1] = score;
    }
    cout << "列表0: " << student[0][0] << endl;
    cout << "列表1: " << student[0][1] << endl;
    cout << "列表0: " << &student[0][0] << endl;

    cout << "列表1: " << &student[0][1] << endl;

    cout << "array: " << array << endl;
    cout << "array1: " << *array << endl;
    cout << "array1+1: " << *array + 1 << endl;

    cout << "array+1: " << *(array + 1) << endl;
    cout << "array+2: " << *(array + 2) << endl;
    cout << "array+3: " << *(array + 3) << endl;

    cout << "&student: " << &student + 1 << endl;
    cout << "&student: " << &(student + 1) << endl;
}
return 0;
}