#ifndef DOUBLYCL_H
#define DOUBLYCL_H

#include <lists/node.h>

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Class name: DoublyLL                                            //
//                                                                  //
//  Description: This class consists of members which are used to   //  
//               Manupulate and perform various operations on       //
//               Doubly Circular Linked List.                       //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    private:
        struct nodeD <T> * First;
        struct nodeD <T> * Last;
    
    protected:
    
        int iNodeCnt;

    public:

        DoublyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int CountNodes();


        //Extra Functions:

        T GetNodeData();
        T GetMiddleData();
        T GetFirstData();

        //sorting algorithms:

        void BubbleSort();
        void SelectionSort();
        void InsertionSort();

        //Searching algorithms:

        int LinearSearch(T Data);

        // int SearchFirstOcc(T no);
        // int SearchLastOcc(T no);
        // T Maximum();
        // T Minimum();
};


template <class T>
class Stack : private DoublyCL<T>
{
    private:
        int iSize;
    public: 
        Stack(int size);

        void Push(T Data);
        void Pop();
        bool CheckFull();
        bool CheckEmpty();

        T GetTop();
        int GetCount();

        void DisplayStack();

};

//////////////////////////////////////////////////////////////////////

template class DoublyCL<void*>;
template class DoublyCL<int>;
template class DoublyCL<float>;
template class DoublyCL<double>;
template class DoublyCL<char>;
template class DoublyCL<bool>;
template class DoublyCL<std::string>;

//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////

template class Stack<void*>;
template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<char>;
template class Stack<bool>;
template class Stack<std::string>;

//////////////////////////////////////////////////////////////////////


#endif