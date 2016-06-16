#pragma once

// Seung-Chan Kim
// ddListBox

class ddListBox : public CListBox
{
	DECLARE_DYNAMIC(ddListBox)

public:
	ddListBox();
	virtual ~ddListBox();

	UINT WhoAmI();
	void dbg(LPCTSTR,...);
	void SelectLastItem();

protected:
	DECLARE_MESSAGE_MAP()
};


