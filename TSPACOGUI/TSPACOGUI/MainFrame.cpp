#include "MainFrame.h"

using namespace System;
using namespace System::Windows::Forms;

// Main

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TSPACOGUI::MainFrame form;
	Application::Run(%form);
}

inline System::Void TSPACOGUI::MainFrame::bXMLFileDialog_Click(System::Object ^ sender, System::EventArgs ^ e) {

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

inline System::Void TSPACOGUI::MainFrame::rbIterative_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
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


inline System::Void TSPACOGUI::MainFrame::bOpenXML_Click(System::Object ^ sender, System::EventArgs ^ e) {

	try {
		String^ strNumberAnts = tbNumberAnts->Text;
		String^ strIterations = tbIteration->Text;
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


		String^ strReductionValue = "0.01";
		strPheromoneDeposit = strPheromoneDeposit->Replace(",", ".");
		strPheromoneReduction = strPheromoneReduction->Replace(",", ".");
		strAlpha = strAlpha->Replace(",", ".");
		strBeta = strBeta->Replace(",", ".");
		runs = Convert::ToInt32(strRuns);

			String^ parameters = tbLoadXML->Text + " " + tbNumberAnts->Text + " " + tbIteration->Text + " " + strReductionValue + " " + strPheromoneDeposit + " " + strPheromoneReduction + " " + strAlpha + " " + strBeta + " " + reduce.ToString() + " " + algorithm.ToString() + " " + probabilityalgorithm.ToString() + " " + csv.ToString() + " " + tbOV->Text;

		std::ofstream file;
		file.open("Data.csv", fstream::app);
		if (csv == 1) {
			String^ csvdeposit = strPheromoneDeposit->Replace(".", ",");
			String^ csvreduction = strPheromoneReduction->Replace(".", ",");
			String^ csvalpha = strAlpha->Replace(".", ",");
			String^ csvbeta = strBeta->Replace(".", ",");


			if (algorithm == 0)
				file << "Algorithm:;Iterativ" << endl;
			else if (algorithm == 1)
				file << "Algorithm:;Parallel" << endl;
			else
				file << "Algorithm:;Iterative with restricted Pheromoneupdate" << endl;
			file << "Number of Ants:;" << msclr::interop::marshal_as<std::string>(strNumberAnts) << endl;
			if (algorithm == 0)
				file << "Iterations:;" << msclr::interop::marshal_as<std::string>(strIterations) << endl;
			else if (algorithm == 1)
				;
			else
				file << "Iterations:;" << msclr::interop::marshal_as<std::string>(strOV) << endl;			
			file << "Pheromonedeposit:;" << msclr::interop::marshal_as<std::string>(csvdeposit) << endl;
			file << "Pheromonereduction:;" << msclr::interop::marshal_as<std::string>(csvreduction) << endl;
			file << "Alpha:;" << msclr::interop::marshal_as<std::string>(csvalpha) << endl;
			file << "Beta:;" << msclr::interop::marshal_as<std::string>(csvbeta) << endl;
			if (probabilityalgorithm == 0)
				file << "ProbabilityAlgorithm:;Simple" << endl;
			else
				file << "ProbabilityAlgorithm:;Komplex" << endl << endl;
			file << "Runs:;" << msclr::interop::marshal_as<std::string>(strRuns) << endl;
		}

		for (int i = 1; i <= runs; i++) {
			progressBar1->Value += 100 / runs;
			ProcessStartInfo^ startInfo = gcnew ProcessStartInfo();
			startInfo->FileName = "TSPACO.exe";
			startInfo->Arguments = parameters;
			startInfo->UseShellExecute = false;
			startInfo->CreateNoWindow = true;
			startInfo->RedirectStandardOutput = true;

			
			Process^ process = gcnew Process();
			process->StartInfo = startInfo;
			auto start = std::chrono::high_resolution_clock::now();
			process->Start();

			StreamReader^ reader = process->StandardOutput;
			String^ output = reader->ReadToEnd();

			if (csv == 0 && algorithm == 0) {
				textBox1->Text += "Iterative Algorithm";
				textBox1->Text += "\r\n";
			} else if (csv == 0 && algorithm == 1) {
				textBox1->Text += "Parallel Algorithm";
				textBox1->Text += "\r\n";
			} else if (csv == 0 && algorithm == 2) {
				textBox1->Text += "Iterative Algorithm with restricted Pheromonupdate";
				textBox1->Text += "\r\n";
			}
			textBox1->Text += output;
			if (csv == 1) {
				file << msclr::interop::marshal_as<std::string>(output) << endl;
			}

			process->WaitForExit();
			process->Close();
			auto finish = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed = finish - start;
			if(csv == 1 && algorithm != 2)
				textBox1->Text += ";";

			if(csv == 0)
				textBox1->Text += "Runtime in [s]: ";

			textBox1->Text += elapsed.count().ToString();
			textBox1->Text += "\r\n";
			
			if (csv == 1) {
				file << msclr::interop::marshal_as<std::string>(elapsed.count().ToString()) << endl;
			}
		}
		file.close();
		progressBar1->Value = 0;

		
		
		
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}

}

inline System::Void TSPACOGUI::MainFrame::rbProbSimple_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	if (rbProbSimple->Checked == true)
		probabilityalgorithm = 0;
	else if (rbProbSimple->Checked == false)
		probabilityalgorithm = 1;
}

inline System::Void TSPACOGUI::MainFrame::tbNumberAnts_Leave(System::Object ^ sender, System::EventArgs ^ e) {
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

inline System::Void TSPACOGUI::MainFrame::tbIteration_Leave(System::Object ^ sender, System::EventArgs ^ e) {
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

inline System::Void TSPACOGUI::MainFrame::tbAlpha_Leave(System::Object ^ sender, System::EventArgs ^ e) {
	double na;

	try {
		na = Convert::ToDouble(tbAlpha->Text);
		if (na <= 0 || na > 1) {
			bOpenXML->Enabled = false;
			MessageBox::Show("Alpha has to be between 0 and 1");
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

inline System::Void TSPACOGUI::MainFrame::tbBeta_Leave(System::Object ^ sender, System::EventArgs ^ e) {
	double na;

	try {
		na = Convert::ToDouble(tbBeta->Text);
		if (na <= 0 || na > 1) {
			bOpenXML->Enabled = false;
			MessageBox::Show("Beta has to be between 0 and 1");
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

inline System::Void TSPACOGUI::MainFrame::tbPheromoneDeposit_Leave(System::Object ^ sender, System::EventArgs ^ e) {
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

inline System::Void TSPACOGUI::MainFrame::tbPheromoneReduction_Leave(System::Object ^ sender, System::EventArgs ^ e) {
	double na;

	try {
		na = Convert::ToDouble(tbPheromoneReduction->Text);
		if (na <= 0 || na > 1) {
			bOpenXML->Enabled = false;
			MessageBox::Show("PheromoneReduction has to be between 0 and 1");
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


inline System::Void TSPACOGUI::MainFrame::tbLoadXML_TextChanged(System::Object ^ sender, System::EventArgs ^ e) {
	if (tbLoadXML->Text == "" || tbLoadXML->Text == " ")
		bOpenXML->Enabled = false;
	else
		bOpenXML->Enabled = true;
}

inline System::Void TSPACOGUI::MainFrame::tbRuns_Leave(System::Object ^ sender, System::EventArgs ^ e) {
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

inline System::Void TSPACOGUI::MainFrame::bClear_Click(System::Object ^ sender, System::EventArgs ^ e) {
	textBox1->Text = "";
}

inline System::Void TSPACOGUI::MainFrame::cbCSV_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	if (cbCSV->Checked == true)
		csv = 1;
	else
		csv = 0;
}

inline System::Void TSPACOGUI::MainFrame::tbOV_Leave(System::Object ^ sender, System::EventArgs ^ e) {
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

inline System::Void TSPACOGUI::MainFrame::rbParallel_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
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
