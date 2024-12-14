#pragma once

#include "CouponCodes.h"
#include "CouponForm.h"
#include <msclr/marshal_cppstd.h>

namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddCouponForm
	/// </summary>
	public ref class AddCouponForm : public System::Windows::Forms::Form
	{
	public:
		AddCouponForm(void)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;

		}

		void saveCoupon() {
			std::string directory = "C:\\CSV FILES\\";
			couponManager->SaveCouponsToCSV(directory);
			MessageBox::Show("Coupon saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddCouponForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtBoxEnterNewCoupon;
	protected:
	private: System::Windows::Forms::TextBox^ txtBoxEnterPercentage;
	private: System::Windows::Forms::Button^ btnAddCoupon;
	private: System::Windows::Forms::Button^ btnBackFromCoupon;
	private: CouponManager* couponManager = &CouponManager::getInstance();
	private: System::Windows::Forms::Button^ btnViewCurrentOrder;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddCouponForm::typeid));
			this->txtBoxEnterNewCoupon = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxEnterPercentage = (gcnew System::Windows::Forms::TextBox());
			this->btnAddCoupon = (gcnew System::Windows::Forms::Button());
			this->btnBackFromCoupon = (gcnew System::Windows::Forms::Button());
			this->btnViewCurrentOrder = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtBoxEnterNewCoupon
			// 
			this->txtBoxEnterNewCoupon->BackColor = System::Drawing::SystemColors::MenuText;
			this->txtBoxEnterNewCoupon->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 26.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtBoxEnterNewCoupon->ForeColor = System::Drawing::Color::White;
			this->txtBoxEnterNewCoupon->Location = System::Drawing::Point(550, 333);
			this->txtBoxEnterNewCoupon->Multiline = true;
			this->txtBoxEnterNewCoupon->Name = L"txtBoxEnterNewCoupon";
			this->txtBoxEnterNewCoupon->Size = System::Drawing::Size(366, 67);
			this->txtBoxEnterNewCoupon->TabIndex = 15;
			this->txtBoxEnterNewCoupon->TextChanged += gcnew System::EventHandler(this, &AddCouponForm::txtBoxEnterNewCoupon_TextChanged);
			// 
			// txtBoxEnterPercentage
			// 
			this->txtBoxEnterPercentage->BackColor = System::Drawing::SystemColors::MenuText;
			this->txtBoxEnterPercentage->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 26.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtBoxEnterPercentage->ForeColor = System::Drawing::Color::White;
			this->txtBoxEnterPercentage->Location = System::Drawing::Point(550, 451);
			this->txtBoxEnterPercentage->Multiline = true;
			this->txtBoxEnterPercentage->Name = L"txtBoxEnterPercentage";
			this->txtBoxEnterPercentage->Size = System::Drawing::Size(366, 67);
			this->txtBoxEnterPercentage->TabIndex = 16;
			// 
			// btnAddCoupon
			// 
			this->btnAddCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnAddCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnAddCoupon->Location = System::Drawing::Point(543, 595);
			this->btnAddCoupon->Name = L"btnAddCoupon";
			this->btnAddCoupon->Size = System::Drawing::Size(165, 51);
			this->btnAddCoupon->TabIndex = 17;
			this->btnAddCoupon->UseVisualStyleBackColor = false;
			this->btnAddCoupon->Click += gcnew System::EventHandler(this, &AddCouponForm::btnAddCoupon_Click);
			// 
			// btnBackFromCoupon
			// 
			this->btnBackFromCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnBackFromCoupon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnBackFromCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBackFromCoupon->Location = System::Drawing::Point(44, 32);
			this->btnBackFromCoupon->Name = L"btnBackFromCoupon";
			this->btnBackFromCoupon->Size = System::Drawing::Size(38, 38);
			this->btnBackFromCoupon->TabIndex = 20;
			this->btnBackFromCoupon->UseVisualStyleBackColor = false;
			this->btnBackFromCoupon->Click += gcnew System::EventHandler(this, &AddCouponForm::btnBackFromCoupon_Click);
			// 
			// btnViewCurrentOrder
			// 
			this->btnViewCurrentOrder->BackColor = System::Drawing::Color::Transparent;
			this->btnViewCurrentOrder->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnViewCurrentOrder->Location = System::Drawing::Point(33, 563);
			this->btnViewCurrentOrder->Name = L"btnViewCurrentOrder";
			this->btnViewCurrentOrder->Size = System::Drawing::Size(166, 114);
			this->btnViewCurrentOrder->TabIndex = 21;
			this->btnViewCurrentOrder->UseVisualStyleBackColor = false;
			this->btnViewCurrentOrder->Click += gcnew System::EventHandler(this, &AddCouponForm::btnViewCurrentOrder_Click);
			// 
			// AddCouponForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1255, 706);
			this->Controls->Add(this->btnViewCurrentOrder);
			this->Controls->Add(this->btnBackFromCoupon);
			this->Controls->Add(this->btnAddCoupon);
			this->Controls->Add(this->txtBoxEnterPercentage);
			this->Controls->Add(this->txtBoxEnterNewCoupon);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddCouponForm";
			this->Text = L"AddCouponForm";
			this->Load += gcnew System::EventHandler(this, &AddCouponForm::AddCouponForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void txtBoxEnterNewCoupon_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnAddCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		// Convert System::String^ to std::string
		std::string couponName = msclr::interop::marshal_as<std::string>(txtBoxEnterNewCoupon->Text);
		std::string percentageStr = msclr::interop::marshal_as<std::string>(txtBoxEnterPercentage->Text);

		// Convert percentageStr to int
		int discountPercentage = std::stoi(percentageStr);

		// Check if the coupon code already exists
		if (CouponManager::getInstance().IsCouponCodeExisting(couponName)) {
			MessageBox::Show("Coupon code already exists!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Add the coupon to the CouponManager
		CouponManager::getInstance().AddCouponCode(couponName, discountPercentage);

		// Optionally, show a message box to confirm the addition
		MessageBox::Show("Coupon added successfully!");

		saveCoupon();

		this->Close();
	}

	private: System::Void AddCouponForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void btnBackFromCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void btnViewCurrentOrder_Click(System::Object^ sender, System::EventArgs^ e) {
		// Retrieve the list of coupon codes
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
