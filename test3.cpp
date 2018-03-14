#include <iostream>
#include <vector>

using namespace std;

pair<bool, int> findDuplicated1(vector<int>& vi)
{
    int i = 0;
    for(int i=0; i<vi.size(); ++i)
    {
        while(vi[i] != i)
        {
            if(vi[i] == vi[vi[i]])
                return {true, vi[i]};
            std::swap(vi[i], vi[vi[i]]);
        }
    }
    return {false, 0};

}

int findDuplicated2(const vector<int>& vi)
{
    if(vi.size() < 2)
        throw exception{};
    for(const auto& num : vi)
    {
        if(num < 1 || num > vi.size()-1)
            throw exception{};
    }
    int left = 1;
    int right = vi.size()-1;
    int mid = (left + right)/2;
    int cnt = 0;
    while(left < right)
    {
        cnt = 0;
        for(const auto& num : vi)
        {
            if(num >= left && num <= mid)
                ++cnt;
        }
        if(cnt > mid - left + 1)
        {
            right = mid;
            mid = (left + right)/2;
        }
        else
        {
            left = mid + 1;
            mid = (left + right)/2;
        }
    }
    return left; //left == mid == right;
}

int main()
{
    vector<int> vi1{2,2,2,2};
    vector<int> vi2{0,1,2,3};
    vector<int> vi3;
    pair<bool, int> rst1 = findDuplicated1(vi1), rst2 = findDuplicated1(vi2), rst3 = findDuplicated1(vi3);
    cout << rst1.first << "  " << rst1.second << endl;
    cout << rst2.first << "  " << rst2.second << endl;
    cout << rst3.first << "  " << rst3.second << endl;

    cout << "Test question2:" << endl;
    vector<int> vi4{2,3,5,4,3,2,6,7};
    vector<int> vi5{1,2,2,3,4};
    vector<int> vi6{1,2,3,4};
    vector<int> vi7;
    auto rst4 = findDuplicated2(vi4);
    cout << rst4 << endl;

    auto rst5 = findDuplicated2(vi5);
    cout << rst5 << endl;

    auto rst6 = findDuplicated2(vi6);  //抛出异常，存在大于n的数字
    cout << rst6 << endl;

    auto rst7 = findDuplicated2(vi7);  //抛出异常，数组大小小于2
    cout << rst7 << endl;
    return 0;
}