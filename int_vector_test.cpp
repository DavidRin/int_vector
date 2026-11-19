#include "int_vector.hpp"
#include "catch_amalgamated.hpp"
#include <sstream>
#include <stdexcept>

using int_vector::IntVector;

// 1. Standard-Konstruktor
TEST_CASE("IntVector::IntVector() ", "[constructor]") {
    IntVector v;
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
    REQUIRE(v.empty() == true);
}

// 2. Konstruktor mit Startkapazität
TEST_CASE("IntVector::IntVector(size_t) ", "[constructor]") {
    IntVector v(10);
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 10);
    REQUIRE(v.empty() == true);
}

// 3. Copy-Konstruktor
TEST_CASE("IntVector::IntVector(const IntVector&)", "[constructor]") {
    IntVector v1;
    v1.push_back(1);
    v1.push_back(2);

    IntVector v2(v1);
    REQUIRE(v2.size() == 2);
    REQUIRE(v2[0] == 1);
    REQUIRE(v2[1] == 2);

    // Deep-Copy prüfen
    v1[0] = 99;
    REQUIRE(v2[0] == 1);
}

// 4. Zuweisungs-Operator (=)
TEST_CASE("IntVector::operator= ", "[operator]") {
    IntVector v1;
    v1.push_back(100);
    v1.push_back(200);

    IntVector v2;
    v2 = v1;

    REQUIRE(v2.size() == 2);
    REQUIRE(v2[0] == 100);
    REQUIRE(v2[1] == 200);

    // Selbstzuweisung prüfen
    v2 = v2;
    REQUIRE(v2.size() == 2);
    REQUIRE(v2[0] == 100);
}

// 5. size()
TEST_CASE("IntVector::size() ", "[state]") {
    IntVector v;
    REQUIRE(v.size() == 0);

    v.push_back(5);
    REQUIRE(v.size() == 1);

    v.push_back(10);
    REQUIRE(v.size() == 2);
}

// 6. capacity()
TEST_CASE("IntVector::capacity()", "[state]") {
    IntVector v(4);
    REQUIRE(v.capacity() == 4);

    // Kapazität überschreiten, um automatisches Vergrößern zu testen
    for (int i = 0; i < 5; i++) {
        v.push_back(i);
    }
    REQUIRE(v.capacity() >= 5);
}

// 7. empty()
TEST_CASE("IntVector::empty() ", "[state]") {
    IntVector v;
    REQUIRE(v.empty() == true);

    v.push_back(42);
    REQUIRE(v.empty() == false);

    v.pop_back();
    REQUIRE(v.empty() == true);
}

// 8. push_back()
TEST_CASE("IntVector::push_back() ", "[modifier]") {
    IntVector v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 10);
    REQUIRE(v[1] == 20);
    REQUIRE(v[2] == 30);
}

// 9. pop_back()
TEST_CASE("IntVector::pop_back() ", "[modifier]") {
    IntVector v;
    v.push_back(7);
    v.push_back(14);

    REQUIRE(v.pop_back() == 14);
    REQUIRE(v.size() == 1);

    REQUIRE(v.pop_back() == 7);
    REQUIRE(v.size() == 0);

    // Fallback bei leerem Vektor
    REQUIRE(v.pop_back() == 0);
}

// 10. at() (non-const)
TEST_CASE("IntVector::at() - Read/Write access and out_of_range", "[access]") {
    IntVector v;
    v.push_back(11);
    v.push_back(22);

    // Reguläres Lesen & Schreiben
    REQUIRE(v.at(0) == 11);
    v.at(1) = 99;
    REQUIRE(v.at(1) == 99);

    // Exception bei ungültigem Index
    REQUIRE_THROWS_AS(v.at(5), std::out_of_range);

    // Exception bei leerem Vektor
    IntVector empty_vec;
    REQUIRE_THROWS_AS(empty_vec.at(0), std::out_of_range);
}

// 11. at() const
TEST_CASE("IntVector::at() const - Read-only access and out_of_range", "[access]") {
    IntVector temp;
    temp.push_back(33);
    temp.push_back(44);

    const IntVector& v = temp;
    REQUIRE(v.at(0) == 33);
    REQUIRE(v.at(1) == 44);
    REQUIRE_THROWS_AS(v.at(10), std::out_of_range);
}

// 12. operator[] (non-const)
TEST_CASE("IntVector::operator[] read/write access", "[access]") {
    IntVector v;
    v.push_back(5);
    v.push_back(10);

    REQUIRE(v[0] == 5);
    v[1] = 50;
    REQUIRE(v[1] == 50);
}

// 13. operator[] const
TEST_CASE("IntVector::operator[] const read-only access", "[access]") {
    IntVector temp;
    temp.push_back(8);
    temp.push_back(16);

    const IntVector& v = temp;
    REQUIRE(v[0] == 8);
    REQUIRE(v[1] == 16);
}

// 14. operator+
TEST_CASE("IntVector::operator+", "[operator]") {
    IntVector v1;
    v1.push_back(1);
    v1.push_back(2);

    IntVector v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);

    IntVector sum = v1 + v2;
    REQUIRE(sum.size() == 3);
    REQUIRE(sum[0] == 11);
    REQUIRE(sum[1] == 22);
    REQUIRE(sum[2] == 30);
}

// 15. operator<<
TEST_CASE("operator<<", "[operator]") {
    IntVector temp;
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);

    const IntVector& v = temp;
    std::stringstream ss;
    ss << v;

    REQUIRE(ss.str() == "[1, 2, 3]");
}

// 16. insert()
TEST_CASE("IntVector::insert() inserts at beginning, middle, end and throws out_of_range", "[modifier]") {
    IntVector v;
    v.insert(0, 20); // in leeren Vektor am Anfang
    v.insert(0, 10); // vorne einfügen -> [10, 20]
    v.insert(2, 40); // am Ende einfügen -> [10, 20, 40]
    v.insert(2, 30); // in der Mitte einfügen -> [10, 20, 30, 40]

    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 10);
    REQUIRE(v[1] == 20);
    REQUIRE(v[2] == 30);
    REQUIRE(v[3] == 40);

    REQUIRE_THROWS_AS(v.insert(5, 99), std::out_of_range);
}

// 17. clear()
TEST_CASE("IntVector::clear() resets size, keeps capacity, and zeroes memory", "[modifier]") {
    IntVector v(5);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    size_t old_capacity = v.capacity();
    REQUIRE(old_capacity >= 5);

    v.clear();

    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == old_capacity);
    REQUIRE(v.empty() == true);
    REQUIRE_THROWS_AS(v.at(0), std::out_of_range);

    for (size_t i = 0; i < v.capacity(); i++) {
        REQUIRE(v[i] == 0);
    }
}

// 18. operator== und operator!=
TEST_CASE("IntVector::operator== and operator!= compare vectors element-wise", "[operator]") {
    IntVector a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    IntVector b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);

    IntVector c;
    c.push_back(1);
    c.push_back(99);
    c.push_back(3);

    REQUIRE(a == b);
    REQUIRE_FALSE(a != b);
    REQUIRE(a != c);
    REQUIRE_FALSE(a == c);
}