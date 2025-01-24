#ifndef INTERVAL_H
#define INTERVAL_H

#include <iostream>
#include <stdexcept>
#include <limits>
#include <vector>

class Interval {
private:
    double lower_bound;
    double upper_bound;
    bool is_empty;

public:
    Interval();
    Interval(double lower, double upper);
    
    static Interval Empty();
    static Interval infinite();

    double lower() const;
    double upper() const;
    bool isEmpty() const;

    Interval add(const Interval &other) const;
    Interval operator+(const Interval &other) const;
    Interval subtract(const Interval &other) const;
    Interval multiply(const Interval &other) const;
    Interval division(const Interval &other) const;

    void print() const;
};

class IntervalVector {
private:
    std::vector<Interval> intervals;

public:
    IntervalVector(size_t size);
    IntervalVector(size_t size, double arr[][2]);

    Interval& operator[](size_t index);
    const Interval& operator[](size_t index) const;

    IntervalVector add(const IntervalVector &other) const;
    IntervalVector multiply(const IntervalVector &other) const;
    IntervalVector subtract(const IntervalVector &other) const;
    IntervalVector division(const IntervalVector &other) const;

    size_t size() const;
    void print() const;
};

#endif // INTERVAL_H
