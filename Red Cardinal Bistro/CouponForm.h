#pragma once
#include "CouponCodes.h"
#include "FoodMenu.h"
#include <msclr/marshal_cppstd.h>
#include "SharedData.h"
#include "Orders.h"
#include <algorithm>

namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class CouponForm : public System::Windows::Forms::Form
	{
	public:
		CouponForm(System::String^ ordersText, double totalPrice, System::String^ schoolID, System::String^ foodName, int quantity)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
			this->ordersText = ordersText;
			this->totalPrice = totalPrice;
			this->schoolID = schoolID;
			this->foodName = foodName;
			this->quantity = quantity;
			this->menu = &FoodMenu::Instance();
			this->couponManager = &CouponManager::getInstance();
		}

		// Event to notify when the coupon code is submitted
		event EventHandler<System::String^>^ CouponCodeSubmitted;

		String^ GetCouponCode()
		{
			// Assuming you have a TextBox named txtCouponCode
			return txtBoxCoupon->Text;
		}



	protected:
		~CouponForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnSubmitOrder;
	private: System::Windows::Forms::Button^ btnSkipCoupon;
	private: System::Windows::Forms::TextBox^ txtBoxCoupon;
		   // newly added
	private:
		System::String^ ordersText;
		double totalPrice;
		System::String^ schoolID;
		System::String^ foodName;
		int quantity;
		FoodMenu* menu;
		CouponManager* couponManager;

	private: System::Void CloseAllExceptFirstAndSecondWindow() {
		// Get the first and second forms (main form and second form)
		Form^ firstForm = Application::OpenForms[0];
		Form^ secondForm = Application::OpenForms[1];

		// Iterate through all open forms
		for (int i = Application::OpenForms->Count - 1; i >= 0; i--) {
			Form^ form = Application::OpenForms[i];
			// Close the form if it is not the first or second form
			if (form != firstForm) {
				if (form == secondForm) {
					form->Hide(); // Hide the second form instead of closing it
				}
				else {
					form->Close();
				}
			}
		}
	}



	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CouponForm::typeid));
			this->btnSubmitOrder = (gcnew System::Windows::Forms::Button());
			this->btnSkipCoupon = (gcnew System::Windows::Forms::Button());
			this->txtBoxCoupon = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnSubmitOrder
			// 
			this->btnSubmitOrder->BackColor = System::Drawing::Color::Transparent;
			this->btnSubmitOrder->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnSubmitOrder->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSubmitOrder->Location = System::Drawing::Point(457, 469);
			this->btnSubmitOrder->Name = L"btnSubmitOrder";
			this->btnSubmitOrder->Size = System::Drawing::Size(340, 89);
			this->btnSubmitOrder->TabIndex = 7;
			this->btnSubmitOrder->UseVisualStyleBackColor = false;
			this->btnSubmitOrder->Click += gcnew System::EventHandler(this, &CouponForm::btnSubmitOrder_Click);
			// 
			// btnSkipCoupon
			// 
			this->btnSkipCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnSkipCoupon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnSkipCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSkipCoupon->Location = System::Drawing::Point(535, 579);
			this->btnSkipCoupon->Name = L"btnSkipCoupon";
			this->btnSkipCoupon->Size = System::Drawing::Size(198, 52);
			this->btnSkipCoupon->TabIndex = 8;
			this->btnSkipCoupon->UseVisualStyleBackColor = false;
			this->btnSkipCoupon->Click += gcnew System::EventHandler(this, &CouponForm::btnSkipCoupon_Click);
			// 
			// txtBoxCoupon
			// 
			this->txtBoxCoupon->BackColor = System::Drawing::SystemColors::MenuText;
			this->txtBoxCoupon->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtBoxCoupon->ForeColor = System::Drawing::Color::White;
			this->txtBoxCoupon->Location = System::Drawing::Point(225, 338);
			this->txtBoxCoupon->Multiline = true;
			this->txtBoxCoupon->Name = L"txtBoxCoupon";
			this->txtBoxCoupon->Size = System::Drawing::Size(806, 81);
			this->txtBoxCoupon->TabIndex = 9;
			this->txtBoxCoupon->TextChanged += gcnew System::EventHandler(this, &CouponForm::txtBoxCoupon_TextChanged);
			// 
			// CouponForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1255, 706);
			this->Controls->Add(this->txtBoxCoupon);
			this->Controls->Add(this->btnSkipCoupon);
			this->Controls->Add(this->btnSubmitOrder);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CouponForm";
			this->Text = L"CouponForm";
			this->Load += gcnew System::EventHandler(this, &CouponForm::CouponForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CouponForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	public: System::Void btnSubmitOrder_Click(System::Object^ sender, System::EventArgs^ e) {
		auto& couponManager = CouponManager::getInstance();
		std::string couponCode = msclr::interop::marshal_as<std::string>(this->txtBoxCoupon->Text);
		if (couponManager.IsCouponCodeValid(couponCode)) {
			int discountRate = couponManager.GetDiscountPercentage(couponCode);
			double discountAmount = totalPrice * discountRate / 100.0;
			double finalPrice = totalPrice - discountAmount;

			// Manually convert System::String^ to std::string
			using namespace System::Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(schoolID)).ToPointer();
			std::string schoolIDStr = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));

			// Retrieve all orders for the customer
			auto customerOrders = Orders::Instance().GetOrdersForCustomer(schoolIDStr);

			// Apply discount to each order and save
			for (auto& order : customerOrders) {
				Orders::Order discountedOrder = order;
				discountedOrder.price *= (1 - discountRate / 100.0);
				Orders::Instance().SaveDiscountedOrder(discountedOrder, discountRate);
			}

			// Display the orders and discount details in a message box
			System::String^ message = ordersText + "\n\nTotal Price: PHP " + totalPrice.ToString("F2") +
				"\nDiscount: " + discountRate + "% (PHP " + discountAmount.ToString("F2") + ")" +
				"\nFinal Price: PHP " + finalPrice.ToString("F2");
			MessageBox::Show(message, "Order Details with Discount", MessageBoxButtons::OK, MessageBoxIcon::Information);

			// Store the coupon code in SharedData
			SharedData::couponCode = txtBoxCoupon->Text;

			// Close form or proceed as needed
			CloseAllExceptFirstAndSecondWindow();
		}
		else {
			MessageBox::Show("Invalid coupon code.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}


	private: System::Void btnSkipCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		// Display the order details and original total price in a message box
		System::String^ message = ordersText + "\nTotal Price: PHP " + totalPrice.ToString("F2");
		MessageBox::Show(message, "Order Details", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// Manually convert System::String^ to std::string
		using namespace System::Runtime::InteropServices;
		const char* schoolIDChars = (const char*)(Marshal::StringToHGlobalAnsi(schoolID)).ToPointer();
		std::string schoolIDStr = schoolIDChars;
		Marshal::FreeHGlobal(IntPtr((void*)schoolIDChars));

		const char* foodNameChars = (const char*)(Marshal::StringToHGlobalAnsi(foodName)).ToPointer();
		std::string foodNameStr = foodNameChars;
		Marshal::FreeHGlobal(IntPtr((void*)foodNameChars));

		// Retrieve all orders for the customer
		auto customerOrders = Orders::Instance().GetOrdersForCustomer(schoolIDStr);

		// Save non-discounted order for each customer order
		for (auto& order : customerOrders) {
			Orders::Order nonDiscountedOrder = order;
			Orders::Instance().SaveNonDiscountedOrder(nonDiscountedOrder);
		}

		// Close form or proceed as needed
		CloseAllExceptFirstAndSecondWindow();
	}

	private: System::Void txtBoxCoupon_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
