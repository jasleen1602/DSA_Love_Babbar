string removeConsecutiveCharacter(string S)
{
    
    if (S.size() == 0)
        return "";

    char c = S[0];
    string ros = removeConsecutiveCharacter(S.substr(1));
    
    if (c == ros[0])
        return ros;
    else
        return c + ros;
}