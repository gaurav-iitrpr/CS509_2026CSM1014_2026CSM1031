#ifndef FASTMAP_H
#define FASTMAP_H

#include <string>
#include <vector>

using namespace std;

struct FastMapResult
{
    vector<vector<double>> coordinates;
    vector<pair<int, int>> pivots;
};

FastMapResult fastMap(
    const vector<vector<double>>& distances,
    int k
);

void runFastMap(const string& filename);

#endif