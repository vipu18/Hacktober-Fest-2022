#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *nextptr;

    node(int val)
    {
        data = val;
        nextptr = NULL;
    }
};
void insert_attail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->nextptr != NULL)
    {
        temp = temp->nextptr;
    }

    temp->nextptr = n;
}
void display(node *head)
{
    // node *temp = head;
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->nextptr;
    }
    cout << "NULL" << endl;
}
void delete_athead(node *&head)
{
    node *todelete = head;
    head = head->nextptr;

    delete todelete;
}
void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        cout << " empty lol";
        return;
    }
    if (head->nextptr == NULL)
    {
        delete_athead(head);
        return;
    }

    node *temp = head;
    while (temp->nextptr->data != val)
    {
        temp = temp->nextptr;
    }
    node *to_delet = temp->nextptr;
    temp->nextptr = temp->nextptr->nextptr;

    delete to_delet;
}

node *reverse(node *&head)
{

    node *prevptr = NULL;
    node *currentptr = head;
    node *nextone;

    while (currentptr != NULL)
    {
        nextone = currentptr->nextptr;

        currentptr->nextptr = prevptr;

        prevptr = currentptr;
        currentptr = nextone;
    }

    return prevptr;
}

node *REC_reverse(node *&head)
{
    if (head->nextptr == NULL || head == NULL)
    {
        return head;
    }

    node *newhead = REC_reverse(head->nextptr);
    head->nextptr->nextptr = head;
    head->nextptr = NULL;
    return newhead;
}

node *reverse_Knode(node *&head, int k)
{

    node *prevptr = NULL;
    node *currentptr = head;
    node *nextptr;
    int counter = 0;

    while (currentptr != 0 && counter < k)
    {
        nextptr = currentptr->nextptr;
        currentptr->nextptr = prevptr;
        prevptr = currentptr;
        currentptr = nextptr;
        counter++;
    }
    if (nextptr != NULL)
    {
        head->nextptr = reverse_Knode(nextptr, k);
    }

    return prevptr;
}

void make_cylce(node *&head, int n)
{

    node *temp = head;
    node *startnode;

    int count = 1;
    while (temp->nextptr != NULL)
    {
        if (count == n)
        {
            startnode = temp;
        }
        temp = temp->nextptr;
        count++;
    }

    temp->nextptr = startnode;
}

bool floyd_detect(node *&head)
{

    node *slowptr = head;
    node *fastptr = head;

    bool is_cycle = false;

    while (fastptr != NULL)
    {
        slowptr = slowptr->nextptr;
        fastptr = fastptr->nextptr->nextptr;
        if (fastptr == slowptr)
        {
            is_cycle = true;
            return is_cycle;
        }
        is_cycle = false;
    }

    return is_cycle;
}

int length_of_LL(node *head)
{
    node *temp = head;
    int count = 0;

    if (head == NULL)
    {

        return count;
    }

    while (temp != NULL)
    {

        temp = temp->nextptr;
        count++;
    }

    return count;
}
node *append_LASTk(node *&head, int k)
{

    node *temp = head;
    node *tail;
    node *newhead;
    int count = 1;
    int l = length_of_LL(head);
    k = k % l;
    while (temp->nextptr != NULL)
    {

        if (count == l - k)
        {
            tail = temp;
            newhead = temp->nextptr;
        }

        temp = temp->nextptr;
        count++;
    }

    tail->nextptr = NULL;
    temp->nextptr = head;

    return newhead;
}

node *merge(node *&head1, node *&head2)
{
    node *p1 = head1;
    node *p2 = head2;
    node *dummynode = new node(-1);

    node *p3 = dummynode;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->nextptr = p1;
            p1 = p1->nextptr;
        }
        else
        {
            p3->nextptr = p2;
            p2 = p2->nextptr;
        }
        p3 = p3->nextptr;
    }
    while (p1 != NULL)
    {
        p3->nextptr = p1;
        p1 = p1->nextptr;
        p3 = p3->nextptr;
    }
    while (p2 != NULL)
    {
        p3->nextptr = p2;
        p2 = p2->nextptr;
        p3 = p3->nextptr;
    }

    return dummynode->nextptr;
}

void evenafter_odd(node *&head)
{
    node *odd = head;

    node *even = head->nextptr;

    node *evenstart = even;

    while (odd->nextptr != NULL && even->nextptr != NULL)
    {
        odd->nextptr = even->nextptr;
        odd = odd->nextptr;
        even->nextptr = odd->nextptr;
        even = even->nextptr;
    }

    odd->nextptr = evenstart;

    if (odd->nextptr != NULL)
    {

        even->nextptr = NULL;
        /* code */
    }
}
int main()
{

    node *head = NULL;

    insert_attail(head, 1);
    insert_attail(head, 2);
    insert_attail(head, 3);
    insert_attail(head, 4);
    display(head);

    deletion(head, 3);
    display(head);

    insert_attail(head, 5);
    insert_attail(head, 7);
    insert_attail(head, 4);
    display(head);

    // make_cylce(head, 3);

    // cout << floyd_detect(head) << endl;

    node *append_head = append_LASTk(head, 2);

    display(append_head);

    node *head1 = NULL;

    node *head2 = NULL;

    int arr1[] = {1, 6, 8, 9};
    int arr2[] = {2, 5, 6, 8, 10};
    for (int i = 0; i < 4; i++)
    {
        insert_attail(head1, arr1[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        insert_attail(head2, arr2[i]);
    }

    display(head1);
    display(head2);

    node *merge_head = merge(head1, head2);
    display(merge_head);
    return 0;
}