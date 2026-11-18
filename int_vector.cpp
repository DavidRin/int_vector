#include "int_vector.hpp"

int_vector::IntVector::IntVector(size_t initial_capacity)
    : size_(0), capacity_(initial_capacity)
{
    if (capacity_ > 0)
    {
        data_ = new int[capacity_];
    }
    else
    {
        data_ = nullptr;
    }
}

std::ostream &int_vector::operator<<(std::ostream &out, const IntVector &v)
{

    out << "[";
    for (size_t i = 0; i < v.size(); ++i)
    {
        out << v[i];
        if (i + 1 < v.size())
        {
            out << ", ";
        }
    }
    out << "]";
    return out;
}