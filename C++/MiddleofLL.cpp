ListNode* middleNode(ListNode* head) {
        int tot = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            tot++;
            temp = temp -> next;
        }
        int cnt = 0, mid = tot/2;
        mid++;
        while(head != NULL)
        {
            cnt++;
            if(cnt == mid)
            {
                break;
            }
            else
                head = head -> next;
        }
        return head;
    }
