class Solution {
public:
    void reverse(string& str) {
        int st = 0;
        int end = str.length() - 1;
        while (st < end) {
            swap(str[st], str[end]);
            st++;
            end--;
        }
    }

    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        int maxLength = max(n, m);
        int carry = 0;
        string result;

        int idx1 = n - 1;
        int idx2 = m - 1;

        while (idx1 >= 0 || idx2 >= 0 || carry) {
            int one = (idx1 >= 0) ? a[idx1] - '0' : 0;
            int two = (idx2 >= 0) ? b[idx2] - '0' : 0;

            int sum = one + two + carry;
            carry = sum / 2;
            int val = sum % 2;
            result.push_back(val + '0');

            idx1--;
            idx2--;
        }

        reverse(result);
        return result;
    }
};
