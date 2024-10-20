#include <iostream>
#include <iomanip>
using namespace std;

const int PLAYERS = 5;
const int ROUNDS = 4;

// Function to calculate total score for each player
int calculateTotalScore(int scores[PLAYERS][ROUNDS], int playerIndex) {
    int total = 0;
    for (int i = 0; i < ROUNDS; ++i) {
        total += scores[playerIndex][i];
    }
    return total;
}

// Function to find the highest score in a round
int findHighestInRound(int scores[PLAYERS][ROUNDS], int roundIndex) {
    int highest = scores[0][roundIndex];
    for (int i = 1; i < PLAYERS; ++i) {
        if (scores[i][roundIndex] > highest) {
            highest = scores[i][roundIndex];
        }
    }
    return highest;
}

// Function to find the lowest score in a round
int findLowestInRound(int scores[PLAYERS][ROUNDS], int roundIndex) {
    int lowest = scores[0][roundIndex];
    for (int i = 1; i < PLAYERS; ++i) {
        if (scores[i][roundIndex] < lowest) {
            lowest = scores[i][roundIndex];
        }
    }
    return lowest;
}

int main() {
    // Sample scores for 5 players over 4 rounds
    int scores[PLAYERS][ROUNDS] = {
        {10, 20, 15, 30},
        {25, 15, 20, 10},
        {30, 10, 25, 20},
        {15, 30, 10, 25},
        {20, 25, 30, 15}
    };

    cout << "Player | Round 1 | Round 2 | Round 3 | Round 4 | Total Score" << endl;
    cout << "------------------------------------------------------------" << endl;

    // Calculate and display the total score for each player
    for (int i = 0; i < PLAYERS; ++i) {
        int totalScore = calculateTotalScore(scores, i);
        cout << setw(4) << i + 1 << "    | " << setw(6) << scores[i][0] << "   | " << setw(6) << scores[i][1]
             << "   | " << setw(6) << scores[i][2] << "   | " << setw(6) << scores[i][3]
             << "   | " << setw(6) << totalScore << endl;
    }

    // Find and display the highest and lowest scores in each round
    for (int i = 0; i < ROUNDS; ++i) {
        int highestScore = findHighestInRound(scores, i);
        int lowestScore = findLowestInRound(scores, i);
        cout << "Highest Score in Round " << i + 1 << ": " << highestScore << endl;
        cout << "Lowest Score in Round " << i + 1 << ": " << lowestScore << endl;
    }

    return 0;
}
