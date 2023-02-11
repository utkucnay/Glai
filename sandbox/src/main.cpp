#include <Engine.h>

int main() {
	Glai::Engine engine;

	engine.EngineStart();

	while (engine.IsEngineWindowClosed())
	{
		engine.EngineUpdate();
	}

	engine.EngineOnEnd();

	return 0;
}