#include <iostream>
#include "queue_list.cpp"
using namespace std;

int josephus_sort(int array[], int size, int skips)
{

    int size2 = size;
    queue<int> queues;
    cout << "The array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ",";
        queues.enqueue(array[i]);
    }
    cout << endl;
    int temp = size;
    int counter = 0;
    int k = 0;
    while (size != 1)
    {
        int flag;
        queues.dequeue(flag);
        // if (flag == -1)
        //     continue;
        if (counter == skips - 1)
        {
            counter = 0;
            size--;
            cout << "Killing: " << flag << endl;
            k++;
        }
        else
        {
            counter++;
            array[k++] = flag;
            queues.enqueue(flag);
        }
    }
    int flag;
    queues.dequeue(flag);
    // cout << flag << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     if (array[i] == flag)
    //         return i;
    // }
    // return 0;
    return flag - 1;
}

// int main()
// {
//     cout << "Enter the number of people: ";
//     int size;
//     cin >> size;
//     int *array = new int[size];
//     for (int i = 0; i < size; i++)
//     {
//         array[i] = i + 1;
//     }
//     cout << "Enter the number of skips: ";
//     int skips;
//     cin >> skips;
//     cout<<josephus_sort(array, size, skips);
// }