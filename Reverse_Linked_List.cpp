#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    class Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList{
    public:
    Node* head;
    LinkedList()
    {
        head=NULL;
    }

    void reverse()
    {
        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while(current!=NULL)
        {
            next=current->next;
            current->next=NULL;
            prev=current;
            current=next;
        }
        head=prev;
    }

    void print()
    {
        class Node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{
    LinkedList l;
    int n; cin>>n;
    for(int i=0;i<n;i++) 
    {
        int num; cin>>num;
        l.push(num);
    }
    
    cout<<" Given Linked List\n";
    l.print();

    l.reverse();

    cout<<"\n Reversed Linked List \n";
    l.print();
    return 0;
}