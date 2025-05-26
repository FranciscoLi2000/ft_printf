# 🖨️ ft_printf – Custom Implementation of printf in C

Welcome to my `ft_printf` project, developed as part of the 42 Barcelona curriculum. This project involves recreating the standard `printf` function in C, handling various format specifiers and demonstrating proficiency in variadic functions, memory management, and algorithmic problem-solving.

---

## 📁 Project Structure

ft_printf/
├── includes/
│ └── ft_printf.h # Function prototypes and structures
├── libft/
│ └── *.c # Custom standard library functions
├── srcs/
│ ├── ft_printf.c # Core ft_printf function
│ ├── print_char.c # Handles %c specifier
│ ├── print_str.c # Handles %s specifier
│ ├── print_int.c # Handles %d and %i specifiers
│ ├── print_uint.c # Handles %u specifier
│ ├── print_hex.c # Handles %x and %X specifiers
│ └── print_ptr.c # Handles %p specifier
├── en.printf.pdf # Project subject PDF
├── LICENSE # License information
└── README.md # Project documentation


---

## 🧠 Key Algorithms and Implementations

### 1. Variadic Function Handling

Utilized `<stdarg.h>` to manage functions with variable arguments. Implemented `va_start`, `va_arg`, and `va_end` to iterate through arguments dynamically, enabling the handling of an arbitrary number of inputs.

### 2. Format Specifier Parsing

Developed a parser that scans the format string, identifies format specifiers, and delegates the formatting task to the appropriate handler functions based on the specifier detected.

### 3. Number to String Conversion

Implemented custom functions to convert integers and unsigned integers to strings:

- `ft_itoa`: Converts signed integers to strings.
- `ft_utoa`: Converts unsigned integers to strings.

These functions handle edge cases, such as zero and negative numbers, ensuring accurate string representations.

### 4. Hexadecimal Conversion

Created `ft_itoa_base` to convert numbers to hexadecimal strings, supporting both lowercase (`%x`) and uppercase (`%X`) formats. This function calculates the length of the resulting string and constructs it by mapping each digit to its corresponding hexadecimal character.

### 5. Pointer Address Formatting

Implemented `ft_ptoa` to convert pointer addresses to a hexadecimal string prefixed with `0x`. This function handles null pointers by returning `(nil)`.

---

## ✅ Supported Format Specifiers

- `%c`: Character
- `%s`: String
- `%p`: Pointer address
- `%d` / `%i`: Signed decimal integer
- `%u`: Unsigned decimal integer
- `%x`: Unsigned hexadecimal integer (lowercase)
- `%X`: Unsigned hexadecimal integer (uppercase)
- `%%`: Literal percent sign

---

## 🛠️ Usage

To compile and use the `ft_printf` library:

1. **Clone the repository:**
```
	git clone https://github.com/FranciscoLi2000/ft_printf.git
	cd ft_printf
```

2. Compile the library:
```
make
```
This will generate the libftprintf.a static library.

3. Include in your project:

In your C source files, include the header:
```
#include "ft_printf.h"
```
Compile your project with the libftprintf.a library:
```
gcc your_program.c libftprintf.a -o your_program
```

## 🧪 Testing
To test the ft_printf function, you can create a simple main.c file:
```
	#include "ft_printf.h"

	int	main(void)
	{
		ft_printf("Character: %c\n", 'A');
		ft_printf("String: %s\n", "Hello, World!");
		ft_printf("Pointer: %p\n", (void *)0x12345678);
		ft_printf("Signed int: %d\n", -42);
		ft_printf("Unsigned int: %u\n", 42);
		ft_printf("Hex (lowercase): %x\n", 255);
		ft_printf("Hex (uppercase): %X\n", 255);
		ft_printf("Percent sign: %%\n");
		return (0);
	}
```
Compile and run:
```
gcc main.c libftprintf.a -o test_printf
./test_printf

```

## 📄 License
This project is licensed under the MIT License. See the LICENSE file for details.

## 🙋‍♂️ Author: yufli

Email: your.email@example.com

Feel free to explore the code, provide feedback, or contribute to the project!


---

This `README.md` provides a comprehensive overview of your `ft_printf` project, highlighting your algorithmic implementations and guiding users on how to utilize your custom `printf` function. Let me know if you'd like to add sections on advanced features, optimization techniques, or testing frameworks.
::contentReference[oaicite:0]{index=0}
 
