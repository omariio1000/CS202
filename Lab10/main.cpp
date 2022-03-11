#include "table.h"
using namespace std;

int main()
{
    table BST;	
    BST.build();
    BST.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
    cout << "There are " << BST.count() << " nodes in the tree that don't match the root." << endl;
    cout << "The right subtree of the smallest node contans " << BST.count_right_subtree() << " nodes." << endl;
    cout << "Largest value: " << BST.display_largest() << endl;
    BST.display_largest2();
    cout << "Deleted largest value, which was " << BST.remove_largest() << "." << endl;
    //cout << "The average of the nodes that have a value which is a multiple of 3 or 5 is " << BST.sum() << "." << endl;
    cout << "ACTUAL AVERAGE: " << BST.easierSum() << endl;
    if (BST.is_full()) cout << "Tree is full." << endl;
    else cout << "Tree is not full." << endl;
    
    /*table newBST;
    newBST.copy(BST);
    cout << endl << "NEW BST:" << endl;
    newBST.display();
    cout << endl;*/

    BST.display(0);

    return 0;
}
