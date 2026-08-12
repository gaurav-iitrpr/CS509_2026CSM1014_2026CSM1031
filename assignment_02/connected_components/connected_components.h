#ifndef CONNECTED_COMPONENTS_H
#define CONNECTED_COMPONENTS_H

#include "../../common/csr.h"
#include <string>

using namespace std;

int countConnectedComponents(
    const CSRGraph &graph
);

void runConnectedComponents(const string &filename);

#endif