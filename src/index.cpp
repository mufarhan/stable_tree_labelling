#include "road_network.h"

#include <iostream>
#include <fstream>

using namespace std;
using namespace road_network;

int main(int argc, char** argv)
{

    // read graph
    ifstream ifs(argv[1]);
    Graph g;
    read_graph(g, ifs);
    ifs.close();

    // degree 1 node contraction
    vector<Neighbor> closest;
    g.contract(closest);

    // construct index
    vector<CutIndex> ci;
    g.create_cut_index(ci, 0.2);
    ContractionIndex con_index(ci, closest);

    // write index
    ofstream ofs(argv[2]);
    con_index.write(ofs);
    ofs.close();

    return 0;
}
