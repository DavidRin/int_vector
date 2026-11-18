#include "int_vector.hpp"


std::ostream& int_vector::operator<<(std::ostream& out, const IntVector& v) {

    out<< "[";
    for (size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i + 1 < v.size()) {
            out<< ", ";
        }
    }
    out << "]";
    return out;
}