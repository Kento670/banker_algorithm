# bankers_algorithm
**CS 33211 Operating Systems Programming Assignment #2**

**By: Kent Ogasawara**


## Description
This project implements the Banker’s Algorithm for deadlock avoidance using C++. The algorithm ensures that the system remains in a safe state by simulating resource allocation and checking for potential deadlocks. The program determines if the system is in a safe state and outputs a safe sequence of process execution if one exists.

## Requirements
- C/C++ compiler on Linux/Unix environment.
- input.txt file

## Compilation

To compile the source files, run the following commands:

    g++ bankers_algorithm.cpp -o bankers_algorithm
    ./bankers_algorithm

## Input.txt format

    3 3 2               # Available resources (A, B, C)
    0 1 0               # Allocation for P0
    2 0 0               # Allocation for P1
    3 0 2               # Allocation for P2
    2 1 1               # Allocation for P3
    0 0 2               # Allocation for P4
    7 5 3               # Max for P0
    3 2 2               # Max for P1
    9 0 2               # Max for P2
    2 2 2               # Max for P3
    4 3 3               # Max for P4

## Example Output
Here’s an example output on Ubuntu in VirtualBox:

    System is in a safe state.
    Safe sequence is: P1 -> P3 -> P4 -> P0 -> P2

    
