#include "list.h"

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int num;
    cout << "What number would you like to check for?" << endl;
    cin >> num;
    cin.clear();
    cin.ignore(100, '\n');

    cout << "That number was found " << object.num_times(num) << " times in the list." << endl;
    cout << endl;
    int ofunt = object.displayAlmostAll();
    cout << "The sum of first and last is: " << ofunt << endl;

    cout << "Removed " << object.removeAlmostAll() << " items from the list." << endl;
    

    object.display();  //displays the LLL again!
   
    
    return 0;
}
