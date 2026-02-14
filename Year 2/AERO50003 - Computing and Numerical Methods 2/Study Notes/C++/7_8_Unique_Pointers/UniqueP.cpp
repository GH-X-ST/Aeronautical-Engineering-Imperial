/* Unique pointers do not allow the pointer to be shared

cannot copied or passed to a function by value

be used where strict ownership of a resource needs to be enforced

*/

using namespace std

auto x = make_unique<int>(2.0);

unique_ptr<int> y;  // create an empty unique pointer

y = move(x);        // pass ownership of the int to y      