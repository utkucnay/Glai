#include <Engine.h>

int main() {
	Engine::Engine engine;

	engine.EngineStart();

	while (engine.IsEngineWindowClosed())
	{
		engine.EngineUpdate();
	}

	engine.EngineOnEnd();

	return 0;
}