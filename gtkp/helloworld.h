#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window 
{

public:
	HelloWorld();
	virtual ~HelloWorld();

protected:
	// Signal Handlers
	void on_button_clicked();

	// Member Widgets
	Gtk::Button m_button;
};

#endif