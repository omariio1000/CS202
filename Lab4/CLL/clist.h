//clist.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;	//some questions are a char * data;
    node * next;
};

class list
{
   public:
   	//These functions are already written
   	list();			//supplied
   	~list();		//supplied
   	void build();	//supplied
   	void display();	//supplied

	/* *****************YOUR TURN! ********************* */
	//Write your function prototype here:
    int copySpecial(list & destination);

  private:
	node * rear;
    int copySpecial(node *& dest, node * source);
};
