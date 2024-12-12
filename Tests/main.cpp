#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "MVC.lib")


#include "TestClient.h"
#include "GameModelTests.h"

int main() {

	TestClient client;

	AddTest(client, undoLastCommand);
	AddTest(client, createMissileTest);
	AddTest(client, moveMissileTest);

	client.run();
}

