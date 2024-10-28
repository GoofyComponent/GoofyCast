#include <iostream>
#include "Color.hpp"
#include "Image.hpp"
#include "Uinputs.hpp"

using namespace std;


int main()
{    
    UserInputs userInputs;
    
    Color red(1, 0, 0);
    Color black;

    cout << "Red : " << red << std::endl;
    cout << "Black : " << black << std::endl;

    int WIDTH = userInputs.AskIntInput("Enter the width of the image : ");
    int HEIGHT = userInputs.AskIntInput("Enter the height of the image : ");

    Image image(WIDTH, HEIGHT, black);

    int centerX = WIDTH / 2;
    int centerY = HEIGHT / 2;
    int radius = min(WIDTH, HEIGHT) / 4;
    int currentPercentage = 0;

    for (int y = 0; y < HEIGHT; y++) {
        if ((y * 100) / HEIGHT > currentPercentage) {
            std::cout << "\033[2J\033[1;1H";
            currentPercentage = (y * 100) / HEIGHT;
            std::cout << "Percentage calculated : " << (y * 100) / HEIGHT << "%" << std::endl;
        }

        for (int x = 0; x < WIDTH; x++) {
            if ((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) < radius * radius) {
                image.SetPixel(x, y, red);
            }
        }
    }
    
    image.WriteFile("../../../circle.png");
}