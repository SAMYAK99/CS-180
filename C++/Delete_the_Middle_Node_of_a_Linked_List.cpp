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
    int count(ListNode* head){
        int ans=0;
        while(head!=NULL){
            ans++;
            head=head->next;
        }
        return ans;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL){
            return NULL;
        }
        ListNode*temp=head;
        ListNode*temp1=head;
        int t=count(head)/2;
        while(t>0){
            // if(temp->next==NULL){
            //     break;
            // }
            if(t>1)
            temp=temp->next;

            temp1=temp1->next;
            t--;
        }
        temp->next=temp1->next;
        delete temp1;
        return head;
    }
};
