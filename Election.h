#ifndef ELECTION_H
#define ELECTION_H

#include <vector>
#include <string>
#include <map>
#include "Ballot.h"

class Election
{
public:
    Election(const std::string &filename);
    bool oneRound();

private:
    std::vector<Ballot> ballots;
    void eliminate(const std::string &candidate);
    std::vector<Ballot> readFile(const std::string &filename);
};

#endif // ELECTION_H
