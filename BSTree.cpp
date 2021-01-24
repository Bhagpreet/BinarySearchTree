    #include "BSTree.h"

    BSTree::BSTree()
    : root(0) {}
    
    void BSTree::insert(const string & word){
        insertHelp = true;
        if (root == 0){
            root = new Node(word);
            return;
        }
        insertHelper(root, word);
        if (insertHelp){ // this helps create the parent function and the bool insertHelp is to not recreate a parent when the count of a node is increased
            Node* temp = root;
            while(temp->right != 0 || temp->left != 0){
                if (temp->right){
                    if (temp->right->data == word){
                        temp->right->parent = temp;
                    }
                }
                if (temp->left){
                    if (temp->left->data == word){
                        temp->left->parent = temp;
                    }
                }
                if (word > temp->data){
                    temp = temp->right;
                }else {
                    temp = temp->left;
                }
            }
        }
    }

    Node* BSTree::insertHelper(Node* item, const string & word){
        if (!item){
            return new Node(word);
        }
        if (word > item->data){
            item->right = insertHelper(item->right, word);
        }else if(word == item->data){
            item->count++;
            insertHelp = false;
            return item;
        }else{
            item->left = insertHelper(item->left, word);
        }
        return item;
    }
    // Insert an item into the binary search tree. Be sure to keep the binary search tree properties. 
    // When an item is first inserted into the tree the count should be set to 1. 
    // When adding a duplicate string (case sensitive), rather than adding another node, the count variable should just be incremented.

    bool BSTree::search(const string & word) const{
        Node* temp = searchHelper(root, word);
        if (temp){
            return true;
        }
        return false;
    }

    Node* BSTree::searchHelper(Node* item,const string & word) const{
        if (!item){
            return 0;
        }        
        if (word == item->data){
            return item;
        }
        if (word > item->data){
            return searchHelper(item->right, word);
        }else{
            return searchHelper(item->left, word);
        }
        return 0;
    }
    // Search for a string in the binary search tree. It should return true if the string is in the tree, and false otherwise.
    
    void BSTree::inOrder( ) const{
        inOrderHelper(root);
        cout << endl;
    }

    void BSTree::inOrderHelper(Node* item) const{
        if (item){
            inOrderHelper(item->left);
            cout << item->data << "(" << item->count << "), ";
            inOrderHelper(item->right);
        }
    }

    void BSTree::postOrder( ) const{
        postOrderHelper(root);
        cout << endl;
    }

    void BSTree::postOrderHelper(Node* item) const{
        if (item){
            postOrderHelper(item->left);
            postOrderHelper(item->right);
            cout << item->data << "(" << item->count << "), ";
        }
    }
    
    void BSTree::preOrder( ) const{
        preOrderHelper(root);
        cout << endl;
    }

    void BSTree::preOrderHelper(Node* item) const{
        if (item){
            cout << item->data << "(" << item->count << "), ";
            preOrderHelper(item->left);
            preOrderHelper(item->right);
        }
    }
    
    string BSTree::largest( ) const{
        if (root == 0){
            return "";
        }
        Node* largest = findMax(root);
        return largest->data;
    }

    Node* BSTree::findMax(Node* item) const{
        if (item->right){
            item = findMax(item->right);
        }
        return item;
    }
    // Find and return the largest value in the tree. Return an empty string if the tree is empty.
    
    string BSTree::smallest( ) const{
        if (root == 0){
            return "";
        }
        Node* smallest = findMin(root);
        return smallest->data;
    }

    Node* BSTree::findMin(Node* item) const{
        if (item->left){
            item = findMin(item->left);
        }
        return item;
    }
    // Find and return the smallest value in the tree. Return an empty string if the tree is empty.
    
    int BSTree::height(const string & word) const{
        Node* value = searchHelper(root, word);
        if (value == 0){
            return -1;
        }
        return heightHelper(value);
    }

    int BSTree::heightHelper(Node* item) const{
        int left = 0;
        int right = 0;

        if (item == 0){
            return -1;
        }
        
        left = 1 + heightHelper(item->left);
        right = 1 + heightHelper(item->right);
        
        if (left > right){
            return left;
        }else{
            return right;
        }
    }


    // Compute and return the height of a particular string in the tree.
    // The height of a leaf node is 0 (count the number of edges on the longest path). Return -1 if the string does not exist.
    
    void BSTree::remove(const string & word){
        Node* value = searchHelper(root, word);
        if (value == 0){
            return;
        }
        if (value->count > 1){ // checks here first so it doesn't recursively call and auto returns
            value->count--;
            return;
        }
        removeHelper(value);
    }

    void BSTree::removeHelper(Node* & value){
        if (value->left == 0 && value->right == 0){
            if (value == root){
                delete root;
                root = 0;
                return;
            }  
            Node* temp = value->parent;
            
            if (temp->right && temp->right == value){
                temp->right = 0;
            }else{  
                temp->left = 0;
            }
            delete value;
            return;
        }
        else if (value->left){
            Node* max = findMax(value->left);
            value->data = max->data;
            value->count = max->count;  
            removeHelper(max);
        }else {
            Node* min = findMin(value->right);
            value->data = min->data;
            value->count = min->count;
            removeHelper(min);
        }
    }


    // If the left child exists
    // Replace node information with the largest
    // value smaller than the value to remove  findMax(leftChild)
    // Else there is a right child
    // Replace node information with the smallest
    // value larger than value to remove  findMin(rightChild)

