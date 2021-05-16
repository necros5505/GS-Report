// ---------------------------------------------------------------------------

#pragma hdrstop

#include "listboxitem.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)

TListBoxItem * CreateListBoxItem(
	System::UnicodeString Text,
	System::UnicodeString Detail,
	bool                  RegularFont )
{
	TListBoxItem * Item = new TListBoxItem( NULL );
	ListBoxItemStyledSettings( Item, 14, RegularFont );
	Item->Text = Text;
	Item->ItemData->Detail = Detail;
	return Item;
}
