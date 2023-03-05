#include "LibException.cpp"
#include "LibHuffman.cpp"
#include "Tree.cpp"

int main()
{
	try
	{
		std::priority_queue<Node, std::vector<Node>, Queue> que;
		int data;

		std::cout << "Choose case you want:\n"
				  << "1 - frequency case.\n"
				  << "2 - probability case.\n"
				  << std::endl;
		std::cin >> data;

		if (data != 1 and data != 2)
		{
			system("cls");
			throw EXCEPTIONS::InvalidArguments();
			exit(0);
		}
		system("cls");

		switch (data)
		{
		case 1:
		{
			// hardcoded frequency case
			std::vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'f'};
			std::vector<int> freq = {16, 5, 12, 17, 10, 25};

			for (int i = 0; i < letters.size(); i++)
			{
				Node temp(letters[i], freq[i]);

				// sort from the smallest to the largest (index 0 -> index max)
				que.push(temp);
			}

			/*
			* Test of priority queue
			while (!que.empty()) {
				Node temp = que.top();
				std::cout << temp.int_value << " ";
				que.pop();
			}
			*/

			break;
		}
		case 2:
		{
			// hardcoded probability test
			std::vector<char> letters = {'c', 'e', 'i', 'r', 's', 't', 'x'};
			std::vector<double> probability = {0.11, 0.22, 0.16, 0.12, 0.15, 0.10, 0.14};

			for (int i = 0; i < letters.size(); i++)
			{
				Node temp(letters[i], probability[i]);

				// sort from the smallest to the largest (index 0 -> index max)
				que.push(temp);
			}

			/*
			* Test of priority queue
			while (!que.empty()) {
				Node temp = que.top();
				std::cout << temp.int_value << " ";
				que.pop();
			}
			*/

			break;
		}
		}

		f_huffman(que, data);
	}
	catch (std::runtime_error &error)
	{
		std::cerr << error.what();
	}
}