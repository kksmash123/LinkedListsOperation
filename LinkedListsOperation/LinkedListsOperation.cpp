#include <iostream>
using namespace std;


struct Node
{
    int data;

    struct Node* next;

}*Hfirst,*Hsecond,*HeadCLL;


struct Node* createll(int a[], int n);

void Display(struct Node* head);

void concatList(struct Node* l1, struct Node* l2);

struct Node* MergeLL(struct Node* l1, struct node* l2);

struct Node* MergeUpdate(struct Node* l1, struct Node* l2);

bool checkLoop(struct Node* head);

struct Node* creatcircularLL(int a[], int n);

void DisplayCLL(struct Node* head);




void DisplayCLL(struct Node* head)
{

}


struct Node* creatcircularLL(int a[], int n) 
{
    struct Node* head=NULL,*p=NULL;

    //empty array ->empty list
    if (n == 0)
        return NULL;
    head = new Node;
    head->data = a[0];
    head->next = head;
   
    //for single element is passed
    if (n == 1)
        return head;
    
    //more then one element is passed
    p = head;

    for (int i = 1;i < n;i++)
    {
        struct Node* temp = new Node;
        temp->data = a[i];
        temp->next = head;
        p->next = temp;

        p = temp;

    }
    return head;
}


bool checkLoop(struct Node* head)
{

    struct Node* slow, * fast;
    slow = fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next ? fast->next->next : NULL;

    } while (slow && fast && (slow != fast));

    if (slow == fast)
        return true;
    else
        return false;
}


struct Node* MergeUpdate(struct Node* l1, struct Node* l2)
{

    struct Node* mstart=NULL, * mend = NULL, * d = NULL;

    while (l1 && l2)
    {
        //Deciding which node to choose

        if (l1->data < l2->data)
        {
            d = l1;
            l1 = l1->next;
        }

        else
        {
            d = l2;
            l2 = l2->next;
        }

        //making the linking to the merge list 

        if (!mstart)
        {
            mstart =mend=d;
        }
        else 
        {
            mend->next = d;
            mend = d;

        }
        mend->next = NULL;
    }

    if (l1)
        mend->next = l1;
    if (l2)
        mend->next = l2;

    return mstart;

}


struct Node* MergeLL(struct Node* l1, struct Node* l2)
{

    struct Node* mergstart=NULL, * mergend=NULL,*decide=NULL;

    if (l1->data < l2->data)
    {
        decide = l1;
        l1 = l1->next;
    }
    else
    {
        decide = l2;
        l2 = l2->next;
    }

    mergstart = decide;
    mergend = decide;
    mergend->next = NULL;

    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            decide = l1;
            l1 = l1->next;
            
        }
        else
        {
            decide = l2;
            l2 = l2->next;
        }

        mergend->next = decide;
        mergend = mergend->next;
        mergend->next = NULL;

    }

    if (l1)
        mergend->next = l1;
    if (l2)
        mergend->next = l2;

    return mergstart;
}


void concatList(struct Node* l1, struct Node* l2)
{
    struct Node* head, * p;
    head = l1;
    p = head;

    while (p->next)
        p = p->next;

    p->next = l2;
    l2 = NULL;
    
}


void Display(struct Node* head)
{
    while (head)
    { 
        cout << head->data<<" ";
        head = head->next;
    }
}


struct Node* createll(int a[], int n)
{
    struct Node* head = new Node,*p=NULL;

    head->data = a[0];
    head->next = NULL;
    p = head;
    for (int i = 1;i < n;i++)
    {
        //making new node and giving value to it 

        struct Node* temp = new Node;
        temp->data = a[i];
        temp->next = NULL;

        //linking the newnode to the parent node
        p->next = temp;

        //moving the pointer to latest added node
        p = p->next;
    }

    return head;

}





int main()
{
    //int a[3] = { 10,20,30 };
    //int b[5] = {5,125,135,140,150};

    //

    ////create 2 linked list 
    //Hfirst = createll(a, 3);
    //Hsecond = createll(b, 5);

    ////Displaying the 2 linked list
    //cout << "First Linked List " << endl;
    //Display(Hfirst);
    //cout <<endl<< "Second Linked List " << endl;
    //Display(Hsecond);

    //concatenating the 2 linked list ,l1 ->first linked list , l2->second linked list concate to l1.
    /*concatList(Hfirst,Hsecond );
    cout <<endl<< "Displaying the Linked List after concatenation" << endl;
    Display(Hsecond);*/

    /*struct Node * Hmerge=MergeLL(Hfirst, Hsecond);
    cout << endl << "After merging the  Linked List " << endl;
    Display(Hmerge);*/


    /*struct Node* Hmerge2 = MergeUpdate(Hfirst, Hsecond);
    cout << endl << "After merging the  Linked List " << endl;
    Display(Hmerge2);*/

    ////making loops in hfirst
    //struct Node* t = Hfirst->next, *t1= Hfirst->next->next;

    //t1->next = t;

    //// displaying loop
    ///*cout << "First Linked List " << endl;
    //Display(Hfirst);*/

    //cout << endl << "Is loop present in the linked list : " << checkLoop(Hsecond);



    //circular linked list creation

    int a[5] = { 10,20,30,40,50 };

    HeadCLL = creatcircularLL(a, 5);

    //Displaying the circular linked list





}
