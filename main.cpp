#include <iostream>

using namespace std;

int Continuous_knapsack(int W, int n)
{
    double W1, price1, eff1;  //объём предмета, цена предмета, эффективность предмета (цена единицы объема)
    double price_all, W_all;  //цена и объем предметов в рюкзаке
    double arr_W[n], arr_price[n], arr_eff[n];    //массивы объёмов, цен и эффективности
    int arr_sort[n];  //массив с порядком сортировки
    double arr_temp[n];
    double part1;  //часть предмета

    for (int i = 0; i < n; i++)
    {
        cin >> W1 >> price1;
        eff1 = price1/W1;
        arr_W[i] = W1;
        arr_price[i] = price1;
        arr_eff[i] = eff1;

        //сортировка вставкой
        int j;
        for (j = i - 1; j >= 0 && arr_temp[j] < eff1; j--)  // поиск места элемента в готовой последовательности
        {
            arr_temp[j+1] = arr_temp[j];  // сдвигаем элемент направо, пока не дошли (сортируем временный массив)
            arr_sort[j+1] = arr_sort[j];  // запоминаем новый порядок сортировки
        }

        arr_temp[j + 1] = eff1; // место найдено, вставить элемент (или i == 0)
        arr_sort[j + 1] = i;    // запоминаем новый порядок сортировки
    }

    price_all = 0;
    W_all = 0;
    double temp;
    //заполняем рюкзак
    for (int i = 0; i < n; i++)
    {
        if (W_all + arr_W[arr_sort[i]] <= W)    //с учетом новой сортирвки по убыванию эффективность предмета (цена единицы объема)
        {
            price_all += arr_price[arr_sort[i]];
            W_all += arr_W[arr_sort[i]];
            arr_temp[arr_sort[i]] = 1.0;  //запомним долю предмета во временном массиве
        }
        else
        {   //не влезло
            part1 = (W - W_all) / arr_W[arr_sort[i]]; //часть предмета
            price_all += part1 * arr_price[arr_sort[i]];
            W_all += part1 * arr_W[arr_sort[i]];
            arr_temp[arr_sort[i]] = part1;  //запомним долю предмета во временном массиве
        }
    }
    
    //выводим доли
    for (int i = 0; i < n; i++)
    {
        cout << arr_temp[i] << " ";
    }
    cout << endl;

    return price_all;
}

int main()
{
    int W, n;  //объём рюкзака и число предметов
    cin >> W >> n;

    cout << Continuous_knapsack(W, n) << endl;

    return 0;
}
