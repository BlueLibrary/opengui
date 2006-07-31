; Script generated by the HM NIS Edit Script Wizard.

; HM NIS Edit Wizard helper defines
!define PRODUCT_NAME "OpenGUI SDK"
!define PRODUCT_VERSION "0.7.5"
!define PRODUCT_WEB_SITE "http://OpenGUI.sourceforge.net"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\Demo1.exe"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}_${PRODUCT_VERSION}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"

; MUI 1.67 compatible ------
!include "MUI.nsh"

; MUI Settings
!define MUI_ABORTWARNING
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\modern-install.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"

; Welcome page
!insertmacro MUI_PAGE_WELCOME
; License page
!insertmacro MUI_PAGE_LICENSE "OpenGUI\LICENSE.TXT"
; Directory page
!insertmacro MUI_PAGE_DIRECTORY
; Instfiles page
!insertmacro MUI_PAGE_INSTFILES
; Finish page
;!define MUI_FINISHPAGE_RUN "$INSTDIR\Demos\Demo1.exe"
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_INSTFILES

; Language files
!insertmacro MUI_LANGUAGE "English"

; MUI end ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "OpenGUI-${PRODUCT_VERSION}_SDK.exe"
InstallDir "$PROGRAMFILES\OpenGUI-${PRODUCT_VERSION}_SDK"
InstallDirRegKey HKLM "${PRODUCT_DIR_REGKEY}" ""
ShowInstDetails show
ShowUnInstDetails show

Section "MainSection" SEC01
  SetOutPath "$INSTDIR\OpenGUI\include"
  SetOverwrite try
  File "winSDK\OpenGUI\include\OpenGUI_Widget.h"
  File "winSDK\OpenGUI\include\OpenGUI_Cursor.h"
  File "winSDK\OpenGUI\include\OpenGUI_PropertySet.h"
  File "winSDK\OpenGUI\include\OpenGUI_Imageset.h"
  File "winSDK\OpenGUI\include\OpenGUI_CursorManager.h"
  File "winSDK\OpenGUI\include\OpenGUI_Types.h"
  File "winSDK\OpenGUI\include\OpenGUI_GenericCursor.h"
  File "winSDK\OpenGUI\include\OpenGUI_Exports.h"
  File "winSDK\OpenGUI\include\OpenGUI.h"
  File "winSDK\OpenGUI\include\UnknownImage.h"
  File "winSDK\OpenGUI\include\OpenGUI_Message.h"
  File "winSDK\OpenGUI\include\OpenGUI_Platform.h"
  File "winSDK\OpenGUI\include\OpenGUI_MouseButton.h"
  File "winSDK\OpenGUI\include\OpenGUI_Font.h"
  File "winSDK\OpenGUI\include\OpenGUI_WidgetFactoryManager.h"
  File "winSDK\OpenGUI\include\OpenGUI_UnusedTypes.h"
  File "winSDK\OpenGUI\include\OpenGUI_RenderCache.h"
  File "winSDK\OpenGUI\include\OpenGUI_StaticImage.h"
  File "winSDK\OpenGUI\include\OpenGUI_Singleton.h"
  File "winSDK\OpenGUI\include\OpenGUI_ImageryManager.h"
  File "winSDK\OpenGUI\include\OpenGUI_GenericResourceProvider.h"
  File "winSDK\OpenGUI\include\OpenGUI_PluginManager.h"
  File "winSDK\OpenGUI\include\OpenGUI_DynamicLib.h"
  File "winSDK\OpenGUI\include\OpenGUI_Resource.h"
  File "winSDK\OpenGUI\include\OpenGUI_Renderer.h"
  File "winSDK\OpenGUI\include\OpenGUI_TimerManager.h"
  File "winSDK\OpenGUI\include\OpenGUI_GUISheet.h"
  File "winSDK\OpenGUI\include\OpenGUI_BaseWidgets.h"
  File "winSDK\OpenGUI\include\OpenGUI_ResourceProvider.h"
  File "winSDK\OpenGUI\include\OpenGUI_Timer.h"
  File "winSDK\OpenGUI\include\OpenGUI_Event.h"
  File "winSDK\OpenGUI\include\OpenGUI_Primitives.h"
  File "winSDK\OpenGUI\include\OpenGUI_Element.h"
  File "winSDK\OpenGUI\include\OpenGUI_SimpleButton.h"
  File "winSDK\OpenGUI\include\OpenGUI_Subscriber.h"
  File "winSDK\OpenGUI\include\OpenGUI_PreRequisites.h"
  File "winSDK\OpenGUI\include\OpenGUI_TextureData.h"
  File "winSDK\OpenGUI\include\OpenGUI_Imagery.h"
  File "winSDK\OpenGUI\include\OpenGUI_Texture.h"
  File "winSDK\OpenGUI\include\OpenGUI_WidgetTemplateManager.h"
  File "winSDK\OpenGUI\include\OpenGUI_LayoutLoader.h"
  File "winSDK\OpenGUI\include\OpenGUI_XMLParser.h"
  File "winSDK\OpenGUI\include\OpenGUI_Exception.h"
  File "winSDK\OpenGUI\include\OpenGUI_RenderOperation.h"
  File "winSDK\OpenGUI\include\OpenGUI_FontManager.h"
  File "winSDK\OpenGUI\include\OpenGUI_CONFIG.h"
  File "winSDK\OpenGUI\include\OpenGUI_FontAtlas.h"
  File "winSDK\OpenGUI\include\OpenGUI_FontGlyph.h"
  File "winSDK\OpenGUI\include\OpenGUI_TextureDataRect.h"
  File "winSDK\OpenGUI\include\OpenGUI_System.h"
  File "winSDK\OpenGUI\include\OpenGUI_FontCache.h"
  File "winSDK\OpenGUI\include\OpenGUI_RefPtr.h"
  File "winSDK\OpenGUI\include\OpenGUI_TextLabel.h"
  File "winSDK\OpenGUI\include\OpenGUI_Primitives_Text.h"
  File "winSDK\OpenGUI\include\OpenGUI_Primitives_Geometric.h"
  File "winSDK\OpenGUI\include\OpenGUI_Primitives_Mutations.h"
  File "winSDK\OpenGUI\include\OpenGUI_LogSystem.h"
  File "winSDK\OpenGUI\include\OpenGUI_EventListener.h"
  
  SetOutPath "$INSTDIR\OpenGUI\lib"
  File "winSDK\OpenGUI\lib\OpenGUI_d.lib"
  File "winSDK\OpenGUI\lib\OpenGUI_d.dll"
  File "winSDK\OpenGUI\lib\OpenGUI.lib"
  File "winSDK\OpenGUI\lib\OpenGUI.dll"
  
  SetOutPath "$INSTDIR\OpenGUI"
  File "winSDK\OpenGUI\LICENSE.TXT"
  
  SetOutPath "$INSTDIR\OGLRenderer\include"
  File "winSDK\OGLRenderer\include\OpenGUI_OGLTexture.h"
  File "winSDK\OGLRenderer\include\OpenGUI_OGLRenderer.h"
  
  SetOutPath "$INSTDIR\OGLRenderer\lib"
  File "winSDK\OGLRenderer\lib\OpenGUI_OGLRenderer.lib"
  File "winSDK\OGLRenderer\lib\OpenGUI_OGLRenderer_d.lib"
  
  SetOutPath "$INSTDIR\Tachometer\include"
  File "winSDK\Tachometer\include\Tachometer.h"
  
  SetOutPath "$INSTDIR\Tachometer\lib"
  File "winSDK\Tachometer\lib\TachometerWidget.dll"
  File "winSDK\Tachometer\lib\TachometerWidget.lib"
  File "winSDK\Tachometer\lib\TachometerWidget_d.dll"
  File "winSDK\Tachometer\lib\TachometerWidget_d.lib"
  
  SetOutPath "$INSTDIR\Demos"
  File "winSDK\Demos\licenses.txt"
  File "winSDK\Demos\pecot.ttf"
  File "winSDK\Demos\kongtext.ttf"
  File "winSDK\Demos\TachometerWidget.dll"
  File "winSDK\Demos\tachometer.png"
  File "winSDK\Demos\tachometer.xml"
  File "winSDK\Demos\Metal.png"
  File "winSDK\Demos\metal.xml"
  File "winSDK\Demos\OpenGUI.dll"
  File "winSDK\Demos\demo1.xml"
  File "winSDK\Demos\Demo1.exe"
  
  SetOutPath "$INSTDIR\OgreFusion"
  File "winSDK\OgreFusion\include\OgreFusion.h"
  File "winSDK\OgreFusion\include\OgreFusion_Platform.h"
  File "winSDK\OgreFusion\include\OgreFusion_Exports.h"
  File "winSDK\OgreFusion\include\OgreFusion_PreRequisites.h"
  File "winSDK\OgreFusion\include\OgreFusion_Texture.h"
  File "winSDK\OgreFusion\include\OgreFusion_Renderer.h"
  File "winSDK\OgreFusion\include\OgreFusion_ResourceProvider.h"
  
  SetOutPath "$INSTDIR\OgreFusion\lib"
  File "winSDK\OgreFusion\lib\OgreFusion_d.lib"
  File "winSDK\OgreFusion\lib\OgreFusion_d.dll"
  File "winSDK\OgreFusion\lib\OgreFusion.lib"
  File "winSDK\OgreFusion\lib\OgreFusion.dll"
  SetOutPath "$INSTDIR\OgreFusion"
  File "winSDK\OgreFusion\LICENSE.TXT"

  
  CreateDirectory "$SMPROGRAMS\OpenGUI ${PRODUCT_VERSION} SDK"
  CreateShortCut "$SMPROGRAMS\OpenGUI ${PRODUCT_VERSION} SDK\Demo1.lnk" "$INSTDIR\Demos\Demo1.exe"
  SetOutPath "$INSTDIR"
  File "winSDK\OpenGUI.chm"
  File "winSDK\OgreFusion.chm"
  File "winSDK\CHANGELOG.txt"
  CreateShortCut "$SMPROGRAMS\OpenGUI ${PRODUCT_VERSION} SDK\OpenGUI API Docs.lnk" "$INSTDIR\OpenGUI.chm"
  CreateShortCut "$SMPROGRAMS\OpenGUI ${PRODUCT_VERSION} SDK\OgreFusion Docs.lnk" "$INSTDIR\OgreFusion.chm"
  CreateShortCut "$SMPROGRAMS\OpenGUI ${PRODUCT_VERSION} SDK\ChangeLog.lnk" "$INSTDIR\CHANGELOG.txt"
SectionEnd

Section -AdditionalIcons
  WriteIniStr "$INSTDIR\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
  CreateShortCut "$SMPROGRAMS\OpenGUI ${PRODUCT_VERSION} SDK\Website.lnk" "$INSTDIR\${PRODUCT_NAME}.url"
  CreateShortCut "$SMPROGRAMS\OpenGUI ${PRODUCT_VERSION} SDK\Uninstall.lnk" "$INSTDIR\uninst.exe"
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\Demos\Demo1.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\Demos\Demo1.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayVersion" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "URLInfoAbout" "${PRODUCT_WEB_SITE}"
SectionEnd


Function un.onUninstSuccess
  HideWindow
  MessageBox MB_ICONINFORMATION|MB_OK "$(^Name) was successfully removed from your computer."
FunctionEnd

Function un.onInit
  MessageBox MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2 "Are you sure you want to completely remove $(^Name) and all of its components?" IDYES +2
  Abort
FunctionEnd

Section Uninstall
  Delete "$INSTDIR\${PRODUCT_NAME}.url"
  Delete "$INSTDIR\uninst.exe"
  Delete "$INSTDIR\OpenGUI.chm"
  Delete "$INSTDIR\Demos\Demo1.exe"
  Delete "$INSTDIR\Demos\demo1.xml"
  Delete "$INSTDIR\Demos\OpenGUI.dll"
  Delete "$INSTDIR\Demos\metal.xml"
  Delete "$INSTDIR\Demos\Metal.png"
  Delete "$INSTDIR\Demos\tachometer.xml"
  Delete "$INSTDIR\Demos\tachometer.png"
  Delete "$INSTDIR\Demos\TachometerWidget.dll"
  Delete "$INSTDIR\Demos\kongtext.ttf"
  Delete "$INSTDIR\Demos\pecot.ttf"
  Delete "$INSTDIR\Demos\licenses.txt"
  Delete "$INSTDIR\Tachometer\lib\TachometerWidget_d.lib"
  Delete "$INSTDIR\Tachometer\lib\TachometerWidget_d.dll"
  Delete "$INSTDIR\Tachometer\lib\TachometerWidget.lib"
  Delete "$INSTDIR\Tachometer\lib\TachometerWidget.dll"
  Delete "$INSTDIR\Tachometer\include\Tachometer.h"
  Delete "$INSTDIR\OGLRenderer\lib\OpenGUI_OGLRenderer_d.lib"
  Delete "$INSTDIR\OGLRenderer\lib\OpenGUI_OGLRenderer.lib"
  Delete "$INSTDIR\OGLRenderer\include\OpenGUI_OGLRenderer.h"
  Delete "$INSTDIR\OGLRenderer\include\OpenGUI_OGLTexture.h"
  Delete "$INSTDIR\OpenGUI\LICENSE.TXT"
  Delete "$INSTDIR\OpenGUI\lib\OpenGUI.dll"
  Delete "$INSTDIR\OpenGUI\lib\OpenGUI.lib"
  Delete "$INSTDIR\OpenGUI\lib\OpenGUI_d.dll"
  Delete "$INSTDIR\OpenGUI\lib\OpenGUI_d.lib"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_LogSystem.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Primitives_Mutations.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Primitives_Geometric.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Primitives_Text.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_TextLabel.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_RefPtr.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_FontCache.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_System.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_TextureDataRect.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_FontGlyph.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_FontAtlas.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_CONFIG.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_FontManager.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_RenderOperation.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Exception.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_XMLParser.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_LayoutLoader.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_WidgetTemplateManager.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Texture.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Imagery.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_TextureData.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_PreRequisites.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Subscriber.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_SimpleButton.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Element.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Primitives.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Event.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Timer.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_ResourceProvider.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_BaseWidgets.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_GUISheet.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_TimerManager.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Renderer.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Resource.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_DynamicLib.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_PluginManager.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_GenericResourceProvider.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_ImageryManager.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Singleton.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_StaticImage.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_RenderCache.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_UnusedTypes.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_WidgetFactoryManager.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Font.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_MouseButton.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Platform.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Message.h"
  Delete "$INSTDIR\OpenGUI\include\UnknownImage.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Exports.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_GenericCursor.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Types.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_CursorManager.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Imageset.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_PropertySet.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Cursor.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_Widget.h"
  Delete "$INSTDIR\OpenGUI\include\OpenGUI_EventListener.h"

  Delete "$SMPROGRAMS\OpenGUI ${PRODUCT_VERSION} SDK\Uninstall.lnk"
  Delete "$SMPROGRAMS\OpenGUI ${PRODUCT_VERSION} SDK\Website.lnk"
  Delete "$SMPROGRAMS\OpenGUI ${PRODUCT_VERSION} SDK\Demo1.lnk"
  Delete "$SMPROGRAMS\OpenGUI ${PRODUCT_VERSION} SDK\ChangeLog.lnk"
  Delete "$SMPROGRAMS\OpenGUI ${PRODUCT_VERSION} SDK\OpenGUI API Docs.lnk"

  RMDir "$SMPROGRAMS\OpenGUI ${PRODUCT_VERSION} SDK"
  RMDir "$INSTDIR\Tachometer\lib"
  RMDir "$INSTDIR\Tachometer\include"
  RMDir "$INSTDIR\OpenGUI\lib"
  RMDir "$INSTDIR\OpenGUI\include"
  RMDir "$INSTDIR\OpenGUI"
  RMDir "$INSTDIR\OGLRenderer\lib"
  RMDir "$INSTDIR\OGLRenderer\include"
  RMDir "$INSTDIR\Demos"
  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd