#pragma once
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include "QuickSort.h"

namespace RedCardinalBistro {

    class FoodMenu {
    public:
        static FoodMenu& Instance() {
            static FoodMenu instance;
            return instance;
        }

        bool addFoodItem(const std::string& name, double price, const std::string& category) {
            if (foodItems.size() >= MAX_FOOD_ITEMS) {
                return false; // Indicate that the item was not added due to the limit
            }

            foodItems.push_back({ name, price });
            if (category == "Main Dish") {
                mainDishes.push_back(name);
            }
            else if (category == "Dessert") {
                desserts.push_back(name);
            }
            else if (category == "Beverage") {
                beverages.push_back(name);
            }
            return true; // Indicate that the item was successfully added
        }

        std::string getFoodItemsAsString() {
            std::string result;
            for (const auto& item : foodItems) {
                result += item.first + ": " + std::to_string(item.second) + "\n";
            }
            return result;
        }

        std::vector<std::pair<std::string, double>> getFoodItems() const {
            return foodItems;
        }

        std::vector<std::pair<std::string, double>> getFoodItemsByCategory(const std::string& category) const {
            std::vector<std::pair<std::string, double>> itemsInCategory;
            if (category == "Main Dish") {
                for (const auto& item : mainDishes) {
                    auto it = std::find_if(foodItems.begin(), foodItems.end(), [&item](const auto& pair) {
                        return pair.first == item;
                        });
                    if (it != foodItems.end()) {
                        itemsInCategory.push_back(*it);
                    }
                }
            }
            else if (category == "Desserts") {
                for (const auto& item : desserts) {
                    auto it = std::find_if(foodItems.begin(), foodItems.end(), [&item](const auto& pair) {
                        return pair.first == item;
                        });
                    if (it != foodItems.end()) {
                        itemsInCategory.push_back(*it);
                    }
                }
            }
            else if (category == "Beverages") {
                for (const auto& item : beverages) {
                    auto it = std::find_if(foodItems.begin(), foodItems.end(), [&item](const auto& pair) {
                        return pair.first == item;
                        });
                    if (it != foodItems.end()) {
                        itemsInCategory.push_back(*it);
                    }
                }
            }

            // Sort items alphabetically by name using quicksort
            quickSortName(itemsInCategory, 0, itemsInCategory.size() - 1);

            return itemsInCategory;
        }

        size_t getFoodItemCount() const {
            return foodItems.size();
        }


        // Save food items to a CSV file
        void SaveMenuToCSV(const std::string& directory) const {
            std::string filePath = directory + "menu.csv";
            std::ofstream file(filePath);
            if (!file.is_open()) {
                throw std::runtime_error("Failed to open file for writing: " + filePath);
            }

            file << "Name,Price,Category\n"; // CSV header

            // Create a copy of foodItems to sort
            std::vector<std::pair<std::string, double>> sortedFoodItems = foodItems;

            // Sort the food items by price in ascending order
            quickSortPrice(sortedFoodItems, 0, sortedFoodItems.size() - 1);

            for (const auto& item : sortedFoodItems) {
                std::string category;
                if (std::find(mainDishes.begin(), mainDishes.end(), item.first) != mainDishes.end()) {
                    category = "Main Dish";
                }
                else if (std::find(desserts.begin(), desserts.end(), item.first) != desserts.end()) {
                    category = "Dessert";
                }
                else if (std::find(beverages.begin(), beverages.end(), item.first) != beverages.end()) {
                    category = "Beverage";
                }
                file << item.first << "," << item.second << "," << category << "\n";
            }

            file.close();
        }

        // Load food items from a CSV file
        void LoadMenuFromCSV(const std::string& directory) {
            std::string filePath = directory + "menu.csv";
            std::ifstream file(filePath);
            if (!file.is_open()) {
                throw std::runtime_error("Failed to open file: " + filePath);
            }

            std::string line;
            // Skip the header line
            std::getline(file, line);

            // Clear current food items
            foodItems.clear();
            mainDishes.clear();
            desserts.clear();
            beverages.clear();

            while (std::getline(file, line)) {
                std::stringstream ss(line);
                std::string name, priceStr, category;

                std::getline(ss, name, ',');
                std::getline(ss, priceStr, ',');
                std::getline(ss, category, ',');

                double price = std::stod(priceStr);
                addFoodItem(name, price, category);
            }

            file.close();
        }

        bool removeFoodItem(const std::string& name) {
            auto it = std::find_if(foodItems.begin(), foodItems.end(), [&name](const auto& pair) {
                return pair.first == name;
                });

            if (it != foodItems.end()) {
                foodItems.erase(it);

                auto removeFromCategory = [&name](std::vector<std::string>& category) {
                    category.erase(std::remove(category.begin(), category.end(), name), category.end());
                    };

                removeFromCategory(mainDishes);
                removeFromCategory(desserts);
                removeFromCategory(beverages);

                return true; // Indicate that the item was successfully removed
            }

            return false; // Indicate that the item was not found
        }

        bool foodItemExists(const std::string& name) const {
            return std::any_of(foodItems.begin(), foodItems.end(), [&name](const auto& item) {
                return item.first == name;
                });
        }

    private:
        FoodMenu() {
            foodItems = {
                {"Menudo", 90.0},
                {"Fried Chicken", 70.0},
                {"Ice Cream", 25.0},
                {"Mango Sago", 25.0},
                {"Liempo", 80.0},
                {"Plain Rice", 15.0},
                {"Bottled Water", 15.0},
                {"Coke", 20.0},
            };

            mainDishes = { "Fried Chicken", "Menudo", "Liempo", "Plain Rice", };
            desserts = { "Ice Cream", "Mango Sago" };
            beverages = { "Bottled Water", "Coke" };
        }

        static const int MAX_FOOD_ITEMS = 16;
        std::vector<std::pair<std::string, double>> foodItems;
        std::vector<std::string> mainDishes;
        std::vector<std::string> desserts;
        std::vector<std::string> beverages;

        // Delete copy constructor and assignment operator
        FoodMenu(const FoodMenu&) = delete;
        FoodMenu& operator=(const FoodMenu&) = delete;
    };
}
