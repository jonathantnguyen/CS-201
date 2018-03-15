#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void display_all_ir(olympic_info * & head);

void display_all_rec(olympic_info * & head, olympic_info * & current);

int main(olympic_info * & head)
{
	if(!head)
		return 0;

	olympic_info * current = NULL;
	current = head;
	display_all_rec(head, current);

}

olympic_info * head = oly_list[0];

int display_all_rec(olympic_info * & head, olympic_info * & current)
{
	if(current == NULL)
		return 0;

	cout << "Name: " << current->name << endl;
	cout << "Nationality: " << current->nationality << endl;
	cout << "Sport: " << current->sport << endl;

	return 1 + display_all_rec(head, current->next);

}


int display_all_ir()
{
	int i = 0;
	while(!current)
	{
		cout << "Name: " << current->name << endl;
		cout << "Nationality: " << current->nationality << endl;
		cout << "Sport: " << current->sport << endl;

		current = current->next;
		i++;
	}

	return i;
}



int add()
{
	if(!head)
		return 0;


	while(current->next != NULL)
	{
		if (strcmp(key[],olympic_info->sport) == 0)
		{
			cout << 
		}
		current = current->next;
	}

	node * temp = new temp;

	current->next = new temp;
	temp->next = NULL;
}

int add_rec(node * & head, node * & current)
{
	if(current->next == NULL)
	{
		node * temp = new temp;
		current->next = new temp;
		temp->next = NULL;
		return 0;
	}

	add_rec(head, current->next);

if (strcmp(key[],olympic_info->sport) == 0)
}



