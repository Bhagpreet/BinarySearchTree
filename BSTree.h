    #ifndef __BSTREE_H__
    #define __BSTREE_H__

    #include <iostream>
    #include "Node.h"


    using namespace std;

    class BSTree {

    private:
    Node *root;   

    private:
    void preOrder(Node *) const;
    Node* insertHelper(Node* root, const string & word);
    Node* searchHelper(Node*,const string & word) const;
    void inOrderHelper(Node* ) const;
    void postOrderHelper(Node* ) const;
    void preOrderHelper(Node* ) const;
    Node* findMax(Node* item) const;
    Node* findMin(Node* item) const;
    int heightHelper(Node* item) const;
    void removeHelper(Node* & value);
    bool insertHelp;

    public:
    BSTree();
    void insert(const string &);
    bool search(const string &) const;
    void inOrder( ) const;
    void postOrder( ) const;
    void preOrder( ) const;
    string largest( ) const;
    string smallest( ) const;
    int height(const string &) const;    
    void remove(const string &);
    };

    #endif