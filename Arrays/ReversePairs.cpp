class Solution
{
public:
    vector<int> merge(vector<int> left, vector<int> right, int &count)
    {
        int j = 0;
        for (int i = 0; i < left.size(); i++)
        {

            while (j < right.size() && left[i] > (long long)2 * right[j])
                j++;
            count += j;
            if (i == left.size() - 1)
                j = 0;
        }

        j = 0;
        int i = 0, k = 0;
        vector<int> ans(left.size() + right.size(), 0);

        while (i < left.size() && j < right.size())
        {

            if (left[i] <= right[j])
                ans[k++] = left[i++];
            else
            {
                ans[k++] = right[j++];
            };
        }
        while (i < left.size())
            ans[k++] = left[i++];
        while (j < right.size())
            ans[k++] = right[j++];

        return ans;
    }

    vector<int> ms(vector<int> nums, int &count)
    {

        if (nums.size() < 2)
            return nums;

        int mid = nums.size() / 2;

        vector<int> left;
        vector<int> right;

        for (int i = 0; i < mid; i++)
            left.push_back(nums[i]);

        for (int i = mid; i < nums.size(); i++)
            right.push_back(nums[i]);

        vector<int> leftS = ms(left, count);
        vector<int> rightS = ms(right, count);

        return merge(leftS, rightS, count);
    }

    int reversePairs(vector<int> &nums)
    {
        int count = 0;
        vector<int> ans = ms(nums, count);
        for (int num : ans)
            cout << num << " ";
        return count;
    }
};