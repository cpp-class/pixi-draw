#ifndef PIXIENGINE_HPP_
#define PIXIENGINE_HPP_

#include "raylib.h"
#include <vector>

namespace pixi
{

void draw_bitmap(const std::vector<unsigned char> bitmap, int x, int y, int pixel_size, int pad, int width, Color color);

void draw_bitmap(const std::vector<unsigned char> bitmap, int x, int y, int pixel_size, int pad, int width, Color color, bool is_circle);

void draw_bitmap(const std::vector<unsigned char> bitmap, int x, int y, int pixel_size, int pad, int width, Color color_pixel, Color color_back, bool is_circle);


}

#endif /* PIXIENGINE_HPP_ */
