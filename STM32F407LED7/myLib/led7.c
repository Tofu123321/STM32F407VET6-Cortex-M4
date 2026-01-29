#include "led7.h"

static uint8_t seg_code[10] =
{
    0x3F, 0x06, 0x5B, 0x4F, 0x66,
    0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

void LED7_Init(LED7_Handle_t *hLED,
               LED7_GPIO_t seg_a,
               LED7_GPIO_t seg_b,
               LED7_GPIO_t seg_c,
               LED7_GPIO_t seg_d,
               LED7_GPIO_t seg_e,
               LED7_GPIO_t seg_f,
               LED7_GPIO_t seg_g,
               LED7_Type_t type)
{
    hLED->type = type;
    hLED->seg[0] = seg_a;
    hLED->seg[1] = seg_b;
    hLED->seg[2] = seg_c;
    hLED->seg[3] = seg_d;
    hLED->seg[4] = seg_e;
    hLED->seg[5] = seg_f;
    hLED->seg[6] = seg_g;
}

void LED7_Display(LED7_Handle_t *hLED, uint8_t num)
{
    if (num > 9) return;

    uint8_t data = seg_code[num];

    for (uint8_t i = 0; i < 7; i++)
    {
        GPIO_PinState state;

        if (hLED->type == LED_ANODE)
            state = (data & (1 << i)) ? GPIO_PIN_RESET : GPIO_PIN_SET;
        else
            state = (data & (1 << i)) ? GPIO_PIN_SET : GPIO_PIN_RESET;

        HAL_GPIO_WritePin(hLED->seg[i].port,
                          hLED->seg[i].pin,
                          state);
    }
}
