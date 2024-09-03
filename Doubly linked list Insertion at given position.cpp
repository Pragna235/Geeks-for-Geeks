//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* a Node of the doubly linked list */
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x)
  {
      data = x;
      next = prev = NULL;
  }
};

void addNode(Node *head, int pos, int data);

Node *insert(Node *head, int x)
{
    if (head == NULL)
    {
        return new Node(x);
    }
    Node *n = new Node(x);
    
    head->next = n;
    n->prev = head;
    head = n;
    return head;
}

void printList(Node *head)
{
  // The purpose of below two loops is
  // to test the created DLL
  Node *temp=head;
  if (temp != NULL) {
    int ct1=0,ct2=0;
  while (temp->next!=NULL)
    temp=temp->next,ct1++;
  while (temp->prev!=NULL)
   temp = temp->prev,ct2++;
   if(ct1!=ct2){
       cout<<-1<<"\n";
       return;
   }
  }
  while (temp != NULL)
  {
      printf("%d ",temp->data);
      temp=temp->next;
  }
  
  cout << endl;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
  Node *head = NULL; 
  Node *root = NULL;
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
     int x;
     scanf("%d",&x);
     head = insert(head, x);
     if(root==NULL) root = head;
  }     
  head = root;
  int pos,data;
  cin>>pos>>data;
  addNode(head, pos, data);
  printList(head);
  }
  return 0;
}
// } Driver Code Ends


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

//Function to insert a new node at given position in doubly linked list.

Node* insertAfterTail(Node* head, int data){
    if(head==NULL){
        Node* temp = new Node(data);
        return temp;
    }
    Node* tail = head;
    while(tail->next){
        tail=tail->next;
    }
    Node* temp = new Node(data);
    temp->prev = tail;
    temp->next = nullptr;
    tail->next = temp;
    return head;
}
void addNode(Node *head, int pos, int data)
{
   // Your code here
   Node* temp = head;
   int cnt=-1;

   while(temp){
       cnt++;
       if(cnt==pos){
           break;
       }
       temp=temp->next;
   }
   
   
   if(temp->next == NULL){
       head = insertAfterTail(head,data);
       return;
   }
   
   
   
   Node* newNode = new Node(data);
   Node* front = temp->next;
   newNode->prev = temp;
   newNode->next = front;
   temp->next = newNode;
   front->prev = newNode;
   //return head;
}
