void delete_node(node * head, node * current)
{
	if(current->next->next == NULL)
	{
		delete(current->next);
		current->next = NULL;
		return;
	}

	delete_node(head, current->next);
}


void delete_last(node * head)
{
	if(!head)
		return;

	node * current = head;
	delete_node(head, current);

	return;
}