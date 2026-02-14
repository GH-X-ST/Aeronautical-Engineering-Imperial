// set // associative container stores unique elements
// elements are referenced by their key (its value) rather than their position
// store elements ordered by their value

// set<datatype> identifier;
set<int> s;

#include <set> // For STL std::set

using namespace std;


// unorderd set // for C++11 // does not order elements

// unordered_set<datatype> identifier

#include <unorderedset> // For STL std::unordered_set


// pair // associate two independently-typed value together

// pair<first-type, second-type> identifier;

#include <utility> // For STL std::pair

pair<int, double> p(42, 3,14159);

cout << "The meaning of life is " << p.first << endl;
cout << "The value of pi is " << p.second << endl;

