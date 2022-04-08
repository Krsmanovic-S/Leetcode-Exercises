#include <iostream>
#include <string>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    string s1, s2;
    
    // Two loops to extract the digits from each list and put them
    // in strings s1 and s2.
    while(l1 != NULL)
    {
        s1 += to_string(l1->val);
        l1 = l1->next;
    }
    while(l2 != NULL)
    {
        s2 += to_string(l2->val);
        l2 = l2->next;
    }
    
    // Now we have s1 and s2 in reverse, now we need to add them to string result.
    // We have to use strings here due to large numbers which we can't represent
    // even with unsigned long long!
    string result;
    unsigned char carry = 0;

    // Make sure s1 is the smaller one first
    if(s1.length() > s2.length())
        swap(s1, s2);
    
    // First we add the smaller strings values to the bigger one.
    for (int i=0; i< s1.size(); i++)
    {
        int sum = ((s1[i] - '0') + (s2[i] - '0') + carry);
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Then we add all remaining digits of the larger string.
    for (int i= s1.size(); i< s2.size(); i++)
    {
        int sum = ((s2[i] - '0') + carry);
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    
    // Add remaining carry at the end if we have it.
    if(carry)
        result.push_back(carry + '0');

    ListNode* head = NULL;
    ListNode* tail = NULL;
    
    // Check for zero itself.
    unsigned int result_size = result.size() - 1;
    if(result.empty() || result[result_size] == '0')
    {
        head = new ListNode(0);
        return head;
    }
    
    // Loop that goes digit-by-digit from result (starting on the right side, meaning lowest digit),
    // it will create a new node with the digit value and then do a simple append method to the list.
    unsigned char digit;
    while(!result.empty())
    {
        digit = result[0] - '0';
        
        ListNode* temp = new ListNode(digit);

        if(head == NULL)
                head = temp, tail = temp;               
        else 
            tail->next = temp, tail = temp;
        
        result.erase(result.begin() + 0);
        
        // Don't leak memory! Reset temp first then delete it.
        temp = NULL;
        delete temp;
    }
    return head;
}

int main()
{
    return 0;
}