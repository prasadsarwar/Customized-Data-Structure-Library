#ifndef NODE_H
#define NODE_H

#include <iostream>

#pragma pack(1)

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Structure name: nodeS                                           //
//                                                                  //
//  Description: It is a structure of node of a Singly linked List  //  
//                                                                  //
//  Members: 1) T Data : This is a generic variable that will store //                                                    
//              actual values (data) of a node in linked list       //
//           2) struct nodeS *next : It is the self pointer that    //
//              stores the address of the corresponding node in list//
//                                                                  //
//  Used By: 1) Singly Linear Linked List                           //
//           2) Singly Circular Linked List                         //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
struct nodeS
{
    T Data;
    struct nodeS *next;
};

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Structure name: nodeD                                           //
//                                                                  //
//  Description: It is a structure of node of a Doubly linked List  //  
//                                                                  //
//  Members: 1) T Data : This is a generic variable that will store //                                                    
//              actual values (data) of a node in linked list       //
//           2) struct nodeS *next : It is the self pointer that    //
//              stores the address of the next node in list         //
//           3) struct nodeS *prev : It is the self pointer that    //
//              stores the address of the previous node in list     //
//                                                                  //
//  Used By: 1) Doubly Linear Linked List                           //
//           2) Doubly Circular Linked List                         //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////


template <class T>
struct nodeD
{
    T Data;
    struct nodeD *next;
    struct nodeD *prev;
};

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Structure name: treenode                                        //
//                                                                  //
//  Description: It is a structure representing a node in a binary  //
//               tree                                               //
//                                                                  //
//  Members:                                                        //
//    1) T Data : This is a generic variable that will store actual //
//                 values (data) of a node in the binary tree       //
//    2) struct nodeD *lchild : It is a pointer to the left child   //
//       of the current node in the binary tree                     //
//    3) struct nodeD *rchild : It is a pointer to the right child  //
//       of the current node in the binary tree                     //
//                                                                  //
//  Used By:                                                        //
//    Binary tree structures                                        //
//                                                                  //
//  Date: 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
struct treenode
{
    T Data;
    struct treenode *lchild;
    struct treenode *rchild;
};

//////////////////////////////////////////////////////////////////////

#endif //NODE_H