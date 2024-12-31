// Compilers semester 7th

#include <iostream>
#include <stdexcept> //Για τα exceptions

class Interval
{
private:
    double lower_bound; // 2 private variable για την εισαγωγη του κατω οριου και του ανω οριου
    double upper_bound;

public:
    // Constructor
    Interval(double lower, double upper) // Αρχικοποιηση του διαστηματος με τα δοσμενα κατω και ανω ορια
    {
        if (lower > upper) // Συγκρηση αν το κατω οριο ειναι μεγαλυτερο απο το ανω
        {
            throw std::invalid_argument("Lower bound must be less than or equal to upper bound."); // Αν ισχυει βγαζει error
        }
        lower_bound = lower; // Εισαγει τις τιμες του κατω και ανω οριου
        upper_bound = upper;
    }

    // Getter functions
    double lower() const
    {
        return lower_bound;
    }

    double upper() const
    {
        return upper_bound;
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

    // Εκτυπωση interval
    void print() const
    {
        std::cout << "[" << lower_bound << ", " << upper_bound << "]";
    }
};

int main()
{
    try
    {
        // Δημιουργια 2 intervals
        Interval x(4.0, 6.0); // Interval [1.0, 2.0]
        Interval y(3.0, 4.0); // Interval [3.0, 4.0]

        // Προσθεση και πολλαπλασιασμος intervals
        Interval sum = x.add(y);
        Interval product = x.multiply(y);
        Interval subtraction = x.subtract(y);

        // Αποτελεσματα
        std::cout << "Sum: ";
        sum.print(); // Expected: [7.0, 10.0]
        std::cout << "\nProduct: ";
        product.print(); // Expected: [12.0, 24.0]
        std::cout << "\nSubtraction ";
        subtraction.print(); // Expected: [1.0, 2.0]
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}