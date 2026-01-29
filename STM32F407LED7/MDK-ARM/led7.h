#ifndef _LED_7
#define _LED_7

#include "stm32f4xx_hal.h"

typedef struct 
{
	 GPIO_TypeDef *port;
   uint16_t pin;
	
}LED7_GPIO_t;

typedef enum
{
	LED_ANODE,
	LED_CATHODE,
}LED7_Type_t;

typedef struct
{
	LED7_GPIO_t seg[7];
	LED7_Type_t type;
}LED7_Handle_t;

static uint8_t seg_code[10] = 
{
		0x3F,
		0x06,
		0x5B,
		0x4F,
		0x66,
		0x7D,
		0x07,
		0x7F,
		0x6F,
};
	

void LED7_Init(LED7_Handle_t *hLED, LED7_GPIO_t seg_a, 
	LED7_GPIO_t seg_b, LED7_GPIO_t seg_c, 
	LED7_GPIO_t seg_d, LED7_GPIO_t seg_e, 
	LED7_GPIO_t seg_f, LED7_GPIO_t seg_g, LED7_Type_t type)
{
	hLED->type =type;
	hLED->seg[0] =seg_a;
	hLED->seg[1] =seg_b;
	hLED->seg[2] =seg_c;
	hLED->seg[3] =seg_d;
	hLED->seg[4] =seg_e;
	hLED->seg[5] =seg_f;
	hLED->seg[6] =seg_g;
}

void LED7_Display(LED7_Handle_t *hLED, uint8_t num)
{
	if(num>9){return;}
	uint8_t data =seg_code[num];
	
	for(int i = 0; i < 7; i++)
	{
		uint8_t bit = (data >> i) & (0x01);
		GPIO_PinState state;
		if(hLED->type == LED_ANODE)
		{
			state = bit ? GPIO_PIN_RESET : GPIO_PIN_SET;
		}
		else
		{
			state = bit ? GPIO_PIN_SET : GPIO_PIN_RESET;
		}
		
		HAL_GPIO_WritePin(hLED->seg[i].port, hLED->seg[i].pin, state);
		
	}
}

#endif




