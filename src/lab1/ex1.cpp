#include <iostream>
using namespace std;
 
int main()
{
    int time;
    int hours, minutes, seconds;
    
    cin >> time;
    hours = time / 3600;
    minutes = time/60 - hours*60;
    seconds = time - hours*3600 - minutes*60;
    char answer[9];
    snprintf(answer, 9, "%d:%d:%d", hours, minutes, seconds);

    cout << answer << endl;

    return 0;
}