#include <GyverPWM.h>

void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
  // Данные функции НЕ УБИРАЮТ один ШИМ выход у 8-ми битных таймеров, оставляя нам ШИМ пины D3, D5, D9 и D10 на ATmega328

  PWM_prescaler(3, 1);  // установить частоту ШИМ на пине D3 равной 31.4 кГц (см. таблицу №2 в GyverPWM.h)
  // частота автоматически будет установлена для пина D11!

  PWM_prescaler(6, 2);  // установить частоту ШИМ на пине D6 равной 7.8 кГц (см. таблицу №2 в GyverPWM.h)
  // частота автоматически будет установлена для пина D5! Также это сломает millis() и delay()

  PWM_prescaler(9, 1);  // установить частоту ШИМ на пине D9 равной 7.8 кГц (см. таблицу №2 в GyverPWM.h)
  // частота автоматически будет установлена для пина D10!

  PWM_mode(9, 1);       // установить режим работы таймера 1 в Fast PWM. Частота будет 15.6 кГц (см. таблицу №2 в GyverPWM.h)
  // режим автоматически будет установлен для пина D10!
}

void loop() {
  // можем пользоваться ШИМом на всех 6-ти пинах!
  analogWrite(3, 123);
  analogWrite(5, 241);
  analogWrite(6, 26);
  analogWrite(9, 98);
  analogWrite(10, 165);
  analogWrite(11, 152);
}
