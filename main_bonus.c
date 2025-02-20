#include <stdio.h>
#include "ft_printf_bonus.h"

int main(void)
{
    int num = 42;
    char *str = "Hello";
    int neg_num = -123;
    int width = 10;
    int precision = 4;

    // Pruebas con números enteros
    printf("\n--- TESTS CON NÚMEROS ENTEROS ---\n");
    ft_printf("1. |%d|\n", num);
    ft_printf("2. |%10d|\n", num);  // Width
    ft_printf("3. |%-10d|\n", num); // Left align
    ft_printf("4. |%010d|\n", num); // Zero padding
    ft_printf("5. |%.5d|\n", num);  // Precision
    ft_printf("6. |%+d|\n", num);   // Plus flag
    ft_printf("7. |% d|\n", num);   // Space flag
    ft_printf("8. |%+d|\n", neg_num); // Negative number with +
    ft_printf("9. |%10.3d|\n", num);  // Width + Precision
    ft_printf("10. |%*.*d|\n", width, precision, num); // Variable width & precision
    // Pruebas con cadenas de texto
    printf("\n--- TESTS CON STRINGS ---\n");
    ft_printf("11. |%s|\n", str);
    ft_printf("12. |%20s|\n", str);  // Width
    ft_printf("13. |%-20s|\n", str); // Left align
    ft_printf("14. |%.3s|\n", str);  // Precision
    ft_printf("15. |%*.*s|\n", width, precision, str); // Variable width & precision
    // Pruebas con hexadecimales
    printf("\n--- TESTS CON HEXADECIMALES ---\n");
    ft_printf("16. |%x|\n", num);
    ft_printf("17. |%#x|\n", num); // Hash flag (prefijo 0x)
    ft_printf("18. |%X|\n", num);  // Mayúsculas
    ft_printf("19. |%#X|\n", num); // Mayúsculas con #
    // Pruebas con punteros
    printf("\n--- TESTS CON PUNTEROS ---\n");
    ft_printf("20. |%p|\n", str);
    ft_printf("21. |%20p|\n", str); // Width
    ft_printf("22. |%-20p|\n", str); // Left align
    // Pruebas con caracteres
    printf("\n--- TESTS CON CARACTERES ---\n");
    ft_printf("23. |%c|\n", 'A');
    ft_printf("24. |%5c|\n", 'A'); // Width
    ft_printf("25. |%-5c|\n", 'A'); // Left align
    // Pruebas con unsigned
    printf("\n--- TESTS CON UNSIGNED ---\n");
    ft_printf("26. |%u|\n", num);
    ft_printf("27. |%10u|\n", num);  // Width
    ft_printf("28. |%-10u|\n", num); // Left align
    ft_printf("29. |%.5u|\n", num);  // Precision
    ft_printf("30. |%*.*u|\n", width, precision, num); // Variable width & precision

    return (0);
}
