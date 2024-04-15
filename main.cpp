#include "Election.h"
#include <iostream>

int main()
{
    Election election("vote.txt");
    bool done = false;
    int round = 1;

    while (!done)
    {
        std::cout << "Round #" << round << "\n";
        done = election.oneRound();
        std::cout << "------------------------------\n";
        round++;
    }

    system("pause");
    return 0;
}
