#pragma once
#include "CustomerForm.h"
#include "AdminForm.h"
#include <vector>
#include <string>
#include <algorithm>

namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
			this->menu = &FoodMenu::Instance();
			this->studentIDs = gcnew System::Collections::Generic::List<System::String^>();
			this->studentIDs->Add("2023104376");
			this->studentIDs->Add("2021135516");
			this->studentIDs->Add("2023102764");
			this->studentIDs->Add("2023101303");
			this->studentIDs->Add("2023101735");
			this->studentIDs->Add("2024123456");
			this->studentIDs->Add("testID");
		}

	protected:
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ tbLogin;
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Label^ lblEnterID;
	private:
		FoodMenu* menu;
		System::Collections::Generic::List<System::String^>^ studentIDs; // Moved studentIDs here
	private: System::Windows::Forms::Button^ btmRegister;

		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			   this->tbLogin = (gcnew System::Windows::Forms::TextBox());
			   this->btnLogin = (gcnew System::Windows::Forms::Button());
			   this->lblEnterID = (gcnew System::Windows::Forms::Label());
			   this->btmRegister = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // tbLogin
			   // 
			   this->tbLogin->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->tbLogin->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->tbLogin->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->tbLogin->Location = System::Drawing::Point(584, 414);
			   this->tbLogin->Name = L"tbLogin";
			   this->tbLogin->Size = System::Drawing::Size(467, 32);
			   this->tbLogin->TabIndex = 1;
			   this->tbLogin->WordWrap = false;
			   this->tbLogin->TextChanged += gcnew System::EventHandler(this, &LoginForm::tbLogin_TextChanged);
			   // 
			   // btnLogin
			   // 
			   this->btnLogin->AutoEllipsis = true;
			   this->btnLogin->BackColor = System::Drawing::Color::Transparent;
			   this->btnLogin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			   this->btnLogin->FlatAppearance->BorderSize = 0;
			   this->btnLogin->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnLogin->Location = System::Drawing::Point(707, 502);
			   this->btnLogin->Name = L"btnLogin";
			   this->btnLogin->Size = System::Drawing::Size(230, 61);
			   this->btnLogin->TabIndex = 0;
			   this->btnLogin->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			   this->btnLogin->UseVisualStyleBackColor = true;
			   this->btnLogin->Click += gcnew System::EventHandler(this, &LoginForm::btnLogin_Click);
			   // 
			   // lblEnterID
			   // 
			   this->lblEnterID->AutoSize = true;
			   this->lblEnterID->BackColor = System::Drawing::Color::Transparent;
			   this->lblEnterID->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblEnterID->ForeColor = System::Drawing::SystemColors::ButtonFace;
			   this->lblEnterID->Location = System::Drawing::Point(580, 378);
			   this->lblEnterID->Margin = System::Windows::Forms::Padding(0);
			   this->lblEnterID->Name = L"lblEnterID";
			   this->lblEnterID->Size = System::Drawing::Size(93, 24);
			   this->lblEnterID->TabIndex = 2;
			   this->lblEnterID->Text = L"Enter ID";
			   this->lblEnterID->Click += gcnew System::EventHandler(this, &LoginForm::label1_Click);
			   // 
			   // btmRegister
			   // 
			   this->btmRegister->Location = System::Drawing::Point(771, 580);
			   this->btmRegister->Name = L"btmRegister";
			   this->btmRegister->Size = System::Drawing::Size(106, 56);
			   this->btmRegister->TabIndex = 3;
			   this->btmRegister->Text = L"Register Now!!";
			   this->btmRegister->UseVisualStyleBackColor = true;
			   this->btmRegister->Click += gcnew System::EventHandler(this, &LoginForm::btmRegister_Click);
			   // 
			   // LoginForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			   this->ClientSize = System::Drawing::Size(1254, 706);
			   this->ControlBox = false;
			   this->Controls->Add(this->btmRegister);
			   this->Controls->Add(this->lblEnterID);
			   this->Controls->Add(this->tbLogin);
			   this->Controls->Add(this->btnLogin);
			   this->DoubleBuffered = true;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"LoginForm";
			   this->Text = L"LoginForm";
			   this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	public: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		// Get the entered ID from tbLogin
		String^ enteredID = tbLogin->Text;

		// Check if the entered ID exists in the list
		if (studentIDs->Contains(enteredID)) {
			MessageBox::Show("Welcome Student");
			CustomerForm^ customerForm = gcnew CustomerForm(enteredID);
			customerForm->ShowDialog();
		}
		else if (enteredID == "") {
			MessageBox::Show("Please enter your ID");
		}
		else if (enteredID == "00000") {
			MessageBox::Show("Welcome Admin");
			AdminForm^ adminForm = gcnew AdminForm();
			adminForm->ShowDialog();
		}
		else {
			MessageBox::Show("Login Failed");
		}

		tbLogin->Text = "";
	}

	public: System::Void btmRegister_Click(System::Object^ sender, System::EventArgs^ e) {
		// Get the entered ID from tbLogin
		String^ newID = tbLogin->Text;

		// Add the new ID to the list
		studentIDs->Add(newID);

		// Clear the text box
		tbLogin->Text = "";

		// Optionally, show a message that the ID has been added
		MessageBox::Show("ID Registered Successfully");
	}

	private: System::Void tbLogin_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnExitProgram_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	}; // Ensure this closing brace is at the correct scope
}
