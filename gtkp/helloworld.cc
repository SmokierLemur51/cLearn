#include "helloworld.h"
#include <iostream>

HelloWorld::HelloWorld()
:	m_button("Hello World")
{
	// set border width
	set_border_width(10);

	// when button received the "clicked" symbol, it will call the
	// on_button_clicked() method defined below
	m_button.signal_clicked().connect(sigc::mem_fun(*this, &HelloWorld::on_button_clicked));


	// currently here
	// https://www.gtk.org/docs/language-bindings/cpp/ 
}