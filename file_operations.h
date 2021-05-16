// ---------------------------------------------------------------------------

#ifndef file_operationsH
#define file_operationsH

// ---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <System.IOUtils.hpp>
#include <System.IniFiles.hpp>
#include <Fmx.Types.hpp>

#include "settings.h"
#include "listboxitem.h"

// ---------------------------------------------------------------------------

extern const System::UnicodeString SETTINGS_FILE_NAME;
extern const System::UnicodeString SERVER_LIST_FILE_NAME;
extern const System::UnicodeString TAG_LIST_FILE_NAME;
extern const System::UnicodeString REPORT_FORMAT_FILE_NAME;
extern const System::UnicodeString SERVER_LIST_RESOURCE_NAME;
extern const System::UnicodeString TAG_LIST_RESOURCE_NAME;
extern const System::UnicodeString REPORT_FORMAT_RESOURCE_NAME;

extern TStringList * LoadListFromFile( System::UnicodeString AFileName );
extern void ShowInExplorer(
	System::UnicodeString APath,
	bool                  SelectLastFile );
extern void SaveSettings( );
extern void LoadSettings( );
extern TResourceStream * LoadListFromResource( System::UnicodeString ResourceName );
#endif
