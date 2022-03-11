#include "table.h"
using namespace std;

//These are the functions that you will be writing for Lab #10


//STEP 1
int table::count()	//SAMPLE wrapper function
{
    return count(root);
}

int table::count(node * root) {
    if (!root) return 0;
    int left = count(root -> left);
    int right = count(root -> right);
    if (this -> root -> data == root -> data) return 0 + left + right;
    return 1 + left + right;
}


//STEP 2
int table::count_right_subtree() {
    if (!root) return 0;
    node * temp = root;
    while (temp -> left) temp = temp -> left;
    return count_right_subtree(temp -> right);
}
int table::count_right_subtree(node * root){
    if (!root) return 0;
    int left = count(root -> left);
    int right = count(root -> right);
    return 1 + left + right;
}


//STEP 3
int table::remove_largest(){
    if (!root) return 0;
    return remove_largest(root);
}
int table::remove_largest(node * & root){
    if (!root -> right) {
        node * temp = root -> left;
        int ret = root -> data;
        delete root;
        root = temp;
        return ret;
    }
    return remove_largest(root -> right);
}


//STEP 4
int table::sum() { 
    if (!root) return 0;
    return sum(root);
}
int table::sum(node * root){
    if (!root) return 0;
    int val = 0;
    int div = 0;
    if (root -> data % 3 == 0 || root -> data % 5 == 0) {
        val += root -> data;
        div+=1;
    }
    if (root -> right) {
        val += sum(root -> right);
        div += 1;
    }
    if (root -> left) {
        val += sum(root -> left);
        div += 1;
    }
    if (div == 0) return 0;
    return (int) (val/div);
}

int table::easierSum() {
    if (!root) return 0;
    int total = 0;
    int sum = easierSum(root, total);
    return (int) (sum/total);
}

int table::easierSum(node * root, int & count) {
    if (!root) return 0;
    if (root -> data % 3 == 0 || root -> data % 5 == 0) {
        count += 1;
        return root -> data + easierSum(root -> left, count) + easierSum(root -> right, count);
    }
    return easierSum(root -> left, count) + easierSum(root -> right, count);
}

//STEP 5
int table::copy(table & to_copy){
    if (!to_copy.root) return 0;
    return copy(root, to_copy.root);
}
int table::copy(node * & destination, node * source){
    if (!source) return 0;
    destination = new node;
    destination -> data = source -> data;
    return 1 + copy(destination -> left, source -> left) + copy(destination -> right, source -> right);
}


//STEP 6a Challenge
int table::create_full(){}
int table::create_full(node * & new_tree){}


//STEP 6b
bool table::is_full(){
    if (!root) return false;
    return is_full(root);
}
bool table::is_full(node * root){
    if (!root) return false;
    if (right || left) return is_full(root -> right) && is_full(root -> left);
    return true;
}


//STEP 6c
int table::display_largest(){
    if (!root) return 0;
    if (!root -> right) return root -> data;
    return display_largest(root -> right);
}
int table::display_largest(node * root){
    if (!root -> right) return root -> data;
    return display_largest(root -> right);
}


//STEP 6d
int table::display_largest2(){
    if (!root) return 0;
    if (!root -> right) {
        cout << "Largest: " << root -> data << endl;
        cout << "Second Largest: " << display_largest(root -> left) << endl;
        return 1;
    }
    return display_largest2(root);
    
}
int table::display_largest2(node * root){
    if (!root -> right -> right) {
        cout << "Largest value: " << root -> right -> data << endl;
        if (root -> right -> left) cout << "Second Largest: " << display_largest(root -> right -> left) << endl;
        else cout << "Second Largest: " << root -> data << endl;
        return 2;
    }
    return display_largest2(root -> right);
}



