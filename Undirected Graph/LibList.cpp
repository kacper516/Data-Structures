#include "LibList.hpp"

void List::f_add_back(List *vertex_number, int value)
{
	if (head == nullptr)
	{
		head = new MainList;
		head->value = value;  // specific number of vert
		head->next = nullptr; // at this moment it's nullptr
	}
	else
	{
		MainList *temp = head;
		MainList *new_node = new MainList;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		new_node->value = value;
		new_node->next = nullptr;
		temp->next = new_node;
	}
}

void List::f_show_list()
{
	while (head != nullptr)
	{
		std::cout << (head->value) + 1 << " "; // +1 becouse verts starts from 1 not 0
		head = head->next;
	}
	std::cout << std::endl;
}

void List::f_fill_list(List *vertex, int **array2d, int max)
{
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			if (array2d[i][j] == 1)
			{
				vertex[i].f_add_back(vertex, j);
			}
		}
	}
}

int *f_fill_array_degree(List *vertex, int **array2d, int max)
{
	int *vertex_degree = new int[int(max)]{};
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			if (array2d[i][j] == 1)
			{
				vertex_degree[i] += 1;
			}
		}
	}
	return vertex_degree;
}

void f_show_info(List *vertex, int *array_degree, int max)
{
	for (int i = 0; i < max; i++)
	{
		std::cout << "Neighbourhood for v=" << i + 1 << " ";
		vertex[i].f_show_list();
	}
	std::cout << std::endl;
	for (int i = 0; i < max; i++)
	{
		std::cout << "Degree for v=" << i + 1 << " ";
		std::cout << array_degree[i];
		std::cout << std::endl;
	}
}