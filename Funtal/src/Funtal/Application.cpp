#include "ftpch.h"

#include "Application.h"

#include "Funtal/Events/Application.h"
#include "Funtal/Log.h"

namespace Funtal
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			FT_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			FT_TRACE(e);
		}
		while (true);
	}

}