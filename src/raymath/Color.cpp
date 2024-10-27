#include <iostream>
#include "Color.hpp"

Color:: Color() : r(0), b(0), g(0)
{  
}

Color:: Color(float iR, float iG, float iB) : r(iR), g(iG), b(iB)
{  
}

Color::~ Color()
{
}

float Color::R()
{
  return r;
}

float Color::G()
{
  return g;
}

float Color::B()
{
  return b;
}

/**
 * Implementation of the + operator :
 * Adding two colors is done by just adding the different components together :
 * (r1, g1, b1) + (r2, g2, b2) = (r1 + r2, g1 + g2, b1 + b2)
 */
Color Color::operator+(Color const& col) {
  Color c;
  c.r = fmax(fmin(r + col.r, 1), 0);
  c.g = fmax(fmin(g + col.g, 1), 0);
  c.b = fmax(fmin(b + col.b, 1), 0);
  return c;
}

/**
 * Overriding the assignment operator
 */
Color& Color::operator=(Color const& col) {
  r = col.r;
  g = col.g;
  b = col.b;
  return *this;
}

/**
 * @brief Overriding the output stream operator.
 * 
 * This function outputs the color components (r, g, b) of a Color object
 * to an output stream.
 * 
 * @param _stream The output stream.
 * @param col The Color object to output.
 * @return std::ostream& A reference to the output stream.
 */
std::ostream & operator<<(std::ostream & _stream, Color const & col) {  
  return _stream << "(" << col.r << "," << col.g << "," << col.b << ")";
}