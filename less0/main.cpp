#include <iostream>
#include<vector>
#include<array>
//Написали один метод для печати
template<class It>
void printAll(It begin, It end)
{
    for(It i = begin; i!= end; i++)
    {
        std::cout<<*i<<" ";
    }
    std::cout<<std::endl;
}
int main()
{
    const int N = 5;
    //вектор
    std::vector<int> a = {1,5,7,9,2,3};
    //массив
    std::array<int, N> b = {8,7,5,4,3};
    //обычный массив
    int c[N] ={6,4,2,5,9};
    //передаем первый итератор и следующий за последний
    printAll(a.begin(), a.end());
    printAll(b.begin(), b.end());
    //для обычных массивов это просто следующие указатели
    printAll(c, c+N);
    return 0;
}
