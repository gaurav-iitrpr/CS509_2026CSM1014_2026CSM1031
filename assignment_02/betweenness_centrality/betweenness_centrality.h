#ifndef BETWEENNESS_CENTRALITY_H
#define BETWEENNESS_CENTRALITY_H

#include "../../common/csr.h"
#include <string>
#include <vector>

using namespace std;

vector<double> calculateBetweennessCentrality(const CSRGraph &graph);

void runBetweennessCentrality(const string &filename);

#endif