#ifndef NQUEENS_H_
#define NQUEENS_H_

#include <iostream>
#include <cstring>

class NQueens{
    public:
        NQueens(int nQueens);
        void computeSolns(bool printAllSolns);
    private:
        int *board_ = NULL;
        int *lastSolution_ = NULL;
        int nQueens_, solnCount = 0;

        void solveNQ(int row, bool printAllSolns);
        bool isSafe(int row, int col);
        void printBoard();
};
#endif

