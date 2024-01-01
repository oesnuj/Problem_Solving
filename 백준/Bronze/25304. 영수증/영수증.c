#include <stdio.h>

int main()
{
    int total_price, total_quantity, item_price, item_quantity;
    int sum = 0;
    scanf("%d\n", &total_price);
    scanf("%d\n", &total_quantity);
    for (int i = 0; i < total_quantity; i++)
    {
        scanf("%d %d", &item_price, &item_quantity);
        sum += item_price * item_quantity;
    }
    if (sum == total_price)
        printf("Yes");
    else
        printf("No");
    return 0;
}