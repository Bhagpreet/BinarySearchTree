    #include "Node.h"

    Node::Node()
    : left(0), right(0), count(1), data("") {}

    Node::Node(const string & word)
    : left(0), right(0), count(1), data(word) {}