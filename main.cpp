#include <iostream>
#include <SFML/Graphics.hpp>

#include "gameobject.h"
#include "gamemanager.h"
#include "inputmanager.h"
#include "windowmanager.h"
#include "ball.h"
#include "canon.h"
#include "brick.h"
#include "border.h"
#include "levelmanager.h"

int main(int argc, char** argv)
{
    GameManager::getInstance().Game();
}




