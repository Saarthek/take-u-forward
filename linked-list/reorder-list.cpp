/*
This code is a solution of the problem Reorder List from LeetCode at the link
https://leetcode.com/problems/reorder-list/description/
The solution progresses from the array-based approach to the optimal in-place approach
Input:
    n -> Size of the linked list
    val[0] val[1] ... val[n-1] -> values of the linked list nodes in order
Output:
    The linked list reordered in place as L0, Ln, L1, Ln-1, L2, Ln-2, ...
*/

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    //Array Based Approach
    /*public:
    void reorderList(ListNode* head) {
        vector<ListNode*> arr;
        ListNode* curr = head;
        while(curr){
            arr.push_back(curr);
            curr = curr->next;
        }
        int n = arr.size();
        int i = 1;
        int j = n-1;
        curr = head;
        while(i<=j){
            curr -> next = arr[j--];
            curr = curr->next;
            curr->next = arr[i++];
            curr = curr->next;
        }
        curr->next = NULL;
    }
    //Time Complexity -> O(n)
    //Space Complexity -> O(n)
    */
    //Optimal In-Place Approach
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
private:
    ListNode* recReverseList(ListNode* curr, ListNode* next){
        if(next==NULL){
            return curr;
        }
        ListNode* tmpnxt = next->next;
        next->next = curr;
        return recReverseList(next, tmpnxt);
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        return recReverseList(NULL, head);
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
            if(!fast || !fast->next){
                return slow;
            }
            fast = fast -> next;
        }
        return slow;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* mid = middleNode(head);
        if(!mid){
            return;
        }
        ListNode* h1 = head;
        ListNode* h2 = mid;
        h2 = reverseList(mid);
        while(h1!=mid&&h2!=NULL){
            ListNode* nh1 = h1->next;
            ListNode* nh2 = h2->next;
            h1->next = h2;
            h2->next = nh1;
            h1 = nh1;
            h2 = nh2;
        }
        h1->next=NULL;
        //return head;
    }
//Time Complexity -> O(n)
//Space Complexity -> O(n)
};

ListNode* build(vector<int>& v){
    ListNode* dummy = new ListNode(0);
    ListNode* c = dummy;
    for(int x : v){ c->next = new ListNode(x); c = c->next; }
    return dummy->next;
}

void printList(ListNode* h){
    while(h){ cout << h->val << " "; h = h->next; }
    cout << "\n";
}

int main(){
    Solution sol;
    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i = 0; i < n; i++){
        cin >> vals[i];
    }
    ListNode* head = build(vals);
    sol.reorderList(head);
    printList(head);
    return 0;
}