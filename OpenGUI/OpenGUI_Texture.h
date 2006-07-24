#ifndef C4152441_F250_46dd_958F_D1007688400A
#define C4152441_F250_46dd_958F_D1007688400A

#include "OpenGUI_Types.h"

namespace OpenGUI{
	/*! \brief
		This is a base class for custom Texture implementations. Custom Renderer
		implementations will also quite likely include a custom Texture
		implementation to deal with API specific texture handling.

		\note All Rendered implementations will need to create a subclass of this
			in order to access the protected data members. Setting the values of
			these protected members is a required function of Renderer implementations.
	*/
	class OPENGUI_API Texture
	{
	public:
		virtual std::string getName();
		Texture() {}
		virtual ~Texture() {}
		IVector2 getSize(){return mTextureSize;}
	protected:
		std::string mTextureName;//!<It is required that this be set to the source filename by custom Renderers
		IVector2 mTextureSize;//!<It is required that this be set to the texture dimensions by custom Renderers
	};
};//namespace OpenGUI{
#endif
