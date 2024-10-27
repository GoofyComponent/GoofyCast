#pragma once

#include <iostream>

/** 
 * @class Color
 * @brief Initialize a color with 3 components : Red, Green and Blue
**/
class  Color
{
private:
  float r = 0;
  float b = 0;
  float g = 0;
public:
  Color();
  Color(float r, float g, float b);
  ~ Color();

  float R();
  float G();
  float B();

  Color operator+(Color const& col);
  Color& operator=(Color const& col);
  friend std::ostream & operator<<(std::ostream & _stream, Color const & col);
};