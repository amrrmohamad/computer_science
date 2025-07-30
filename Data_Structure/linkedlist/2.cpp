#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
};

void addlast(node* &first, int x){
    node *q, *run;
    q = new node();
    q -> val = x;
    q -> next =  NULL;
    run = first;

    while (run -> next != NULL)
    {
        run = run -> next;
    }
    run -> next = q;
}

int main(){
    node *p, *o;
    p = new node();
    o = new node();
    p -> val = 10;
    p -> next = o;
    o -> val = 20;
    o -> next = NULL;

    addlast(p, 1000);
    cout << o -> next -> val;
}
