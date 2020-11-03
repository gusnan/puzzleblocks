
#ifndef __HEADER_EXAMPLE_EVENTHANDLER_
#define __HEADER_EXAMPLE_EVENTHANDLER_

/**
 * This is an Eventhandler that takes care of the keyboard events, mouse motion
 *	events, and the Quit events. (This event is pushed when you press the close
 * window button for example)
 */
class ExampleEventHandler : public EventHandler
{
public:

	/**
	 * Handle keyboard presses and releases
	 */
	virtual bool handleKeyboard(KeyEvent &keyEvent);

};


#endif /*__HEADER_EXAMPLE_EVENTHANDLER_*/
