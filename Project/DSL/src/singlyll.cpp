#ifndef SINGLYLL_CPP
#define SINGLYLL_CPP

#include <lists/singlyll.h>
#include <lists/stack.h>
#include <string.h>
#include <type_traits>

using namespace std;

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Finction name: SinglyLL()  {Default Constructor}                //
//                                                                  //
//  Description: This is simply a default constructor which         //
//               initialises the characteristics of the SinglyLL    //
//               class                                              //
//                                                                  //
//  Author : Prasad Sarwar                                          //
//                                                                  //
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
SinglyLL<T>::SinglyLL()
{
    First = NULL;
    iCount = 0;
}

/////////////////////////////////////////////////////////////////////

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
void SinglyLL<T>::InsertFirst(T no)
{
    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->Data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
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
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL <T>:: InsertLast(T no)
{
    struct nodeS<T> * newn = new struct nodeS<T>;
    struct nodeS<T> * Temp = First;

    newn->Data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
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
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL <T>:: InsertAtPosition(T no, int iPos)
{
    // int iCount = CountNodes();

    struct nodeS<T> * newn = new struct nodeS<T>;
    struct nodeS<T> * Temp = First;

    newn->Data = no;
    newn->next = NULL;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position..."<<endl;
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
        for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
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
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL <T>:: DeleteFirst()
{   
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First; 
        First = NULL;
    }
    else
    {   
        struct nodeS<T> *Temp = First;
        First = First->next;
        delete Temp;
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
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL <T> :: DeleteLast()
{

    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First; 
        First = NULL;
    }
    else
    {
        struct nodeS<T> *Temp = First;

        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        delete (Temp)->next;
        Temp->next = NULL;
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
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL <T> :: DeleteAtPosition(int iPos)
{
	struct nodeS <T> *Temp1 = First;
	struct nodeS <T> *Temp2;

    // int iCount = CountNodes();
	
	if((iPos < 1) || (iPos > iCount + 1))
	{
		cout<<"Invalid position"<<endl;
		return;
	}
	
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iCount + 1)
	{
		DeleteLast();	
	}
	else
	{
		for(int iCnt = 1; iCnt < (iPos-1); iCnt++)
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
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL <T>:: Display()
{
    struct nodeS<T> * Temp = First;

    while(Temp != NULL)
    {
        cout<<"| "<<Temp->Data<<" | -> ";
        Temp = Temp->next;
    }
    cout<<"NULL"<<endl;
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
//  Date : 26 August 2023                                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL <T>::  CountNodes()
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
T SinglyLL<T>:: GetNodeData()
{
    static struct nodeS<T> *Temp = First;

    if(Temp == NULL)
    {
        Temp = First;
        return NULL ;
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
int SinglyLL<T>::LinearSearch(T Data)
{
    int iCnt = 0;
    struct nodeS<T> * Temp = First;

    while(Temp != NULL)
    {
        iCnt++;
        if(Temp->Data == Data)
        {
            break;
        }
        Temp = Temp->next;
    }
    if(iCnt == 0)
    {
        return -1;
    }
    else
    {
        return iCnt;
    }
} 

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void SinglyLL<T>::BubbleSort()                   //
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
void SinglyLL<T>::BubbleSort()
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

        while (Temp->next != NULL) {
            if (Temp->Data > Temp->next->Data) {
                // Swap the data of the nodes without using std::swap
                T tData = Temp->Data;
                Temp->Data = Temp->next->Data;
                Temp->next->Data = tData;

                swapped = true;
            }
            Temp = Temp->next;
        }
    } while (swapped);
    
} 

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void SinglyLL<T>::SelectionSort()                //
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
void SinglyLL<T>::SelectionSort() 
{
    struct nodeS<T>* current = First;

    while (current) {
        struct nodeS<T>* minNode = current;
        struct nodeS<T>* Temp = current->next;

        while (Temp) {
            if (Temp->Data < minNode->Data)
                minNode = Temp;

            Temp = Temp->next;
        }

        T tempdata = current->Data;
        current->Data = minNode->Data;
        minNode->Data = tempdata;

        current = current->next;
    }
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void SinglyLL<T>::InsertionSort()                //
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
void SinglyLL<T>::InsertionSort() 
{
    if (First == NULL || First->next == NULL)
    {
        return;
    }

    struct nodeS<T>* sorted = nullptr;
    struct nodeS<T>* current = First;

    while (current != NULL) 
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
            while (temp->next && temp->next->Data < current->Data) 
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = nextNode;
    }

    First = sorted;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: T SinglyLL<T>::GetMiddleData()                  //
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
T SinglyLL<T>::GetMiddleData() 
{
    struct nodeS<T> *Temp1 = First;
    struct nodeS<T> *Temp2 = First;

    while((Temp2 != NULL) && (Temp2->next != NULL))   // Even & Odd
    {
        Temp2 = Temp2->next->next;
        Temp1 = Temp1->next;
    }

    return (Temp1->Data);
}

template <class T>
T SinglyLL<T>::GetFirstData()
{
    return First->Data;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

#endif