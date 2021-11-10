#include <iostream>
using namespace std;
int main()
{
    int space = 1000;
    string inputCommand;
    string command[200];
    bool EXIT = false;
    int cnt = 0;
    while (EXIT == false)
    {
        cin >> inputCommand;
        command[cnt] = inputCommand;
        if (inputCommand == "exit")
        {
            EXIT = true;
        }
        cnt++;
    }
    return 0;
}