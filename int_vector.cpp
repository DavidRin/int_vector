#include "int_vector.hpp"
#include <iostream>

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
        for (size_t i = 0; i < size_; ++i) {
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
            for (size_t i = 0; i < other.size_; ++i) {
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

    for (size_t i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
    }

    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

void IntVector::push_back(int value) {
    if (size_ >= capacity_) {
        size_t new_cap = (capacity_ == 0) ? 2 : capacity_ * 2;
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
        if (size_ > 0) return data_[0];
        static int dummy = 0;
        dummy = 0;
        return dummy;
    }
    return data_[index];
}

const int& IntVector::at(size_t index) const {
    if (index >= size_) {
        if (size_ > 0) return data_[0];
        static const int dummy = 0;
        return dummy;
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
    size_t max_size = (size_ > other.size_) ? size_ : other.size_;
    IntVector result; 

    for (size_t i = 0; i < max_size; ++i) {
        int val1 = (i < size_) ? data_[i] : 0;
        int val2 = (i < other.size_) ? other.data_[i] : 0;
        result.push_back(val1 + val2);
    }
    return result;
}


std::ostream& operator<<(std::ostream& out, const IntVector& v) {
    out << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i + 1 < v.size()) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

} 