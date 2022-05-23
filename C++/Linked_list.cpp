#include <iostream>
using namespace std;
//Node Class
class Node
{
    public:
    int data;
    Node* next;
};

void printList(Node* node)
{
    cout<<endl;
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
    cout<<endl;
}
void push(Node** head_ref, int new_data)
{
    //Allocate node
    Node* new_node= new Node();
    //Insert data
    new_node->data=new_data;
    //Make "next node" of new node to the previous head
    new_node->next=(*head_ref);
    //move the head to point to the new node
    (*head_ref)=new_node;
}
void insertAfter(Node* prev_node, int new_data)
{
    if(prev_node==NULL)
    {
        cout<<"The given previous node cannot be NULL dummy pants.";
        return;
    }
    //Allocate new node
    Node* new_node= new Node();

    //insert data
    new_node->data=new_data;
    
    //Make the next of new node as the next of previous node
    new_node->next=prev_node->next;

    //Make the nexc of the previous node as new node
    prev_node->next=new_node;

}
void append(Node** head_ref, int new_data)
{
    //Allocate node
    Node* new_node= new Node();

    Node *last=*head_ref;
    
    //Insert data
    new_node->data=new_data;

    //Since the new node will be the last the "next" must be NULL
    new_node->next=NULL;

    //If the list is empty the new node will be the head.
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    //traverse list until we are at the end
    while(last->next!=NULL)
    {
        last=last->next;
    }
    // change the next of the last node to the new last node
    last->next=new_node;
    return;
}
int main()
{
    //create a list with three nodes
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    //allocate 3 nodes to the heap
    head = new Node();
    second = new Node();
    third = new Node();

    //assign data to desired input
    //link node to next node
    cout<<"Enter an integer to being the linked list: "<<endl;
    int start;
    cin>>start;

    head->data=start;
    head->next=NULL;

    cout<<"Thank you\n";

    char choice;

    while (choice != 'Q'||choice !='Q')
    {
        cout<<endl<<"--Welcome to linked list thingy--"<<endl;
        cout<<"--Please choose from the selections bellow--"<<endl;
        cout<<"Press P to print linked list"<<endl;
        cout<<"Press U to push an integer to front of list"<<endl;
        cout<<"Press A to append an integer to end of list"<<endl;
        cout<<"Press Q to quit program"<<endl;

        cin>>choice;

        if (choice == 'P'||choice =='p')
        {
            printList(head);
        }
        else if(choice == 'U'||choice=='u')
        {
            int pushi;
            cout<<"Enter integer to push: ";
            cin>>pushi;
            push(&head,pushi);
        }
        else if(choice=='A'||choice=='a')
        {
            int appendi;
            cout<<"Enter integer to append: ";
            cin>>appendi;
            append(&head, appendi);
        }
        else if(choice=='Q'||choice=='q')
        {
            cout<<"Good bye!";
            break;
            
        }
    }
 
    return 0;
}