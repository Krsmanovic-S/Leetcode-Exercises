#include <vector>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

void reorderList(ListNode* head) {
    // Early return case.
    if(!head->next || !head->next->next)
        return;
        
    std::vector<int> numValues;
    ListNode* temp = head;
    
    // Traverse the list and get all the
    // values into a vector to hold it.
    while(temp)
    {
        numValues.push_back(temp->val);
        temp = temp->next;
    }
    temp = head;
    
    // Variables for reordering the list,
    // keep track of the left/right index 
    // and a swap boolian so we alternate  
    // in correct order.
    int left = 0, right = numValues.size() - 1;
    bool swapSide = false;
    
    while(left <= right)
    {
        // Swap sides each iteration, first take
        // from the left side, then the right side.
        if(!swapSide)
        {
            temp->val = numValues[left];
            left++;
        }
        else
        {
            temp->val = numValues[right];
            right--;
        }
        swapSide = !swapSide; 
        temp = temp->next;
    }
}