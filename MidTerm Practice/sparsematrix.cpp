#include <iostream>
#include <vector>
using namespace std;

struct Term
{
    Term(int row, int col, int value) : row(row), col(col), value(value) {}
    int row;
    int col;
    int value;
};

typedef vector<Term> TermVector;

TermVector Input(int rowNum, int colNum)
{
    int **array;        //為了給使用者input內容
    int value = 0;      //計算總共有多少有效數值
    TermVector vecList; //為所有有效數值列出的內容
    array = new int *[rowNum];
    for (int i = 0; i < rowNum; i++)
    {
        array[i] = new int[colNum];
        for (int j = 0; j < colNum; j++)
        {
            cin >> array[i][j];
            if (array[i][j] != 0)
            {
                vecList.push_back(Term(i, j, array[i][j]));
                value++;
            }
        }
    }
    vecList.insert(vecList.begin(), Term(rowNum, colNum, value));
    for (int i = 0; i < rowNum; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    return vecList;
}

TermVector Transpose(TermVector matrix)
{
    int rowNum = matrix[0].row;
    int colNum = matrix[0].col;
    int totalElement = matrix[0].value;
    int col2RowNum[colNum];
    int startPosition[colNum];
    for (int i = 0; i < totalElement; i++)
    {
        col2RowNum[i] = 0;
    }
    for (int i = 0; i < colNum; i++)
    {
        startPosition[i] = 0;
    }

    for (int i = 1; i <= totalElement; i++)
    {
        col2RowNum[matrix[i].col]++;
    }
    startPosition[0] = 1;
    for (int i = 1; i < colNum; i++)
    {
        startPosition[i] = startPosition[i - 1] + col2RowNum[i - 1];
    }

    TermVector transMatrix = matrix;
    for (int i = 1; i <= totalElement; i++)
    {
        transMatrix.at(startPosition[matrix[i].col]).row = matrix[i].col;
        transMatrix.at(startPosition[matrix[i].col]).col = matrix[i].row;
        transMatrix.at(startPosition[matrix[i].col]).value = matrix[i].value;
        startPosition[matrix[i].col]++;
    }
    transMatrix.at(0).row = matrix[0].col;
    transMatrix.at(0).col = matrix[0].row;

    return transMatrix;
}

int Compare(int a, int b)
{
    if (a < b)
    {
        return -1;
    }
    else if (a == b)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void StoreSum(TermVector *result, int row, int col, int *sum, int *totalDecrease)
{
    int value = *sum;
    if (value != 0)
    {
        (*result).push_back(Term(row, col, value));
    }
    else
    {
        *totalDecrease += 1;
    }

    *sum = 0;
}

TermVector Multiply(TermVector firstMatrix, TermVector transMatrix)
{
    int rowBegin = 1;
    int row = firstMatrix[1].row;
    int sum = 0;
    int totalCount = 0;
    int totalDecrease = 0;
    TermVector result;
    result.push_back(Term(firstMatrix[0].row, transMatrix[0].row, 0));
    firstMatrix.push_back(Term(firstMatrix[0].row, 0, 0));
    transMatrix.push_back(Term(transMatrix[0].col, 0, 0));
    for (int i = 1; i <= firstMatrix[0].value;)
    {
        int column = transMatrix[1].row;
        for (int j = 1; j <= transMatrix[0].value + 1;)
        {
            if (firstMatrix[i].row != row)
            {
                totalCount += 1;
                StoreSum(&result, row, column, &sum, &totalDecrease);
                i = rowBegin;
                for (; transMatrix[j].row == column; j++)
                    ;
                column = transMatrix[j].row;
            }
            else if (transMatrix[j].row != column)
            {
                totalCount += 1;
                StoreSum(&result, row, column, &sum, &totalDecrease);
                i = rowBegin;
                column = transMatrix[j].row;
            }
            else
            {
                switch (Compare(firstMatrix[i].col, transMatrix[j].col))
                {
                case -1:
                    i++;
                    break;
                case 0:
                    sum += firstMatrix[i++].value * transMatrix[j++].value;
                    break;
                case 1:
                    j++;
                }
            }
        }
        result[0].value = totalCount - totalDecrease;
        for (; firstMatrix[i].row == row; i++)
            ;
        rowBegin = i;
        row = firstMatrix[i].row;
    }
    return result;
}

int main()
{
    int rowNum1, rowNum2;
    int colNum1, colNum2;
    cin >> rowNum1 >> colNum1;
    TermVector firstMatrix = Input(rowNum1, colNum1);

    cin >> rowNum2 >> colNum2;
    TermVector secondMatrix = Input(rowNum2, colNum2);
    TermVector transMatrix = Transpose(secondMatrix);
}