#include "EventHandler.h"

EventHandler::EventHandler(RenderWindow* window)
{
	this->window = window;
}

void EventHandler::start()
{
	// ������������ ������� � �����
	Event event;
	while (window->pollEvent(event))
	{
		// ������������ ����� �� �������� � ����� ������� ����?
		if (event.type == Event::Closed)
			// ����� ��������� ���
			window->close();
	}
}
