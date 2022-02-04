#include "store.h"
using namespace std;

//Implement each of these using exception handeling
//For each function consider if you should have the try block
//in the function or if you should have the try block in the
//calling routine. If you throw an exception without a
//try block, then add an exception specification list


//Step 5a - throw an exception if there is an invalid response
bool again()
{
    char ans;
    cin >> ans;
    cin.clear();
    cin.ignore(100, '\n');
    try {
        if (toupper(ans) == 'Y') return true;
        else if (toupper (ans) == 'N') return false;
        else throw ans;
    }
    catch (char x) {
        cout << endl << "Invalid Character. Try again." << endl;
        return again();
    }
}

//Step 5b - implement the address constructor and throw an
//exception if ther eis a null string being copied:

address::address(char * new_street, char * new_zip)
{
    if (!new_street || !new_zip) {
        NULL_STRING obj;
        if (!new_street) obj.street = nullptr;
        else {
            obj.street = new char[strlen(new_street) + 1];
            strcpy(obj.street, new_street);
        }
        if (!new_zip) obj.zip = nullptr;
        else {
            obj.zip = new char[strlen(new_zip) + 1];
            strcpy(obj.street, new_street);
        }
        throw obj;
    }

    street = new char[strlen(new_street) + 1];
    strcpy(street, new_street);

    zip = new char[strlen(new_zip) + 1];
    strcpy(zip, new_zip);
}

//Step 5c - implement the set pay function and throw an
//exception if a zzero or negative pay is requested

void hourly_employee::set_pay_rate(float rate) 
{
    if (rate <= 0) {
        INVALID_PAY obj;
        obj.pay = rate;
        throw obj;
    }
    else pay_rate = rate;
    return;
}

// *************************** Now move to main.cpp and work there


//Step 7 - implement the two compare functions. The first
//compares the employees name. Throw an exception if there is no match
bool employee::compare(const name & match)
{
    if (find_by_name(match)) return true;
    throw match;
    return false;
}

//Now travere the binary search tree of reviews and
//throw an exception if there is no match
bool employee::compare(char * match)
{
    bool ans = compare(root, match);
    if (ans) return ans;
    else throw ans;
    return ans;
}

bool employee::compare(node * root, char * match) {
    if (!root) return false;
    if ((root -> find_by_name(match)) return true;
    bool left = compare(root -> go_left(), match);
    bool right = compare(root -> go_right(), match);
    if (left || right) return true;
    return false;
}
