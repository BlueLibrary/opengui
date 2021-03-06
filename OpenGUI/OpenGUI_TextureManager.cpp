// OpenGUI (http://opengui.sourceforge.net)
// This source code is released under the BSD License
// See LICENSE.TXT for details

#include "OpenGUI_TextureManager.h"
#include "OpenGUI_Renderer.h"
#include "OpenGUI_Exception.h"
#include "OpenGUI_LogSystem.h"

namespace OpenGUI {
	//############################################################################
	template<> TextureManager* Singleton<TextureManager>::mptr_Singleton = 0;
	//############################################################################
	TextureManager& TextureManager::getSingleton( void ) {
		assert( mptr_Singleton );
		return ( *mptr_Singleton );
	}
	//############################################################################
	TextureManager* TextureManager::getSingletonPtr( void ) {
		return mptr_Singleton;
	}
	//############################################################################
	//############################################################################
	//############################################################################
	TextureManager::TextureManager( Renderer* renderer ) {
		LogManager::SlogMsg( "INIT", OGLL_INFO2 ) << "Creating TextureManager" << Log::endlog;
		mRenderer = renderer;
		mRTTavail = mRenderer->supportsRenderToTexture();
	}
	//############################################################################
	TextureManager::~TextureManager() {
		LogManager::SlogMsg( "SHUTDOWN", OGLL_INFO2 ) << "Destroying TextureManager" << Log::endlog;
		destroyAllTextures();
	}
	//############################################################################
	TexturePtr TextureManager::createTextureFromFile( const String& filename ) {
		LogManager::SlogMsg( "TextureManager", OGLL_INFO2 ) << "Create Texture from File: " << filename << Log::endlog;
		Texture* tex = mRenderer->createTextureFromFile( filename );
		mTextureCPtrList.push_front( tex );
		return TexturePtr( tex );
	}
	//############################################################################
	TexturePtr TextureManager::createTextureFromTextureData( const String& name, TextureData* textureData ) {
		LogManager::SlogMsg( "TextureManager", OGLL_INFO2 ) << "Create Texture from TextureData: "
		<< name
		<< " (" << ( size_t ) textureData << ")"
		<< Log::endlog;
		Texture* tex = mRenderer->createTextureFromTextureData( textureData );
		tex->_setName( name );
		mTextureCPtrList.push_front( tex );
		return TexturePtr( tex );
	}
	//############################################################################
	void TextureManager::updateTextureFromTextureData( TexturePtr texturePtr, TextureData* textureData ) {
		LogManager::SlogMsg( "TextureManager", OGLL_INFO2 ) << "Update Texture from TextureData: "
		<< texturePtr->getName()
		<< " (" << ( size_t ) textureData << ")"
		<< Log::endlog;

		Texture* tex;
		tex = texturePtr.get();
		mRenderer->updateTextureFromTextureData( tex, textureData );
	}
	//############################################################################
	void TextureManager::destroyTexture( Texture* texturePtr ) {
		LogManager::SlogMsg( "TextureManager", OGLL_INFO2 ) << "DestroyTexture: " << texturePtr->getName() << " " << texturePtr << Log::endlog;
		mTextureCPtrList.remove( texturePtr );
		mRenderer->destroyTexture( texturePtr );
	}
	//############################################################################
	void TextureManager::destroyAllTextures() {
		LogManager::SlogMsg( "TextureManager", OGLL_INFO2 ) << "DestroyAllTextures..." << Log::endlog;
		Texture* tex;
		while ( mTextureCPtrList.size() > 0 ) {
			tex = mTextureCPtrList.front();
			mTextureCPtrList.pop_front();
			mRenderer->destroyTexture( tex );
		}
	}
	//############################################################################
	RenderTexturePtr TextureManager::createRenderTexture( const IVector2& size ) {
		if ( !mRTTavail )
			OG_THROW( Exception::ERR_INTERNAL_ERROR, "Cannot create RenderTexture when Renderer does not support this feature", __FUNCTION__ );
		RenderTexture* tex = mRenderer->createRenderTexture( size );
		return RenderTexturePtr( tex );
	}
	//############################################################################
	void TextureManager::destroyRenderTexture( RenderTexture* texturePtr ) {
		if ( !mRTTavail )
			OG_THROW( Exception::ERR_INTERNAL_ERROR, "Cannot destroy RenderTexture when Renderer does not support this feature", __FUNCTION__ );
		mRenderer->destroyRenderTexture( texturePtr );
	}
	//############################################################################
}//namespace OpenGUI{