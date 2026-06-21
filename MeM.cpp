#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <thread>
#include <algorithm>
#include <random>

using namespace std;

bool rewardsEnabled = true; 
bool animationsEnabled = true; 

void clearScreen() {
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear"); 
    #endif
}

void displayTrophyAnimation(string player) {
    string trophy1 = R"(
             ___________
            '._==_==_=_.'  
            .-/\:      /-.  
           | (|:.     |) |  
            '-|:.     |-'   
              \::.    /     
               '::. .'      
                 ) (        
               _.' '._      
              """"""""      
    )";
    
    string trophy2 = R"(
             ___________
            '._==_==_=_.'  
            .-\:      /-.  
           | (|:.     |) |  
            '-|:.     |-'   
              \::.    /     
               '::. .'      
                 ) (        
               _.' '._      
              """"""""      
    )";

    for (int i = 0; i < 6; ++i) {  
        clearScreen();
        if (i % 2 == 0) {
            cout << "          " << player << " have won!" << endl;
            cout << trophy1 << endl;
        } else {
            cout << "          " << player << " have won!" << endl;
            cout << trophy2 << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void displayLoseAnimation() {
    string loseFace = R"(
     .-""""""-.
   .'          '.
  /   O      O   \
 :      ______    :
 |     /      \   |  
 :    |        |  :
  \    \______/  /
   '.          .'
     '-......-'
    )";
    
    clearScreen();
    cout << "    You've lost!" << endl;
    cout << loseFace << endl;
}

void displayBoard(const vector<vector<char>>& board, const vector<vector<bool>>& revealed, int animRow = -1, int animCol = -1, char animChar = '\0') {
    clearScreen(); 
    cout << "    ";
    for (int i = 0; i < board[0].size(); ++i)
        cout << setw(2) << i + 1 << " "; 
    cout << endl;

    for (int i = 0; i < board.size(); ++i) {
        cout << setw(2) << i + 1 << " "; 
        for (int j = 0; j < board[i].size(); ++j) {
            if (i == animRow && j == animCol) {
                cout << setw(2) << animChar << " "; 
            } else if (revealed[i][j]) {
                cout << setw(2) << board[i][j] << " "; 
            } else {
                cout << setw(2) << "#" << " "; 
            }
        }
        cout << endl;
    }
}

void smoothRevealAnimation(int row, int col, const vector<vector<char>>& board, vector<vector<bool>>& revealed) {
    char steps[] = {'#', '-', '/', '|', '\\', '?', board[row][col]}; 
    int totalSteps = sizeof(steps) / sizeof(steps[0]);

    for (int i = 0; i < totalSteps; ++i) {
        revealed[row][col] = true; 
        int delay = 50 + (i * 100 / totalSteps); 
        displayBoard(board, revealed, row, col, steps[i]); 
        this_thread::sleep_for(chrono::milliseconds(delay)); 
    }
}


void revealCard(int row, int col, vector<vector<bool>>& revealed) {
    revealed[row][col] = true; 
}

void initializeBoard(vector<vector<char>>& board) {
    vector<char> symbols;
    int totalCards = board.size() * board[0].size();
    
    
    for (char c = 'A'; c <= 'Z'; ++c) symbols.push_back(c);
    for (char c = 'a'; c <= 'z'; ++c) symbols.push_back(c);
    for (char c = '0'; c <= '9'; ++c) symbols.push_back(c);

    if (totalCards / 2 > symbols.size()) {
        cerr << "Board is too big to generate unique symbols." << endl;
        exit(1); 
    }

    symbols.resize(totalCards / 2);
    symbols.insert(symbols.end(), symbols.begin(), symbols.end());
    
    random_device rd;
    mt19937 g(rd());
    shuffle(symbols.begin(), symbols.end(), g);

    int k = 0;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            board[i][j] = symbols[k++];
        }
    }
}

void revealCard(int row, int col, const vector<vector<char>>& board, vector<vector<bool>>& revealed) {
    revealed[row][col] = true; 
    displayBoard(board, revealed); 
}


void displaySettingsMenu() {
    clearScreen();
    cout << "+-------------------------+\n";
    cout << "| Animations  |  " << (animationsEnabled ? "Enabled " : "Disabled") << " |\n"; 
    cout << "+-------------------------+\n";
    cout << "| Rewards*    |  " << (rewardsEnabled ? "Enabled " : "Disabled") << " |\n"; 
    cout << "+-------------------------+\n";
    cout << "* - the person who got a match will get an extra round;\n\n"; 
}


void displayMainMenu() {
    clearScreen();
    cout << " _  _  ____  _  _ \n";
    cout << "( \\/ )(  __)( \\/ )\n";
    cout << "/ \\/ \\ ) _) / \\/ \\\n";
    cout << "\\_)(_/(____)\\_)(_/ \n";
    cout << "\nWelcome to Memory Game!\n\n"; 
    cout << "(1) 2-Players Mode\n";
    cout << "(2) Vs. Computer Mode\n";
    cout << "(3) Settings\n"; 
    cout << "(4) Exit\n";
    cout << "\nInput: ";
}


pair<int, int> computerPickCard(const vector<vector<bool>>& revealed, int rows, int cols) {
    int r, c;
    do {
        r = rand() % rows;
        c = rand() % cols;
    } while (revealed[r][c]); 
    return {r, c}; 
}

void playGame(int rows, int cols, bool isVsComputer = false) {
    vector<vector<char>> board(rows, vector<char>(cols)); 
    vector<vector<bool>> revealed(rows, vector<bool>(cols, false)); 

    initializeBoard(board); 

    int currentPlayer = 1; 
    int pairsFound = 0; 
    int totalPairs = (rows * cols) / 2; 

    int player1Pairs = 0, player2Pairs = 0, computerPairs = 0; 
    bool roundWon = false; 

    while (pairsFound < totalPairs) { 
        displayBoard(board, revealed); 
        int row1, col1, row2, col2; 
        
        if (isVsComputer && currentPlayer == 2) {
            do {
                tie(row1, col1) = computerPickCard(revealed, rows, cols); 
            } while (revealed[row1][col1]); 
        } else {
            do {
                cout << "Player " << currentPlayer << ", pick the first card (row and column): ";
                cin >> row1 >> col1;
                --row1; --col1; 
            } while (row1 < 0 || row1 >= rows || col1 < 0 || col1 >= cols || revealed[row1][col1]); 
        }

        if (animationsEnabled) smoothRevealAnimation(row1, col1, board, revealed); 
        else revealCard(row1, col1, board, revealed); 

        
        if (isVsComputer && currentPlayer == 2) {
            do {
                tie(row2, col2) = computerPickCard(revealed, rows, cols); 
            } while ((row1 == row2 && col1 == col2) || revealed[row2][col2]); 
        } else {
            do {
                cout << "Player " << currentPlayer << ", pick the second card (row and column): ";
                cin >> row2 >> col2;
                --row2; --col2; 
            } while ((row1 == row2 && col1 == col2) || row2 < 0 || row2 >= rows || col2 < 0 || col2 >= cols || revealed[row2][col2]); 
        }

        if (animationsEnabled) smoothRevealAnimation(row2, col2, board, revealed); 
        else revealCard(row2, col2, board, revealed); 

        
        if (board[row1][col1] == board[row2][col2]) {
            cout << "It's a match!\n";
            pairsFound++; 
            roundWon = true; 
            if (currentPlayer == 1) player1Pairs++; 
            else if (isVsComputer) computerPairs++; 
            else player2Pairs++; 
        } else {
            cout << "Not a match.\n";
            this_thread::sleep_for(chrono::milliseconds(1000)); 
            revealed[row1][col1] = revealed[row2][col2] = false; 
            roundWon = false; 
        }

        
        if (!(roundWon && rewardsEnabled)) {
            currentPlayer = (currentPlayer == 1) ? 2 : 1; 
        }
    }
    
    cout << "\nGame Over! Final Results:\n";
    cout << "Player 1 Pairs: " << player1Pairs << endl;
    
    if (isVsComputer) {
        cout << "Computer Pairs: " << computerPairs << endl;
    } else {
        cout << "Player 2 Pairs: " << player2Pairs << endl;
    }

    if (player1Pairs > (isVsComputer ? computerPairs : player2Pairs)) {
        displayTrophyAnimation("Player 1");
    } else if (isVsComputer && computerPairs > player1Pairs) {
        displayLoseAnimation(); 
    } else if (!isVsComputer && player2Pairs > player1Pairs) {
        displayTrophyAnimation("Player 2");
    } else {
        cout << "It's a tie!" << endl; 
    }
}

void mainMenu() {
    while (true) {
        displayMainMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                clearScreen();
                int rows, cols;
                cout << "Please choose the board size." << endl;
                cout << "Enter number of rows: ";
                cin >> rows;
                cout << "Enter number of columns: ";
                cin >> cols;
                playGame(rows, cols); 
                break; 
            }
            case 2: {
                clearScreen();
                int rows, cols;
                cout << "Please choose the board size." << endl;
                cout << "Enter number of rows: ";
                cin >> rows;
                cout << "Enter number of columns: ";
                cin >> cols;
                playGame(rows, cols, true); 
                break; 
            }
            case 3: {
                displaySettingsMenu();
                cout << "Enable animations during card reveals? (1 for Yes, 0 for No): ";
                cin >> animationsEnabled;
                cout << "Enable extra turn rewards for correct guesses? (1 for Yes, 0 for No): ";
                cin >> rewardsEnabled;
                break;
            }
            case 4: {
                return; 
            }
            default: {
                cout << "Invalid choice." << endl; 
                break; 
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    mainMenu(); 
    return 0; 
}
