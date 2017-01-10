#include <iostream>

using namespace std;

int Continuous_knapsack(int W, int n)
{
    double W1, price1, eff1;  //����� ��������, ���� ��������, ������������� �������� (���� ������� ������)
    double price_all, W_all;  //���� � ����� ��������� � �������
    double arr_W[n], arr_price[n], arr_eff[n];    //������� �������, ��� � �������������
    int arr_sort[n];  //������ � �������� ����������
    double arr_temp[n];
    double part1;  //����� ��������

    for (int i = 0; i < n; i++)
    {
        cin >> W1 >> price1;
        eff1 = price1/W1;
        arr_W[i] = W1;
        arr_price[i] = price1;
        arr_eff[i] = eff1;

        //���������� ��������
        int j;
        for (j = i - 1; j >= 0 && arr_temp[j] < eff1; j--)  // ����� ����� �������� � ������� ������������������
        {
            arr_temp[j+1] = arr_temp[j];  // �������� ������� �������, ���� �� �����
            arr_sort[j+1] = arr_sort[j];
        }

        arr_temp[j + 1] = eff1; // ����� �������, �������� ������� (��� i == 0)
        arr_sort[j + 1] = i;
    }

    price_all = 0;
    W_all = 0;
    double temp;
    for (int i = 0; i < n; i++)
    {
        if (W_all + arr_W[arr_sort[i]] <= W)
        {
            price_all += arr_price[arr_sort[i]];
            W_all += arr_W[arr_sort[i]];
            arr_temp[arr_sort[i]] = 1.0;  //�������� ���� ��������
        }
        else
        {
            part1 = (W - W_all) / arr_W[arr_sort[i]];
            price_all += part1 * arr_price[arr_sort[i]];
            W_all += part1 * arr_W[arr_sort[i]];
            arr_temp[arr_sort[i]] = part1;  //�������� ���� ��������
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr_temp[i] << " ";
    }
    cout << endl;

    return price_all;
}

int main()
{
    int W, n;  //����� ������� � ����� ���������
    cin >> W >> n;

    cout << Continuous_knapsack(W, n) << endl;

    return 0;
}
