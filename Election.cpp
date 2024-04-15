#include "Election.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

Election::Election(const std::string &filename)
{
    ballots = readFile(filename);
}

bool Election::oneRound()
{
    std::map<std::string, int> voteCounts;
    for (const Ballot &ballot : ballots)
    {
        std::string candidate = ballot.getCandidate();
        voteCounts[candidate]++;
    }

    std::string top, bottom;
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
        std::cout << entry.second << " votes for " << entry.first << " (" << percent << "%)\n";
    }

    if (topCount == bottomCount)
    {
        std::cout << "Election has no winner\n";
        return true;
    }
    else if (topCount > ballots.size() / 2.0)
    {
        std::cout << "Winner is " << top << "\n";
        return true;
    }
    else
    {
        std::cout << "No winner, eliminating " << bottom << "\n";
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
            std::cout << "All ballots are empty. No winner.\n";
            return true;
        }
        else
        {
            return oneRound();
        }
    }
}

void Election::eliminate(const std::string &candidate)
{
    for (Ballot &ballot : ballots)
    {
        ballot.eliminate(candidate);
    }
}

std::vector<Ballot> Election::readFile(const std::string &filename)
{
    std::vector<Ballot> ballots;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::vector<std::string> votes;
        std::string token;
        while (std::getline(iss, token, ','))
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
