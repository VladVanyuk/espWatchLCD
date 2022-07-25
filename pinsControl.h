#define buttonPin D3


#define potPin A0
uint16_t potValue = 0;


#define bulbPin D8
uint16_t bulbValue = 0;

#define ledPin D4
uint16_t ledBrigh = 0;



// ********** Переменные для энкодера ***************

#define CLK D5
#define DT D6
#define SW D7
#define BINARY_ALGORITHM
bool lineSelected = 0;

Encoder enc1(CLK, DT, SW);
