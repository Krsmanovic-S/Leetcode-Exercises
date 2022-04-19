#include <iostream>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;
    
    ListNode* mergedList = list1;
    
    // First node.
    if(list1->val < list2->val)
    {
        mergedList = list1;
        list1 = list1->next;
    }
    else
    {
        mergedList = list2;
        list2 = list2->next;
    }
    
    ListNode* current = mergedList;
    
    // Go until both lists have remaining elements.
    while(list1 && list2)
    {
        if(list1->val < list2->val)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    
    // Last elements if lists arent equal lenght.
    if(!list1)
        current->next = list2;
    else
        current->next = list1;
        
    return mergedList;
}

int main()
{
    return 0;
}