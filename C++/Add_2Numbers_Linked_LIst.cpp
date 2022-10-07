// Problem Link :https://leetcode.com/problems/add-two-numbers
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* tmp=new ListNode();
        ListNode* res=tmp;
        int c=0;
        while(l1!=NULL || l2!=NULL || c==1)
        {
            int s=0;
            if(l1!=NULL)
            {
                s+=l1->val;
                l1=l1->next;
            } 
            if(l2!=NULL)
            {
                s+=l2->val;
                l2=l2->next;
            }
            s+=c;
            res->next=new ListNode(s%10);
            c=s/10;
            res=res->next;
        }
        return tmp->next;
        
    }
};
