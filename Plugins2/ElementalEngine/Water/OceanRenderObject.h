///============================================================================
/// \file		OceanRenderObject.h
/// \brief		Header file for an Ocean Render Object
/// \date		06-25-2007
/// \note   Elemental Engine
///         Copyright (c)  2005-2008 Signature Devices, Inc.
///
///         This code is redistributable under the terms of the EE License.
///
///         This code is distributed without warranty or implied warranty of
///			merchantability or fitness for a particular purpose. See the 
///			EE License for more details.
///
///         You should have received a copy of the EE License along with this
///			code; If not, write to Signature Devices, Inc.,
///			3200 Bridge Parkway Suite 102, Redwood City, CA 94086 USA.
///============================================================================

#ifndef	OCEANRENDEROBJECT_H
#define	OCEANRENDEROBJECT_H

#include "CObjectTemplate.hpp"
#include "CRenderObject.h"

static const int OCEAN_HEIGHTMAPTEXTURE_COUNT = 16;
static const int OCEAN_RENDERTARGET_SIZE = 256;
const int OCEAN_DISTANCEGRID_RES = 256; // was 512 in demo
const int OCEAN_RADIALGRID_RES = 192; // was 384 in demo

class COceanRenderObject : public CRenderObject<>
{
protected:
	/// \brief Default Constructor
	/// \param parentName = name of parent in hierarchy
	/// \param name = IHashString * name of this object
	COceanRenderObject(IHashString *parentName, IHashString *name, bool bAddToHier);

public:
	/// \briefDefault Destructor
	virtual ~COceanRenderObject();

	/// \brief Create an instance
	/// \return	Pointer to this
	static IComponent *Create(int nArgs, va_list argptr);

	virtual void Init();

	virtual bool Update();

	virtual void DeInit();

	virtual void Serialize(IArchive &ar);

	virtual OBJECTSORTTYPES GetSceneSortID() const { return RENDEROBJECT3D; }

	/// \brief Render the renderobject
	/// \return true if object was rendered, false otherwise
	virtual bool Render( UINT pass , IEffect * override);

	/// \brief Compare for sorting
	/// \param obj = object to compare to
	/// \param sortMethod = a sort method specifying how to compare(set in RENDEROBJECTCOMPARE)
	/// \param curRenderPass = the current render pass to sort to
	/// \return bool = must return true if (this pointer) < (obj)
	virtual bool IsLessThan( const IRenderObject * obj, DWORD sortMethod, int curRenderPass );

	/// \brief This is for render priorities between classes
	/// will change as soon as a new architecture can be designed to better incorporate
	/// different renderobject types being pushed on the same sorted list
	/// \return DWORD = the priority key this returns, the higher the number,
	/// the higher its priority
	virtual DWORD GetRenderPriority();

	/// \brief Number of passes this render object has to go through
	/// \return UINT = the number of passes that this object has to go through
	virtual UINT GetNumPass();

	virtual bool GetBoundingBox( Vec3 &pos, Vec3 &dim, EulerAngle &rotation )
	{	
		return false;
	}

	/// \brief Gets the base sort class which implements IRenderObject::IsLessThan()
	/// child classes must not re-implement IsLessThan() if they return the BaseSortClass hash!!
	/// typically, each render object has a IsLessThan() and returns a unique BaseSortClass
	virtual IHashString * GetBaseSortClass();

	/// \brief returns if this renderobject needs to be sorted in the transparency list
	/// \return bool = true if this object uses transparency
	virtual bool IsAlphaObject();

	/// \brief Gets the internal mesh
	virtual IMeshObject * GetMeshObject();

	/// Gets the number of Geometry elements this renderobject possesses or if it uses geometry at all	
	virtual UINT GetNumGeometry(){ return 0; }

	/// Grabs the geometry pieces of the render object if there is any uses it for render instead
	/// of the render object render(might need to be changed)
	virtual IGeometry* GetGeometry( int index ){ return NULL; }

	virtual void AttachLight( ILightObject * light ) { }
	virtual void DetachAllLights() { }
	virtual IMaterial * GetMaterial( int index ){ return NULL; }
	virtual UINT GetNumMaterial() { return 0; }
	virtual ISceneSettings * GetSceneSettings(){ return NULL; }

	// Messages
	DWORD OnSetEnvMapTexture( DWORD size, void *params );

private:
	void RenderHeightmapAnimations( float fAnimSpeed, IEffect *pEffect );
	void CreateRadialGrid();
	void DestroyRadialGrid();
	void CreateTextures();
	void DestroyTextures();
	void CreateTextureGenerationGeometry();
	void DestroyTextureGenerationGeometry();

	/// Pointer to the IRenderer
	bool m_bAddToHierarchy;
	IRenderer * m_IRenderer;
	Matrix4x4 m_bParentTransform;
	float m_fCurrentTime;
	float m_fPreviousAnimationTime;

	BUFFERALLOCATIONSTRUCT m_VertexBufferAllocation;
	IVertexBufferObject *m_VertexBuffer;
	BUFFERALLOCATIONSTRUCT m_IndexBufferAllocation;
	IIndexBuffer *m_IndexBuffer;

	IEffect *m_pEffect;

	IBaseTextureObject *m_pHeightmapTextures[OCEAN_HEIGHTMAPTEXTURE_COUNT];
	ITextureObject *m_pHeightmapRenderTarget0;
	ITextureObject *m_pHeightmapRenderTarget1;
	IEffect *m_pHeightmapGenerationEffect;
	bool m_bRenderTargetActive;
	float m_fRenderingHeightmapAnimSpeed;
	CHashString m_hszRenderTargetCameraName;
	BUFFERALLOCATIONSTRUCT m_TextureGenerationVB;
	IVertexBufferObject *m_TextureGenerationVBI;

	IBaseTextureObject *m_pFoamTexture;
	IBaseTextureObject *m_pEnvMap;
	ITextureObject *m_pFresnelLookup;

	StdString m_szFoamTexture;
	StdString m_szEnvMapTexture;
	Vec3 m_DiffuseColor;
	float m_AmbientValue;
	Vec3 m_SunDir;
	float m_fClipScale;
	float m_fClipOffset;
	float m_fTextureScale;
	float m_fWindy;
};

#endif //OCEANRENDEROBJECT_H
