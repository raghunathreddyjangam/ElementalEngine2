///============================================================================
/// \file		SplinePointRender.h
/// \brief		Declaration of CSplinePointRenderObject Class
/// \date		09-10-2005
/// \author		D. Patrick Ghiocel
///============================================================================
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
///============================================================================

#ifndef __SPLINEPOINTRENDEROBJECT_H__
#define __SPLINEPOINTRENDEROBJECT_H__

#include "CObjectTemplate.hpp"
#include "Vec3.h"
#include "IRenderObject.h"

class CSplinePointRenderObject : public CSceneObject<IRenderObject>
{
private:
	/// Default Constructor
	CSplinePointRenderObject(IHashString *parentName, IHashString *name, bool bAddToHier);

public:
	/// Default Destructor
	~CSplinePointRenderObject();

    static IComponent *Create(int nArgs, va_list argptr);

	/// Init
	virtual void Init();
	/// DeInit
	virtual void DeInit();

	/// Serialize this component to the archive.
	///	\param ar = reference to the archive class
	virtual void Serialize( IArchive &ar );

	/// return a string of the component type
	/// \return IHashString *reference to textual classname
	virtual IHashString *GetComponentType();

	/// Checks if this is similar to it's base classes component
	/// \return true if it is simlar, else false
	virtual bool IsKindOf(IHashString *compType);

	/// Render the renderobject
	/// \return true if object was rendered, false otherwise
	virtual bool Render( UINT pass, IEffect * override );

	/// Compare for sorting
	/// \param obj = object to compare to
	/// \param sortMethod = a sort method specifying how to compare(set in RENDEROBJECTCOMPARE)
	/// \param curRenderPass = the current render pass to sort to
	/// \return bool = must return true if (this pointer) < (obj)
	virtual bool IsLessThan( const IRenderObject * obj, DWORD sortMethod, int curRenderPass );

	/// This is for render priorities between classes
	/// will change as soon as a new architecture can be designed to better incorporate
	/// different renderobject types being pushed on the same sorted list
	/// \return DWORD = the priority key this returns, the higher the number,
	/// the higher its priority
	virtual DWORD GetRenderPriority();

	/// Number of passes this render object has to go through
	/// \return UINT = the number of passes that this object has to go through
	virtual UINT GetNumPass();

	/// Sets the position of the render object
	/// \param position Vec3 class reference to fill in
	virtual void SetPosition( const Vec3 &position );

	/// Gets the position of the render object
	/// \return Vec3 = position f the object
	virtual Vec3 &GetPosition();

	/// Gets the base sort class which implements IRenderObject::IsLessThan()
	/// child classes must not re-implement IsLessThan() if they return the BaseSortClass hash!!
	/// typically, each render object has a IsLessThan() and returns a unique BaseSortClass
	virtual IHashString* GetBaseSortClass();

	/// returns if this renderobject needs to be sorted in the transparency list
	/// \return bool = true if this object uses transparency
	virtual bool IsAlphaObject();

	/// Gets the internal mesh
	virtual IMeshObject* GetMeshObject();

	/// Gets the number of Geometry elements this renderobject possesses or if it uses geometry at all	
	virtual UINT GetNumGeometry(){ return 0; }

	/// Grabs the geometry pieces of the render object if there is any uses it for render instead
	/// of the render object render(might need to be changed)
	virtual IGeometry* GetGeometry( int index ){ return NULL; }

	/// Returns the Bounding Box for the Object
	virtual bool GetBoundingBox( Vec3 &pos, Vec3 &dim, EulerAngle &rotation );


	// Stub functions unused from IRenderObject interface
	virtual void AttachLight( ILightObject * light ){};
	virtual void DetachAllLights(){};
	
	virtual IMaterial * GetMaterial( int index ){ return NULL; }
	virtual UINT GetNumMaterial() { return 0; }
	virtual ISceneSettings * GetSceneSettings(){ return NULL; }

	/// Turns on/off spline rendering
	/// \param value = to render (t/f)
	void SetToRender( bool value );

	// Messages
	/// 
	DWORD OnSetGlobalPosition( DWORD size, void *params );

private:
	/// Pointed to the EE Tool Box
	IToolBox *m_ToolBox;

	/// Pointer to the IRenderer
	IRenderer * m_IRenderer;

	/// Class Type
	CHashString m_hszNameType;

	/// Size of BoundingBox of Point
	Vec3 m_Ends;

	/// Flag to turn on/off spline rendering
	bool m_bRender;

	bool m_bAddToHierarchy;
};

#endif //__SPLINEPOINTRENDEROBJECT_H__

