// ---------------------------------------------------------------------------

#pragma hdrstop

#include "styled_settings.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

const System::UnicodeString REGULAR_FONT_NAME = "Roboto";
const System::UnicodeString FONT_NAME = "Roboto Light";
const int DEF_FONT_SIZE = 14;

void ListBoxItemStyledSettings(
	TListBoxItem * SourceItem,
	int            FontSize,
	bool           RegularFont )
{
	SourceItem->TextSettings->BeginUpdate( );
	SourceItem->StyledSettings = SourceItem->StyledSettings >> TStyledSetting::Family;
	SourceItem->StyledSettings = SourceItem->StyledSettings >> TStyledSetting::Size;
	SourceItem->TextSettings->Font->Family = RegularFont ? REGULAR_FONT_NAME : FONT_NAME;
	SourceItem->TextSettings->Font->Size = ( FontSize > 0 ) ? FontSize : DEF_FONT_SIZE;
	SourceItem->TextSettings->EndUpdate( );
}

void PopupMenuStyledSettings(
	TMenuItem * SourceMenuItem,
	int         FontSize )
{
	SourceMenuItem->TextSettings->BeginUpdate( );
	SourceMenuItem->StyledSettings = SourceMenuItem->StyledSettings >> TStyledSetting::Family;
	SourceMenuItem->StyledSettings = SourceMenuItem->StyledSettings >> TStyledSetting::Size;
	SourceMenuItem->TextSettings->Font->Family = FONT_NAME;
	SourceMenuItem->TextSettings->Font->Size = FontSize > 0 ? FontSize : DEF_FONT_SIZE;
	SourceMenuItem->TextSettings->EndUpdate( );
}

void ButtonStyledSettings(
	TButton * SourceButton,
	int       FontSize )
{
	SourceButton->TextSettings->BeginUpdate( );
	SourceButton->StyledSettings = SourceButton->StyledSettings >> TStyledSetting::Family;
	SourceButton->StyledSettings = SourceButton->StyledSettings >> TStyledSetting::Size;
	SourceButton->TextSettings->Font->Family = FONT_NAME;
	SourceButton->TextSettings->Font->Size = FontSize > 0 ? FontSize : DEF_FONT_SIZE;
	SourceButton->TextSettings->EndUpdate( );
}
