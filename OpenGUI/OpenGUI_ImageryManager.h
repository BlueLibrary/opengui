// OpenGUI (http://opengui.sourceforge.net)
// This source code is released under the BSD License
// See LICENSE.TXT for details

#ifndef A7EB8CEB_DF02_4714_AD1E_53FDCDD6C2E2
#define A7EB8CEB_DF02_4714_AD1E_53FDCDD6C2E2

#include "OpenGUI_PreRequisites.h"
#include "OpenGUI_Exports.h"
#include "OpenGUI_String.h"
#include "OpenGUI_Singleton.h"
#include "OpenGUI_Imageset.h"
#include "OpenGUI_Face.h"
#include "OpenGUI_XML.h"
#include "OpenGUI_StrConv.h"

namespace OpenGUI {

	class ResourceProvider; //forward declaration

	/*! \brief
		Provides management services for loading, unloading, keeping track of,
		and searching for Imageset and the children Image objects.\n \b [Singleton]
	*/
	class OPENGUI_API ImageryManager : public Singleton<ImageryManager> {
		friend class XMLParser;
		friend class Imageset;
	public:
		ImageryManager( ResourceProvider* resourceProvider );
		~ImageryManager();

		//Reimplementation required for this style of singleton implementation to work across DLLs
		//! Retrieve the current singleton, if one exists. If none exists, this will cause an error.
		static ImageryManager& getSingleton( void );

		//Reimplementation required for this style of singleton implementation to work across DLLs
		//! Retrieve a pointer to the current singleton, if one exists. If none exists, this will return 0.
		static ImageryManager* getSingletonPtr( void );


		//! Create a new Imageset.
		/*! This will create a new Imageset based on the image file specified. If an Imageset
			already exists based on the provided filename, then the existing Imageset is returned
			instead of creating a new one.

			\param imageFilename The filename of the source image file. This name
				can also be used to later retrieve the Imageset pointer via getImageset()
			\return pointer to the newly created imageset, or 0 on failure.
		*/
		ImagesetPtr createImageset( const String& imageFilename );
		//! Static pass through function to createImageset()
		static ImagesetPtr createImagesetEx( const String& imageFilename ) {
			return ImageryManager::getSingleton().createImageset( imageFilename );
		}

		//! Create a new Imageset from an existing texture.
		/*! This acts much like the file-based \c createImageset() function, with the
			exception that it does not attempt to load the texture from a file on disk.
			Instead, it uses the already existing texture that is given. The \c imageFilename
			parameter is only used for future lookups by \c getImageset(), and must therefore
			be unique, but is otherwise meaningless. If no \c imageFilename is given, one is
			automatically generated for you.

			Any single \c texture or \c imageFilename can only be used once to create an Imageset,
			so future calls to this function with the same \c texture or \c imageFilename will
			result in varying functionality.

			If the given \c imageFilename ever matches an existing filename, an exception is thrown.
			Due to TexturePtr caching, the redefinition of an Imageset's texture would result in
			staggered usage across the GUI, which is undesirable. If you want to have dynamically
			changing textures for use within Imagery, you should create a texture specifically for that
			purpose and directly update the Texture's contents as needed.

			If the given \c imageFilename does not match any existing Imageset filenames, but a duplicate
			\c texture is found, the Imageset will successfully create using the texture for yet another
			Imageset. The usefulness of this is minimal, but it is the most logical action given the
			design.

			\returns On success the return value is the pointer to the Imageset created.
		*/
		ImagesetPtr createImagesetFromTexture( TexturePtr texture, const String& imageFilename = "" );

		//! Returns a pointer to the Imageset that was created using the given filename, or 0 on failure.
		ImagesetPtr getImageset( const String& imageFilename );

		//! Returns a pointer to the Imageset that is based on the given \c texture, or 0 on failure.
		ImagesetPtr getImagesetByTexture( TexturePtr texture );

		//! Destroys an Imageset.
		void destroyImageset( ImagesetPtr pImageset );
		//! Destroys an Imageset.
		void destroyImageset( const String& imageFilename );
		//! Destroys all Imagesets
		void destroyAllImagesets();

		//! Retrieves an Imagery by fully qualified name, or by first match on name alone
		/*! This method provides 2 paths for Imagery lookup. The first method attempted is lookup by
		fully qualified name. This is in the format "<Imageset_Name>:<Imagery_Name>", and if used will
		provide a perfect lookup of the Imagery specified. Fully qualified name is identified by the
		presence of the ':' character, and if this is found the function will only return a valid pointer
		if that exact Imagery can be found.

		The second method of lookup is used when the ':' character is not found in given the Imagery name.
		This method searches all Imagesets for the first Imagery found with the given name. If an Imagery
		is found it is immediately returned. This method is only useful if you can guarantee that the Imagery
		you are searching for has a globally unique name, otherwise you may not get the Imagery you were
		intending.

		\returns ImageryPtr(0) on failure, otherwise a RefPtr to the found Imagery */
		ImageryPtr getImagery( const String& imageryName );

		//! A string list used by ImageryManager::getImagesetList()
		typedef std::list<String> ImagesetList;

		//! Returns an ImagesetList of all Imagesets that are currently loaded. Items can be fed back into getImageset()
		ImagesetList getImagesetList();

		//! Adds the given FacePtr to the managed list of Faces so that it can be retrieved later by name
		void addFace( FacePtr facePtr );
		//! Retrieves a previously added Face by name
		FacePtr getFace( const String& faceName );
		//! Removes a previously added Face by name.
		void removeFace( const String& faceName );
		//! Returns a list of all registered faces
		StringList getFaceList();

	private:
		ImagesetPtrList mImagesetList;
		static String _generateRandomName();//Generates unique names for Imagesets/Imagery
		ResourceProvider* mResourceProvider;

		//! list of FacePtrs
		typedef std::map<String, FacePtr> FacePtrMap;
		FacePtrMap mFacePtrMap;

		// XML tag handlers for <Imageset> tags
		static bool _Imageset_XMLNode_Load( const XMLNode& node, const String& nodePath );
		static bool _Imageset_XMLNode_Unload( const XMLNode& node, const String& nodePath );

		// XML tag handlers for <Face> tags
		static bool _Face_XMLNode_Load( const XMLNode& node, const String& nodePath );
		static bool _Face_XMLNode_Unload( const XMLNode& node, const String& nodePath );
	};

}
;//namespace OpenGUI{

#endif

