#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_image.lib")

#include <ctime>
#include "../MVC/Game.h"

int main() {

	srand(std::time(nullptr));

	Game game;

	return 0;
}