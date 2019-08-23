#include "node.h"
#include "grid.h"
#include <iostream>
#include <vector>

//__________________________________________________
//##################################################
// {     node class 
//
// child class VirtualNode


Node::Node(unsigned int index)
{

    t_neighbor    = NULL;
    l_neighbor    = NULL;
    b_neighbor    = NULL;
    r_neighbor    = NULL;
    this->index   = index;
    root          = this;
    // 
    open          = false;
    
    child_nodes.push_back(this);
}

void Node::map_neighbors(unsigned int N,  
                         unsigned int index,
                         std::vector<Node> &node_vector)
{


    // identify index for top and bottom root
    const unsigned int TOP_ROOT_INDEX    = N;
    const unsigned int BOTTOM_ROOT_INDEX = N+1;
    // real nodes 0 - (N - 1)
    // LEFT
    if(index % N)                        l_neighbor   = &node_vector[index - 1];
    // RIGHT
    if((index + 1) %  N)                 r_neighbor   = &node_vector[index + 1];

    // TOP15
    if((index + N) <  (N * N))           t_neighbor   = &node_vector[index + N];
    // top_neighbor    => top_root
    else                                 t_neighbor   = &node_vector[TOP_ROOT_INDEX];

    // BOTTOM
    if(((int)index - (int)N) >= 0)       b_neighbor   = &node_vector[index - N];
    // bottom_neighbor => bottom_root
    else                                 b_neighbor   = &node_vector[BOTTOM_ROOT_INDEX];

    // identify top and bottom nodes 
    root = (index < N)              ? &node_vector[BOTTOM_ROOT_INDEX] :
           ((index + N) >= (N * N)) ? &node_vector[TOP_ROOT_INDEX]    :
                                      root;
}



void Node::join(Node* node)
{
    // join 
    // up, left, down, right 
    Node* new_root = node->get_root();
    new_root->child_nodes.insert(new_root->child_nodes.end(), 
                                 root->child_nodes.begin(), 
                                 root->child_nodes.end());
    // TODO 
    // change root for each new node in vector
    //

    // then clear 
    root->child_nodes.clear();

}


// } end node class 
//__________________________________________________


//__________________________________________________
//##################################################
// {    virtual node class 

VirtualNode::VirtualNode(int N) 
{ 
    for(int i = 0; i < N ; ++i)
    {
        neighbors_index.push_back(N - i - 1);
    }
    root = this;
    open = true;
}



// } end virtual node class 
//__________________________________________________

