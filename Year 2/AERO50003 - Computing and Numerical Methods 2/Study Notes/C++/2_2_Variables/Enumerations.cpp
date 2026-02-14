// enum // simple custom data type

enum Colour 
{
red,        // red    -> 0 for first name (implicitly chosen)
green = 5,  // green  -> 5
blue,       // blue   -> 6 = 5 + 1 (implicitly chosen)
yellow = 10 // yellow -> 10
};

Colour c = blue;
int x = c   // x == 6