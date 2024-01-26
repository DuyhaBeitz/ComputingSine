#include "../Headers/fp_num.hpp"//fixed point number
#include "../Headers/sine_helper.hpp"//range reduction helper
#include "../Headers/MyMath.hpp"//Sign()

float angles_lut[15] = {
    0.78539816339744827899949086713604629039764404296875,
    0.46364760900080609351547877849952783435583114624023,
    0.24497866312686414347332686247682431712746620178223,
    0.12435499454676143815667899161780951544642448425293,
    0.06241880999595735002305474381500971503555774688721,
    0.03123983343026827744215445648023887770250439643860,
    0.01562372862047683129416153491320073953829705715179,
    0.00781234106010111114398730691732453124132007360458,
    0.00390623013196697175739013907502794609172269701958,
    0.00195312251647881875843415500071387214120477437973,
    0.00097656218955931945943649274965991935459896922112,
    0.00048828121119489828992621394121442790492437779903,
    0.00024414062014936177124474481203719733457546681166,
    0.00012207031189367020785306594543584424172877334058,
    0.00006103515617420877259350145416227917394280666485,
};

double CordicSineFPN(double angle)
{
    //range reduction
    const double limited_angle = sine_mirror_angle(angle);
    const int func_sign = sine_func_sign(angle);

    // Constants for CORDIC calculations
    constexpr double k = 0.607252935385914;//cos(angles_lut[0]) * cos(angles_lut[1]) ...
    constexpr int iterations = 15;

    //vector (1, 0)
    fixed<int32_t, int64_t, 30> x(1.0), y(0.0);
    //angle to rotate vector
    double z = limited_angle;

    for (int i = 0; i < iterations; ++i) {
            
        //direction of rotation
        int direction = (z >= 0) ? 1 : -1;

        //calculate coords after rotation
        int32_t new_x = x.value - (direction * y.value >> i );
        int32_t new_y = y.value + (direction * x.value >> i );

        //assign them
        x.value = new_x;
        y.value = new_y;

        //angle
        z -= direction * angles_lut[i];
    }

    return double(y) * k * func_sign * Sign(angle);
}