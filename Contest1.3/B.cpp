#include <list>

using std::list;

list<int> merge(const list<int> &first, const list<int> &second) {
    std::list<int> list(0);
    auto i = first.begin();
    auto j = second.begin();
    while (i != first.end() || j != second.end()) {
        if (i != first.end() && j != second.end()) {
            if (*i > *j) {
                list.push_back(*j);
                ++j;
            } else {
                list.push_back(*i);
                ++i;
            }
            continue;
        }
        if (i != first.end()) {
            list.push_back(*i);
            ++i;
            continue;
        }
        if (j != second.end()) {
            list.push_back(*j);
            ++j;
            continue;
        }
    }
    return list;
}