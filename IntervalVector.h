#ifndef INTERVALVECTOR_H
#define INTERVALVECTOR_H

#include <vector>
#include "Interval.h" //πρεπει να το φτιαξει ο παπ

class IntervalVector {
private:
    std::vector<Interval> intervals;

public:
    // Κατασκευαστές
    IntervalVector() = default;
    IntervalVector(const std::vector<Interval>& intervals);

    // Μέθοδοι
    void add(const Interval& interval);
    void remove(size_t index);
    Interval get(size_t index) const;
    size_t size() const;

    // Πράξεις
    IntervalVector operator+(const Interval& interval) const;
    IntervalVector operator-(const Interval& interval) const;

    // Εμφάνιση
    void print() const;
};

#endif
