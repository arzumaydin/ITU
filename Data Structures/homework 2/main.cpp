/* @Author
Student Name: Arzum Aydın 
Student ID : 150190701
Date: 7.12.2020 
*/

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

#include "circuit.h"

void Circuit::create()
{
    head = new resistor;
    head->next = head;
    head->quantity = 0;
}

void Circuit::add_resistor(char c, double val)
{
    resistor* new_res = new resistor;
    new_res->group = c;
    new_res->value = val;
    new_res->quantity = 0;
    
    resistor* lptr = head->next;

    if(head->next->value > new_res->value) // if new value is the smallest in the list
    {
        new_res->next = head->next; // make head point to the new value
        head->next = new_res;
        new_res->quantity += 1;
        return;
    }

    while(lptr->next != head)
    {
        if(lptr->next->value >= new_res->value) // trying to obtain a sorted list from smallest to the largest
        {
            if(new_res->group == lptr->next->group) // if the new res is already on the list 
            {
                lptr->next->quantity += 1;
                return;
            }
            else
            {
                new_res->next = lptr->next; // add the value in between
                lptr->next = new_res;
                new_res->quantity += 1;
                return;
            }
        }
        lptr = lptr->next;
    }
    
    new_res->next = lptr->next; // add the largest value
    lptr->next = new_res;
    new_res->quantity += 1;
    
} 

void Circuit::remove_resistor(char c, double num)
{
    resistor* rmv_res = new resistor;
    rmv_res->group = c;
    rmv_res->value = num;
    resistor* lptr = head->next;
    while(lptr != head)
    {
        if(rmv_res->group == lptr->group)
        {
            if(lptr->quantity > 1)
            {
                lptr->quantity -= 1;
                return;
            }
            else if(lptr->quantity == 1)
            {
                delete_resistor(c);
                return;
            }
        }
        lptr = lptr->next;
    }

    cout << "NO_RESISTOR" << endl;
} 

void Circuit::delete_resistor(char c)
{
    resistor* ptr = head->next;
    resistor* temp; //temp points to the node we want to delete

    while(ptr->next->group != c) // traverse the list until the one before we want to delete
    {
        ptr = ptr->next;
    }
    temp = ptr->next; 
    ptr->next = temp->next; 
    delete temp;
}

void Circuit::circuit_info()
{
    resistor* ptr = head->next;
    double total = 0; // total resistance
    int count = 0;

    while(ptr != head)
    {
        while(ptr->value == ptr->next->value)
        {
            count += ptr->quantity;
            ptr = ptr->next;
        }
        count += ptr->quantity;

        cout << ptr->value << ":" << count << endl;
        count = 0;
        ptr = ptr->next;
    }

    ptr = head->next;
    while(ptr != head)
    {   
        if(ptr->quantity > 1)
        {
            double res = 0;
            res = (ptr->value / ptr->quantity);
            total += res;
        }
        else if (ptr->quantity == 1)
        {
            total += ptr->value; 
        }
        ptr = ptr->next;
    }
    cout << "Total resistance=" << total << " ohm" << endl;
}

void Circuit::clear()
{
    resistor* ptr = head->next;
    resistor* del;

    while(ptr != head)
    {
        del = ptr;
        ptr = ptr->next;
        delete del;
    }
    delete head;
} 


int main(int argc, char* argv[])
{
    system("clear");
    
    Circuit circuit;

    circuit.create();

    char group; 
    double value;

    ifstream myfile;
    myfile.open(argv[1]);

    if(myfile.fail()) // checks to see if file opended 
    { 
      cout << "error" << endl; 
      exit(1);
    }
    else
    {
        while(!myfile.eof())
        {
            myfile >> group >> value;

            if(myfile.eof()) //check if end of file is reached.
            {
                break;
            }
            
            if(value > 0) // if condition holds, add resistor to the list
            {
                circuit.add_resistor(group, value);
            }
            else if(value < 0) 
            {
                circuit.remove_resistor(group, value);
            }

            if((group == 'A') && (value == 0)) // print list if A 0 
            {
                circuit.circuit_info();
            }
        }
    }
    myfile.close();
    
    circuit.clear();

    return EXIT_SUCCESS;
}