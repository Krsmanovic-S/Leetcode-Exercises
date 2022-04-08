#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == headB) return headA;
    
    ListNode* temp = headB;
    
    // Loop that moves temp one by one, when it reaches NULL it
    // will reset temp to headB, move headA by one space and
    // repeat the whole process
    while(headA != NULL)
    {
        if(headA == temp) return temp;
        
        temp = temp->next;
        
        if(!temp)
        {
            headA = headA->next;
            temp = headB;
        }
    }
    return NULL;
}

int main()
{
    return 0;
}