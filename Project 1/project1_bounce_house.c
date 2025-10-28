/*Daud Ahmad Nisar
This program calculates the charges of renting a bounce house depending you the kind
of bounce house that is rented and the number of hours and days it is rented for.*/

#include <stdio.h>

// Bounce house rates defined as constants
#define MAGIC_CASTLE_3HRS 58
#define MAGIC_CASTLE_HOURLY 8
#define MAGIC_CASTLE_DAILY 80

#define GIGANTIC_JUMP_3HRS 85
#define GIGANTIC_JUMP_HOURLY 12
#define GIGANTIC_JUMP_DAILY 120

#define WET_SLIDE_3HRS 100
#define WET_SLIDE_HOURLY 15
#define WET_SLIDE_DAILY 150

#define OBSTACLE_COMBO_3HRS 180
#define OBSTACLE_COMBO_HOURLY 20
#define OBSTACLE_COMBO_DAILY 250

int calculate_charge(int selection, int days, int hours) {
    int base_charge = 0;
    int hourly_rate = 0;
    int max_daily_charge = 0;

    // Assign charges based on selection
    if (selection == 1) {
        base_charge = MAGIC_CASTLE_3HRS;
        hourly_rate = MAGIC_CASTLE_HOURLY;
        max_daily_charge = MAGIC_CASTLE_DAILY;
    } else if (selection == 2) {
        base_charge = GIGANTIC_JUMP_3HRS;
        hourly_rate = GIGANTIC_JUMP_HOURLY;
        max_daily_charge = GIGANTIC_JUMP_DAILY;
    } else if (selection == 3) {
        base_charge = WET_SLIDE_3HRS;
        hourly_rate = WET_SLIDE_HOURLY;
        max_daily_charge = WET_SLIDE_DAILY;
    } else if (selection == 4) {
        base_charge = OBSTACLE_COMBO_3HRS;
        hourly_rate = OBSTACLE_COMBO_HOURLY;
        max_daily_charge = OBSTACLE_COMBO_DAILY;
    }

    int charge = 0;

    // Calculate the charge for full days. Full days are charged for the daily maximum
    if (days > 0) {
        charge += days * max_daily_charge;
    }

    // handling the additional hours if any
    if (hours > 0) {
        if (days == 0) {
            // If no full days, the 3-hour base charge is applied, then calculate the extra hours
            if (hours <= 3) {
                charge += base_charge;
            } else {
                int hourly_charge = base_charge + (hours - 3) * hourly_rate;
                // The daily maximum cap for a single day if the hourly charge exceeds it
                if (hourly_charge > max_daily_charge) {
                    hourly_charge = max_daily_charge;
                }
                charge += hourly_charge;
            }
        } else {
            // If there are full days involved, charge extra hours based on the hourly rate
            int extra_hourly_charge = hours * hourly_rate;
            if (extra_hourly_charge > max_daily_charge) {
                extra_hourly_charge = max_daily_charge;  // Cap at the daily max if hourly exceeds it
            }
            charge += extra_hourly_charge;
        }
    }

    return charge;
}

int main() {
    int selection, days, hours;

    // Ask user for bounce house selection
    printf("Please select from four bounce houses: 1, 2, 3, and 4\n");
    printf("Enter bounce house selection: ");
    scanf("%d", &selection);

    // Validate bounce house selection
    if (selection < 1 || selection > 4) {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 1;  // Exit the program
    }

    // Ask user for number of days and hours
    printf("Enter days: ");
    scanf("%d", &days);
    printf("Enter hours: ");
    scanf("%d", &hours);

    // Validate hours input
    if (hours < 0 || hours >= 24) {
        printf("Invalid hours.\n");
        return 1;
    }

    // Calculate and display charge
    int charge = calculate_charge(selection, days, hours);
    printf("Charge($): %d\n", charge);

    return 0;
}
