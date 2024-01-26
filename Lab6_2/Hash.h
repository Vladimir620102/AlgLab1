#pragma once
#include <string>

using namespace std;

struct Node
{
	string value;
	Node* next;
	Node* prev;
	Node* get_next() { return next; }
	Node* get_prev() { return prev; }

	Node(Node* prev_node, Node* next_node, string str_node) {
		next = next_node;
		prev = prev_node;
		value = str_node;
	}
	
};

struct cell {
	int key;
	string value;
};

struct h_table
{
	Node* head;
	h_table()
	{
		head = NULL;
	};
	Node* getFirst()
	{
		return head;
	};
	Node* getLast();
	Node* search(string data);
	bool insert(string data);
	bool deleteByNode(Node* node);
	bool deleteByData(string data);
	void scan();
};
h_table* create();
