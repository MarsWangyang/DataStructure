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
    int **array;
    int value = 0;
    TermVector vecList;
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
    int totalRow = matrix[0].row;
    int totalCol = matrix[0].col;
    int totalCount = matrix[0].value;
    int col2RowNum[totalCount];
    int startRowPosition[totalCol];
    //Initialization
    for (int i = 0; i < totalCount; i++)
    {
        col2RowNum[i] = 0;
    }
    for (int i = 0; i < totalCol; i++)
    {
        startRowPosition[i] = 0;
    }
    //計算每個col有多少個
    for (int i = 1; i <= totalCount; i++)
    {
        col2RowNum[matrix[i].col]++;
    }
    //計算轉置過後的起始位置
    startRowPosition[0] = 1;
    for (int i = 1; i < totalCol; i++)
    {
        startRowPosition[i] = startRowPosition[i - 1] + col2RowNum[i - 1];
    }

    //開始Transpose
    TermVector transMatrix = matrix;
    for (int cnt = 1; cnt <= totalCount; cnt++)
    {
        transMatrix.at(startRowPosition[matrix[cnt].col]).row = matrix[cnt].col;
        transMatrix.at(startRowPosition[matrix[cnt].col]).col = matrix[cnt].row;
        transMatrix.at(startRowPosition[matrix[cnt].col]).value = matrix[cnt].value;
        startRowPosition[matrix[cnt].col]++;
    }
    transMatrix.at(0).row = matrix[0].col;
    transMatrix.at(0).col = matrix[0].row;

    return transMatrix;
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

int Compare(int a, int b)
{
    if (a > b)
    {
        return 1;
    }
    else if (a == b)
    {
        return 0;
    }
    else
    {
        return -1;
    }
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
    //對Matrix做處理，讓for loop在讀取的時候，可以讓row往下一個開始
    firstMatrix.push_back(Term(firstMatrix[0].row, 0, 0));
    transMatrix.push_back(Term(transMatrix[0].col, 0, 0));
    for (int i = 1; i <= firstMatrix[0].value;)
    {
        int column = transMatrix[1].row;
        for (int j = 1; j <= transMatrix[0].value + 1;)
        {
            /*
            在firstMatrix當中，每次都會去依照row，去找transMatrix上面的col相乘，
            所以在firstMatrix裏面，row在計算的時候，只會是e.g. row=0的element去和transMatrix做計算，
            所以才會需要用if else if來檢查是否現在的firstMatrix[i].row(scanned) == row()
            */
            if (firstMatrix[i].row != row)
            //針對firstMatrix已經讀完row的部分，要再看transMatrix是否要換col計算
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
                    sum += (firstMatrix[i++].value * transMatrix[j++].value);
                    break;
                case 1:
                    j++;
                }
            }
        }
        /*
            去對A還有剩下的row還要讀，也就是可能有row=0, 2, 3...，
            現在只讀完0，但已經刷了一輪transMatrix，因此要換firstMatrix row=2的部分，
            因此要i++，為了讓我們能夠重新開始下一個row的計算。
        */
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
    TermVector Result = Multiply(firstMatrix, transMatrix);
    for (int i = 0; i < Result.size(); i++)
    {
        cout << Result[i].row << " " << Result[i].col << " " << Result[i].value << endl;
    }
    return 0;
}