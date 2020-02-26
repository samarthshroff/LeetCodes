#pragma once

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    
};

class Merge2SortedLinkedLists
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

