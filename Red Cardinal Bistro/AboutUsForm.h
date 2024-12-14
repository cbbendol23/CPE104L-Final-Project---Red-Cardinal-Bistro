#pragma once

namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AboutUsForm
	/// </summary>
	public ref class AboutUsForm : public System::Windows::Forms::Form
	{
	public:
		AboutUsForm(void)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AboutUsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnBackFromCoupon;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutUsForm::typeid));
			this->btnBackFromCoupon = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnBackFromCoupon
			// 
			this->btnBackFromCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnBackFromCoupon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnBackFromCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBackFromCoupon->Location = System::Drawing::Point(44, 17);
			this->btnBackFromCoupon->Name = L"btnBackFromCoupon";
			this->btnBackFromCoupon->Size = System::Drawing::Size(38, 38);
			this->btnBackFromCoupon->TabIndex = 20;
			this->btnBackFromCoupon->UseVisualStyleBackColor = false;
			this->btnBackFromCoupon->Click += gcnew System::EventHandler(this, &AboutUsForm::btnBackFromCoupon_Click);
			// 
			// AboutUsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1186, 667);
			this->Controls->Add(this->btnBackFromCoupon);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AboutUsForm";
			this->Text = L"AboutUsForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnBackFromCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
