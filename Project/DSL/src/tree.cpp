#ifndef TREE_CPP
#define TREE_CPP

#include <lists/tree.h>
#include <stdbool.h>
#include <string.h>
using namespace std;

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: BTree();                                         //
//                                                                  //
//  Parameters: --                                                  //
//                                                                  //
//  Description: Constructor for the BTree class. Initializes the   //
//               binary tree with a null root.                      //
//                                                                  //
//  Return Parameter: --                                            //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template<class T>
BTree<T>:: BTree()
{
    Root = NULL;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void Insert(T Data);                             //
//                                                                  //
//  Parameters:                                                     //
//      - T Data: The data to be inserted into the binary tree.     //
//                                                                  //
//  Description: Inserts a new node with the provided data into     //
//               the binary tree. If the data already exists, it    //
//               displays a message indicating that duplicate       //
//               elements are not allowed.                          //
//                                                                  //
//  Return Parameter: --                                            //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void BTree<T>:: Insert(T Data)
{
    struct treenode<T> *newn = new struct treenode<T>;
    newn->Data = Data;
    newn->lchild = NULL;
    newn->rchild = NULL;

    struct treenode<T> *Temp = Root;

    if(Root == NULL)
    {
        Root = newn;
    }
    else
    {
        while(1)
        {
            if(Data > Temp->Data)
            {
                if(Temp->rchild == NULL)
                {
                    Temp->rchild = newn;
                    break;
                }
                Temp = Temp->rchild;
            }
            else if(Data < Temp->Data)
            {
                if(Temp->lchild == NULL)
                {
                    Temp->lchild = newn;
                    break;
                }
                Temp = Temp->lchild;
            }
            else if(Data == Temp->Data)
            {
                free(newn);
                cout<<"Duplicate element not allowed"<<endl;
                break;
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DeleteNode(T Data);                         //
//                                                                  //
//  Parameters:                                                    //
//      - T Data: The data to be deleted from the binary tree.      //
//                                                                  //
//  Description: Deletes a node with the provided data from the     //
//               binary tree. If the data is not found, it returns  //
//               the root unchanged. If the data is found, it       //
//               handles the case of nodes with one or two children.//
//                                                                  //
//  Return Parameter: --                                            //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void BTree<T>::DeleteNode(T Data) 
{
    DeleteNode(Root, Data);
}

template <class T>
treenode<T>* BTree<T>::DeleteNode(treenode<T>* root, T key) 
{
    if (root == NULL) 
    {
        return root; // Node not found
    }

    if (key < root->Data) 
    {
        root->lchild = DeleteNode(root->lchild, key);
    } 
    else if (key > root->Data) 
    {
        root->rchild = DeleteNode(root->rchild, key);
    } 
    else 
    {
        // Node with the key to be deleted found

        // Node with only one child or no child
        if (root->lchild == NULL) 
        {
            treenode<T>* temp = root->rchild;
            delete root;
            return temp;
        } 
        else if (root->rchild == NULL) 
        {
            treenode<T>* temp = root->lchild;
            delete root;
            return temp;
        }

        // Node with two children: get the in-order successor (or predecessor)
        treenode<T>* temp = findMin(root->rchild); // Find the in-order successor
        root->Data = temp->Data; // Copy the Data of the in-order successor
        root->rchild = DeleteNode(root->rchild, temp->Data); // Delete the in-order successor
    }

    return root;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: treenode<T>* findMin(treenode<T>* root);         //
//                                                                  //
//  Parameters:                                                    //
//      - treenode<T>* root: The root of the binary search tree.    //
//                                                                  //
//  Description: Finds and returns the node with the minimum value  //
//               in the binary search tree.                         //
//                                                                  //
//  Return Parameter: treenode<T>*: The node with the minimum value //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

// Function to find the minimum value node in a BST
template <class T>
treenode<T>* findMin(treenode<T>* root) {
    while (root->lchild != NULL) {
        root = root->lchild;
    }
    return root;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DisplayInorder();                           //
//                                                                  //
//  Parameters: --                                                  //
//                                                                  //
//  Description: Displays the elements of the binary tree in       //
//               inorder traversal.                                 //
//                                                                  //
//  Return Parameter: --                                            //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void BTree<T>::DisplayInorder()
{
    DisplayInorder(Root);
    cout << endl;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DisplayInorder(treenode<T>* node);          //
//                                                                  //
//  Parameters:                                                    //
//      - treenode<T>* node: The root or node to start the          //
//        inorder traversal from.                                  //
//                                                                  //
//  Description: Helper function for displaying the elements of    //
//               the binary tree in inorder traversal.              //
//                                                                  //
//  Return Parameter: --                                            //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void BTree<T>::DisplayInorder(treenode<T>* node)
{
    if (node != NULL)
    {
        DisplayInorder(node->lchild);
        cout << "| " << node->Data << " |\t";
        DisplayInorder(node->rchild);
    }
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DisplayPreorder();                          //
//                                                                  //
//  Parameters: --                                                  //
//                                                                  //
//  Description: Displays the elements of the binary tree in       //
//               preorder traversal.                                //
//                                                                  //
//  Return Parameter: --                                            //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void BTree<T>::DisplayPreorder()
{
    DisplayPreorder(Root);
    cout << endl;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DisplayPreorder(treenode<T>* node);         //
//                                                                  //
//  Parameters:                                                     //
//      - treenode<T>* node: The root or node to start the          //
//        preorder traversal from.                                  //
//                                                                  //
//  Description: Helper function for displaying the elements of     //
//               the binary tree in preorder traversal.             //
//                                                                  //
//  Return Parameter: --                                            //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void BTree<T>::DisplayPreorder(treenode<T>* node)
{
    if (node != NULL)
    {
        cout << "| " << node->Data << " |\t";
        DisplayPreorder(node->lchild);
        DisplayPreorder(node->rchild);
    }
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DisplayPostorder();                         //
//                                                                  //
//  Parameters: --                                                  //
//                                                                  //
//  Description: Displays the elements of the binary tree in        //
//               postorder traversal.                               //
//                                                                  //
//  Return Parameter: --                                            //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void BTree<T>::DisplayPostorder()
{
    DisplayPostorder(Root);
    cout << endl;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DisplayPostorder(treenode<T>* node);        //
//                                                                  //
//  Parameters:                                                     //
//      - treenode<T>* node: The root or node to start the          //
//        postorder traversal from.                                 //
//                                                                  //
//  Description: Helper function for displaying the elements of     //
//               the binary tree in postorder traversal.            //
//                                                                  //
//  Return Parameter: --                                            //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void BTree<T>::DisplayPostorder(treenode<T>* node)
{
    if (node != NULL)
    {
        DisplayPostorder(node->lchild);
        DisplayPostorder(node->rchild);
        cout << "| " << node->Data << " |\t";
    }
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: bool Search(T Data);                             //
//                                                                  //
//  Parameters:                                                    //
//      - T Data: The data to be searched in the binary tree.       //
//                                                                  //
//  Description: Searches for the specified data in the binary     //
//               tree using a recursive approach and returns true  //
//               if found, or false if not found.                   //
//                                                                  //
//  Return Parameter: bool: true if the data is found, false if not //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
bool BTree<T>::Search(T Data)
{
    return SearchRecursive(Root, Data);
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: bool SearchRecursive(treenode<T>* node, T Data);  //
//                                                                  //
//  Parameters:                                                    //
//      - treenode<T>* node: The root or node to start the search   //
//        from.                                                     //
//      - T Data: The data to be searched in the binary tree.       //
//                                                                  //
//  Description: Recursive helper function for searching for the    //
//               specified data in the binary tree.                 //
//                                                                  //
//  Return Parameter: bool: true if the data is found, false if not //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
bool BTree<T>::SearchRecursive(treenode<T>* node, T Data)
{
    if (node == NULL)
    {
        return false; // Element not found
    }

    if (node->Data == Data)
    {
        return true; // Element found
    }
    else if (Data > node->Data)
    {
        return SearchRecursive(node->rchild, Data);
    }
    else
    {
        return SearchRecursive(node->lchild, Data);
    }
}


//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: int CountLeafNode();                             //
//                                                                  //
//  Parameters: --                                                  //
//                                                                  //
//  Description: Counts and returns the number of leaf nodes in    //
//               the binary tree. A leaf node is a node with no     //
//               children.                                          //
//                                                                  //
//  Return Parameter: int: Number of leaf nodes in the binary tree //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
int BTree<T>:: CountLeafNode()
{
    return CountLeafNode(Root);
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: int CountLeafNode(treenode<T>* node);            //
//                                                                  //
//  Parameters:                                                     //
//      - treenode<T>* node: The root or node to start the count    //
//        from.                                                     //
//                                                                  //
//  Description: Helper function for counting the number of leaf    //
//               nodes in the binary tree.                          //
//                                                                  //
//  Return Parameter: int: Number of leaf nodes under the provided  //
//  node.                                                           //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
int BTree<T>:: CountLeafNode(treenode<T>* node)
{
    int Count = 0;
    if(node != NULL)
    {
        if((node->lchild == NULL) && (node->rchild == NULL))
        {
            Count++;
        }
        Count = Count + CountLeafNode(node->lchild);
        Count = Count + CountLeafNode(node->rchild);
    }
    return Count;  
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: int CountParentNode();                            //
//                                                                  //
//  Parameters: --                                                  //
//                                                                  //
//  Description: Counts and returns the number of parent nodes in   //
//               the binary tree. A parent node is a node that has  //
//               at least one child.                                //
//                                                                  //
//  Return Parameter: int: Number of parent nodes in the binary tree//
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
int BTree<T>::CountParentNode()
{
    return CountParentNode(Root);
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: int CountParentNode(treenode<T>* node);          //
//                                                                  //
//  Parameters:                                                    //
//      - treenode<T>* node: The root or node to start the count   //
//        from.                                                     //
//                                                                  //
//  Description: Helper function for counting the number of parent  //
//               nodes in the binary tree.                           //
//                                                                  //
//  Return Parameter: int: Number of parent nodes under the provided//
//  node.                                                          //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
int BTree<T>::CountParentNode(treenode<T>* node)
{
    int Count = 0;

    if (node != NULL)
    {
        if (node->lchild != NULL || node->rchild != NULL)
        {
            Count++;
        }
        Count += CountParentNode(node->lchild);
        Count += CountParentNode(node->rchild);
    }

    return Count;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: int CountCompleteParentNode();                    //
//                                                                  //
//  Parameters: --                                                  //
//                                                                  //
//  Description: Counts and returns the number of complete parent   //
//               nodes in the binary tree. A complete parent node is //
//               a node that has both a left and a right child.      //
//                                                                  //
//  Return Parameter: int: Number of complete parent nodes in the   //
//  binary tree.                                                    //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
int BTree<T>::CountCompleteParentNode()
{
    return CountCompleteParentNode(Root);
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: int CountCompleteParentNode(treenode<T>* node);   //
//                                                                  //
//  Parameters:                                                    //
//      - treenode<T>* node: The root or node to start the count   //
//        from.                                                     //
//                                                                  //
//  Description: Helper function for counting the number of complete //
//               parent nodes in the binary tree.                   //
//                                                                  //
//  Return Parameter: int: Number of complete parent nodes under    //
//  the provided node.                                              //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 23 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
int BTree<T>::CountCompleteParentNode(treenode<T>* node)
{
    int Count = 0;

    if (node != NULL)
    {
        if (node->lchild != NULL && node->rchild != NULL)
        {
            Count++;
        }
        Count += CountCompleteParentNode(node->lchild);
        Count += CountCompleteParentNode(node->rchild);
    }

    return Count;
}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////

#endif