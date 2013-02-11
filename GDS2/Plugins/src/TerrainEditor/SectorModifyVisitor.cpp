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

#include "StdAfx.h"

CSectorModifyVisitor::CSectorModifyVisitor(CTerrainEditor *pParent) :
	  m_SectorClassHashName(_T("CTerrainSector"))
{
	m_ToolBox = EngineGetToolBox();
	m_pParent = pParent;
}

bool CSectorModifyVisitor::IsHierarchicalVisitor() 
{
	return false; 
}

bool CSectorModifyVisitor::Visit( IComponent * component, bool bVisitEnter)
{
	if (component->GetComponentType()->GetUniqueID() == m_SectorClassHashName.GetUniqueID())
	{
		IObject *object;
		object = dynamic_cast<IObject *>(component);
		m_pParent->SetSectorModified(object->GetName());
	}
	return true;
}
