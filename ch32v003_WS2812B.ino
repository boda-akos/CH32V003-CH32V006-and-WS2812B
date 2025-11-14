
// Maximum number of LEDs supported by the library
#define WS_MAX_LEDS 256
typedef struct {
    byte r;  // Red component (0-255)
    byte g;  // Green component (0-255)
    byte b;  // Blue component (0-255)
} WS_Color;

// Pre-defined colors
#define WS_RED (WS_Color){255, 0, 0}
#define WS_GREEN (WS_Color){0, 255, 0}
#define WS_BLUE (WS_Color){0, 0, 255}
#define WS_WHITE (WS_Color){255, 255, 255}
#define WS_BLACK (WS_Color){0, 0, 0}
#define WS_PURPLE (WS_Color){128, 0, 128}
#define WS_YELLOW (WS_Color){255, 255, 0}
#define WS_CYAN (WS_Color){0, 255, 255}
#define WS_ORANGE (WS_Color){255, 165, 0}
#define WS_PINK (WS_Color){255, 20, 147}

byte global_brightness=0x40;
byte led_count=8;
void WS_SetBrightness(byte brightness);
void WS_SetPixel(byte index, WS_Color color);
void WS_Fill(WS_Color color);
void WS_Clear(void);
void WS_Show(void);

WS_Color WS_RGB(byte r, byte g, byte b);
static WS_Color led_buffer[WS_MAX_LEDS];

void setup() {

/*  This section used with PCBs with no external quartz (internal 24Mhz oscillator)
    RCC->CTLR |= RCC_PLLON;          // Enable PLL 48MHz 
    while(!(RCC->CTLR & RCC_PLLRDY)); // Wait for PLL lock
    RCC->CFGR0 |= 0;    // No clock division
    RCC->CFGR0 &= ~RCC_SW;            // Clear clock source
    RCC->CFGR0 |= RCC_SW_PLL;         // Switch to PLL (48 MHz)
    while((RCC->CFGR0 & RCC_SWS) != RCC_SWS_PLL); // Wait for switch
*/
pinMode(PC4, OUTPUT);
        // Fill all LEDs with red
        WS_Fill(WS_BLACK);
        WS_Show(); delay(1000); // Set individual LED colors
        WS_SetPixel(0, WS_RED);WS_SetPixel(1, WS_GREEN);WS_SetPixel(2, WS_BLUE);
        WS_SetPixel(3, WS_CYAN);WS_SetPixel(4, WS_PURPLE);WS_SetPixel(5, WS_ORANGE);WS_SetPixel(6, WS_PURPLE);WS_SetPixel(7, WS_ORANGE);
        WS_Show();
        //delay(5000);
//while(1) {send_bit(1);}  //Oscilloscope waveform check 
/*Serial.begin(9600); for(int i = 0; i < 255; i ++) Serial.println(i);//serial warmup
Serial.println();
Serial.println("Table");
for (byte i=0; i<8; i++) {
Serial.print(led_buffer[i].r);Serial.print("  "); Serial.print(led_buffer[i].g); Serial.print("  "); Serial.print(led_buffer[i].b);
Serial.println(); }*/
}


void loop(void) {

   // Set brightness (0-255)
     WS_SetBrightness(100);

    while(1) {
        // Fill all LEDs with red
        WS_Fill(WS_RED);
        WS_Show();
        delay(2500);

        // Set individual LED colors
        WS_SetPixel(0, WS_RED);
        WS_SetPixel(1, WS_GREEN);
        WS_SetPixel(2, WS_BLUE);
        WS_Show();
        delay(2500);

        // Create custom colors
        WS_Color purple = WS_RGB(128, 0, 128);
        WS_Fill(purple);
        WS_Show();
        delay(2500);

    }
}

static void send_bit(byte x) { 
    if (x) {// Send a 1 bit (high for 0.8us, low for 0.45us, tolerance 150usec)
        GPIOC->OUTDR |=(1<<4);  // Set high
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop"); __asm__ volatile ("nop"); 
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop"); __asm__ volatile ("nop"); 
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop"); __asm__ volatile ("nop"); 
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop"); __asm__ volatile ("nop"); __asm__ volatile ("nop");  __asm__ volatile ("nop"); 
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop"); 

         GPIOC->OUTDR &=~(1<<4);    // Set low 
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop"); __asm__ volatile ("nop"); 
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop"); __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop"); 
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop"); 
        }
else { // Send a 0 bit (high for 0.4us, low for 0.85us, tolerance 150usec)
         GPIOC->OUTDR |=(1<<4);   
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop"); __asm__ volatile ("nop"); 
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop"); 
        GPIOC->OUTDR &=~(1<<4);  // Set low
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop"); __asm__ volatile ("nop"); 
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop"); __asm__ volatile ("nop"); 
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop"); __asm__ volatile ("nop"); 
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop"); 
 __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  __asm__ volatile ("nop");  
}  
//GPIOC->OUTDR |=(1<<4); GPIOC->OUTDR &=~(1<<4); //Marker for oscilloscope waveform check
}

// Send a byte to WS2812B
static void send_byte(byte b) {
for (byte x=0x80; x > 0; x/=2) send_bit(b & x);
}

// Send array data to LED strip
void WS_Show(void) {

        for (byte i = 0; i < led_count; i++) {
        byte r = gen_bright(led_buffer[i].r);
        byte g = gen_bright(led_buffer[i].g);
        byte b = gen_bright(led_buffer[i].b);

        // send WS2812B GRB data 
        send_byte(g);
        send_byte(r);
        send_byte(b);    
    }
  //GPIOC->OUTDR &=~(1<<4);  //exit with Data pin=Low
    delayMicroseconds(100);  // Reset pulse delay >50us 
}

// Fill all LEDs with the same color
void WS_Fill(WS_Color color) {
 
    for (byte i = 0; i < led_count; i++) {
        led_buffer[i] = color;
    }
}

// Clear all LEDs 
void WS_Clear(void) {
    WS_Fill(WS_BLACK);
}


// Set global brightness
void WS_SetBrightness(byte brightness) {
    global_brightness = brightness;
}

// Set pixel color 
void WS_SetPixel(byte index, WS_Color color) {
    led_buffer[index] = color;
}

// Apply brightness 
static byte gen_bright(byte color) {
    return (uint16_t)color * global_brightness / 255;
}

// Create RGB color
WS_Color WS_RGB(byte r, byte g, byte b) {
    WS_Color color = {r, g, b};
    return color;
}
