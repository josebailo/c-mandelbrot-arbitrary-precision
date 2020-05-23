#include "period2_detection.h"

int inside_period_2_bulb(acb_t c, slong prec, app_config config) {
    int ret = 0;
    arb_t x, y;           // Real and imaginary parts
    arb_t temp;           // Temporal results and constants in the formula
    arb_t _1;             // 1
    arb_t _0_0625;        // 1/16 = 0.0625
    arb_t y_sqr;          // y²

    arb_init(x);
    arb_init(y);
    arb_init(temp);
    arb_init(_1);
    arb_init(_0_0625);
    arb_init(y_sqr);

    // Set formula constants
    arb_set_str(_0_0625, "0.0625", prec);
    arb_set_str(_1, "1", prec);

    // Get real and imaginary parts
    acb_get_real(x, c);
    acb_get_imag(y, c);

    /**  Calculate left side of comparison **/

    // temp = x + 1
    arb_add(temp, x, _1, prec);
    // temp = (x + 1)²
    arb_sqr(temp, temp, prec);
    // y²
    arb_sqr(y_sqr, y, prec);
    // temp = (x + 1)² + y²
    arb_add(temp, temp, y_sqr, prec);

    // temp < 1/16
    if (arb_lt(temp, _0_0625)) {
        ret = 1;
    }

    arb_clear(x);
    arb_clear(y);
    arb_clear(temp);
    arb_clear(_1);
    arb_clear(_0_0625);
    arb_clear(y_sqr);

    return ret;
}