#ifndef _LED_7
#define _LED_7

#include "stm32f4xx_hal.h"

typedef struct
{
    GPIO_TypeDef *port;
    uint16_t pin;
} LED7_GPIO_t;

typedef enum
{
    LED_ANODE,
    LED_CATHODE
} LED7_Type_t;

typedef struct
{
    LED7_GPIO_t seg[7];
    LED7_Type_t type;
} LED7_Handle_t;

/* ch? khai báo */
void LED7_Init(LED7_Handle_t *hLED,
               LED7_GPIO_t seg_a,
               LED7_GPIO_t seg_b,
               LED7_GPIO_t seg_c,
               LED7_GPIO_t seg_d,
               LED7_GPIO_t seg_e,
               LED7_GPIO_t seg_f,
               LED7_GPIO_t seg_g,
               LED7_Type_t type);

void LED7_Display(LED7_Handle_t *hLED, uint8_t num);

#endif
