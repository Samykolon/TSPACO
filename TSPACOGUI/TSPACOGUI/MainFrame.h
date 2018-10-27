#pragma once

namespace TSPACOGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für MainFrame
	/// </summary>
	public ref class MainFrame : public System::Windows::Forms::Form
	{
	public:
		MainFrame(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~MainFrame()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lXML;
	protected:
	private: System::Windows::Forms::OpenFileDialog^  ofdxml;
	private: System::Windows::Forms::Button^  bXMLFileDialog;
	private: System::Windows::Forms::TextBox^  tbLoadXML;


	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lXML = (gcnew System::Windows::Forms::Label());
			this->ofdxml = (gcnew System::Windows::Forms::OpenFileDialog());
			this->bXMLFileDialog = (gcnew System::Windows::Forms::Button());
			this->tbLoadXML = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// lXML
			// 
			this->lXML->AutoSize = true;
			this->lXML->Location = System::Drawing::Point(12, 13);
			this->lXML->Name = L"lXML";
			this->lXML->Size = System::Drawing::Size(93, 13);
			this->lXML->TabIndex = 0;
			this->lXML->Text = L"XML-Datei öffnen:";
			// 
			// ofdxml
			// 
			this->ofdxml->FileName = L"openFileDialog1";
			// 
			// bXMLFileDialog
			// 
			this->bXMLFileDialog->Location = System::Drawing::Point(464, 8);
			this->bXMLFileDialog->Name = L"bXMLFileDialog";
			this->bXMLFileDialog->Size = System::Drawing::Size(114, 23);
			this->bXMLFileDialog->TabIndex = 1;
			this->bXMLFileDialog->Text = L"Durchsuchen";
			this->bXMLFileDialog->UseVisualStyleBackColor = true;
			this->bXMLFileDialog->Click += gcnew System::EventHandler(this, &MainFrame::bXMLFileDialog_Click);
			// 
			// tbLoadXML
			// 
			this->tbLoadXML->Location = System::Drawing::Point(109, 10);
			this->tbLoadXML->Name = L"tbLoadXML";
			this->tbLoadXML->Size = System::Drawing::Size(349, 20);
			this->tbLoadXML->TabIndex = 2;
			// 
			// MainFrame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(593, 519);
			this->Controls->Add(this->tbLoadXML);
			this->Controls->Add(this->bXMLFileDialog);
			this->Controls->Add(this->lXML);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainFrame";
			this->ShowIcon = false;
			this->Text = L"TSP with ACO";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bXMLFileDialog_Click(System::Object^  sender, System::EventArgs^  e) {

		ofdxml->FileName = "";
		ofdxml->DefaultExt = L".xml";
		ofdxml->AddExtension;
		ofdxml->Filter = L"XML-Datei (*.xml) | *.xml";

		try {
			if (ofdxml->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				tbLoadXML->Text = ofdxml->FileName;
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ungültiger Pfad!");
		}


	}
	};
}
