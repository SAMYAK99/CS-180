/*
Link to the problem - https://leetcode.com/problems/merge-k-sorted-lists/

Problem Description-
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

*/

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
    // This function merges two sorted linked-lists into one sorted linked-list
    ListNode*merge(ListNode*a, ListNode*b){
        if(a==NULL) return b;
        if(b==NULL) return a;
        if(a->val<b->val){
            a->next=merge(a->next,b);
            return a;
        }else{
            b->next=merge(a,b->next);
            return b;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(lists.size()==0) return NULL;
        /* We traverse over the array of linked-list, everytime we remove two lists from the beginning of the array,
        merge them and push the merged list at the end of the array. Repeat this until we are left with only 1 list */
        while(lists.size()>1){
            lists.push_back(merge(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }
};


/*
Time Complexity: O(k * N) where k is the number of lists and N is the maximum number of elements in the list
since merging two sorted lists takes O(N) time and we do it for k lists here.  

Space Complexity: O(1) since we do not use any extra space here.

*/
