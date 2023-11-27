#ifndef STACK_H
#define STACK_H

#include <lists/singlyll.h>

template <class T>
class Stack
{
    private:
        int iSize;
        int iCount;
        struct nodeS<T> * First;
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

template class Stack<void*>;
template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<char>;
template class Stack<bool>;
template class Stack<std::string>;

//////////////////////////////////////////////////////////////////////



#endif