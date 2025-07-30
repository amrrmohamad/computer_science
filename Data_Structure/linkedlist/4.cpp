#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
};

void addbefor(node* &first, int x, int y){
    node *q, *run;
    q = new node();
    q -> val = x;
    q -> next =  NULL;
    run = first;

    while (run -> next != NULL)
    {
        // cout << run -> val << endl;
        if (run -> next -> val == y){
            q -> next = run -> next;
            run -> next = q;
            break;
        }
        run = run -> next;
    }
}

int main(){
    node *p, *o, *r;
    p = new node();
    o = new node();
    r = new node();
    p -> val = 10;
    p -> next = o;
    o -> val = 20;
    o -> next = r;
    r -> val = 30;
    r -> next = NULL;

    addbefor(p, 1000, 30);
    cout << p -> next -> next -> next -> val;
}
