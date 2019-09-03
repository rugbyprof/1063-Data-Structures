#include <iostream>
#include <string>
#include <fstream>

// #ifdef __cplusplus__
// #include <cstdlib>
// #else
// #include <stdlib.h>
// #endif

#include <unistd.h>

using namespace std;

bool fileExists(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

class GameOfLife{
private:
    int **Board;
    int **Board2;
    int Rows;
    int Cols;
    int Generations;
public:
    GameOfLife(string filename){
        Generations = 1;
        string line;
        char ch;

        if(!fileExists(filename.c_str())){
            cout<<"File doesn't exist!"<<endl;
            exit(0);
        }

        loadDataFile(filename);
        // ifstream fin;
        // fin.open(filename);
        // fin >> Rows >> Cols;
        // InitBoardArray(Board);
        // InitBoardArray(Board2);
        // for (int i = 0; i < Rows; i++){
        //     for (int j = 0; j < Cols; j++){
        //         fin.get(ch);
        //         if (ch == 10){
        //             continue;
        //         }
        //         Board[i][j] = int(ch) - 48;
        //     }
        // }
    }
    
    GameOfLife(int r, int c){
        Rows = r;
        Cols = c;
        InitBoardArray(Board);
        InitBoardArray(Board2);
        PrintBoard();
    }

    void loadDataFile(string filename){
        string row;
        ifstream fin;
        fin.open(filename);
        fin >> Rows >> Cols;
        InitBoardArray(Board);
        InitBoardArray(Board2);
        for (int i = 0; i < Rows; i++){
            fin>>row;
            for(int j=0;j<Cols;j++){
                Board[i][j] = int(row[j]) - 48;
            }
            
        }
    }
    
    void InitBoardArray(int **&b){
        b = new int*[Rows];
        for (int i = 0; i < Rows; i++){
            b[i] = new int[Cols];
        }
        ResetBoardArray(b);
    }
    
    void ResetBoardArray(int **&b){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                b[i][j] = 0;
            }
        }
    }
    
    void PrintBoard(){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                if (Board[i][j] == 1)
                    //cout << char('X');
                    //cout << "\u2593";
                    cout << "\u25A9";
                    //cout<<  "\u2b1c";
                    
                else
                    cout << " ";
            }
            cout << endl;
        }
        cout<<"Gen:"<<Generations<<endl;
    }
    
    int CountNeighbors(int row, int col){
        int neighbors = 0;
        if (Board[row][col] == 1){
            neighbors--;
        }
        for (int i = row - 1; i <= row + 1; i++){
            for (int j = col - 1; j <= col + 1; j++){
                if (OnBoard(i, j)){
                    neighbors += Board[i][j];
                }
            }
        }
        return neighbors;
    }
    
    bool OnBoard(int row, int col){
        return (row >= 0 && row < Rows && col >= 0 && col < Cols);
    }
    
    void RandomPopulate(int num){
        int r = 0;
        int c = 0;
        for (int i = 0; i<num; i++){
            r = rand() % Rows;
            c = rand() % Cols;
            Board[r][c] = 1;
        }
    }
    
    void SetCell(int r, int c, int val){
        Board[r][c] = val;
    }
    
    void AddGens(){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                Board[i][j] += Board2[i][j];
            }
        }
        ResetBoardArray(Board2);
    }
    
    void clear_screen(int lines){
      for(int i=0;i<lines;i++){
        cout<<endl;
      }
    }
    
    void Run(int max_generations=99999){
        int neighbors = 0;
        Generations = 0;
        while (Generations < max_generations){
            for (int i = 0; i < Rows; i++){
                for (int j = 0; j < Cols; j++){
                    neighbors = CountNeighbors(i, j);
                    if (Board[i][j] == 1 && (neighbors < 2 || neighbors > 3)){
                        Board2[i][j] = -1;
                    }
                    if (Board[i][j] == 0 && neighbors == 3){
                        Board2[i][j] = 1;
                    }
                }
            }
            AddGens();
            usleep(100000);
            clear_screen(40);
            PrintBoard();
            Generations++;
        }
        
    }
};

int main(){
    //GameOfLife G(26, 40);

    GameOfLife G("data.txt");

    //G.PrintBoard();

    //G.RandomPopulate(60);
    G.Run(400);
    return 0;
}
