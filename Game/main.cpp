#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "SDL2_ttf.lib")

#include <ctime>
#include "../MVC/Game.h"

int main() {

	srand(std::time(nullptr));

	Game game;

	return 0;
}