#ifndef ELECTION_H
#define ELECTION_H

#include <vector>
#include <string>
#include <map>
#include "Ballot.h"

using namespace std;
class Election
{
public:
    Election(const string &filename);
    bool oneRound();

private:
    vector<Ballot> ballots;
    void eliminate(const string &candidate);
    vector<Ballot> readFile(const string &filename);
};

#endif // ELECTION_H
