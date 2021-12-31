#include <FastLED.h>
#define biaoqingnum 10          //表情的数量，如果需要删改表情的话要改这里
#define NUM_LEDS 269            //LED数量
#define DATA_PIN 3              //数据线
#define COLOR_NUM 11            //颜色库数量
CRGB leds[NUM_LEDS];
const byte INPUT_Pin[4] = {5,6,7,8}; //四个按键
int Modes = -1;
int Color_num = 0;
int Brightness = 10;
int Liquid = 0;
int R;
int G;
int B;
int mode01;
//int R2;
//int G2;
//int B2;
bool C=1;
bool D=1;
bool Brightness_button = true;
bool Brightness_button1 = true;
bool Press_button = false;
bool star = true;
bool butmod = true;
unsigned long timers[4] = {0};
void setup()
{
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(Brightness);  //可以设置全局亮度，调低亮度不刺眼
  Serial.begin(9600);
  for (byte i = 0; i < 4; i++)
    pinMode(INPUT_Pin[i], INPUT_PULLUP);
  Refresh();
  timers[3] = millis();
  //====================================开机自检
  for (int i = 0; i <= 30; i++) {
    leds[i] = CRGB ( R, G, B);
    FastLED.show();
    R = 30;
    //G = 30;
    B = 30;
    delay(40);
  }
  delay(500);
  R = 0;
  G = 0;
  B = 0;
  for (int i = 18; i >= 0; i--) {
    leds[i] = CRGB ( R, G, B);
    FastLED.show();}
    delay(40);
   startrunning();
    //=======由黑联科技辅助工具生成======
    

  
  //====================================
}

void loop()//按钮按键判断
{
  if (!Press_button && !digitalRead(INPUT_Pin[0]))
  {
    timers[0] = millis();
    Press_button = true;
  }
  else if (Press_button && digitalRead(INPUT_Pin[0]))
  {
    unsigned long Buf = millis();
    if (Buf - timers[0] >= 1500) {
      longpress();
    }
    else if (Buf - timers[0] < 1500 && Buf - timers[0] >= 50) {
      shortpress1();
    }
    timers[0] = millis();
    Press_button = false;
  }
  //=====================================
  if (!Brightness_button1 && !digitalRead(INPUT_Pin[1]))
  {
    timers[1] = millis();
    Brightness_button1 = true;
  }
  else if (Brightness_button1 && digitalRead(INPUT_Pin[1]))
  {
    unsigned long Buf = millis();
    if (Buf - timers[1] >= 1500)
      longpress3();
    else if (Buf - timers[1] < 1500 && Buf - timers[1] >= 50)
      shortpress2();
    timers[0] = millis();
    Brightness_button1 = false;
  }
  if (millis() - timers[3] >= 100)
  {
    //Refresh();
    timers[3] = millis();
  }
  if (digitalRead(7)==0 && C==1){
    C=0;
    modeC();
    delay(100);
  }
  if (digitalRead(7)==1)
  C=1;
  if (digitalRead(8)==0 && D==1){
    D=0;
    modeD();
    delay(100);
  }
  if (digitalRead(8)==1)
  D=1;
}
void Refresh()
{
  switch (Modes)//如果要修改表情的话从这里改
  {
    case 0:     //表情，从0开始数
      R = 255;
      G = 0;
      B = 255;      //RGB值，可以自定义显示的颜色
      for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB ( 0, 0, 0);
      }
      //=======由黑联科技辅助工具生成======
leds[36] = CRGB(R,G,B);
leds[35] = CRGB(R,G,B);
leds[34] = CRGB(R,G,B);
leds[33] = CRGB(R,G,B);
leds[32] = CRGB(R,G,B);
leds[45] = CRGB(R,G,B);
leds[44] = CRGB(R,G,B);
leds[42] = CRGB(R,G,B);
leds[41] = CRGB(R,G,B);
leds[43] = CRGB(R,G,B);
leds[233] = CRGB(R,G,B);
leds[227] = CRGB(R,G,B);
leds[228] = CRGB(R,G,B);
leds[235] = CRGB(R,G,B);
leds[234] = CRGB(R,G,B);
leds[226] = CRGB(R,G,B);
leds[225] = CRGB(R,G,B);
leds[236] = CRGB(R,G,B);
leds[237] = CRGB(R,G,B);
leds[224] = CRGB(R,G,B);
leds[221] = CRGB(R,G,B);
leds[220] = CRGB(R,G,B);
leds[209] = CRGB(R,G,B);
leds[208] = CRGB(R,G,B);
leds[61] = CRGB(R,G,B);
leds[60] = CRGB(R,G,B);
leds[49] = CRGB(R,G,B);
leds[48] = CRGB(R,G,B);
leds[50] = CRGB(R,G,B);
leds[59] = CRGB(R,G,B);
leds[83] = CRGB(R,G,B);
leds[210] = CRGB(R,G,B);
leds[219] = CRGB(R,G,B);
leds[58] = CRGB(R,G,B);
leds[211] = CRGB(R,G,B);
leds[186] = CRGB(R,G,B);
leds[185] = CRGB(R,G,B);
leds[180] = CRGB(R,G,B);
leds[84] = CRGB(R,G,B);
leds[89] = CRGB(R,G,B);
leds[90] = CRGB(R,G,B);
leds[116] = CRGB(R,G,B);
leds[115] = CRGB(R,G,B);
leds[122] = CRGB(R,G,B);
leds[147] = CRGB(R,G,B);
leds[154] = CRGB(R,G,B);
leds[153] = CRGB(R,G,B);
leds[179] = CRGB(R,G,B);
leds[148] = CRGB(R,G,B);
leds[121] = CRGB(R,G,B);
break;
    case 1: //face0
      R = 255;
      G = 0;
      B = 255;
      //先清空颜色
      for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB ( 0, 0, 0);
      }
      //=======由黑联科技辅助工具生成======
     //=======由黑联科技辅助工具生成======
leds[251] = CRGB(R,G,B);
leds[240] = CRGB(R,G,B);
leds[221] = CRGB(R,G,B);
leds[249] = CRGB(R,G,B);
leds[242] = CRGB(R,G,B);
leds[219] = CRGB(R,G,B);
leds[18] = CRGB(R,G,B);
leds[48] = CRGB(R,G,B);
leds[29] = CRGB(R,G,B);
leds[20] = CRGB(R,G,B);
leds[27] = CRGB(R,G,B);
leds[50] = CRGB(R,G,B);
leds[82] = CRGB(R,G,B);
leds[90] = CRGB(R,G,B);
leds[115] = CRGB(R,G,B);
leds[123] = CRGB(R,G,B);
leds[147] = CRGB(R,G,B);
leds[154] = CRGB(R,G,B);
leds[179] = CRGB(R,G,B);
leds[187] = CRGB(R,G,B);
leds[188] = CRGB(R,G,B);
leds[238] = CRGB(R,G,B);
leds[233] = CRGB(R,G,B);
leds[227] = CRGB(R,G,B);
leds[202] = CRGB(R,G,B);
leds[194] = CRGB(R,G,B);
leds[204] = CRGB(R,G,B);
leds[225] = CRGB(R,G,B);
leds[237] = CRGB(R,G,B);
leds[254] = CRGB(R,G,B);
leds[73] = CRGB(R,G,B);
leds[74] = CRGB(R,G,B);
leds[75] = CRGB(R,G,B);
leds[76] = CRGB(R,G,B);
leds[66] = CRGB(R,G,B);
leds[65] = CRGB(R,G,B);
leds[67] = CRGB(R,G,B);
leds[68] = CRGB(R,G,B);
      
      break;
    case 2: //face1
      R = 255;
      G = 0;
      B = 255;
      //先清空颜色
      for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB ( 0, 0, 0);
      }
      //=======由黑联科技辅助工具生成======
      //=======由黑联科技辅助工具生成======
leds[36] = CRGB(R,G,B);
leds[36] = CRGB(R,G,B);
leds[35] = CRGB(R,G,B);
leds[34] = CRGB(R,G,B);
leds[34] = CRGB(R,G,B);
leds[33] = CRGB(R,G,B);
leds[44] = CRGB(R,G,B);
leds[65] = CRGB(R,G,B);
leds[76] = CRGB(R,G,B);
leds[68] = CRGB(R,G,B);
leds[67] = CRGB(R,G,B);
leds[66] = CRGB(R,G,B);
leds[64] = CRGB(R,G,B);
leds[63] = CRGB(R,G,B);
leds[132] = CRGB(R,G,B);
leds[137] = CRGB(R,G,B);
leds[106] = CRGB(R,G,B);
leds[107] = CRGB(R,G,B);
leds[108] = CRGB(R,G,B);
leds[109] = CRGB(R,G,B);
leds[127] = CRGB(R,G,B);
leds[142] = CRGB(R,G,B);
leds[160] = CRGB(R,G,B);
leds[161] = CRGB(R,G,B);
leds[162] = CRGB(R,G,B);
leds[163] = CRGB(R,G,B);
leds[196] = CRGB(R,G,B);
leds[195] = CRGB(R,G,B);
leds[194] = CRGB(R,G,B);
leds[193] = CRGB(R,G,B);
leds[204] = CRGB(R,G,B);
leds[225] = CRGB(R,G,B);
leds[228] = CRGB(R,G,B);
leds[227] = CRGB(R,G,B);
leds[226] = CRGB(R,G,B);
leds[224] = CRGB(R,G,B);
leds[223] = CRGB(R,G,B);
leds[236] = CRGB(R,G,B);
leds[223] = CRGB(R,G,B);
leds[113] = CRGB(R,G,B);
leds[123] = CRGB(R,G,B);
leds[147] = CRGB(R,G,B);
leds[153] = CRGB(R,G,B);
leds[156] = CRGB(R,G,B);
leds[146] = CRGB(R,G,B);
leds[122] = CRGB(R,G,B);
leds[116] = CRGB(R,G,B);
leds[49] = CRGB(R,G,B);
leds[50] = CRGB(R,G,B);
leds[51] = CRGB(R,G,B);
leds[53] = CRGB(R,G,B);
leds[220] = CRGB(R,G,B);
leds[219] = CRGB(R,G,B);
leds[219] = CRGB(R,G,B);
leds[218] = CRGB(R,G,B);
leds[216] = CRGB(R,G,B);
      FastLED.show();
      delay(50);

      break;
    case 3: //face2
      R = 255;
      G = 0;
      B = 255;
      //先清空颜色
      for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB ( 0, 0, 0);
      }
      //=======由黑联科技辅助工具生成======
leds[34] = CRGB(R,G,B);
leds[45] = CRGB(R,G,B);
leds[64] = CRGB(R,G,B);
leds[33] = CRGB(R,G,B);
leds[76] = CRGB(R,G,B);
leds[75] = CRGB(R,G,B);
leds[67] = CRGB(R,G,B);
leds[42] = CRGB(R,G,B);
leds[43] = CRGB(R,G,B);
leds[44] = CRGB(R,G,B);
leds[65] = CRGB(R,G,B);
leds[235] = CRGB(R,G,B);
leds[236] = CRGB(R,G,B);
leds[227] = CRGB(R,G,B);
leds[202] = CRGB(R,G,B);
leds[194] = CRGB(R,G,B);
leds[193] = CRGB(R,G,B);
leds[205] = CRGB(R,G,B);
leds[224] = CRGB(R,G,B);
leds[203] = CRGB(R,G,B);
leds[204] = CRGB(R,G,B);
leds[225] = CRGB(R,G,B);
leds[223] = CRGB(R,G,B);
leds[253] = CRGB(R,G,B);
leds[239] = CRGB(R,G,B);
leds[57] = CRGB(R,G,B);
leds[58] = CRGB(R,G,B);
leds[82] = CRGB(R,G,B);
leds[91] = CRGB(R,G,B);
leds[114] = CRGB(R,G,B);
leds[211] = CRGB(R,G,B);
leds[212] = CRGB(R,G,B);
leds[187] = CRGB(R,G,B);
leds[178] = CRGB(R,G,B);
leds[155] = CRGB(R,G,B);
leds[146] = CRGB(R,G,B);
leds[123] = CRGB(R,G,B);
      break;
      
      case 4: //face2
      R = 255;
      G = 0;
      B = 255;
      //先清空颜色
      for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB ( 0, 0, 0);
      }
//=======由黑联科技辅助工具生成======
leds[35] = CRGB(R,G,B);
leds[41] = CRGB(R,G,B);
leds[68] = CRGB(R,G,B);
leds[74] = CRGB(R,G,B);
leds[66] = CRGB(R,G,B);
leds[63] = CRGB(R,G,B);
leds[234] = CRGB(R,G,B);
leds[228] = CRGB(R,G,B);
leds[201] = CRGB(R,G,B);
leds[195] = CRGB(R,G,B);
leds[226] = CRGB(R,G,B);
leds[223] = CRGB(R,G,B);
leds[225] = CRGB(R,G,B);
leds[65] = CRGB(R,G,B);
leds[92] = CRGB(R,G,B);
leds[113] = CRGB(R,G,B);
leds[188] = CRGB(R,G,B);
leds[156] = CRGB(R,G,B);
leds[177] = CRGB(R,G,B);
leds[145] = CRGB(R,G,B);
leds[124] = CRGB(R,G,B);
leds[91] = CRGB(R,G,B);
leds[89] = CRGB(R,G,B);
leds[90] = CRGB(R,G,B);
leds[187] = CRGB(R,G,B);
leds[185] = CRGB(R,G,B);
leds[186] = CRGB(R,G,B);
leds[180] = CRGB(R,G,B);
leds[153] = CRGB(R,G,B);
leds[148] = CRGB(R,G,B);
leds[121] = CRGB(R,G,B);
leds[116] = CRGB(R,G,B);

break;


case 5: //face2
      R = 255;
      G = 0;
      B = 255;
      //先清空颜色
      for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB ( 0, 0, 0);
      }
//=======由黑联科技辅助工具生成======
//=======由黑联科技辅助工具生成======
leds[41] = CRGB(R,G,B);
leds[68] = CRGB(R,G,B);
leds[68] = CRGB(R,G,B);
leds[73] = CRGB(R,G,B);
leds[100] = CRGB(R,G,B);
leds[105] = CRGB(R,G,B);
leds[132] = CRGB(R,G,B);
leds[137] = CRGB(R,G,B);
leds[164] = CRGB(R,G,B);
leds[169] = CRGB(R,G,B);
leds[196] = CRGB(R,G,B);
leds[201] = CRGB(R,G,B);
leds[228] = CRGB(R,G,B);
leds[197] = CRGB(R,G,B);
leds[195] = CRGB(R,G,B);
leds[74] = CRGB(R,G,B);
leds[72] = CRGB(R,G,B);
leds[76] = CRGB(R,G,B);
leds[77] = CRGB(R,G,B);
leds[78] = CRGB(R,G,B);
leds[79] = CRGB(R,G,B);
leds[97] = CRGB(R,G,B);
leds[108] = CRGB(R,G,B);
leds[108] = CRGB(R,G,B);
leds[129] = CRGB(R,G,B);
leds[140] = CRGB(R,G,B);
leds[161] = CRGB(R,G,B);
leds[172] = CRGB(R,G,B);
leds[193] = CRGB(R,G,B);
leds[192] = CRGB(R,G,B);
leds[189] = CRGB(R,G,B);
leds[190] = CRGB(R,G,B);
leds[191] = CRGB(R,G,B);
leds[176] = CRGB(R,G,B);
leds[157] = CRGB(R,G,B);
leds[144] = CRGB(R,G,B);
leds[125] = CRGB(R,G,B);
leds[112] = CRGB(R,G,B);
leds[93] = CRGB(R,G,B);
leds[80] = CRGB(R,G,B);
leds[95] = CRGB(R,G,B);
leds[110] = CRGB(R,G,B);
leds[127] = CRGB(R,G,B);
leds[159] = CRGB(R,G,B);
leds[142] = CRGB(R,G,B);
leds[174] = CRGB(R,G,B);
leds[90] = CRGB(R,G,B);
leds[115] = CRGB(R,G,B);
leds[179] = CRGB(R,G,B);
leds[154] = CRGB(R,G,B);
leds[122] = CRGB(R,G,B);
leds[147] = CRGB(R,G,B);
leds[145] = CRGB(R,G,B);
leds[123] = CRGB(R,G,B);
leds[146] = CRGB(R,G,B);
leds[124] = CRGB(R,G,B);
leds[121] = CRGB(R,G,B);
leds[120] = CRGB(R,G,B);
leds[119] = CRGB(R,G,B);
leds[150] = CRGB(R,G,B);
leds[148] = CRGB(R,G,B);
leds[149] = CRGB(R,G,B);
leds[83] = CRGB(R,G,B);
leds[186] = CRGB(R,G,B);


      break;


      case 6: //face2
      R = 255;
      G = 0;
      B = 255;
      //先清空颜色
      for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB ( 0, 0, 0);
      }
//=======由黑联科技辅助工具生成======
//=======由黑联科技辅助工具生成======
//=======由黑联科技辅助工具生成======
leds[35] = CRGB(R,G,B);
leds[42] = CRGB(R,G,B);
leds[66] = CRGB(R,G,B);
leds[75] = CRGB(R,G,B);
leds[97] = CRGB(R,G,B);
leds[77] = CRGB(R,G,B);
leds[64] = CRGB(R,G,B);
leds[46] = CRGB(R,G,B);
leds[31] = CRGB(R,G,B);
leds[234] = CRGB(R,G,B);
leds[227] = CRGB(R,G,B);
leds[203] = CRGB(R,G,B);
leds[194] = CRGB(R,G,B);
leds[172] = CRGB(R,G,B);
leds[192] = CRGB(R,G,B);
leds[223] = CRGB(R,G,B);
leds[238] = CRGB(R,G,B);
leds[205] = CRGB(R,G,B);
leds[29] = CRGB(R,G,B);
leds[61] = CRGB(R,G,B);
leds[240] = CRGB(R,G,B);
leds[208] = CRGB(R,G,B);
leds[81] = CRGB(R,G,B);
leds[188] = CRGB(R,G,B);
leds[178] = CRGB(R,G,B);
leds[91] = CRGB(R,G,B);
leds[115] = CRGB(R,G,B);
leds[154] = CRGB(R,G,B);
leds[147] = CRGB(R,G,B);
leds[122] = CRGB(R,G,B);
break;

case 7:
      R = 255;
      G = 0;
      B = 255;
      for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB ( 0, 0, 0);
      }
//=======由黑联科技辅助工具生成======
leds[42] = CRGB(R,G,B);
leds[43] = CRGB(R,G,B);
leds[44] = CRGB(R,G,B);
leds[45] = CRGB(R,G,B);
leds[67] = CRGB(R,G,B);
leds[66] = CRGB(R,G,B);
leds[65] = CRGB(R,G,B);
leds[64] = CRGB(R,G,B);
leds[48] = CRGB(R,G,B);
leds[18] = CRGB(R,G,B);
leds[251] = CRGB(R,G,B);
leds[221] = CRGB(R,G,B);
leds[253] = CRGB(R,G,B);
leds[238] = CRGB(R,G,B);
leds[224] = CRGB(R,G,B);
leds[205] = CRGB(R,G,B);
leds[193] = CRGB(R,G,B);
leds[203] = CRGB(R,G,B);
leds[226] = CRGB(R,G,B);
leds[234] = CRGB(R,G,B);
leds[237] = CRGB(R,G,B);
leds[82] = CRGB(R,G,B);
leds[187] = CRGB(R,G,B);
leds[90] = CRGB(R,G,B);
leds[115] = CRGB(R,G,B);
leds[122] = CRGB(R,G,B);
leds[147] = CRGB(R,G,B);
leds[154] = CRGB(R,G,B);
leds[179] = CRGB(R,G,B);
break;

case 8:
      R = 255;
      G = 0;
      B = 255;
      for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB ( 0, 0, 0);
      }
//=======由黑联科技辅助工具生成======
//=======由黑联科技辅助工具生成======
leds[235] = CRGB(R,G,B);
leds[226] = CRGB(R,G,B);
leds[236] = CRGB(R,G,B);
leds[225] = CRGB(R,G,B);
leds[204] = CRGB(R,G,B);
leds[193] = CRGB(R,G,B);
leds[205] = CRGB(R,G,B);
leds[224] = CRGB(R,G,B);
leds[34] = CRGB(R,G,B);
leds[33] = CRGB(R,G,B);
leds[43] = CRGB(R,G,B);
leds[44] = CRGB(R,G,B);
leds[65] = CRGB(R,G,B);
leds[76] = CRGB(R,G,B);
leds[45] = CRGB(R,G,B);
leds[64] = CRGB(R,G,B);
leds[48] = CRGB(R,G,B);
leds[18] = CRGB(R,G,B);
leds[251] = CRGB(R,G,B);
leds[221] = CRGB(R,G,B);
leds[82] = CRGB(R,G,B);
leds[187] = CRGB(R,G,B);
leds[90] = CRGB(R,G,B);
leds[115] = CRGB(R,G,B);
leds[122] = CRGB(R,G,B);
leds[147] = CRGB(R,G,B);
leds[154] = CRGB(R,G,B);
leds[179] = CRGB(R,G,B);
break;

case 9:
      R = 255;
      G = 0;
      B = 255;
      for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB ( 0, 0, 0);
      }
//=======由黑联科技辅助工具生成======
//=======由黑联科技辅助工具生成======
leds[235] = CRGB(R,G,B);
leds[236] = CRGB(R,G,B);
leds[225] = CRGB(R,G,B);
leds[226] = CRGB(R,G,B);
leds[204] = CRGB(R,G,B);
leds[193] = CRGB(R,G,B);
leds[205] = CRGB(R,G,B);
leds[224] = CRGB(R,G,B);
leds[34] = CRGB(R,G,B);
leds[43] = CRGB(R,G,B);
leds[33] = CRGB(R,G,B);
leds[44] = CRGB(R,G,B);
leds[65] = CRGB(R,G,B);
leds[76] = CRGB(R,G,B);
leds[45] = CRGB(R,G,B);
leds[64] = CRGB(R,G,B);
leds[17] = CRGB(R,G,B);
leds[47] = CRGB(R,G,B);
leds[252] = CRGB(R,G,B);
leds[222] = CRGB(R,G,B);
leds[190] = CRGB(R,G,B);
leds[79] = CRGB(R,G,B);
leds[93] = CRGB(R,G,B);
leds[92] = CRGB(R,G,B);
leds[91] = CRGB(R,G,B);
leds[176] = CRGB(R,G,B);
leds[177] = CRGB(R,G,B);
leds[178] = CRGB(R,G,B);
leds[83] = CRGB(R,G,B);
leds[186] = CRGB(R,G,B);
leds[113] = CRGB(R,G,B);
leds[124] = CRGB(R,G,B);
leds[145] = CRGB(R,G,B);
leds[156] = CRGB(R,G,B);
      break;

  }

      FastLED.setBrightness(Brightness);
      FastLED.show();
  }

void shortpress2()
{
  if (!butmod) {
    Color_num--;
    Modes--;
    if (Color_num < 0)
      Color_num = 10;//颜色数量
    Serial.print("颜色: ");
    Serial.println(Color_num + 1);
  } else {
    if (Modes == -1)Modes = biaoqingnum;
    Brightness = Brightness - 25;
    if (Brightness < 0)
      Brightness = 250;
    Serial.print("亮度: ");
    Serial.println(Brightness);
  }
  Refresh();
    if (Modes > biaoqingnum)
    Modes = 0;
    if (Modes == -1)
    Modes = biaoqingnum;
     Serial.print(Modes);
}
void shortpress1()
{
  Serial.println("短按");
  if (!butmod) {
    Color_num++;
    Modes++;
    if (Color_num > 10)//颜色+，颜色数量
      Color_num = 0;
    Serial.print("颜色: ");
    Serial.println(Color_num + 1);
  } else {
    Brightness = Brightness + 25;
    if (Brightness > 250)
      Brightness = 0;
    Serial.print("亮度: ");
    Serial.println(Brightness);
  }
    if (Modes > biaoqingnum)
    Modes = 0;
    if (Modes == -1)
    Modes = biaoqingnum;
     Serial.print(Modes);

  Refresh();
}
void shortpress()//亮度调节
{
  Serial.println("短按");
  if (Modes == -1)Modes = 0;
  Brightness_button = !Brightness_button;
  Refresh();
}
void longpress()
{
  Serial.println("长按");
  if (Modes > biaoqingnum)
    Modes = 0;
  Serial.print("模式: ");
  Serial.println(Modes + 1);
  if (Modes == -1)
  Modes = 0;
  Refresh();
}
void longpress3()
{
  Serial.println("长按");
  butmod = !butmod;
  if (Modes == -1)Modes = 0;
  Refresh();
}

void startrunning(){       //开机自检画面，可以自行修改
      R = 255;
      G = 0;
      B = 255;
rest();
  leds[12] = CRGB(R,G,B);
leds[13] = CRGB(R,G,B);
leds[14] = CRGB(R,G,B);
leds[15] = CRGB(R,G,B);
leds[16] = CRGB(R,G,B);
leds[67] = CRGB(R,G,B);
leds[66] = CRGB(R,G,B);
leds[65] = CRGB(R,G,B);
leds[64] = CRGB(R,G,B);
leds[63] = CRGB(R,G,B);
leds[33] = CRGB(R,G,B);
leds[44] = CRGB(R,G,B);
leds[99] = CRGB(R,G,B);
leds[98] = CRGB(R,G,B);
leds[97] = CRGB(R,G,B);
leds[96] = CRGB(R,G,B);
leds[95] = CRGB(R,G,B);
leds[110] = CRGB(R,G,B);
leds[127] = CRGB(R,G,B);
leds[163] = CRGB(R,G,B);
leds[162] = CRGB(R,G,B);
leds[161] = CRGB(R,G,B);
leds[160] = CRGB(R,G,B);
leds[159] = CRGB(R,G,B);
leds[195] = CRGB(R,G,B);
leds[171] = CRGB(R,G,B);
leds[172] = CRGB(R,G,B);
leds[192] = CRGB(R,G,B);
leds[206] = CRGB(R,G,B);
leds[234] = CRGB(R,G,B);
leds[237] = CRGB(R,G,B);
leds[241] = CRGB(R,G,B);
leds[236] = CRGB(R,G,B);
leds[255] = CRGB(R,G,B);
leds[254] = CRGB(R,G,B);
leds[238] = CRGB(R,G,B);
FastLED.show();
delay(300);
rest();

//=======由黑联科技辅助工具生成======
leds[68] = CRGB(R,G,B);
leds[67] = CRGB(R,G,B);
leds[66] = CRGB(R,G,B);
leds[65] = CRGB(R,G,B);
leds[64] = CRGB(R,G,B);
leds[63] = CRGB(R,G,B);
leds[78] = CRGB(R,G,B);
leds[95] = CRGB(R,G,B);
leds[201] = CRGB(R,G,B);
leds[202] = CRGB(R,G,B);
leds[203] = CRGB(R,G,B);
leds[204] = CRGB(R,G,B);
leds[205] = CRGB(R,G,B);
leds[206] = CRGB(R,G,B);
leds[191] = CRGB(R,G,B);
leds[174] = CRGB(R,G,B);
leds[159] = CRGB(R,G,B);
leds[142] = CRGB(R,G,B);
leds[127] = CRGB(R,G,B);
leds[110] = CRGB(R,G,B);
leds[73] = CRGB(R,G,B);
leds[100] = CRGB(R,G,B);
leds[105] = CRGB(R,G,B);
leds[132] = CRGB(R,G,B);
leds[137] = CRGB(R,G,B);
leds[164] = CRGB(R,G,B);
leds[169] = CRGB(R,G,B);
leds[196] = CRGB(R,G,B);
leds[131] = CRGB(R,G,B);
leds[130] = CRGB(R,G,B);
leds[129] = CRGB(R,G,B);
leds[128] = CRGB(R,G,B);
leds[138] = CRGB(R,G,B);
leds[139] = CRGB(R,G,B);
leds[140] = CRGB(R,G,B);
leds[141] = CRGB(R,G,B);
leds[194] = CRGB(R,G,B);
leds[172] = CRGB(R,G,B);
leds[160] = CRGB(R,G,B);
leds[75] = CRGB(R,G,B);
leds[97] = CRGB(R,G,B);
leds[109] = CRGB(R,G,B);
leds[93] = CRGB(R,G,B);
leds[112] = CRGB(R,G,B);
leds[125] = CRGB(R,G,B);
leds[189] = CRGB(R,G,B);
leds[176] = CRGB(R,G,B);
leds[157] = CRGB(R,G,B);
leds[144] = CRGB(R,G,B);
leds[126] = CRGB(R,G,B);
leds[143] = CRGB(R,G,B);
leds[124] = CRGB(R,G,B);
leds[145] = CRGB(R,G,B);
leds[146] = CRGB(R,G,B);
leds[123] = CRGB(R,G,B);
leds[82] = CRGB(R,G,B);
leds[91] = CRGB(R,G,B);
leds[114] = CRGB(R,G,B);
leds[155] = CRGB(R,G,B);
leds[178] = CRGB(R,G,B);
leds[187] = CRGB(R,G,B);
leds[210] = CRGB(R,G,B);
leds[59] = CRGB(R,G,B);
leds[83] = CRGB(R,G,B);
leds[57] = CRGB(R,G,B);
leds[115] = CRGB(R,G,B);
leds[116] = CRGB(R,G,B);
leds[154] = CRGB(R,G,B);
leds[153] = CRGB(R,G,B);
leds[186] = CRGB(R,G,B);
leds[212] = CRGB(R,G,B);
leds[217] = CRGB(R,G,B);
FastLED.show();
delay(300);
rest();
//=======由黑联科技辅助工具生成======
leds[35] = CRGB(R,G,B);
leds[42] = CRGB(R,G,B);
leds[67] = CRGB(R,G,B);
leds[74] = CRGB(R,G,B);
leds[99] = CRGB(R,G,B);
leds[12] = CRGB(R,G,B);
leds[34] = CRGB(R,G,B);
leds[33] = CRGB(R,G,B);
leds[32] = CRGB(R,G,B);
leds[31] = CRGB(R,G,B);
leds[75] = CRGB(R,G,B);
leds[76] = CRGB(R,G,B);
leds[77] = CRGB(R,G,B);
leds[78] = CRGB(R,G,B);
leds[44] = CRGB(R,G,B);
leds[65] = CRGB(R,G,B);
leds[79] = CRGB(R,G,B);
leds[46] = CRGB(R,G,B);
leds[63] = CRGB(R,G,B);
leds[30] = CRGB(R,G,B);
leds[80] = CRGB(R,G,B);
leds[81] = CRGB(R,G,B);
leds[82] = CRGB(R,G,B);
leds[61] = CRGB(R,G,B);
leds[49] = CRGB(R,G,B);
leds[28] = CRGB(R,G,B);
leds[29] = CRGB(R,G,B);
leds[19] = CRGB(R,G,B);
leds[83] = CRGB(R,G,B);
leds[131] = CRGB(R,G,B);
leds[139] = CRGB(R,G,B);
leds[202] = CRGB(R,G,B);
leds[194] = CRGB(R,G,B);
leds[129] = CRGB(R,G,B);
leds[140] = CRGB(R,G,B);
leds[161] = CRGB(R,G,B);
leds[172] = CRGB(R,G,B);
leds[193] = CRGB(R,G,B);
leds[204] = CRGB(R,G,B);
leds[110] = CRGB(R,G,B);
leds[127] = CRGB(R,G,B);
leds[142] = CRGB(R,G,B);
leds[159] = CRGB(R,G,B);
leds[174] = CRGB(R,G,B);
leds[191] = CRGB(R,G,B);
leds[206] = CRGB(R,G,B);
leds[223] = CRGB(R,G,B);
leds[160] = CRGB(R,G,B);
leds[173] = CRGB(R,G,B);
leds[158] = CRGB(R,G,B);
leds[175] = CRGB(R,G,B);
leds[144] = CRGB(R,G,B);
leds[124] = CRGB(R,G,B);
leds[114] = CRGB(R,G,B);
leds[176] = CRGB(R,G,B);
leds[188] = CRGB(R,G,B);
leds[210] = CRGB(R,G,B);
leds[218] = CRGB(R,G,B);
FastLED.show();
delay(300);
rest();
//=======由黑联科技辅助工具生成======
leds[73] = CRGB(R,G,B);
leds[67] = CRGB(R,G,B);
leds[42] = CRGB(R,G,B);
leds[35] = CRGB(R,G,B);
leds[13] = CRGB(R,G,B);
leds[43] = CRGB(R,G,B);
leds[44] = CRGB(R,G,B);
leds[45] = CRGB(R,G,B);
leds[46] = CRGB(R,G,B);
leds[47] = CRGB(R,G,B);
leds[48] = CRGB(R,G,B);
leds[15] = CRGB(R,G,B);
leds[32] = CRGB(R,G,B);
leds[64] = CRGB(R,G,B);
leds[77] = CRGB(R,G,B);
leds[49] = CRGB(R,G,B);
leds[50] = CRGB(R,G,B);
leds[51] = CRGB(R,G,B);
leds[31] = CRGB(R,G,B);
leds[17] = CRGB(R,G,B);
leds[18] = CRGB(R,G,B);
leds[63] = CRGB(R,G,B);
leds[79] = CRGB(R,G,B);
leds[106] = CRGB(R,G,B);
leds[130] = CRGB(R,G,B);
leds[109] = CRGB(R,G,B);
leds[127] = CRGB(R,G,B);
leds[112] = CRGB(R,G,B);
leds[125] = CRGB(R,G,B);
leds[144] = CRGB(R,G,B);
leds[157] = CRGB(R,G,B);
leds[176] = CRGB(R,G,B);
leds[189] = CRGB(R,G,B);
leds[207] = CRGB(R,G,B);
leds[138] = CRGB(R,G,B);
leds[139] = CRGB(R,G,B);
leds[141] = CRGB(R,G,B);
leds[140] = CRGB(R,G,B);
leds[142] = CRGB(R,G,B);
leds[143] = CRGB(R,G,B);
leds[145] = CRGB(R,G,B);
leds[146] = CRGB(R,G,B);
leds[147] = CRGB(R,G,B);
FastLED.show();
delay(300);
rest();

//=======由黑联科技辅助工具生成======
leds[34] = CRGB(R,G,B);
leds[43] = CRGB(R,G,B);
leds[66] = CRGB(R,G,B);
leds[75] = CRGB(R,G,B);
leds[13] = CRGB(R,G,B);
leds[41] = CRGB(R,G,B);
leds[42] = CRGB(R,G,B);
leds[44] = CRGB(R,G,B);
leds[45] = CRGB(R,G,B);
leds[46] = CRGB(R,G,B);
leds[47] = CRGB(R,G,B);
leds[48] = CRGB(R,G,B);
leds[49] = CRGB(R,G,B);
leds[50] = CRGB(R,G,B);
leds[51] = CRGB(R,G,B);
leds[27] = CRGB(R,G,B);
leds[18] = CRGB(R,G,B);
leds[30] = CRGB(R,G,B);
leds[63] = CRGB(R,G,B);
leds[77] = CRGB(R,G,B);
leds[107] = CRGB(R,G,B);
leds[130] = CRGB(R,G,B);
leds[139] = CRGB(R,G,B);
leds[162] = CRGB(R,G,B);
leds[171] = CRGB(R,G,B);
leds[137] = CRGB(R,G,B);
leds[138] = CRGB(R,G,B);
leds[140] = CRGB(R,G,B);
leds[141] = CRGB(R,G,B);
leds[110] = CRGB(R,G,B);
leds[127] = CRGB(R,G,B);
leds[142] = CRGB(R,G,B);
leds[159] = CRGB(R,G,B);
leds[159] = CRGB(R,G,B);
leds[174] = CRGB(R,G,B);
leds[175] = CRGB(R,G,B);
leds[157] = CRGB(R,G,B);
leds[145] = CRGB(R,G,B);
leds[123] = CRGB(R,G,B);
leds[115] = CRGB(R,G,B);
leds[125] = CRGB(R,G,B);
leds[155] = CRGB(R,G,B);
leds[179] = CRGB(R,G,B);
leds[111] = CRGB(R,G,B);
FastLED.show();
delay(300);
rest();
}
void rest(){
  for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB ( 0, 0, 0);
        //FastLED.show();
        }
}

void modeC(){
  Serial.println("模式C");
  
}

void modeD(){
  Serial.println("模式D");
}
