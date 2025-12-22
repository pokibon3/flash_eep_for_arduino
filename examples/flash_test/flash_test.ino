//#include <Arduino.h>
#include "flash_eep.h"

extern FLASH_EEP eep; // global instance defined in flash_test.cpp

void print_hex(const uint8_t *buf, size_t len)
{
    for (size_t i = 0; i < len; i++) {
        if (buf[i] < 16) Serial.print('0');
        Serial.print(buf[i], HEX);
        if (i + 1 < len) Serial.print(' ');
    }
    Serial.println();
}

void setup() {
    Serial.begin(115200);
    while (!Serial) { delay(10); }
    delay(100);
    Serial.println("flash_test_arduino: start");

    int r = eep.begin(2u);
    Serial.print("eep.begin: "); Serial.println(r);

    // simple write/read test
    uint8_t wbuf[FLASH_PAGE_SIZE];
    for (uint32_t i = 0; i < FLASH_PAGE_SIZE; i++) wbuf[i] = (uint8_t)(i + 1);

    r = eep.write(0, wbuf);
    Serial.print("write page 0: "); Serial.println(r);

    uint8_t rbuf[FLASH_PAGE_SIZE];
    r = eep.read(0, rbuf);
    Serial.print("read page 0: "); Serial.println(r);
    if (r == 0) {
        Serial.print("data[0..15]: ");
        print_hex(rbuf, 16);
    }
}

void loop() {
    delay(1000);
}
