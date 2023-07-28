//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* zeroH = NULL;
        Node* zeroT = NULL;
        Node* oneH = NULL;
        Node* oneT = NULL;
        Node* twoH = NULL;
        Node* twoT = NULL;
        
        Node* curr = head;
        if(!head -> next){
            return head;
        }
        while(curr){
            Node* temp = curr -> next;
            if(curr -> data == 0){
                if(zeroH == NULL){
                    zeroH = curr;
                    zeroT = curr;
                }else{
                    zeroT -> next = curr;
                    zeroT = zeroT -> next;
                }
            }else if(curr -> data == 1){
                if(oneH == NULL){
                    oneH = curr;
                    oneT = curr;
                }else{
                    oneT -> next = curr;
                    oneT = oneT -> next;
                }
            }else{
                if(twoH == NULL){
                    twoH = curr;
                    twoT = curr;
                }else{
                    twoT -> next = curr;
                    twoT = twoT -> next;
                }
            }
            curr -> next = NULL;
            curr = temp;
        }
        Node* ans;
        if(zeroH != NULL){
            ans = zeroH;
            if(oneH != NULL){
                zeroT -> next = oneH;
                oneT -> next = twoH;
            }else{
                zeroT -> next = twoH;
            }
        }else if(oneH != NULL){
            ans = oneH;
            oneT -> next = twoH;
        }else{
            ans = twoH;
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends