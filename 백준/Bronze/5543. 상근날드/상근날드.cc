#include <iostream>
using namespace std;

int main()
{

    int burgersPrice[3];
    int drinksPrice[2];
    int cheapBurgerPrice ,cheapDrinkPrice;
    for(int i =0; i<3; i++)
    {
        cin >> burgersPrice[i];
        if(i==0)
            cheapBurgerPrice = burgersPrice[i];
        cheapBurgerPrice = burgersPrice[i] < cheapBurgerPrice ? burgersPrice[i] : cheapBurgerPrice;
    }
    for(int i =0; i<2; i++)
    {
        cin >> drinksPrice[i];
            if(i==0)
            cheapDrinkPrice = drinksPrice[i];
        cheapDrinkPrice = drinksPrice[i] < cheapDrinkPrice ? drinksPrice[i]: cheapDrinkPrice;
    }
    cout << cheapBurgerPrice + cheapDrinkPrice - 50;
    
}
