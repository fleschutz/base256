The Base256 Encoding based on Unicode (Base256U)
================================================
This repo contains a small C++ program to represent binary data in base256 encoding by using Unicode characters. Typical use cases are safe passwords, digital keys, file checksums, identifiers, hashes and very big numbers.

What is Base256U?
-----------------
Each byte is represented by exactly one Unicode character and vice versa each Unicode character represents exactly one byte. The mapping of Byte vs Unicode is quite simple:

| Byte       | Unicode             | Description           |
|------------|---------------------|-----------------------|
| 0 ... 9    | '0' ... '9'         | 10 digits             |
| 10 ... 35  | 'A' ... 'Z'         | 26 uppercase letters  |
| 36 ... 61  | 'a' ... 'z'         | 26 lowercase letters  |
| 62 ... 255 | 'À', 'Á', 'Â', ...  | 194 umlaut characters |

✔️ Advantages of Base256U
-------------------------
* **Ultra compact:** e.g. 16 characters like `5iŗ3īÛźUKĺŰÑÞbŒŜ` can encode 128-bit of data.
* **Easy to recognize** due to the umlaut characters.
* **Safe to use:** nearly impossible to remember, so people are forced to copy & paste it.
* **Supports double-clicking** for comfortable copy & paste (all Unicode characters are non-terminal ones).
* **Supports all Unicode versions** due to highest code point 385 (requires Unicode 1.0 or higher).
* **Easy to implement:** see the [source code in main.cpp](main.cpp)

🔧 Installation
----------------
Requires **cmake** and a **C++ compiler**. Then execute in a terminal window: 
```
> git clone https://github.com/fleschutz/base256  # or download und unzip the ZIP file (click the green button)
> cd base256
> cmake .
> make
> ./base256
```


Examples of Base256U
--------------------
* 128 bit: `ĺËĀ8Ę3ĩŔá0VzœĹŀî`, `ŽTĭŊõł3ÐÑęGųĢÛąĶ`, `5iŗ3īÛźUKĺŰÑÞbŒŜ`, `ņĨqvLŀŠsůØŸÙGCŰƀ`, `ŋôBĉOÍŬįēĳmōįUĞÜ`, `Sőś6ŬŹŠęűöìÇthTK`.
* 256 bits: `ħŅŹĬšÝŋţĀĸĻňőċqâĮŹúŪßWPŞÓā8æťÁüċ`, `Ě2ħŤRŧáÃĆĶ2ÕŀSŜöĄPŞÜbŰ06lŔùö9ĬŒģ`, `āLë2lÏäöĥųŧpğĨķŇHĺ4LăsŸđĵ_űLeYhĩ`, `ÂŚÔJàįŶļcvàPĈčĲċĉĲĂūęŻÉĢJĸķ3ğPĭŠ`


Other Encoding Standards
------------------------

| Base | Name        | Alphabet                      | Example |
|------|-------------|-------------------------------|---------|
|    2 | Bit         | 0 or 1                        | 0101101 |
|    8 | Octal       | 0-7                           | 7734124 |
|   10 | Decimal     | 0-9                           | 3849834 |
|   16 | Hexadecimal | 0-9,a-f (or A-F)              | 7a9ff34 |
|   36 | Base36      | 0-9,A-Z                       | 7RT99XQ |
|   45 | Base45      | 0-9,A-Z,space,$,%,*,+,-,.,/,: | 8X%/9:A |
|   64 | Base64      | A-Z,a-z,0-9,+,-               | zA8r+8q |


How long does it take to break a random key or password?
--------------------------------------------------------
Required is a good random generator. Then trying every possible key or password (called a 'brute force attack') at one billion attempts per second:

| Key Size | Key Example                        | Maximum Time Needed                       | 
|----------|------------------------------------|-------------------------------------------|
|  40-bit  | `ŞŰÀ8Œ`                            | about 9 minutes                           |
|  56-bit  | `ŖÔńĪ7ėñ`                          | about a year                              |
| 128-bit  | `ĤŗwĹĦñŧīĳēaqöĜĖŅ`                 | about 5,783,128,169,837,158,197,871 years |
| 256-bit  | `ÿőMêŽĖiĘśŃäŞŰÀ8ŒŽĎäPfSŖÔńiĪ7ėëŷò` | never, for all practical purposes         |

📧 Feedback
------------
Send your email feedback to: markus.fleschutz [at] gmail.com

🤝 License & Copyright
-----------------------
This open source project is licensed under the CC0 license. All trademarks are the property of their respective owners.
