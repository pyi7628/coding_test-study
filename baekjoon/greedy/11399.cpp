#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    vector<int> numbers;
    int num[1002] = {0};
    int sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num = 0;

        cin >> num;
        numbers.push_back(num);
    }
    sort(numbers.begin(), numbers.end());
    num[0] = numbers[0];
    sum = num[0];
    for (int i = 1; i < N; i++)
    {
        num[i] = num[i - 1] + numbers[i];
        sum += num[i];
    }

    cout << sum << '\n';

    return 0;
}