/*
YOU HAVE TO WRITE THE REQUIRED  FUNCTIONS. YOU CAN ADD NEW FUNCTIONS IF YOU NEED.
*/

/* @Author
Student Name: Arzum Aydın 
Student ID : 150190701
Date: 5.11.2020 
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "counter.h"

using namespace std;
	
int Counter::findindex(Token *arr,char elem[]){
	//THIS FUNCTION WILL BE CODED BY YOU
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		if(strcmp(arr->token, elem) == 0)
		{
			return i;
		}
		arr++;
	}
	return -1;
} 

bool Counter::contains(char *token, char target){ //
	//THIS FUNCTION WILL BE CODED BY YOU
	for(int i = 0; i<ARRAY_SIZE; i++)
	{
		if(*token == target)
		{
			return true;
		}
		token++;
	}
	return false;
}

void Counter::read_and_count(){
	//THIS FUNCTION WILL BE CODED BY YOU
	FILE* read_pi;
	int i = 0; // index of token_array
	read_pi = fopen("pi_approximate", "r+"); //read from file
	char token[TOKEN_LENGTH];
	char* ptr_to_token = &token[0]; //ptr_to_token points to token array
	Token* ptr = &token_array[0]; //ptr points to token_array

	if(read_pi == NULL)
	{
		cerr << "Cannot open file" << endl;
		exit(1);
	}
	else
	{
		while(!feof(read_pi)) 
		{
			fgets(token, sizeof(char)*3, read_pi); //read two decimals into token array 

			if(contains(ptr_to_token, '.')) //continue if token involves '.'
			{
				i++;
			}
			else
			{
				if(findindex(ptr, token) == -1) //if token is not in the token array
				{
					strcpy(token_array[i].token, token);
					token_array[i].count++;
					if(feof(read_pi)) //if end of file is reached, break
					{
						break;
					}
					else
					{
						fseek(read_pi, -sizeof(char), SEEK_CUR);
					}
					
				}
				else //if token is already in the token array
				{
					int n = findindex(ptr, token);
					token_array[n].count++;
					if(feof(read_pi))
					{
						break;
					}
					else
					{
						fseek(read_pi, -sizeof(char), SEEK_CUR);
					}
				}
				
				i++;
			}
		}
	}

	fclose(read_pi);

}


Token *Counter::get_most_common_three(){
	//THIS FUNCTION WILL BE CODED BY YOU
	static Token c_three[3];
	
	c_three->count = 0, (c_three + 1)->count = 0, (c_three + 2)->count = 0;

	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		if(token_array[i].count > c_three->count)
		{
			(c_three + 2)->count = (c_three + 1)->count;
			strcpy((c_three + 2)->token, (c_three + 1)->token);

			(c_three + 1)->count = c_three->count;
			strcpy((c_three + 1)->token, c_three->token);

			strcpy(c_three->token, token_array[i].token);
			c_three->count = token_array[i].count;
		}
		else if(token_array[i].count > (c_three + 1)->count)
		{
			(c_three + 2)->count = (c_three + 1)->count;
			strcpy((c_three + 2)->token, (c_three + 1)->token);

			strcpy((c_three + 1)->token, token_array[i].token);
			(c_three + 1)->count = token_array[i].count;			
		}
		else if(token_array[i].count > (c_three + 2)->count)
		{
			strcpy((c_three + 2)->token, token_array[i].token);
			(c_three + 2)->count = token_array[i].count;
		}
	}
	
	return c_three;
}
