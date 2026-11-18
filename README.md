# IntVector

A simple C++ implementation of a dynamic integer array inside the int_vector namespace.

## Class Diagram

```mermaid
classDiagram
    namespace int_vector {
        class IntVector {
            - int* m_data
            - size_t m_size
            - size_t m_capacity
            - void resize_internal(size_t new_capacity)
            
            + IntVector()
            + IntVector(const IntVector& other)
            + IntVector& operator=(const IntVector& other)
            + ~IntVector()
            
            + size_t size() const
            + size_t capacity() const
            + bool empty() const
            
            + void push_back(int value)
            + int pop_back()
            + int& at(size_t index)
            + const int& at(size_t index) const
            + int& operator[](size_t index)
            
            + IntVector operator+(const IntVector& other) const
        }
    }
```