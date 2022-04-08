#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<ListNode*> visitedNodes;
    
bool hasCycle(ListNode *head) {
    //                                 EXPLANATION
    // ------------------------------------------------------------------------------
    // First we check if head itself is NULL, if yes we return false (no cycle). 
    // Then we take the pointer going from the head and check if its NULL.
    
    // If it is, that means that we reached the end of the list, returns false.
    
    // If it isn't, we cross check it with the visitedNodes vector, if it matches
    // any of it's members, it means we already encountered that node and we do have
    // a cycle
    
    // No match means we just add that pointer to our vector and continue our journey
    
    // Last step is to call the function recursively with the next pointer, and go on 
    // until we either find a NULL pointer (will return FALSE) or a match in the 
    // visitedNodes vector (returns TRUE).
    
    if(head == NULL) return false;
    
    if(head->next == NULL)
        return false;
    else
    {
        for(int i = 0; i < visitedNodes.size(); i++)
        {
            if(head->next == visitedNodes[i]) return true;
        }

        visitedNodes.push_back(head->next);

        return hasCycle(head->next);
    }
}

int main()
{
    return 0;
}