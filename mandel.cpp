#include <iostream>

constexpr int mandel(double cr, double ci) {
    double zr = 0, zi = 0;
    int i = 0;
    while (i < 30 && zr * zr + zi * zi <= 4) {
        double t = zr * zr - zi * zi + cr;
        zi = 2 * zr * zi + ci;
        zr = t;
        ++i;
    }
    return i;
}

int main() {
    const char* shades = " .:-=+*#%@";
    for (double y = -1.2; y <= 1.2; y += 0.1) {
        for (double x = -2.0; x <= 0.6; x += 0.04)
            std::cout << shades[mandel(x, y) * 9 / 30];
        std::cout << '\n';
    }
}
