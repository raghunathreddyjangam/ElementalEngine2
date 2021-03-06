//=====================================================================
// File:		ObjectTexture.cpp
// Description: Defines the initialization routines for the DLL.
// Started:		10/31/2001
// Original:	Kenneth Hurley
//=====================================================================

#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

AFX_EXTENSION_MODULE ObjectTextureDLL = { NULL, NULL };
CObjectTexture *gObjectTexture;

extern "C" int APIENTRY DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("OBJECTTEXTURE.DLL Initializing!\n");
		
		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(ObjectTextureDLL, hInstance))
			return 0;

		// Insert this DLL into the resource chain
		// NOTE: If this Extension DLL is being implicitly linked to by
		//  an MFC Regular DLL (such as an ActiveX Control)
		//  instead of an MFC application, then you will want to
		//  remove this line from DllMain and put it in a separate
		//  function exported from this Extension DLL.  The Regular DLL
		//  that uses this Extension DLL should then explicitly call that
		//  function to initialize this Extension DLL.  Otherwise,
		//  the CDynLinkLibrary object will not be attached to the
		//  Regular DLL's resource chain, and serious problems will
		//  result.

		new CDynLinkLibrary(ObjectTextureDLL);
		// this has to be done after module is intialized.
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("OBJECTTEXTURE.DLL Terminating!\n");
		// Terminate the library before destructors are called
		AfxTermExtensionModule(ObjectTextureDLL);
		delete gObjectTexture;
	}
	return 1;   // ok
}

extern "C" DWORD GetDLLVersion()
{
	return INTERFACEDLLVERSION;
}

// Exported DLL initialization is run in context of running application
extern "C" CDLLInterface *GetDLLInterface(CProgramInfo *pi)
{
	gObjectTexture = new CObjectTexture(pi);
	return gObjectTexture;
}

static LPTSTR OpenFilter = {
	"DevIL Files (*.oil)\0" "*.oil\0"
	"DirectX Image Files (*.dds)\0" "*.dds\0"
	"Graphics Interchange Format (*.gif)\0" "*.gif\0"
	"Half-Life Model Files (*.mdl)\0" "*.mdl\0"
	"Homeworld Image Files (*.lif)\0" "*.lif\0"
	"Jpeg Files (*.jpe, *.jpg, *.jpeg)\0" "*.jpe;*.jpg;*.jpeg\0"
	"Microsoft Bitmap Files (*.bmp)\0" "*.bmp\0"
	"Microsoft Icon Files (*.ico)\0" "*.ico\0"
	"Portable AnyMap Files (*.pbm, *.pgm, *.pnm, *.ppm)\0" "*.pbm;*.pgm;*.pnm;*.ppm\0"
	"Portable Network Graphics Files (*.png)\0" "*.png\0"
	"Sgi Files (*.sgi)\0" "*.bw;*.rgb;*.rgba;*.sgi\0"
	"Targa Files (*.tga)\0" "*.tga\0"
	"Tiff Files (*.tif)\0" "*.tif;*.tiff\0"
	"Quake Wal Files (*.wal)\0" "*.wal\0"
	"ZSoft Pcx Files (*.pcx)\0" "*.pcx\0"
	"\0\0"
};

static LPTSTR SaveFilter = {
	"C-Style Header (*.h)\0" "*.h\0"
	"DevIL Files (*.oil)\0" "*.oil\0"
	"Direct X Files (*.dds)\0" "*.dds\0"
	"Jpeg Files (*.jpe, *.jpg, *.jpeg)\0" "*.jpe;*.jpg;*.jpeg\0"
	"Microsoft Bitmap Files (*.bmp)\0" "*.bmp\0"
	"Portable AnyMap Files (*.pbm, *.pgm, *.ppm)\0" "*.pbm;*.pgm;*.ppm\0"
	"Portable Network Graphics Files (*.png)\0" "*.png\0"
	"Sgi Files (*.sgi)\0" "*.bw;*.rgb;*.rgba;*.sgi\0"
	"Targa Files (*.tga)\0" "*.tga\0"
	"ZSoft Pcx Files (*.pcx)\0" "*.pcx\0"
	"\0\0"
};

//---------------------------------------------------------------------
// Function:	CObjectTexture
// Description:	Standard Constructor
// Parameters:	pi = program's information structure
// Returns:		.
//---------------------------------------------------------------------
CObjectTexture::CObjectTexture(CProgramInfo *ProgramInfo)
{
    m_ProgramInfo = ProgramInfo;
	m_LoadStrings = OpenFilter;
	m_SaveStrings = SaveFilter;
	m_ThumbNail = NULL;					// we'll generate one later WIP
	m_Priority = IDR_TEXTURETYPE;
}

//---------------------------------------------------------------------
// Function:	GetName 
// Description:	DLL's module name
// Parameters:	.
// Returns:		CString * = pointer to name of loaded DLL
//---------------------------------------------------------------------
CString *CObjectTexture::GetName()
{
    static CString name;
    LPTSTR tBuff;

    tBuff = name.GetBuffer(_MAX_PATH+1);
	GetModuleFileName(ObjectTextureDLL.hModule, tBuff, _MAX_PATH);
    name.ReleaseBuffer();

    return &name;
}

//---------------------------------------------------------------------
// Function:	Initialize
// Description:	Initialization like InitInstace
// Parameters:	.
// Returns:		TRUE, if successful
//---------------------------------------------------------------------
BOOL CObjectTexture::Initialize()
{
	CString tName;
	HINSTANCE appInst;
	CMDIFrameWnd *mainWnd;
		
	// Register the doc templates we provide to the app
	CWinApp* pApp = AfxGetApp();
	ASSERT(pApp != NULL);
    if (pApp == NULL)
    {
        return FALSE;
    }

	mainWnd = DYNAMIC_DOWNCAST(CMDIFrameWnd, pApp->m_pMainWnd);

	// get the apps instance handle for loading resources
	appInst = AfxGetResourceHandle();
	// now tell the application to look in dll for resources
	AfxSetResourceHandle(ObjectTextureDLL.hModule);

	// use my string / icon resources
	// *** note IDR_TEXTURE type needs to be unique ID even between
	// dlls
	m_DocTemplate = new CMultiDocTemplate(IDR_TEXTURETYPE,
			RUNTIME_CLASS(CTextureDoc),
			RUNTIME_CLASS(CMDIChildWnd),
			RUNTIME_CLASS(CTextureView));

	pApp->AddDocTemplate(m_DocTemplate);

	VERIFY(MergeMenus(&m_DocTemplate->m_hMenuShared, *(m_ProgramInfo->curMenu), _T("&Window")));	
	VERIFY(MergeAccelerators(&m_DocTemplate->m_hAccelTable, *(m_ProgramInfo->curAccel)));

	// Initialze the image library
	ilInit();
	iluInit();
	ilutInit();

	// construct resource info
	m_ObjInfo.name.LoadString(IDS_OBJECT_NAME);
	m_ObjInfo.pageIndex = &m_PageIndex;

	m_ObjInfo.icon = (HICON)LoadImage(ObjectTextureDLL.hModule, MAKEINTRESOURCE(IDR_TEXTURETYPE), 
		IMAGE_ICON, 0, 0, LR_CREATEDIBSECTION);
	VERIFY(m_ObjInfo.icon != NULL);

	// value should be 1 - 1000
	m_ObjInfo.priority = IDR_TEXTURETYPE;
	m_ObjInfo.objFlags = OBJFLAGS_EXPORTABLE |
		OBJFLAGS_IMPORTABLE | OBJFLAGS_THUMBNAIL;

	AfxSetResourceHandle(appInst);

    return TRUE;

}

//---------------------------------------------------------------------
// Function:	~CObjectTexture
// Description:	Standard Desctructor
// Parameters:	.
// Returns:		.
//---------------------------------------------------------------------
CObjectTexture::~CObjectTexture()
{
	TEXOBJLIST::iterator toIT;

	if (m_ObjInfo.icon != NULL)
	{
		DestroyIcon(m_ObjInfo.icon);
		m_ObjInfo.icon = NULL;
	}

	for (toIT = m_TextureObjects.begin(); toIT != m_TextureObjects.end(); toIT++)
	{
		delete *toIT;
	}

	ilShutDown();
}

//---------------------------------------------------------------------
// Function:	Save
// Description:	Save data to a file
// Parameters:	filename = name of file to save
// Returns:		DWORD = possible error or 0 for no error
//---------------------------------------------------------------------
DWORD CObjectTexture::Save(LPTSTR filename)
{
	return NO_ERROR;
}

//---------------------------------------------------------------------
// Function:	Load
// Description:	Load data from a file
// Parameters:	filename = name of file to load
// Returns:		DWORD = possible error or 0 for no error
//---------------------------------------------------------------------
DWORD CObjectTexture::Load(LPTSTR filename)
{
	m_DocTemplate->OpenDocumentFile(filename);

	return NO_ERROR;
}

