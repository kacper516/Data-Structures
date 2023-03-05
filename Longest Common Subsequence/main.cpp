#include <iostream>
#include "longest_common_subsequence.cpp"

int main()
{
    int **tab = nullptr;
    std::string str1 = "";
    std::string str2 = "";

    std::cout << "Put first string:\n str1 = ";
    std::cin >> str1;
    std::cout << "Put second string:\n str2 = ";
    std::cin >> str2;

    int m = str1.length();
    int n = str2.length();

    tab = createArray2D(tab, m + 1, n + 1);
    tab = lcs(tab, str1, str2);
    show_arr(tab, m + 1, n + 1);

    int longest_val = get_longest_value(tab, m, n);

    std::cout << "\nValue of longest common subsequence of: " << str1 << " and " << str2 << " is: " << longest_val<<".";

    if (longest_val == 0)
        std::cout << "\nLongest common subsequence of " << str1 << " and " << str2 << " is empty set (longest common subsequence doesn't exist)." << std::endl;
    else
        std::cout << "\nLongest common subsequence of " << str1 << " and " << str2 << " is: " << readSubsequence(tab, str1, str2) <<"." << std::endl;

    delete_array(tab, m + 1);
    return 0;
}