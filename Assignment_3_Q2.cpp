#include "Assignment_3_Q2.h"
#include <iostream>

// Inserts a new element at the rear of the queue.
template <typename T>
void Queue<T>::enqueue(const T& element) {
    elements.push_back(element);
    std::cout << "Enqueued Element: " << element << std::endl;
}

// Removes the front element of the queue and returns it.
template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }

    T frontElement = elements.front();
    elements.pop_front();
    std::cout << "Dequeued Element: " << frontElement << std::endl;
    return frontElement;
}

// Returns the front element present in the queue without removing it.
template <typename T>
T Queue<T>::front() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }

    T frontElement = elements.front();
    std::cout << "Front Element: " << frontElement << std::endl;
    return frontElement;
}

// Checks if the queue is empty.
template <typename T>
bool Queue<T>::isEmpty() const {
    bool result = elements.empty();
    std::cout << "Is Empty? " << (result ? "Yes" : "No") << std::endl;
    return result;
}
// Returns the total number of elements present in the queue.
template <typename T>
size_t Queue<T>::size() const {
    size_t result = elements.size();
    std::cout << "Queue Size: " << result << std::endl;
    return result;
}

int main() {
    // Test your Queue implementation here
    Queue<int> myQueue;

    myQueue.enqueue(5);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.dequeue();
    myQueue.size();
   // myQueue.isEmpty();

    return 0;
}