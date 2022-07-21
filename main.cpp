#include <iostream>
#include <vector>

void printRow(const std::vector<int>& row)
{
    for(const auto& i : row) 
        std::cout << i << ' ';
    std::cout << '\n';
}

std::vector<int> getKthRow(const int& k)
{
    std::vector<int> lastRow;
    lastRow.push_back(1);
    std::vector<int> curRow;
    for(int i = 0; i < k-1; i++) {
        curRow.push_back(1);
        for(int j = 1; j < lastRow.size(); j++) {
            curRow.push_back(lastRow[j] + lastRow[j-1]);
        }
        curRow.push_back(1);
        lastRow = curRow;
        curRow = std::vector<int>();
    }
    return lastRow;
}

int main()
{
    std::vector<int> res = getKthRow(10);
    printRow(res);
    return 0;
}
