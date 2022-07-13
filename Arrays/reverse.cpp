string reverseWord(string str)
{
    string output = "";

    for (int i = (str.length() - 1); i >= 0; i--)
    {
        output += str[i];
    }

    return output;
}