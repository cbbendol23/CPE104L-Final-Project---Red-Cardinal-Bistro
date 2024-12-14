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
	/// Summary for UpdateCouponForm2
	/// </summary>
	public ref class UpdateCouponForm2 : public System::Windows::Forms::Form
	{
	public:
		UpdateCouponForm2(String^ oldCouponCode)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
			this->oldCouponCode = oldCouponCode;
		}

		void saveCoupon() {
			std::string directory = "C:\\CSV FILES\\";
			couponManager->SaveCouponsToCSV(directory);
			MessageBox::Show("Coupon updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UpdateCouponForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtBoxEnterNewCouponName;
	private: System::Windows::Forms::TextBox^ txtBoxEnterNewDiscount;
	private: System::Windows::Forms::Button^ btnUpdateCoupon;
	private: System::Windows::Forms::Button^ btnBackFromCoupon;
	private: CouponManager* couponManager = &CouponManager::getInstance();
		   String^ oldCouponCode;

	protected:


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UpdateCouponForm2::typeid));
			this->txtBoxEnterNewCouponName = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxEnterNewDiscount = (gcnew System::Windows::Forms::TextBox());
			this->btnUpdateCoupon = (gcnew System::Windows::Forms::Button());
			this->btnBackFromCoupon = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtBoxEnterNewCouponName
			// 
			this->txtBoxEnterNewCouponName->BackColor = System::Drawing::SystemColors::MenuText;
			this->txtBoxEnterNewCouponName->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 26.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtBoxEnterNewCouponName->ForeColor = System::Drawing::Color::White;
			this->txtBoxEnterNewCouponName->Location = System::Drawing::Point(643, 337);
			this->txtBoxEnterNewCouponName->Multiline = true;
			this->txtBoxEnterNewCouponName->Name = L"txtBoxEnterNewCouponName";
			this->txtBoxEnterNewCouponName->Size = System::Drawing::Size(366, 67);
			this->txtBoxEnterNewCouponName->TabIndex = 16;
			// 
			// txtBoxEnterNewDiscount
			// 
			this->txtBoxEnterNewDiscount->BackColor = System::Drawing::SystemColors::MenuText;
			this->txtBoxEnterNewDiscount->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 26.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtBoxEnterNewDiscount->ForeColor = System::Drawing::Color::White;
			this->txtBoxEnterNewDiscount->Location = System::Drawing::Point(643, 456);
			this->txtBoxEnterNewDiscount->Multiline = true;
			this->txtBoxEnterNewDiscount->Name = L"txtBoxEnterNewDiscount";
			this->txtBoxEnterNewDiscount->Size = System::Drawing::Size(366, 67);
			this->txtBoxEnterNewDiscount->TabIndex = 17;
			// 
			// btnUpdateCoupon
			// 
			this->btnUpdateCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnUpdateCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnUpdateCoupon->Location = System::Drawing::Point(543, 596);
			this->btnUpdateCoupon->Name = L"btnUpdateCoupon";
			this->btnUpdateCoupon->Size = System::Drawing::Size(165, 51);
			this->btnUpdateCoupon->TabIndex = 18;
			this->btnUpdateCoupon->UseVisualStyleBackColor = false;
			this->btnUpdateCoupon->Click += gcnew System::EventHandler(this, &UpdateCouponForm2::btnUpdateCoupon_Click);
			// 
			// btnBackFromCoupon
			// 
			this->btnBackFromCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnBackFromCoupon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnBackFromCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBackFromCoupon->Location = System::Drawing::Point(45, 33);
			this->btnBackFromCoupon->Name = L"btnBackFromCoupon";
			this->btnBackFromCoupon->Size = System::Drawing::Size(38, 38);
			this->btnBackFromCoupon->TabIndex = 19;
			this->btnBackFromCoupon->UseVisualStyleBackColor = false;
			this->btnBackFromCoupon->Click += gcnew System::EventHandler(this, &UpdateCouponForm2::btnBackFromCoupon_Click);
			// 
			// UpdateCouponForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1255, 706);
			this->Controls->Add(this->btnBackFromCoupon);
			this->Controls->Add(this->btnUpdateCoupon);
			this->Controls->Add(this->txtBoxEnterNewDiscount);
			this->Controls->Add(this->txtBoxEnterNewCouponName);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"UpdateCouponForm2";
			this->Text = L"UpdateCouponForm2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnBackFromCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnUpdateCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		// Get the new coupon name and discount percentage from the text boxes
		String^ newCouponName = txtBoxEnterNewCouponName->Text;
		String^ newDiscount = txtBoxEnterNewDiscount->Text;

		// Create a marshal_context for the conversion
		msclr::interop::marshal_context context;

		// Convert System::String^ to std::string
		std::string newCouponNameStd = context.marshal_as<std::string>(newCouponName);
		std::string newDiscountStd = context.marshal_as<std::string>(newDiscount);
		std::string oldCouponCodeStd = context.marshal_as<std::string>(oldCouponCode);

		// Convert discount to integer
		int newDiscountInt = std::stoi(newDiscountStd);

		// Update the coupon information
		CouponManager::getInstance().UpdateCoupon(oldCouponCodeStd, newCouponNameStd, newDiscountInt);

		saveCoupon();

		this->Close();
	}
};
}
