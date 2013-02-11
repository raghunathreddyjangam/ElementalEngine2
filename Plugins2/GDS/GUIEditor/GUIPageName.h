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

#ifndef _C_GUIPAGENAME_H_
#define _C_GUIPAGENAME_H_

class CGUIEditorDoc;

// CGUIPageName dialog

class CGUIPageName : public CDialog
{
	DECLARE_DYNAMIC(CGUIPageName)

public:
	CGUIPageName(CWnd* pParent = NULL);   // standard constructor
	virtual ~CGUIPageName();

// Dialog Data
	enum { IDD = IDD_ENTERPAGENAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CGUIEditorDoc *m_Doc;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void SetPageName(StdString name);
	void SetDocParent(CGUIEditorDoc *value) { m_Doc = value; }
	CString m_szPageName;
};

#endif