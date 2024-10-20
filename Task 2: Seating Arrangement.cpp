#include <iostream>
using namespace std;

const int ROWS = 10;
const int COLS = 10;

// Function to display the seating arrangement
void displaySeatingArrangement(int seating[ROWS][COLS]) {
    cout << "Current Seating Arrangement:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << seating[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to reserve a seat
void reserveSeat(int seating[ROWS][COLS], int row, int col) {
    if (seating[row][col] == 0) {
        seating[row][col] = 1; // Mark as reserved
        cout << "Seat reserved successfully!" << endl;
    } else {
        cout << "Seat is already reserved!" << endl;
    }
}

// Function to cancel a reservation
void cancelSeat(int seating[ROWS][COLS], int row, int col) {
    if (seating[row][col] == 1) {
        seating[row][col] = 0; // Mark as available
        cout << "Reservation canceled successfully!" << endl;
    } else {
        cout << "Seat is not reserved!" << endl;
    }
}

int main() {
    int seating[ROWS][COLS] = {0};

    int choice, row, col;

    do {
        cout << "\nSeating Arrangement System" << endl;
        cout << "1. Display Seating Arrangement" << endl;
        cout << "2. Reserve a Seat" << endl;
        cout << "3. Cancel a Reservation" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
      
                displaySeatingArrangement(seating);
                break;
            case 2:
                // Reserve a seat
                cout << "Enter row (0-9) and column (0-9) to reserve: ";
                cin >> row >> col;
                if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
                    reserveSeat(seating, row, col);
                } else {
                    cout << "Invalid seat location!" << endl;
                }
                break;
            case 3:
                // Cancel a reservation
                cout << "Enter row (0-9) and column (0-9) to cancel reservation: ";
                cin >> row >> col;
                if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
                    cancelSeat(seating, row, col);
                } else {
                    cout << "Invalid seat location!" << endl;
                }
                break;
            case 4:
                // Exit
                cout << "Exiting...)" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
