// my calendar 

class MyCalendarTwo {
private:
    struct Interval {
        int start, end;
        Interval(int start, int end) : start(start), end(end) {}
        bool operator<(const Interval &other) const {
            return this->end <= other.start;
        }
  
    };
  
  set<Interval> once_booked, twice_booked;

public:
    MyCalendarTwo() : once_booked(set<Interval>()), twice_booked(set<Interval>()) {}

    bool bookInterval(Interval &i) {
        // Determine whether the interval can be booked.
        if (twice_booked.contains(i))
            return false;

        auto [conflict, successful_insertion] = once_booked.insert(i);

        if (successful_insertion)
            return true;

        Interval j = *conflict;
        once_booked.erase(conflict);

        // Promote intersection to twice_booked.
        twice_booked.insert(Interval(max(i.start, j.start), min(i.end, j.end)));

        // Book the edges recursively to promote other
        // intersections of i with intervals in once_booked.
        book(min(i.start, j.start), max(i.start, j.start));
        book(min(i.end, j.end), max(i.end, j.end));

        return true;
    }

    bool book(int start, int end) {
        if (end <= start) return true;
        Interval i = Interval(start, end);
        return bookInterval(i);
    }
};
