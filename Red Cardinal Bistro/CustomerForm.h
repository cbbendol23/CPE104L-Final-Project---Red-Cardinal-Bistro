#pragma once
#include "CategoryForm.h"
#include "FoodMenu.h"
#include "CurrentOrderForm.h"
#include "CustomerCurrentOrder.h"
#include "Orders.h"
#include <string>
#include "AdminFunction.h"
#include <msclr/marshal.h>
#include <vector>
#include <algorithm>
#include "AddtOrderForm.h"
#include "AbousUsForm1.h"

namespace RedCardinalBistro {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class CustomerForm : public System::Windows::Forms::Form
    {
    public:
        CustomerForm(String^ schoolID)
        {
            InitializeComponent();
            this->StartPosition = FormStartPosition::CenterScreen;
            this->schoolID = schoolID;
            this->menu = &FoodMenu::Instance();
            this->labelCount = 0;
 
        }


    private:
        String^ schoolID;
        FoodMenu* menu;
    private: System::Windows::Forms::Button^ btnViewMoreFood;
    private: System::Windows::Forms::Button^ btnAboutUs;
    private: System::Windows::Forms::Button^ btnOrderMenudo1;

           int labelCount;

           std::string ConvertString(System::String^ str)
           {
               if (str == nullptr)
                   return std::string();

               // Pin the System::String^ to prevent the garbage collector from moving it
               pin_ptr<const wchar_t> wch = PtrToStringChars(str);
               size_t convertedChars = 0;
               size_t sizeInBytes = ((str->Length + 1) * 2);
               errno_t err = 0;
               std::string os(sizeInBytes, '\0');
               wcstombs_s(&convertedChars, &os[0], sizeInBytes, wch, sizeInBytes);
               os.resize(convertedChars - 1); // Remove the null terminator
               return os;
           }

    protected:
        ~CustomerForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Button^ btnLogOut;


    private: System::Windows::Forms::Label^ lblChkPrice;
    private: System::Windows::Forms::Button^ btnOrderChk;
    private: System::Windows::Forms::Button^ btnMainDish;
    private: System::Windows::Forms::Button^ btnDeserts;
    private: System::Windows::Forms::Button^ btnBeverages;
    private: System::Windows::Forms::Button^ btnShowOrder;

    private: System::Windows::Forms::Button^ btnOrderLiempo;

    private: System::Windows::Forms::Button^ btnOrderRice;
    private: System::Windows::Forms::Button^ btnOrderIceCream;
    private: System::Windows::Forms::Button^ btnOrderBottledWater;
    private: System::Windows::Forms::Button^ btnOrderCoke;


    private: System::Windows::Forms::Button^ btnOrderMangoSago;



    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CustomerForm::typeid));
            this->btnLogOut = (gcnew System::Windows::Forms::Button());
            this->lblChkPrice = (gcnew System::Windows::Forms::Label());
            this->btnOrderChk = (gcnew System::Windows::Forms::Button());
            this->btnMainDish = (gcnew System::Windows::Forms::Button());
            this->btnDeserts = (gcnew System::Windows::Forms::Button());
            this->btnBeverages = (gcnew System::Windows::Forms::Button());
            this->btnShowOrder = (gcnew System::Windows::Forms::Button());
            this->btnOrderLiempo = (gcnew System::Windows::Forms::Button());
            this->btnOrderRice = (gcnew System::Windows::Forms::Button());
            this->btnOrderIceCream = (gcnew System::Windows::Forms::Button());
            this->btnOrderBottledWater = (gcnew System::Windows::Forms::Button());
            this->btnOrderCoke = (gcnew System::Windows::Forms::Button());
            this->btnOrderMangoSago = (gcnew System::Windows::Forms::Button());
            this->btnViewMoreFood = (gcnew System::Windows::Forms::Button());
            this->btnAboutUs = (gcnew System::Windows::Forms::Button());
            this->btnOrderMenudo1 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // btnLogOut
            // 
            this->btnLogOut->BackColor = System::Drawing::Color::Transparent;
            this->btnLogOut->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnLogOut->Location = System::Drawing::Point(49, 631);
            this->btnLogOut->Name = L"btnLogOut";
            this->btnLogOut->Size = System::Drawing::Size(149, 38);
            this->btnLogOut->TabIndex = 0;
            this->btnLogOut->UseVisualStyleBackColor = false;
            this->btnLogOut->Click += gcnew System::EventHandler(this, &CustomerForm::btnLogOut_Click);
            // 
            // lblChkPrice
            // 
            this->lblChkPrice->BackColor = System::Drawing::Color::Transparent;
            this->lblChkPrice->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblChkPrice->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
                static_cast<System::Int32>(static_cast<System::Byte>(38)));
            this->lblChkPrice->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
            this->lblChkPrice->Location = System::Drawing::Point(309, 277);
            this->lblChkPrice->Name = L"lblChkPrice";
            this->lblChkPrice->Size = System::Drawing::Size(59, 28);
            this->lblChkPrice->TabIndex = 3;
            this->lblChkPrice->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            this->lblChkPrice->Click += gcnew System::EventHandler(this, &CustomerForm::label1_Click_1);
            // 
            // btnOrderChk
            // 
            this->btnOrderChk->BackColor = System::Drawing::Color::Transparent;
            this->btnOrderChk->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnOrderChk->Location = System::Drawing::Point(400, 320);
            this->btnOrderChk->Name = L"btnOrderChk";
            this->btnOrderChk->Size = System::Drawing::Size(72, 37);
            this->btnOrderChk->TabIndex = 4;
            this->btnOrderChk->UseVisualStyleBackColor = false;
            this->btnOrderChk->Click += gcnew System::EventHandler(this, &CustomerForm::btnOrderChk_Click);
            // 
            // btnMainDish
            // 
            this->btnMainDish->BackColor = System::Drawing::Color::Transparent;
            this->btnMainDish->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnMainDish->ForeColor = System::Drawing::Color::Transparent;
            this->btnMainDish->Location = System::Drawing::Point(496, 60);
            this->btnMainDish->Name = L"btnMainDish";
            this->btnMainDish->Size = System::Drawing::Size(149, 38);
            this->btnMainDish->TabIndex = 5;
            this->btnMainDish->UseVisualStyleBackColor = false;
            this->btnMainDish->Click += gcnew System::EventHandler(this, &CustomerForm::btnMainDish_Click);
            // 
            // btnDeserts
            // 
            this->btnDeserts->BackColor = System::Drawing::Color::Transparent;
            this->btnDeserts->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnDeserts->Location = System::Drawing::Point(693, 60);
            this->btnDeserts->Name = L"btnDeserts";
            this->btnDeserts->Size = System::Drawing::Size(147, 38);
            this->btnDeserts->TabIndex = 6;
            this->btnDeserts->UseVisualStyleBackColor = false;
            this->btnDeserts->Click += gcnew System::EventHandler(this, &CustomerForm::btnDeserts_Click);
            // 
            // btnBeverages
            // 
            this->btnBeverages->BackColor = System::Drawing::Color::Transparent;
            this->btnBeverages->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnBeverages->Location = System::Drawing::Point(887, 60);
            this->btnBeverages->Name = L"btnBeverages";
            this->btnBeverages->Size = System::Drawing::Size(148, 38);
            this->btnBeverages->TabIndex = 7;
            this->btnBeverages->UseVisualStyleBackColor = false;
            this->btnBeverages->Click += gcnew System::EventHandler(this, &CustomerForm::btnBeverages_Click);
            // 
            // btnShowOrder
            // 
            this->btnShowOrder->BackColor = System::Drawing::Color::Transparent;
            this->btnShowOrder->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnShowOrder->Location = System::Drawing::Point(49, 488);
            this->btnShowOrder->Name = L"btnShowOrder";
            this->btnShowOrder->Size = System::Drawing::Size(149, 39);
            this->btnShowOrder->TabIndex = 8;
            this->btnShowOrder->UseVisualStyleBackColor = false;
            this->btnShowOrder->Click += gcnew System::EventHandler(this, &CustomerForm::btnShowOrder_Click);
            // 
            // btnOrderLiempo
            // 
            this->btnOrderLiempo->BackColor = System::Drawing::Color::Transparent;
            this->btnOrderLiempo->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnOrderLiempo->Location = System::Drawing::Point(631, 320);
            this->btnOrderLiempo->Name = L"btnOrderLiempo";
            this->btnOrderLiempo->Size = System::Drawing::Size(72, 37);
            this->btnOrderLiempo->TabIndex = 19;
            this->btnOrderLiempo->UseVisualStyleBackColor = false;
            this->btnOrderLiempo->Click += gcnew System::EventHandler(this, &CustomerForm::btnOrderLiempo_Click);
            // 
            // btnOrderRice
            // 
            this->btnOrderRice->BackColor = System::Drawing::Color::Transparent;
            this->btnOrderRice->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnOrderRice->Location = System::Drawing::Point(1094, 320);
            this->btnOrderRice->Name = L"btnOrderRice";
            this->btnOrderRice->Size = System::Drawing::Size(72, 37);
            this->btnOrderRice->TabIndex = 21;
            this->btnOrderRice->UseVisualStyleBackColor = false;
            this->btnOrderRice->Click += gcnew System::EventHandler(this, &CustomerForm::btnOrderRice_Click);
            // 
            // btnOrderIceCream
            // 
            this->btnOrderIceCream->BackColor = System::Drawing::Color::Transparent;
            this->btnOrderIceCream->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnOrderIceCream->Location = System::Drawing::Point(400, 499);
            this->btnOrderIceCream->Name = L"btnOrderIceCream";
            this->btnOrderIceCream->Size = System::Drawing::Size(72, 37);
            this->btnOrderIceCream->TabIndex = 22;
            this->btnOrderIceCream->UseVisualStyleBackColor = false;
            this->btnOrderIceCream->Click += gcnew System::EventHandler(this, &CustomerForm::btnOrderIceCream_Click);
            // 
            // btnOrderBottledWater
            // 
            this->btnOrderBottledWater->BackColor = System::Drawing::Color::Transparent;
            this->btnOrderBottledWater->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnOrderBottledWater->Location = System::Drawing::Point(631, 499);
            this->btnOrderBottledWater->Name = L"btnOrderBottledWater";
            this->btnOrderBottledWater->Size = System::Drawing::Size(72, 37);
            this->btnOrderBottledWater->TabIndex = 23;
            this->btnOrderBottledWater->UseVisualStyleBackColor = false;
            this->btnOrderBottledWater->Click += gcnew System::EventHandler(this, &CustomerForm::btnOrderBottledWater_Click);
            // 
            // btnOrderCoke
            // 
            this->btnOrderCoke->BackColor = System::Drawing::Color::Transparent;
            this->btnOrderCoke->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnOrderCoke->Location = System::Drawing::Point(862, 501);
            this->btnOrderCoke->Name = L"btnOrderCoke";
            this->btnOrderCoke->Size = System::Drawing::Size(72, 37);
            this->btnOrderCoke->TabIndex = 26;
            this->btnOrderCoke->UseVisualStyleBackColor = false;
            this->btnOrderCoke->Click += gcnew System::EventHandler(this, &CustomerForm::btnOrderCoke_Click);
            // 
            // btnOrderMangoSago
            // 
            this->btnOrderMangoSago->BackColor = System::Drawing::Color::Transparent;
            this->btnOrderMangoSago->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnOrderMangoSago->Location = System::Drawing::Point(1094, 501);
            this->btnOrderMangoSago->Name = L"btnOrderMangoSago";
            this->btnOrderMangoSago->Size = System::Drawing::Size(72, 37);
            this->btnOrderMangoSago->TabIndex = 29;
            this->btnOrderMangoSago->UseVisualStyleBackColor = false;
            this->btnOrderMangoSago->Click += gcnew System::EventHandler(this, &CustomerForm::btnOrderMangoSago_Click);
            // 
            // btnViewMoreFood
            // 
            this->btnViewMoreFood->BackColor = System::Drawing::Color::Transparent;
            this->btnViewMoreFood->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnViewMoreFood->Location = System::Drawing::Point(49, 435);
            this->btnViewMoreFood->Name = L"btnViewMoreFood";
            this->btnViewMoreFood->Size = System::Drawing::Size(149, 37);
            this->btnViewMoreFood->TabIndex = 30;
            this->btnViewMoreFood->UseVisualStyleBackColor = false;
            this->btnViewMoreFood->Click += gcnew System::EventHandler(this, &CustomerForm::btnViewMoreFood_Click);
            // 
            // btnAboutUs
            // 
            this->btnAboutUs->BackColor = System::Drawing::Color::Transparent;
            this->btnAboutUs->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnAboutUs->Location = System::Drawing::Point(49, 577);
            this->btnAboutUs->Name = L"btnAboutUs";
            this->btnAboutUs->Size = System::Drawing::Size(149, 37);
            this->btnAboutUs->TabIndex = 31;
            this->btnAboutUs->UseVisualStyleBackColor = false;
            this->btnAboutUs->Click += gcnew System::EventHandler(this, &CustomerForm::btnAboutUs_Click);
            // 
            // btnOrderMenudo1
            // 
            this->btnOrderMenudo1->BackColor = System::Drawing::Color::Transparent;
            this->btnOrderMenudo1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnOrderMenudo1->Location = System::Drawing::Point(862, 320);
            this->btnOrderMenudo1->Name = L"btnOrderMenudo1";
            this->btnOrderMenudo1->Size = System::Drawing::Size(72, 37);
            this->btnOrderMenudo1->TabIndex = 32;
            this->btnOrderMenudo1->UseVisualStyleBackColor = false;
            this->btnOrderMenudo1->Click += gcnew System::EventHandler(this, &CustomerForm::btnOrderMenudo1_Click_1);
            // 
            // CustomerForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->ClientSize = System::Drawing::Size(1255, 706);
            this->Controls->Add(this->btnOrderMenudo1);
            this->Controls->Add(this->btnAboutUs);
            this->Controls->Add(this->btnViewMoreFood);
            this->Controls->Add(this->btnOrderMangoSago);
            this->Controls->Add(this->btnOrderCoke);
            this->Controls->Add(this->btnOrderBottledWater);
            this->Controls->Add(this->btnOrderIceCream);
            this->Controls->Add(this->btnOrderRice);
            this->Controls->Add(this->btnOrderLiempo);
            this->Controls->Add(this->btnShowOrder);
            this->Controls->Add(this->btnBeverages);
            this->Controls->Add(this->btnDeserts);
            this->Controls->Add(this->btnMainDish);
            this->Controls->Add(this->btnOrderChk);
            this->Controls->Add(this->lblChkPrice);
            this->Controls->Add(this->btnLogOut);
            this->DoubleBuffered = true;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"CustomerForm";
            this->Load += gcnew System::EventHandler(this, &CustomerForm::CustomerForm_Load);
            this->ResumeLayout(false);

        }
#pragma endregion

    private: System::Void btnLogOut_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();

    }
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

    }
    private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void CustomerForm_Load(System::Object^ sender, System::EventArgs^ e) {
        //AddLabelAndButton("Food", "Price");
    }

    private: System::Void btnDeserts_Click(System::Object^ sender, System::EventArgs^ e) {
        CategoryForm^ categoryForm = gcnew CategoryForm();
        categoryForm->SetCategoryLabelText("Desserts");

        // Print the desserts
        FoodMenu* menu = &FoodMenu::Instance();
        auto desserts = menu->getFoodItemsByCategory("Desserts");

        // Debugging output
        if (desserts.empty()) {
            MessageBox::Show("No desserts found", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }

        std::vector<std::string> dessertNames;
        for (const auto& item : desserts) {
            dessertNames.push_back(item.first);
        }
        categoryForm->PrintCategory(dessertNames);

        categoryForm->Show();
    }

    private: System::Void btnMainDish_Click(System::Object^ sender, System::EventArgs^ e) {
        CategoryForm^ categoryForm = gcnew CategoryForm();
        categoryForm->SetCategoryLabelText("Main Dish");

        // Print the main dishes
        FoodMenu* menu = &FoodMenu::Instance();
        auto mainDishes = menu->getFoodItemsByCategory("Main Dish");

        // Debugging output
        if (mainDishes.empty()) {
            MessageBox::Show("No main dishes found", "Debug", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }

        std::vector<std::string> mainDishNames;
        for (const auto& item : mainDishes) {
            mainDishNames.push_back(item.first);
        }
        categoryForm->PrintCategory(mainDishNames);

        categoryForm->Show();
    }

    private: System::Void btnBeverages_Click(System::Object^ sender, System::EventArgs^ e) {
        CategoryForm^ categoryForm = gcnew CategoryForm();
        categoryForm->SetCategoryLabelText("Beverages");

        // Print the beverages
        FoodMenu* menu = &FoodMenu::Instance();
        auto beverages = menu->getFoodItemsByCategory("Beverages");


        std::vector<std::string> beverageNames;
        for (const auto& item : beverages) {
            beverageNames.push_back(item.first);
        }
        categoryForm->PrintCategory(beverageNames);

        categoryForm->Show();
    }


    private: System::Void lblMenudo_Click(System::Object^ sender, System::EventArgs^ e) {
    }


    private: System::Void btnShowOrder_Click(System::Object^ sender, System::EventArgs^ e) {
        CustomerCurrentOrder^ customerCurrentOrder = gcnew CustomerCurrentOrder(schoolID);
        customerCurrentOrder->ShowDialog();
    }

    private: System::Void btnOrderChk_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string itemName = "Fried Chicken";
        if (menu->foodItemExists(itemName)) {
            std::string schoolIDStr = ConvertString(schoolID);
            Orders::Instance().AddOrder(schoolIDStr, itemName, 1, 70.00);
            MessageBox::Show("Fried Chicken has been added to your order!", "Order Added", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            MessageBox::Show("Fried Chicken is out of stock", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void btnOrderLiempo_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string itemName = "Liempo";
        if (menu->foodItemExists(itemName)) {
            std::string schoolIDStr = ConvertString(schoolID);
            Orders::Instance().AddOrder(schoolIDStr, itemName, 1, 80.00);
            MessageBox::Show("Liempo has been added to your order!", "Order Added", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            MessageBox::Show("Liempo is out of stock", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    

    private: System::Void btnOrderMenudo1_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string itemName = "Menudo";
        if (menu->foodItemExists(itemName)) {
            std::string schoolIDStr = ConvertString(schoolID);
            Orders::Instance().AddOrder(schoolIDStr, itemName, 1, 90.00);
            MessageBox::Show("Menudo has been added to your order!", "Order Added", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            MessageBox::Show("Menudo is out of stock", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void btnOrderRice_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string itemName = "Plain Rice";
        if (menu->foodItemExists(itemName)) {
            std::string schoolIDStr = ConvertString(schoolID);
            Orders::Instance().AddOrder(schoolIDStr, itemName, 1, 15.00);
            MessageBox::Show("Plain Rice has been added to your order!", "Order Added", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            MessageBox::Show("Plain Rice is out of stock", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void btnOrderIceCream_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string itemName = "Ice Cream";
        if (menu->foodItemExists(itemName)) {
            std::string schoolIDStr = ConvertString(schoolID);
            Orders::Instance().AddOrder(schoolIDStr, itemName, 1, 15.00);
            MessageBox::Show("Ice Cream has been added to your order!", "Order Added", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            MessageBox::Show("Ice Cream is out of stock", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void btnOrderBottledWater_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string itemName = "Bottled Water";
        if (menu->foodItemExists(itemName)) {
            std::string schoolIDStr = ConvertString(schoolID);
            Orders::Instance().AddOrder(schoolIDStr, itemName, 1, 15.00);
            MessageBox::Show("Bottled Water has been added to your order!", "Order Added", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            MessageBox::Show("Bottled Water is out of stock", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void btnOrderCoke_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string itemName = "Coke";
        if (menu->foodItemExists(itemName)) {
            std::string schoolIDStr = ConvertString(schoolID);
            Orders::Instance().AddOrder(schoolIDStr, itemName, 1, 20.00);
            MessageBox::Show("Coke has been added to your order!", "Order Added", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            MessageBox::Show("Coke is out of stock", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void btnOrderMangoSago_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string itemName = "Mango Sago";
        if (menu->foodItemExists(itemName)) {
            std::string schoolIDStr = ConvertString(schoolID);
            Orders::Instance().AddOrder(schoolIDStr, itemName, 1, 25.00);
            MessageBox::Show("Mango Sago has been added to your order!", "Order Added", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            MessageBox::Show("Mango Sago is out of stock", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void btnOrderMenudo1_Click_1(System::Object^ sender, System::EventArgs^ e) {
        std::string itemName = "Menudo";
        if (menu->foodItemExists(itemName)) {
            std::string schoolIDStr = ConvertString(schoolID);
            Orders::Instance().AddOrder(schoolIDStr, itemName, 1, 90.00);
            MessageBox::Show("Menudo has been added to your order!", "Order Added", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            MessageBox::Show("Menudo is out of stock", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void btnViewMoreFood_Click(System::Object^ sender, System::EventArgs^ e) {
        AddtOrderForm^ addtOrderForm = gcnew AddtOrderForm(schoolID);
        addtOrderForm->ShowDialog();
    }
    private: System::Void btnAboutUs_Click(System::Object^ sender, System::EventArgs^ e) {
        AbousUsForm1^ abousUsForm1 = gcnew AbousUsForm1();
        abousUsForm1->ShowDialog();
    }
};
}
