Library Documentation :

What’s the Library include !!
The Generalized Data Structures Library  aims to provide a comprehensive collection of generic implementations of various types of data structures, both linear and nonlinear, in a way that address to object-oriented design principles.
 The primary goal is to create a reusable and versatile library that enables users to seamlessly work with different data types while enjoying a consistent interface. 
These libraries typically provide generic templates or classes that can be instantiated with the desired data type, making it easier to maintain the code.

How to Install Library package  ?
For linux or Mac :
1.	Update package list:
sudo apt-get update
2.	Install make 
sudo apt-get install make
Clone git repository
git clone https://github.com/prasadsarwar/Customized-Data-Structure-Library

sudo apt-get install make
Clone git repository
git clone https://github.com/prasadsarwar/Customized-Data-Structure-Library


3.	Run make file from the linux directory 
Make
OR
4.	Copy header from /DSL/include/* to standard location /usr/local/include
sudo cp -r DSL/include/lists /usr/local/include/

AND 
5.	Copy library from /DSL/lib/so (dylib for mac-os) to standard location /usr/local/lib
sudo cp DSL/lib/so/libgenlists.so /usr/local/lib/
6.	Update linker
sudo ldconfig

Now the library is intsalled system-wide on your system. You can use it by including header file for example:
#include<lists/tree.h>

And
Compiling the program by adding a flag -lgenlists for example:
g++ client.cpp -o Myexe -lgenlists
And Run the exe file
./Myexe


Windows:

1.	Install make 
http://www.gnu.org/software/make

              Clone git repository
               git clone https://github.com/prasadsarwar/Customized-Data-Structure-Library

2.	Run make file from the win directory 
Make
OR
3.	Copy header from \DSL\include\* to standard location \Mingw\include
copy -r DSL\include\lists \Mingw\include

AND 
4.	Copy library from \DSL\lib\so (dylib for mac-os) to standard location \Windows\System32
copy DSL\lib\so\libgenlists.so \Windows\System32
OR we can do it by adding library path i.e \DSL\lib\dll to System environmental varible (PATH)

Now the library is intsalled system-wide on your system. You can use it by including header file for example:
#include<lists\tree.h>

And
Compiling the program by adding a flag -lgenlists for example:
g++ client.cpp -o Myexe -lgenlists
And Run the exe file
Myexe









Classes which are used in the Library 
1.SinglyLL                                           
 Description: This class consists of members which are used to   
                        Manupulate and perform various operations on       
                        Singly Linear Linked List.

 2.SinglyCL                                            
 Description: This class consists of members which are used to   
                       Manupulate and perform various operations on       
                       Singly Circular Linked List
	
 3.DoublyLL                                           
 Description: This class consists of members which are used to   
                        Manupulate and perform various operations on       
                        Doubly Linear Linked List.

 4.DoublyCL                                            
 Description: This class consists of members which are used to   
                       Manupulate and perform various operations on       
                       Doubly Circular Linked List.


   5.BTree                                               
    Description: This class represents a Binary Tree data structure 
                      and provides various operations for manipulating   
                       and managing the tree, including insertion,       
                       deletion, traversal, and counting operations.



Library Functions :
Common Functions in all Linked List :

1.	InsertFirst(T no);
Function prototype                                                                                             
void SinglyLL<T>::InsertFirst(T no);

Function Description: This function inserts a new element of type T at the beginning of a singly linked list.

Code Snipiet 
struct nodeS<T> * newn = new struct nodeS<T>;
newn->Data = no;
newn->next = NULL;
if (First == NULL)
{
    First = newn;
}
else
{
    newn->next = First;
    First = newn;
}
iCount++;

Function Flow:
1.	A new node (newn) is created with the provided data (no) and a NULL next pointer.
2.	If the linked list is empty (First == NULL), the new node becomes the first node in the list.
3.	If the linked list is not empty, the new node is linked to the current first node, and then it becomes the new first node.
4.	The node count (iCount) is incremented.

Example Usage:
SinglyLL<int> myList; // Assuming the list is of type int
myList.InsertFirst(42);
myList.InsertFirst(30);
myList.InsertFirst(15);

// The linked list now contains: 15 -> 30 -> 42


2.  InsertLast(T no);                                                     
Function prototype :
void SinglyLL<T>::InsertLast(T no);

Function Description: This function inserts a new element of type T at the end of a singly linked list.

Code Snipet :
struct nodeS<T> * newn = new struct nodeS<T>;
struct nodeS<T> * Temp = First;
newn->Data = no;
newn->next = NULL;
if (First == NULL)
{
    First = newn;
}
else
{
    while (Temp->next != NULL)
    {
        Temp = Temp->next;
    }
    Temp->next = newn;
}iCount++;
Function Flow:
1.	A new node (newn) is created with the provided data (no) and a NULL next pointer.
2.	If the linked list is empty (First == NULL), the new node becomes the first node in the list.
3.	If the linked list is not empty, a temporary pointer (Temp) is used to traverse the list to its end.
4.	The new node is then linked to the last node in the list.
5.	The node count (iCount) is incremented.

Usage Exapmple :
SinglyLL<int> myList; // Assuming the list is of type int
myList.InsertLast(42);
myList.InsertLast(30);
myList.InsertLast(15);
      

    3) void InsertAtPos(T no, int ipos)
    Function Prototype :
    void SinglyLL<T>::InsertAtPosition(T no, int iPos);
   Function Description :
         - a new element of type T at a specified position in the data 
           structure.    

      Code Snipet :
// int iCount = CountNodes();
struct nodeS<T> * newn = new struct nodeS<T>;
struct nodeS<T> * Temp = First;
newn->Data = no;
newn->next = NULL;
if ((iPos < 1) || (iPos > iCount + 1))
{
    cout << "Invalid position..." << endl;
    return;
}
if (iPos == 1)
{
    InsertFirst(no);
}
else if (iPos == iCount + 1)
{
    InsertLast(no);
}
else
{
    for (int iCnt = 1; iCnt < (iPos - 1); iCnt++)
    {
        Temp = Temp->next;
    }
    newn->next = Temp->next;
    Temp->next = newn;
    iCount++;
}

Function Flow:
1.	A new node (newn) is created with the provided data (no) and a NULL next pointer.
2.	If the specified position is invalid (less than 1 or greater than the count of nodes + 1), an error message is displayed.
3.	If the position is 1, the function calls InsertFirst to insert the new node at the beginning.
4.	If the position is the count of nodes + 1, the function calls InsertLast to insert the new node at the end.
5.	Otherwise, the function iterates through the list to the position before the specified position and inserts the new node in between the nodes.
6.	The node count (iCount) is updated.
Usage Example :
SinglyLL<int> myList; // Assuming the list is of type int
myList.InsertLast(42);
myList.InsertLast(30);
myList.InsertLast(15);
myList.InsertAtPosition(25, 2);
// The linked list now contains: 42 -> 25 -> 30 -> 15



      4) void DeleteFirst()
       Function Prototype :
       void SinglyLL<T>::DeleteFirst();

Function Description:
This function deletes the first element in a singly linked list.

Code Snippet:
if (First == NULL)
{
    return;
}
else if (First->next == NULL)
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

Function Flow:
1.If the linked list is empty (First == NULL), the function does nothing and returns.
2.If there is only one element in the linked list, it is deleted, and the First pointer is set to NULL.
3.If there is more than one element, a temporary pointer (Temp) is used to hold the first node, the First pointer is updated to the next node, and the original first node is deleted.
4.The node count (iCount) is decremented.

Usage Example:
SinglyLL<int> myList; // Assuming the list is of type int
myList.InsertLast(42);
myList.InsertLast(30);
myList.InsertLast(15);
myList.DeleteFirst();
// The linked list now contains: 30 -> 15
       

      5) void DeleteLast()
Function Prototype :
void SinglyLL<T>::DeleteLast();

  Function Description :
      - Removes the Last element from the data structure.

 Code Snipet :
if (First == NULL)
{
    return;
}
else if (First->next == NULL)
{
    delete First;
    First = NULL;
}
else
{
    struct nodeS<T> *Temp = First;

    while (Temp->next->next != NULL)
    {
        Temp = Temp->next;
    }
    delete (Temp)->next;
    Temp->next = NULL;
}
iCount--;

Function Flow:
1.	If the linked list is empty (First == NULL), the function does nothing and returns.
2.	If there is only one element in the linked list, it is deleted, and the First pointer is set to NULL.
3.	If there is more than one element, a temporary pointer (Temp) is used to traverse the list to the second-to-last node.
4.	The last node is deleted, and the next pointer of the second-to-last node is set to NULL.
5.	The node count (iCount) is decremented.

Usage Example :
SinglyLL<int> myList; // Assuming the list is of type int
myList.InsertLast(42);
myList.InsertLast(30);
myList.InsertLast(15);
myList.DeleteLast();
// The linked list now contains: 42 -> 30


      6) void DeleteAtPos(int ipos)

  Function Prototype :
void SinglyLL<T>::DeleteAtPosition(int iPos);
 
function Description :
 - Removes the element at the specified position in the data structure.
   Parameters: ipos - The position of the element to be deleted.

 Code Snipet :
struct nodeS<T> *Temp1 = First;
struct nodeS<T> *Temp2;
// int iCount = CountNodes();
if ((iPos < 1) || (iPos > iCount + 1))
{
    cout << "Invalid position" << endl;
    return;
}

if (iPos == 1)
{
    DeleteFirst();
}
else if (iPos == iCount + 1)
{
    DeleteLast();
}
else
{
    for (int iCnt = 1; iCnt < (iPos - 1); iCnt++)
    {
        Temp1 = Temp1->next;
    }
    Temp2 = Temp1->next;
    Temp1->next = Temp2->next;
    delete Temp2;
    iCount--;
}

Function Flow:
1.	If the specified position is invalid (less than 1 or greater than the count of nodes + 1), an error message is displayed.
2.	If the position is 1, the function calls DeleteFirst to delete the first element.
3.	If the position is the count of nodes + 1, the function calls DeleteLast to delete the last element.
4.	Otherwise, the function iterates through the list to the position before the specified position and deletes the node at the specified position.
5.	The node count (iCount) is decremented

Usage Example :
SinglyLL<int> myList; // Assuming the list is of type int
myList.InsertLast(42);
myList.InsertLast(30);
myList.InsertLast(15);
myList.DeleteAtPosition(2);
// The linked list now contains: 42 -> 15

      7)  void Display()
      Function Prototype :
    void SinglyLL<T>::Display();

       Function Description :
       - Displays the elements of the data structure.
      
     Code snipet :
    struct nodeS<T> *Temp = First;
      while (Temp != NULL)
  {
    cout << "| " << Temp->Data << " | -> ";
    Temp = Temp->next;
}
cout << "NULL" << endl;

Usage Example :
SinglyLL<int> myList; // Assuming the list is of type int
myList.InsertLast(42);
myList.InsertLast(30);
myList.InsertLast(15);
myList.Display();
// Output: | 42 | -> | 30 | -> | 15 | -> NULL

  8) int CountNodes()
Function Prototype :
int SinglyLL<T>::CountNodes();
Function Description :
      - Returns the count of nodes (elements) in the data structure.
Code Snipet :
return iCount;

Function Flow:
•	The function simply returns the value of the private member variable iCount, which represents the count of nodes in the linked list.

Usage example :
SinglyLL<int> myList; // Assuming the list is of type int
myList.InsertLast(42);
myList.InsertLast(30);
myList.InsertLast(15);
int nodeCount = myList.CountNodes();
// nodeCount now holds the value 3

     9)  T GetNodeData()
Function Prototype :
T SinglyLL<T>::GetNodeData();
Function Description :
  - Returns the data of the current node (element) in the data structure.
Code Snipet :
static struct nodeS<T> *Temp = First;
if (Temp == NULL)
{
    Temp = First;
    return NULL;
}
else
{
    T data = Temp->Data;
    Temp = Temp->next;
    return data;
}

Function Flow:
1.	A static temporary pointer (Temp) is used to keep track of the current position in the linked list.
2.	If Temp is NULL, it is reset to the beginning of the list (First) and NULL is returned.
3.	Otherwise, the data of the current node is stored in a variable (data), and Temp is moved to the next node.
4.	The stored data is then returned.

Example usage :
SinglyLL<int> myList; // Assuming the list is of type int
myList.InsertLast(42);
myList.InsertLast(30);
myList.InsertLast(15);
int data1 = myList.GetNodeData(); // Retrieves 42
int data2 = myList.GetNodeData(); // Retrieves 30
int data3 = myList.GetNodeData(); // Retrieves 15
int data4 = myList.GetNodeData(); // Retrieves NULL (if the list is exhausted)


     10)  void BubbleSort()
Function Prototype :
void SinglyLL<T>::BubbleSort();
Function Description :
 - Sorts the elements in the data structure using the Bubble Sort    algorithm.

Code Snipet :
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
Function Flow:
1.	The function checks if the list is empty or contains only one element. If so, it's considered already sorted, and the function returns.
2.	A loop is used to iterate through the list repeatedly until no swaps are performed during an iteration, indicating that the list is fully sorted.
3.	Within each iteration, another loop traverses the list and compares adjacent elements. If they are out of order, their data is swapped.
4.	The process continues until no more swaps are needed, indicating that the list is sorted.

Usage Example :
SinglyLL<int> myList; // Assuming the list is of type intmyList.InsertLast(42);
myList.InsertLast(30);
myList.InsertLast(15);
myList.BubbleSort();
// The linked list is now sorted: 15 -> 30 -> 42


 11) void SelectionSort()
Function Prototype :
void SinglyLL<T>::SelectionSort();
Function Description :
-	Sorts the elements in the data structure using the Selection Sort algorithm.

Code Snipet :
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
Function Flow:
1.	The function uses two nested loops. The outer loop iterates through each node in the list.
2.	Within each iteration of the outer loop, the function finds the minimum value node (minNode) in the unsorted part of the list by iterating through the remaining nodes with the inner loop.
3.	The data of the current node and the minimum value node are then swapped.
4.	The outer loop continues until the entire list is sorted.


Example Usage :
SinglyLL<int> myList; // Assuming the list is of type int
myList.InsertLast(42);
myList.InsertLast(30);
myList.InsertLast(15);
myList.SelectionSort();
// The linked list is now sorted: 15 -> 30 -> 42

     12) void InsertionSort()
     Function Prototype :
void SinglyLL<T>::InsertionSort();
    Function Description :
-	Sorts the elements in the data structure using the Insertion Sort algorithm.

Code snipet :
   if (First == NULL || First->next == NULL)
{
    return;
}
struct nodeS<T>* sorted = nullptr;
struct nodeS<T>* current = First;
while (current != NULL) 
{
    struct nodeS<T>* nextNode = current->next;
    if (sorted == NULL || sorted->Data >= current->Data) 
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

Function Flow:
1.	The function checks if the list is empty or contains only one element. If so, it's considered already sorted, and the function returns.
2.	Two pointers, sorted and current, are used to keep track of the sorted and unsorted portions of the list, respectively.
3.	The function iterates through each node in the unsorted portion of the list:
•	If the sorted list is empty or the data of the current node is less than or equal to the data of the first node in the sorted list, the current node is inserted at the beginning of the sorted list.
•	Otherwise, the function finds the appropriate position for the current node in the sorted list by iterating through it and inserts the node at that position.
4.	The First pointer is updated to point to the head of the sorted list.

Example Usage :
SinglyLL<int> myList; // Assuming the list is of type int
myList.InsertLast(42);
myList.InsertLast(30);
myList.InsertLast(15);
myList.InsertionSort();
// The linked list is now sorted: 15 -> 30 -> 42

        //Searching algorithms:

13) int LinearSearch(T Data)
Function Prototype :
int SinglyLL<T>::LinearSearch(T Data);
Function Description :
-	Performs a linear search for a given data element in the data structure.
-	Parameters: Data - The data element to be searched.
-	Returns: The index of the found element or -1 if not found.

Code Snipet :
int iCnt = 0;
struct nodeS<T> *Temp = First;
while (Temp != NULL)
{
    iCnt++;
    if (Temp->Data == Data)
    {
        break;
    }
    Temp = Temp->next;
}
if (iCnt == 0)
{
    return -1;
}
else
{
    return iCnt;
}

Function Flow:
1.	The function initializes a counter (iCnt) to 0 and a temporary pointer (Temp) to the first node of the list.
2.	It then iterates through the list:
•	Incrementing the counter.
•	Checking if the data of the current node matches the target data.
•	If a match is found, the loop breaks.
3.	If the counter is 0, indicating that the list is empty, the function returns -1.
4.	Otherwise, it returns the position (index) where the target data was found in the list


Usage Example :
SinglyLL<int> myList; // Assuming the list is of type int
myList.InsertLast(42);
myList.InsertLast(30);
myList.InsertLast(15);
int position = myList.LinearSearch(30);
// position now holds the value 2 (index of 30 in the list)







Stack Functions :
1. Push(T Data)
Function Prototype :
     template <class T>
void Stack<T>::Push(T Data);

 Function Description :
This function adds an element to the top of a stack.

 Code Snipet :
if (iCount == iSize)
{
    cout << "Stack is full !!!" << endl;
    return;
}
struct nodeS<T> *newn = new struct nodeS<T>;
newn->Data = Data;
newn->next = NULL;
if (First == NULL)
{
    First = newn;
}
else
{
    newn->next = First;
    First = newn;
}
iCount++;

Function Flow:
1.	The function checks if the stack is already full (i.e., the current count of elements iCount is equal to the specified size iSize).
2.	If the stack is full, an error message is displayed, and the function returns.
3.	If the stack is not full, a new node (newn) is created with the provided data (Data) and a NULL next pointer.
4.	If the stack is empty (First == NULL), the new node becomes the first node in the stack.
5.	If the stack is not empty, the new node is linked to the current first node, and then it becomes the new first node.
6.	The count of elements in the stack (iCount) is incremented.

Usage Example :
Stack<int> myStack(5); // Assuming the stack has a maximum size of 5
myStack.Push(10);
myStack.Push(20);
myStack.Push(30);
// The stack now contains: 30 -> 20 -> 10

2.	Pop() 


Function Prototype :
template <class T>
void Stack<T>::Pop();

Function Description :
This function removes the top element from a stack
 
     Code Snipet:
   if (iCount <= 0)
{
    cout << "Stack is empty !!!" << endl;
}
else
{
    if (First == NULL)
    {
        return;
    }
    else if (First->next == NULL)
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

Function Flow:
1.	The function checks if the stack is empty (i.e., the current count of elements iCount is less than or equal to 0).
2.	If the stack is empty, an error message is displayed, and the function returns.
3.	If the stack is not empty, it checks different scenarios:
•	If the stack has only one element, that element is deleted, and the First pointer is set to NULL.
•	If the stack has more than one element, a temporary pointer (Temp) is used to hold the first node, the First pointer is updated to the next node, and the original first node is deleted.
4.	The count of elements in the stack (iCount) is decremented

Usage Example :

Stack<int> myStack;
myStack.Push(10);
myStack.Push(20);
myStack.Push(30);

myStack.Pop();
// The stack now contains: 20 -> 10

3.	CheckEmpty();

Function prototype :

template <class T>
   bool Stack<T>::CheckEmpty();

Function Description: This function checks if a stack is empty.
Code Snipet :
if (iCount <= 0)
{
    cout << "Stack is empty !!!" << endl;
    return true;
}
else
{
    return false;
}
Function Flow:
1.	The function checks if the count of elements in the stack (iCount) is less than or equal to 0.
2.	If the stack is empty, an error message is displayed, and the function returns true.
3.	If the stack is not empty, the function returns false

Usage Example :
Stack<int> myStack;
bool isEmpty = myStack.CheckEmpty(); // This will print "Stack is empty !!!" and return true
myStack.Push(10);
myStack.Push(20);
isEmpty = myStack.CheckEmpty(); // This will not print an error message and return false

4.CheckFull():
Function Prototype :
template <class T>
bool Stack<T>::CheckFull();

Function Description: This function checks if a stack is full.
Code Snipet :
if (iCount == iSize)
{
    cout << "Stack is Full !!!" << endl;
    return true;
}
else
{
    return false;
}
Function Flow:
1.	The function checks if the count of elements in the stack (iCount) is equal to the specified maximum size of the stack (iSize).
2.	If the stack is full, an error message is displayed, and the function returns true.
3.	If the stack is not full, the function returns false.

Usage Example:
Stack<int> myStack(2); // Assuming the stack has a maximum size of 2
bool isFull = myStack.CheckFull(); // This will not print an error message and return false
myStack.Push(10);
myStack.Push(20);
isFull = myStack.CheckFull(); // This will print "Stack is Full !!!" and return true


5.DisplayStack():
Function prototype :
template <class T>
void Stack<T>::DisplayStack();

Function Description: This function displays the elements of a stack along with an indication of the top of the stack.
Code snipet :
struct nodeS<T> *Temp = First;
int iCnt = 1;

while (Temp != NULL)
{
    cout << "| " << Temp->Data << " |";
    if (iCnt == 1)
    {
        cout << "  <- Top";
    }
    cout << endl;
    iCnt++;
    Temp = Temp->next;
}
Function Flow:
1.	A temporary pointer (Temp) is initialized to the first node of the stack, and a counter (iCnt) is initialized to 1.
2.	A loop iterates through the stack, printing the data of each node and indicating the top of the stack if it's the first node.
3.	The loop continues until the end of the stack is reached.

Usage Example :
Stack<int> myStack;
myStack.Push(10);
myStack.Push(20);
myStack.Push(30);
myStack.DisplayStack();



Queue Functions :
1. Enqueue(T Data)
Function Prototype :
template <class T>
void Queue<T>::Enqueue(T Data);

Function Description: This function adds an element to the back of a queue.
Code Snipet :
if (iCount == iSize)
{
    cout << "Queue is full !!!" << endl;
    return;
}
tempData = Data;
struct nodeS<T> *newn = new struct nodeS<T>;
struct nodeS<T> *Temp = First;

newn->Data = Data;
newn->next = NULL;

if (First == NULL)
{
    First = newn;
}
else
{
    while (Temp->next != NULL)
    {
        Temp = Temp->next;
    }
    Temp->next = newn;
}
iCount++;

Function Flow:
1.	The function checks if the queue is already full (i.e., the current count of elements iCount is equal to the specified size iSize).
2.	If the queue is full, an error message is displayed, and the function returns.
3.	If the queue is not full, a new node (newn) is created with the provided data (Data) and a NULL next pointer.
4.	If the queue is empty (First == NULL), the new node becomes the first node in the queue.
5.	If the queue is not empty, the new node is linked to the last node in the queue.
6.	The count of elements in the queue (iCount) is incremented.
Usage Example :
Queue<int> myQueue(3); // Assuming the queue has a maximum size of 3
myQueue.Enqueue(10);
myQueue.Enqueue(20);
myQueue.Enqueue(30);
// The queue now contains: 10 -> 20 -> 30

2. Dequeue();
Function Prototype :
template <class T>
void Queue<T>::Dequeue();

Function Description: This function removes the front element from a queue.
Code snipet :
if (iCount <= 0)
{
    cout << "Queue is empty !!!" << endl;
}
else
{
    if (First == NULL)
    {
        return;
    }
    else if (First->next == NULL)
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
Function Flow:
1.	The function checks if the queue is empty (i.e., the current count of elements iCount is less than or equal to 0).
2.	If the queue is empty, an error message is displayed, and the function returns.
3.	If the queue is not empty, it checks different scenarios:
•	If the queue has only one element, that element is deleted, and the First pointer is set to NULL.
•	If the queue has more than one element, a temporary pointer (Temp) is used to hold the first node, the First pointer is updated to the next node, and the original first node is deleted.
4.	The count of elements in the queue (iCount) is decremented.

Usage Example :
Queue<int> myQueue;
myQueue.Enqueue(10);
myQueue.Enqueue(20);
myQueue.Enqueue(30);

myQueue.Dequeue();

// The queue now contains: 20 -> 30

3. CheckEmpty()
Function prototype :
template <class T>
bool Queue<T>::CheckEmpty();

Function Description: This function checks if a queue is empty.
Code snipet :
if (iCount <= 0)
{
    cout << "Queue is empty !!!" << endl;
    return true;
}
else
{
    return false;
}

Function Flow:
1.	The function checks if the count of elements in the queue (iCount) is less than or equal to 0.
2.	If the queue is empty, an error message is displayed, and the function returns true.
3.	If the queue is not empty, the function returns false.

Usage Example :
Queue<int> myQueue;
bool isEmpty = myQueue.CheckEmpty(); // This will print "Queue is empty !!!" and return true
myQueue.Enqueue(10);
myQueue.Enqueue(20);

isEmpty = myQueue.CheckEmpty(); // This will not print an error message and return false


4. CheckFull()
Function Prototype :
template <class T>
bool Queue<T>::CheckFull();

Function Description: This function checks if a queue is full.
Code snipet :
if (iCount == iSize)
{
    cout << "Queue is Full !!!" << endl;
    return true;
}
else
{
    return false;
}

Function Flow:
1.	The function checks if the count of elements in the queue (iCount) is equal to the specified maximum size of the queue (iSize).
2.	If the queue is full, an error message is displayed, and the function returns true.
3.	If the queue is not full, the function returns false.

Usage Example :
Queue<int> myQueue(2); // Assuming the queue has a maximum size of 2
bool isFull = myQueue.CheckFull(); // This will not print an error message and return false
myQueue.Enqueue(10);
myQueue.Enqueue(20);
isFull = myQueue.CheckFull(); // This will print "Queue is Full !!!" and return true


5. GetFront();

Function Prototype :
template <class T>
T Queue<T>::GetFront();

Function Description: This function returns the data of the front element in a queue without removing it.

Code snipet:
return (First->Data);

Function Flow:
1.	The function directly returns the data of the first node in the queue (First).

Usage Example :
Queue<int> myQueue;
myQueue.Enqueue(10);
myQueue.Enqueue(20);
int frontData = myQueue.GetFront(); // frontData now holds the value 10


6. GetRear()

Function prototype :
template <class T>
T Queue<T>::GetRear();

Function Description: This function returns the data of the rear element in a queue without removing it.
Code snipet :
return (tempData);

Function Flow:
1.	The function directly returns the value stored in the tempData variable. This variable is typically updated during the Enqueue operation to hold the data of the last enqueued element.

Usage example :
Queue<int> myQueue;
myQueue.Enqueue(10);
myQueue.Enqueue(20);

int rearData = myQueue.GetRear(); // rearData now holds the value 20



7.	GetCount()
Function Prototype :

template <class T>
int Queue<T>::GetCount();

Function Description: This function returns the count of elements in a queue.
Code snipet:
return iCount;
Function Flow:
1.	The function directly returns the count of elements in the queue (iCount).

Usage Example :
Queue<int> myQueue;
myQueue.Enqueue(10);
myQueue.Enqueue(20);

int count = myQueue.GetCount(); // count now holds the value 2


8. DisplayQueue()
Function prototype :
template <class T>
void Queue<T>::DisplayQueue();

Function Description: This function displays the elements of a queue along with indications for the front and rear elements.

Code snipet:
struct nodeS<T> *Temp = First;
int iCnt = 1;

while (Temp != NULL)
{
    cout << "| " << Temp->Data << " |";
    if (iCnt == 1)
    {
        cout << "  <- Front";
    }
    else if (Temp->next == NULL)
    {
        cout << " <- Rear";
    }
    cout << endl;
    iCnt++;
    Temp = Temp->next;
}



Function Flow:
1.	A temporary pointer (Temp) is initialized to the first node of the queue, and a counter (iCnt) is initialized to 1.
2.	A loop iterates through the queue, printing the data of each node and indicating the front and rear elements based on the counter and the next pointer of the current node.
3.	The loop continues until the end of the queue is reached.

Usage Example :
Queue<int> myQueue;
myQueue.Enqueue(10);
myQueue.Enqueue(20);
myQueue.Enqueue(30);
myQueue.DisplayQueue();



Tree Functions :

1. Insert(T Data)
Function Prototype :
template <class T>
void BTree<T>::Insert(T Data);

Function Description: This function inserts a new node with the given data into a binary tree.
Code snipet:
struct treenode<T> *newn = new struct treenode<T>;
newn->Data = Data;
newn->lchild = NULL;
newn->rchild = NULL;

struct treenode<T> *Temp = Root;

if (Root == NULL)
{
    Root = newn;
}
else
{
    while (true)
    {
        if (Data > Temp->Data)
        {
            if (Temp->rchild == NULL)
            {
                Temp->rchild = newn;
                break;
            }
            Temp = Temp->rchild;
        }
        else if (Data < Temp->Data)
        {
            if (Temp->lchild == NULL)
            {
                Temp->lchild = newn;
                break;
            }
            Temp = Temp->lchild;
        }
        else if (Data == Temp->Data)
        {
            free(newn);
            cout << "Duplicate element not allowed" << endl;
            break;
        }
    }
}

Function Flow:
1.	A new node (newn) is created and initialized with the provided data, and its left and right child pointers are set to NULL.
2.	A temporary pointer (Temp) is initialized to the root of the binary tree.
3.	If the binary tree is empty (Root == NULL), the new node becomes the root.
4.	If the binary tree is not empty, a loop iterates until the appropriate position for the new node is found:
•	If the data is greater than the current node's data, move to the right child.
•	If the data is less than the current node's data, move to the left child.
•	If the data is equal to the current node's data, display an error message for duplicate elements and break out of the loop.
•	If the child pointer in the chosen direction is NULL, the new node is inserted at that position, and the loop is terminated.

Usage Example :
BTree<int> myTree;
myTree.Insert(50);
myTree.Insert(30);
myTree.Insert(70);

// The binary tree now has nodes with data: 50 (Root), 30 (Left Child), 70 (Right Child)

2. DeleteNode(T Data);
Function prototype :

template <class T>
void BTree<T>::DeleteNode(T Data);

Function Description: This function initiates the deletion of a node with the given data from the binary tree.

Code snipet:
DeleteNode(Root, Data);

Function Flow:
1.	The function calls the private helper function DeleteNode with the root of the binary tree (Root) and the data to be deleted (Data).
2.	The DeleteNode helper function handles the actual deletion process and returns the updated root of the modified binary tree.

Usage Example :
BTree<int> myTree;
myTree.Insert(50);
myTree.Insert(30);
myTree.Insert(70);
myTree.DeleteNode(30);


3. findMin(treenode<T>* root);
Function prototype :
 template <class T>
treenode<T>* BTree<T>::findMin(treenode<T>* root);

Function Description: This function finds and returns the node with the minimum value in a binary search tree.
Code snipet :
while (root->lchild != NULL) {
    root = root->lchild;
}
return root;

Function Flow:
1.	Starting from the given node (root), the function traverses the left child pointers until it reaches the leftmost node, which has the minimum value in the binary search tree.
2.	The leftmost node is then returned.

Usage Example:
BTree<int> myTree;
myTree.Insert(50);
myTree.Insert(30);
myTree.Insert(70);
treenode<int>* minNode = myTree.findMin(myTree.getRoot());

// minNode now points to the node with the minimum value (30) in the binary search tree


4. DisplayInorder();
Function Prototype: 
template <class T>
void BTree<T>::DisplayInorder();

Function Description: This function initiates the inorder traversal of a binary tree, starting from the root.

Code snipet :
DisplayInorder(Root);
cout << endl;

Usage Example :
BTree<int> myTree;
myTree.Insert(50);
myTree.Insert(30);
myTree.Insert(70);

myTree.DisplayInorder(); // Output: 30 50 70


5. DisplayPreorder();

Function Prototype :
template <class T>
void BTree<T>::DisplayPreorder();
Function Description: This function initiates the preorder traversal of a binary tree, starting from the root.

Code snipet :
DisplayPreorder(Root);

Usage Example :

BTree<int> myTree;
myTree.Insert(50);
myTree.Insert(30);
myTree.Insert(70);

myTree.DisplayPreorder(); // Output: | 50 |   | 30 |   | 70 |


6.DisplayPostorder()

Function Prototype :

template <class T>
void BTree<T>::DisplayPostorder();

Function Description: This function initiates the postorder traversal of a binary tree, starting from the root.
Code snipet :

if (node != NULL)
{
    DisplayPostorder(node->lchild); // Traverse the left subtree
    DisplayPostorder(node->rchild); // Traverse the right subtree
    cout << "| " << node->Data << " |\t";
}


Usage Example :
BTree<int> myTree;
myTree.Insert(50);
myTree.Insert(30);
myTree.Insert(70);

myTree.DisplayPostorder(); // Output: | 30 |   | 70 |   | 50 |



7. SearchRecursive(treenode<T>* node, T Data)

Function prototype :
template <class T>
bool BTree<T>::SearchRecursive(treenode<T>* node, T Data);
Function Description: This helper function performs the actual recursive search for a specific data value in a binary tree. It returns true if the data is found and false if the data is not found.

Code snipet :
if (node == NULL)
{
    return false; // Element not found
}

if (node->Data == Data)
{
    return true; // Element found
}
else if (Data > node->Data)
{
    return SearchRecursive(node->rchild, Data);
}
else
{
    return SearchRecursive(node->lchild, Data);
}

Usage Example:
BTree<int> myTree;

myTree.Insert(50);
myTree.Insert(30);
myTree.Insert(70);

bool isFound = myTree.SearchRecursive(myTree.getRoot(), 30); // isFound is true


8. CountLeafNode(treenode<T>* node)

Function Prototype :

template <class T>
int BTree<T>::CountLeafNode(treenode<T>* node);

Function Description: This function counts the number of leaf nodes (nodes with no children) in a binary tree.

Code snipet:
int Count = 0;
if (node != NULL)
{
    if ((node->lchild == NULL) && (node->rchild == NULL))
    {
        Count++;
    }
    Count = Count + CountLeafNode(node->lchild);
    Count = Count + CountLeafNode(node->rchild);
}
return Count;


Usage Example:

BTree<int> myTree;
myTree.Insert(50);
myTree.Insert(30);
myTree.Insert(70);
myTree.Insert(20);
myTree.Insert(40);
myTree.Insert(60);
myTree.Insert(80);

int leafNodeCount = myTree.CountLeafNode(myTree.getRoot()); // leafNodeCount is 4


8.	CountParentNode(treenode<T>* node)

Function prototype :
 template <class T>
int BTree<T>::CountParentNode(treenode<T>* node);

Function Description: This function counts the number of parent nodes (nodes with at least one child) in a binary tree.

Code snipet:
int Count = 0;

if (node != NULL)
{
    if (node->lchild != NULL || node->rchild != NULL)
    {
        Count++;
    }
    Count += CountParentNode(node->lchild);
    Count += CountParentNode(node->rchild);
}

return Count;


Usage Example:
BTree<int> myTree;

myTree.Insert(50);
myTree.Insert(30);
myTree.Insert(70);
myTree.Insert(20);
myTree.Insert(40);
myTree.Insert(60);
myTree.Insert(80);

int parentNodeCount = myTree.CountParentNode(myTree.getRoot()); // parentNodeCount is 3




