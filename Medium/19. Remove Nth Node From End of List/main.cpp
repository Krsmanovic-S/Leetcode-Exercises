#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head->next == NULL) return NULL;
    
    int sizeOfList = 0;
    ListNode* temp = head;
    
    // This is to get the size of the list,
    // which we will use to locate the removal position
    while (temp != NULL)
    {
        sizeOfList++;
        temp = temp->next;
    }
    
    // Calculate the position at which we will remove the Node
    int remove = sizeOfList - n + 1;
    
    ListNode* prev;
    ListNode* current = head;
    for(int i = 1; i < remove; i++)
    {
        prev = current;
        current = current->next;
    }
    
    if(prev != NULL)
    {
        prev->next = current->next;
        delete current;
    }
    else
    {
        // This means the head needs to be removed
        // so the 2nd Node becomes the new head
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    return head;
}

int main()
{
    return 0;
}