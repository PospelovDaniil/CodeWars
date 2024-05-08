#include <iostream>
#include <string>
#include <cstdio>

/**
 * RGB To Hex Conversion
 *
 * The rgb function is incomplete. Complete it so that passing in RGB decimal values will result
 * in a hexadecimal representation being returned. Valid decimal values for RGB are 0 - 255.
 * Any values that fall out of that range must be rounded to the closest valid value.
 * Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.
 *
 * Examples (input --> output):
 * 255, 255, 255 --> "FFFFFF"
 * 255, 255, 300 --> "FFFFFF"
 * 0, 0, 0       --> "000000"
 * 148, 0, 211   --> "9400D3"
 */


std::string rgb_to_hex(int r, int g, int b)
{
    std::string res{"000000"};
    res.reserve(6);

    auto replaceToValid = [](int &x){
        if (x < 0) {
            x = 0;
        }
        else if (x > 255) {
            x = 255;
        }
    };

    replaceToValid(r);
    replaceToValid(g);
    replaceToValid(b);

    std::sprintf(&res[0], "%02X%02X%02X", r, g, b);

    return res;
}

int main()
{
    std::cout << rgb_to_hex(0xA, 0xB, 0xC) << std::endl;
    return 0;
}
