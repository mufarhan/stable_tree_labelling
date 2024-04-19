#include "road_network.h"
#include "util.h"

#include <iostream>
#include <fstream>

using namespace std;
using namespace road_network;

const size_t nr_updates = 1000;
const size_t MB = 1024 * 1024;

int main(int argc, char** argv)
{

    // read graph
    fstream fs(argv[1]);
    Graph g;
    read_graph(g, fs);
    fs.close();

    // read index
    fs.open(argv[2]);
    util::start_timer();
    ContractionIndex con_index(fs);
    double read_index_time = util::stop_timer();
    fs.close();
    cout << "read index in " << read_index_time << "s (" << con_index.size() / MB << " MB)" << endl;

    vector<pair<pair<distance_t, distance_t>, pair<NodeID, NodeID> > > updates;
    fs.open(argv[3]); NodeID a, b; distance_t weight;
    while(fs >> a >> b >> weight) {

        distance_t new_weight;
        if(argv[4][0] == 'd')
            new_weight = weight * 0.5;
        else if(argv[4][0] == 'i')
            new_weight = weight * 1.5;

        updates.push_back(make_pair(make_pair(weight, new_weight), make_pair(a, b)));
    }
    fs.close();

    util::start_timer();
    if(argv[4][0] == 'd') {
        //g.LabelSearchDec(con_index, updates);
        g.ParetoSearchDec(con_index, updates);
    } else if(argv[4][0] == 'i') {
        //g.LabelSearchInc(con_index, updates);
        g.ParetoSearchInc(con_index, updates);
    }
    double random_update_time = util::stop_timer();
    cout << "ran " << updates.size() << " random updates in " << random_update_time << endl;
    return 0;
}
