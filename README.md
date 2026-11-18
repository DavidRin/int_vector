# IntVector

A simple C++ implementation of a dynamic integer array inside the int_vector namespace.

## Class Diagram

```mermaid
classDiagram
    namespace int_vector {
        class IntVector {
            - int32_t* data
            - size_t size
            - size_t capacity
            - void resize_internal(size_t new_capacity)
            
            + IntVector()
            + explicit IntVector(size_t capacity)
            + IntVector(const IntVector& other)
            + IntVector& operator=(const IntVector& other)
            + ~IntVector()
            
            + size_t size() const
            + size_t capacity() const
            + bool empty() const
            
            + void push_back(int32_t value)
            + int32_t pop_back()
            + int32_t& at(size_t index)
            + const int32_t& at(size_t index) const
            + int32_t& operator[](size_t index)
            + const int32_t& operator[](size_t index) const
            
            + IntVector operator+(const IntVector& other) const
        }
    }
```