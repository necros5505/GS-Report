// ---------------------------------------------------------------------------

#ifndef clipboard_initH
#define clipboard_initH

// ---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Clipboard.hpp>

// ---------------------------------------------------------------------------
extern System::UnicodeString GetCText( );
extern void SetCText( System::UnicodeString Text );
extern void InitCService( );
#endif
