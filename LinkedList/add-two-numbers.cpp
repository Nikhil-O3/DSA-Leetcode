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
        int carry=0;
        ListNode dummy(0);
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        ListNode *res=&dummy;

        while(temp1 && temp2)
        {

            int curr=carry+temp1->val + temp2->val ;
            carry=curr>9 ? 1 :0;

            ListNode *newnode=new ListNode(curr%10);
            res->next=newnode;res=newnode;

            temp1=temp1->next;temp2=temp2->next;

        }

        while(temp1)
        {
            int curr=carry+temp1->val;
            carry=curr>9 ? 1 :0;

            ListNode *newnode=new ListNode(curr%10);
            res->next=newnode;res=newnode;

            temp1=temp1->next;
            
        }

        while(temp2)
        {
            int curr=carry+temp2->val;
            carry=curr>9 ? 1 :0;

            ListNode *newnode=new ListNode(curr%10);
            res->next=newnode;res=newnode;

            temp2=temp2->next;
        }

        if(carry)
        {
             ListNode *newnode=new ListNode(1);
            res->next=newnode;
        }

        return dummy.next;
    }
};