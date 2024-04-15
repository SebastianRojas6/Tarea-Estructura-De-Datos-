#include "Ballot.h"
#include <algorithm>

Ballot::Ballot(const std::vector<std::string> &names) : preferences(names) {}

std::string Ballot::getCandidate() const
{
    if (!preferences.empty())
    {
        return preferences.front();
    }
    else
    {
        return "none";
    }
}

void Ballot::eliminate(const std::string &name)
{
    preferences.erase(std::remove(preferences.begin(), preferences.end(), name), preferences.end());
}

bool Ballot::isEmpty() const
{
    return preferences.empty();
}
