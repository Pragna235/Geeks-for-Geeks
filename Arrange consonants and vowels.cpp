//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        // Code here
        Node *vowel = NULL, *consonant = NULL, *start = NULL,
         *end = NULL;
    while (head != NULL) {
        char x = head->data;
        // Checking the current node data is vowel or
        // not
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o'
            || x == 'u') {
            if (!vowel) {
                vowel = new Node(x);
                start = vowel;
            }
            else {
                vowel->next = new Node(x);
                vowel = vowel->next;
            }
        }
        else {
            if (!consonant) {
                consonant = new Node(x);
                end = consonant;
            }
            else {
                consonant->next = new Node(x);
                consonant = consonant->next;
            }
        }
        head = head->next;
    }
    // In case when there is no vowel in the incoming LL
    // then we have to return the head of the consonant LL
    if (start == NULL)
        return end;
    // Connecting the vowel and consonant LL
    vowel->next = end;
    return start;
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends
