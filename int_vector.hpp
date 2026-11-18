#ifndef INT_VECTOR_HPP
#define INT_VECTOR_HPP

#include <cstddef>
#include <ostream>
namespace int_vector
{

    class IntVector
    {

    public:
        IntVector() : data_(nullptr), size_(0), capacity_(0) {}
        explicit IntVector(size_t initial_capacity);
        IntVector(const IntVector &other);
        IntVector &operator=(const IntVector &other);
        ~IntVector();

        size_t size() const
        {
            return size_;
        }
        size_t capacity() const
        {
            return capacity_;
        }
        bool empty() const
        {
            return size_ == 0;
        }
        void push_back(int value);
        int pop_back();
        int &at(size_t index);
        const int &at(size_t index) const;
        int &operator[](size_t index);
        const int &operator[](size_t index) const;

        IntVector operator+(const IntVector &other) const;
        friend std::ostream &operator<<(std::ostream &os, const IntVector &v);

    private:
        int *data_;
        size_t size_;
        size_t capacity_;

        void resize_internal(size_t new_capacity);
    };

    std::ostream &operator<<(std::ostream &out, const IntVector &v);

}

#endif