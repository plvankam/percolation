#ifndef NODE_H
#define NODE_H

#include<memory>
#include<vector>


//__________________________________________________
//##################################################
// {     node class 
//
// child class VirtualNode

class Node
{
private:
    // pointers to neighbors
    Node*                   t_neighbor;
    Node*                   b_neighbor;
    Node*                   l_neighbor;
    Node*                   r_neighbor;
    // pointer to root (union)
    Node*                   root;
    bool                    open;
    // index
    unsigned int            index;

public:

    // pointer to nodes in tree (if root)
    std::vector<Node*>      child_nodes;

    explicit Node() {}
    explicit Node(unsigned int index);
    ~Node() {}
    void map_neighbors(unsigned int N, 
                       unsigned int index,  
                       std::vector<Node> &node_vector);
    void join(Node* node);

    // inline 
    unsigned short is_open()  const { return open;}
    Node*          get_root() const { return root;}
 
};

// } end node class 
//__________________________________________________

//__________________________________________________
//##################################################
// {    virtual node class 

class VirtualNode : public Node 
{
    private:
        std::vector<int>   neighbors_index;
        Node*              root;
        bool               open;
    public:
        explicit VirtualNode(int N);


};

// } end virtual node class 
//__________________________________________________

#endif // NODE_H
