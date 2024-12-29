#include "IntervalVector.h"
#include <iostream>

// Κατασκευαστής
IntervalVector::IntervalVector(const std::vector<Interval>& intervals)
    : intervals(intervals) {}

// Προσθήκη διαστήματος
void IntervalVector::add(const Interval& interval) {
    intervals.push_back(interval);
}

// Αφαίρεση διαστήματος
void IntervalVector::remove(size_t index) {
    if (index < intervals.size()) {
        intervals.erase(intervals.begin() + index);
    } else {
        throw std::out_of_range("Index out of range");
    }
}

// Επιστροφή διαστήματος
Interval IntervalVector::get(size_t index) const {
    if (index < intervals.size()) {
        return intervals[index];
    } else {
        throw std::out_of_range("Index out of range");
    }
}

// Μέγεθος διανύσματος
size_t IntervalVector::size() const {
    return intervals.size();
}

// Πράξη πρόσθεσης
IntervalVector IntervalVector::operator+(const Interval& interval) const {
    IntervalVector result;
    for (const auto& i : intervals) {
        result.add(i + interval);
    }
    return result;
}

// Πράξη αφαίρεσης
IntervalVector IntervalVector::operator-(const Interval& interval) const {
    IntervalVector result;
    for (const auto& i : intervals) {
        result.add(i - interval);
    }
    return result;
}

// Εμφάνιση διανύσματος
void IntervalVector::print() const {
    std::cout << "[";
    for (size_t i = 0; i < intervals.size(); ++i) {
        std::cout << "[" << intervals[i].lower << ", " << intervals[i].upper << "]";
        if (i != intervals.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
