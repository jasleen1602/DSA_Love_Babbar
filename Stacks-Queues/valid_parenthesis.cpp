class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> temp;
        int i = 0;

        if (s.length() % 2 != 0)
            return false;

        while (i != s.length())
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                temp.push(s[i]);

            else if (temp.empty())
                return false;

            else if (s[i] == '}')
            {
                if (temp.top() == '{')
                    temp.pop();
                else
                    return false;
            }

            else if (s[i] == ']')
            {
                if (temp.top() == '[')
                    temp.pop();
                else
                    return false;
            }

            else if (s[i] == ')')
            {
                if (temp.top() == '(')
                    temp.pop();
                else
                    return false;
            }

            else
                return false;
            i++;
        }

        return temp.empty();
    }
};