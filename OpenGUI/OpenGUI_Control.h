// OpenGUI (http://opengui.sourceforge.net)
// This source code is released under the BSD License
// See LICENSE.TXT for details

#ifndef F9497A73_9AD4_4241_8A38_7566DBC752BE
#define F9497A73_9AD4_4241_8A38_7566DBC752BE

#include "OpenGUI_PreRequisites.h"
#include "OpenGUI_Exports.h"
#include "OpenGUI_Types.h"
#include "OpenGUI_Widget.h"
#include "OpenGUI_Cursor.h"

namespace OpenGUI {
	class ContainerControl; //forward declaration

	//! Base class for all GUI objects that have position and size
	/*!
	\par Properties
	- Left: setLeft(), getLeft()
	- Top: setTop(), getTop()
	- Width: setWidth(), getWidth()
	- Height: setHeight(), getHeight()
	- Position: getPosition()
	- Size: getSize()
	- Rect: getRect()
	- Visible: setVisible(), getVisible()
	- Alpha: setAlpha(), getAlpha()
	- Margin: setMargin(), getMargin()

	\par Events Introduced
		- \ref Event_Moved "Moved"
		- \ref Event_Resized "Resized"
		- \ref Event_CursorEnter "CursorEnter"
		- \ref Event_CursorLeave "CursorLeave"
		- \ref Event_Targeted "Targeted"
		- \ref Event_UnTargeted "UnTargeted"
	\see \ref EventList_Control "Control Events"
	*/
	class OPENGUI_API Control : public Widget {
		friend class ContainerControl; //needed for layout state protection
	public:
		//! public constructor
		Control();
		//! public destructor
		virtual ~Control();

		//! Sets the position of the left side of the Control
		void setLeft( float left );
		//! Returns the position of the left side of the Control
		float getLeft();
		//! Sets the position of the top side of the Control
		void setTop( float top );
		//! Returns the position of the top side of the Control
		float getTop();
		//! Sets the width of the Control
		void setWidth( float width );
		//! Returns the width of the Control
		float getWidth();
		//! Sets the height of the Control
		void setHeight( float height );
		//! Returns the height of the Control
		float getHeight();

		//! Returns the position of the upper left corner of the Control
		const FVector2& getPosition();
		//! Returns the size of the Control
		FVector2 getSize();
		//! Returns the FRect describing this Control's size and position
		const FRect& getRect();

		//! Returns the minimum size this Control will allow itself to be resized to
		const FVector2& getMinimumSize();
		//! Sets the minimum size this Control will allow itself to be resized to
		void setMinimumSize( const FVector2& size );
		//! Returns the maximum size this Control will allow itself to be resized to
		const FVector2& getMaximumSize();
		//! Sets the maximum size this Control will allow itself to be resized to
		void setMaximumSize( const FVector2& size );

		//! Sets the visibility of this Control
		void setVisible( bool visible );
		//! Returns the visibility of this Control
		bool getVisible();

		//! Sets the alpha transparency of this Control
		void setAlpha( float alpha );
		//! Returns the alpha transparency of this Control
		float getAlpha();

		//Object Functions
		virtual ObjectAccessorList* getAccessors();
		virtual unsigned int getObjectType() const;

		//! Values used by get/setDocking and get/setAnchor
		enum ControlSides {
			None = 0, //!< No side
			Left = 1, //!< Left side
			Right = 1 << 1, //!< Right side
			Top = 1 << 2, //!< Top side
			Bottom = 1 << 3, //!< Bottom side
			All = Left | Right | Top | Bottom, //!< All sides
			Fill = All //!< Alias for All sides
		};

		//! Sets the docking preference for this Control
		void setDocking( int dockStyle );
		//! Gets the current docking preference for this Control
		int getDocking();

		//! Sets the anchored sides for this Control
		void setAnchor( int anchoredSides );
		//! Gets the current anchored sides for this control
		int getAnchor();

		//! sets the margin of this Control
		void setMargin( float margin );
		//! gets the margin of this Control
		float getMargin();

		//! \internal In addition to previous functionality, this enforces Alpha and Visibility before the Draw event is issued
		virtual void _draw( Brush& brush );

		//! \internal  Returns a reference to the cursor to draw over this Control
		const CursorPtr& _getCurrentCursor() const;

		//! Returns true if the given point is inside this Widget
		virtual bool isInside( const FVector2& position );

	protected:
//!\name Event Injectors
//@{
		//! Control has been moved
		void eventMoved( const FVector2& oldPosition, const FVector2& newPosition );
		//! Control has been resized
		void eventResized( const FVector2& oldSize, const FVector2& newSize );

		//! Called when this Control is targeted, either by cursor or by menu navigation
		void eventTargeted();
		//! Called when this Control is no longer targeted, either by cursor or by menu navigation
		void eventUnTargeted();
//@}

//!\name Event Handlers
//@{
		//! "Moved" event
		virtual void onMoved( Object* sender, Moved_EventArgs& evtArgs );
		//! "Resized" event
		virtual void onResized( Object* sender, Resized_EventArgs& evtArgs );

		//! "CursorMove" event, consumes the event
		virtual void onCursorMove( Object* sender, Cursor_EventArgs& evtArgs );
		//! "CursorPress" event, consumes the event
		virtual void onCursorPress( Object* sender, Cursor_EventArgs& evtArgs );
		//! "CursorRelease" event, consumes the event
		virtual void onCursorRelease( Object* sender, Cursor_EventArgs& evtArgs );
		//! "CursorEnter" event
		virtual void onCursorEnter( Object* sender, EventArgs& evtArgs );
		//! "CursorLeave" event
		virtual void onCursorLeave( Object* sender, EventArgs& evtArgs );
		//! "Targeted" event
		virtual void onTargeted( Object* sender, EventArgs& evtArgs );
		//! "UnTargeted" event
		virtual void onUnTargeted( Object* sender, EventArgs& evtArgs );
//@}
		//! Sets the cursor displayed when the Screen cursor is over this Control
		void setCursor( CursorPtr cursorPtr );
		//! Gets the current cursor displayed when the Screen cursor is over this Control
		CursorPtr getCursor() const;


	private:
		// returns a pointer to the first sibling found at the given position
		Widget* getSiblingAt( const FVector2& pos );

		//! Call for any operation that invalidates layouts, like moves and resizes.
		void _invalidateLayout();
		//! Call for any operation that breaks docking. (Moves and resizes along a conflicting axis)
		void _breakDocking();

		FRect mRect; // position & size of this Control
		bool mVisible; // visibility of this Control
		float mAlpha; // alpha of this Control
		FVector2 mMinSize; // Minimum Size
		FVector2 mMaxSize; // Maximum Size

		int mAnchors; // anchored sides
		int mDock; // docking preference
		float mMargin; // layout margin

		CursorPtr m_Cursor; // the cursor drawn when over this Control

		bool mCursorInside; // cursor position state variable
		bool m_InDockAnchor; // prevents re-entry into setDocking/setAnchor
		bool m_InLayout; // managed entirely by ContainerControl.
		// ^-- Signifies that layout is in process, so ignore invalidations and docking breaking operations

		bool mClickTrack; // press/release tracking for Cursor_Click event generation
	};

} // namespace OpenGUI{

#endif // F9497A73_9AD4_4241_8A38_7566DBC752BE
