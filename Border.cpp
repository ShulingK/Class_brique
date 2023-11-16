#include "Border.h"

Border::Border(float _posX, float _posY, float _width, float angle, float _height, const sf::Color color, int layer, bool _isBounceable) 
    : GameObject(_posX, _posY, _width, angle, _height, color, layer)
{
    isBouceable = _isBounceable;
}