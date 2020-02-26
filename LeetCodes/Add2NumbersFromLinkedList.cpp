#include "Add2NumbersFromLinkedList.h"


int Add2NumbersFromLinkedList::add(int x, int y)
{
    while (y != 0)
    {
        int carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}

ListNode* Add2NumbersFromLinkedList::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* root = l1;
    ListNode* prev = nullptr;
    int carryBit = 0;

    //simply add the numbers and move the prev node. by the end of this loop
    //prev will point the tail
    while (l1 != nullptr && l2 != nullptr)
    {
        l1->val = add(l1->val, l2->val);

        prev = l1;
        l1 = l1->next;
        l2 = l2->next;
    }

    //add any remaining numbers from l2 (if l2 list has more elements than l1)
    if (prev->next == nullptr && l2 != nullptr)
    {
        prev->next = l2;
    }

    //let this list point to the head of l1
    ListNode* finalRoot = root;

    //time to add carry bits
    while (root != nullptr)
    {
        root->val = add(root->val, carryBit);

        //dividing a number with 10 will give us the quotient which is technically the
        //carry bit number
        carryBit = root->val / 10;
        //if there is a carry bit it means that the number in root->val is a double digit number
        //so % it with 10 to get the digit at unit place and store it
        if (carryBit != 0) root->val = root->val % 10;

        prev = root;
        root = root->next;
    }

    //for the last digit carry bit to be added at the end of the list
    if (carryBit != 0)
    {
        prev->next = new ListNode(carryBit);
    }

    return finalRoot;
}