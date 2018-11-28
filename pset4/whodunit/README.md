# Questions

## What's `stdint.h`?

`stdint.h` is a header file in the C standard library that allows programmers to write more portable code by providing a set of typedefs that specify exact-width integer types, along with the defined min and max values for each type, using macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

If you want your program to work universally in any system environments you cannot rely on using basic data types like `int` or `long long`. That is because you cannot be sure that the actual size of `int` will always be 32 bits, and `long long` will always be 64 bits. Instead, you can include `stdint.h` header file which contains the definition of new integer types. With them, you can be more specific in what you want from your integer. For example, you can use fixed-width integer type `int32_t`, which is guaranteed to have 32 bits anywhere.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1 byte in a BYTE <br/>
4 bytes in a DWORD (32 bits) <br/>
4 bytes in a LONG (32 bits) <br/>
2 bytes in a WORD (16 bits)

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes must be BM (ASCII) / 65 77 (decimal) / 42 4D (hexadecimal).

## What's the difference between `bfSize` and `biSize`?

`bfSize` is the size of the bmp file. `biSize` is the size of the structure. Both in bytes.

## What does it mean if `biHeight` is negative?

The image orientation is indicated by the `biHeight` member of the `BITMAPINFOHEADER` structure.
If `biHeight` is positive, the image is bottom-up. If `biHeight` is negative, the image is top-down.

More on https://docs.microsoft.com/en-us/windows/desktop/directshow/top-down-vs--bottom-up-dibs

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount` specifies the number of bits per pixel (bpp).

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

`fopen` might return `NULL` if it cannot find the file

## Why is the third argument to `fread` always `1` in our code?

https://reference.cs50.net/stdio/fread
https://www.reddit.com/r/cs50/comments/3krzkb/pset4_need_help_with_some_questions/
https://www.reddit.com/r/cs50/comments/3owr34/questions_about_structs/

```
fread(<buffer>, <size>, <qty>, <file pointer>)
```

The third argument of fread is the number of quantity, each one with a size of <size> bytes. Since there are only 1 `struct` variable for each type (`BITMAPFILEHEADER`, `BITMAPINFOHEADER`, and  `RGBTRIPLLE`), we are looking through each struct one at a time, going through the whole `struct ` once, so we put the third argument as 1 every time.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4
            = (4 - (3 * 3) % 4) % 4
            = 3

## What does `fseek` do?

https://reference.cs50.net/stdio/fseek
```
int fseek(FILE* fp, long int offset, int from_where);
```
Use `fseek` when you want to change the offset of the file pointer `fp`. This is an extremely useful tool. Normally, when reading in from a file, the pointer continues in one direction, from the start of the file to the end. `fseek`, however, allows you to change the location of the file pointer.

## What is `SEEK_CUR`?

If you want to change the location of the pointer `fp` from its current location, set `from_where` to `SEEK_CUR`.

## Whodunit?

It was Professor Plum with the candlestick in the library.
