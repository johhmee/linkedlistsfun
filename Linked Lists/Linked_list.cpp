#include <iostream>
#include <unistd.h>
#include <stdlib.h>
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
void sortedInsert(Node** head_ref, int new_data)
{
    Node* new_node=new Node();
    new_node->data=new_data;

    if(*head_ref==NULL||(*head_ref)->data>=new_node->data)
    {
        new_node->next=*head_ref;
        *head_ref=new_node;
        return;
    }

    Node* current = *head_ref;
    while(current->next!=NULL && current->data<new_node->data)
    {
        current=current->next;
    }

    new_node->next=current->next;
    current->next=new_node;

}
void deleteNode(Node** head_ref, int key)
{
    Node* temp= *head_ref;
    Node* prev= NULL;

    //If head node holds desired key, change the head and free the old head.
    if(temp!=NULL&&temp->data==key)
    {
        *head_ref=temp->next;
        delete temp;
        return;
    }
    //search for the key to be deleted. Keep track of previous node as we need to change 'prev->next'
    else{
    while(temp!=NULL&&temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    //if key is not found
    if(temp==NULL)
    {
        return;
    }
    prev->next=temp->next;
    delete temp;
}
}
void deleteList(Node**head_ref)
{
    Node* current=*head_ref;
    Node* next= NULL;

    while(current!=NULL)
    {
        next=current->next;
        free(current);
        current=next;
    }
    *head_ref=NULL;
}

int main()
{
    //create a list with three nodes
    Node* head = NULL;
    Node* sorted = NULL;
   

    //allocate 3 nodes to the heap
    head = new Node();
    sorted = new Node();

    //assign data to desired input
    //link node to next node
    cout<<endl<<"--Welcome to linked list thingy--"<<endl;
    cout<<"Enter an integer to begin the linked list: "<<endl;
    int start;
    cin>>start;

    head->data=start;
    head->next=NULL;

    cout<<"Thank you\n";

    char choice;

    while (choice != 'Q'||choice !='Q')
    {
        cout<<"--Please choose from the selections bellow--"<<endl;
        cout<<"Press U to push an integer to front of list"<<endl;
        cout<<"Press A to append an integer to end of list"<<endl;
        cout<<"Press S to sort insert an integer to the list"<<endl;
        cout<<"Press D to delete an integer from the list"<<endl;
        cout<<"Press L to delete the entire list"<<endl;
        cout<<"Press Q to quit program"<<endl;
        cout<<"--------------------------------------------"<<endl;
        cout<<"Your choice: ";
        cin>>choice;
        cout<<endl;

    
        if(choice == 'U'||choice=='u')
        {
            int pushi;
            cout<<"Enter integer to push: ";
            cin>>pushi;
            push(&head,pushi);
            printList(head);
        }
        else if(choice=='A'||choice=='a')
        {
            int appendi;
            cout<<"Enter integer to append: ";
            cin>>appendi;
            append(&head, appendi);
            printList(head);
        }
        else if(choice=='S'||choice=='s')
        {
            int sorti;
            cout<<"Enter integer to sort insert: ";
            cin>>sorti;
            sortedInsert(&head,sorti);
            printList(head);
        }
        else if (choice=='D'||choice =='d')
        {
            int deleti;
            cout<<"Enter integer to delete: ";
            cin>>deleti;
            deleteNode(&head, deleti);
            printList(head);
        }
        else if(choice=='L'||choice=='l')
        {
            deleteList(&head);
            printList(head);
        }
        else if(choice=='Q'||choice=='q')
        {
            cout<<endl<<"---------"<<endl<<"Good bye!!"<<endl<<"---------"<<endl;
            sleep(3);
            break;
            
        }
        else
        {
            int random;
            srand(time(NULL));
            random=rand()%10+1;
     
            if(random%2==0)
            {
                cout<<"Are you blind?!? Pick one of the options, dummy."<<endl<<endl;
            }
            else if(random==9||random==7)
            {
                cout<<"Should we do any eye exam instead?"<<endl<<endl;
            }
            else if(random==3||random==5||random==1)
            {
                cout<<"Your reading is getting a lot better. Try again >:("<<endl<<endl;
            }

        }
    }
 
    return 0;
}