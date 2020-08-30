#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *next;
};

node *head = NULL;
node *last = head;

void insertbeg(int n){
    node *ptr = new node();
    ptr->val = n;
    ptr->next = head;
    head = ptr;
}

void insertend(int n){
    node *ptr = new node();
    ptr->val = n;
    ptr->next = NULL;
    if(head==NULL){
        head = ptr;
        last = ptr;
    }else{
        last->next = ptr;
        last = ptr;
    }
}

void traverse(){
    while(head!=NULL){
        cout << head->val<<" ";
        head = head->next;
    }
}

void reverse(){
    node *prev = NULL;
    node *cur = head;
    last = head;
    while(cur !=NULL){
        node *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    head = prev;
}

void findmiddle(){
    node *a = head;
    node *b = head;
    while(!(b==NULL || b->next==NULL)){
        b = b->next;
        b = b->next;
        if(b!=NULL){
            a = a->next;
        }
    }
    cout<<a->val;
}
int main(){
    int n;
    cin>>n;
    for(int x,i=0;i<n;i++){
        cin>>x;
        insertend(x);
    }
    //reverse();
    //traverse();
    findmiddle();
}