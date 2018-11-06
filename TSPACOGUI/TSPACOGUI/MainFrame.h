#pragma once
#include <shlobj.h>
#include <shlwapi.h>
#include <objbase.h>
#include <string.h>
#include <msclr\marshal_cppstd.h>
#include <fstream>

namespace TSPACOGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Diagnostics;
	using namespace std;

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

			tbRuns->Text = runs.ToString();
			tbAlpha->Text = alpha.ToString();
			tbBeta->Text = beta.ToString();
			tbNumberAnts->Text = numberants.ToString();
			tbPheromoneDeposit->Text = pheromonedeposit.ToString();
			tbPheromoneReduction->Text = pheromonereduction.ToString();
			tbReduction->Text = reducevalue.ToString();
			tbIteration->Text = iterationsmax.ToString();
			tbOV->Text = ovit.ToString();
			bOpenXML->Enabled = false;
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
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::GroupBox^  gpAlgorithm;
	private: System::Windows::Forms::GroupBox^  gpProbAlgorithm;
	private: System::Windows::Forms::RadioButton^  rbProbKomplex;
	private: System::Windows::Forms::RadioButton^  rbProbSimple;
	private: System::Windows::Forms::Label^  lRuns;
	private: System::Windows::Forms::TextBox^  tbRuns;
	private: System::Windows::Forms::Button^  bClear;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::CheckBox^  cbCSV;
	private: System::Windows::Forms::TextBox^  tbOV;
	private: System::Windows::Forms::Label^  lOV;
	private: System::Windows::Forms::RadioButton^  rbOV;



	private:
		
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
			this->tbIteration = (gcnew System::Windows::Forms::TextBox());
			this->lIteration = (gcnew System::Windows::Forms::Label());
			this->rbParallel = (gcnew System::Windows::Forms::RadioButton());
			this->rbIterative = (gcnew System::Windows::Forms::RadioButton());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->gpAlgorithm = (gcnew System::Windows::Forms::GroupBox());
			this->tbOV = (gcnew System::Windows::Forms::TextBox());
			this->lOV = (gcnew System::Windows::Forms::Label());
			this->rbOV = (gcnew System::Windows::Forms::RadioButton());
			this->gpProbAlgorithm = (gcnew System::Windows::Forms::GroupBox());
			this->rbProbKomplex = (gcnew System::Windows::Forms::RadioButton());
			this->rbProbSimple = (gcnew System::Windows::Forms::RadioButton());
			this->lRuns = (gcnew System::Windows::Forms::Label());
			this->tbRuns = (gcnew System::Windows::Forms::TextBox());
			this->bClear = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->cbCSV = (gcnew System::Windows::Forms::CheckBox());
			this->gpSettings->SuspendLayout();
			this->gpAlgorithm->SuspendLayout();
			this->gpProbAlgorithm->SuspendLayout();
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
			this->tbLoadXML->TextChanged += gcnew System::EventHandler(this, &MainFrame::tbLoadXML_TextChanged);
			// 
			// bOpenXML
			// 
			this->bOpenXML->Location = System::Drawing::Point(18, 480);
			this->bOpenXML->Name = L"bOpenXML";
			this->bOpenXML->Size = System::Drawing::Size(479, 23);
			this->bOpenXML->TabIndex = 3;
			this->bOpenXML->Text = L"Start";
			this->bOpenXML->UseVisualStyleBackColor = true;
			this->bOpenXML->Click += gcnew System::EventHandler(this, &MainFrame::bOpenXML_Click);
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
			this->gpSettings->Location = System::Drawing::Point(15, 74);
			this->gpSettings->Name = L"gpSettings";
			this->gpSettings->Size = System::Drawing::Size(563, 201);
			this->gpSettings->TabIndex = 5;
			this->gpSettings->TabStop = false;
			this->gpSettings->Text = L"Settings";
			// 
			// tbReduction
			// 
			this->tbReduction->Location = System::Drawing::Point(159, 159);
			this->tbReduction->Name = L"tbReduction";
			this->tbReduction->Size = System::Drawing::Size(135, 20);
			this->tbReduction->TabIndex = 16;
			this->tbReduction->TextChanged += gcnew System::EventHandler(this, &MainFrame::tbReduction_TextChanged);
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
			this->tbPheromoneReduction->Leave += gcnew System::EventHandler(this, &MainFrame::tbPheromoneReduction_Leave);
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
			this->tbPheromoneDeposit->Leave += gcnew System::EventHandler(this, &MainFrame::tbPheromoneDeposit_Leave);
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
			this->tbBeta->Leave += gcnew System::EventHandler(this, &MainFrame::tbBeta_Leave);
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
			this->tbAlpha->BackColor = System::Drawing::SystemColors::Window;
			this->tbAlpha->Location = System::Drawing::Point(159, 58);
			this->tbAlpha->Name = L"tbAlpha";
			this->tbAlpha->Size = System::Drawing::Size(135, 20);
			this->tbAlpha->TabIndex = 7;
			this->tbAlpha->Leave += gcnew System::EventHandler(this, &MainFrame::tbAlpha_Leave);
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
			this->tbNumberAnts->BackColor = System::Drawing::SystemColors::Window;
			this->tbNumberAnts->Location = System::Drawing::Point(159, 23);
			this->tbNumberAnts->Name = L"tbNumberAnts";
			this->tbNumberAnts->Size = System::Drawing::Size(135, 20);
			this->tbNumberAnts->TabIndex = 5;
			this->tbNumberAnts->Leave += gcnew System::EventHandler(this, &MainFrame::tbNumberAnts_Leave);
			// 
			// tbIteration
			// 
			this->tbIteration->Location = System::Drawing::Point(94, 56);
			this->tbIteration->Name = L"tbIteration";
			this->tbIteration->Size = System::Drawing::Size(100, 20);
			this->tbIteration->TabIndex = 20;
			this->tbIteration->Leave += gcnew System::EventHandler(this, &MainFrame::tbIteration_Leave);
			// 
			// lIteration
			// 
			this->lIteration->AutoSize = true;
			this->lIteration->Location = System::Drawing::Point(24, 59);
			this->lIteration->Name = L"lIteration";
			this->lIteration->Size = System::Drawing::Size(53, 13);
			this->lIteration->TabIndex = 19;
			this->lIteration->Text = L"Iterations:";
			// 
			// rbParallel
			// 
			this->rbParallel->AutoSize = true;
			this->rbParallel->Location = System::Drawing::Point(246, 30);
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
			this->rbIterative->Location = System::Drawing::Point(69, 30);
			this->rbIterative->Name = L"rbIterative";
			this->rbIterative->Size = System::Drawing::Size(63, 17);
			this->rbIterative->TabIndex = 17;
			this->rbIterative->TabStop = true;
			this->rbIterative->Text = L"Iterative";
			this->rbIterative->UseVisualStyleBackColor = true;
			this->rbIterative->CheckedChanged += gcnew System::EventHandler(this, &MainFrame::rbIterative_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(18, 509);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(563, 187);
			this->textBox1->TabIndex = 6;
			// 
			// gpAlgorithm
			// 
			this->gpAlgorithm->Controls->Add(this->tbOV);
			this->gpAlgorithm->Controls->Add(this->lOV);
			this->gpAlgorithm->Controls->Add(this->rbOV);
			this->gpAlgorithm->Controls->Add(this->tbIteration);
			this->gpAlgorithm->Controls->Add(this->rbIterative);
			this->gpAlgorithm->Controls->Add(this->rbParallel);
			this->gpAlgorithm->Controls->Add(this->lIteration);
			this->gpAlgorithm->Location = System::Drawing::Point(15, 282);
			this->gpAlgorithm->Name = L"gpAlgorithm";
			this->gpAlgorithm->Size = System::Drawing::Size(563, 100);
			this->gpAlgorithm->TabIndex = 22;
			this->gpAlgorithm->TabStop = false;
			this->gpAlgorithm->Text = L"Switch Algorithm";
			// 
			// tbOV
			// 
			this->tbOV->Location = System::Drawing::Point(420, 56);
			this->tbOV->Name = L"tbOV";
			this->tbOV->Size = System::Drawing::Size(100, 20);
			this->tbOV->TabIndex = 23;
			this->tbOV->Leave += gcnew System::EventHandler(this, &MainFrame::tbOV_Leave);
			// 
			// lOV
			// 
			this->lOV->AutoSize = true;
			this->lOV->Location = System::Drawing::Point(350, 59);
			this->lOV->Name = L"lOV";
			this->lOV->Size = System::Drawing::Size(53, 13);
			this->lOV->TabIndex = 22;
			this->lOV->Text = L"Iterations:";
			// 
			// rbOV
			// 
			this->rbOV->AutoSize = true;
			this->rbOV->Location = System::Drawing::Point(410, 30);
			this->rbOV->Name = L"rbOV";
			this->rbOV->Size = System::Drawing::Size(57, 17);
			this->rbOV->TabIndex = 21;
			this->rbOV->TabStop = true;
			this->rbOV->Text = L"MMAS";
			this->rbOV->UseVisualStyleBackColor = true;
			// 
			// gpProbAlgorithm
			// 
			this->gpProbAlgorithm->Controls->Add(this->rbProbKomplex);
			this->gpProbAlgorithm->Controls->Add(this->rbProbSimple);
			this->gpProbAlgorithm->Location = System::Drawing::Point(15, 389);
			this->gpProbAlgorithm->Name = L"gpProbAlgorithm";
			this->gpProbAlgorithm->Size = System::Drawing::Size(563, 79);
			this->gpProbAlgorithm->TabIndex = 23;
			this->gpProbAlgorithm->TabStop = false;
			this->gpProbAlgorithm->Text = L"Switch Probabilty-Function";
			// 
			// rbProbKomplex
			// 
			this->rbProbKomplex->AutoSize = true;
			this->rbProbKomplex->Location = System::Drawing::Point(338, 38);
			this->rbProbKomplex->Name = L"rbProbKomplex";
			this->rbProbKomplex->Size = System::Drawing::Size(65, 17);
			this->rbProbKomplex->TabIndex = 1;
			this->rbProbKomplex->Text = L"Komplex";
			this->rbProbKomplex->UseVisualStyleBackColor = true;
			// 
			// rbProbSimple
			// 
			this->rbProbSimple->AutoSize = true;
			this->rbProbSimple->Checked = true;
			this->rbProbSimple->Location = System::Drawing::Point(154, 38);
			this->rbProbSimple->Name = L"rbProbSimple";
			this->rbProbSimple->Size = System::Drawing::Size(56, 17);
			this->rbProbSimple->TabIndex = 0;
			this->rbProbSimple->TabStop = true;
			this->rbProbSimple->Text = L"Simple";
			this->rbProbSimple->UseVisualStyleBackColor = true;
			this->rbProbSimple->CheckedChanged += gcnew System::EventHandler(this, &MainFrame::rbProbSimple_CheckedChanged);
			// 
			// lRuns
			// 
			this->lRuns->AutoSize = true;
			this->lRuns->Location = System::Drawing::Point(13, 42);
			this->lRuns->Name = L"lRuns";
			this->lRuns->Size = System::Drawing::Size(35, 13);
			this->lRuns->TabIndex = 24;
			this->lRuns->Text = L"Runs:";
			// 
			// tbRuns
			// 
			this->tbRuns->Location = System::Drawing::Point(109, 42);
			this->tbRuns->Name = L"tbRuns";
			this->tbRuns->Size = System::Drawing::Size(100, 20);
			this->tbRuns->TabIndex = 25;
			this->tbRuns->Leave += gcnew System::EventHandler(this, &MainFrame::tbRuns_Leave);
			// 
			// bClear
			// 
			this->bClear->Location = System::Drawing::Point(503, 480);
			this->bClear->Name = L"bClear";
			this->bClear->Size = System::Drawing::Size(75, 23);
			this->bClear->TabIndex = 21;
			this->bClear->Text = L"Clear";
			this->bClear->UseVisualStyleBackColor = true;
			this->bClear->Click += gcnew System::EventHandler(this, &MainFrame::bClear_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(18, 702);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(563, 23);
			this->progressBar1->TabIndex = 26;
			// 
			// cbCSV
			// 
			this->cbCSV->AutoSize = true;
			this->cbCSV->Location = System::Drawing::Point(467, 44);
			this->cbCSV->Name = L"cbCSV";
			this->cbCSV->Size = System::Drawing::Size(114, 17);
			this->cbCSV->TabIndex = 27;
			this->cbCSV->Text = L"Write into CSV File";
			this->cbCSV->UseVisualStyleBackColor = true;
			this->cbCSV->CheckedChanged += gcnew System::EventHandler(this, &MainFrame::cbCSV_CheckedChanged);
			// 
			// MainFrame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(593, 730);
			this->Controls->Add(this->cbCSV);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->bClear);
			this->Controls->Add(this->tbRuns);
			this->Controls->Add(this->lRuns);
			this->Controls->Add(this->gpProbAlgorithm);
			this->Controls->Add(this->gpAlgorithm);
			this->Controls->Add(this->textBox1);
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
			this->gpAlgorithm->ResumeLayout(false);
			this->gpAlgorithm->PerformLayout();
			this->gpProbAlgorithm->ResumeLayout(false);
			this->gpProbAlgorithm->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		int algorithm = 0;
		int runs = 1;
		int numberants = 500;
		int iterationsmax = 300;
		int probabilityalgorithm = 0;
		int reduce = 0;
		double reducevalue = 0.001;
		double pheromonedeposit = 40;
		double pheromonereduction = 0.15;
		double alpha = 3.9;
		double beta = 1.0;
		int numbercities = 14;
		String^ filename;
		int csv = 0;
		int ovit = 20;



	private: System::Void bXMLFileDialog_Click(System::Object^  sender, System::EventArgs^  e) {

		ofdxml->FileName = "";
		ofdxml->DefaultExt = L".xml";
		ofdxml->AddExtension;
		ofdxml->Filter = L"XML-Datei (*.xml) | *.xml";

		try {
			if (ofdxml->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				filename = ofdxml->FileName;
				filename = filename->Replace(L"\\", L"/");
				tbLoadXML->Text = filename;
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ungültiger Pfad!");
		}


	}
	private: System::Void rbIterative_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (rbIterative->Checked == true) {
			tbIteration->Enabled = true;
			tbOV->Enabled = false;
			algorithm = 0;
		}
		else if (rbParallel->Checked == true) {
			tbIteration->Enabled = false;
			tbOV->Enabled = false;
			algorithm = 1;
		}
		else if (rbOV->Checked == true) {
			tbIteration->Enabled = false;
			tbOV->Enabled = true;
			algorithm = 2;
		}
		
	}

private: System::Void cbReduction_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (cbReduction->Checked == true) {
		tbReduction->Enabled = true;
		reduce = 1;
	}
	else if (cbReduction->Checked == false) {
		tbReduction->Enabled = false;
		reduce = 0;
	}
}


private: System::Void bOpenXML_Click(System::Object^  sender, System::EventArgs^  e) {

	try {
		String^ strNumberAnts = tbNumberAnts->Text;
		String^ strIterations = tbIteration->Text;
		String^ strReductionValue = tbReduction->Text;
		String^ strPheromoneDeposit = tbPheromoneDeposit->Text;
		String^ strPheromoneReduction = tbPheromoneReduction->Text;
		String^ strAlpha = tbAlpha->Text;
		String^ strBeta = tbBeta->Text;
		String^ strReduce = reduce.ToString();
		String^ strAlgorithm = algorithm.ToString();
		String^ strProbabilityAlgorithm = probabilityalgorithm.ToString();
		String^ strNumberCities = numbercities.ToString();
		String^ strRuns = tbRuns->Text;
		String^ strOV = tbOV->Text;


		strReductionValue = strReductionValue->Replace(",", ".");
		strPheromoneDeposit = strPheromoneDeposit->Replace(",", ".");
		strPheromoneReduction = strPheromoneReduction->Replace(",", ".");
		strAlpha = strAlpha->Replace(",", ".");
		strBeta = strBeta->Replace(",", ".");
		runs = Convert::ToInt32(strRuns);
		
		/*for (double j = 1; j < 80; j += 0.5) {

			textBox1->Text += "PheromoneReduction = " + j.ToString() + "\r\n";*/

		String^ parameters = tbLoadXML->Text + " " + tbNumberAnts->Text + " " + tbIteration->Text + " " + strReductionValue + " " + strPheromoneDeposit + " " + strPheromoneReduction + " " + strAlpha + " " + strBeta + " " + reduce.ToString() + " " + algorithm.ToString() + " " + probabilityalgorithm.ToString() + " " + csv.ToString() + " " + tbOV->Text;

			std::ofstream file;
			file.open("Data.csv");
			if (csv == 1) {
				if (algorithm == 0)
					file << "Algorithm:;Iterativ" << endl;
				else if (algorithm == 1)
					file << "Algorithm:;Parallel" << endl;
				else
					file << "Algorithm:;MMAS-Adaption" << endl;
				file << "Number of Ants:;" << msclr::interop::marshal_as<std::string>(strNumberAnts) << endl;
				if (algorithm == 0)
					file << "Iterations:;" << msclr::interop::marshal_as<std::string>(strIterations) << endl;
				else if (algorithm == 1)
					;
				else
					file << "Iterations:;" << msclr::interop::marshal_as<std::string>(strOV) << endl;
				if (reduce == 1)
					file << "Overall Reductionvalue:;" << msclr::interop::marshal_as<std::string>(strReductionValue) << endl;
				file << "Pheromonedeposit:;" << msclr::interop::marshal_as<std::string>(strPheromoneDeposit) << endl;
				file << "Pheromonereduction:;" << msclr::interop::marshal_as<std::string>(strPheromoneReduction) << endl;
				file << "Alpha:;" << msclr::interop::marshal_as<std::string>(strAlpha) << endl;
				file << "Beta:;" << msclr::interop::marshal_as<std::string>(strBeta) << endl;
				if (probabilityalgorithm == 0)
					file << "ProbabilityAlgorithm:;Simple" << endl;
				else
					file << "ProbabilityAlgorithm:;Komplex" << endl << endl;
				file << "Runs:;" << msclr::interop::marshal_as<std::string>(strRuns) << endl;
			}

			for (int i = 1; i <= runs; i++) {
				ProcessStartInfo^ startInfo = gcnew ProcessStartInfo();
				startInfo->FileName = "TSPACO.exe";
				startInfo->Arguments = parameters;
				startInfo->UseShellExecute = false;
				startInfo->CreateNoWindow = true;
				startInfo->RedirectStandardOutput = true;

				Process^ process = gcnew Process();
				process->StartInfo = startInfo;
				process->Start();

				StreamReader^ reader = process->StandardOutput;
				String^ output = reader->ReadToEnd();

				textBox1->Text += output;
				if (csv == 1) {					
					file << msclr::interop::marshal_as<std::string>(output) << endl;
				}

				process->WaitForExit();
				process->Close();
				textBox1->Text += "\r\n";
				progressBar1->Value += 100 / runs;
			}
			file.close();
			progressBar1->Value = 0;

			
		//}
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}	

}
private: System::Void rbProbSimple_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (rbProbSimple->Checked == true)
		probabilityalgorithm = 0;
	else if (rbProbSimple->Checked == false)
		probabilityalgorithm = 1;
}
private: System::Void tbNumberAnts_Leave(System::Object^  sender, System::EventArgs^  e) {
	int na;
	
	try {
		na = Convert::ToInt32(tbNumberAnts->Text);
		if (na <= 0 || na > 20000) {
			bOpenXML->Enabled = false;
			MessageBox::Show("Ant-Number has to be between 1 and 20000");
			this->tbNumberAnts->BackColor = System::Drawing::Color::Salmon;
			
		}
		else {
			bOpenXML->Enabled = true;
			this->tbNumberAnts->BackColor = System::Drawing::SystemColors::Window;
		}
		
	}
	catch (Exception^ ex) {
		bOpenXML->Enabled = false;
		MessageBox::Show("Invalid Input!");
		this->tbNumberAnts->BackColor = System::Drawing::Color::Salmon;
	}
}
private: System::Void tbIteration_Leave(System::Object^  sender, System::EventArgs^  e) {
	double na;

	try {
		na = Convert::ToDouble(tbIteration->Text);
		if (na <= 0 || na > 20000) {
			bOpenXML->Enabled = false;
			MessageBox::Show("Iteration-Value has to be between 1 and 20000");
			this->tbIteration->BackColor = System::Drawing::Color::Salmon;

		}
		else {
			bOpenXML->Enabled = true;
			this->tbIteration->BackColor = System::Drawing::SystemColors::Window;
		}

	}
	catch (Exception^ ex) {
		bOpenXML->Enabled = false;
		MessageBox::Show("Invalid Input!");
		this->tbIteration->BackColor = System::Drawing::Color::Salmon;
	}
}
private: System::Void tbAlpha_Leave(System::Object^  sender, System::EventArgs^  e) {
	double na;

	try {
		na = Convert::ToDouble(tbAlpha->Text);
		if (na <= 0 || na > 50) {
			bOpenXML->Enabled = false;
			MessageBox::Show("Alpha has to be between 0 and 50");
			this->tbAlpha->BackColor = System::Drawing::Color::Salmon;

		}
		else {
			bOpenXML->Enabled = true;
			this->tbAlpha->BackColor = System::Drawing::SystemColors::Window;
		}

	}
	catch (Exception^ ex) {
		bOpenXML->Enabled = false;
		MessageBox::Show("Invalid Input!");
		this->tbAlpha->BackColor = System::Drawing::Color::Salmon;
	}
}
private: System::Void tbBeta_Leave(System::Object^  sender, System::EventArgs^  e) {
	double na;

	try {
		na = Convert::ToDouble(tbBeta->Text);
		if (na <= 0 || na > 50) {
			bOpenXML->Enabled = false;
			MessageBox::Show("Beta has to be between 0 and 50");
			this->tbBeta->BackColor = System::Drawing::Color::Salmon;

		}
		else {
			bOpenXML->Enabled = true;
			this->tbBeta->BackColor = System::Drawing::SystemColors::Window;
		}

	}
	catch (Exception^ ex) {
		bOpenXML->Enabled = false;
		MessageBox::Show("Invalid Input!");
		this->tbBeta->BackColor = System::Drawing::Color::Salmon;
	}
}
private: System::Void tbPheromoneDeposit_Leave(System::Object^  sender, System::EventArgs^  e) {
	double na;

	try {
		na = Convert::ToDouble(tbPheromoneDeposit->Text);
		if (na <= 0 || na > 80) {
			bOpenXML->Enabled = false;
			MessageBox::Show("PheromoneDeposit has to be between 0 and 80");
			this->tbPheromoneDeposit->BackColor = System::Drawing::Color::Salmon;

		}
		else {
			bOpenXML->Enabled = true;
			this->tbPheromoneDeposit->BackColor = System::Drawing::SystemColors::Window;
		}

	}
	catch (Exception^ ex) {
		bOpenXML->Enabled = false;
		MessageBox::Show("Invalid Input!");
		this->tbPheromoneDeposit->BackColor = System::Drawing::Color::Salmon;
	}
}
private: System::Void tbPheromoneReduction_Leave(System::Object^  sender, System::EventArgs^  e) {
	double na;

	try {
		na = Convert::ToDouble(tbPheromoneReduction->Text);
		if (na <= 0 || na > 80) {
			bOpenXML->Enabled = false;
			MessageBox::Show("PheromoneReduction has to be between 0 and 80");
			this->tbPheromoneReduction->BackColor = System::Drawing::Color::Salmon;

		}
		else {
			bOpenXML->Enabled = true;
			this->tbPheromoneReduction->BackColor = System::Drawing::SystemColors::Window;
		}

	}
	catch (Exception^ ex) {
		bOpenXML->Enabled = false;
		MessageBox::Show("Invalid Input!");
		this->tbPheromoneReduction->BackColor = System::Drawing::Color::Salmon;
	}
}
private: System::Void tbReduction_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	double na;

	try {
		na = Convert::ToDouble(tbReduction->Text);
		if (na <= 0 || na > 1) {
			bOpenXML->Enabled = false;
			MessageBox::Show("Overall-Reduction has to be between 0 and 1");
			this->tbReduction->BackColor = System::Drawing::Color::Salmon;

		}
		else {
			bOpenXML->Enabled = true;
			this->tbReduction->BackColor = System::Drawing::SystemColors::Window;
		}

	}
	catch (Exception^ ex) {
		bOpenXML->Enabled = false;
		MessageBox::Show("Invalid Input!");
		this->tbReduction->BackColor = System::Drawing::Color::Salmon;
	}
}
private: System::Void tbLoadXML_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (tbLoadXML->Text == "" || tbLoadXML->Text == " ")
		bOpenXML->Enabled = false;
	else
		bOpenXML->Enabled = true;
}
private: System::Void tbRuns_Leave(System::Object^  sender, System::EventArgs^  e) {
	double na;

	try {
		na = Convert::ToInt32(tbRuns->Text);
		if (na <= 0 || na > 200) {
			bOpenXML->Enabled = false;
			MessageBox::Show("Run-Value has to be between 1 and 200");
			this->tbRuns->BackColor = System::Drawing::Color::Salmon;

		}
		else {
			bOpenXML->Enabled = true;
			this->tbRuns->BackColor = System::Drawing::SystemColors::Window;
		}

	}
	catch (Exception^ ex) {
		bOpenXML->Enabled = false;
		MessageBox::Show("Invalid Input!");
		this->tbRuns->BackColor = System::Drawing::Color::Salmon;
	}
}
private: System::Void bClear_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text = "";
}
private: System::Void cbCSV_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (cbCSV->Checked == true)
		csv = 1;
	else
		csv = 0;
}
private: System::Void tbOV_Leave(System::Object^  sender, System::EventArgs^  e) {
	int na;

	try {
		na = Convert::ToInt32(tbOV->Text);
		if (na <= 0 || na > 2000) {
			bOpenXML->Enabled = false;
			MessageBox::Show("Ant-Number has to be between 1 and 2000");
			this->tbOV->BackColor = System::Drawing::Color::Salmon;

		}
		else {
			bOpenXML->Enabled = true;
			this->tbOV->BackColor = System::Drawing::SystemColors::Window;
		}

	}
	catch (Exception^ ex) {
		bOpenXML->Enabled = false;
		MessageBox::Show("Invalid Input!");
		this->tbOV->BackColor = System::Drawing::Color::Salmon;
	}
}
};
}
