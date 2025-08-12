#include "vehicle_purchase.h"

namespace vehicle_purchase {

// needs_license determines whether a license is needed to drive a type of
// vehicle. Only "car" and "truck" require a license.
bool needs_license(std::string kind) {
    return kind == "car" || kind == "truck";
}

// choose_vehicle recommends a vehicle for selection. It always recommends the
// vehicle that comes first in lexicographical order.
std::string choose_vehicle(std::string option1, std::string option2) {
    std::string choice{option2};
    if (option1 < option2) {
        choice = option1;
    }
    return choice + " is clearly the better choice.";
}

// calculate_resell_price calculates how much a vehicle can resell for at a
// certain age.
double calculate_resell_price(double original_price, double age) {
    if (age < 3.0) {
        return original_price * (80.0 / 100.0);
    } else if (age >= 10.0) {
        return original_price * (50.0 / 100.0);
    } else if (age >= 3.0 && age < 10.0) {
        return original_price * (70.0 / 100.0);
    }
    return 0.0;
}

} // namespace vehicle_purchase
