#ifndef SINGLYCL_H
#define SINGLYCL_H

#include <lists/node.h>

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Class name: SinglyCL                                            //
//                                                                  //
//  Description: This class consists of members which are used to   //  
//               Manupulate and perform various operations on       //
//               Singly Circular Linked List.                         //
//                                                                  //
//  Date : 8 September 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    private:

        struct nodeS <T> * First;
        struct nodeS <T> * Last;
    
    protected:
    
        int iCount;
    
    public:
        SinglyCL();

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
class Stack : private SinglyCL<T>
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

template class SinglyCL<void*>;
template class SinglyCL<int>;
template class SinglyCL<float>;
template class SinglyCL<double>;
template class SinglyCL<char>;
template class SinglyCL<bool>;
template class SinglyCL<std::string>;

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

#endif  //SINGLYCL_H