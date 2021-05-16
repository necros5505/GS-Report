// ---------------------------------------------------------------------------

#ifndef listboxitemH
#define listboxitemH

// ---------------------------------------------------------------------------

#include <FMX.ListBox.hpp>
#include "styled_settings.h"

// ---------------------------------------------------------------------------
extern TListBoxItem * CreateListBoxItem(
	System::UnicodeString Text,
	System::UnicodeString Detail,
	bool                  RegularFont );
#endif
