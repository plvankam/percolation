#ifndef GRID_H
#define GRID_H

#include<vector>
#include<memory>

#include"node.h"

class Grid
{
private:
    std::vector<Node>      Node_Vector;
    Node                   top_node;
    unsigned int           num_nodes;
public:
    // Grid();
    Grid(unsigned int N);
    ~Grid() {}
    bool         Percolates()    const;
    unsigned int get_num_nodes() const { return num_nodes ; }
    bool         open(unsigned int index);
 };

#endif // GRID_H
