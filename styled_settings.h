// ---------------------------------------------------------------------------

#ifndef styled_settingsH
#define styled_settingsH

// ---------------------------------------------------------------------------

#include <FMX.ListBox.hpp>
#include <FMX.Menus.hpp>
#include <FMX.StdCtrls.hpp>

// ---------------------------------------------------------------------------

extern void ListBoxItemStyledSettings(
	TListBoxItem * SourceItem,
	int            FontSize,
	bool           RegularFont );
extern void PopupMenuStyledSettings(
	TMenuItem * SourceMenuItem,
	int         FontSize );
extern void ButtonStyledSettings(
	TButton * SourceButton,
	int       FontSize );

#endif
