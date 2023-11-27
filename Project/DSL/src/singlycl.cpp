#ifndef SINGLYCL_CPP
#define SINGLYCL_CPP

#include <lists/singlycl.h>
using namespace std;


//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: SinglyCL()  {Default Constructor}                //
//                                                                  //
//  Description: This is simply a default constructor which         //
//               initialises the characteristics of the SinglyCL    //
//               class                                              //
//                                                                  //
//  Author : Prasad Sarwar                                          //
//                                                                  //
//  Date : 25 September 2023                                        //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
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
//  Date : 25 September 2023                                        //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>:: InsertFirst(T no)
{
    struct nodeS <T> * newn = new struct nodeS<T>;
    newn->Data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
    iCount++;
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
//  Date : 26 September 2023                                        //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL <T>:: InsertLast(T no)
{
    struct nodeS <T> * newn = new struct nodeS<T>;
    newn->Data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First =Last = newn;
        (Last)->next = First;
    }
    else
    {
        (Last)->next = newn;
        Last = newn;
        (Last)->next = First;
    }
    iCount++;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: void InsertAtPosition(T no, int iPos)            //
//                                                                  //
//  Parameters: 1) T no : It actual data that is to be inserted in  //
//                        Linked List                               //
//               2) int iPos : It is the actual position (starts    //
//                        from 1) given by user to insert the node  //
//                                                                  //
//  Description: This function adds (inserts) a new node at the     //
//               specific position (iPos) in the linked list and    //
//               increments the count of nodes in linked list       //
//                                                                  //
//  Author : Prasad Sarwar                                          //
//                                                                  //
//  Date : 26 September 2023                                        //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL <T>:: InsertAtPosition(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Position..."<<"\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeS <T> * newn = new struct nodeS<T>;
        newn->Data = no;
        newn->next = NULL;

        struct nodeS <T> * Temp = First;
        int iCnt = 0;

        for (iCnt = 1; iCnt < (iPos-1); iCnt++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn; 
        iCount++;  
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
//  Date : 26 September 2023                                        //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL <T>:: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }

    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        // struct node <T> * Temp = First;

        // First = Temp->next;
        // delete Temp;
        // Last->next = First;

        First = (First)->next;
        delete (Last)->next;
        (Last)->next = First;
    }
    iCount--;
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
//  Date : 26 September 2023                                        //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL <T>:: DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }

    if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeS <T> * Temp = First;

        while (Temp->next != Last)
        {
            Temp = Temp->next;   
        }

        delete Last;
        Last = Temp;
        (Last)->next = First;
    }
    iCount--;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: void DeleteAtPosition(int iPos)                  //
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
//  Date : 26 September 2023                                        //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL <T>:: DeleteAtPosition(int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position..."<<"\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS <T> * Temp1 = First;
        struct nodeS <T> * Temp2 = NULL;
        int iCnt = 0;

        for ( iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            Temp1 = Temp1->next;
        }

        Temp2 = Temp1->next;
        Temp1->next = Temp2->next;
        delete Temp2;
        iCount--;   
    }
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
//  Date : 26 September 2023                                        //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL <T>:: Display()
{
    cout<<"Elements in Linked list are:"<<"\n";

    if((First == NULL) && (Last == NULL))
    {
        cout<<"NULL"<<"\n";
        return;
    }

    do
    {
        cout<<"| "<<First->Data<<" | -> ";
        First = First->next;

    } while (First != Last->next);
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: void CountNodes()                                //
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
//  Date : 26 September 2023                                        //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL <T>:: CountNodes()
{
    return iCount;
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
T SinglyCL<T>:: GetNodeData()
{
    static struct nodeS<T> *Temp = First;

    if(Temp == NULL)
    {
        Temp = First;
        return T();
    }
    else
    {
        T data = Temp->Data;
        Temp = Temp->next;
        
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
int SinglyCL<T>::LinearSearch(T Data)
{
    int iCnt = 0;
    struct nodeS<T> * Temp = First;

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
    }while(Temp != First);

        return -1;
} 

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void SinglyCL<T>::BubbleSort()                   //
//                                                                  //
//  Parameters: None                                                //
//                                                                  //
//  Description:                                                    //
//  This function performs the Bubble Sort algorithm on the singly  //
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
void SinglyCL<T>::BubbleSort()
{
    if (First == NULL || First->next == NULL)
    {
        return; // Already sorted or empty list
    }

    bool swapped;
    struct nodeS<T> *Temp;

    do {
        swapped = false;
        Temp = First;

        do 
        {
            if (Temp->Data > Temp->next->Data) 
            {
                // Swap the data of the nodes without using std::swap
            
                T tData = Temp->Data;
                Temp->Data = Temp->next->Data;
                Temp->next->Data = tData;

                swapped = true;
            }
            Temp = Temp->next;
        }while (Temp->next != First);
    } while (swapped);
    
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void SinglyCL<T>::SelectionSort()                //
//                                                                  //
//  Parameters: None                                                //
//                                                                  //
//  Description:                                                    //
//  This function performs the Selection Sort algorithm on the      //
//  singly linked list. It iterates through the list, finds the     //
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
void SinglyCL<T>::SelectionSort() 
{

     if (First == NULL || First->next == First)
    {
        return;
    }

    struct nodeS<T>* current = First;
     
    do
    {
        struct nodeS<T>* minNode = current;
        struct nodeS<T>* Temp = current->next;

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
    }while(current != First->next);
    
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void SinglyCL<T>::InsertionSort()                //
//                                                                  //
//  Parameters: None                                                //
//                                                                  //
//  Description:                                                    //
//  This function performs the Insertion Sort algorithm on the      //
//  singly linked list. It iterates through the list, maintaining a //
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
void SinglyCL<T>::InsertionSort() 
{
    if (First == NULL || First->next == NULL)
    {
        return;
    }

    struct nodeS<T>* sorted = NULL;
    struct nodeS<T>* current = First;
    struct nodeS<T>* lastSorted = NULL;


    do
    {
        struct nodeS<T>* nextNode = current->next;

        if (sorted == NULL|| sorted->Data >= current->Data) 
        {
            current->next = sorted;
            sorted = current;
        } 
        else 
        {
            struct nodeS<T>* temp = sorted;

            while (temp->next != First && temp->next->Data < current->Data) 
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        if (lastSorted == NULL)
        {
            sorted = current;
        }
        else
        {
            lastSorted->next = current;
        }
        
        lastSorted = current;

        current = nextNode;
    } while(current != First);

    First = sorted;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: T SinglyCL<T>::GetMiddleData()                   //
//                                                                  //
//  Parameters: None                                                //
//                                                                  //
//  Description:                                                    //
//  This function returns the data of the middle element in the     //
//  singly linked list. If the number of nodes is even, it returns  //
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
T SinglyCL<T>::GetMiddleData() 
{

    if (First == NULL)
    {
        return T();
    }

    struct nodeS<T> *Temp1 = First;
    struct nodeS<T> *Temp2 = First;

    do
    {
        if (Temp2->next != First && Temp2->next->next != First)
        {
            Temp2 = Temp2->next->next;
            Temp1 = Temp1->next;
        }
        else
        {
            break;
        }
        
              
    }while(true);

    return (Temp1->Data);
}


template <class T>
T SinglyCL<T>::GetFirstData()
{
    return First->Data;
}

//////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

#endif;