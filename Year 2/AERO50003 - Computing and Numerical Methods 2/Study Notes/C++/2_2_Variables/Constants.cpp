// Using const to mark a variable as constant
// cannot be changed after it has been declared

const double vPi = 3.14159;
const double vLight = 299792458; // m/s

// Compile-time constant
// possible to evaluate at compile-time

constexpr double vPi = 3.14159;            // valid as known at compile-time
constexpr double vTime = getCurrentTime(); // almost certainly not valid