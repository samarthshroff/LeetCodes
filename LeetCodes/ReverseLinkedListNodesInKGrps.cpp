#include "ReverseLinkedListNodesInKGrps.h"

ReverseLinkedListNodesInKGrps::ReverseLinkedListNodesInKGrps()
{

}

ListNode* ReverseLinkedListNodesInKGrps::reverseKGroup(ListNode* head, int k)
{
	ListNode* current = head;
	ListNode* previous = nullptr;
	ListNode* next = nullptr;
	int count = 0;

	while (current != nullptr && count < k)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
		count++;
	}
	
	if (current != nullptr)
	{
		head->next = reverseKGroup(next, k);
	}
	else if (count < k && current == nullptr)
	{
		current = previous;
		previous = nullptr;

		while (current != nullptr)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
	}
	
	return previous;
}

/*	if (head == nullptr) return head;

	deque<ListNode*> q;
	ListNode* current = head;
	ListNode* tail = nullptr;

	while (current != nullptr)
	{
		int count = 0;

		while (count < k && current != nullptr)
		{
			q.push_back(current);
			current = current->next;
			count++;
		}
		if (count >= k)
		{
			head = tail = q.back();
			q.pop_back();

			while (!q.empty())
			{
				tail->next = q.back();
				tail = tail->next;
				q.pop_back();
			}
		}
		else if (count < k && current == nullptr)
		{

		}

	}*/
