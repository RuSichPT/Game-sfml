#include "EventHandler.h"

EventHandler::EventHandler(RenderWindow* window)
{
	this->window = window;
}

void EventHandler::start()
{
	// Обрабатываем события в цикле
	Event event;
	while (window->pollEvent(event))
	{
		// Пользователь нажал на «крестик» и хочет закрыть окно?
		if (event.type == Event::Closed)
			// тогда закрываем его
			window->close();
	}
}
