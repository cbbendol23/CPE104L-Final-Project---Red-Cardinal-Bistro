#pragma once
#include "LoginForm.h" // Include the LoginForm header

namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(LoginForm^ loginForm)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
			this->loginForm = loginForm;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblSchoolID;
	protected:
	private: System::Windows::Forms::TextBox^ lblEnterSchoolID;
	private: System::Windows::Forms::Button^ btnRegister;
	private: LoginForm^ loginForm;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblSchoolID = (gcnew System::Windows::Forms::Label());
			this->lblEnterSchoolID = (gcnew System::Windows::Forms::TextBox());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblSchoolID
			// 
			this->lblSchoolID->AutoSize = true;
			this->lblSchoolID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSchoolID->Location = System::Drawing::Point(125, 79);
			this->lblSchoolID->Name = L"lblSchoolID";
			this->lblSchoolID->Size = System::Drawing::Size(177, 25);
			this->lblSchoolID->TabIndex = 0;
			this->lblSchoolID->Text = L"Enter SCHOOLID";
			// 
			// lblEnterSchoolID
			// 
			this->lblEnterSchoolID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblEnterSchoolID->Location = System::Drawing::Point(115, 158);
			this->lblEnterSchoolID->Name = L"lblEnterSchoolID";
			this->lblEnterSchoolID->Size = System::Drawing::Size(203, 31);
			this->lblEnterSchoolID->TabIndex = 1;
			// 
			// btnRegister
			// 
			this->btnRegister->Location = System::Drawing::Point(180, 241);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(75, 23);
			this->btnRegister->TabIndex = 2;
			this->btnRegister->Text = L"Register";
			this->btnRegister->UseVisualStyleBackColor = true;
			this->btnRegister->Click += gcnew System::EventHandler(this, &RegisterForm::btnRegister_Click);
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(438, 377);
			this->Controls->Add(this->btnRegister);
			this->Controls->Add(this->lblEnterSchoolID);
			this->Controls->Add(this->lblSchoolID);
			this->Name = L"RegisterForm";
			this->Text = L"RegisterForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	};
}