# Arduino logging library

This library allows you to log data to an Arduino.
It supports Serial logging to the Arduino/ESP serial port.

***printf format support***

This library supports printf format strings.

e.g. ``%[flags][width][.precision][length]specifier``

* specifier
    | **specifier** | **Output** | **Example ** |
    |---|---|---|
    | d or i | Signed decimal integer | 392  |
    | u | Unsigned decimal integer | 7235  |
    | o | Unsigned octal | 610  |
    | x | Unsigned hexadecimal integer | 7fa  |
    | X | Unsigned hexadecimal integer (uppercase) | 7FA  |
    | f | Decimal floating point, lowercase | 392.65  |
    | F | Decimal floating point, uppercase | 392.65  |
    | e | Scientific notation (mantissa/exponent), lowercase | 3.9265e+2  |
    | E | Scientific notation (mantissa/exponent), uppercase | 3.9265E+2  |
    | g | Use the shortest representation: %e or %f | 392.65  |
    | G | Use the shortest representation: %E or %F | 392.65  |
    | a | Hexadecimal floating point, lowercase | -0xc.90fep-2  |
    | A | Hexadecimal floating point, uppercase | -0XC.90FEP-2  |
    | c | Character | a  |
    | s | String of characters | sample  |
    | p | Pointer address | b8000000  |
    | n | Nothing printed. The corresponding argument must be a pointer to a signed int. The number of characters written so far is stored in the pointed location. |  |
    |  |  |  |
    |  |   |  |

see: [https://cplusplus.com/reference/cstdio/printf/](https://cplusplus.com/reference/cstdio/printf/) for more details.

## Usage

```cpp
#include <Arduino.h>
#include <logging.h>

Logging logging;

void setup() {
  logging.begin(9600);
}

void loop() {
  LogTrace("Hello world!");
  LogDebug("Debug message for %d integers", 42);
  LogInfo("Info message for %d integers", 42);
  LogWarn("Info message for %d integers", 42);
  LogErr("This is an error message");
  delay(1000);
}
```

## Support

Tested on:

- Arduino Uno
- Expressif ESP8266

## License

MIT

## Author

[@kbeaugrand](https://github.com/kbeaugrand)
