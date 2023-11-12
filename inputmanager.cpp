#include "inputmanager.h"
#include <SFML/Graphics.hpp>

InputManager::InputManager(sf::RenderWindow& _window) : window(_window) 
{
//	button.left = button.right = button.up = button.down = button.space
//		= button.escape = button.a = button.z = button.e = button.r = button.t = button.t = button.y = button.u = button.i = button.o = button.p = button.q = button.s = button.d = button.f = button.g = button.h = button.j = button.k = button.l = button.m = button.w = button.x = button.c = button.v = button.b = button.n = false;
}

bool InputManager::GetButton(sf::Keyboard::Key eKey) const
{
	auto it = maps.find(eKey);
	
	if (it == maps.end())
		return false;

	return it->second;
}

void InputManager::InputHandler(Event event, RenderWindow& window)
{

	if (event.type == Event::Closed)
	{
		window.close();
	}

	//key pressed
	if (event.type == Event::KeyPressed)
	{

		maps[event.key.code] = true; // ça eneleve tout le switch

		/*switch (event.key.code)
		{
		case Keyboard::Escape:
			button.escape = true;
			break;

		case Keyboard::Down:
			button.down = true;
			break;

		case Keyboard::Up:
			button.up = true;
			break;

		case Keyboard::Left:
			button.left = true;
			break;

		case Keyboard::Right:
			button.right = true;
			break;

		case Keyboard::Space:
			button.space = true;
			break;

		case Keyboard::A:
			button.a = true;
			break;
		
		case Keyboard::Z:
			button.z = true;
			break;

		case Keyboard::E:
			button.e = true;
			break;

		case Keyboard::R:
			button.r = true;
			break;

		case Keyboard::T:
			button.t = true;
			break;

		case Keyboard::Y:
			button.y= true;
			break;

		case Keyboard::U:
			button.u = true;
			break;

		case Keyboard::I:
			button.i = true;
			break;

		case Keyboard::O:
			button.o = true;
			break;

		case Keyboard::P:
			button.p = true;
			break;

		case Keyboard::Q:
			button.q= true;
			break;

		case Keyboard::S:
			button.s= true;
			break;

		case Keyboard::D:
			button.d = true;
			break;

		case Keyboard::F:
			button.f = true;
			break;

		case Keyboard::G:
			button.g = true;
			break;

		case Keyboard::H:
			button.h = true;
			break;

		case Keyboard::J:
			button.j = true;
			break;

		case Keyboard::K:
			button.k = true;
			break;

		case Keyboard::L:
			button.l = true;
			break;

		case Keyboard::M:
			button.m = true;
			break;

		case Keyboard::W:
			button.w = true;
			break;

		case Keyboard::X:
			button.x = true;
			break;

		case Keyboard::C:
			button.c = true;
			break;

		case Keyboard::V:
			button.v = true;
			break;

		case Keyboard::B:
			button.b = true;
			break;

		case Keyboard::N:
			button.n = true;
			break;




		}*/

	}

	//key released
	if (event.type == Event::KeyReleased)
	{

		maps[event.key.code] = false; // ça eneleve tout le switch

		/*switch (event.key.code)
		{
		case Keyboard::Escape:
			button.escape = false;
			break;

		case Keyboard::Down:
			button.down = false;
			break;

		case Keyboard::Up:
			button.up = false;
			break;

		case Keyboard::Left:
			button.left = false;
			break;

		case Keyboard::Right:
			button.right = false;
			break;

		case Keyboard::Space:
			button.space = false;
			break;

		case Keyboard::A:
			button.a = false;
			break;

		case Keyboard::Z:
			button.z = false;
			break;

		case Keyboard::E:
			button.e = false;
			break;

		case Keyboard::R:
			button.r = false;
			break;

		case Keyboard::T:
			button.t = false;
			break;

		case Keyboard::Y:
			button.y = false;
			break;

		case Keyboard::U:
			button.u = false;
			break;

		case Keyboard::I:
			button.i = false;
			break;

		case Keyboard::O:
			button.o = false;
			break;

		case Keyboard::P:
			button.p = false;
			break;

		case Keyboard::Q:
			button.q = false;
			break;

		case Keyboard::S:
			button.s = false;
			break;

		case Keyboard::D:
			button.d = false;
			break;

		case Keyboard::F:
			button.f = false;
			break;

		case Keyboard::G:
			button.g = false;
			break;

		case Keyboard::H:
			button.h = false;
			break;

		case Keyboard::J:
			button.j = false;
			break;

		case Keyboard::K:
			button.k = false;
			break;

		case Keyboard::L:
			button.l = false;
			break;

		case Keyboard::M:
			button.m = false;
			break;

		case Keyboard::W:
			button.w = false;
			break;

		case Keyboard::X:
			button.x = false;
			break;

		case Keyboard::C:
			button.c = false;
			break;

		case Keyboard::V:
			button.v = false;
			break;

		case Keyboard::B:
			button.b = false;
			break;

		case Keyboard::N:
			button.n = false;
			break;
		}*/
	}

}

