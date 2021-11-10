#include <iostream>
#include <stack>
using namespace std;

typedef struct
{
    int vert;
    int horiz;
} offset;

struct Element
{
    Element(int row, int col, int dir) : row(row), col(col), dir(dir) {}
    int row;
    int col;
    int dir;
};

void MoveSetting(offset *move)
{
    move[0].vert = -1; //N
    move[0].horiz = 0;

    move[1].vert = 0; //E
    move[1].horiz = 1;

    move[2].vert = 1; //S
    move[2].horiz = 0;

    move[3].vert = 0; //W
    move[3].horiz = -1;

    return;
}

void Move(int **matrix, int **marked, offset *move, int endRow, int endCol)
{
    bool FOUND = false;
    int top = 0;
    int row, col, dir;
    int nextRow, nextCol;
    stack<Element> elementStack;
    elementStack.push(Element(-1, -1, -1));
    elementStack.push(Element(1, 1, 1)); // inital location
    marked[1][1] = 1;
    //cout << "end: " << endRow << " " << endCol << endl;
    while (top > -1 && !FOUND)
    {
        Element pos = elementStack.top();
        top--;
        row = pos.row;
        col = pos.col;
        dir = pos.dir;
        if (row != -1)
        {
            elementStack.pop();
        }
        else
            break;
        while (dir < 4 && !FOUND)
        {

            /* Move in direction */
            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;
            //cout << "next: " << nextRow << " " << nextCol << endl;
            if (nextRow == endRow && nextCol == endCol)
            {

                elementStack.push(Element(row, col, dir));
                elementStack.push(Element(nextRow, nextCol, -1));
                FOUND = true;
            }
            else if (!matrix[nextRow][nextCol] && !marked[nextRow][nextCol])
            {
                marked[nextRow][nextCol] = 1;
                pos.row = row;
                pos.col = col;
                pos.dir = dir++;
                elementStack.push(pos);
                top++;
                row = nextRow;
                col = nextCol;
                dir = 0;
            }
            else
            {
                ++dir;
            }
            //cout << "Stack: " << elementStack.top().row << elementStack.top().col << elementStack.top().dir << endl;
        }
    }
    if (FOUND)
    {
        stack<Element> result;
        while (elementStack.size())
        {
            Element value = elementStack.top();
            result.push(value);
            //cout << "(" << value.row - 1 << "," << value.col - 1 << ") ";
            elementStack.pop();
        }
        result.pop();
        while (result.size())
        {

            cout << "(" << result.top().row - 1 << "," << result.top().col - 1 << ") ";
            result.pop();
        }
    }
    else
    {
        cout << "Can't reach the exit!" << endl;
    }

    return;
}

int main()
{
    int row, col;

    cin >> row >> col;
    int **matrix;
    int **marked;
    int endRow, endCol;
    endRow = row;
    endCol = col;
    offset move[4];
    matrix = new int *[row + 2];
    marked = new int *[row + 2];

    MoveSetting(move);
    for (int i = 0; i <= row + 1; i++)
    {
        marked[i] = new int[col + 2];
    }
    for (int i = 0; i <= row + 1; i++)
    {
        matrix[i] = new int[col + 2];
        for (int j = 0; j <= col + 1; j++)
        {
            if (i == 0 || j == 0 || i == row + 1 || j == col + 1)
            {
                matrix[i][j] = 1;
                marked[i][j] = 1;
            }
            else
            {
                cin >> matrix[i][j];
                marked[i][j] = matrix[i][j];
            }
        }
    }
    Move(matrix, marked, move, endRow, endCol);

    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    for (int i = 0; i < row; i++)
    {
        delete[] marked[i];
    }
    delete[] marked;
    delete[] matrix;
    return 0;
}