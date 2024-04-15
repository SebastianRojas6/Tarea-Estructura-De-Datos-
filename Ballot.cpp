#include "Ballot.h"
#include <algorithm>

using namespace std;

Ballot::Ballot(const vector<string> &names) : preferences(names) {}

string Ballot::getCandidate() const
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

void Ballot::eliminate(const string &name)
{
    preferences.erase(remove(preferences.begin(), preferences.end(), name), preferences.end());
}

bool Ballot::isEmpty() const
{
    return preferences.empty();
}
