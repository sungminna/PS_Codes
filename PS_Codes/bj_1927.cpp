#include <iostream>
#include <vector>
#include<queue>
int main()
{
    int input;
    std::cin >> input;
    int tmp, cnt;
    cnt = 0;
    std::vector<int> res;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;
    for (int i = 0; i < input; i++) {
        std::cin >> tmp;
        if (tmp == 0) {
            if (minheap.size() == 0) {
                res.push_back(0);
            }
            else {
                res.push_back(minheap.top());
                minheap.pop();
            }
        }
        else {
            minheap.push(tmp);
        }
    }
    for (std::vector<int>::iterator itr = res.begin(); itr != res.end(); ++itr) {
        std::cout << *itr << '\n';
    }
}
