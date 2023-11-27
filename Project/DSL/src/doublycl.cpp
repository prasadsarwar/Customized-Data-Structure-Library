#ifndef DOUBLYCL_CPP
#define DOUBLYCL_CPP

#include <lists/doublycl.h>
using namespace std;


//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: DoublyCL()  {Default Constructor}                //
//                                                                  //
//  Description: This is simply a default constructor which         //
//               initialises the characteristics of the DoublyLL    //
//               class                                              //
//                                                                  //
//  Author : Prasad Sarwar                                          //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
DoublyCL <T>:: DoublyCL()  // Default constructor
{
    First = NULL;
    Last = NULL;
	iNodeCnt = 0;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: void InsertFirst(T no)                           //
//                                                                  //
//  Parameters: 1) T no : It actual data that is to be inserted in  //
//                        Linked List                               //
//                                                                  //
//  Description: This function adds (inserts) a new node at the     //
//               begining of the linked list and increments the     //
//               count of nodes in linked list                      //
//                                                                  //
//  Author : Prasad Sarwar                                          //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL <T>:: InsertFirst(T no)
{
    struct nodeD <T> * newn = new struct nodeD <T>; 

    newn->Data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn; 
    }

    (First)->prev = Last;
    (Last)->next = First;
	iNodeCnt++;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: void InsertLast(T no)                            //
//                                                                  //
//  Parameters: 1) T no : It actual data that is to be inserted in  //
//                        Linked List                               //
//                                                                  //
//  Description: This function adds (inserts) a new node at the     //
//               end of the linked list and increments the          //
//               count of nodes in linked list                      //
//                                                                  //
//  Author : Prasad Sarwar                                          //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL <T>:: InsertLast(T no)
{
    struct nodeD <T> * newn = new struct nodeD <T>; 

    newn->Data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        (Last) -> next = newn;
        newn->prev = Last;
        Last = newn;
    }

    (First)->prev = Last;
    (Last)->next = First;
	iNodeCnt++;
}

//////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: void InsertAtPosition(T no, int iPos)            //
//                                                                  //
//  Parameters: 1) T no : It actual data that is to be inserted in  //
//                        Linked List                               //
//               2) int ipos : It is the actual position (starts    //
//                        from 1) given by user to insert the node  //
//                                                                  //
//  Description: This function adds (inserts) a new node at the     //
//               specific position (iPos) in the linked list and    //
//               increments the count of nodes in linked list       //
//                                                                  //
//  Author : Prasad Sarwar                                          //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////


template <class T>
void DoublyCL <T>:: InsertAtPos(T no, int ipos)
{
    struct nodeD <T> * newn = NULL;
    struct nodeD <T> * temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct nodeD <T>;
        newn->Data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
		iNodeCnt++;
    }
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: void DeleteFirst()                               //
//                                                                  //
//  Parameters: --                                                  //
//                                                                  //
//  Description: This function removes (delete) the first node      //
//               of linked list and decrements the count of nodes   //
//                                                                  //
//  Author : Prasad Sarwar                                          //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL <T>:: DeleteFirst()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single nodeD
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one nodeD
    {
        (First) = (First) ->next;
        delete (Last)->next;        // free((*First)->prev);

        (First)->prev = Last;
        (Last)->next = First;
    }
	iNodeCnt--;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: void DeleteLast()                                //
//                                                                  //
//  Parameters: --                                                  //
//                                                                  //
//  Description: This function removes (delete) the last node       //
//               of linked list and decrements the count of nodes   //
//                                                                  //
//  Author : Prasad Sarwar                                          //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL <T>:: DeleteLast()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single nodeD
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one nodeD
    {
        Last = (Last) -> prev;
        delete (First)->prev;       // free((*Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
	iNodeCnt--;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: void DeleteAtPos(int ipos)                  //
//                                                                  //
//  Parameters: 1)iPos : It is the actual position of node (starts  //
//                      from 1) given by user to delete the specific// 
//                      node at position                            //
//                                                                  //
//  Description: This function removes (delete) the node            //
//               of linked list at specific position given by user  //
//               and decrements the count of nodes                  //
//                                                                  //
//  Author : Prasad Sarwar                                          //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL <T>:: DeleteAtPos(int ipos)
{
    struct nodeD <T> * temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
	iNodeCnt--;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: void Display()                                   //
//                                                                  //
//  Parameters: --                                                  //
//                                                                  //
//  Description: This function prints the linked list on terminal   //
//                                                                  //
//  Author : Prasad Sarwar                                          //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL <T>:: Display()
{
    struct nodeD <T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked list are : "<<"\n";

    cout<<"<=> ";

    do
    {
        cout<<"| " <<temp->Data<<" | <=> ";
        temp = temp -> next;
    }while(temp != Last->next);

    cout<<"NULL"<<endl;

}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: int CountNodes()                                 //
//                                                                  //
//  Parameters: --                                                  //
//                                                                  //
//  Description: This function returns the number of nodes present  //
//               in Linked list                                     //
//                                                                  //
//  Return Parameter : (int) count of nodes in list                 //
//                                                                  //
//  Author : Prasad Sarwar                                          //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL <T>:: CountNodes()
{
    return iNodeCnt;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: T GetNodeData();                                 //
//                                                                  //
//  Parameters: --                                                  //
//                                                                  //
//  Description: This function returns the Data present in the      //
//             node of linked list; Node(this function should be    //
//             called in loop to get all data of list);             //
//                                                                  //
//  Return Parameter : (T) Data of Node                             //
//                                                                  //
//  Author : Prasad Sarwar                                          //
//                                                                  //
//  Date : 9 Oct 2023                                               //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template<class T>
T DoublyCL<T>:: GetNodeData()
{
    static struct nodeD<T> *Temp = First;

    if(Temp == NULL)
    {
        Temp = First;
        return T();
    }
    else
    {
        T data = Temp->Data;

        Temp = Temp->next;

        if (Temp == First)
            Temp = NULL;
        
        return data;
    }
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: int LinearSearch(T Data)                         //
//                                                                  //
//  Parameters: T Data: Element to be searched                      //
//                                                                  //
//  Description: This function returns the Data present in the      //
//             node of linked list; Node(this function should be    //
//             called in loop to get all data of list);             //
//                                                                  //
//  Return Parameter : (int) position of fetched element; if not    //
//                    found return -1                               //
//                                                                  //
//  Author : Prasad Sarwar                                          //
//                                                                  //
//  Date : 9 Oct 2023                                               //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T>::LinearSearch(T Data)
{
    int iCnt = 0;
    struct nodeD<T> * Temp = First;

    if (Temp == NULL)
    {
        return -1;
    }

    do
    {
        iCnt++;
        if(Temp->Data == Data)
        {
            return iCnt;
        }
        Temp = Temp->next;
    } while(Temp != First);


    return -1;
} 

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DoublyCL<T>::BubbleSort()                   //
//                                                                  //
//  Parameters: None                                                //
//                                                                  //
//  Description:                                                    //
//  This function performs the Bubble Sort algorithm on the doubly  //
//  linked list. If the list is already sorted or empty, it         //
//  returns early. Otherwise, it iteratively compares adjacent      //
//  elements and swaps them if they are in the wrong order, moving  //
//  towards the end of the list in each iteration.                  //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 9 October 2023                                            //
//                                                                  //
//////////////////////////////////////////////////////////////////////


template <class T>
void DoublyCL<T>::BubbleSort()
{
    if (First == NULL || First->next == NULL)
    {
        return;
    }

    bool swapped;
    struct nodeD<T> *current;
    // struct nodeD<T> *Temp = NULL;

    do 
    {
        swapped = false;
        current = First;

        do
        {
            if (current->Data > current->next->Data) 
            {    
                T tData = current->Data;

                current->Data = current->next->Data;
                current->next->Data = tData;

                swapped = true;
            }
            current = current->next;
        }while(current->next != First);

    } while (swapped);
    
} 

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DoublyCL<T>::SelectionSort()                //
//                                                                  //
//  Parameters: None                                                //
//                                                                  //
//  Description:                                                    //
//  This function performs the Selection Sort algorithm on the      //
//  doubly linked list. It iterates through the list, finds the     //
//  minimum element in the unsorted part, and swaps it with the     //
//  current element, thus gradually sorting the list.               //
//                                                                  //
//  Return: void                                                    //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 9 October 2023                                            //
//                                                                  //
//////////////////////////////////////////////////////////////////////


template <class T>
void DoublyCL<T>::SelectionSort() 
{

    if (First == NULL)
    {
        return;
    }

    struct nodeD<T>* current = First;

    do
    {
        struct nodeD<T>* minNode = current;
        struct nodeD<T>* Temp = current->next;

        do
        {
            if (Temp->Data < minNode->Data)
                minNode = Temp;

            Temp = Temp->next;
        }while(Temp != First);

        T tempdata = current->Data;
        current->Data = minNode->Data;
        minNode->Data = tempdata;

        current = current->next;
    }while(current != First->prev);
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DoublyCL<T>::InsertionSort()                //
//                                                                  //
//  Parameters: None                                                //
//                                                                  //
//  Description:                                                    //
//  This function performs the Insertion Sort algorithm on the      //
//  doubly linked list. It iterates through the list, maintaining a //
//  sorted sublist while inserting each element in its correct      //
//  position within the sublist, resulting in a sorted list.        //
//                                                                  //
//  Return: void                                                    //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 9 October 2023                                            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertionSort() 
{
    if (First == NULL)
    {
        return;
    }

    struct nodeD<T>* sorted = NULL;
    struct nodeD<T>* current = First;

    while(current != First->prev)
    {
        struct nodeD<T>* nextNode = current->next;

        if (sorted == NULL || sorted->Data >= current->Data) 
        {
            current->next = sorted;
            current->prev = sorted->prev;
            sorted->prev->next = current;
            sorted->prev = current;
            sorted = current;
        }
        else
        {
            struct nodeD<T>* temp = sorted;

            while (temp->next != First && temp->next->Data < current->Data) 
            {
                temp = temp->next;
            }

                current->next = temp->next;
                current->prev = temp;
                temp->next->prev = current;
                temp->next = current;
        }

        current = nextNode;
    }

    First = sorted;
    // First->prev = sorted->prev;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: T DoublyCL<T>::GetMiddleData()                  //
//                                                                  //
//  Parameters: None                                                //
//                                                                  //
//  Description:                                                    //
//  This function returns the data of the middle element in the     //
//  doubly linked list. If the number of nodes is even, it returns  //
//  the data of the second middle element.                          //
//                                                                  //
//  Return: T - The data of the middle element in the list          //
//                                                                  //
//  Author: Prasad Sarwar                                           //
//                                                                  //
//  Date: 13 October 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////


template <class T>
T DoublyCL<T>::GetMiddleData() 
{

    if (First == NULL)
    {
        return T();
    }
    
    struct nodeD<T> * Temp1 = First;
    struct nodeD<T> * Temp2 = First;

    while(Temp2->next != First && Temp2->next->next != First)
    {
        Temp2 = Temp2->next->next;
        Temp1 = Temp1->next;
    }

    return (Temp1->Data);
}

template <class T>
T DoublyCL<T>::GetFirstData()
{
    return First->Data;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


#endif // DOUBLYCL_CPP
