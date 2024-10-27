#pragma once

#include <iostream>
#include "../raymath/Color.hpp"

/** 
 * @class Image
 * @brief Initialize an image with a width and a height
 **/
class Image
{
private:
  unsigned int width = 0;
  unsigned int height = 0;
  std::vector<Color> buffer;
public:
  /** 
   * @brief Initialize an image with a width and a height
   * @param w : width of the image
   * @param h : height of the image
   **/
  Image(unsigned int w, unsigned int h);
  /** 
   * @brief Initialize an image with a width, a height and a background color
   * @param w : width of the image
   * @param h : height of the image
   * @param c : color of the image
   **/
  Image(unsigned int w, unsigned int h, Color c);
  /** 
   * @brief Destructor of the image
   * @details Free the memory allocated for the image
   **/
  ~ Image();

  /** 
   * @brief Set the color of a pixel in the image
   * @param x : x coordinate of the pixel
   * @param y : y coordinate of the pixel
   * @param color : color of the pixel
   **/
  void SetPixel(unsigned int x, unsigned int y, Color color);
  /** 
   * @brief Get the color of a pixel in the image
   * @param x : x coordinate of the pixel
   * @param y : y coordinate of the pixel
   * @return Color : color of the pixel
   **/
  Color GetPixel(unsigned int x, unsigned int y);

  /** 
   * @brief Write the image to a file
   * @param filename : name of the file
   **/
  void WriteFile(const char* filename);
};