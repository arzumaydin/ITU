/* @Author
    Student Name: Arzum Aydın 
    Student ID : 150190701
    Date: 11.01.2020 
*/

#include <iostream>
#include <string>
#include <fstream>
#include "data_structs.h"

using namespace std;

int count_twos = 0;
int completion_time = 0;
bool special_condition = false;

void execute_task(Process* process)
{
    Subtask* st = process->task_stack.pop();
    cout << process->name << " " << st->name << endl;
    completion_time += st->duration;
}

void execute_process(MultiQueue* multiqueue)
{
    int cl = 0; //cumulative lateness

    while(!multiqueue->queues[0].isEmpty()) // execute tasks with priority 1 
    {
        int prio = 1;
        Process* ptr = multiqueue->front(prio);
        if(completion_time < ptr->arrival_time)
        {
            completion_time = ptr->arrival_time;
        }
        while(!ptr->task_stack.isEmpty())
        {
            execute_task(ptr);
        }
        if(ptr->task_stack.isEmpty())
        {
            cl += completion_time - ptr->deadline;
            multiqueue->dequeue(prio);
        }
    }
    while(!multiqueue->queues[1].isEmpty())
    {
        if(!special_condition)
        {
            int prio = 2;
            Process* ptr = multiqueue->front(prio);
            if(completion_time < ptr->arrival_time)
            {
                completion_time = ptr->arrival_time;
            }
            execute_task(ptr);
            if(ptr->task_stack.isEmpty())
            {
                cl += completion_time - ptr->deadline;
                multiqueue->dequeue(prio);
            }
            count_twos++;

            if(count_twos == 2)
            {
                special_condition = true;
            }
        }
        else
        {
            int prio = 3;
            Process* ptr = multiqueue->front(prio);
            if(completion_time < ptr->arrival_time)
            {
                completion_time = ptr->arrival_time;
            }
            execute_task(ptr);
            if(ptr->task_stack.isEmpty())
            {
                cl += completion_time - ptr->deadline;
                multiqueue->dequeue(prio);
            }
            count_twos = 0;
            special_condition = false;
        }
    }

    while(!multiqueue->queues[2].isEmpty())
    {
        int prio = 3;
        Process* ptr = multiqueue->front(prio);
        if(completion_time < ptr->arrival_time)
        {
            completion_time = ptr->arrival_time;
        }
        while(!ptr->task_stack.isEmpty())
        {
            execute_task(ptr);
        }
        if(ptr->task_stack.isEmpty())
        {
            cl += completion_time - ptr->deadline;
            multiqueue->dequeue(prio);
        }
    }

    cout << "Cumulative Lateness: " << cl << endl;

    multiqueue->close();
}

int main(int argc, char* argv[])
{
    system("clear");

    MultiQueue multiqueue;

    multiqueue.init();

    bool first_task = true;

    ifstream myfile;
    
    myfile.open(argv[1]);
    
    //myfile.open("/Users/Arzum/Desktop/hw3/Codes/data.txt");

    if(myfile.fail()) // checks to see if file open
    { 
      cerr << "error while opening the file" << endl; 
      exit(1);
    }
    else
    {
        while(!myfile.eof())
        {
            if(myfile.eof()) //check if end of file is reached.
            {
                break;
            }

            Process* process = new Process;  //create new process
            
            myfile >> process->name >> process->priority;
            myfile >> process->arrival_time >> process->task_count;

            multiqueue.queue(process);

            process->task_stack.init(); // create task stack for process
            process->deadline += process->arrival_time;

            for(int i = 0; i < process->task_count; i++) //push all subtasks into stack
            {
                Subtask* subtask = new Subtask;
                myfile >> subtask->name >> subtask->duration;
                process->deadline += subtask->duration;

                process->task_stack.push(subtask);
            }

            if(first_task) //print first ever task regardless of priority
            {
                Subtask* first = process->task_stack.pop();
                cout << process->name << " " << first->name << endl;
                
                first_task = false;

                if(process->priority == 2)
                {
                    count_twos++;
                }

                completion_time += first->duration;
            }
        }
    }
    myfile.close();
    
    while(!multiqueue.isEmpty())
    {
        execute_process(&multiqueue);
    }
    
    return EXIT_SUCCESS;
}