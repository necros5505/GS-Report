// ---------------------------------------------------------------------------

#ifndef settingsH
#define settingsH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>
#include <System.Rtti.hpp>

#include <FMX.Dialogs.hpp>
#include <System.IniFiles.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>

#include "file_operations.h"
#include "main.h"
//#include "listboxitem.h"

// ---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published: // IDE-managed Components
	TCheckBox * CheckBox1;
	TListBox * ListBox1;
	TEdit * Edit1;
	TLabel * Label1;
	TButton * Button1;
	TButton * Button2;
	TCheckBox * CheckBox2;
	TButton * Button3;
	TButton * Button4;
	TLabel * Label2;
	TListBox * ListBox2;
	TButton * Button5;
	TButton * Button6;
	TButton * Button7;
	TButton * Button8;
	TLabel * Label3;
	TButton * Button9;
	TEdit * Edit2;
	TLabel * Label4;
	TLabel * Label5;
	TEdit * Edit3;
	TButton * Button10;
	TButton * Button11;
	TCheckBox * CheckBox3;
	TMemo * Memo1;
	TLabel * Label6;
	TButton * Button12;

	void __fastcall Button10Click( TObject * Sender );
	void __fastcall Button9Click( TObject * Sender );
	void __fastcall Button11Click( TObject * Sender );
	void __fastcall Button1Click( TObject * Sender );
	void __fastcall Button2Click( TObject * Sender );
	void __fastcall Button8Click( TObject * Sender );
	void __fastcall Button7Click( TObject * Sender );
	void __fastcall Button5Click( TObject * Sender );
	void __fastcall Button6Click( TObject * Sender );
	void __fastcall Button3Click( TObject * Sender );
	void __fastcall Button4Click( TObject * Sender );
	void __fastcall FormShow( TObject * Sender );
	void __fastcall FormClose(
		TObject *      Sender,
		TCloseAction & Action );
	void __fastcall FormCreate( TObject * Sender );
	void __fastcall FillMainServerList( TObject * Sender );
	void __fastcall Button12Click( TObject * Sender );
	void __fastcall ListBox1DblClick( TObject * Sender );
	void __fastcall ListBox2DblClick( TObject * Sender );
	void __fastcall CheckBox2Change( TObject * Sender );

private: // User declarations
public: // User declarations
	__fastcall TForm2( TComponent * Owner );
	System::UnicodeString GetDir( );
} ;

// ---------------------------------------------------------------------------
extern PACKAGE TForm2 * Form2;
// ---------------------------------------------------------------------------
#endif
