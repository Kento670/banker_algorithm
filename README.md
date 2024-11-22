# banker_algorithm
**CS 33211 Operating Systems Programming Assignment #2**

**By: Kent Ogasawara**


## Description
This project implements the Banker’s Algorithm for deadlock avoidance using C++. The algorithm ensures that the system remains in a safe state by simulating resource allocation and checking for potential deadlocks.The program determines if the system is in a safe state and outputs a safe sequence of process execution if one exists.

## Requirements
- C/C++ compiler on Linux/Unix environment.

## Compilation

To compile the source files, run the following commands:

    g++ -c producer.cpp -pthread -o producer.o
    g++ -c consumer.cpp -pthread -o consumer.o
    g++ -o producer_consumer producer.o consumer.o -pthread
    ./producer_consumer

## Example Output
Here’s an example output on Ubuntu in VirtualBox:

    Produced: 83
    Consumed: 83
    Produced: 86
    Produced: 77
    Consumed: 86
    Produced: 15
    Consumed: 77
    Produced: 93
    Consumed: 15
    Produced: 35

    ctrl + c This will stop (terminate) a running program immediately.
