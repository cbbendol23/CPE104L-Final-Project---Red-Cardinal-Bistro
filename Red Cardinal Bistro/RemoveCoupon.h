#pragma once

#include "CouponCodes.h"
#include <msclr/marshal_cppstd.h>

namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RemoveCoupon
	/// </summary>
	public ref class RemoveCoupon : public System::Windows::Forms::Form
	{
	public:
		RemoveCoupon(void)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
		}

		void saveCoupon() {
			std::string directory = "C:\\CSV FILES\\";
			couponManager->SaveCouponsToCSV(directory);
			MessageBox::Show("Coupon removed successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RemoveCoupon()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtBoxEnterRemoveCoupon;
	private: System::Windows::Forms::Button^ btnRemoveCoupon;
	private: System::Windows::Forms::Button^ btnBackFromCoupon;
	private: CouponManager* couponManager = &CouponManager::getInstance();
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RemoveCoupon::typeid));
			this->txtBoxEnterRemoveCoupon = (gcnew System::Windows::Forms::TextBox());
			this->btnRemoveCoupon = (gcnew System::Windows::Forms::Button());
			this->btnBackFromCoupon = (gcnew System::Windows::Forms::Button());
			this->btnViewCurrentCoupon = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtBoxEnterRemoveCoupon
			// 
			this->txtBoxEnterRemoveCoupon->BackColor = System::Drawing::SystemColors::MenuText;
			this->txtBoxEnterRemoveCoupon->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 26.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtBoxEnterRemoveCoupon->ForeColor = System::Drawing::Color::White;
			this->txtBoxEnterRemoveCoupon->Location = System::Drawing::Point(551, 392);
			this->txtBoxEnterRemoveCoupon->Multiline = true;
			this->txtBoxEnterRemoveCoupon->Name = L"txtBoxEnterRemoveCoupon";
			this->txtBoxEnterRemoveCoupon->Size = System::Drawing::Size(366, 67);
			this->txtBoxEnterRemoveCoupon->TabIndex = 17;
			// 
			// btnRemoveCoupon
			// 
			this->btnRemoveCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnRemoveCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRemoveCoupon->Location = System::Drawing::Point(542, 595);
			this->btnRemoveCoupon->Name = L"btnRemoveCoupon";
			this->btnRemoveCoupon->Size = System::Drawing::Size(165, 51);
			this->btnRemoveCoupon->TabIndex = 19;
			this->btnRemoveCoupon->UseVisualStyleBackColor = false;
			this->btnRemoveCoupon->Click += gcnew System::EventHandler(this, &RemoveCoupon::btnRemoveCoupon_Click);
			// 
			// btnBackFromCoupon
			// 
			this->btnBackFromCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnBackFromCoupon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnBackFromCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBackFromCoupon->Location = System::Drawing::Point(45, 32);
			this->btnBackFromCoupon->Name = L"btnBackFromCoupon";
			this->btnBackFromCoupon->Size = System::Drawing::Size(38, 38);
			this->btnBackFromCoupon->TabIndex = 20;
			this->btnBackFromCoupon->UseVisualStyleBackColor = false;
			this->btnBackFromCoupon->Click += gcnew System::EventHandler(this, &RemoveCoupon::btnBackFromCoupon_Click);
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
			this->btnViewCurrentCoupon->Click += gcnew System::EventHandler(this, &RemoveCoupon::btnViewCurrentCoupon_Click);
			// 
			// RemoveCoupon
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1255, 706);
			this->Controls->Add(this->btnViewCurrentCoupon);
			this->Controls->Add(this->btnBackFromCoupon);
			this->Controls->Add(this->btnRemoveCoupon);
			this->Controls->Add(this->txtBoxEnterRemoveCoupon);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"RemoveCoupon";
			this->Text = L"RemoveCoupon";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnRemoveCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		// Get the coupon code from the text box
		String^ couponCode = txtBoxEnterRemoveCoupon->Text;

		// Convert the managed String^ to std::string
		msclr::interop::marshal_context context;
		std::string couponCodeStr = context.marshal_as<std::string>(couponCode);

		// Get the instance of CouponManager
		auto& couponManager = CouponManager::getInstance();

		// Try to remove the coupon
		if (couponManager.RemoveCouponCode(couponCodeStr)) {
			saveCoupon();
			this->Close();
		}
		else {
			MessageBox::Show("Coupon code not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnBackFromCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
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
