#include <iostream>

const uint64_t frac_mask = uint64_t(uint64_t(1)<<52)+~0;
const uint64_t exp_mask = (uint64_t(uint64_t(1)<<11)+~0)<<52;
const uint64_t sign_mask = uint64_t(1)<<63;


class truef32
{
    public:
        uint32_t value;
        bool valid;
        truef32(double input)
        {
            uint64_t input_u64 =*((uint64_t *)(&input));
            uint64_t frac = frac_mask & input_u64;
            int exp = (exp_mask & input_u64) >> 52;
            bool sign = bool((sign_mask & input_u64)>>63);
            if (exp>=1023)
            {
                valid = false;
                value = 0;
            }
            else if (exp-1023+11>=0)
            {
                uint64_t mid_value = (frac | ((uint64_t)(1)<<52)) << (exp-1023+11);
                value = mid_value >> 32;
                valid = true;
            }
            else if (exp-1023+11<0 && exp-1023+11>=-52)
            {
                uint64_t mid_value = (frac | ((uint64_t)(1)<<52)) >> -(exp-1023+11);
                value = mid_value >> 32;
                valid = true;
            }
            else
            {
                valid = true;
                value = 0;
            }
            if (sign)
            {
                value = ~value + 1;
            }
            return;
        }

        friend std::ostream &operator<<(std::ostream &os,const truef32 & f32)
        {
            if(f32.valid)
            {
                os<<std::hex<<f32.value<<std::oct;
            }
            else
            {
                os<<"Invalid Number";
            }
            return os;
        }
};