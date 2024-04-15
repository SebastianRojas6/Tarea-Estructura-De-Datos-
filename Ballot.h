#ifndef BALLOT_H
#define BALLOT_H

#include <vector>
#include <string>

class Ballot
{
public:
    Ballot(const std::vector<std::string> &names);
    std::string getCandidate() const;
    void eliminate(const std::string &name);
    bool isEmpty() const;

private:
    std::vector<std::string> preferences;
};

#endif // BALLOT_H
