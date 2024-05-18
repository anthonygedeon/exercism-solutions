#include "leap.h"

/**
 * Determine if a year is a leap year.
 * @param year the given year. 
 * @return the result of the year being a leap year or not.
 */
bool leap_year(int year) {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}
