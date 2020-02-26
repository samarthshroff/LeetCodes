#pragma once


struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Add2NumbersFromLinkedList
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);    

private:
    int add(int x, int y);
};

