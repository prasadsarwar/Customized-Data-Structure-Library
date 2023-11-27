#ifndef DOUBLYLL_CPP
#define DOUBLYLL_CPP

#include <lists/doublyll.h>
using namespace std;


//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: DoublyLL()  {Default Constructor}                //
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
DoublyLL <T>:: DoublyLL()
{
    First = NULL;
    iCount = 0;
} 

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void InsertFirst(T no)                           //
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
void DoublyLL <T>:: InsertFirst(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>;

    newn->Data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
        iCount++;
    }
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void InsertLast(T no)                            //
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
void DoublyLL <T>:: InsertLast(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>;
    struct nodeD<T> * Temp = First;

    newn->Data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
        newn->prev = Temp;
        iCount++;
    }
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void InsertAtPosition(T no, int iPos)            //
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
void DoublyLL <T>:: InsertAtPosition(T no, int iPos)
{
    // int iCount = CountNodes();

    struct nodeD<T> * newn = new struct nodeD<T>;
    struct nodeD<T> * Temp = First;

    newn->Data = no;
    newn->next = NULL;
    newn->prev = NULL;

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
        Temp->next->prev = newn;
        Temp->next = newn;
        newn->prev = Temp;
        iCount++;
    }
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DeleteFirst()                               //
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
void DoublyLL <T>:: DeleteFirst()
{   
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First; 
        First = NULL;
        iCount--;
    }
    else
    {   
        // struct nodeD<T> *Temp = First;
        First = First->next;
        // delete Temp;
        delete First->prev;
        iCount--;
    }
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DeleteLast()                                //
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
void DoublyLL <T> :: DeleteLast()
{

    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First; 
        First = NULL;
        iCount--;
    }
    else
    {
        struct nodeD<T> *Temp = First;

        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        delete (Temp)->next;
        Temp->next = NULL;
        iCount--;
    }
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DeleteAtPosition(int iPos)                  //
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
void DoublyLL <T> :: DeleteAtPosition(int iPos)
{
	struct nodeD <T> *Temp1 = First;
	struct nodeD <T> *Temp2;

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
        Temp2->prev = Temp1;
		delete Temp2;
        iCount--;
	}
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void Display()                                   //
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
void DoublyLL <T>:: Display()
{
    struct nodeD<T> * Temp = First;
  
    cout<<"NULL <=> ";

    while(Temp != NULL)
    {
        cout<<"| "<<Temp->Data<<" | <=> ";
        Temp = Temp->next;
    }
    cout<<"NULL"<<endl;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: int CountNodes()                                //
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
int DoublyLL <T>:: CountNodes()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: T GetNodeData();                                 //
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
T DoublyLL<T>:: GetNodeData()
{
    static struct nodeD<T> * Temp = First;

    if (Temp == NULL)
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
//  Function name: int LinearSearch(T Data)                         //
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
int DoublyLL<T>::LinearSearch(T Data)
{
    int iCnt = 0;
    struct nodeD<T> *Temp = First;
    int FoundAtPos = -1;

    while (Temp != NULL)
    {
        iCnt++;
        if (Temp->Data == Data)
        {
            FoundAtPos = iCnt;
            break;
        }
        Temp = Temp->next;
    }

    return FoundAtPos;
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DoublyLL<T>::BubbleSort()                   //
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
void DoublyLL<T>::BubbleSort()
{
    if (First == NULL || First->next == NULL)
    {
        return;
    }

    bool swapped;
    struct nodeD<T> *Temp;

    do 
    {
        swapped = false;
        Temp = First;

        while (Temp->next != NULL)
        {
            if (Temp->Data > Temp->next->Data) 
            {
                T tData = Temp->Data;
                Temp->Data = Temp->next->Data;
                Temp->next->Data = tData;

                swapped = true;
            }
            Temp = Temp->next;
        }
    }while (swapped);
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DoublyLL<T>::SelectionSort()                //
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
void DoublyLL<T>::SelectionSort()
{
    struct nodeD<T> * current = First;

    while (current != NULL) 
    {
        struct nodeD<T> * minNode = current;
        struct nodeD<T> * Temp = current->next;

        while (Temp != NULL) 
        {
            if (Temp->Data < minNode->Data)
                minNode = Temp;

            Temp = Temp->next;
        }

        T tempData = current->Data;
        current->Data = minNode->Data;
        minNode->Data = tempData;

        current = current->next;
    }
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: void DoublyLL<T>::InsertionSort()                //
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
void DoublyLL<T>::InsertionSort() 
{
    if (First == NULL || First->next == NULL)
    {
        return;
    }

    struct nodeD<T> * sorted = NULL;
    struct nodeD<T> * current = First;

    while (current != NULL) 
    {
        struct nodeD<T> * nextNode = current->next;

        if (sorted == NULL || sorted->Data >= current->Data) 
        {
            current->next = sorted;
            current->prev = NULL; // Adjust the previous pointer
            if (sorted != NULL)
                sorted->prev = current;
            sorted = current;
        } 
        else 
        {
            struct nodeD<T> * temp = sorted;
            while (temp->next && temp->next->Data < current->Data) 
            {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = current;
            temp->next = current;
            current->prev = temp; // Adjust the previous pointer
        }

        current = nextNode;
    }

    First = sorted;
    First->prev = NULL; // Ensure the previous pointer of the new first node is Null
}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Function name: T DoublyLL<T>::GetMiddleData()                  //
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
T DoublyLL<T>::GetMiddleData() 
{
    if (First == NULL) 
    {
        return T();
    }

     struct nodeD<T>* Temp1 = First;
     struct nodeD<T>* Temp2 = First;

    while (Temp2 != NULL && Temp2->next != NULL) 
    {
        Temp2 = Temp2->next->next;
        Temp1 = Temp1->next;
    }

    return (Temp1->Data);
}


template <class T>
T DoublyLL<T>::GetFirstData()
{
    return First->Data;
}


////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

#endif // DOUBLYLL_CPP
