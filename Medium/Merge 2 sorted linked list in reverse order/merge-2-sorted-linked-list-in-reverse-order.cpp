//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    private:
    void reverse(Node** head){
        Node* cur = *head, *prev = nullptr, *N;
        while(cur){
            N = cur->next;
            cur->next = prev;
            prev = cur;
            cur = N;
        }
        *head = prev;
    }
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        // jai ganesh
        
        reverse(&node1);reverse(&node2);
        if(node1 == nullptr) return node2;
        if(node2 == nullptr) return node1;
        if(node2 == nullptr) return node1;
        Node* head , *cur;
        if(node1->data >= node2->data){
            head = cur = node1;
            node1 = node1->next;
        }
        else{
            head=cur=node2;
            node2 = node2->next;
        }
        while(node1 && node2){
            if(node1->data >= node2->data){
                cur->next = node1;
                cur = cur->next;
                node1 = node1->next;
            }
            else{
                cur->next = node2;
                cur = cur->next;
                node2 = node2->next;
            }
        }
        while(node1){
            cur->next = node1;
            cur = cur->next;
            node1 = node1->next;
        }
        while(node2){
            cur->next = node2;
            cur = cur->next;
            node2 = node2->next;
        }
        
        return head;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends