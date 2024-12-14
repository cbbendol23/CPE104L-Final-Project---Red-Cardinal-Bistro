#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <sstream>


namespace RedCardinalBistro {

    struct Coupon {
        std::string code;
        int discountPercentage; // Discount percentage (e.g., 50 for 50%)
		std::chrono::system_clock::time_point expirationDate; // Expiration date of the coupon code
    };

    class CouponManager {
    public:
        // Get the singleton instance
        static CouponManager& getInstance() {
            static CouponManager instance;
            return instance;
        }

        // Delete copy constructor and assignment operator
        CouponManager(const CouponManager&) = delete;
        CouponManager& operator=(const CouponManager&) = delete;

        void AddCouponCode(const std::string& code, int discountPercentage) {
            auto it = std::find_if(couponCodes.begin(), couponCodes.end(), [&code](const Coupon& c) {
                return c.code == code;
                });

            if (it == couponCodes.end()) {
                auto now = std::chrono::system_clock::now();
                auto expirationDate = now + std::chrono::hours(24 * 3); // 3 days from now
                couponCodes.push_back({ code, discountPercentage, expirationDate });
            }
            else {
                it->discountPercentage = discountPercentage;
                // Do not reset the expiration date for existing coupon codes
            }
        }

        // Function to edit an existing coupon code
        bool EditCouponCode(const std::string& oldCode, const std::string& newCode, int newDiscountPercentage) {
            auto it = std::find_if(couponCodes.begin(), couponCodes.end(), [&oldCode](const Coupon& c) {
                return c.code == oldCode;
                });
            if (it != couponCodes.end()) {
                it->code = newCode;
                it->discountPercentage = newDiscountPercentage;
                it->expirationDate = std::chrono::system_clock::now() + std::chrono::hours(24 * 3); // Reset expiration to 3 days from now
                return true;
            }
            return false;
        }

        // Function to remove a coupon code
        bool RemoveCouponCode(const std::string& code) {
            auto it = std::remove_if(couponCodes.begin(), couponCodes.end(), [&code](const Coupon& c) {
                return c.code == code;
                });
            if (it != couponCodes.end()) {
                couponCodes.erase(it, couponCodes.end());
                return true;
            }
            return false;
        }

        // Function to check if a coupon code is valid
        bool IsCouponCodeValid(const std::string& code) {
            auto it = std::find_if(couponCodes.begin(), couponCodes.end(), [&code](const Coupon& c) {
                return c.code == code;
                });
            if (it != couponCodes.end()) {
                // Check if the coupon is expired
                if (std::chrono::system_clock::now() <= it->expirationDate) {
                    return true;
                }
            }
            return false;
        }

        // Function to get the discount percentage for a given coupon code
        int GetDiscountPercentage(const std::string& code) {
            auto it = std::find_if(couponCodes.begin(), couponCodes.end(), [&code](const Coupon& c) {
                return c.code == code;
                });
            if (it != couponCodes.end()) {
                return it->discountPercentage;
            }
            return 0;
        }

        bool UpdateCoupon(const std::string& oldCode, const std::string& newCode, int newDiscountPercentage) {
            return EditCouponCode(oldCode, newCode, newDiscountPercentage);
        }

        // Function to save coupon codes to a CSV file
        void SaveCouponsToCSV(const std::string& directory) {
            std::string filePath = directory + "couponcodes.csv";
            std::ofstream file(filePath);
            if (!file.is_open()) {
                throw std::runtime_error("Failed to open file for writing: " + filePath);
            }

            file << "Coupon Code,Discount,Expiration\n"; // CSV header

            for (const auto& coupon : couponCodes) {
                std::time_t expirationTimeT = std::chrono::system_clock::to_time_t(coupon.expirationDate);
                file << coupon.code << "," << coupon.discountPercentage << "," << std::put_time(std::localtime(&expirationTimeT), "%Y-%m-%d %H:%M:%S") << "\n";
            }

            file.close();
        }

        void LoadCouponsFromCSV(const std::string& directory) {
            std::string filePath = directory + "couponcodes.csv";
            std::ifstream file(filePath);
            if (!file.is_open()) {
                throw std::runtime_error("Failed to open file for reading: " + filePath);
            }

            std::string line;
            std::getline(file, line); // Skip the header

            couponCodes.clear(); // Clear existing coupons

            while (std::getline(file, line)) {
                std::istringstream ss(line);
                std::string code, discountStr, expirationStr;

                std::getline(ss, code, ',');
                std::getline(ss, discountStr, ',');
                std::getline(ss, expirationStr, ',');

                int discountPercentage = std::stoi(discountStr);
                std::tm tm = {};
                std::istringstream ssTime(expirationStr);
                ssTime >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
                auto expirationDate = std::chrono::system_clock::from_time_t(std::mktime(&tm));

                couponCodes.push_back({ code, discountPercentage, expirationDate });
            }

            file.close();
        }

        bool IsCouponCodeExisting(const std::string& code) {
            auto it = std::find_if(couponCodes.begin(), couponCodes.end(), [&code](const Coupon& c) {
                return c.code == code;
                });
            return it != couponCodes.end();
        }
        
        double applyDiscount(const std::string& code, double price) {
            if (IsCouponCodeValid(code)) {
                int discountPercentage = GetDiscountPercentage(code);
                double discountAmount = (price * discountPercentage) / 100.0;
                return price - discountAmount;
            }
            return price; // No discount applied if the coupon is not valid
        }

        std::vector<Coupon> GetAllCouponCodes() const {
            return couponCodes;
        }

    private:
        // Private constructor
        CouponManager() {
            InitializeCoupons();
        }

        // Initialize default coupon codes
        void InitializeCoupons() {
            auto now = std::chrono::system_clock::now();
            auto expirationDate = now + std::chrono::hours(24 * 3); // 3 days from now
            couponCodes.push_back({ "SAVE10", 10, expirationDate });
            couponCodes.push_back({ "SAVE20", 20, expirationDate });
            couponCodes.push_back({ "SAVE30", 30, expirationDate });
            couponCodes.push_back({ "BENPOGI", 40, expirationDate });
            couponCodes.push_back({ "NOSINGKO", 50, expirationDate });


            auto expirationDate1Minutes = now + std::chrono::minutes(1);
            couponCodes.push_back({ "EXPIRE1MIN", 90, expirationDate1Minutes });
        }

        std::vector<Coupon> couponCodes;
    };

}