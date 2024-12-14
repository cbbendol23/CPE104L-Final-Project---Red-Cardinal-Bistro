#pragma once

#include "FoodMenu.h"
#include "Utils.h" // Include Utils to use ConvertString method
#include "Orders.h" // Include Orders to use Orders::Instance
#include <iomanip>
#include <sstream>

namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddtOrderForm
	/// </summary>
	public ref class AddtOrderForm : public System::Windows::Forms::Form
	{
	public:
		AddtOrderForm(System::String^ id)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
			this->schoolID = id;
		}

	protected:
		~AddtOrderForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;
		System::Windows::Forms::FlowLayoutPanel^ panel;
		System::String^ schoolID;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// panel
			// 
			this->panel->AutoScroll = true;
			this->panel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->panel->Location = System::Drawing::Point(10, 10);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(420, 380);
			this->panel->TabIndex = 0;
			// 
			// AddtOrderForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(444, 398);
			this->Controls->Add(this->panel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"AddtOrderForm";
			this->Text = L"AddtOrderForm";
			this->Load += gcnew System::EventHandler(this, &AddtOrderForm::AddtOrderForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void AddtOrderForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// Access the FoodMenu instance
		auto& foodMenu = RedCardinalBistro::FoodMenu::Instance();
		auto foodItems = foodMenu.getFoodItems();

		// List of items to exclude
		std::vector<std::string> excludedItems = {
			"Menudo", "Fried Chicken", "Ice Cream", "Mango Sago",
			"Liempo", "Plain Rice", "Bottled Water", "Coke"
		};

		// Check if there are any items to display
		bool hasNewItems = false;
		for (const auto& item : foodItems) {
			if (std::find(excludedItems.begin(), excludedItems.end(), item.first) == excludedItems.end()) {
				hasNewItems = true;
				break;
			}
		}

		if (!hasNewItems) {
			Label^ noItemsLabel = gcnew Label();
			noItemsLabel->Text = "No New Menu Item has been added";
			noItemsLabel->AutoSize = true;
			noItemsLabel->Font = gcnew System::Drawing::Font("Arial", 15);
			this->panel->Controls->Add(noItemsLabel);
		}
		else {
			for (const auto& item : foodItems) {
				if (std::find(excludedItems.begin(), excludedItems.end(), item.first) == excludedItems.end()) {
					// Create a new FlowLayoutPanel for each item
					FlowLayoutPanel^ itemPanel = gcnew FlowLayoutPanel();
					itemPanel->FlowDirection = System::Windows::Forms::FlowDirection::LeftToRight;
					itemPanel->AutoSize = true;

					// Create and configure the label
					Label^ label = gcnew Label();
					std::ostringstream oss;
					oss << item.first << ": " << std::fixed << std::setprecision(2) << item.second;
					label->Text = gcnew String(oss.str().c_str());
					label->AutoSize = true;
					label->Font = gcnew System::Drawing::Font("Arial", 15);

					// Create and configure the button
					Button^ button = gcnew Button();
					button->Text = "Order";
					button->AutoSize = true;
					button->Click += gcnew System::EventHandler(this, &AddtOrderForm::OnOrderButtonClick);

					// Store item details in the button's Tag property
					button->Tag = gcnew Tuple<String^, double>(gcnew String(item.first.c_str()), item.second);

					// Add the label and button to the item panel
					itemPanel->Controls->Add(label);
					itemPanel->Controls->Add(button);

					// Add the item panel to the main panel
					this->panel->Controls->Add(itemPanel);
				}
			}
		}
	}

		   // Dynamic button click handler
	private: System::Void OnOrderButtonClick(System::Object^ sender, System::EventArgs^ e) {
		Button^ button = safe_cast<Button^>(sender);
		auto itemDetails = safe_cast<Tuple<String^, double>^>(button->Tag);

		String^ itemName = itemDetails->Item1;
		double itemPrice = itemDetails->Item2;

		std::string schoolIDStr = Utils::ConvertString(schoolID);
		std::string itemNameStr = Utils::ConvertString(itemName);
		Orders::Instance().AddOrder(schoolIDStr, itemNameStr, 1, itemPrice);
		MessageBox::Show(itemName + " has been added to your order!", "Order Added", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	};
}
