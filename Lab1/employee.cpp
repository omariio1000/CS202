#include "employee.h"
using namespace std;

//Step 7 implement select functions as provided here:

employee::employee(char * name, char * street, char * zip, int id)
{
	//Avoid accessing the base class members here.
        //Instead, use an initialization list to cause the
        //base class constructor to be called with the name


}

//Step 8 implement the hourly_employee constructor

//Set up a new hourly employee, give a person's information
//Think about how to use the member functions inherited to
//initialize the new hourly employee.
//Avoid use of the = operator as it does a shallow copy!
hourly_employee::hourly_employee(const person & input)
{

}

//Step 9 implement the wrapper display function
//Think about what it means to use the word "wrapper"

//Implement the wrapper function to display an employee
//and then call the recursive display function to display
//the BST containing performance review information
void employee::display() const
{

}

// *******************************************************
//Now go do Step 10 and examine the node class in node.h
// *******************************************************

//Step 11 implement the recursive display function

//Implement the recursive display function using the 
//functions available within the hierarchy
void employee::display(node * root) const
{


}

//Step 12 - Implement a recursive copy function
void employee::copy_tree(node * & dest_root, node * source_root) const
{


}
