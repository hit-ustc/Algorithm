#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


vector<int> numberSort(char str[])
{
    int len = strlen(str);
    int num =0;
    int i, j;
    vector<int> vec;

    if(len == 0)
    {
        return vec;
    }

    for(i = 0; i <= len; ++i)
    {
        if(i == len || str[i] == ',')
        {
            vec.push_back(num);
            num = 0;
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            num = num * 10 + str[i] - '0';
        }
    }

    sort(vec.begin(), vec.end());
    int vecSize = vec.size();

    int equalIndex = 0;
    for(i = 1; i <= vecSize; ++i)
    {
        if(i == vecSize || vec[i] != vec[i - 1] + 1)
        {
            for(j = equalIndex + 1; j <= i - 2; ++j)
            {
                vec[j] = -1;
            }
            equalIndex = i;
        }
    }

    return vec;
}
int main()
{

    char str[100];
    int i;
    vector<int> vec;

    cin >> str;

    vec = numberSort(str);

    for(i = 0; i < vec.size(); ++i)
    {
        if(vec[i] == -1)
        {
            continue;
        }

        if(i == 0)
        {
            cout << vec[i];
        }
        else
        {
            cout << " " << vec[i];
        }
    }

    return 0;
}