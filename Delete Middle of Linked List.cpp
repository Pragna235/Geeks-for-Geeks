//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
class Solution {
  public:
    int lengthList(Node* head){
        int cnt=0;
        Node* temp = head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    Node* deleteMid(Node* head) {
        // Your Code Here
        if(head == NULL || head->next == NULL) return NULL;
        int n = lengthList(head);
        int del = (n/2) + 1;
        int cnt=0;
        Node* temp = head;
        Node* prev=NULL;
        while(temp){
            cnt++;
            if(cnt==del){
                prev->next = temp->next;
                free(temp);
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
        
    }
};

//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

int main() {
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
        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution obj;
        head = obj.deleteMid(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
