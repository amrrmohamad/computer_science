#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
};

void addafter(node* &first, int x, int y){
    node *q, *run;
    q = new node();
    q -> val = x;
    q -> next =  NULL;
    run = first;

    while (run -> next != NULL)
    {
        // cout << run -> val << endl;
        if (run -> val == y){
            q -> next = run -> next;
            run -> next = q;
            break;
        }
        run = run -> next;
    }
}

int main(){
    node *p, *o;
    p = new node();
    o = new node();
    p -> val = 10;
    p -> next = o;
    o -> val = 20;
    o -> next = NULL;

    addafter(p, 1000, 10);
    cout << p -> val;
    cout << p -> val;
}
