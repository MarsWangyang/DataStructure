#include <iostream>
#include <stack>
using namespace std;

typedef struct
{
    int horiz;
    int vert;
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
    elementStack.push(Element(1, 1, 1));
    marked[1][1] = 1;
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
        {
            break;
        }
        while (dir < 4 && !FOUND)
        {
            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;
            if (nextRow == endRow && nextCol == endCol)
            {
                elementStack.push(Element(row, col, dir));
                elementStack.push(Element(nextRow, nextCol, -1));
                FOUND = true;
            }
            else if (!marked[nextRow][nextCol] && !matrix[nextRow][nextCol])
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
        }
        if (FOUND)
        {
            stack<Element> result;
            while (elementStack.size())
            {
                Element value = elementStack.top();
                result.push(value);
                elementStack.pop();
            }
            result.pop();
            while (result.size())
            {
                cout << "nncie ";
            }
        }
    }
}

int main()
{
    int row, col;
    cin >> row >> col;
    int **matrix;
    int **marked;
    int endRow = row;
    int endCol = col;
    offset move[4];
    matrix = new int *[row + 2];
    marked = new int *[row + 2];

    for (int i = 0; i < row + 2; i++)
    {
        marked[i] = new int[col + 2];
    }

    MoveSetting(move);
    for (int i = 0; i < row + 2; i++)
    {
        matrix[i] = new int[col + 2];
        for (int j = 0; j < col + 2; j++)
        {
            if (i == 0 || j == 0 || j == col + 1 || i == row + 1)
            {
                marked[i][j] = 1;
                matrix[i][j] = 1;
            }
            else
            {
                cin >> matrix[i][j];
                marked[i][j] = matrix[i][j];
            }
        }
    }

    return 0;
}