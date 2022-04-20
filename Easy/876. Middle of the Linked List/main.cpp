// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    int listSize = 0, middlePos;
    ListNode* temp = head;
    
    // Get the size of the list.
    while(temp)
    {
        listSize++;
        temp = temp->next;
    }
    
    // This is the middle of our list.
    middlePos = listSize / 2;
    
    // A while loop will guarantee we return
    // the correct elements (in cases of both
    // odd and even sized lists).
    temp = head;
    while(middlePos)
    {
        middlePos--;
        temp = temp->next;
    }
    
    return temp;
}

int main()
{
    return 0;
}