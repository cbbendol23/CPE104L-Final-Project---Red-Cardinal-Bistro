#pragma once
#include "Orders.h"
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <sstream>
#include <iomanip>

namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DiscountOrderForm
	/// </summary>
	public ref class DiscountOrderForm : public System::Windows::Forms::Form
	{
	public:
		DiscountOrderForm(void)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
		}


		void AddDiscountedOrder(System::String^ orderDetails)
		{

			this->txtboxDiscountedOrders->AppendText(orderDetails + Environment::NewLine);
		}

		/*
		void LoadDiscountedOrdersFromCSV(DiscountOrderForm^ discountForm)
		{
			// Specify the directory where the CSV file is saved
			std::string directory = "C:\\CSV FILES\\";
			std::string filePath = directory + "orders.csv";

			std::ifstream file(filePath);
			if (!file.is_open()) {
				MessageBox::Show("Failed to open file: " + gcnew System::String(filePath.c_str()));
				return;
			}

			std::string line;
			System::Text::StringBuilder^ discountedSb = gcnew System::Text::StringBuilder();

			// Skip the first two header lines
			std::getline(file, line);
			std::getline(file, line);

			while (std::getline(file, line)) {
				std::stringstream ss(line);
				std::string schoolID, foodName, quantityStr, priceStr, dummy;

				// Skip non-discounted order columns
				std::getline(ss, dummy, ',');
				std::getline(ss, dummy, ',');
				std::getline(ss, dummy, ',');
				std::getline(ss, dummy, ',');

				// Read discounted order columns
				std::getline(ss, schoolID, ',');
				std::getline(ss, foodName, ',');
				std::getline(ss, quantityStr, ',');
				std::getline(ss, priceStr, ',');

				if (!schoolID.empty() && !foodName.empty() && !quantityStr.empty() && !priceStr.empty()) {
					try {
						int quantity = std::stoi(quantityStr);
						double price = std::stod(priceStr);

						System::String^ orderDetails = gcnew System::String((schoolID + ", " + foodName + ", " + quantityStr + ", PHP " + priceStr).c_str());
						discountForm->AddDiscountedOrder(orderDetails);
						discountedSb->AppendLine(orderDetails);

						// Push the order back to the vector using SaveDiscountedOrderNoDiscountRate
						Orders::Order order = { schoolID, foodName, quantity, price, true };
						Orders::Instance().SaveDiscountedOrderNoDiscountRate(order);
					}
					catch (const std::invalid_argument&) {
						continue;
					}
					catch (const std::out_of_range&) {
						continue;
					}
				}
			}

			file.close();
			discountForm->txtboxDiscountedOrders->Text = discountedSb->ToString();  // Display discounted orders
		}*/

		void LoadDiscountedOrdersFromCSV(DiscountOrderForm^ discountForm)
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
				System::Text::StringBuilder^ discountedSb = gcnew System::Text::StringBuilder();

				// Skip the first two header lines
				std::getline(file, line);
				std::getline(file, line);

				while (std::getline(file, line)) {
					std::stringstream ss(line);
					std::string schoolID, foodName, quantityStr, priceStr, dummy;

					// Skip non-discounted order columns
					std::getline(ss, dummy, ',');
					std::getline(ss, dummy, ',');
					std::getline(ss, dummy, ',');
					std::getline(ss, dummy, ',');

					// Read discounted order columns
					std::getline(ss, schoolID, ',');
					std::getline(ss, foodName, ',');
					std::getline(ss, quantityStr, ',');
					std::getline(ss, priceStr, ',');

					if (!schoolID.empty() && !foodName.empty() && !quantityStr.empty() && !priceStr.empty()) {
						try {
							int quantity = std::stoi(quantityStr);
							double price = std::stod(priceStr);

							if (schoolID.front() != '\'') {
								schoolID = "'" + schoolID;
							}

							System::String^ orderDetails = gcnew System::String((schoolID + ", " + foodName + ", " + quantityStr + ", PHP " + priceStr).c_str());
							discountForm->AddDiscountedOrder(orderDetails);
							discountedSb->AppendLine(orderDetails);

							// Push the order back to the vector using SaveDiscountedOrderNoDiscountRate
							Orders::Order order = { schoolID, foodName, quantity, price, true };
							Orders::Instance().SaveDiscountedOrderNoDiscountRate(order);
						}
						catch (const std::invalid_argument&) {
							continue;
						}
						catch (const std::out_of_range&) {
							continue;
						}
					}
				}

				file.close();
				discountForm->txtboxDiscountedOrders->Text = discountedSb->ToString();  // Display discounted orders
			}
		}




	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DiscountOrderForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtboxDiscountedOrders;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Button^ btnLoadDiscountedOrder;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DiscountOrderForm::typeid));
			this->txtboxDiscountedOrders = (gcnew System::Windows::Forms::TextBox());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnLoadDiscountedOrder = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtboxDiscountedOrders
			// 
			this->txtboxDiscountedOrders->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(77)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->txtboxDiscountedOrders->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 15.75F, System::Drawing::FontStyle::Bold));
			this->txtboxDiscountedOrders->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(127)));
			this->txtboxDiscountedOrders->Location = System::Drawing::Point(70, 190);
			this->txtboxDiscountedOrders->Multiline = true;
			this->txtboxDiscountedOrders->Name = L"txtboxDiscountedOrders";
			this->txtboxDiscountedOrders->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtboxDiscountedOrders->Size = System::Drawing::Size(1116, 405);
			this->txtboxDiscountedOrders->TabIndex = 8;
			this->txtboxDiscountedOrders->TextChanged += gcnew System::EventHandler(this, &DiscountOrderForm::txtboxDiscountedOrders_TextChanged);
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::Color::Transparent;
			this->btnBack->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBack->Location = System::Drawing::Point(45, 32);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(38, 38);
			this->btnBack->TabIndex = 9;
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &DiscountOrderForm::btnBack_Click);
			// 
			// btnLoadDiscountedOrder
			// 
			this->btnLoadDiscountedOrder->BackColor = System::Drawing::Color::Transparent;
			this->btnLoadDiscountedOrder->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnLoadDiscountedOrder->Location = System::Drawing::Point(73, 605);
			this->btnLoadDiscountedOrder->Name = L"btnLoadDiscountedOrder";
			this->btnLoadDiscountedOrder->Size = System::Drawing::Size(129, 40);
			this->btnLoadDiscountedOrder->TabIndex = 10;
			this->btnLoadDiscountedOrder->UseVisualStyleBackColor = false;
			this->btnLoadDiscountedOrder->Click += gcnew System::EventHandler(this, &DiscountOrderForm::btnLoadDiscountedOrder_Click);
			// 
			// DiscountOrderForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1255, 706);
			this->Controls->Add(this->btnLoadDiscountedOrder);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->txtboxDiscountedOrders);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"DiscountOrderForm";
			this->Text = L"DiscountOrderForm";
			this->Load += gcnew System::EventHandler(this, &DiscountOrderForm::DiscountOrderForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void txtboxDiscountedOrders_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void DiscountOrderForm_Load(System::Object^ sender, System::EventArgs^ e) {
		const auto& orders = Orders::Instance().GetDiscountedOrders();
		System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();

		for (const auto& order : orders) {
			std::ostringstream oss;
			oss << std::fixed << std::setprecision(2) << order.price; // Format price to 2 decimal places
			std::string priceStr = oss.str();
			sb->AppendLine(gcnew System::String((order.schoolID + ", " + order.foodName + ", " + std::to_string(order.quantity) + ", PHP " + priceStr).c_str()));
		}

		txtboxDiscountedOrders->Text = sb->ToString();

	}

	private: System::Void btnLoadDiscountedOrder_Click(System::Object^ sender, System::EventArgs^ e) {
		LoadDiscountedOrdersFromCSV(this);
	}
};
	
}




	