#pragma once

#include "CouponCodes.h"
#include "UpdateCouponForm2.h"
#include <msclr/marshal_cppstd.h>

namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UpdateCouponForm1
	/// </summary>
	public ref class UpdateCouponForm1 : public System::Windows::Forms::Form
	{
	public:
		UpdateCouponForm1(void)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UpdateCouponForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtBoxEnterCouponName;
	private: System::Windows::Forms::Button^ btnAddCoupon;
	private: System::Windows::Forms::Button^ btnBackFromCoupon;
	private: System::Windows::Forms::Button^ btnViewCurrentCoupon;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UpdateCouponForm1::typeid));
			this->txtBoxEnterCouponName = (gcnew System::Windows::Forms::TextBox());
			this->btnAddCoupon = (gcnew System::Windows::Forms::Button());
			this->btnBackFromCoupon = (gcnew System::Windows::Forms::Button());
			this->btnViewCurrentCoupon = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtBoxEnterCouponName
			// 
			this->txtBoxEnterCouponName->BackColor = System::Drawing::SystemColors::MenuText;
			this->txtBoxEnterCouponName->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 26.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtBoxEnterCouponName->ForeColor = System::Drawing::Color::White;
			this->txtBoxEnterCouponName->Location = System::Drawing::Point(550, 392);
			this->txtBoxEnterCouponName->Multiline = true;
			this->txtBoxEnterCouponName->Name = L"txtBoxEnterCouponName";
			this->txtBoxEnterCouponName->Size = System::Drawing::Size(366, 67);
			this->txtBoxEnterCouponName->TabIndex = 16;
			// 
			// btnAddCoupon
			// 
			this->btnAddCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnAddCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnAddCoupon->Location = System::Drawing::Point(543, 595);
			this->btnAddCoupon->Name = L"btnAddCoupon";
			this->btnAddCoupon->Size = System::Drawing::Size(165, 51);
			this->btnAddCoupon->TabIndex = 18;
			this->btnAddCoupon->UseVisualStyleBackColor = false;
			this->btnAddCoupon->Click += gcnew System::EventHandler(this, &UpdateCouponForm1::btnAddCoupon_Click);
			// 
			// btnBackFromCoupon
			// 
			this->btnBackFromCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnBackFromCoupon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnBackFromCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBackFromCoupon->Location = System::Drawing::Point(46, 33);
			this->btnBackFromCoupon->Name = L"btnBackFromCoupon";
			this->btnBackFromCoupon->Size = System::Drawing::Size(38, 38);
			this->btnBackFromCoupon->TabIndex = 19;
			this->btnBackFromCoupon->UseVisualStyleBackColor = false;
			this->btnBackFromCoupon->Click += gcnew System::EventHandler(this, &UpdateCouponForm1::btnBackFromCoupon_Click);
			// 
			// btnViewCurrentCoupon
			// 
			this->btnViewCurrentCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnViewCurrentCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnViewCurrentCoupon->Location = System::Drawing::Point(33, 563);
			this->btnViewCurrentCoupon->Name = L"btnViewCurrentCoupon";
			this->btnViewCurrentCoupon->Size = System::Drawing::Size(166, 114);
			this->btnViewCurrentCoupon->TabIndex = 22;
			this->btnViewCurrentCoupon->UseVisualStyleBackColor = false;
			this->btnViewCurrentCoupon->Click += gcnew System::EventHandler(this, &UpdateCouponForm1::btnViewCurrentCoupon_Click);
			// 
			// UpdateCouponForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1255, 706);
			this->Controls->Add(this->btnViewCurrentCoupon);
			this->Controls->Add(this->btnBackFromCoupon);
			this->Controls->Add(this->btnAddCoupon);
			this->Controls->Add(this->txtBoxEnterCouponName);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"UpdateCouponForm1";
			this->Text = L"UpdateCouponForm1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnBackFromCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnAddCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		// Get the coupon name from the text box
		String^ couponName = txtBoxEnterCouponName->Text;
		std::string couponNameStd = msclr::interop::marshal_as<std::string>(couponName);

		// Check if the coupon exists
		if (CouponManager::getInstance().IsCouponCodeValid(couponNameStd)) {
			// Open UpdateCouponForm2 with the old coupon code
			UpdateCouponForm2^ updateForm = gcnew UpdateCouponForm2(couponName);
			updateForm->ShowDialog();
			this->Close();
		}
		else {
			// Show message box
			MessageBox::Show("The coupon does not exist.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnViewCurrentCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		auto couponCodes = CouponManager::getInstance().GetAllCouponCodes();

		// Check if there are any coupon codes
		if (couponCodes.empty()) {
			MessageBox::Show("No coupon codes available.", "Coupon Codes", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}

		// Format the coupon codes into a string
		std::ostringstream oss;
		oss << "Existing Coupon Codes:\n";
		for (const auto& coupon : couponCodes) {
			oss << coupon.code << " - " << coupon.discountPercentage << "%\n";
		}

		// Convert the formatted string to System::String^
		String^ couponCodesStr = gcnew String(oss.str().c_str());

		// Display the coupon codes in a message box
		MessageBox::Show(couponCodesStr, "Coupon Codes", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
};
}
