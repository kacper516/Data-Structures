#include "kadane_alg.hpp"

int **create_arr(int row, int col)
{
    int **array_2d = new int *[row];
    int numb;
    for (int i = 0; i < row; i++)
    {
        try
        {
            array_2d[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                std::cin >> numb; // user can write his own numbers
                array_2d[i][j] = numb;
            }
        }
        catch (const std::exception &)
        {
            exit(0);
        }
    }
    return array_2d; // zwracany jest adres do tej tablicy
}

void current_max(int **arr, int row, int col)
{
    // current max sum of elements, new max
    int current_max{}, new_max{};

    // in this array we will write sum of columns
    int *new_arr_1d = new int[col]{};

    // we put maximum value right now
    for (int start = 0; start < 1; start++)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // rewrite to array 1 sum of all rows and put it in right index in new array
                new_arr_1d[j] += arr[i][j];
            }
        }
        // we want to count maximum sum of submatrix
        current_max = alg_kadane(new_arr_1d, col);
    }

    for (int start = 1; start < row; start++)
    {
        for (int w = 0; w < col; w++)
            new_arr_1d[w] = 0; // we need to set 0 to every element

        for (int i = start; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                new_arr_1d[j] += arr[i][j];
            }
        }

        new_max = alg_kadane(new_arr_1d, col);

        if (current_max < new_max)
        {
            current_max = new_max;
        }
    }

    // maximum value will be print
    std::cout <<"Maximum value of submatrix is: "<< current_max << std::endl;
}

int alg_kadane(int *arr, int col)
{
    // current max submatrix is first element in array we give to function
    int current_max = arr[0];
    int new_max = 0;

    for (int i = 0; i < col; i++)
    {
        // we sum next element in array
        new_max = new_max + arr[i];

        if (current_max < new_max)
            current_max = new_max;
        if (new_max < 0) // we can ignore this value and start count from next element
            new_max = 0;
    }

    if (current_max <= 0) // if every element is smaller or equal to 0 then we return 0
    {
        return 0;
    }
    else if (current_max > 0)
    {
        return current_max;
    }

    return 0;
}

void delete_array(int **arr, int row)
{
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
