#ifndef QUEUE_H
#define QUEUE_H

#include <lists/singlyll.h>

template <class T>
class Queue
{
    private:
        int iSize;
        int iCount;
        struct nodeS<T> * First;
    public: 
        Queue(int size);

        void Enqueue(T Data);
        void Dequeue();
        bool CheckFull();
        bool CheckEmpty();

        T GetFront();
        T GetRear();
        int GetCount();

        void DisplayQueue();

};


//////////////////////////////////////////////////////////////////////

template class Queue<void*>;
template class Queue<int>;
template class Queue<float>;
template class Queue<double>;
template class Queue<char>;
template class Queue<bool>;
template class Queue<std::string>;

//////////////////////////////////////////////////////////////////////



#endif