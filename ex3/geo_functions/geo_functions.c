/**
 * @file geo_functions.c
 * @author Camille Monière
 * @brief  Contains definitions for geometric functions
 * @version 1.0
 * @date 2023-10-03
 * 
 * @copyright Copyright (c) 2023
 *
 */

/** @cond */
#include "geo_functions/geo_functions.h"
/** @endcond */

/**
 * @brief Calculates the perimeter of a rectangle
 *
 * @details The perimeter of a rectangle with length \f$L\f$ and height \f$H\f$ is
 * equal to \f$2 \times (L + H)\f$
 *
 * @param L length
 * @param H height
 * @return float perimeter
 */
float rectangle_perimeter(float L, float H) {
    return (L + H) * 2.f;
}

/**
 * @brief Calculates the area of a rectangle
 *
 * @details The area of a rectangle with length \f$L\f$ and height \f$H\f$ is equal
 * to \f$L \times H\f$
 *
 * @param L length
 * @param H height
 * @return float area
 */
float rectangle_area(float L, float H) {
    return L * H;
}

/**
 * @brief Calculates the perimeter of a square
 *
 * @details A square is a rectangle where \f$H = \f$L, so it is sufficient to call
 * rectangle_perimeter(c, c).
 *
 * @param c side length
 * @return float perimeter
 */
float square_perimeter(float c) {
    return rectangle_perimeter(c, c);
}

/**
 * @brief Calculates the area of a square
 *
 * @details A square is a rectangle where \f$H = \f$L, so it is sufficient to call
 * rectangle_area(c, c).
 *
 * @param c side length
 * @return float area
 */
float square_area(float c) {
    return rectangle_area(c, c);
}

/**
 * @brief Local constant value of  \f$\pi\f$
 *
 */
static const float pi = 3.141592653589793f;

/**
 * @brief Multiplies by  \f$\pi\f$
 *
 * @details The requested functions cannot include the ``*'' operator, so we
 * use a function to perform multiplication by  \f$\pi\f$.
 * @param x operand \f$x\f$
 * @return float \f$\pi \times x\f$
 */
static float pi_times(float x) {
    return x * pi;
}

/**
 * @brief Calculates the perimeter of a circle
 *
 * @details The perimeter of a circle with radius \f$r\f$ is equal to \f$2 \pi r = 2 \times
 * (\pi r + 0)\f$. Thus, call rectangle_perimeter(pi_times(r), 0).
 * @param r radius
 * @return float perimeter
 */
float circle_perimeter(float r) {
    return rectangle_perimeter(pi_times(r), 0);
}

/**
 * @brief Calculates the area of a circle
 *
 * @details The area of a circle with radius \f$r\f$ is equal to \f$\pi r^2 = \pi r \times r\f$. Thus, call rectangle_area(pi_times(r), r).
 * @param r radius
 * @return float area
 */
float circle_area(float r) {
    return rectangle_area(pi_times(r), r);
}
