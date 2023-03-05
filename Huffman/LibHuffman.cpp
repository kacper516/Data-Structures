#include "LibHuffman.hpp"

void f_fill_values(Node *node)
{
	if (node->left != nullptr)
	{
		Node *temp = new Node('n', 0);
		temp = node->left;
		temp->label = 0;

		// if we can't go to the left side we need to return to previous node and check if we can go to the right side
		f_fill_values(temp);
		temp = node->right;
		temp->label = 1;
		f_fill_values(temp);
	}
}

void f_huffman(std::priority_queue<Node, std::vector<Node>, Queue> tree, int data)
{
	while (tree.size() > 1)
	{
		try
		{
			// we take to node elment with the lowest frequency
			Node *t1 = new Node('n', 0);
			*t1 = tree.top();
			tree.pop();

			// we take to node next element with the lowest frequency
			Node *t2 = new Node('n', 0);
			*t2 = tree.top();
			tree.pop();

			Node *tempnode = nullptr;

			// in case of frequency or probability it'll be int (frequency) or double value (probability)
			if (data == 1)
			{
				tempnode = new Node('n', t1->int_value + t2->int_value);
			}
			else
			{
				tempnode = new Node('n', t1->double_value + t2->double_value);
			}

			// on the left side we set value with lower probability beetwen this 2, on the right side with bigger
			tempnode->left = t1;
			tempnode->right = t2;
			t1->root = tempnode;
			t2->root = tempnode;
			tree.push(*tempnode);
		}
		catch (std::runtime_error &error)
		{
			std::cerr << error.what();
			exit(1);
		}
	}

	Node *returning = new Node('n', 0);
	*returning = tree.top();
	f_fill_values(returning);
	std::string text;
	f_show_result(returning, text);
}

void f_show_result(Node *start, std::string code_value)
{
	// we need to create there new node in case it will be visible in second if
	Node *temp = start;
	std::string text_0_1 = code_value;

	if (start->left != nullptr)
	{
		temp = start->left;
		text_0_1 += std::to_string(temp->label);

		// it means that start is going to be temp in this call and text_0_1 code_value that is, their values are rewritten in the next circulation
		f_show_result(temp, text_0_1);
		text_0_1.pop_back();
		temp = start->right;
		text_0_1 += std::to_string(temp->label);
		f_show_result(temp, text_0_1);
	}

	if (start->left == nullptr)
	{
		std::cout << temp->sign << " = " << text_0_1 << std::endl;
	}
}