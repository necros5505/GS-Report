// ---------------------------------------------------------------------------

#ifndef clipboard_threadH
#define clipboard_threadH

// ---------------------------------------------------------------------------

#include <System.Classes.hpp>

// ---------------------------------------------------------------------------

class TClipboardWt : public TThread
{
private:
	bool FCanAdd;
	bool FPause;
	TStringList * FList;

	void __fastcall UpdateListBox( );

protected:
	void __fastcall Execute( );

public:
	__fastcall TClipboardWt( bool CreateSuspended );
	__property bool IsPaused =
	{
		read = FPause,
		write = FPause
	} ;
} ;
// ---------------------------------------------------------------------------

#endif
