///============================================================================
/// \file		RadioViewObject.h
/// \brief		Header file for radio box object in a view
/// \date		08-03-2005
/// \author		Kenneth Hurley
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

#ifndef _RADIOVIEWOBJECT_H_
#define _RADIOVIEWOBJECT_H_

class CRadioViewObject : public IRadioViewObject
{
public:
	CRadioViewObject();
	CRadioViewObject(StdString &name, StdString &basicType);
	~CRadioViewObject();

	/// \brief	Creates a radio item and adds it to the tree
	///			Will also create and return ViewFormatObject containing 
	///			formatting data for the created option tree item.
	/// \param	ar - the xml archive to read data from
	/// \return	ViewFormatObject* - returns a new ViewFormatObject
	static ViewFormatObject* CreateFormatObject(IXMLArchive &ar);

	/// Get the list of selectable items
	RADIOLIST* GetRadioList();

	/// Get the selected item
	StdString& GetDefSelect();

	/// Set the item that is initially selected
	void SetDefSelect(StdString& defSelect);
	
	/// Add a selectable item
	void AddListEntry(StdString &entry);

private:

	/// list of selectable items
	RADIOLIST *m_RadioList;
	/// initialy selected item
	StdString m_szDefSelect;

};

#endif // #ifndef _RADIOVIEWOBJECT_H_
