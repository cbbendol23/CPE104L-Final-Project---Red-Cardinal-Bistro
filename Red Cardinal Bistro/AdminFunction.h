#pragma once
#include <string>
#include <msclr/marshal.h>

namespace RedCardinalBistro {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class UIHelpers
    {
    private:
        static UIHelpers^ instance = nullptr;

        UIHelpers() {}

    public:
        static property UIHelpers^ Instance
        {
            UIHelpers^ get()
            {
                if (instance == nullptr)
                {
                    instance = gcnew UIHelpers();
                }
                return instance;
            }
        }

        void AddLabelAndButton(Form^ form, String^ labelText, String^ buttonText, int labelCount)
        {
            int yOffset = 50 + (labelCount * 30); // Adjust the vertical position for each new set

            Label^ newLabel = gcnew Label();
            newLabel->Text = labelText;
            newLabel->Location = Point(50, yOffset);
            newLabel->AutoSize = true; // Ensure the label size adjusts to the text
            form->Controls->Add(newLabel);

            Button^ newButton = gcnew Button();
            newButton->Text = buttonText;
            newButton->Location = Point(200, yOffset); // Adjust the horizontal position
            newButton->AutoSize = true; // Ensure the button size adjusts to the text
            form->Controls->Add(newButton);
        }

        void UpdateLabelText(Label^ label, String^ newText)
        {
            label->Text = newText;
            MessageBox::Show(newText, "Updated Label Text", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    };
}