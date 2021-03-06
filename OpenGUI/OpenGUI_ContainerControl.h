// OpenGUI (http://opengui.sourceforge.net)
// This source code is released under the BSD License
// See LICENSE.TXT for details

#ifndef C98415A7_E835_4241_AC5B_7DB94CB10233
#define C98415A7_E835_4241_AC5B_7DB94CB10233

#include "OpenGUI_PreRequisites.h"
#include "OpenGUI_Exports.h"
#include "OpenGUI_String.h"
#include "OpenGUI_Types.h"
#include "OpenGUI_Widget.h"
#include "OpenGUI_WidgetCollection.h"
#include "OpenGUI_Control.h"

namespace OpenGUI {

	class Brush_Caching; // forward declaration

	//! base class for all Controls that are also containers
	/*!
	In addition to simply being a Control that contains child Controls, this Widget
	also supplies an automatic layout system that will reposition and resize child controls
	according to their exposed layout preferences. Additionally, the results of draw operations
	from this object, as well as its children, are cached by this object to provide speed
	increases.

	\note
	If a subclass wishes to restrict the client area (the rect within the container in which
	contained widgets are drawn) to a smaller area, it will need to modify m_ClientAreaOffset_UL
	and m_ClientAreaOffset_LR as appropriate to reflect the desired client area. The default
	values for both of these is (0.0fx0.0f), which will result in the full area of the container
	being used as client area.

	\par Properties
		- Padding: setPadding(), getPadding()
		- ConsumeInput: setConsumeInput(), getConsumeInput()

	\par Events Introduced
		- \ref Event_ChildAttached "ChildAttached"
		- \ref Event_ChildDetached "ChildDetached"
		- \ref Event_DrawBG "DrawBG"

	\see \ref EventList_ContainerControl "ContainerControl Events"
	*/
	class OPENGUI_API ContainerControl : public Control, WidgetCollectionListener {
	public:
		//! public constructor
		ContainerControl();
		//! public destructor
		virtual ~ContainerControl();

		//! sets the padding of this container
		void setPadding( float padding );
		//! gets the current padding of this container
		float getPadding();

		//! toggles auto consumption of input that occurs inside this container, preventing it from reaching overdrawn widgets. Default is \c TRUE
		void setConsumeInput( bool consume );
		//! retrieves current ConsumeInput setting
		bool getConsumeInput();

		//! suspends automatic layout updates until resumeLayout() is called
		void suspendLayout();
		//! resumes automatic layout updates and performs an immediate layout update if the current layout is out of date
		void resumeLayout();
		//! returns true if the current layout schema is still valid
		bool layoutValid();
		//! Performs the layout operation for child widgets, marking the new layout as valid.
		void updateLayout();
		//! Marks the current layout schema as invalid.
		void invalidateLayout();

		//! \internal In addition to previous functionality, this adds a "DrawBG" operation and calls the children _draw between the foreground and background onDraws
		virtual void _draw( Brush& brush );

		//! \internal Calls base class _tick() function and passed the Tick on to all children
		virtual void _tick( float seconds );

		//! Collection of child widgets that are contained by this ContainerControl
		WidgetCollection Children;

		//Object Functions
		virtual ObjectAccessorList* getAccessors();
		virtual unsigned int getObjectType() const;

		// reimplementations from Widget
		virtual void _translatePointIn( FVector2& point );
		virtual void _translatePointOut( FVector2& point );

		virtual void _doflush();

		virtual void _sendToChildren_CursorMove( Cursor_EventArgs& moveEvent );
		virtual void _sendToChildren_CursorPress( Cursor_EventArgs& pressEvent );
		virtual void _sendToChildren_CursorRelease( Cursor_EventArgs& releaseEvent );

	protected:
//!\name Event Injectors
//@{
		//! Draw this object's background using the given brush
		void eventDrawBG( Brush& brush );
		//! A new child has been attached to this container
		void eventChildAttached( WidgetCollection* container, Widget* newChild );
		//! A child has been detached from this container
		void eventChildDetached( WidgetCollection* container, Widget* prevChild );
		//! A child of this container has been invalidated
		void eventInvalidatedChild();
//@}

//!\name Event Handlers
//@{
		//! "DrawBG" event
		virtual void onDrawBG( Object* sender, Draw_EventArgs& evtArgs );
		//! "ChildAttached" event
		virtual void onChildAttached( Object* sender, Attach_EventArgs& evtArgs );
		//! "ChildDetached" event
		virtual void onChildDetached( Object* sender, Attach_EventArgs& evtArgs );

		//! Flushes the local Brush output cache that contains operations from this and all child Widgets
		virtual void onInvalidated( Object* sender, EventArgs& evtArgs );
		//! Invalidates this widget, which causes a flush of the local cache of child operations
		virtual void onInvalidatedChild( Object* sender, EventArgs& evtArgs );

		//! flushes local Brush cache in addition to normal functionality
		virtual void onResized( Object* sender, Resized_EventArgs& evtArgs );

		//! "CursorMove" event, only allows Control to consume if ConsumeInput is \c true
		virtual void onCursorMove( Object* sender, Cursor_EventArgs& evtArgs );
		//! "CursorPress" event, only allows Control to consume if ConsumeInput is \c true
		virtual void onCursorPress( Object* sender, Cursor_EventArgs& evtArgs );
		//! "CursorRelease" event, only allows Control to consume if ConsumeInput is \c true
		virtual void onCursorRelease( Object* sender, Cursor_EventArgs& evtArgs );
//@}

		//! Returns the client area position and size as an FRect
		const FRect& getClientArea();

		//! The client area offset from the upper left of the ContainerControl
		FVector2 m_ClientAreaOffset_UL;
		//! The client area offset from the lower right of the ContainerControl
		FVector2 m_ClientAreaOffset_LR;
		//! Signifies if this container should clip the output of its children against the defined client area
		/*! It is important to note that children will always be clipped against the rect bounds of the
		container (either implicitly from a render to texture context, or forcibly by a ClippingRect).
		This option is merely present to supply an enforced rect clipping of child output in the event that
		you are not drawing a solid border in the area between the edge of the control and the edge of the
		client area. The default is \c false. */
		bool m_ClipChildren;

		//! This performs the actual layout operation
		virtual void _doUpdateLayout();

		//! \internal virtual implementation for getChildrenAt(). Hidden because overriding is almost always unnecessary
		virtual void _getChildrenAt( const FVector2& position, WidgetPtrList& outList, bool recursive );
		//! \internal virtual implementation for getChildAt(). Hidden because overriding is almost always unnecessary
		virtual Widget* _getChildAt( const FVector2& position, bool recursive );

		//! \internal reimplementation from Widget. This will return the requested child if it exists, otherwise returns 0
		Widget* _getChildByName( const String& childName ) const;

		//! \internal redefinition from Widget::_invalidatedChild()
		virtual void _invalidatedChild();

		//! flushes the local draw cache. Causes a call to invalidate() automatically
		void dirtyCache();
		//! returns \c true if the local cache is dirty
		bool isCacheDirty() const;
		//! retrieves a Brush reference to the underlying cache. Should only be used within _draw() overloads
		Brush_Caching& _getCacheBrush();

	private:
		void _setChildControlLayoutState( bool state );
		bool m_LayoutSuspended; // state variable: marks if layouts are suspended
		bool m_LayoutValid; // state variable: holds layout validity
		bool m_InUpdateLayout; // state variable: true if currently running updateLayout()
		Brush_Caching* mCacheBrush;
		void onDetached_BrushCache( Object* sender, Attach_EventArgs& evtArgs );

		float mPadding; // holds the padding of the container

		bool mConsumeInput; // holds setting to auto-consume input that occurs within this container
	};

} // namespace OpenGUI{

#endif // C98415A7_E835_4241_AC5B_7DB94CB10233
