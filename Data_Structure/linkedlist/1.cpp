#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
};

// function to add in first linked list

void addFirst (node* &first, int x){
    node *q;
    q = new node();
    q -> val = x;
    q -> next = first;
    first = q;
}


int main(){
    node *p, *o;
    p = new node();
    o = new node();
    p -> val = 10;
    p -> next = o;
    o -> val = 20;
    o -> next = NULL;

    addFirst(p, 1000);
    cout << p -> val;
}