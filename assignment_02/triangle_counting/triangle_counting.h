#ifndef TRIANGLE_COUNTING_H
#define TRIANGLE_COUNTING_H
#include "../../common/csr.h"
#include <string>

using namespace std;
int countTriangles(const CSRGraph &graph);
void runTriangleCounting(const string &filename);

#endif