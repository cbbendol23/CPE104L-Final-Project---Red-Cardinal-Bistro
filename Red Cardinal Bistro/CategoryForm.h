#pragma once
#include "FoodMenu.h"
namespace RedCardinalBistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CategoryForm
	/// </summary>
	public ref class CategoryForm : public System::Windows::Forms::Form
	{
	public:
		CategoryForm(void)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
			this->menu = &FoodMenu::Instance();
		}

		// Set the category label
		void SetCategoryLabelText(String^ category) {
			this->lblCategory->Text = category;
		}
		
		void PrintCategory(const std::vector<std::string>& items) {
			String^ itemList = "";
			for (const auto& item : items) {
				itemList += gcnew String(item.c_str()) + "\n";
			}
			this->lblCategoryMenu->Text = itemList;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CategoryForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnBackFromCategoryForm;
	private: FoodMenu* menu;

	private: System::Windows::Forms::Label^ lblCategory;
	private: System::Windows::Forms::Label^ lblCategoryMenu;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CategoryForm::typeid));
			this->btnBackFromCategoryForm = (gcnew System::Windows::Forms::Button());
			this->lblCategory = (gcnew System::Windows::Forms::Label());
			this->lblCategoryMenu = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnBackFromCategoryForm
			// 
			this->btnBackFromCategoryForm->BackColor = System::Drawing::Color::Transparent;
			this->btnBackFromCategoryForm->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBackFromCategoryForm->Location = System::Drawing::Point(32, 36);
			this->btnBackFromCategoryForm->Name = L"btnBackFromCategoryForm";
			this->btnBackFromCategoryForm->Size = System::Drawing::Size(35, 28);
			this->btnBackFromCategoryForm->TabIndex = 0;
			this->btnBackFromCategoryForm->UseVisualStyleBackColor = false;
			this->btnBackFromCategoryForm->Click += gcnew System::EventHandler(this, &CategoryForm::btnBackFromCategoryForm_Click);
			// 
			// lblCategory
			// 
			this->lblCategory->AutoSize = true;
			this->lblCategory->BackColor = System::Drawing::Color::Transparent;
			this->lblCategory->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCategory->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)));
			this->lblCategory->Location = System::Drawing::Point(258, 114);
			this->lblCategory->Name = L"lblCategory";
			this->lblCategory->Size = System::Drawing::Size(178, 45);
			this->lblCategory->TabIndex = 3;
			this->lblCategory->Text = L"Main Dish";
			this->lblCategory->Click += gcnew System::EventHandler(this, &CategoryForm::lblCategory_Click);
			// 
			// lblCategoryMenu
			// 
			this->lblCategoryMenu->AutoSize = true;
			this->lblCategoryMenu->BackColor = System::Drawing::Color::Transparent;
			this->lblCategoryMenu->Font = (gcnew System::Drawing::Font(L"Chesna Grotesk Medium", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCategoryMenu->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)));
			this->lblCategoryMenu->Location = System::Drawing::Point(98, 221);
			this->lblCategoryMenu->Name = L"lblCategoryMenu";
			this->lblCategoryMenu->Size = System::Drawing::Size(220, 29);
			this->lblCategoryMenu->TabIndex = 4;
			this->lblCategoryMenu->Text = L"(List all Menu Items)";
			this->lblCategoryMenu->Click += gcnew System::EventHandler(this, &CategoryForm::lblMainDishMenu_Click);
			// 
			// CategoryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1255, 706);
			this->Controls->Add(this->lblCategoryMenu);
			this->Controls->Add(this->lblCategory);
			this->Controls->Add(this->btnBackFromCategoryForm);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CategoryForm";
			this->Text = L"CategoryForm";
			this->Load += gcnew System::EventHandler(this, &CategoryForm::CategoryForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CategoryForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnBackFromCategoryForm_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lblCategory_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void lblMainDishMenu_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
