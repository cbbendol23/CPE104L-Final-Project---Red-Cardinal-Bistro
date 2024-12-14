/*
#include "CouponCodes.h"

namespace RedCardinalBistro {
    void AddCouponCode(const std::string& code, int discountPercentage) {
        couponCodes.push_back({ code, discountPercentage });
    }

    bool EditCouponCode(const std::string& oldCode, const std::string& newCode, int newDiscountPercentage) {
        auto it = std::find_if(couponCodes.begin(), couponCodes.end(), [&](const Coupon& coupon) {
            return coupon.code == oldCode;
            });
        if (it != couponCodes.end()) {
            it->code = newCode;
            it->discountPercentage = newDiscountPercentage;
            return true;
        }
        return false;
    }

    bool RemoveCouponCode(const std::string& code) {
        auto it = std::remove_if(couponCodes.begin(), couponCodes.end(), [&](const Coupon& coupon) {
            return coupon.code == code;
            });
        if (it != couponCodes.end()) {
            couponCodes.erase(it, couponCodes.end());
            return true;
        }
        return false;
    }

    bool IsCouponCodeValid(const std::string& code) {
        return std::any_of(couponCodes.begin(), couponCodes.end(), [&](const Coupon& coupon) {
            return coupon.code == code;
            });
    }

    int GetDiscountPercentage(const std::string& code) {
        auto it = std::find_if(couponCodes.begin(), couponCodes.end(), [&](const Coupon& coupon) {
            return coupon.code == code;
            });
        if (it != couponCodes.end()) {
            return it->discountPercentage;
        }
        return 0; // No discount if coupon code is not found
    }
}
*/