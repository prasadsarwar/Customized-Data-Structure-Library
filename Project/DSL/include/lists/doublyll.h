#ifndef DOUBLYLL_H
#define DOUBLYLL_H

#include <lists/node.h>

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Class name: DoublyLL                                            //
//                                                                  //
//  Description: This class consists of members which are used to   //  
//               Manupulate and perform various operations on       //
//               Doubly Linear Linked List.                         //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    private:

        struct nodeD <T> * First;

    protected:

        int iCount;

    public:
        DoublyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int iPos);

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
class Stack : public DoublyLL<T>
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

template class DoublyLL<void*>;
template class DoublyLL<int>;
template class DoublyLL<float>;
template class DoublyLL<double>;
template class DoublyLL<char>;
template class DoublyLL<bool>;
template class DoublyLL<std::string>;

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


#endif    //DOUBLYLL_H