#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int P = 5; // Number of processes
const int R = 3; // Number of resources

// Function to calculate the need matrix
void calculateNeed(int need[P][R], int max[P][R], int allot[P][R]) {
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }
}

// Function to determine if the system is in a safe state
bool isSafe(int processes[], int avail[], int max[][R], int allot[][R]) {
    int need[P][R];
    calculateNeed(need, max, allot);

    bool finish[P] = {false}; // Tracks if a process has finished
    int safeSeq[P];           // Stores the safe sequence
    int work[R];              // Copy of available resources

    // Initialize work with available resources
    for (int i = 0; i < R; i++) {
        work[i] = avail[i];
    }

    int count = 0; // Count of processes included in the safe sequence

    while (count < P) {
        bool found = false;

        for (int p = 0; p < P; p++) {
            // Check if process `p` can be allocated resources
            if (!finish[p]) {
                int j;
                for (j = 0; j < R; j++) {
                    if (need[p][j] > work[j]) {
                        break;
                    }
                }

                // If all resources can be allocated
                if (j == R) {
                    // Allocate resources to process `p`
                    for (int k = 0; k < R; k++) {
                        work[k] += allot[p][k];
                    }

                    // Add this process to the safe sequence
                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }

        // If no process could be allocated resources in this pass
        if (!found) {
            cout << "System is not in a safe state." << endl;
            return false;
        }
    }

    // Output the safe sequence
    cout << "System is in a safe state.\nSafe sequence is: ";
    for (int i = 0; i < P; i++) {
        cout << "P" << safeSeq[i] << (i < P - 1 ? " -> " : "");
    }
    cout << endl;

    return true;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening input file" << endl;
        return 1;
    }

    int processes[P];
    for (int i = 0; i < P; i++) {
        processes[i] = i; // Process IDs (0 to P-1)
    }

    int avail[R];       // Available resources
    int max[P][R];      // Maximum demand of each process
    int allot[P][R];    // Resources allocated to each process

    // Read available resources
    for (int i = 0; i < R; i++) {
        inputFile >> avail[i];
    }

    // Read allocation matrix
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            inputFile >> allot[i][j];
        }
    }

    // Read maximum demand matrix
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            inputFile >> max[i][j];
        }
    }

    inputFile.close();

    // Check if the system is in a safe state
    isSafe(processes, avail, max, allot);

    return 0;
}
