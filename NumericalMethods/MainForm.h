#pragma once
#include "LagrangesInterpolation.h"

namespace NumericalMethods 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private: int startX;
	private: int endX;
	private: int startY;
	private: int endY;
	private: Pen^ linePen;
	private: Pen^ cooldinatePen;
	private: SolidBrush^ pointBrush;
	private: SolidBrush^ numbersBrush;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ methodToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ lagrangesInterpolateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ finiteDifferenceInterpolationToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ newtonInterpolationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ interpolationMultipleNodesToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ graphToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveGraphToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^ checkBoxPoints;
	private: System::Windows::Forms::ToolStripMenuItem^ functionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fxX3ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fxX2ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fxLogxToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fxSqrtxToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fx2xToolStripMenuItem;
	private: System::Windows::Forms::Panel^ panel3;

	public: MainForm(void)
		{
			InitializeComponent();
			linePen = gcnew Pen(Color::FromArgb(255, 150, 50), 3.0f);
			cooldinatePen = gcnew Pen(Color::Black, 2.0f);
			pointBrush = gcnew SolidBrush(Color::BlueViolet);
			numbersBrush = gcnew SolidBrush(Color::Black);
			startX = -5;
			endX = 5;
			startY = -5;
			endY = 5;
			auto rowX = gcnew DataGridViewRow();
			rowX->HeaderCell->Value = "X";
			auto rowY = gcnew DataGridViewRow();
			rowY->HeaderCell->Value = "Y";
			auto newColumnt = gcnew DataGridViewTextBoxColumn();
			dataGridView->Columns->Add(newColumnt);
			dataGridView->Rows->Add(rowX);
			dataGridView->Rows->Add(rowY);
			addColumn(-2.0, -8.0);
			addColumn(-1.0, -1.0);
			addColumn(0.0, 0.0);
			addColumn(1.0, 1.0);
			addColumn(2.0, 8.0);
			dataGridView->Columns->RemoveAt(0);
			dataGridView_ColumnRemoved(this, nullptr);
			dataGridView->ColumnRemoved += gcnew DataGridViewColumnEventHandler(this, &MainForm::dataGridView_ColumnRemoved);
			dataGridView->ColumnAdded += gcnew DataGridViewColumnEventHandler(this, &MainForm::dataGridView_ColumnRemoved);
		}

	private: void dataGridView_ColumnRemoved(Object^ sender, DataGridViewColumnEventArgs^ e)
		  {
			  for (int i = 0; i < dataGridView->ColumnCount; i++)
				  dataGridView->Columns[i]->HeaderText = (i + 1).ToString();
		  }

	protected: ~MainForm()
		{
			if (components)
				delete components;
		}

	private: System::Windows::Forms::DataGridView^ dataGridView;
	private: System::Windows::Forms::Button^ buttonAddPoint;
	private: System::Windows::Forms::Button^ buttonRemovePoint;
	private: System::Windows::Forms::Panel^ panelGraph;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownStartY;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownStartX;
	private: System::Windows::Forms::CheckBox^ checkBoxAutoScale;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownEndY;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownEndX;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::CheckBox^ checkBoxCells;
	private: System::Windows::Forms::CheckBox^ checkBoxNumbers;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->panelGraph = (gcnew System::Windows::Forms::Panel());
			this->buttonAddPoint = (gcnew System::Windows::Forms::Button());
			this->buttonRemovePoint = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->checkBoxPoints = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxNumbers = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxCells = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownEndY = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownEndX = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownStartY = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownStartX = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBoxAutoScale = (gcnew System::Windows::Forms::CheckBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->methodToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lagrangesInterpolateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->finiteDifferenceInterpolationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newtonInterpolationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->interpolationMultipleNodesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->graphToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveGraphToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->functionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fx2xToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fxX2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fxX3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fxSqrtxToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fxLogxToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownEndY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownEndX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownStartY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownStartX))->BeginInit();
			this->panel2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->AllowUserToResizeRows = false;
			this->dataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::SeaShell;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView->Location = System::Drawing::Point(-1, 32);
			this->dataGridView->MultiSelect = false;
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView->Size = System::Drawing::Size(617, 83);
			this->dataGridView->TabIndex = 0;
			this->dataGridView->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView_CellEndEdit);
			// 
			// panelGraph
			// 
			this->panelGraph->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelGraph->BackColor = System::Drawing::Color::White;
			this->panelGraph->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelGraph->Location = System::Drawing::Point(8, 153);
			this->panelGraph->Name = L"panelGraph";
			this->panelGraph->Size = System::Drawing::Size(617, 416);
			this->panelGraph->TabIndex = 1;
			this->panelGraph->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panelGraph_Paint);
			this->panelGraph->Resize += gcnew System::EventHandler(this, &MainForm::panelGraph_Resize);
			// 
			// buttonAddPoint
			// 
			this->buttonAddPoint->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAddPoint->Location = System::Drawing::Point(581, 3);
			this->buttonAddPoint->Name = L"buttonAddPoint";
			this->buttonAddPoint->Size = System::Drawing::Size(29, 24);
			this->buttonAddPoint->TabIndex = 2;
			this->buttonAddPoint->Text = L"+";
			this->buttonAddPoint->UseVisualStyleBackColor = true;
			this->buttonAddPoint->Click += gcnew System::EventHandler(this, &MainForm::buttonAddPoint_Click);
			// 
			// buttonRemovePoint
			// 
			this->buttonRemovePoint->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonRemovePoint->Location = System::Drawing::Point(550, 3);
			this->buttonRemovePoint->Name = L"buttonRemovePoint";
			this->buttonRemovePoint->Size = System::Drawing::Size(29, 24);
			this->buttonRemovePoint->TabIndex = 3;
			this->buttonRemovePoint->Text = L"-";
			this->buttonRemovePoint->UseVisualStyleBackColor = true;
			this->buttonRemovePoint->Click += gcnew System::EventHandler(this, &MainForm::buttonRemovePoint_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->checkBoxPoints);
			this->panel1->Controls->Add(this->checkBoxNumbers);
			this->panel1->Controls->Add(this->checkBoxCells);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->numericUpDownEndY);
			this->panel1->Controls->Add(this->numericUpDownEndX);
			this->panel1->Controls->Add(this->numericUpDownStartY);
			this->panel1->Controls->Add(this->numericUpDownStartX);
			this->panel1->Controls->Add(this->checkBoxAutoScale);
			this->panel1->Location = System::Drawing::Point(8, 575);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(617, 77);
			this->panel1->TabIndex = 4;
			// 
			// checkBoxPoints
			// 
			this->checkBoxPoints->AutoSize = true;
			this->checkBoxPoints->Checked = true;
			this->checkBoxPoints->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxPoints->Location = System::Drawing::Point(192, 15);
			this->checkBoxPoints->Name = L"checkBoxPoints";
			this->checkBoxPoints->Size = System::Drawing::Size(59, 19);
			this->checkBoxPoints->TabIndex = 11;
			this->checkBoxPoints->Text = L"Точки";
			this->checkBoxPoints->UseVisualStyleBackColor = true;
			this->checkBoxPoints->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBoxPoints_CheckedChanged);
			// 
			// checkBoxNumbers
			// 
			this->checkBoxNumbers->AutoSize = true;
			this->checkBoxNumbers->Checked = true;
			this->checkBoxNumbers->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxNumbers->Location = System::Drawing::Point(158, 42);
			this->checkBoxNumbers->Name = L"checkBoxNumbers";
			this->checkBoxNumbers->Size = System::Drawing::Size(95, 19);
			this->checkBoxNumbers->TabIndex = 10;
			this->checkBoxNumbers->Text = L"Координаты";
			this->checkBoxNumbers->UseVisualStyleBackColor = true;
			this->checkBoxNumbers->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBoxNumbers_CheckedChanged);
			// 
			// checkBoxCells
			// 
			this->checkBoxCells->AutoSize = true;
			this->checkBoxCells->Checked = true;
			this->checkBoxCells->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxCells->Location = System::Drawing::Point(15, 42);
			this->checkBoxCells->Name = L"checkBoxCells";
			this->checkBoxCells->Size = System::Drawing::Size(137, 19);
			this->checkBoxCells->TabIndex = 9;
			this->checkBoxCells->Text = L"Координатная сетка";
			this->checkBoxCells->UseVisualStyleBackColor = true;
			this->checkBoxCells->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBoxCells_CheckedChanged);
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(454, 43);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(54, 15);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Конец Y:";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(454, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 15);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Конец X:";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(284, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 15);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Начало Y:";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(284, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 15);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Начало X:";
			// 
			// numericUpDownEndY
			// 
			this->numericUpDownEndY->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDownEndY->Location = System::Drawing::Point(520, 40);
			this->numericUpDownEndY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDownEndY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->numericUpDownEndY->Name = L"numericUpDownEndY";
			this->numericUpDownEndY->Size = System::Drawing::Size(82, 23);
			this->numericUpDownEndY->TabIndex = 4;
			this->numericUpDownEndY->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownEndY->ValueChanged += gcnew System::EventHandler(this, &MainForm::numericUpDowns_ValueChanged);
			// 
			// numericUpDownEndX
			// 
			this->numericUpDownEndX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDownEndX->Location = System::Drawing::Point(520, 10);
			this->numericUpDownEndX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDownEndX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->numericUpDownEndX->Name = L"numericUpDownEndX";
			this->numericUpDownEndX->Size = System::Drawing::Size(82, 23);
			this->numericUpDownEndX->TabIndex = 3;
			this->numericUpDownEndX->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownEndX->ValueChanged += gcnew System::EventHandler(this, &MainForm::numericUpDowns_ValueChanged);
			// 
			// numericUpDownStartY
			// 
			this->numericUpDownStartY->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDownStartY->Location = System::Drawing::Point(358, 40);
			this->numericUpDownStartY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDownStartY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->numericUpDownStartY->Name = L"numericUpDownStartY";
			this->numericUpDownStartY->Size = System::Drawing::Size(82, 23);
			this->numericUpDownStartY->TabIndex = 2;
			this->numericUpDownStartY->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, System::Int32::MinValue });
			this->numericUpDownStartY->ValueChanged += gcnew System::EventHandler(this, &MainForm::numericUpDowns_ValueChanged);
			// 
			// numericUpDownStartX
			// 
			this->numericUpDownStartX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDownStartX->Location = System::Drawing::Point(358, 10);
			this->numericUpDownStartX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDownStartX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->numericUpDownStartX->Name = L"numericUpDownStartX";
			this->numericUpDownStartX->Size = System::Drawing::Size(82, 23);
			this->numericUpDownStartX->TabIndex = 1;
			this->numericUpDownStartX->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, System::Int32::MinValue });
			this->numericUpDownStartX->ValueChanged += gcnew System::EventHandler(this, &MainForm::numericUpDowns_ValueChanged);
			// 
			// checkBoxAutoScale
			// 
			this->checkBoxAutoScale->AutoSize = true;
			this->checkBoxAutoScale->Checked = true;
			this->checkBoxAutoScale->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxAutoScale->Location = System::Drawing::Point(15, 15);
			this->checkBoxAutoScale->Name = L"checkBoxAutoScale";
			this->checkBoxAutoScale->Size = System::Drawing::Size(171, 19);
			this->checkBoxAutoScale->TabIndex = 0;
			this->checkBoxAutoScale->Text = L"Автоматический масштаб";
			this->checkBoxAutoScale->UseVisualStyleBackColor = true;
			this->checkBoxAutoScale->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBoxAutoScale_CheckedChanged);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->dataGridView);
			this->panel2->Controls->Add(this->buttonAddPoint);
			this->panel2->Controls->Add(this->buttonRemovePoint);
			this->panel2->Location = System::Drawing::Point(8, 31);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(617, 116);
			this->panel2->TabIndex = 5;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(463, 8);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(76, 15);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Количество:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 8);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 15);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Точки:";
			// 
			// menuStrip1
			// 
			this->menuStrip1->AutoSize = false;
			this->menuStrip1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3)
			{
				this->methodToolStripMenuItem,
					this->graphToolStripMenuItem, this->functionsToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(0, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(615, 24);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// methodToolStripMenuItem
			// 
			this->methodToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4)
			{
				this->lagrangesInterpolateToolStripMenuItem,
					this->finiteDifferenceInterpolationToolStripMenuItem, this->newtonInterpolationToolStripMenuItem, this->interpolationMultipleNodesToolStripMenuItem
			});
			this->methodToolStripMenuItem->Name = L"methodToolStripMenuItem";
			this->methodToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->methodToolStripMenuItem->Text = L"Метод";
			// 
			// lagrangesInterpolateToolStripMenuItem
			// 
			this->lagrangesInterpolateToolStripMenuItem->Checked = true;
			this->lagrangesInterpolateToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->lagrangesInterpolateToolStripMenuItem->Name = L"lagrangesInterpolateToolStripMenuItem";
			this->lagrangesInterpolateToolStripMenuItem->Size = System::Drawing::Size(460, 22);
			this->lagrangesInterpolateToolStripMenuItem->Text = L"Интерполяционный многочлен лагранжа";
			this->lagrangesInterpolateToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::lagrangesInterpolateToolStripMenuItem_Click);
			// 
			// finiteDifferenceInterpolationToolStripMenuItem
			// 
			this->finiteDifferenceInterpolationToolStripMenuItem->Name = L"finiteDifferenceInterpolationToolStripMenuItem";
			this->finiteDifferenceInterpolationToolStripMenuItem->Size = System::Drawing::Size(460, 22);
			this->finiteDifferenceInterpolationToolStripMenuItem->Text = L"Конечноразностные интерполяционные формулы";
			this->finiteDifferenceInterpolationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::finiteDifferenceInterpolationToolStripMenuItem_Click);
			// 
			// newtonInterpolationToolStripMenuItem
			// 
			this->newtonInterpolationToolStripMenuItem->Name = L"newtonInterpolationToolStripMenuItem";
			this->newtonInterpolationToolStripMenuItem->Size = System::Drawing::Size(460, 22);
			this->newtonInterpolationToolStripMenuItem->Text = L"Интерполяционные формулы Ньютона для неравноотстоящих узлов";
			this->newtonInterpolationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::newtonInterpolationToolStripMenuItem_Click);
			// 
			// interpolationMultipleNodesToolStripMenuItem
			// 
			this->interpolationMultipleNodesToolStripMenuItem->Name = L"interpolationMultipleNodesToolStripMenuItem";
			this->interpolationMultipleNodesToolStripMenuItem->Size = System::Drawing::Size(460, 22);
			this->interpolationMultipleNodesToolStripMenuItem->Text = L"Интерполяция с кратными узлами";
			this->interpolationMultipleNodesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::interpolationMultipleNodesToolStripMenuItem_Click);
			// 
			// graphToolStripMenuItem
			// 
			this->graphToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->saveGraphToolStripMenuItem });
			this->graphToolStripMenuItem->Name = L"graphToolStripMenuItem";
			this->graphToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->graphToolStripMenuItem->Text = L"График";
			// 
			// saveGraphToolStripMenuItem
			// 
			this->saveGraphToolStripMenuItem->Name = L"saveGraphToolStripMenuItem";
			this->saveGraphToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->saveGraphToolStripMenuItem->Text = L"Сохранить";
			this->saveGraphToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveGraphToolStripMenuItem_Click);
			// 
			// functionsToolStripMenuItem
			// 
			this->functionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5)
			{
				this->fx2xToolStripMenuItem,
					this->fxX2ToolStripMenuItem, this->fxX3ToolStripMenuItem, this->fxSqrtxToolStripMenuItem, this->fxLogxToolStripMenuItem
			});
			this->functionsToolStripMenuItem->Name = L"functionsToolStripMenuItem";
			this->functionsToolStripMenuItem->Size = System::Drawing::Size(68, 20);
			this->functionsToolStripMenuItem->Text = L"Функции";
			// 
			// fx2xToolStripMenuItem
			// 
			this->fx2xToolStripMenuItem->Name = L"fx2xToolStripMenuItem";
			this->fx2xToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->fx2xToolStripMenuItem->Text = L"f(x) = 2x";
			this->fx2xToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::fx2xToolStripMenuItem_Click);
			// 
			// fxX2ToolStripMenuItem
			// 
			this->fxX2ToolStripMenuItem->Name = L"fxX2ToolStripMenuItem";
			this->fxX2ToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->fxX2ToolStripMenuItem->Text = L"f(x) = x^2";
			this->fxX2ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::fxX2ToolStripMenuItem_Click);
			// 
			// fxX3ToolStripMenuItem
			// 
			this->fxX3ToolStripMenuItem->Name = L"fxX3ToolStripMenuItem";
			this->fxX3ToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->fxX3ToolStripMenuItem->Text = L"f(x) = x^3";
			this->fxX3ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::fxX3ToolStripMenuItem_Click);
			// 
			// fxSqrtxToolStripMenuItem
			// 
			this->fxSqrtxToolStripMenuItem->Name = L"fxSqrtxToolStripMenuItem";
			this->fxSqrtxToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->fxSqrtxToolStripMenuItem->Text = L"f(x) = sqrt(x)";
			this->fxSqrtxToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::fxSqrtxToolStripMenuItem_Click);
			// 
			// fxLogxToolStripMenuItem
			// 
			this->fxLogxToolStripMenuItem->Name = L"fxLogxToolStripMenuItem";
			this->fxLogxToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->fxLogxToolStripMenuItem->Text = L"f(x) = log(x)";
			this->fxLogxToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::fxLogxToolStripMenuItem_Click);
			// 
			// panel3
			// 
			this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel3->BackColor = System::Drawing::Color::SeaShell;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->menuStrip1);
			this->panel3->Location = System::Drawing::Point(8, -1);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(617, 26);
			this->panel3->TabIndex = 7;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Linen;
			this->ClientSize = System::Drawing::Size(634, 663);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panelGraph);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(650, 693);
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Численные методы";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownEndY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownEndX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownStartY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownStartX))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
	#pragma endregion

		private: int getPointsNumber();
		private: point getPoint(int n);
		private: void addColumn(double x, double y);
		private: Void render(Graphics^ graphics);
		private: System::Void panelGraph_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
		private: System::Void panelGraph_Resize(System::Object^ sender, System::EventArgs^ e);
		private: System::Void dataGridView_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		private: System::Void buttonAddPoint_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void buttonRemovePoint_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void numericUpDowns_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void checkBoxAutoScale_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void checkBoxCells_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void checkBoxNumbers_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void lagrangesInterpolateToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void newtonInterpolationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void saveGraphToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void checkBoxPoints_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void finiteDifferenceInterpolationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void interpolationMultipleNodesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void fxX3ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void fxX2ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void fxLogxToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void fx2xToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void fxSqrtxToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
