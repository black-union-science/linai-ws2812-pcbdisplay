 #include <FastLED.h>
#define biaoqingnum 10
#define NUM_LEDS 269            //LED数量
#define DATA_PIN 3              //数据线
#define COLOR_NUM 11            //颜色库数量
CRGB leds[NUM_LEDS];
const byte INPUT_Pin[4] = {5,6,7,8}; //按键 A B
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
//unsigned long color[COLOR_NUM][3] = {{0, 0, 0}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 35, 0}, {255, 255, 255}, {0, 255, 255}, {255, 255, 15}, {10, 240, 187}, {255, 4, 255}, {239, 73, 149}}; //颜色库，第一个括号颜色数量
//unsigned long color[8][3] = {{0, 0, 0},{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 0}, {0, 255, 255}, {255, 255, 255}, {249, 204, 226}};//, {255, 255, 255}
//line162,line182
void setup()
{
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(Brightness);  //可以设置全局亮度，调低亮度不刺眼
  Serial.begin(9600);
  for (byte i = 0; i < 4; i++)
    pinMode(INPUT_Pin[i], INPUT_PULLUP);
  timers[3] = millis();
  //====================================开机自检，刷新全屏（由于未知的bug，有可能会刷新到249号灯停止，不影响正常使用）
  for (int i = 0; i <= 270; i++) {
    leds[i] = CRGB ( R, G, B);
    FastLED.show();
    R = 100;
    G = 100;
    B = 100;
    delay(40);
  }
  delay(500);
  R = 0;
  G = 0;
  B = 0;
  for (int i = 270; i >= 0; i--) {
    leds[i] = CRGB ( R, G, B);
    FastLED.show();}
    delay(40);
    //=======由黑联科技辅助工具生成======
    

  
  //====================================
}

void loop()   //把这玩意删了就过不去编译，不知道为啥，不建议删除
{
  if (!Press_button && !digitalRead(INPUT_Pin[0]))
  {
    timers[0] = millis();
    Press_button = true;
  }

}
