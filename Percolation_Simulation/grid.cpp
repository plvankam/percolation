#include "grid.h"
#include "node.h"
#include<memory>
#include<algorithm>

Grid::Grid(unsigned int N)
{
    num_nodes = N;
    top_node  = VirtualNode(N);

    // fill vector<Node>
    for(unsigned int i = 0; i < N; ++i)
    {
        Node_Vector.push_back(Node(i));
    }
    // push back top and bottom roots
    Node_Vector.push_back(top_node);
    // Node_Vector.push_back(bottom_root);

    // map neighbors for nodes
    for(unsigned int i = 0; i < N; ++i)
        {Node_Vector[i].map_neighbors(N,i,Node_Vector);  }
}


bool Grid::Percolates() const
{
    unsigned int N                = num_nodes;
    Node*        top_node_root    = Node_Vector[N].get_root();
    // if(Node_Vector[N].get_root() == Node_Vector[N+1].get_root())
    for(int i = 0; i < N; ++i)
    {
        // scan bottom row and compare
        // against top node
        if(Node_Vector[i].get_root() == top_node_root)
        {
            return true;
        }
    }
    return false;
}

bool Grid::open(unsigned int index)
{
    if(!Node_Vector[index].is_open())
    {

    }
}
