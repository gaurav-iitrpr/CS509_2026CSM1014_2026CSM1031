#ifndef BFS_H
#define BFS_H
#include "../common/csr.h"
#include <vector>
using namespace std;

vector<int> bfsTraversal(const CSRGraph &graph, int source);
vector<int> bfsDistance(const CSRGraph &graph, int source);
void runBFS(const string &filename);

#endif