/* @Author
Student Name: Arzum Aydın 
Student ID : 150190701
Date: 7.12.2020 
*/

#ifndef _H
#define _H
#include "resistor.h"

struct Circuit
{
    resistor *head;
    void create();
    void add_resistor(char, double); 
    void remove_resistor(char, double); 
    void delete_resistor(char); 
    void circuit_info();
    void clear(); 
};
#endif