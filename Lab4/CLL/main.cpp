#include "clist.h"


int main()
{
    list object;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    list newList;

    cout << endl << "Copied " << object.copySpecial(newList) << " items" << endl;
    newList.display();


    object.display(); //resulting list after your function call!
    
        
    return 0;
}
