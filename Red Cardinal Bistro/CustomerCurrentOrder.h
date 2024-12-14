#pragma once
#include "Orders.h"
#include "CouponForm.h"
#include <msclr/marshal_cppstd.h>

namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class CustomerCurrentOrder : public System::Windows::Forms::Form
	{
	public:
		CustomerCurrentOrder(System::String^ id)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
			customerID = id;
		}

		System::String^ GetOrdersText() {
			return txtboxOrdersCustomer->Text;
		}

		void ResetOrdersTextBox() {
			txtboxOrdersCustomer->Text = "";
		}

		void ResetTotalPriceTextBox() {
			txtboxTotalPrice->Text = "Total Price: PHP";
		}

	protected:
		~CustomerCurrentOrder()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnFinalizeOrderCustomer;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::TextBox^ txtboxOrdersCustomer;
	private: System::Windows::Forms::TextBox^ txtboxTotalPrice;
		   // newly added
		   System::String^ customerID;
		   FoodMenu* menu;
	private: System::Windows::Forms::Button^ btnRemoveAllOrder;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CustomerCurrentOrder::typeid));
			this->btnFinalizeOrderCustomer = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->txtboxOrdersCustomer = (gcnew System::Windows::Forms::TextBox());
			this->txtboxTotalPrice = (gcnew System::Windows::Forms::TextBox());
			this->btnRemoveAllOrder = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnFinalizeOrderCustomer
			// 
			this->btnFinalizeOrderCustomer->BackColor = System::Drawing::Color::Transparent;
			this->btnFinalizeOrderCustomer->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnFinalizeOrderCustomer->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnFinalizeOrderCustomer->Location = System::Drawing::Point(539, 616);
			this->btnFinalizeOrderCustomer->Name = L"btnFinalizeOrderCustomer";
			this->btnFinalizeOrderCustomer->Size = System::Drawing::Size(178, 59);
			this->btnFinalizeOrderCustomer->TabIndex = 7;
			this->btnFinalizeOrderCustomer->UseVisualStyleBackColor = false;
			this->btnFinalizeOrderCustomer->Click += gcnew System::EventHandler(this, &CustomerCurrentOrder::btnFinalizeOrderCustomer_Click);
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::Color::Transparent;
			this->btnBack->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBack->Location = System::Drawing::Point(45, 33);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(38, 38);
			this->btnBack->TabIndex = 8;
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &CustomerCurrentOrder::btnBack_Click_1);
			// 
			// txtboxOrdersCustomer
			// 
			this->txtboxOrdersCustomer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(77)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->txtboxOrdersCustomer->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 15.75F, System::Drawing::FontStyle::Bold));
			this->txtboxOrdersCustomer->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(127)));
			this->txtboxOrdersCustomer->Location = System::Drawing::Point(71, 190);
			this->txtboxOrdersCustomer->Multiline = true;
			this->txtboxOrdersCustomer->Name = L"txtboxOrdersCustomer";
			this->txtboxOrdersCustomer->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtboxOrdersCustomer->Size = System::Drawing::Size(1116, 405);
			this->txtboxOrdersCustomer->TabIndex = 9;
			this->txtboxOrdersCustomer->TextChanged += gcnew System::EventHandler(this, &CustomerCurrentOrder::txtboxOrders_TextChanged);
			// 
			// txtboxTotalPrice
			// 
			this->txtboxTotalPrice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(77)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->txtboxTotalPrice->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtboxTotalPrice->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(127)));
			this->txtboxTotalPrice->Location = System::Drawing::Point(71, 616);
			this->txtboxTotalPrice->Name = L"txtboxTotalPrice";
			this->txtboxTotalPrice->Size = System::Drawing::Size(201, 30);
			this->txtboxTotalPrice->TabIndex = 10;
			this->txtboxTotalPrice->Text = L"Total Price: PHP";
			// 
			// btnRemoveAllOrder
			// 
			this->btnRemoveAllOrder->BackColor = System::Drawing::Color::Transparent;
			this->btnRemoveAllOrder->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnRemoveAllOrder->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRemoveAllOrder->Location = System::Drawing::Point(1052, 623);
			this->btnRemoveAllOrder->Name = L"btnRemoveAllOrder";
			this->btnRemoveAllOrder->Size = System::Drawing::Size(129, 39);
			this->btnRemoveAllOrder->TabIndex = 11;
			this->btnRemoveAllOrder->UseVisualStyleBackColor = false;
			this->btnRemoveAllOrder->Click += gcnew System::EventHandler(this, &CustomerCurrentOrder::btnRemoveAllOrder_Click);
			// 
			// CustomerCurrentOrder
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1255, 706);
			this->Controls->Add(this->btnRemoveAllOrder);
			this->Controls->Add(this->txtboxTotalPrice);
			this->Controls->Add(this->txtboxOrdersCustomer);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btnFinalizeOrderCustomer);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CustomerCurrentOrder";
			this->Text = L"CustomerCurrentOrder";
			this->Load += gcnew System::EventHandler(this, &CustomerCurrentOrder::CustomerCurrentOrder_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CustomerCurrentOrder_Load(System::Object^ sender, System::EventArgs^ e) {
		// Convert System::String^ to std::string
		using namespace System::Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(customerID)).ToPointer();
		std::string customerIDStr = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));

		// Get the orders for the specific customer
		const auto& orders = Orders::Instance().GetOrdersForCustomer(customerIDStr);

		// Print the orders
		System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
		double totalPrice = 0.0;
		for (const auto& order : orders) {
			sb->AppendLine(gcnew System::String(
				(order.schoolID + ", " + order.foodName + ", " + std::to_string(order.quantity) + ", PHP" +
					std::to_string(order.price).substr(0, std::to_string(order.price).find(".") + 3)).c_str()));
			totalPrice += order.price;
		}

		// Display the orders in txtboxOrdersCustomer
		txtboxOrdersCustomer->Text = sb->ToString();
		txtboxTotalPrice->Text = "Total Price: PHP " + totalPrice.ToString("F2");
	}

	private: System::Void btnBack_Click_1(System::Object^ sender, System::EventArgs^ e) {
		this->Close();

	}
	private: System::Void txtboxOrders_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnFinalizeOrderCustomer_Click(System::Object^ sender, System::EventArgs^ e) {
		// Check if the order is empty
		if (String::IsNullOrWhiteSpace(txtboxOrdersCustomer->Text)) {
			MessageBox::Show(
				"No orders to finalize. Please add items to your order before finalizing.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		// Display a confirmation message box
		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Are you sure you want to finalize the order? Make sure you are sure before finalizing. There is no option to go back.",
			"Confirm Finalization",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Warning
		);

		// Check the user's response
		if (result == System::Windows::Forms::DialogResult::Yes) {
			// User chose to continue, proceed with finalization
			System::String^ ordersText = txtboxOrdersCustomer->Text;
			double totalPrice = Convert::ToDouble(txtboxTotalPrice->Text->Replace("Total Price: PHP ", ""));

			// Extract schoolID, foodName, and quantity from the orders
			using namespace System::Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(customerID)).ToPointer();
			std::string customerIDStr = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));

			const auto& orders = Orders::Instance().GetOrdersForCustomer(customerIDStr);
			if (!orders.empty()) {
				const auto& order = orders.front(); // Assuming you want the first order
				System::String^ schoolID = gcnew System::String(order.schoolID.c_str());
				System::String^ foodName = gcnew System::String(order.foodName.c_str());
				int quantity = order.quantity;

				CouponForm^ couponForm = gcnew CouponForm(ordersText, totalPrice, schoolID, foodName, quantity);
				couponForm->Show();
			}

			ResetOrdersTextBox();
			ResetTotalPriceTextBox();
		}
		else {
			// User chose not to continue, do nothing
		}
	}

	
	private: System::Void btnRemoveAllOrder_Click(System::Object^ sender, System::EventArgs^ e) {
		// Display a confirmation message box
		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Are you sure you want to remove all orders? This action cannot be undone.",
			"Confirm Removal",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Warning
		);

		// Check the user's response
		if (result == System::Windows::Forms::DialogResult::Yes) {
			// User chose to continue, proceed with removal
			using namespace System::Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(customerID)).ToPointer();
			std::string customerIDStr = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));

			Orders::Instance().RemoveAllOrdersForCustomer(customerIDStr);
			ResetOrdersTextBox();
			ResetTotalPriceTextBox();
		}
		else {
			// User chose not to continue, do nothing
		}
	}
	};
}
