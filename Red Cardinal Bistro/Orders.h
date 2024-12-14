#pragma once
#include <vector>
#include <string>

class Orders {
public:
    struct Order {
        std::string schoolID;
        std::string foodName;
        int quantity;
        double price;
        bool isDiscounted;
    };

    static Orders& Instance() {
        static Orders instance;
        return instance;
    }

    void AddOrder(const std::string& schoolID, const std::string& foodName, int quantity, double price) {
        for (auto& order : orders) {
            if (order.schoolID == schoolID && order.foodName == foodName) {
                order.quantity += quantity;
                order.price += price * quantity;
                return;
            }
        }
        orders.push_back({ schoolID, foodName, quantity, price * quantity, false });
    }

    const std::vector<Order>& GetOrders() const {
        return orders;
    }

    const std::vector<Order> GetOrdersForCustomer(const std::string& customerID) const {
        std::vector<Order> customerOrders;
        for (const auto& order : orders) {
            if (order.schoolID == customerID) {
                customerOrders.push_back(order);
            }
        }
        return customerOrders;
    }

\
    std::vector<Order> GetDiscountedOrders() const {
        std::vector<Order> discountedOrders;

        for (const auto& order : orders) {
            if (order.isDiscounted) {
                discountedOrders.push_back(order);
            }
        }
        return discountedOrders;
    }

    std::vector<Order> GetNonDiscountedOrders() const {
        std::vector<Order> nonDiscountedOrders;
        for (const auto& order : orders) {
            if (!order.isDiscounted) {
                nonDiscountedOrders.push_back(order);
            }
        }
        return nonDiscountedOrders;
    }

    void SetDiscountRate(double rate) {
        discountRate = rate;
    }

    void RemoveAllOrdersForCustomer(const std::string& customerID) {
        orders.erase(
            std::remove_if(orders.begin(), orders.end(), [&customerID](const Order& order) {
                return order.schoolID == customerID;
                }),
            orders.end()
        );
    }


    void SaveOrder(const Order& order) {
        orders.push_back(order);
    }

    void SaveNonDiscountedOrder(const Order& order) {
        for (const auto& existingOrder : orders) {
            if (existingOrder.schoolID == order.schoolID && existingOrder.foodName == order.foodName && !existingOrder.isDiscounted) {
                // Order already exists, no need to add
                return;
            }
        }
        Order nonDiscountedOrder = order;
        nonDiscountedOrder.isDiscounted = false;
        orders.push_back(nonDiscountedOrder);
    }

    void SaveDiscountedOrder(const Order& order, double discountRate) {
        // Remove the original non-discounted order
        orders.erase(
            std::remove_if(orders.begin(), orders.end(), [&order](const Order& existingOrder) {
                return existingOrder.schoolID == order.schoolID && existingOrder.foodName == order.foodName && !existingOrder.isDiscounted;
                }),
            orders.end()
        );
        Order discountedOrder = order;
        //discountedOrder.price *= (1 - discountRate / 100.0);
        discountedOrder.isDiscounted = true;
        orders.push_back(discountedOrder);
    }

    void SaveDiscountedOrderNoDiscountRate(const Order& order) {
        // Remove the original non-discounted order if it exists
        orders.erase(
            std::remove_if(orders.begin(), orders.end(), [&order](const Order& existingOrder) {
                return existingOrder.schoolID == order.schoolID && existingOrder.foodName == order.foodName && !existingOrder.isDiscounted;
                }),
            orders.end()
        );

        // Create a discounted order
        Order discountedOrder = order;
        discountedOrder.isDiscounted = true;

        // Push the discounted order back to the orders vector
        orders.push_back(discountedOrder);
    }

private:
    Orders() : discountRate(0) {}
    std::vector<Order> orders;
    double discountRate;
};
