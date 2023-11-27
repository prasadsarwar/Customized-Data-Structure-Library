#ifndef TREE_H
#define TREE_H

#include <lists/node.h>
using namespace std;

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Class name: BTree                                               //
//                                                                  //
//  Description: This class represents a Binary Tree data structure //
//               and provides various operations for manipulating   //
//               and managing the tree, including insertion,        //
//               deletion, traversal, and counting operations.      //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////


template <class T>
class BTree
{   
    private:

        struct treenode<T>* Root;

        treenode<T>* DeleteNode(treenode<T>* root, T key);
        void DisplayInorder(treenode<T>* node);
        void DisplayPreorder(treenode<T>* node);
        void DisplayPostorder(treenode<T>* node);
        int CountLeafNode(treenode<T>* node);
        bool SearchRecursive(treenode<T>* node, T Data);
        int CountParentNode(treenode<T>* node);
        int CountCompleteParentNode(treenode<T>* node);

    public:

        BTree();
        void Insert(T Data);
        void DeleteNode(T Data); 

        void DisplayInorder();
        void DisplayPreorder();
        void DisplayPostorder();

        bool Search(T Data);

        int CountLeafNode();
        int CountParentNode();
        int CountCompleteParentNode();

};

//////////////////////////////////////////////////////////////////////

// template class BTree<void*>;
template class BTree<int>;
template class BTree<float>;
template class BTree<double>;
template class BTree<char>;
template class BTree<bool>;
template class BTree<std::string>;

//////////////////////////////////////////////////////////////////////

#endif  //TREE_H