#pragma once
#include "AboutUsForm.h"

namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AbousUsForm1
	/// </summary>
	public ref class AbousUsForm1 : public System::Windows::Forms::Form
	{
	public:
		AbousUsForm1(void)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AbousUsForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnBackFromCoupon;
	protected:
	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AbousUsForm1::typeid));
			this->btnBackFromCoupon = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnBackFromCoupon
			// 
			this->btnBackFromCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnBackFromCoupon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnBackFromCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBackFromCoupon->Location = System::Drawing::Point(27, 22);
			this->btnBackFromCoupon->Name = L"btnBackFromCoupon";
			this->btnBackFromCoupon->Size = System::Drawing::Size(38, 38);
			this->btnBackFromCoupon->TabIndex = 20;
			this->btnBackFromCoupon->UseVisualStyleBackColor = false;
			this->btnBackFromCoupon->Click += gcnew System::EventHandler(this, &AbousUsForm1::btnBackFromCoupon_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Location = System::Drawing::Point(1083, 598);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(38, 38);
			this->button1->TabIndex = 21;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &AbousUsForm1::button1_Click);
			// 
			// AbousUsForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1186, 667);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnBackFromCoupon);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AbousUsForm1";
			this->Text = L"AbousUsForm1";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnBackFromCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		AboutUsForm^ form = gcnew AboutUsForm();
		form->ShowDialog();
	}
	};
}
