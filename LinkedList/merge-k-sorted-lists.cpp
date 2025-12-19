class Solution {
public:
    struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min-heap
    }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return nullptr;

        priority_queue< ListNode*, vector<ListNode*>, cmp> pq;
        ListNode dummy(0);
        ListNode *temp=&dummy;
        
        //-------------------
        for(auto node:lists){if(node)pq.push(node);}//only valid ones.

        while(pq.size())
        {
            ListNode* curr=pq.top();  //get top
            
            pq.pop();//remove top
            if(curr->next)pq.push(curr->next); //push the next of current removed if exits.

            temp->next=curr;temp=curr;//add node to mergedlist
        }

        //-------------------
        
        return dummy.next;
    }
};
