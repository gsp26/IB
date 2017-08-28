/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"
*/

string Solution::fractionToDecimal(int numerator, int denominator) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if (numerator == 0)
        return "0";
    int64_t n = numerator, d = denominator;
    string res = "";
    
    if (n < 0 ^ d < 0)      //Brilliant
        res += '-';
    
    n = abs(n), d = abs(d);
    
    res += to_string(n/d);
    int64_t rem = n%d;
    
    if (rem == 0)
        return res;
    
    res += '.';
    
    unordered_map<int, int> m;
    
    for (; rem; rem %= d)
    {
        if (m.find(rem) != m.end())
        {
            res.insert(m[rem], 1, '(');
            res.push_back(')');
            break;
        }
        
        m[rem] = res.size();
        rem *= 10;
        res.push_back('0' + rem/d);
    }
    return res;
}
