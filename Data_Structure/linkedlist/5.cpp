#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
};

void deletefirst(node* &first){
    if (first == NULL){
        cout << "Empty\n";
        exit;
    }

    node *t;
    t = first;
    first = first -> next;
    delete(t);
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

    deletefirst(p);
    cout << p -> next -> val;
}
