#include <iostream>
#include "queue.h"

int main(void) {
    Queue q(5);

    std::cout << "Queue empty? " << std::boolalpha << q.empty() << std::endl;

    q.enqueue(Point(1, 2, 3));
    q.enqueue(Point(4, 5, 6));
    q.enqueue(Point(7, 8, 9));

    std::cout << "Queue size: " << q.size() << std::endl;
    std::cout << "Front element: " << q.peek() << std::endl;

    q.dequeue();
    std::cout << "After one dequeue, front: " << q.peek() << std::endl;
    std::cout << "Queue size: " << q.size() << std::endl;

    q.enqueue(Point(10, 11, 12));
    q.enqueue(Point(13, 14, 15));
    q.enqueue(Point(16, 17, 18));

    std::cout << "Queue full? " << q.full() << std::endl;

    while (!q.empty()) {
        std::cout << "Dequeuing: " << q.peek() << std::endl;
        q.dequeue();
    }

    std::cout << "Queue empty? " << q.empty() << std::endl;
    return 0;
}
