#pragma once

#include "AdminFunction.h"
#include "FoodMenu.h"
#include "CustomerForm.h"
#include "QuickSort.h" 
#include <msclr/marshal_cppstd.h>
#include <sstream>
#include <iomanip>

namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AddItem : public System::Windows::Forms::Form
	{
	public:
		AddItem(FoodMenu* menu, CustomerForm^ customerForm)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
			this->menu = &FoodMenu::Instance();
			this->customerForm = customerForm;
		}

		void saveMenuItem() {
			std::string filePath = "C:\\CSV FILES\\";
			menu->SaveMenuToCSV(filePath);
			MessageBox::Show("Menu saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	protected:
		~AddItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnAddItemToMenu;
	private: FoodMenu* menu;
		   CustomerForm^ customerForm;

	private: System::Windows::Forms::Button^ btnViewCurrentOrder;
	private: System::Windows::Forms::TextBox^ txtBoxEnterNewItem;
	private: System::Windows::Forms::TextBox^ txtboxEnterPrice;
	private: System::Windows::Forms::TextBox^ txtBoxEnterCategory;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddItem::typeid));
			this->btnAddItemToMenu = (gcnew System::Windows::Forms::Button());
			this->btnViewCurrentOrder = (gcnew System::Windows::Forms::Button());
			this->txtBoxEnterNewItem = (gcnew System::Windows::Forms::TextBox());
			this->txtboxEnterPrice = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxEnterCategory = (gcnew System::Windows::Forms::TextBox());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnAddItemToMenu
			// 
			this->btnAddItemToMenu->BackColor = System::Drawing::Color::Transparent;
			this->btnAddItemToMenu->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnAddItemToMenu->Location = System::Drawing::Point(542, 595);
			this->btnAddItemToMenu->Name = L"btnAddItemToMenu";
			this->btnAddItemToMenu->Size = System::Drawing::Size(165, 51);
			this->btnAddItemToMenu->TabIndex = 12;
			this->btnAddItemToMenu->UseVisualStyleBackColor = false;
			this->btnAddItemToMenu->Click += gcnew System::EventHandler(this, &AddItem::btnAddItemToMenu_Click);
			// 
			// btnViewCurrentOrder
			// 
			this->btnViewCurrentOrder->BackColor = System::Drawing::Color::Transparent;
			this->btnViewCurrentOrder->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnViewCurrentOrder->Location = System::Drawing::Point(19, 530);
			this->btnViewCurrentOrder->Name = L"btnViewCurrentOrder";
			this->btnViewCurrentOrder->Size = System::Drawing::Size(164, 114);
			this->btnViewCurrentOrder->TabIndex = 13;
			this->btnViewCurrentOrder->UseVisualStyleBackColor = false;
			this->btnViewCurrentOrder->Click += gcnew System::EventHandler(this, &AddItem::btnViewCurrentOrder_Click);
			// 
			// txtBoxEnterNewItem
			// 
			this->txtBoxEnterNewItem->BackColor = System::Drawing::SystemColors::MenuText;
			this->txtBoxEnterNewItem->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 26.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtBoxEnterNewItem->ForeColor = System::Drawing::Color::White;
			this->txtBoxEnterNewItem->Location = System::Drawing::Point(550, 306);
			this->txtBoxEnterNewItem->Multiline = true;
			this->txtBoxEnterNewItem->Name = L"txtBoxEnterNewItem";
			this->txtBoxEnterNewItem->Size = System::Drawing::Size(366, 67);
			this->txtBoxEnterNewItem->TabIndex = 14;
			this->txtBoxEnterNewItem->TextChanged += gcnew System::EventHandler(this, &AddItem::txtBoxCoupon_TextChanged);
			// 
			// txtboxEnterPrice
			// 
			this->txtboxEnterPrice->BackColor = System::Drawing::SystemColors::MenuText;
			this->txtboxEnterPrice->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtboxEnterPrice->ForeColor = System::Drawing::Color::White;
			this->txtboxEnterPrice->Location = System::Drawing::Point(550, 407);
			this->txtboxEnterPrice->Multiline = true;
			this->txtboxEnterPrice->Name = L"txtboxEnterPrice";
			this->txtboxEnterPrice->Size = System::Drawing::Size(366, 67);
			this->txtboxEnterPrice->TabIndex = 15;
			// 
			// txtBoxEnterCategory
			// 
			this->txtBoxEnterCategory->BackColor = System::Drawing::SystemColors::MenuText;
			this->txtBoxEnterCategory->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 26.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtBoxEnterCategory->ForeColor = System::Drawing::Color::White;
			this->txtBoxEnterCategory->Location = System::Drawing::Point(550, 496);
			this->txtBoxEnterCategory->Multiline = true;
			this->txtBoxEnterCategory->Name = L"txtBoxEnterCategory";
			this->txtBoxEnterCategory->Size = System::Drawing::Size(366, 67);
			this->txtBoxEnterCategory->TabIndex = 16;
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::Color::Transparent;
			this->btnBack->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBack->Location = System::Drawing::Point(44, 32);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(38, 38);
			this->btnBack->TabIndex = 17;
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &AddItem::btnBack_Click);
			// 
			// AddItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1255, 706);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->txtBoxEnterCategory);
			this->Controls->Add(this->txtboxEnterPrice);
			this->Controls->Add(this->txtBoxEnterNewItem);
			this->Controls->Add(this->btnViewCurrentOrder);
			this->Controls->Add(this->btnAddItemToMenu);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddItem";
			this->Text = L"AddItem";
			this->Load += gcnew System::EventHandler(this, &AddItem::AddItem_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void displayFoodItemsInMessageBox() {
			auto foodItems = menu->getFoodItems();
			std::vector<std::pair<std::string, double>> items(foodItems.begin(), foodItems.end());

			// Sort the items using QuickSort
			quickSortPrice(items, 0, items.size() - 1);

			std::ostringstream oss;
			for (const auto& item : items) {
				oss << item.first << ": " << std::fixed << std::setprecision(2) << item.second << "\n";
			}
			std::string foodItemsStr = oss.str();
			String^ foodItemsManagedStr = gcnew String(foodItemsStr.c_str());
			MessageBox::Show(foodItemsManagedStr, "Food Items");
		}


#pragma endregion
	private: System::Void AddItem_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void txtBoxCoupon_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	

	private: System::Void btnAddItemToMenu_Click(System::Object^ sender, System::EventArgs^ e)
	{

		if (menu->getFoodItemCount() >= 15) {
			MessageBox::Show("Maximum number of food items reached. Cannot add more items.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		String^ itemName = txtBoxEnterNewItem->Text;
		String^ itemPrice = txtboxEnterPrice->Text;
		String^ itemCategory = txtBoxEnterCategory->Text;
		
		if (itemCategory != "Beverage" && itemCategory != "Main Dish" && itemCategory != "Dessert") {
			MessageBox::Show("Invalid category. Please enter 'Beverage', 'Main Dish', or 'Dessert'.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			txtBoxEnterCategory->Text = "";
			return;
		}

		if (!String::IsNullOrEmpty(itemName) && !String::IsNullOrEmpty(itemPrice) && !String::IsNullOrEmpty(itemCategory)) {
			std::string name = msclr::interop::marshal_as<std::string>(itemName);
			double price = Convert::ToDouble(itemPrice);
			std::string category = msclr::interop::marshal_as<std::string>(itemCategory);

			// Check if the item already exists in the menu
			if (menu->foodItemExists(name)) {
				MessageBox::Show("The item already exists in the menu.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				txtBoxEnterNewItem->Text = "";
				txtboxEnterPrice->Text = "";
				txtBoxEnterCategory->Text = "";
				return;
			}

			menu->addFoodItem(name, price, category);
			displayFoodItemsInMessageBox(); // Refresh the MessageBox

			saveMenuItem();
		}
		else {
			MessageBox::Show("Please fill in all fields.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}


		this->Close();
	}

		   
	private: System::Void btnViewCurrentOrder_Click(System::Object^ sender, System::EventArgs^ e) {
		displayFoodItemsInMessageBox();
	}

	private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
