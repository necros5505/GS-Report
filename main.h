// ---------------------------------------------------------------------------

#ifndef mainH
#define mainH

// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.ComboEdit.hpp>
#include <FMX.Edit.hpp>
#include <System.Rtti.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Menus.hpp>
#include <System.UITypes.hpp>

#include "clipboard_thread.h"
#include "clipboard_init.h"
#include "settings.h"

// ---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published: // IDE-managed Components
	TLabel * Label1;
	TLabel * Label2;
	TLabel * Label3;
	TLabel * Label4;
	TMemo * Memo1;
	TLabel * Label5;
	TButton * Button1;
	TButton * Button2;
	TButton * Button3;
	TComboEdit * ComboEdit1;
	TLayout * Layout1;
	TLayout * Layout2;
	TButton * Button4;
	TLayout * Layout3;
	TSwitch * Switch1;
	TLabel * Label6;
	TButton * Button5;
	TPopup * Popup1;
	TPopupMenu * PopupMenu1;
	TMenuItem * MenuItem1;
	TMenuItem * MenuItem2;
	TMenuItem * MenuItem3;
	TMenuItem * MenuItem4;
	TEdit * Edit1;
	TEdit * Edit2;
	TListBox * ListBox1;

	void __fastcall Label6Click( TObject * Sender );
	void __fastcall Button4Click( TObject * Sender );
	void __fastcall OnTagItemClick(
		TCustomListBox * const Sender,
		TListBoxItem * const   Item );
	void __fastcall OnTagPasteClick( TObject * Sender );
	void __fastcall Button5Click( TObject * Sender );
	void __fastcall Button1Click( TObject * Sender );
	void __fastcall Button2Click( TObject * Sender );
	void __fastcall OnPopup( TObject * Sender );
	void __fastcall PopupMenu1Popup( TObject * Sender );
	void __fastcall MenuItem1Click( TObject * Sender );
	void __fastcall MenuItem2Click( TObject * Sender );
	void __fastcall MenuItem4Click( TObject * Sender );
	void __fastcall Button3Click( TObject * Sender );
	void __fastcall Switch1Switch( TObject * Sender );
	void __fastcall ListBox1DblClick( TObject * Sender );
	void __fastcall ListBox1MouseDown(
		TObject *    Sender,
		TMouseButton Button,
		TShiftState  Shift,
		float        X,
		float        Y );
	void __fastcall FormCreate( TObject * Sender );

private: // User declarations
public: // User declarations
	__fastcall TForm1( TComponent * Owner );

	TButton * FPopupButton;
	TListBox * FPopupListBox;

	void __fastcall CreatePopupListBox( );
	void __fastcall CreatePopupButton( );
	void __fastcall CreatePopupListBoxItem( );
} ;

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 * Form1;
// ---------------------------------------------------------------------------
#endif
