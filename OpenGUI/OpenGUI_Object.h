// OpenGUI (http://opengui.sourceforge.net)
// This source code is release under the BSD License
// See LICENSE.TXT for details

#ifndef AC660DA3_935C_49BC_AB5A_0CC6BBFBFA8E
#define AC660DA3_935C_49BC_AB5A_0CC6BBFBFA8E

#include "OpenGUI_PreRequisites.h"
#include "OpenGUI_Exports.h"
#include "OpenGUI_HandledObject.h"
#include "OpenGUI_Event.h"
#include "OpenGUI_EventHandler.h"

namespace OpenGUI {

	class ObjectAccessorList; //forward declaration
	class Value;
	class ValueList;

	//! Base class for all GUI objects. Provides an exposed interface to the Accessor and Event systems.
	class OPENGUI_API Object: public HandledObject {
	public:
		Object();
		virtual ~Object();

		//! returns the value of \c propertyName via \c valueOut
		void getProperty( const std::string& propertyName, Value& valueOut );
		//! sets the value of \c propertyName to the contents of \c valueIn
		void setProperty( const std::string& propertyName, Value& valueIn );
		//! invokes \c methodName, sending \c paramIn as arguments, and catching return values in \c returnOut
		void callMethod( const std::string& methodName, ValueList& paramIn, ValueList& returnOut );

		//! triggers the event of the given \c eventName, sending the given \c evtArgs
		/*!	\param eventName The name of the event to trigger
			\param evtArgs The EventArgs based event data, by reference */
		void triggerEvent( const std::string& eventName, EventArgs& evtArgs ) {
			getEvents()[eventName].invoke( this, evtArgs );
		}
		//############################################################################

		//! returns this object's ObjectAccessorList head
		virtual ObjectAccessorList* getAccessors();
		//! Returns the most specific class name available for this object
		/*! \note Developers, make sure you override this function in your Object derived classes. */
		virtual char* getClassName();

		//! Returns the Event::EventReceiver for this Object instance
		EventReceiver& getEvents();

	private:
		EventReceiver mEventReceiver;
	};

}//namespace OpenGUI{

#endif
