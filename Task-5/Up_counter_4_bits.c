#include<stdio.h>
#include<debug.h>
#include<ch32v00x.h>

// GPIO Configuration Function
void GPIO_Config(void) {
    GPIO_InitTypeDef GPIO_InitStructure = {0}; // GPIO configuration structure

    // Enable clocks for the required GPIO ports
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); // Enable clock for Port C

    // Configure output pins (for LEDs)
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // Configure as push-pull output
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Set output speed
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

// Simple delay function
void Delay_ms(uint32_t ms) {
    uint32_t count;
    while (ms--) {
        for (count = 0; count < 8000; count++); // Approx. delay for 1ms (tune as needed)
    }
}

// Main Function
int main(void) {
    uint8_t counter = 0; // 4-bit counter (0 to 15)

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // Set priority grouping
    SystemCoreClockUpdate();                       // Update system clock
    Delay_Init();                                  // Initialize delay
    GPIO_Config();                                 // Initialize GPIO

    while (1) {
        // Write the 4-bit counter value to GPIO pins
        GPIO_Write(GPIOC, (counter & 0x0F)); // Only use the lower 4 bits of the counter

        // Increment counter (wraps around after 15)
        counter = (counter + 1) & 0x0F; // Keep counter within 4 bits

        // Add a delay for visibility
        Delay_ms(500); // 500ms delay for visible LED changes
    }
}
