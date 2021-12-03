#include "GameManager.h"

using namespace std;

int main()
{
	GameManager demo;
	if (demo.Construct(240, 240, 3, 3))
		demo.Start();

	return 0;
}