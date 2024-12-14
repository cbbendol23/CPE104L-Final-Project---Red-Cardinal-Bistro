#pragma once
#include "AdminFunction.h"
#include "FoodMenu.h"
#include "CustomerForm.h"
#include <msclr/marshal_cppstd.h>
#include "QuickSort.h"
#include "iomanip"
#include <sstream>

namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DeleteItem
	/// </summary>
	public ref class DeleteItem : public System::Windows::Forms::Form
	{
	public:
		DeleteItem(void)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
			this->menu = &FoodMenu::Instance();
			//displayFoodItemsInMessageBox();
			this->customerForm = customerForm;
		}

		void saveMenuItem() {
			std::string filePath = "C:\\CSV FILES\\";
			menu->SaveMenuToCSV(filePath);
			MessageBox::Show("Menu Item removed successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DeleteItem()
		{
			if (components)
			{
				delete components;
			}
		}


	private: FoodMenu* menu;
		   CustomerForm^ customerForm;
	private: System::Windows::Forms::TextBox^ txtBoxEnterRemoveItem;
	private: System::Windows::Forms::Button^ btnDeleteItem;

	private: System::Windows::Forms::Button^ btnViewCurrentOrder;
	private: System::Windows::Forms::Button^ btnBack;
		   /*
		   void displayFoodItemsInMessageBox() {
			   std::string foodItemsStr = menu->getFoodItemsAsString();
			   String^ foodItemsManagedStr = gcnew String(foodItemsStr.c_str());
			   MessageBox::Show(foodItemsManagedStr, "Food Items");
		   }*/
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DeleteItem::typeid));
			this->txtBoxEnterRemoveItem = (gcnew System::Windows::Forms::TextBox());
			this->btnDeleteItem = (gcnew System::Windows::Forms::Button());
			this->btnViewCurrentOrder = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtBoxEnterRemoveItem
			// 
			this->txtBoxEnterRemoveItem->BackColor = System::Drawing::SystemColors::MenuText;
			this->txtBoxEnterRemoveItem->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 26.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtBoxEnterRemoveItem->ForeColor = System::Drawing::Color::White;
			this->txtBoxEnterRemoveItem->Location = System::Drawing::Point(558, 325);
			this->txtBoxEnterRemoveItem->Multiline = true;
			this->txtBoxEnterRemoveItem->Name = L"txtBoxEnterRemoveItem";
			this->txtBoxEnterRemoveItem->Size = System::Drawing::Size(372, 67);
			this->txtBoxEnterRemoveItem->TabIndex = 18;
			// 
			// btnDeleteItem
			// 
			this->btnDeleteItem->BackColor = System::Drawing::Color::Transparent;
			this->btnDeleteItem->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnDeleteItem->Location = System::Drawing::Point(550, 543);
			this->btnDeleteItem->Name = L"btnDeleteItem";
			this->btnDeleteItem->Size = System::Drawing::Size(168, 51);
			this->btnDeleteItem->TabIndex = 20;
			this->btnDeleteItem->UseVisualStyleBackColor = false;
			this->btnDeleteItem->Click += gcnew System::EventHandler(this, &DeleteItem::btnDeleteItem_Click);
			// 
			// btnViewCurrentOrder
			// 
			this->btnViewCurrentOrder->BackColor = System::Drawing::Color::Transparent;
			this->btnViewCurrentOrder->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnViewCurrentOrder->Location = System::Drawing::Point(19, 536);
			this->btnViewCurrentOrder->Name = L"btnViewCurrentOrder";
			this->btnViewCurrentOrder->Size = System::Drawing::Size(167, 117);
			this->btnViewCurrentOrder->TabIndex = 21;
			this->btnViewCurrentOrder->UseVisualStyleBackColor = false;
			this->btnViewCurrentOrder->Click += gcnew System::EventHandler(this, &DeleteItem::btnViewCurrentOrder_Click);
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::Color::Transparent;
			this->btnBack->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBack->Location = System::Drawing::Point(45, 32);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(38, 38);
			this->btnBack->TabIndex = 22;
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &DeleteItem::btnBack_Click);
			// 
			// DeleteItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1271, 715);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btnViewCurrentOrder);
			this->Controls->Add(this->btnDeleteItem);
			this->Controls->Add(this->txtBoxEnterRemoveItem);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"DeleteItem";
			this->Text = L"DeleteItem";
			this->Load += gcnew System::EventHandler(this, &DeleteItem::DeleteItem_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DeleteItem_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void btnViewCurrentOrder_Click(System::Object^ sender, System::EventArgs^ e) {
		auto foodItems = menu->getFoodItems();
		std::vector<std::pair<std::string, double>> itemsList(foodItems.begin(), foodItems.end());

		// Sort the items by name using quicksort
		quickSortPrice(itemsList, 0, itemsList.size() - 1);

		std::ostringstream itemsListStr;
		itemsListStr << std::fixed << std::setprecision(2); // Set precision for prices

		for (const auto& item : itemsList) {
			itemsListStr << item.first << ": " << item.second << "\n";
		}

		String^ message = gcnew String(itemsListStr.str().c_str());
		MessageBox::Show(message, "Current Food Items", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnDeleteItem_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string itemName = msclr::interop::marshal_as<std::string>(txtBoxEnterRemoveItem->Text);

		if (menu->removeFoodItem(itemName)) {
			saveMenuItem();
		}
		else {
			MessageBox::Show("Item not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		txtBoxEnterRemoveItem->Clear();

		this->Close();
	}
};
}
