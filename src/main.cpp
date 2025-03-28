#include "tga.h"
#include <iostream>
#include <algorithm>

int main() {
    Image layer1 = readImage("layer1");
    Image layer2 = readImage("layer2");
    Image pattern1 = readImage("pattern1");
    Image pattern2 = readImage("pattern2");
    Image car = readImage("car");
    Image circles = readImage("circles");
    Image text = readImage("text");
    Image text2 = readImage("text2");
    Image layer_blue = readImage("layer_blue");
    Image layer_green = readImage("layer_green");
    Image layer_red = readImage("layer_red");

    output(layer1 * pattern1, "part1");
    output(car - layer2, "part2");
    output(screen(layer1 * pattern2, text), "part3");
    output((layer2 * circles) - pattern2, "part4");
    output(overlay(layer1, pattern1), "part5");

    Image part6 = readImage("car");
    for (int i = 0; i < part6.pixels.size(); i++) {
        part6.pixels[i].G = std::min(255, part6.pixels[i].G + 200);
    }
    output(part6, "part6");

    Image part7 = readImage("car");
    for (int i = 0; i < part6.pixels.size(); i++) {
        part7.pixels[i].R = std::min(255, part7.pixels[i].R * 4);
        part7.pixels[i].B = 0;
    }
    output(part7, "part7");

    Image part8_b = Image(car.header, std::vector<Pixel>());
    Image part8_g = Image(car.header, std::vector<Pixel>());
    Image part8_r = Image(car.header, std::vector<Pixel>());
    for (int i = 0; i < car.pixels.size(); i++) {
        part8_b.pixels.push_back(Pixel(car.pixels[i].B,car.pixels[i].B,car.pixels[i].B));
        part8_g.pixels.push_back(Pixel(car.pixels[i].G,car.pixels[i].G,car.pixels[i].G));
        part8_r.pixels.push_back(Pixel(car.pixels[i].R,car.pixels[i].R,car.pixels[i].R));
    }
    output(part8_b, "part8_b");
    output(part8_g, "part8_g");
    output(part8_r, "part8_r");

    Image part9 = Image(layer_blue.header, std::vector<Pixel>());
    for (int i = 0; i < layer_blue.pixels.size(); i++) {
        part9.pixels.push_back(Pixel(layer_blue.pixels[i].B,layer_green.pixels[i].G,layer_red.pixels[i].R));
    }
    output(part9, "part9");

    std::reverse(text2.pixels.begin(), text2.pixels.end());
    output(text2, "part10");
    return 0;
}
