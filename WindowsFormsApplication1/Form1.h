#pragma once
#include<string>

#include"syntax.h"
#include<Windows.h>
namespace WindowsFormsApplication1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Runtime::InteropServices;
	using namespace System::IO;
	using namespace::System::Text;

	/// <summary>
	/// Form1 ժҪ
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  �ļ�ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Դ�ļ�ToolStripMenuItem;





	private: System::Windows::Forms::ToolStripMenuItem^  �ʷ�����ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  �﷨�������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �Ż�ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Ŀ���������ToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;

	private: System::Windows::Forms::ToolStripMenuItem^  �����ļ�ToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::ToolStripMenuItem^  �˳�ToolStripMenuItem;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
	private: System::Windows::Forms::RichTextBox^  richTextBox4;
	private: System::Windows::Forms::RichTextBox^  richTextBox5;
	private: System::Windows::Forms::RichTextBox^  richTextBox6;
	private: System::Windows::Forms::ToolStripMenuItem^  ��ϵ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;


	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�ļ�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Դ�ļ�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ļ�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�˳�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�ʷ�����ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�﷨�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�Ż�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Ŀ���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��ϵ����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox5 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox6 = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->�ļ�ToolStripMenuItem,
					this->����ToolStripMenuItem, this->����ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1093, 25);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �ļ�ToolStripMenuItem
			// 
			this->�ļ�ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->Դ�ļ�ToolStripMenuItem,
					this->�����ļ�ToolStripMenuItem, this->�˳�ToolStripMenuItem
			});
			this->�ļ�ToolStripMenuItem->Name = L"�ļ�ToolStripMenuItem";
			this->�ļ�ToolStripMenuItem->Size = System::Drawing::Size(44, 21);
			this->�ļ�ToolStripMenuItem->Text = L"�ļ�";
			// 
			// Դ�ļ�ToolStripMenuItem
			// 
			this->Դ�ļ�ToolStripMenuItem->Name = L"Դ�ļ�ToolStripMenuItem";
			this->Դ�ļ�ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->Դ�ļ�ToolStripMenuItem->Text = L"Դ�ļ�";
			this->Դ�ļ�ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Դ�ļ�ToolStripMenuItem_Click);
			// 
			// �����ļ�ToolStripMenuItem
			// 
			this->�����ļ�ToolStripMenuItem->Name = L"�����ļ�ToolStripMenuItem";
			this->�����ļ�ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->�����ļ�ToolStripMenuItem->Text = L"�����ļ�";
			this->�����ļ�ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�����ļ�ToolStripMenuItem_Click);
			// 
			// �˳�ToolStripMenuItem
			// 
			this->�˳�ToolStripMenuItem->Name = L"�˳�ToolStripMenuItem";
			this->�˳�ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->�˳�ToolStripMenuItem->Text = L"�˳�";
			this->�˳�ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�˳�ToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->�ʷ�����ToolStripMenuItem1,
					this->�﷨�������ToolStripMenuItem, this->�Ż�ToolStripMenuItem, this->Ŀ���������ToolStripMenuItem, this->����ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(44, 21);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �ʷ�����ToolStripMenuItem1
			// 
			this->�ʷ�����ToolStripMenuItem1->Name = L"�ʷ�����ToolStripMenuItem1";
			this->�ʷ�����ToolStripMenuItem1->Size = System::Drawing::Size(153, 22);
			this->�ʷ�����ToolStripMenuItem1->Text = L"�ʷ�����";
			this->�ʷ�����ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::�ʷ�����ToolStripMenuItem1_Click);
			// 
			// �﷨�������ToolStripMenuItem
			// 
			this->�﷨�������ToolStripMenuItem->Name = L"�﷨�������ToolStripMenuItem";
			this->�﷨�������ToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->�﷨�������ToolStripMenuItem->Text = L"�﷨/�������";
			this->�﷨�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�﷨�������ToolStripMenuItem_Click);
			// 
			// �Ż�ToolStripMenuItem
			// 
			this->�Ż�ToolStripMenuItem->Enabled = false;
			this->�Ż�ToolStripMenuItem->Name = L"�Ż�ToolStripMenuItem";
			this->�Ż�ToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->�Ż�ToolStripMenuItem->Text = L"�Ż�";
			this->�Ż�ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�Ż�ToolStripMenuItem_Click);
			// 
			// Ŀ���������ToolStripMenuItem
			// 
			this->Ŀ���������ToolStripMenuItem->Enabled = false;
			this->Ŀ���������ToolStripMenuItem->Name = L"Ŀ���������ToolStripMenuItem";
			this->Ŀ���������ToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->Ŀ���������ToolStripMenuItem->Text = L"Ŀ���������";
			this->Ŀ���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Ŀ���������ToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Enabled = false;
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::����ToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->��ϵ����ToolStripMenuItem,
					this->����ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(44, 21);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// ��ϵ����ToolStripMenuItem
			// 
			this->��ϵ����ToolStripMenuItem->Name = L"��ϵ����ToolStripMenuItem";
			this->��ϵ����ToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->��ϵ����ToolStripMenuItem->Text = L"��ϵ����";
			this->��ϵ����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::��ϵ����ToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::����ToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->richTextBox1->Location = System::Drawing::Point(25, 459);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(768, 132);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->TabStop = false;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->AcceptsTab = true;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->richTextBox2->Location = System::Drawing::Point(27, 53);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(766, 359);
			this->richTextBox2->TabIndex = 2;
			this->richTextBox2->Text = L"";
			this->richTextBox2->Click += gcnew System::EventHandler(this, &Form1::richTextBox2_Click);
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox2_TextChanged_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(819, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 12);
			this->label1->TabIndex = 4;
			this->label1->Text = L"token����";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 441);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 12);
			this->label2->TabIndex = 5;
			this->label2->Text = L"���";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(821, 53);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowTemplate->Height = 23;
			this->dataGridView1->Size = System::Drawing::Size(256, 511);
			this->dataGridView1->TabIndex = 6;
			this->dataGridView1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(27, 29);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Դ����";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(99, 29);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"���ű�";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(171, 29);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 9;
			this->button3->Text = L"�м����";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(242, 29);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 10;
			this->button4->Text = L"�Ż�";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(314, 29);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 11;
			this->button5->Text = L"Ŀ�����";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(821, 571);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 12);
			this->label3->TabIndex = 12;
			// 
			// richTextBox3
			// 
			this->richTextBox3->AcceptsTab = true;
			this->richTextBox3->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->richTextBox3->Location = System::Drawing::Point(25, 53);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->ReadOnly = true;
			this->richTextBox3->Size = System::Drawing::Size(766, 359);
			this->richTextBox3->TabIndex = 13;
			this->richTextBox3->Text = L"";
			this->richTextBox3->Visible = false;
			// 
			// richTextBox4
			// 
			this->richTextBox4->AcceptsTab = true;
			this->richTextBox4->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->richTextBox4->Location = System::Drawing::Point(27, 53);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->ReadOnly = true;
			this->richTextBox4->Size = System::Drawing::Size(766, 359);
			this->richTextBox4->TabIndex = 14;
			this->richTextBox4->Text = L"";
			this->richTextBox4->Visible = false;
			this->richTextBox4->Click += gcnew System::EventHandler(this, &Form1::richTextBox4_Click);
			// 
			// richTextBox5
			// 
			this->richTextBox5->AcceptsTab = true;
			this->richTextBox5->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->richTextBox5->Location = System::Drawing::Point(25, 53);
			this->richTextBox5->Name = L"richTextBox5";
			this->richTextBox5->ReadOnly = true;
			this->richTextBox5->Size = System::Drawing::Size(766, 359);
			this->richTextBox5->TabIndex = 15;
			this->richTextBox5->Text = L"";
			this->richTextBox5->Visible = false;
			this->richTextBox5->Click += gcnew System::EventHandler(this, &Form1::richTextBox5_Click);
			// 
			// richTextBox6
			// 
			this->richTextBox6->AcceptsTab = true;
			this->richTextBox6->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->richTextBox6->Location = System::Drawing::Point(27, 53);
			this->richTextBox6->Name = L"richTextBox6";
			this->richTextBox6->ReadOnly = true;
			this->richTextBox6->Size = System::Drawing::Size(766, 359);
			this->richTextBox6->TabIndex = 16;
			this->richTextBox6->Text = L"";
			this->richTextBox6->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1093, 603);
			this->Controls->Add(this->richTextBox6);
			this->Controls->Add(this->richTextBox5);
			this->Controls->Add(this->richTextBox4);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"TinyCLangCompilier";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	public:void MarshalString(String ^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
	private:void clearToken(){
		dataGridView1->Rows->Clear();
	}
	private:void showToken(){        //�ʷ��������
		clearToken();
		
		dataGridView1->AllowUserToOrderColumns = false;
		
		String ^tokenText = "";
		if (token[0].token_name == ""){ MessageBox::Show("it is empty"); }

		dataGridView1->ColumnCount = 3;
		dataGridView1->Columns[0]->Name = "tokenԴ��";
		dataGridView1->Columns[1]->Name = "������";
		dataGridView1->Columns[2]->Name = "����";
		dataGridView1->Columns[0]->AutoSizeMode;
		for (auto t : token){
			if (t.token_name != ""){
				String ^tokenName = gcnew String(t.token_name.c_str());
				String ^tokenNumber = gcnew String(t.token_number.ToString());
				String ^tokenLine = gcnew String(t.line.ToString());

				array<String^>^row = gcnew array<String^>{
					tokenName, tokenNumber, tokenLine
				};
				dataGridView1->Rows->Add(row);
			}
		}
		for (int i = 0; i < 200; i++){
			//token[i].token_name = "";
		}
	}

	public:int showSyntaxResult(){				//�﷨����������
		String ^resultText;
		int syntaxResult = syntax();
		//MessageBox::Show(syntaxResult.ToString());
		switch (syntaxResult)
		{
		case 1:resultText = "compiler success"; break;
		case 1000: resultText = "error1000:line " + line.ToString() + " ͷ�ļ���ʽ����"; break;
		case 1001: resultText = "error1001:line " + line.ToString() + " main ��Ҫ����"; break;
		case 1002: resultText = "error1002:line " + line.ToString() + " need 'main'"; break;
		case 1003: resultText = "error1003:line " + line.ToString() + " need '('"; break;
		case 1004: resultText = "error1004:line " + line.ToString() + " need ')'"; break;
		case 1005: resultText = "error1005:line " + line.ToString() + " need '{'"; break;
		case 1006: resultText = "error1006:line " + line.ToString() + " need '}'"; break;
		case 1007: resultText = "error1007:line " + line.ToString() + " need operator"; break;
		case 1008: resultText = "error1008:line " + line.ToString() + " �������ʽ����1"; break;
		case 1009: resultText = "error1009:line " + line.ToString() + " �������ʽ����2"; break;
		case 1010: resultText = "error1010:line " + line.ToString() + " ��ֵ���ʹ���"; break;
		case 1011: resultText = "error1011:line " + line.ToString() + " ��ֵ���ʹ���"; break;
		case 1012: resultText = "error1012:line " + line.ToString() + " need '='"; break;
		case 1013: resultText = "error1013:line " + line.ToString() + " need ';'"; break;
		case 1200: resultText = "error1200:line " + line.ToString() + " ���ʽ��ֵ����"; break;
		case 1100: resultText = "error1100:line " + line.ToString() + " δʶ�����"; break;
		case 3001: resultText = "error3001:line " + line.ToString() + " ��ʶ���ض���"; break;
		case 3002: resultText = "error3002:line " + line.ToString() + " ��ʶ��δ����"; break;
		case 3003: resultText = "error3003:line " + line.ToString() + " ���ʽ�Ҳ��������������Ͳ�ƥ��"; break;
		default: resultText = "δ�������" + syntaxResult.ToString();
			break;
		}
		//richTextBox1->Text = "����ɹ�";
		richTextBox1->Text += resultText;
		richTextBox1->Text += "\n";
		if (syntaxResult == 1)
			return 1;
		return 0;
	}

	private:void showSourceCode(){					//Դ����
		if (fileName != ""){
			StreamReader^ file = gcnew StreamReader(fileName);
			String^ str = file->ReadToEnd();
			richTextBox2->Text = str;
		}
		else
			MessageBox::Show("��δ���ļ�");
	}
	private:void showSymbolTable(){    //��ʾ���ű�
		richTextBox3->Text = "";
		String ^symbolText = "";
		
		String ^temp = "�����ܱ�\n";
		for (auto t : symbol_total_table){   //�ܱ�
			temp += gcnew String(t.name.c_str()); temp += "\t   ";
			temp += gcnew String(t.cat.c_str()); temp += "\t   ";
			temp += gcnew String(t.addr.c_str()); temp += "\t   ";
			temp += "\n";
			symbolText += temp;
			temp = "";
		}
		//symbol_total_table.clear();
		symbolText += "��ʶ����\n";
		String ^type = "";
		for (auto t : identifier_table){
			switch (t.type){
			case 4:type = "int"; break;
			case 5:type = "float"; break;
			case 6:type = "char"; break;
			}
			temp += t.number.ToString(); temp += "\t   ";
			temp += gcnew String((t.name).c_str()); temp += "\t   ";
			temp += type; temp += "\t   ";
			temp += "\n";
			symbolText += temp;
			temp = "";
		}

		symbolText += "�ؼ��ֱ�\n";
		for (auto t : keyword_table){
			temp += t.number.ToString(); temp += "\t   ";
			temp += gcnew String((t.name).c_str()); temp += "\t   ";
			temp += "\n";
			symbolText += temp;
			temp = "";
		}
		symbolText += "������\n";
		for (auto t : constant_table){
			temp += t.number.ToString(); temp += "\t   ";
			temp += gcnew String((t.value).c_str()); temp += "\t   ";
			temp += "\n";
			symbolText += temp;
			temp = "";
		}
		richTextBox3->Text = symbolText;
		symbolText = "";
	}

	private:void showTempCode(){       //��ʾ�м����
		richTextBox4->Text = "";
		String ^tempcodeText = "";
		String ^temp = "";
		for (auto t : temp_code){
			temp += gcnew String((t.op).c_str()); temp += "\t";
			temp += gcnew String((t.arg1).c_str()); temp += "\t";
			temp += gcnew String((t.arg2).c_str()); temp += "\t";
			temp += gcnew String((t.result).c_str()); temp += "\t";
			temp += "\n";
			tempcodeText += temp;
			temp = "";
		}
		richTextBox4->Text = tempcodeText;
	}

	private:void showOptimize(){
		richTextBox5->Text = "";
		String ^tempcodeText = "�Ż������Ԫʽ\n";
		String ^temp = "";
		for (auto t : temp_code){
			temp += gcnew String((t.op).c_str()); temp += "\t";
			temp += gcnew String((t.arg1).c_str()); temp += "\t";
			temp += gcnew String((t.arg2).c_str()); temp += "\t";
			temp += gcnew String((t.result).c_str()); temp += "\t";
			temp += "\n";
			tempcodeText += temp;
			temp = "";
		}
		richTextBox5->Text = tempcodeText;
	}

	private:void showobjectCode(){
		richTextBox6->Text = "";
		String ^objectCodeText;
		String ^temp;
		for (auto t : object_code){
			objectCodeText += gcnew String(t.c_str()); objectCodeText += "\n";
		}
		richTextBox6->Text = objectCodeText;
	}
	private:String ^fileName="";
	
	private: System::Void Դ�ļ�ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			fileName = openFileDialog1->FileName;

			StreamReader^ file = gcnew StreamReader(fileName);
			String^ str = file->ReadToEnd();
			file->Close();
			richTextBox2->Text = str;
		}
		else
			MessageBox::Show("δѡ���ļ�");

	}


private: System::Void �����ļ�ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {   //�����ļ���ť
	String ^saveText = richTextBox2->Text;
	fileName = "";
	saveFileDialog1->ShowDialog();
	if (saveFileDialog1->FileName != ""){
		fileName = saveFileDialog1->FileName;
		richTextBox2->SaveFile(fileName, RichTextBoxStreamType::PlainText);
		richTextBox2->LoadFile(fileName, RichTextBoxStreamType::PlainText);
	}
	else
		MessageBox::Show("��δ���ļ�");
}

	private: System::Void �˳�ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }
private: System::Void �ʷ�����ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (fileName != ""){
		richTextBox1->Text = "���ڽ��дʷ�����\n";
		char*  filename = (char*)(void*)Marshal::StringToHGlobalAnsi(fileName);
		int result = getToken(filename); 
		if (result >= 1000){
			richTextBox1->Text = "error2200:line " + error_line.ToString() + " δ��ʶ����ַ�";
		}
		else{
			showToken();
			richTextBox1->Text += "�ʷ������ɹ�\n";
		}
	}
	else
		MessageBox::Show("��δ���ļ�");
}
private: System::Void �﷨�������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (fileName != ""){
		richTextBox1->Text = "���ڽ��дʷ�����\n";
		char*  filename = (char*)(void*)Marshal::StringToHGlobalAnsi(fileName);
		int tokenResult = getToken(filename);
		if (tokenResult >= 1000){
			richTextBox1->Text += "error2200:line " + error_line.ToString() + " δ��ʶ����ַ�\n";
		}
		else{
			richTextBox1->Text += "�ʷ������ɹ�\n";
			richTextBox1->Text += "���ڽ����﷨�������\n";
			createSymbolTable();   //���ɷ��ű�
			showToken();   //��ʾ�ʷ�����
			if (showSyntaxResult()){   //��ʾ�ʷ��﷨�������
			
				showSymbolTable();		//��ʾ���ű�
				showTempCode();     //��ʾ�м����
				button2->Visible = true;
				button3->Visible = true;
				�Ż�ToolStripMenuItem->Enabled = true;
				//identifier_table.clear();
				//symbol_total_table.clear();
			}
			else{
				identifier_table.clear();
			}
		}
	}
	else
		MessageBox::Show("û�д��ļ�");
}
private: System::Void �Ż�ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {   //�Ż�
	richTextBox5->Text = "";
	button4->Visible = true;
	opt_constant();
	opt_common();
	richTextBox1->Text += "�Ż��ɹ�\n";
	showOptimize();
	Ŀ���������ToolStripMenuItem->Enabled = true;
}

private: System::Void Ŀ���������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	createObjectCode();
	richTextBox6->Text = "";
	showobjectCode();
	button5->Visible = true;
	Ŀ���������ToolStripMenuItem->Enabled = true;
	richTextBox1->Text += "Ŀ��������ɳɹ�\n";
	����ToolStripMenuItem->Enabled = true;
	richTextBox6->SaveFile("g:\\hb\\demo.asm", RichTextBoxStreamType::PlainText);
	//richTextBox6->LoadFile("g:\\hb\\demo.asm", RichTextBoxStreamType::PlainText);
}

private: System::Void ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	richTextBox6->SaveFile("g:\\hb\\demo.asm", RichTextBoxStreamType::PlainText);
	richTextBox6->LoadFile("g:\\hb\\demo.asm", RichTextBoxStreamType::PlainText);
	system("DOSBox-0.74\\DOSBox");
	system("exit");
	//clearToken();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {   //��ʾԴ����
	richTextBox2->Visible = true;
	richTextBox3->Visible = false;
	richTextBox4->Visible = false;
	richTextBox5->Visible = false;
	richTextBox6->Visible = false;
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {	//��ʾ���ű�
	richTextBox2->Visible = false;
	richTextBox3->Visible = true;
	richTextBox4->Visible = false;
	richTextBox5->Visible = false;
	richTextBox6->Visible = false;
}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {   //��ʾ�м����
	richTextBox2->Visible = false;
	richTextBox3->Visible = false;
	richTextBox4->Visible = true;
	richTextBox5->Visible = false;
	richTextBox6->Visible = false;
}

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {    //��ʾ�Ż�����м����
	richTextBox2->Visible = false;
	richTextBox3->Visible = false;
	richTextBox4->Visible = false;
	richTextBox5->Visible = true;
	richTextBox6->Visible = false;
}


private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {	//��ʾĿ�����
	richTextBox2->Visible = false;
	richTextBox3->Visible = false;
	richTextBox4->Visible = false;
	richTextBox5->Visible = false;
	richTextBox6->Visible = true;
}


private: System::Void richTextBox2_Click(System::Object^  sender, System::EventArgs^  e) {
	int row =1+ richTextBox2->GetLineFromCharIndex(richTextBox2->SelectionStart);
	label3->Text ="line:"+ Convert::ToString(row);
	int col = (1 + richTextBox2->SelectionStart - (richTextBox2->GetFirstCharIndexFromLine(1 + richTextBox2->GetLineFromCharIndex(richTextBox2->SelectionStart) - 1)));
	label3->Text += ",row:" + col.ToString();
}


private: System::Void richTextBox2_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
	int row =1+ richTextBox2->GetLineFromCharIndex(richTextBox2->SelectionStart);
	label3->Text = "line:" + Convert::ToString(row);
	int col = (1 + richTextBox2->SelectionStart - (richTextBox2->GetFirstCharIndexFromLine(1 + richTextBox2->GetLineFromCharIndex(richTextBox2->SelectionStart) - 1)));
	label3->Text += ",row:" + col.ToString();
}

private: System::Void richTextBox4_Click(System::Object^  sender, System::EventArgs^  e) {
	int row = 1 + richTextBox4->GetLineFromCharIndex(richTextBox4->SelectionStart);
	label3->Text = "line:" + Convert::ToString(row);
	int col = (1 + richTextBox4->SelectionStart - (richTextBox4->GetFirstCharIndexFromLine(1 + richTextBox4->GetLineFromCharIndex(richTextBox4->SelectionStart) - 1)));
	label3->Text += ",row:" + col.ToString();
}
private: System::Void richTextBox5_Click(System::Object^  sender, System::EventArgs^  e) {
	int row = 1 + richTextBox5->GetLineFromCharIndex(richTextBox5->SelectionStart);
	label3->Text = "line:" + Convert::ToString(row);
	int col = (1 + richTextBox5->SelectionStart - (richTextBox5->GetFirstCharIndexFromLine(1 + richTextBox5->GetLineFromCharIndex(richTextBox5->SelectionStart) - 1)));
	label3->Text += ",row:" + col.ToString();
}
private: System::Void ��ϵ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	system("explorer https://github.com/xujingguo58");
}
private: System::Void ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("����", "����\n��һ��\n��һ��");
}
};
}

