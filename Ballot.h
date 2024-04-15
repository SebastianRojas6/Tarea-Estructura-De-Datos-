#ifndef BALLOT_H
#define BALLOT_H

#include <vector>
#include <string>

using namespace std;
class Ballot
{
public:
    Ballot(const vector<string> &names);
    string getCandidate() const;
    void eliminate(const string &name);
    bool isEmpty() const;

private:
    vector<string> preferences;
};

#endif // BALLOT_H
