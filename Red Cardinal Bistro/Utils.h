#pragma once

#include <string>
#include <msclr/marshal_cppstd.h>

namespace RedCardinalBistro {
    public ref class Utils {
    public:
        static std::string ConvertString(System::String^ str) {
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
    };
}
