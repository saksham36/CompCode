class MyCalendarThree
{
private:
    map<int, int> diff;

public:
    MyCalendarThree()
    {
    }

    int book(int start, int end)
    {

        int curr = 0, res = 0;
        diff[start]++;
        diff[end]--;
        for (auto &[_, delta] : diff)
        {
            curr += delta;
            res = max(res, curr);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */