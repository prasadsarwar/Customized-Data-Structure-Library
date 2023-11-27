#ifndef SINGLYLL_H
#define SINGLYLL_H

#include <lists/node.h>

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Class name: SinglyLL                                            //
//                                                                  //
//  Description: This class consists of members which are used to   //  
//               Manupulate and perform various operations on       //
//               Singly Linear Linked List.                         //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{      
    private:


    protected:
    
        struct nodeS<T> * First;
        int iCount;
    
    public: 
        SinglyLL();

        // Fundamental functions:

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
        // nodeS<T> GetHead();

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


//////////////////////////////////////////////////////////////////////

template class SinglyLL<void*>;
template class SinglyLL<int>;
template class SinglyLL<float>;
template class SinglyLL<double>;
template class SinglyLL<char>;
template class SinglyLL<bool>;
template class SinglyLL<std::string>;

//////////////////////////////////////////////////////////////////////


#endif //SINGLYLL_H