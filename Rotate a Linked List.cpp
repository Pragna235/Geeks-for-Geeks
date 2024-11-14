//{ Driver Code Starts
// Initial Template for C++
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

void printList(Node* node) {
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
Node* getKthNode(Node* temp, int k){
    k-=1;
    while(temp && k>0){
        k--;
        temp = temp->next;
    }
    return temp;
}
class Solution {
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        // Your code here
        Node* temp = head;
        Node* tail = head;
        int len = 1; 
        if(!head || !head->next) return head;
        while(tail->next){
            tail = tail->next;
            len++;
        }
        if(k%len==0) return head;
        k = k%len;
        
        Node* kthNode = getKthNode(temp,k) ;
        tail->next = head;
        head = kthNode->next;
        kthNode->next = NULL;
        
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

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends
