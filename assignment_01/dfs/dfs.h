#ifndef DFS_H
#define DFS_H
#include "../common/csr.h"
#include <vector>
#include <string>

using namespace std;

vector<int> dfsTraversal(const CSRGraph &graph, int source);

void runDFS(const string &filename);

#endif