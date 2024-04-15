#include "Election.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

Election::Election(const string &filename)
{
    ballots = readFile(filename);
}

bool Election::oneRound()
{
    map<string, int> voteCounts;
    for (const Ballot &ballot : ballots)
    {
        string candidate = ballot.getCandidate();
        voteCounts[candidate]++;
    }

    string top, bottom;
    int topCount = 0, bottomCount = ballots.size() + 1;
    for (const auto &entry : voteCounts)
    {
        if (entry.second > topCount)
        {
            topCount = entry.second;
            top = entry.first;
        }
        if (entry.second < bottomCount)
        {
            bottomCount = entry.second;
            bottom = entry.first;
        }
    }

    for (const auto &entry : voteCounts)
    {
        double percent = 100.0 * entry.second / ballots.size();
        cout << entry.second << " votes for " << entry.first << " (" << percent << "%)\n";
    }

    if (topCount == bottomCount)
    {
        cout << "Election has no winner\n";
        return true;
    }
    else if (topCount > ballots.size() / 2.0)
    {
        cout << "Winner is " << top << "\n";
        return true;
    }
    else
    {
        cout << "No winner, eliminating " << bottom << "\n";
        eliminate(bottom);

        for (Ballot &ballot : ballots)
        {
            if (!ballot.isEmpty())
            {
                ballot.eliminate(bottom);
            }
        }

        if (ballots.empty())
        {
            cout << "All ballots are empty. No winner.\n";
            return true;
        }
        else
        {
            return oneRound();
        }
    }
}

void Election::eliminate(const string &candidate)
{
    for (Ballot &ballot : ballots)
    {
        ballot.eliminate(candidate);
    }
}

vector<Ballot> Election::readFile(const string &filename)
{
    vector<Ballot> ballots;
    ifstream file(filename);
    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        vector<string> votes;
        string token;
        while (getline(iss, token, ','))
        {
            votes.push_back(token);
        }
        if (!votes.empty())
        {
            ballots.push_back(Ballot(votes));
        }
    }

    return ballots;
}
