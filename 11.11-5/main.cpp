#include <iostream>
#include <iomanip>
#include"Rectangle.h"
using namespace std;
Rectangle* sortBySelection(Rectangle rectInAndOut[], int size) {
    Rectangle* rectOut = new Rectangle[size];
    for (int i = 0; i < size - 1; i++) {
        int place = i;
        for (int j = i + 1; j < size; j++) {
            if (rectInAndOut[j].getArea() < rectInAndOut[place].getArea()) {
                place = j;
            }
        }
        *rectOut = rectInAndOut[i];
        rectInAndOut[i] = rectInAndOut[place];
        rectInAndOut[place] = *rectOut;
    }
    return rectInAndOut;
}
int main()
{
    const int arrSize = 10;
    Rectangle rectArr[arrSize];
    double width, height;

    for (int i = 0; i < arrSize; i++)
    {
        cin >> width >> height;
        rectArr[i] = Rectangle(width, height);
    }

    cout << "----- Original Array -----" << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cout << fixed << setprecision(2) << rectArr[i].getArea() << endl;
    }
    Rectangle* returnArray = sortBySelection(rectArr, arrSize);
    cout << "----- Sorted Array -----" << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cout << fixed << setprecision(2) << rectArr[i].getArea() << endl;
    }
    cout << "----- Return Sorted Array -----" << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cout << fixed << setprecision(2) << returnArray[i].getArea() << endl;
    }
}
