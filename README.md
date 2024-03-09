# Multithreaded Sorting Application

This project illustrates the use of multithreading for sorting operations in both C++ and Java. It includes two main components: a C++ program (`prog.cpp`) that uses pthreads for parallel sorting and calculating the average of array segments, and a Java program (`prog_j.java`) that employs an ExecutorService to achieve the same objectives. This approach showcases the handling of threads in different programming languages to enhance performance in computational tasks.

## Features

- **Parallel Sorting**: Utilizes multithreading to divide the sorting task into smaller segments, achieving faster processing by sorting segments in parallel.
- **Average Calculation**: Computes the average value of array segments post-sorting to demonstrate thread synchronization and data aggregation.

## Getting Started

### Prerequisites

- For the C++ program: A C++ compiler with pthread support.
- For the Java program: JDK (Java Development Kit).

### Compiling and Running

#### C++ Program

1. Compile the program using a C++ compiler:
    ```
    g++ -pthread -o prog prog.cpp
    ```
2. Run the compiled executable:
    ```
    ./prog <array_size>
    ```

#### Java Program

1. Compile the Java program:
    ```
    javac prog_j.java
    ```
2. Run the Java program:
    ```
    java MultithreadedSortingApp <array_size>
    ```

### Usage

Replace `<array_size>` with the number of elements you want in the randomly generated array. The programs will then sort the array in parallel threads and calculate the average values of the sorted segments.

## License

This project is open source and available for educational purposes. Feel free to explore, modify, and improve upon it as you learn more about multithreaded programming in C++ and Java.
