#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node *next;
    node() {
        data = 0;
        next = nullptr;
    }

    node(int data) {
        this->data = data;
        next = nullptr;
    }
};
node*first;
void insert(node*newnode) {
    if(first == nullptr) {
        first = newnode;
    }else if(newnode->data < first->data) {
        newnode->next = first;
        first = newnode;
    }else {
        node*p;
        p = first;
        while(p->next !=nullptr && p->next->data < newnode->data) {
            p = p->next;
        }
        newnode->next = p->next;
        p->next = newnode;
    }
}
void count() {
    int result=0;
    node *q = first;
    while(q != nullptr) {
        result++;
        q = q->next;
    }
    cout << result << endl;
}
void display() {
    node *o = first;
    while(o != nullptr) {
        cout << o->data << endl;
        o = o->next;
    }
}
node*search( int data) {
    node *t= first;
    while(t!= nullptr) {
        if(t->data == data) {
           return t;
        }else{
            t = t->next;
        }

    }
    cout<<"not found"<<endl;
    return nullptr;
}
void remove(node*q) {
    node*p;
    if(first==q) {
        first=q->next;
    }else {
        p = first;
        while(p->next !=q) {
            p = p->next;
        }
        p->next = q->next;

    }
}


int main(){
        node*n1 =new node(1);
        insert(n1);
        node*n2 =new node(0);
        insert(n2);
    node*n3 =new node(3);
    insert(n3);
    node*n4=new node(7);
    insert(n4);
    // cout<<first->data<<endl;
    // count();
    // display();
    remove(n3);
    display();
    return 0;
    }