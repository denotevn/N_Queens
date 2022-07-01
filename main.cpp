/**
 * @file main.cpp
 * @author tuan dinh 
 * @brief 
 * @version 0.1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "NQueens.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc <= 1)
	{
		cerr << "ERROR: Missing argument for board dimensions" << endl;
		return 1;
	}

    // Solve 4 queens or more
    if (atoi(argv[1]) < 4)
	{
		cerr << "ERROR: Invalid board dimensions; first argument must be integer >= 4" << endl;
		return 2;
	}

    NQueens nq = NQueens(atoi(argv[1]));
	nq.computeSolns(argv[2]);

    return 0;
}