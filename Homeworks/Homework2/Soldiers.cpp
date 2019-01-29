#include <iostream>
#include<vector>

long long mergeSort(int sequence[], int temp[], int left, int right);
long long merge(int sequence[], int temp[], int left, int middle, int right);
long long mSort(int sequence[], int size);
void Input(int n,int q, std::vector<long long> &countInversion);
void Print(std::vector<long long> &countInversion);

int main()
{
    int q;
    int n;
    std::cin >> q >> n;

    std::vector<long long> countInversion;
    Input(n,q,countInversion);
    Print(countInversion);
    
    return 0;
}

long long mergeSort(int sequence[], int temp[], int left, int right)
{
    int middle = 0;
    long long inversionCount = 0;
    if (right > left)
    {
        middle = (right + left) / 2;
        inversionCount = mergeSort(sequence, temp, left, middle);
        inversionCount += mergeSort(sequence, temp, middle + 1, right);
        inversionCount += merge(sequence, temp, left, middle + 1, right);
    }
    return inversionCount;
}

long long merge(int sequence[], int temp[], int left, int middle, int right)
{
    int i = left;
    int j = middle;
    int k = left;
    long long inversionCount = 0;

    while ((i <= middle - 1) && (j <= right))
    {
        if (sequence[i] <= sequence[j])
        {
            temp[k] = sequence[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = sequence[j];
            k++;
            j++;
            inversionCount = inversionCount + (middle - i);
        }
    }
    while (i <= middle - 1)
    {
        temp[k] = sequence[i];
        k++;
        i++;
    }
    while (j <= right)
    {
        temp[k] = sequence[j];
        k++;
        j++;
    }
    for (i = left; i <= right; i++)
    {
        sequence[i] = temp[i];
    }
    return inversionCount;
}

long long mSort(int sequence[], int size)
{
    int*temp = (int*)malloc(sizeof(int) * size);
    return mergeSort(sequence, temp, 0, size - 1);
}

void Input(int n,int q, std::vector<long long> &countInversion)
{
    int count = 0;
    int h;
    int* arr;
    while (count < q)
    {
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            std::cin >> h;
            arr[i] = h;
        }
        countInversion.push_back(mSort(arr, n));
        delete[] arr;
        count++;
        if (count < q)
        {
            std::cin >> n;
        }
    }
}

void Print(std::vector<long long> &countInversion)
{
    for (int i = 0; i < countInversion.size(); i++)
    {
        std::cout << countInversion[i] << std::endl;
    }
}