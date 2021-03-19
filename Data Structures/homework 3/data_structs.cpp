/* @Author
    Student Name: Arzum Aydın 
    Student ID : 150190701
    Date: 11.01.2020 
*/

#include <iostream>
#include "data_structs.h"

using namespace std;

void Stack::push(Subtask* in)
{
    in->next = head;
    head = in;
}

Subtask* Stack::pop()
{
    Subtask* topop; 
    topop = head; //topop will hold the value
    head = head->next; 

    return topop;
}

void Stack::init()
{
    //Subtask* head = new Subtask;
    head = NULL;
}

bool Stack::isEmpty()
{
    return head == NULL;
}

void Stack::close()
{
    Subtask* todel;
    while(head)
    {
        todel = head;
        head = head->next;
        delete todel;
    }

}

void Queue::init()
{
    //Subtask* head = new Subtask;
    //Subtask* tail = new Subtask;

    head = NULL;
    tail = NULL;
}

void Queue::close()
{
    Process* todel;
    while(front())
    {
        todel = head;
        head = head->next;
        delete todel;
    }

    delete tail;
}

void Queue::queue(Process* in) // write a function to sort queue
{
    if(isEmpty()) {
		tail = in;
		head = tail;
	}
	else {
        tail->next = in;
        tail = in;
	}
}

Process* Queue::dequeue()
{
    Process* ptr;
    ptr = head;
    head = head->next;
    
    return ptr;
}

bool Queue::isEmpty()
{
    return head == NULL;
}

Process* Queue::front()
{
    return head;
}

void MultiQueue::init()
{
    for(int i = 0; i < 3; i++) //initialize queues
    {
        queues[i].init();
    }
}

void MultiQueue::close()
{
    for(int i = 0; i < 3; i++) //close queues
    {
        queues[i].close();
    }   
}

void MultiQueue::queue(Process* in)
{
    if(in->priority == 1) // queue process according to priority
    {
        queues[0].queue(in);
    }
    else if(in->priority == 2)
    {
        queues[1].queue(in);
    }
    else
    {
        queues[2].queue(in);
    }
}

bool MultiQueue::isEmpty()
{
    if(queues[0].isEmpty() && queues[1].isEmpty() && queues[2].isEmpty())
    {
        return true;
    }
    
    return false;
}

Process* MultiQueue::front(int priority)
{
    if(priority == 1)
    {
        return queues[0].front();
    }
    else if(priority == 2)
    {
        return queues[1].front();
    }
    else
    {
        return queues[2].front();
    }
}

Process* MultiQueue::dequeue(int priority)
{
    if(priority == 1)
    {
        return queues[0].dequeue();
    }
    else if(priority == 2)
    {
        return queues[1].dequeue();
    }
    else
    {
        return queues[2].dequeue();
    }
}