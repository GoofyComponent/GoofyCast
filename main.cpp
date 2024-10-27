#include <iostream>
#include "Color.hpp"
#include "Image.hpp"

using namespace std;

void generateAmogus() {
    Color backgroundColor(1, 1, 1);
    Color susColor(1, 0, 0);
    Color impostorColor(0, 0, 1);


    const int ROWS = 4;
    const int COLS = 4;

    Image image(ROWS, COLS, backgroundColor);


    bool susAmogus[ROWS][COLS];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            susAmogus[i][j] = false;
        }
    }

    susAmogus[1][0] = true;
    susAmogus[2][0] = true;
    susAmogus[3][0] = true;
    susAmogus[0][1] = true;
    susAmogus[1][1] = true;
    susAmogus[0][2] = true;
    susAmogus[1][2] = true;
    susAmogus[2][2] = true;
    susAmogus[3][2] = true;
    susAmogus[1][3] = true;
    susAmogus[3][3] = true;


    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (susAmogus[i][j]) {
                image.SetPixel(i, j, susColor);
            }
        }
    }

    image.WriteFile("amogus.png");
}

int main()
{    
    Color red(1, 0, 0);
    Color green(0, 1, 0);
    Color black;

    cout << "Red : " << red << std::endl;
    cout << "Green : " << green << std::endl;
    cout << "Black : " << black << std::endl;

    Color yellow = red + green;

    cout << "Yellow : " << yellow << std::endl;

    // Create an image in memory, and fill it with yellow
    Image image(512, 512, yellow);

    // Make a red square on the top left of the image
    for (int y = 0; y < 100; y++) {
      for (int x = 0; x < 100; x++) {
        image.SetPixel(x, y, Color(1, 0, 0));
      }
      for (int x = 200; x < 300; x++) {
        image.SetPixel(x, y, Color(1, 1, 1));
      }
    }
    
    image.WriteFile("test.png");

    generateAmogus();
}