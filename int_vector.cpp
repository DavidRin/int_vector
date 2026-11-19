#include "int_vector.hpp"
#include <iostream>
#include <stdexcept>
namespace int_vector {

IntVector::IntVector(size_t initial_capacity) 
    : size_(0), capacity_(initial_capacity) {
    if (capacity_ > 0) {
        data_ = new int[capacity_];
    } else {
        data_ = nullptr;
    }
}

IntVector::IntVector(const IntVector& other) 
    : size_(other.size_), capacity_(other.capacity_) {
    if (capacity_ > 0) {
        data_ = new int[capacity_];
        for (size_t i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    } else {
        data_ = nullptr;
    }
}

IntVector& IntVector::operator=(const IntVector& other) {
    if (this != &other) { 
        int* new_data = nullptr;
        if (other.capacity_ > 0) {
            new_data = new int[other.capacity_];
            for (size_t i = 0; i < other.size_; i++) {
                new_data[i] = other.data_[i];
            }
        }

        delete[] data_;

        data_ = new_data;
        size_ = other.size_;
        capacity_ = other.capacity_;
    }
    return *this;
}

void IntVector::resize(size_t new_capacity) {
    if (new_capacity < size_) {
        new_capacity = size_;
    }
    if (new_capacity == 0) {
        new_capacity = 1;
    }

    int* new_data = new int[new_capacity];

    for (size_t i = 0; i < size_; i++) {
        new_data[i] = data_[i];
    }

    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

void IntVector::push_back(int value) {
    if (size_ >= capacity_) {
        size_t new_cap = 0;
        if (capacity_ == 0) {
            new_cap = 2;
        } else {
            new_cap = capacity_ * 2;
        }
        resize(new_cap);
    }
    data_[size_++] = value;
}

int IntVector::pop_back() {
    if (size_ > 0) {
        --size_;
        return data_[size_];
    }
    return 0; 
}

int& IntVector::at(size_t index) {
    if (index >= size_) {
        throw std::out_of_range("out of range");
    }
    return data_[index];
}

const int& IntVector::at(size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("out of range");
    }
    return data_[index];
}

int& IntVector::operator[](size_t index) {
    return data_[index];
}

const int& IntVector::operator[](size_t index) const {
    return data_[index];
}

IntVector IntVector::operator+(const IntVector& other) const {
    size_t max_size = 0;
    if (size_ > other.size_) {
        max_size = size_;
    } else {
        max_size = other.size_;
    }

    IntVector result; 

    for (size_t i = 0; i < max_size; i++) {
        int val1 = 0;
        if (i < size_) {
            val1 = data_[i];
        }

        int val2 = 0;
        if (i < other.size_) {
            val2 = other.data_[i];
        }

        result.push_back(val1 + val2);
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, const IntVector& v) {
    out << "[";
    for (size_t i = 0; i < v.size(); i++) {
        out << v[i];
        if (i + 1 < v.size()) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

}