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
			tbReduction->Enabled = false;
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
	private: System::Windows::Forms::Button^  bOpenXML;
	private: System::Windows::Forms::Label^  lNumberAnts;
	private: System::Windows::Forms::GroupBox^  gpSettings;
	private: System::Windows::Forms::Label^  lAlgorithm;
	private: System::Windows::Forms::TextBox^  tbIteration;
	private: System::Windows::Forms::Label^  lIteration;
	private: System::Windows::Forms::RadioButton^  rbParallel;
	private: System::Windows::Forms::RadioButton^  rbIterative;
	private: System::Windows::Forms::TextBox^  tbReduction;
	private: System::Windows::Forms::CheckBox^  cbReduction;
	private: System::Windows::Forms::TextBox^  tbPheromoneReduction;
	private: System::Windows::Forms::Label^  lPheromoneReduction;
	private: System::Windows::Forms::TextBox^  tbPheromoneDeposit;
	private: System::Windows::Forms::Label^  lPheromoneDeposit;
	private: System::Windows::Forms::TextBox^  tbBeta;
	private: System::Windows::Forms::Label^  lBeta;
	private: System::Windows::Forms::TextBox^  tbAlpha;
	private: System::Windows::Forms::Label^  lAlpha;
	private: System::Windows::Forms::TextBox^  tbNumberAnts;


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
			this->bOpenXML = (gcnew System::Windows::Forms::Button());
			this->lNumberAnts = (gcnew System::Windows::Forms::Label());
			this->gpSettings = (gcnew System::Windows::Forms::GroupBox());
			this->lAlgorithm = (gcnew System::Windows::Forms::Label());
			this->tbIteration = (gcnew System::Windows::Forms::TextBox());
			this->lIteration = (gcnew System::Windows::Forms::Label());
			this->rbParallel = (gcnew System::Windows::Forms::RadioButton());
			this->rbIterative = (gcnew System::Windows::Forms::RadioButton());
			this->tbReduction = (gcnew System::Windows::Forms::TextBox());
			this->cbReduction = (gcnew System::Windows::Forms::CheckBox());
			this->tbPheromoneReduction = (gcnew System::Windows::Forms::TextBox());
			this->lPheromoneReduction = (gcnew System::Windows::Forms::Label());
			this->tbPheromoneDeposit = (gcnew System::Windows::Forms::TextBox());
			this->lPheromoneDeposit = (gcnew System::Windows::Forms::Label());
			this->tbBeta = (gcnew System::Windows::Forms::TextBox());
			this->lBeta = (gcnew System::Windows::Forms::Label());
			this->tbAlpha = (gcnew System::Windows::Forms::TextBox());
			this->lAlpha = (gcnew System::Windows::Forms::Label());
			this->tbNumberAnts = (gcnew System::Windows::Forms::TextBox());
			this->gpSettings->SuspendLayout();
			this->SuspendLayout();
			// 
			// lXML
			// 
			this->lXML->AutoSize = true;
			this->lXML->Location = System::Drawing::Point(12, 13);
			this->lXML->Name = L"lXML";
			this->lXML->Size = System::Drawing::Size(80, 13);
			this->lXML->TabIndex = 0;
			this->lXML->Text = L"Open XML-File:";
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
			this->bXMLFileDialog->Text = L"Search...";
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
			// bOpenXML
			// 
			this->bOpenXML->Location = System::Drawing::Point(15, 341);
			this->bOpenXML->Name = L"bOpenXML";
			this->bOpenXML->Size = System::Drawing::Size(563, 23);
			this->bOpenXML->TabIndex = 3;
			this->bOpenXML->Text = L"Start";
			this->bOpenXML->UseVisualStyleBackColor = true;
			// 
			// lNumberAnts
			// 
			this->lNumberAnts->AutoSize = true;
			this->lNumberAnts->Location = System::Drawing::Point(18, 26);
			this->lNumberAnts->Name = L"lNumberAnts";
			this->lNumberAnts->Size = System::Drawing::Size(83, 13);
			this->lNumberAnts->TabIndex = 4;
			this->lNumberAnts->Text = L"Number of Ants:";
			// 
			// gpSettings
			// 
			this->gpSettings->Controls->Add(this->lAlgorithm);
			this->gpSettings->Controls->Add(this->tbIteration);
			this->gpSettings->Controls->Add(this->lIteration);
			this->gpSettings->Controls->Add(this->rbParallel);
			this->gpSettings->Controls->Add(this->rbIterative);
			this->gpSettings->Controls->Add(this->tbReduction);
			this->gpSettings->Controls->Add(this->cbReduction);
			this->gpSettings->Controls->Add(this->tbPheromoneReduction);
			this->gpSettings->Controls->Add(this->lPheromoneReduction);
			this->gpSettings->Controls->Add(this->tbPheromoneDeposit);
			this->gpSettings->Controls->Add(this->lPheromoneDeposit);
			this->gpSettings->Controls->Add(this->tbBeta);
			this->gpSettings->Controls->Add(this->lBeta);
			this->gpSettings->Controls->Add(this->tbAlpha);
			this->gpSettings->Controls->Add(this->lAlpha);
			this->gpSettings->Controls->Add(this->tbNumberAnts);
			this->gpSettings->Controls->Add(this->lNumberAnts);
			this->gpSettings->Location = System::Drawing::Point(15, 48);
			this->gpSettings->Name = L"gpSettings";
			this->gpSettings->Size = System::Drawing::Size(563, 287);
			this->gpSettings->TabIndex = 5;
			this->gpSettings->TabStop = false;
			this->gpSettings->Text = L"Settings";
			// 
			// lAlgorithm
			// 
			this->lAlgorithm->AutoSize = true;
			this->lAlgorithm->Location = System::Drawing::Point(242, 206);
			this->lAlgorithm->Name = L"lAlgorithm";
			this->lAlgorithm->Size = System::Drawing::Size(85, 13);
			this->lAlgorithm->TabIndex = 21;
			this->lAlgorithm->Text = L"Switch Algorithm";
			// 
			// tbIteration
			// 
			this->tbIteration->Location = System::Drawing::Point(271, 254);
			this->tbIteration->Name = L"tbIteration";
			this->tbIteration->Size = System::Drawing::Size(135, 20);
			this->tbIteration->TabIndex = 20;
			// 
			// lIteration
			// 
			this->lIteration->AutoSize = true;
			this->lIteration->Location = System::Drawing::Point(154, 257);
			this->lIteration->Name = L"lIteration";
			this->lIteration->Size = System::Drawing::Size(53, 13);
			this->lIteration->TabIndex = 19;
			this->lIteration->Text = L"Iterations:";
			// 
			// rbParallel
			// 
			this->rbParallel->AutoSize = true;
			this->rbParallel->Location = System::Drawing::Point(347, 228);
			this->rbParallel->Name = L"rbParallel";
			this->rbParallel->Size = System::Drawing::Size(59, 17);
			this->rbParallel->TabIndex = 18;
			this->rbParallel->Text = L"Parallel";
			this->rbParallel->UseVisualStyleBackColor = true;
			// 
			// rbIterative
			// 
			this->rbIterative->AutoSize = true;
			this->rbIterative->Checked = true;
			this->rbIterative->Location = System::Drawing::Point(157, 228);
			this->rbIterative->Name = L"rbIterative";
			this->rbIterative->Size = System::Drawing::Size(63, 17);
			this->rbIterative->TabIndex = 17;
			this->rbIterative->TabStop = true;
			this->rbIterative->Text = L"Iterative";
			this->rbIterative->UseVisualStyleBackColor = true;
			this->rbIterative->CheckedChanged += gcnew System::EventHandler(this, &MainFrame::rbIterative_CheckedChanged);
			// 
			// tbReduction
			// 
			this->tbReduction->Location = System::Drawing::Point(159, 159);
			this->tbReduction->Name = L"tbReduction";
			this->tbReduction->Size = System::Drawing::Size(135, 20);
			this->tbReduction->TabIndex = 16;
			// 
			// cbReduction
			// 
			this->cbReduction->AutoSize = true;
			this->cbReduction->Location = System::Drawing::Point(21, 161);
			this->cbReduction->Name = L"cbReduction";
			this->cbReduction->Size = System::Drawing::Size(111, 17);
			this->cbReduction->TabIndex = 15;
			this->cbReduction->Text = L"Overall Reduction";
			this->cbReduction->UseVisualStyleBackColor = true;
			this->cbReduction->CheckedChanged += gcnew System::EventHandler(this, &MainFrame::cbReduction_CheckedChanged);
			// 
			// tbPheromoneReduction
			// 
			this->tbPheromoneReduction->Location = System::Drawing::Point(159, 125);
			this->tbPheromoneReduction->Name = L"tbPheromoneReduction";
			this->tbPheromoneReduction->Size = System::Drawing::Size(135, 20);
			this->tbPheromoneReduction->TabIndex = 13;
			// 
			// lPheromoneReduction
			// 
			this->lPheromoneReduction->AutoSize = true;
			this->lPheromoneReduction->Location = System::Drawing::Point(18, 128);
			this->lPheromoneReduction->Name = L"lPheromoneReduction";
			this->lPheromoneReduction->Size = System::Drawing::Size(108, 13);
			this->lPheromoneReduction->TabIndex = 12;
			this->lPheromoneReduction->Text = L"Pheromonereduction:";
			// 
			// tbPheromoneDeposit
			// 
			this->tbPheromoneDeposit->Location = System::Drawing::Point(159, 92);
			this->tbPheromoneDeposit->Name = L"tbPheromoneDeposit";
			this->tbPheromoneDeposit->Size = System::Drawing::Size(135, 20);
			this->tbPheromoneDeposit->TabIndex = 11;
			// 
			// lPheromoneDeposit
			// 
			this->lPheromoneDeposit->AutoSize = true;
			this->lPheromoneDeposit->Location = System::Drawing::Point(18, 95);
			this->lPheromoneDeposit->Name = L"lPheromoneDeposit";
			this->lPheromoneDeposit->Size = System::Drawing::Size(98, 13);
			this->lPheromoneDeposit->TabIndex = 10;
			this->lPheromoneDeposit->Text = L"Pheromonedeposit:";
			// 
			// tbBeta
			// 
			this->tbBeta->Location = System::Drawing::Point(410, 58);
			this->tbBeta->Name = L"tbBeta";
			this->tbBeta->Size = System::Drawing::Size(135, 20);
			this->tbBeta->TabIndex = 9;
			// 
			// lBeta
			// 
			this->lBeta->AutoSize = true;
			this->lBeta->Location = System::Drawing::Point(320, 61);
			this->lBeta->Name = L"lBeta";
			this->lBeta->Size = System::Drawing::Size(32, 13);
			this->lBeta->TabIndex = 8;
			this->lBeta->Text = L"Beta:";
			// 
			// tbAlpha
			// 
			this->tbAlpha->Location = System::Drawing::Point(159, 58);
			this->tbAlpha->Name = L"tbAlpha";
			this->tbAlpha->Size = System::Drawing::Size(135, 20);
			this->tbAlpha->TabIndex = 7;
			// 
			// lAlpha
			// 
			this->lAlpha->AutoSize = true;
			this->lAlpha->Location = System::Drawing::Point(18, 61);
			this->lAlpha->Name = L"lAlpha";
			this->lAlpha->Size = System::Drawing::Size(37, 13);
			this->lAlpha->TabIndex = 6;
			this->lAlpha->Text = L"Alpha:";
			// 
			// tbNumberAnts
			// 
			this->tbNumberAnts->Location = System::Drawing::Point(159, 23);
			this->tbNumberAnts->Name = L"tbNumberAnts";
			this->tbNumberAnts->Size = System::Drawing::Size(135, 20);
			this->tbNumberAnts->TabIndex = 5;
			// 
			// MainFrame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(593, 376);
			this->Controls->Add(this->gpSettings);
			this->Controls->Add(this->bOpenXML);
			this->Controls->Add(this->tbLoadXML);
			this->Controls->Add(this->bXMLFileDialog);
			this->Controls->Add(this->lXML);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainFrame";
			this->ShowIcon = false;
			this->Text = L"TSP with ACO";
			this->gpSettings->ResumeLayout(false);
			this->gpSettings->PerformLayout();
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
				String^ filename = ofdxml->FileName;
				filename = filename->Replace(L"\\", L"/");
				tbLoadXML->Text = filename;
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ungültiger Pfad!");
		}


	}
	private: System::Void rbIterative_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (rbIterative->Checked == true)
			tbIteration->Enabled = true;
		else if (rbIterative->Checked == false)
			tbIteration->Enabled = false;
	}

private: System::Void cbReduction_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (cbReduction->Checked == true)
		tbReduction->Enabled = true;
	else if (cbReduction->Checked == false)
		tbReduction->Enabled = false;
}
};
}
