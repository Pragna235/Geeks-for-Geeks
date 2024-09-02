//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to insert a node in the middle of the linked list.
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
    Node *insertInMiddle(Node *head, int x) {
        if(head==NULL){
            Node* temp = new Node(x);
            return temp;
        }
        // Code Here
        int n = lengthList(head);
        n = (n+1)/2;
        int cnt=0;
        Node* temp = head;
        while(temp){
            cnt++;
            if(cnt==n){
                Node* n = new Node(x);
                n->next = temp->next;
                temp->next = n;
            }
            temp=temp->next;
        }
        return head;
        
    }
};

//{ Driver Code Starts.

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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int x;
        cin >> x;
        cin.ignore();

        Node *head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        Solution ob;
        Node *ans = ob.insertInMiddle(head, x);
        printList(ans);
    }

    return 0;
}
// } Driver Code Ends
