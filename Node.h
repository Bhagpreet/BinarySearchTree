    #ifndef NODE_H
    #define NODE_H

    #include <iostream>
    
    using namespace std;

    class Node{
        public:
        Node* left;
        Node* right;
        Node* parent;
        int count;
        string data;
        Node();
        Node(const string & word);
    };


    #endif