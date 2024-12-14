#pragma once
#include "FoodMenu.h"
#include "CustomerForm.h"
#include "CurrentOrderForm.h"
#include "AddItem.h"
#include "AddCouponForm.h"
#include "UpdateCouponForm1.h"
#include "RemoveCoupon.h"
#include "CouponCodes.h"
#include "DiscountOrderForm.h"
#include "DeleteItem.h"

namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminForm
	/// </summary>
	public ref class AdminForm : public System::Windows::Forms::Form
	{
	public:
		AdminForm(void)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
			this->menu = &FoodMenu::Instance();
		}

		// newly added
	private:
		FoodMenu* menu;
		String^ couponCode;
		CouponManager* couponManager = &CouponManager::getInstance();
		FoodMenu* foodMenu = &FoodMenu::Instance();

	private: System::Windows::Forms::Button^ btnRemoveItem;
	private: System::Windows::Forms::Button^ btnAddItem;

	private: System::Windows::Forms::Button^ btnAddCoupon;
	private: System::Windows::Forms::Button^ btnUpdateCoupon;
	private: System::Windows::Forms::Button^ btnRemoveCoupon;
	private: System::Windows::Forms::Button^ btnBackFromCoupon;
	private: System::Windows::Forms::Button^ btnExitProgram;
	private: System::Windows::Forms::Button^ btnLoadCoupon;
	private: System::Windows::Forms::Button^ btnSaveCoupon;
	private: System::Windows::Forms::Button^ btnSaveMenu;
	private: System::Windows::Forms::Button^ btnLoadMenu;
	private: System::Windows::Forms::Button^ btnSaveOrders;
	private: System::Windows::Forms::Button^ btnViewDiscountedOrders;

		   CustomerForm^ customerForm;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnShowOrderAdminSide;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminForm::typeid));
			this->btnShowOrderAdminSide = (gcnew System::Windows::Forms::Button());
			this->btnRemoveItem = (gcnew System::Windows::Forms::Button());
			this->btnAddItem = (gcnew System::Windows::Forms::Button());
			this->btnAddCoupon = (gcnew System::Windows::Forms::Button());
			this->btnUpdateCoupon = (gcnew System::Windows::Forms::Button());
			this->btnRemoveCoupon = (gcnew System::Windows::Forms::Button());
			this->btnBackFromCoupon = (gcnew System::Windows::Forms::Button());
			this->btnExitProgram = (gcnew System::Windows::Forms::Button());
			this->btnLoadCoupon = (gcnew System::Windows::Forms::Button());
			this->btnSaveCoupon = (gcnew System::Windows::Forms::Button());
			this->btnSaveMenu = (gcnew System::Windows::Forms::Button());
			this->btnLoadMenu = (gcnew System::Windows::Forms::Button());
			this->btnSaveOrders = (gcnew System::Windows::Forms::Button());
			this->btnViewDiscountedOrders = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnShowOrderAdminSide
			// 
			this->btnShowOrderAdminSide->BackColor = System::Drawing::Color::Transparent;
			this->btnShowOrderAdminSide->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnShowOrderAdminSide->Location = System::Drawing::Point(85, 537);
			this->btnShowOrderAdminSide->Name = L"btnShowOrderAdminSide";
			this->btnShowOrderAdminSide->Size = System::Drawing::Size(154, 46);
			this->btnShowOrderAdminSide->TabIndex = 9;
			this->btnShowOrderAdminSide->UseVisualStyleBackColor = false;
			this->btnShowOrderAdminSide->Click += gcnew System::EventHandler(this, &AdminForm::btnShowOrderAdminSide_Click);
			// 
			// btnRemoveItem
			// 
			this->btnRemoveItem->BackColor = System::Drawing::Color::Transparent;
			this->btnRemoveItem->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRemoveItem->Location = System::Drawing::Point(582, 553);
			this->btnRemoveItem->Name = L"btnRemoveItem";
			this->btnRemoveItem->Size = System::Drawing::Size(154, 46);
			this->btnRemoveItem->TabIndex = 10;
			this->btnRemoveItem->UseVisualStyleBackColor = false;
			this->btnRemoveItem->Click += gcnew System::EventHandler(this, &AdminForm::btnRemoveItem_Click);
			// 
			// btnAddItem
			// 
			this->btnAddItem->BackColor = System::Drawing::Color::Transparent;
			this->btnAddItem->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnAddItem->Location = System::Drawing::Point(582, 485);
			this->btnAddItem->Name = L"btnAddItem";
			this->btnAddItem->Size = System::Drawing::Size(154, 50);
			this->btnAddItem->TabIndex = 11;
			this->btnAddItem->UseVisualStyleBackColor = false;
			this->btnAddItem->Click += gcnew System::EventHandler(this, &AdminForm::btnAddItem_Click);
			// 
			// btnAddCoupon
			// 
			this->btnAddCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnAddCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnAddCoupon->Location = System::Drawing::Point(1009, 470);
			this->btnAddCoupon->Name = L"btnAddCoupon";
			this->btnAddCoupon->Size = System::Drawing::Size(154, 46);
			this->btnAddCoupon->TabIndex = 13;
			this->btnAddCoupon->UseVisualStyleBackColor = false;
			this->btnAddCoupon->Click += gcnew System::EventHandler(this, &AdminForm::btnAddCoupon_Click);
			// 
			// btnUpdateCoupon
			// 
			this->btnUpdateCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnUpdateCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnUpdateCoupon->Location = System::Drawing::Point(830, 537);
			this->btnUpdateCoupon->Name = L"btnUpdateCoupon";
			this->btnUpdateCoupon->Size = System::Drawing::Size(154, 46);
			this->btnUpdateCoupon->TabIndex = 14;
			this->btnUpdateCoupon->UseVisualStyleBackColor = false;
			this->btnUpdateCoupon->Click += gcnew System::EventHandler(this, &AdminForm::btnUpdateCoupon_Click);
			// 
			// btnRemoveCoupon
			// 
			this->btnRemoveCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnRemoveCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRemoveCoupon->Location = System::Drawing::Point(830, 604);
			this->btnRemoveCoupon->Name = L"btnRemoveCoupon";
			this->btnRemoveCoupon->Size = System::Drawing::Size(154, 46);
			this->btnRemoveCoupon->TabIndex = 15;
			this->btnRemoveCoupon->UseVisualStyleBackColor = false;
			this->btnRemoveCoupon->Click += gcnew System::EventHandler(this, &AdminForm::btnRemoveCoupon_Click);
			// 
			// btnBackFromCoupon
			// 
			this->btnBackFromCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnBackFromCoupon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnBackFromCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBackFromCoupon->Location = System::Drawing::Point(44, 32);
			this->btnBackFromCoupon->Name = L"btnBackFromCoupon";
			this->btnBackFromCoupon->Size = System::Drawing::Size(38, 38);
			this->btnBackFromCoupon->TabIndex = 16;
			this->btnBackFromCoupon->UseVisualStyleBackColor = false;
			this->btnBackFromCoupon->Click += gcnew System::EventHandler(this, &AdminForm::btnBackFromCoupon_Click);
			// 
			// btnExitProgram
			// 
			this->btnExitProgram->BackColor = System::Drawing::Color::Transparent;
			this->btnExitProgram->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnExitProgram->Location = System::Drawing::Point(50, 247);
			this->btnExitProgram->Name = L"btnExitProgram";
			this->btnExitProgram->Size = System::Drawing::Size(64, 63);
			this->btnExitProgram->TabIndex = 17;
			this->btnExitProgram->UseVisualStyleBackColor = false;
			this->btnExitProgram->Click += gcnew System::EventHandler(this, &AdminForm::btnExitProgram_Click);
			// 
			// btnLoadCoupon
			// 
			this->btnLoadCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnLoadCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnLoadCoupon->Location = System::Drawing::Point(1009, 537);
			this->btnLoadCoupon->Name = L"btnLoadCoupon";
			this->btnLoadCoupon->Size = System::Drawing::Size(154, 46);
			this->btnLoadCoupon->TabIndex = 18;
			this->btnLoadCoupon->UseVisualStyleBackColor = false;
			this->btnLoadCoupon->Click += gcnew System::EventHandler(this, &AdminForm::btnLoadCoupon_Click);
			// 
			// btnSaveCoupon
			// 
			this->btnSaveCoupon->BackColor = System::Drawing::Color::Transparent;
			this->btnSaveCoupon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSaveCoupon->Location = System::Drawing::Point(829, 470);
			this->btnSaveCoupon->Name = L"btnSaveCoupon";
			this->btnSaveCoupon->Size = System::Drawing::Size(154, 46);
			this->btnSaveCoupon->TabIndex = 19;
			this->btnSaveCoupon->UseVisualStyleBackColor = false;
			this->btnSaveCoupon->Click += gcnew System::EventHandler(this, &AdminForm::btnSaveCoupon_Click);
			// 
			// btnSaveMenu
			// 
			this->btnSaveMenu->BackColor = System::Drawing::Color::Transparent;
			this->btnSaveMenu->Cursor = System::Windows::Forms::Cursors::Default;
			this->btnSaveMenu->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSaveMenu->Location = System::Drawing::Point(334, 485);
			this->btnSaveMenu->Name = L"btnSaveMenu";
			this->btnSaveMenu->Size = System::Drawing::Size(154, 48);
			this->btnSaveMenu->TabIndex = 20;
			this->btnSaveMenu->UseVisualStyleBackColor = false;
			this->btnSaveMenu->Click += gcnew System::EventHandler(this, &AdminForm::btnSaveMenu_Click);
			// 
			// btnLoadMenu
			// 
			this->btnLoadMenu->BackColor = System::Drawing::Color::Transparent;
			this->btnLoadMenu->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnLoadMenu->Location = System::Drawing::Point(334, 553);
			this->btnLoadMenu->Name = L"btnLoadMenu";
			this->btnLoadMenu->Size = System::Drawing::Size(154, 46);
			this->btnLoadMenu->TabIndex = 21;
			this->btnLoadMenu->UseVisualStyleBackColor = false;
			this->btnLoadMenu->Click += gcnew System::EventHandler(this, &AdminForm::btnLoadMenu_Click);
			// 
			// btnSaveOrders
			// 
			this->btnSaveOrders->BackColor = System::Drawing::Color::Transparent;
			this->btnSaveOrders->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSaveOrders->Location = System::Drawing::Point(85, 603);
			this->btnSaveOrders->Name = L"btnSaveOrders";
			this->btnSaveOrders->Size = System::Drawing::Size(154, 46);
			this->btnSaveOrders->TabIndex = 22;
			this->btnSaveOrders->UseVisualStyleBackColor = false;
			this->btnSaveOrders->Click += gcnew System::EventHandler(this, &AdminForm::btnSaveOrders_Click);
			// 
			// btnViewDiscountedOrders
			// 
			this->btnViewDiscountedOrders->BackColor = System::Drawing::Color::Transparent;
			this->btnViewDiscountedOrders->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnViewDiscountedOrders->Location = System::Drawing::Point(85, 470);
			this->btnViewDiscountedOrders->Name = L"btnViewDiscountedOrders";
			this->btnViewDiscountedOrders->Size = System::Drawing::Size(154, 46);
			this->btnViewDiscountedOrders->TabIndex = 23;
			this->btnViewDiscountedOrders->UseVisualStyleBackColor = false;
			this->btnViewDiscountedOrders->Click += gcnew System::EventHandler(this, &AdminForm::btnViewDiscountedOrders_Click);
			// 
			// AdminForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1255, 706);
			this->Controls->Add(this->btnViewDiscountedOrders);
			this->Controls->Add(this->btnSaveOrders);
			this->Controls->Add(this->btnLoadMenu);
			this->Controls->Add(this->btnSaveMenu);
			this->Controls->Add(this->btnSaveCoupon);
			this->Controls->Add(this->btnLoadCoupon);
			this->Controls->Add(this->btnExitProgram);
			this->Controls->Add(this->btnBackFromCoupon);
			this->Controls->Add(this->btnRemoveCoupon);
			this->Controls->Add(this->btnUpdateCoupon);
			this->Controls->Add(this->btnAddCoupon);
			this->Controls->Add(this->btnAddItem);
			this->Controls->Add(this->btnRemoveItem);
			this->Controls->Add(this->btnShowOrderAdminSide);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AdminForm";
			this->Text = L"AdminForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnShowOrderAdminSide_Click(System::Object^ sender, System::EventArgs^ e) {


		CurrentOrderForm^ currentorderForm = gcnew CurrentOrderForm();

		currentorderForm->ShowDialog();
	}
	private: System::Void btnAddItem_Click(System::Object^ sender, System::EventArgs^ e) {
		AddItem^ addItemForm = gcnew AddItem(menu, customerForm);
		addItemForm->ShowDialog();
	}
	private: System::Void btnAddCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		AddCouponForm^ addOpenForm = gcnew AddCouponForm();
		addOpenForm->ShowDialog();
	}
	private: System::Void btnUpdateItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnUpdateCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		UpdateCouponForm1^ updateCouponForm1 = gcnew UpdateCouponForm1();
		updateCouponForm1->ShowDialog();
	}
	private: System::Void btnRemoveItem_Click(System::Object^ sender, System::EventArgs^ e) {
		DeleteItem^ deleteItemForm = gcnew DeleteItem();
		deleteItemForm->ShowDialog();
	}
	private: System::Void btnRemoveCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		RemoveCoupon^ removeCouponForm = gcnew RemoveCoupon();
		removeCouponForm->ShowDialog();
	}
	private: System::Void btnBackFromCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnExitProgram_Click(System::Object^ sender, System::EventArgs^ e) {

		Application::Exit();
	}
	private: System::Void btnSaveCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string directory = "C:\\CSV FILES\\";
		couponManager->SaveCouponsToCSV(directory);
		MessageBox::Show("Coupon saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void btnLoadCoupon_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string directory = "C:\\CSV FILES\\";
		couponManager->LoadCouponsFromCSV(directory);
		MessageBox::Show("Coupon loaded successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void btnSaveMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			std::string filePath = "C:\\CSV FILES\\";
			foodMenu->SaveMenuToCSV(filePath);
			MessageBox::Show("Menu saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (const std::exception& ex) {
			MessageBox::Show(gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnLoadMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			std::string directory = "C:\\CSV FILES\\";
			foodMenu->LoadMenuFromCSV(directory);
			MessageBox::Show("Menu loaded successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (const std::exception& ex) {
			MessageBox::Show(gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnSaveOrders_Click(System::Object^ sender, System::EventArgs^ e) {
		RedCardinalBistro::CurrentOrderForm^ currentOrderForm = gcnew RedCardinalBistro::CurrentOrderForm();

		currentOrderForm->SaveOrdersToCSV();

		MessageBox::Show("Orders saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void btnViewDiscountedOrders_Click(System::Object^ sender, System::EventArgs^ e) {
		RedCardinalBistro::DiscountOrderForm^ discountOrderForm = gcnew RedCardinalBistro::DiscountOrderForm();

		discountOrderForm->ShowDialog();
	}
	};
}
