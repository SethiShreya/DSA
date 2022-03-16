#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
       
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head= new ListNode();
        ListNode* total= head;
        int c=0;
        // below while loop exit if l1 == Null, l2==Null and c==0
        // here c is important as for last node 7+8=15 if c is not included it will only display 1 and not 5
        while (l1!=NULL || l2!= NULL || c){
            // total->val=0;
            int sum=0;
            // adding all the l1 values in sum 
            if (l1!=NULL){
                sum+=l1->val;
                l1= l1->next;
            }
            // adding all the l2 values in sum
            if (l2!=NULL){
                sum+=l2->val;
                l2= l2->next;
            }
            sum+=c;
            c =  sum/10;
            ListNode* node= new ListNode(sum%10);
            total->next= node;
            total= total->next;
    }
    return head->next;
    }
};

int main(){
    int i,n;
    cout<<"How many nodes you want to create: ";
    cin>>n;
    ListNode* a_head= NULL;
    ListNode* b_head= NULL;
    ListNode* temp1= NULL;
    ListNode* temp2= NULL;
    
    for (int i=0; i<n; i++){
        ListNode* a= new ListNode();
        ListNode* b= new ListNode();
        int n1, n2;
        cout<<"\nEnter value of 1st node: ";
        cin>>n1;
        cout<<"\nEnter value of 2nd node: ";
        cin>>n2;
        // make a head node if head is null
        if (a_head==NULL && b_head==NULL){
            a_head= a;
            b_head= b;
            a_head->val= n1;
            b_head->val= n2;
            a_head->next= NULL;
            b_head->next= NULL;
            temp1= a_head;
            temp2= b_head;
        }
        // make other nodes and attach to head
        else{    
            a->val= n1;
            b->val= n2;
            temp1->next = a;
            temp2->next = b;
            temp1=a;
            temp2=b;
        }
        
    }
        Solution sol;
        ListNode* total= sol.addTwoNumbers(a_head, b_head);
        while(total!=NULL){
            cout<<total->val<<' ';
            total= total->next;
        }
    

    return (0);
}