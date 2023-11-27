#ifndef QUEUE_CPP
#define QUEUE_CPP

#include <lists/queue.h>
#include <lists/singlyll.h>
#include <lists/node.h>
using namespace std;


template <class T>
Queue<T>::Queue(int size)
{
    iSize = size;
    First = NULL;
    iCount = 0;
}

//////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Enqueue(T Data)
{
    if(iCount == iSize)
    {
        cout<<"Queue is full !!!"<<endl;
        return;
    }

    struct nodeS<T> * newn = new struct nodeS<T>;
    struct nodeS<T> * Temp = First;

    newn->Data = Data;
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

template <class T>
void Queue<T>::Dequeue()
{
    if(iCount <= 0)
    {
        cout<<"Queue is empty !!!"<<endl;
    }
    else
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

} 

//////////////////////////////////////////////////////////////////////

template <class T>
bool Queue<T>::CheckEmpty()
{
    if(iCount <= 0)
    {
        cout<<"Queue is empty !!!"<<endl;
        return true;
    }
    else
    {
        return false;
    }
} 

//////////////////////////////////////////////////////////////////////

template <class T>
bool Queue<T>::CheckFull()
{
    if(iCount == iSize)
    {
        cout<<"Queue is Full !!!"<<endl;
        return true;
    }
    else
    {
        return false;
    }
} 

//////////////////////////////////////////////////////////////////////

template <class T>
T Queue<T>::GetFront()
{
    return (First->Data);
}

//////////////////////////////////////////////////////////////////////

template <class T>
T Queue<T>::GetRear()
{
    return (First->Data);
}

//////////////////////////////////////////////////////////////////////
template <class T>
int Queue<T>::GetCount()
{
    return iCount;
}
//////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::DisplayQueue()
{
    struct nodeS<T> * Temp = First;
    int iCnt = 1;

    while(Temp != NULL)
    {
        cout<<"| "<<Temp->Data<<" |";
        if(iCnt == 1)
        {
            cout<<"  <- Front";
        }
        else if(Temp->next == NULL)
        {
            cout<<" <- Rear";
        }
        cout<<endl;
        iCnt++;
        Temp = Temp->next;
    }
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////



#endif