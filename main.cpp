#include "Election.h"
#include <iostream>

using namespace std;
int main()
{
    Election election("vote.txt");
    bool done = false;
    int round = 1;

    while (!done)
    {
        cout << "Round #" << round << "\n";
        done = election.oneRound();
        cout << "------------------------------\n";
        round++;
    }

    system("pause");
    return 0;
}
