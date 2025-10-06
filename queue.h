#ifndef QUEUE_H
#define QUEUE_H

// Insert the relevant headers here
#include <iostream>
#include <cstdlib>

// Define a struct for representing three dimensional points with integral coordinates
struct Point {
    int x, y, z;

    // Constructor with default values
    Point(int x_val = 0, int y_val = 0, int z_val = 0)
        : x(x_val), y(y_val), z(z_val) {}

    // Overload << operator for printing
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
        return os;
    }
};

// Class for representing a queue
class Queue {
public:
    // Constructor: It allocates memory for an array of size max_size
    Queue(int max_size=1024) : _num_items(0), _max_size(max_size),
        _first(0), _last(0), _items(new Point[max_size]) {}

    // Destructor
    ~Queue() { delete[] _items; }

    // Prevent copy and move
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;
    Queue(Queue&&) = delete;
    Queue& operator=(Queue&&) = delete;

    // Interface

    // Check whether the queue is empty
    // (the implementation will go in queue.cpp)
    bool empty();

    // Check whether the queue is full
    // (the implementation will go in queue.cpp)
    bool full();

    // Return the number of elements in the queue
    // (the implementation will go in queue.cpp)
    int size();

    // Insert an element in the queue
    // print an error message on std::cerr and exit in case of overflow
    // (the implementation will go in queue.cpp)
    void enqueue(Point);

    // Remove an element from the queue
    // print an error message on std::cerr and exit in case of underflow
    // (the implementation will go in queue.cpp)
    void dequeue();

    // Access the least recently added element
    // (the implementation will go in queue.cpp)
    Point peek();

private:
    int _num_items; // number of elements in the queue
    int _max_size;  // capacity of the fixed-size queue
    int _first;     // index to the first element of the queue
    int _last;      // index of the next available slot
    Point* _items;  // data container
};

#endif
