#include <iostream>
#include <vector>
int main()
{   
    int input;
    std::cin >> input;
    int tmp;

    std::vector<int> vec;
    for (int i = 0; i < input; i++) {
        std::cin >> tmp;
        vec.push_back(tmp);
    }
    int sum;
    int imax;
    imax = -10001;
    for (int i = 0; i < input; i++) {
        sum = 0;
        for (int j = i; j < input; j++) {
            sum += vec[j];
            if (sum > imax) {
                imax = sum;
            }
        }
    }
    std::cout << imax <<'\n';
}
