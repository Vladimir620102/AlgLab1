#include "Hash.h"

bool h_table::insert(string data)
{
	bool rc = NULL;
	if (head == NULL)
		head = new Node(NULL, head, data);
	else
		head = (head->prev = new Node(NULL, head, data));
	return rc;
}

Node* h_table::search(string data)
{
	Node* rc = head;
	//while ((rc != NULL) && (rc->value
	//	//	((((cell*)rc->value)->key) != ((AAA*)data)->key))
	//	rc = rc->next;
	return rc;
}
