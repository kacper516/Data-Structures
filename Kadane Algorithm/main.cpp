#include "kadane_alg.cpp"

int main()
{
    int sets; //number of sets
    int row;
    int col;
    std::cout<<"How many sets do you want: ";
    std::cin >> sets;
    while (sets != 0)
    {
        std::cout<<"\nInput how many rows and cols you want in new array: ";
        std::cin >> row >> col;
        int **new_array = create_arr(row, col); // create new array
        current_max(new_array, row, col);       // we search for max submatrix
        delete_array(new_array, row);           // free memory
        sets--;                                 // decrement sets
    }
}
