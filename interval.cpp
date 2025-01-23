#include "interval.h"
#include <algorithm>
#include <initializer_list>

// Interval class implementations
Interval::Interval() : lower_bound(0), upper_bound(0), is_empty(true) {}

Interval::Interval(double lower, double upper) {
    if (lower > upper) {
        std::cout << "Lower bound must be less than or equal to upper bound.";
        lower_bound = 0;
        upper_bound = 0;
    } else {
        lower_bound = lower;
        upper_bound = upper;
        is_empty = false;
    }
}

Interval Interval::Empty() {
    return Interval();
}

Interval Interval::infinite() {
    return Interval(-std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity());
}

double Interval::lower() const {
    if (is_empty) {
        std::cout << "Interval is empty";
    }
    return lower_bound;
}

double Interval::upper() const {
    if (is_empty) {
        std::cout << "Interval is empty.";
    }
    return upper_bound;
}

bool Interval::isEmpty() const {
    return is_empty;
}

Interval Interval::add(const Interval &other) const {
    return Interval(lower_bound + other.lower_bound, upper_bound + other.upper_bound);
}

Interval Interval::operator+(const Interval &other) const {
    return add(other);
}

Interval Interval::subtract(const Interval &other) const {
    return Interval(lower_bound - other.upper_bound, upper_bound - other.lower_bound);
}

Interval Interval::multiply(const Interval &other) const {
    double ll = lower_bound * other.lower_bound;
    double lu = lower_bound * other.upper_bound;
    double ul = upper_bound * other.lower_bound;
    double uu = upper_bound * other.upper_bound;

    double new_lower = *std::min_element(std::initializer_list<double>{ll, lu, ul, uu}.begin(),
                                         std::initializer_list<double>{ll, lu, ul, uu}.end());
    double new_upper = *std::max_element(std::initializer_list<double>{ll, lu, ul, uu}.begin(),
                                         std::initializer_list<double>{ll, lu, ul, uu}.end());

    return Interval(new_lower, new_upper);
}

Interval Interval::division(const Interval &other) const {
    if (is_empty || other.is_empty) {
        return Empty();
    }
    if (other.lower_bound <= 0 && other.upper_bound >= 0) {
        std::cout << "\nDivision with 0 can't happen.";
        return Interval();
    }

    double ll = lower_bound / other.lower_bound;
    double lu = lower_bound / other.upper_bound;
    double ul = upper_bound / other.lower_bound;
    double uu = upper_bound / other.upper_bound;

    double new_lower = *std::min_element(std::initializer_list<double>{ll, lu, ul, uu}.begin(),
                                         std::initializer_list<double>{ll, lu, ul, uu}.end());
    double new_upper = *std::max_element(std::initializer_list<double>{ll, lu, ul, uu}.begin(),
                                         std::initializer_list<double>{ll, lu, ul, uu}.end());

    return Interval(new_lower, new_upper);
}

void Interval::print() const {
    if (is_empty) {
        std::cout << "Empty Interval";
    } else {
        std::cout << "[" << lower_bound << ", " << upper_bound << "]";
    }
}

// IntervalVector class implementations
IntervalVector::IntervalVector(size_t size) : intervals(size, Interval()) {}

IntervalVector::IntervalVector(size_t size, double arr[][2]) {
    for (size_t i = 0; i < size; ++i) {
        intervals.emplace_back(arr[i][0], arr[i][1]);
    }
}

Interval& IntervalVector::operator[](size_t index) {
    if (index >= intervals.size()) {
        throw std::out_of_range("Index out of range");
    }
    return intervals[index];
}

const Interval& IntervalVector::operator[](size_t index) const {
    if (index >= intervals.size()) {
        throw std::out_of_range("Index out of range");
    }
    return intervals[index];
}

IntervalVector IntervalVector::add(const IntervalVector &other) const {
    if (intervals.size() != other.intervals.size()) {
        throw std::invalid_argument("Size mismatch for addition");
    }
    IntervalVector result(intervals.size());
    for (size_t i = 0; i < intervals.size(); ++i) {
        result[i] = intervals[i].add(other.intervals[i]);
    }
    return result;
}

IntervalVector IntervalVector::multiply(const IntervalVector &other) const {
    if (intervals.size() != other.intervals.size()) {
        throw std::invalid_argument("Size mismatch for multiplication");
    }
    IntervalVector result(intervals.size());
    for (size_t i = 0; i < intervals.size(); ++i) {
        result[i] = intervals[i].multiply(other.intervals[i]);
    }
    return result;
}

IntervalVector IntervalVector::subtract(const IntervalVector &other) const {
    if (intervals.size() != other.intervals.size()) {
        throw std::invalid_argument("Size mismatch for subtraction");
    }
    IntervalVector result(intervals.size());
    for (size_t i = 0; i < intervals.size(); ++i) {
        result[i] = intervals[i].subtract(other.intervals[i]);
    }
    return result;
}

IntervalVector IntervalVector::division(const IntervalVector &other) const {
    if (intervals.size() != other.intervals.size()) {
        throw std::invalid_argument("Size mismatch for division");
    }
    IntervalVector result(intervals.size());
    for (size_t i = 0; i < intervals.size(); ++i) {
        result[i] = intervals[i].division(other.intervals[i]);
    }
    return result;
}

size_t IntervalVector::size() const {
    return intervals.size();
}

void IntervalVector::print() const {
    for (const auto &interval : intervals) {
        interval.print();
        std::cout << " ";
    }
    std::cout << std::endl;
}

// Main function
int main()
{
    // Δημιουργια 2 intervals
    Interval x(1.0, 2.0); // Interval [1.0, 2.0]
    Interval y(3.0, 4.0); // Interval [3.0, 4.0]
    Interval empty = Interval::Empty();
    Interval infinites = Interval::infinite();

    // Προσθεση και πολλαπλασιασμος intervals
    Interval sum = x.add(y);
    Interval multipli = x.multiply(y);
    Interval subtraction = x.subtract(y);
    Interval divide = x.division(y);

    // Αποτελεσματα
    std::cout << "\nSum: ";
    sum.print(); // Expected: [4.0, 6.0]
    std::cout << "\nMultiplication: ";
    multipli.print(); // Expected: [3.0, 8.0]
    std::cout << "\nSubtraction ";
    subtraction.print(); // Expected: [-3.0, -1.0]
    std::cout << "\nDivision ";
    divide.print(); // Expected: [0.25, 0.6667]
    std::cout << "\nInterval is a ";
    empty.print();

    // Δημιουργια 2 IntervalVectors
    double arr1[][2] = {{1.0, 2.0}, {3.0, 4.0}};
    double arr2[][2] = {{5.0, 6.0}, {7.0, 8.0}};
    IntervalVector vec1(2, arr1);
    IntervalVector vec2(2, arr2);

    // Προσθεση, πολλαπλασιασμος, αφαιρεση και διαιρεση IntervalVectors
    IntervalVector vec_sum = vec1.add(vec2);
    IntervalVector vec_multipli = vec1.multiply(vec2);
    IntervalVector vec_subtraction = vec1.subtract(vec2);
    IntervalVector vec_divide = vec1.division(vec2);

    // Αποτελεσματα
    std::cout << "\nVector Sum: ";
    vec_sum.print(); // Expected: [6.0, 8.0] [10.0, 12.0]
    std::cout << "\nVector Multiplication: ";
    vec_multipli.print(); // Expected: [5.0, 12.0] [21.0, 32.0]
    std::cout << "\nVector Subtraction: ";
    vec_subtraction.print(); // Expected: [-5.0, -3.0] [-5.0, -3.0]
    std::cout << "\nVector Division: ";
    vec_divide.print(); // Expected: [0.1667, 0.4] [0.375, 0.5714]
}
