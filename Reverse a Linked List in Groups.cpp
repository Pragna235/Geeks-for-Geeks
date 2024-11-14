//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/*
   // Redirecting input from file
  freopen("/Users/debojyoti.mandal/expt/input.txt", "r", stdin);

  // Redirecting output to file
  freopen("/Users/debojyoti.mandal/expt/output.txt", "w", stdout);
*/

struct node {
    int data;
    struct node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

struct node* getKthNode(struct node* temp, int k){
    k-=1;
    while(temp && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}
struct node* reverse(struct node* head){
    if(!head || !head->next) return head;
    struct node* newHead = reverse(head->next);
    struct node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

class Solution {
  public:
    struct node *reverseIt(struct node *head, int k) {
        // Complete this method
        struct node* temp = head;
        struct node* prevNode = NULL;
        while(temp){
            struct node* kthNode = getKthNode(temp, k);
            if(kthNode==NULL){
                if(temp)kthNode = reverse(temp);
                if(prevNode)prevNode->next = kthNode;
                break;
            }
            struct node* nextNode = kthNode->next;
            kthNode->next = NULL;
            kthNode = reverse(temp);
            
            if(temp==head){
                head=kthNode;
            }
            else{
                prevNode->next = kthNode;
            }
            
            prevNode = temp;
            temp=nextNode;
        }
        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        node* head = new node(data);
        node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return (0);
}

// } Driver Code Ends
