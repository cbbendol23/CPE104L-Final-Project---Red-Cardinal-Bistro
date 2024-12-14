#pragma once
#include "Orders.h"
#include "CouponForm.h"
#include "CouponCodes.h"
#include "DiscountOrderForm.h"
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <sstream>
#include <algorithm>

namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class CurrentOrderForm : public System::Windows::Forms::Form
	{
	public:
		CurrentOrderForm(void)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
			this->menu = &FoodMenu::Instance();
			this->couponManager = &CouponManager::getInstance();
			System::String^ couponCode = SharedData::couponCode;
		}


	private: System::Windows::Forms::Button^ btnLoadOrder;
	public: String^ schoolID;



	protected:
		~CurrentOrderForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnBack;
	private: FoodMenu* menu;
	private: CouponManager* couponManager;
	private: System::String^ couponCode;
	private: System::Windows::Forms::TextBox^ txtboxOrders;

	protected:

	public:

		/*
		void SaveOrdersToCSV()
		{
			const auto& nonDiscountedOrders = Orders::Instance().GetNonDiscountedOrders();
			const auto& discountedOrders = Orders::Instance().GetDiscountedOrders();
			auto& couponManager = CouponManager::getInstance(); // Use the singleton instance

			// Specify the directory where you want to save the CSV file
			std::string directory = "D:\\";
			std::string filePath = directory + "orders.csv";

			std::ofstream file(filePath);
			if (!file.is_open()) {
				MessageBox::Show("Failed to open file for writing: " + gcnew System::String(filePath.c_str()));
				return;
			}

			file << "Non-Discounted Orders,,,,Discounted Orders\n";
			file << "SchoolID,FoodName,Quantity,Price,SchoolID,FoodName,Quantity,Price\n"; // CSV header

			msclr::interop::marshal_context context; // Create a marshal context

			size_t maxSize = (std::max)(static_cast<size_t>(nonDiscountedOrders.size()), static_cast<size_t>(discountedOrders.size()));

			for (size_t i = 0; i < maxSize; ++i) {
				if (i < nonDiscountedOrders.size()) {
					const auto& order = nonDiscountedOrders[i];
					file << "'" << order.schoolID << "," << order.foodName << "," << order.quantity << "," << order.price;
				}
				else {
					file << ",,,";
				}

				file << ",";

				if (i < discountedOrders.size()) {
					const auto& order = discountedOrders[i];
					double price = order.price;
					std::string usedCouponCode = "";
					if (!String::IsNullOrEmpty(couponCode)) {
						std::string couponCodeStdStr = context.marshal_as<std::string>(couponCode);
						if (couponManager.IsCouponCodeValid(couponCodeStdStr)) {
							int discountPercentage = couponManager.GetDiscountPercentage(couponCodeStdStr);
							double discountAmount = order.price * discountPercentage / 100.0;
							price = order.price - discountAmount;
						}
					}
					file << "'" << order.schoolID << "," << order.foodName << "," << order.quantity << "," << price << ",";
				}

				file << "\n";
			}

			file.close();
		}
*/
		void SaveOrdersToCSV()
		{
			// Create copies of the orders to ensure data integrity
			auto nonDiscountedOrders = Orders::Instance().GetNonDiscountedOrders();
			auto discountedOrders = Orders::Instance().GetDiscountedOrders();
			auto& couponManager = CouponManager::getInstance(); // Use the singleton instance

			// Specify the directory where you want to save the CSV file
			std::string directory = "C:\\CSV FILES\\";
			std::string filePath = directory + "orders.csv";

			std::ofstream file(filePath);
			if (!file.is_open()) {
				MessageBox::Show("Failed to open file for writing: " + gcnew System::String(filePath.c_str()));
				return;
			}

			file << "Non-Discounted Orders,,,,Discounted Orders\n";
			file << "SchoolID,FoodName,Quantity,Price,SchoolID,FoodName,Quantity,Price\n"; // CSV header

			msclr::interop::marshal_context context; // Create a marshal context

			size_t maxSize = (std::max)(static_cast<size_t>(nonDiscountedOrders.size()), static_cast<size_t>(discountedOrders.size())); // calculates the max size

			for (size_t i = 0; i < maxSize; ++i) {
				if (i < nonDiscountedOrders.size()) {
					const auto& order = nonDiscountedOrders[i];
					std::string schoolID = order.schoolID;
					if (schoolID.front() != '\'') { // ' is added to signify that the order is saved in csv
						schoolID = "'" + schoolID;
					}
					file << schoolID << "," << order.foodName << "," << order.quantity << "," << order.price;
				}
				else {
					file << ",,,"; // Fill empty columns for non-discounted orders
				}

				file << ",";

				if (i < discountedOrders.size()) {
					const auto& order = discountedOrders[i];
					double price = order.price;
					std::string usedCouponCode = "";
					if (!String::IsNullOrEmpty(couponCode)) {
						std::string couponCodeStdStr = context.marshal_as<std::string>(couponCode);
						if (couponManager.IsCouponCodeValid(couponCodeStdStr)) {
							int discountPercentage = couponManager.GetDiscountPercentage(couponCodeStdStr);
							double discountAmount = order.price * discountPercentage / 100.0;
							price = order.price - discountAmount;
						}
					}
					std::string schoolID = order.schoolID;
					if (schoolID.front() != '\'') {
						schoolID = "'" + schoolID;
					}
					file << schoolID << "," << order.foodName << "," << order.quantity << "," << price;
				}

				file << "\n";
			}

			file.close();
		}
		// CurrentOrderForm.h
		void LoadOrdersFromCSV(DiscountOrderForm^ discountForm)
		{
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Filter = "CSV files (*.csv)|*.csv|All files (*.*)|*.*";
			openFileDialog->Title = "Open Orders CSV File";

			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				std::string filePath = msclr::interop::marshal_as<std::string>(openFileDialog->FileName);

				std::ifstream file(filePath);
				if (!file.is_open()) {
					MessageBox::Show("Failed to open file: " + gcnew System::String(filePath.c_str()));
					return;
				}

				std::string line;
				System::Text::StringBuilder^ nonDiscountedSb = gcnew System::Text::StringBuilder();

				// Skip the header line
				std::getline(file, line);

				Orders& ordersInstance = Orders::Instance();

				while (std::getline(file, line)) {
					std::stringstream ss(line);
					std::string schoolID, foodName, quantityStr, priceStr, discountStatus;

					std::getline(ss, schoolID, ',');

					std::getline(ss, foodName, ',');
					std::getline(ss, quantityStr, ',');
					std::getline(ss, priceStr, ',');
					std::getline(ss, discountStatus, ','); // Assuming this is the last column

					try {
						int quantity = std::stoi(quantityStr);
						double price = std::stod(priceStr);

						System::String^ orderDetails = gcnew System::String((schoolID + ", " + foodName + ", " + quantityStr + ", PHP " + priceStr).c_str());

						if (discountStatus != "Discounted") {
							// Non-discounted orders go to CurrentOrderForm
							ordersInstance.AddOrder(schoolID, foodName, quantity, price);
							nonDiscountedSb->AppendLine(orderDetails);
						}
						else {
							// Discounted orders go to DiscountOrderForm
							discountForm->AddDiscountedOrder(orderDetails);
						}
					}
					catch (const std::invalid_argument&) {
						continue;
					}
					catch (const std::out_of_range&) {
						continue;
					}
				}

				file.close();
				txtboxOrders->Text = nonDiscountedSb->ToString();  // Display non-discounted orders
			}
		}

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CurrentOrderForm::typeid));
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->txtboxOrders = (gcnew System::Windows::Forms::TextBox());
			this->btnLoadOrder = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::Color::Transparent;
			this->btnBack->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBack->Location = System::Drawing::Point(45, 32);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(38, 38);
			this->btnBack->TabIndex = 1;
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &CurrentOrderForm::btnBack_Click);
			// 
			// txtboxOrders
			// 
			this->txtboxOrders->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(77)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->txtboxOrders->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 15.75F, System::Drawing::FontStyle::Bold));
			this->txtboxOrders->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)));
			this->txtboxOrders->Location = System::Drawing::Point(70, 189);
			this->txtboxOrders->Multiline = true;
			this->txtboxOrders->Name = L"txtboxOrders";
			this->txtboxOrders->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtboxOrders->Size = System::Drawing::Size(1116, 405);
			this->txtboxOrders->TabIndex = 7;
			this->txtboxOrders->TextChanged += gcnew System::EventHandler(this, &CurrentOrderForm::textBox1_TextChanged);
			// 
			// btnLoadOrder
			// 
			this->btnLoadOrder->BackColor = System::Drawing::Color::Transparent;
			this->btnLoadOrder->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnLoadOrder->Location = System::Drawing::Point(73, 605);
			this->btnLoadOrder->Name = L"btnLoadOrder";
			this->btnLoadOrder->Size = System::Drawing::Size(129, 40);
			this->btnLoadOrder->TabIndex = 8;
			this->btnLoadOrder->UseVisualStyleBackColor = false;
			this->btnLoadOrder->Click += gcnew System::EventHandler(this, &CurrentOrderForm::btnLoadOrder_Click);
			// 
			// CurrentOrderForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1255, 706);
			this->Controls->Add(this->btnLoadOrder);
			this->Controls->Add(this->txtboxOrders);
			this->Controls->Add(this->btnBack);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CurrentOrderForm";
			this->Text = L"CurrentOrderForm";
			this->Load += gcnew System::EventHandler(this, &CurrentOrderForm::CurrentOrderForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void CurrentOrderForm_Load(System::Object^ sender, System::EventArgs^ e) {
		const auto& orders = Orders::Instance().GetNonDiscountedOrders();
		System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();

		for (const auto& order : orders) {
			sb->AppendLine(gcnew System::String((order.schoolID + ", " + order.foodName + ", " + std::to_string(order.quantity) + ", PHP " + std::to_string(order.price)).c_str()));
		}

		txtboxOrders->Text = sb->ToString();

	}


	private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void lblCurrentOrders_Click(System::Object^ sender, System::EventArgs^ e) {
		// Handle the click event here
	}
	private: System::Void btnFinalizeOrder_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void hScrollBar1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {

	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void vScrollBar1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	}

	private: System::Void btnLoadOrder_Click(System::Object^ sender, System::EventArgs^ e) {
		DiscountOrderForm^ discountForm = gcnew DiscountOrderForm();
		LoadOrdersFromCSV(discountForm);  // Load order
	}
	};
}