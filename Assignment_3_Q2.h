#include <list>
#include <cstddef>

template <typename T>
class Queue {
private:
    std::list<T> elements;

public:
    // Inserts a new element at the rear of the queue.
    void enqueue(const T& element);

    // Removes the front element of the queue and returns it.
    T dequeue();

    // Returns the front element present in the queue without removing it.
    T front() const;

    // Checks if the queue is empty.
    bool isEmpty() const;

    // Returns the total number of elements present in the queue.
    size_t size() const;
};