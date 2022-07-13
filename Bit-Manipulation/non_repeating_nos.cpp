/*
Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs 
whereas the other two number occur exactly once and are distinct. Find the other two numbers.
*/

bool set(int n, int pos)
{
    return (1 << pos) & n;
}

vector<int> singleNumber(vector<int> nums)
{

    vector<int> res;
    int n = nums[0] ^ nums[1];

    for (int i = 2; i < nums.size(); i++)
        n = n ^ nums[i];

    int temp = n;
    int pos = 0, setbit;
    while (n)
    {
        if (set(n, pos))
            break;
        pos++;
    }
    n = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (set(nums[i], pos))
            n = n ^ nums[i];
    }
    if (n < (temp ^ n))
    {
        res.push_back(n);
        res.push_back(temp ^ n);
    }
    else
    {
        res.push_back(temp ^ n);
        res.push_back(n);
    }
    return res;
}