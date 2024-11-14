//{ Driver Code Starts
#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->random == NULL)
            k = -1;
        else
            k = temp->random->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}

void append(Node **head_ref, Node **tail_ref, int new_data) {
    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*tail_ref)->next = new_node;
    }
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {
    Node *temp1 = head;
    Node *temp2 = res;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data)
            return false;
        if ((temp1->random == NULL && temp2->random != NULL) ||
            (temp1->random != NULL && temp2->random == NULL) ||
            (temp1->random != NULL && temp2->random != NULL &&
             temp1->random->data != temp2->random->data))
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}


// } Driver Code Ends
/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
void insertCopyInBetween(Node* head){
    Node* temp = head;
    while(temp != NULL){
        
        // Create a new node with the same data
        Node* copy = new Node(temp->data);  
        
        // Point the copy's next to
        // the original node's next
        copy->next = temp->next;  
        
        // Point the original
        // node's next to the copy
        temp->next = copy;         

        // Move to the next original node
        temp = temp->next->next;         
    }
}

// Function to connect random
// pointers of the copied nodes
void connectRandomPointers(Node* head){
    Node* temp = head;
    while(temp != NULL){
        // Access the copied node
        Node* copyNode = temp->next;    
        
        // If the original node
        // has a random pointer
        if(temp->random){   
             // Point the copied node's random to the
             // corresponding copied random node
            copyNode->random = temp->random->next; 
        }
        else{
             // Set the copied node's random to
             // null if the original random is null
            copyNode->random = NULL;   
        }
        
         // Move to the next original node
        temp = temp->next->next;   
    }
}

// Function to retrieve the
// deep copy of the linked list
Node* getDeepCopyList(Node* head){
    Node* temp = head;
     // Create a dummy node
    Node* dummyNode = new Node(-1);   
    // Initialize a result pointer
    Node* res = dummyNode;             

    while(temp != NULL){
        // Creating a new List by
        // pointing to copied nodes
        res->next = temp->next;
        res = res->next;

        // Disconnect and revert back to the
        // initial state of the original linked list
        temp->next = temp->next->next;
        temp = temp->next;
    }
    
     // Return the deep copy of the
     // list starting from the dummy node
    return dummyNode->next;   
}
class Solution {
public:
    Node* copyList(Node* head) {
        if(!head) return nullptr;   
    
    
    insertCopyInBetween(head); 
    
    connectRandomPointers(head);  
    
    return getDeepCopyList(head); 
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore the newline after T
    while (T--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Node *head = NULL, *tail = NULL;
        for (int i = 0; i < arr.size(); ++i) {
            append(&head, &tail, arr[i]);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> arr2;
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Node *temp = head;
        for (int i = 0; i < arr2.size(); i += 2) {
            int a = arr2[i];
            int b = arr2[i + 1];

            Node *tempA = head;
            Node *tempB = head;
            for (int j = 1; j < a; ++j) {
                tempA = tempA->next;
            }
            for (int j = 1; j < b; ++j) {
                tempB = tempB->next;
            }

            tempA->random = tempB;
        }

        Solution ob;
        Node *res = ob.copyList(head);
        if (!res or res == head) {
            cout << "false" << endl;
            continue;
        }
        if (validation(head, res)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
