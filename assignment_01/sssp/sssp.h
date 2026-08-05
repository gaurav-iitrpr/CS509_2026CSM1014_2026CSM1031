#ifndef SSSP_H
#define SSSP_H

#include "../common/csr.h"

#include <vector>
#include <string>

using namespace std;
vector<int> dijkstra(const CSRGraph &graph, int source);
void runSSSP(const string &filename);

#endif