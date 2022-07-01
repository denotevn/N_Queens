#include "NQueens.hpp"

using namespace std;

// Initialize input data for processing
/**
 * @brief Construct a new NQueens::NQueens object
 * 
 * @param NQueens 
 */
NQueens::NQueens(int NQueens){
    nQueens_ = NQueens;
    solnCount = 0;
    board_ = new int[NQueens]; 
    lastSolution_ = new int[NQueens];
}

void NQueens::computeSolns(bool printAllSolns)
{
    solveNQ(0, printAllSolns);
    if (!printAllSolns)
    {
        board_ = lastSolution_; // go back to the solution
        printBoard(); // only print the last solution
    }
    cout << "nQueens: " << nQueens_ << endl;
    cout << solnCount << " solutions found" << endl; 
}

// use recursion and backtracking to find solutions
void NQueens::solveNQ(int row, bool printAllSolution)
{
    if(row >= nQueens_)
    {
        solnCount ++;
        // copy solution (board_) to lastSolution_
        memcpy(lastSolution_, board_, nQueens_ * sizeof(int));
        // void memcpy( void* destination, void* source, size_t num);

        if (printAllSolution)
        {
            printBoard();
        }
        return;   
    }

    // check
    for(int i = 0; i < nQueens_; i++)
    {
        if(isSafe(row, i))
        {
            // put the queen here
            board_[row] = i;
            // recursively call function for the next row
            solveNQ(row + 1, printAllSolution);
        }
    }

}


bool NQueens::isSafe(int row, int col)
{	
    for (int i = 0; i < row; i++)
    {
        // Check this column
        if (board_[i] == col) return false; // Neu board[i] == col nghia la theo hang doc no da co quan hau roi
        
        // Check upper-left diagonal direction
        if (board_[i] == col - (row - i)) return false;
        
        // Check upper-right diagonal direction
        if (board_[row - 1 - i] == col + i + 1) return false;
    }
    
    // Queen is safe in this position
    return true;
}


void NQueens::printBoard()
{
    int row = 0, col = 0;
    cout << endl;

    // display array values
    for (row = 0; row < nQueens_; row++){
        cout << board_[row];
    }
    cout << endl;

    // display pretty board
    for (int dash = 0; dash < nQueens_ * 4 + 1; dash++)
    {
        cout << "-";
    }
    cout << endl;

    for(row = 0; row < nQueens_; row ++)
    {
        cout << "|";
        for (col = 0; col < nQueens_; col++ )
        {
            if (board_[row] == col)
            {
                cout << " Q |";
            }
            else
            {
                cout << "   |";
            } 
        }
        cout << endl;

        for (int dash = 0; dash < nQueens_ * 4 + 1; dash++)
        {
            cout << "-";
        }
        cout << endl; 
    }

}

