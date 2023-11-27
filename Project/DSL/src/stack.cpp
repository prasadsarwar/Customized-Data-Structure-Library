#ifndef STACK_CPP
#define STACK_CPP

#include <lists/stack.h>
#include <lists/singlyll.h>
#include <lists/node.h>
using namespace std;


template <class T>
Stack<T>::Stack(int size)
{
    iSize = size;
    First = NULL;
    iCount = 0;
}

//////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Push(T Data)
{
    if(iCount == iSize)
    {
        cout<<"Stack is full !!!"<<endl;
        return;
    }

    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->Data = Data;
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

template <class T>
void Stack<T>::Pop()
{
    if(iCount <= 0)
    {
        cout<<"Stack is empty !!!"<<endl;
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
bool Stack<T>::CheckEmpty()
{
    if(iCount <= 0)
    {
        cout<<"Stack is empty !!!"<<endl;
        return true;
    }
    else
    {
        return false;
    }
} 

//////////////////////////////////////////////////////////////////////

template <class T>
bool Stack<T>::CheckFull()
{
    if(iCount == iSize)
    {
        cout<<"Stack is Full !!!"<<endl;
        return true;
    }
    else
    {
        return false;
    }
} 

//////////////////////////////////////////////////////////////////////

template <class T>
T Stack<T>::GetTop()
{
    return (First->Data);
}

//////////////////////////////////////////////////////////////////////
template <class T>
int Stack<T>::GetCount()
{
    return iCount;
}
//////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::DisplayStack()
{
    struct nodeS<T> * Temp = First;
    int iCnt = 1;

    while(Temp != NULL)
    {
        cout<<"| "<<Temp->Data<<" |";
        if(iCnt == 1)
        {
            cout<<"  <- Top";
        }
        cout<<endl;
        iCnt++;
        Temp = Temp->next;
    }
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////



#endif