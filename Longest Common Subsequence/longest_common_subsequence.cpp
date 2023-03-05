#include "longest_common_subsequence.hpp"

int **createArray2D(int **array, int row, int col)
{
    try
    {
        array = new int *[row];
    }
    catch (const std::bad_alloc &)
    {
        std::cerr << "error";
    }

    for (int i = 0; i < row; i++)
    {
        try
        {
            array[i] = new int[col];
        }
        catch (const std::bad_alloc &)
        {
            std::cerr << "error";
        }
    }
    return array;
}

void delete_array(int **T, int row)
{
    for (int j = 0; j < row; j++)
    {
        delete[] T[j];
    }
    delete[] T;
}

int **lcs(int **array, std::string str1, std::string str2)
{
    int m = str1.length();
    int n = str2.length();
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // we put 0 in first row and first col (initial states)
            if (i == 0 || j == 0)
            {
                array[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                array[i][j] = array[i - 1][j - 1] + 1;
            }
            else
            {
                array[i][j] = std::max(array[i - 1][j], array[i][j - 1]);
            }
        }
    }
    return array;
}
std::string readSubsequence(int **array, std::string str1, std::string str2)
{
    int m = str1.length();
    int n = str2.length();

    std::string lcs = "";

    // we start from right down corner of array
    while (m > 0 && n > 0)
    {
        // if chars is the same, we put them to LCS
        if (str1[m - 1] == str2[n - 1])
        {
            lcs += str1[m - 1];
            m--;
            n--;
        }
        // if not we need to go to left or upper neighbour
        else if (array[m - 1][n] > array[m][n - 1])
            m--;
        else
            n--;
    }

    // reverse LCS
    std::reverse(lcs.begin(), lcs.end());
    return lcs;
}

int get_longest_value(int **array, int row, int col)
{
    int res = array[row][col];
    return res;
}

void show_arr(int **array, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << array[i][j] << std::setw(3) << " ";
        }
        std::cout << std::endl;
    }
}