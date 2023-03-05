#include "LibBackpack_rec.cpp"
#include "LibError.cpp"
#include "LibFiles.cpp"

int main()
{
	try
	{
		std::ifstream inputFile;

		int dataSets;
		int capacity;
		int element;
		int size;

		// weights
		std::vector<int> vector_weights;
		std::vector<int> vector_return;

		// hardcoded name of file input
		f_open_file_read("input.txt", inputFile);
		inputFile >> dataSets;

		if (dataSets <= 0)
			throw EXCEPTION_ERROR::Valid_variables;

		std::cout<<"Weight = "<<" . . . (in dots, we'll se weight of item we'll pack)."<<std::endl;
		while (dataSets--)
		{
			std::cout<<std::endl;
			inputFile >> capacity;
			inputFile >> size;

			if (capacity <= 0 or size <= 0)
				throw EXCEPTION_ERROR::Valid_variables;

			vector_weights.clear();
			vector_return.clear();

			for (int j = 0; j < size; j++)
			{
				if (inputFile.eof())
					break;
				inputFile >> element;
				vector_weights.push_back(element);
			}

			std::cout << capacity << " = ";
			f_backpack_recursion(vector_weights, vector_return, 0, capacity);
			if (vector_return.size() != 0)
			{
				for (int i = 0; i < vector_return.size(); i++)
				{
					std::cout << vector_return[i] << " ";
				}
			}
			else
			{
				std::cout << "There is no best package.";
			}

			std::cout << std::endl;
		}
	}
	catch (EXCEPTION_ERROR error)
	{
		f_see_error(error);
	}
}
