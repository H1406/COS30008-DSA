#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};
int main(){
    Node* head = new Node{10,nullptr};
    head->next = new Node{5,nullptr};
    cout<< head->next->value;
}