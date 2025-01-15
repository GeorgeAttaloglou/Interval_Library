// Compilers semester 7th

#include <iostream>
#include <stdexcept>
#include <limits>

class Interval
{
private:
    double lower_bound; // 2 private variable για την εισαγωγη του κατω οριου και του ανω οριου
    double upper_bound;
    bool is_empty; // Μεταβλητη τυπου bool ειναι true ή false

public:
    // Constructor
    Interval() : lower_bound(0), upper_bound(0), is_empty(true) {}

    Interval(double lower, double upper) // Αρχικοποιηση του διαστηματος με τα δοσμενα κατω και ανω ορια
    {
        if (lower > upper) // Συγκρηση αν το κατω οριο ειναι μεγαλυτερο απο το ανω
        {
            std::cout << "Lower bound must be less than or equal to upper bound."; // Αν ισχυει βγαζει error
            lower_bound = 0;                                                       // Εισαγωγη 0 ετσι ωστε σε περιπτωση εισαγωγης λαθος τιμης να υπαρχει ενα γνωστο default value χωρις να crasharei το program
            upper_bound = 0;
        }
        else
        {
            lower_bound = lower; // Εισαγει τις τιμες του κατω και ανω οριου
            upper_bound = upper;
            is_empty = false;
        }
    }

    // Στατικος τροπος δημιουργιας empty interval
    static Interval Empty()
    {
        return Interval();
    }

    // Στατικος τροπος δημιουργιας inf interval
    static Interval infinite()
    {
        return Interval(-std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity());
    }

    // Getter functions
    double lower() const
    {
        if (is_empty)
        {
            std::cout << "Interval is empty";
        }
        return lower_bound;
    }

    double upper() const
    {
        if (is_empty)
        {
            std::cout << "Interval is empty.";
        }
        return upper_bound;
    }

    bool isEmpty() const
    {
        return is_empty;
    }

    // Add two intervals
    Interval add(const Interval &other) const // Ληψει ενος αλλου αντικειμενου Interval ως αναφορα για να αποφευχθει η αντιγραφη
    {
        return Interval(lower_bound + other.lower_bound, upper_bound + other.upper_bound); // Δημιουργια ενος νεου Interval αντικειμενου με την τελικη προσθεση
    }

    // Subtract two intervals
    Interval subtract(const Interval &other) const // Ιδιο με το απο πανω
    {
        return Interval(lower_bound - other.upper_bound, upper_bound - other.lower_bound); // Δημιουργια ενος νεου Interval αντικειμενου με την τελικη αφαιρεση
    }

    // Multiply two intervals
    Interval multiply(const Interval &other) const // Ιδιο με το απο πανω
    {
        double ll = lower_bound * other.lower_bound;
        double lu = lower_bound * other.upper_bound;
        double ul = upper_bound * other.lower_bound;
        double uu = upper_bound * other.upper_bound; // Υπολογισμος ολων των πιθανων γινομενω των οριων

        double new_lower = ll; // Υποθεση οτι το ll ειναι το μικροτερο γινομενο
        if (lu < new_lower)
            new_lower = lu;
        if (ul < new_lower)
            new_lower = ul;
        if (uu < new_lower)
            new_lower = uu;

        double new_upper = ll;
        if (lu > new_upper)
            new_upper = lu;
        if (ul > new_upper)
            new_upper = ul;
        if (uu > new_upper)
            new_upper = uu;

        return Interval(new_lower, new_upper);
    }

    // Divide 2 intervals
    Interval division(const Interval &other) const
    {
        if (is_empty || other.is_empty)
        {
            return Empty();
        }
        if (other.lower_bound <= 0 && other.upper_bound >= 0)
        {
            std::cout << "\nDivision with 0 cant happen.";
            return Interval();
        }

        double ll = lower_bound / other.lower_bound;
        double lu = lower_bound / other.upper_bound;
        double ul = upper_bound / other.lower_bound;
        double uu = upper_bound / other.upper_bound;

        double new_lower = ll; // Ιδιος τροπος με το multiplication
        if (lu < new_lower)
            new_lower = lu;
        if (ul < new_lower)
            new_lower = ul;
        if (uu < new_lower)
            new_lower = uu;

        double new_upper = ll;
        if (lu > new_upper)
            new_upper = lu;
        if (ul > new_upper)
            new_upper = ul;
        if (uu > new_upper)
            new_upper = uu;

        return Interval(new_lower, new_upper);
    }
    // Εκτυπωση interval
    void print() const
    {
        if (is_empty)
        {
            std::cout << "Empty Interval";
        }
        else
        {
            std::cout << "[" << lower_bound << ", " << upper_bound << "]";
        }
    }
};

int main()
{

    // Δημιουργια 2 intervals
    Interval x(4.0, 2.0); // Interval [1.0, 2.0]
    Interval y(0.0, 0.0); // Interval [3.0, 4.0]
    Interval empty = Interval::Empty();
    Interval infinites = Interval::infinite();

    // Προσθεση και πολλαπλασιασμος intervals
    Interval sum = x.add(y);
    Interval multipli = x.multiply(y);
    Interval subtraction = x.subtract(y);
    Interval divide = x.division(y);

    // Αποτελεσματα
    std::cout << "\nSum: ";
    sum.print(); // Expected: [6.0, 9.0]
    std::cout << "\nMultiplication: ";
    multipli.print(); // Expected: [8.0, 18.0]
    std::cout << "\nSubtraction ";
    subtraction.print(); // Expected: [2.0, 3.0]
    std::cout << "\nDivision ";
    divide.print(); // Expected: [2.0, 2.0]
    std::cout << "\nInterval is a ";
    empty.print();
    std::cout << "\nInfinity ";
    infinites.print();
    std::cout << std::endl;

    return 0;
}