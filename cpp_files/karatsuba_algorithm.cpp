//
// Created by shivam on 7/12/2020.
//
#include "iostream"
#include <bits/stdc++.h>
#include "vector"


using namespace std;

string first_half(const string &s);

string second_half(const string &s);

string operator+(string a, string b);

// Returns true if a is smaller than b.
bool is_smaller(string a, string b);

string operator-(string a, string b);

string add_zero_square(std::size_t n, std::string z_2);

string add_zero(std::size_t n, std::string z_1) {
    for (int i = 0; i < n; ++i) {
        z_1.push_back('0');
    }
    return z_1;
}

string multiply(const string &n1, const string &n2) {

    size_t n{0};
    if (n1.size() / 2) {
        n = (n1.size() / 2);
    } else {
        n = (n1.size() / 2) + 1;
    }
    if (n < 2) {
        return to_string(((stoi(n1) * (stoi(n2)))));
    }

    string a = first_half(n1);
    string b = second_half(n1);
    string c = first_half(n2);
    string d = second_half(n2);

    string z_2 = multiply(a, c);
    string z_0 = multiply(b, d);
    string z_1 = multiply((a + b), (c + d)) - z_0 - z_2;
    return add_zero_square(n, z_2) + add_zero(n, z_1) + z_0;
}

int main() {
    cout << multiply("12345",
            "05678") << endl;

//    cout << multiply("12774", "5678") << endl;
    cout << to_string(12345 * 5678) << endl;

    cout << "success";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

string operator-(string a, string b) {
    // Before proceeding further, make sure a
    // is not smaller
    if (is_smaller(a, b))
        swap(a, b);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = a.length(), n2 = b.length();

    // Reverse both of strings
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int carry = 0;

    // Run loop till small string length
    // and subtract digit of a to b
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of
        // current digits

        int sub = ((a[i] - '0') - (b[i] - '0') - carry);

        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((a[i] - '0') - carry);

        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else
            carry = 0;

        str.push_back(sub + '0');
    }

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

string first_half(const string &s) {
    return s.substr(0, (s.size() / 2));
}

string operator+(string a, string b) {
// Before proceeding further, make sure length
    // of b is larger.
    if (a.length() > b.length())
        swap(a, b);

    // Take an empty string for storing result
    string str;

    // Calculate length of both string
    int n1 = a.length(), n2 = b.length();

    // Reverse both of strings
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int carry = 0;
    for (int i = 0; i < n1; i++) {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((a[i] - '0') + (b[i] - '0') + carry);
        str.push_back(sum % 10 + '0');

        // Calculate carry for next step
        carry = sum / 10;
    }

    // Add remaining digits of larger number
    for (int i = n1; i < n2; i++) {
        int sum = ((b[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry + '0');

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

bool is_smaller(string a, string b) {
    // Calculate lengths of both string
    int n1 = a.length(), n2 = b.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
        if (a[i] < b[i])
            return true;
        else if (a[i] > b[i])
            return false;

    return false;
}

string second_half(const string &s) {
    return s.substr((s.size() / 2), (s.size() - 1));
}

string add_zero_square(std::size_t n, std::string z_2) {
    for (int i = 0; i < 2 * n; ++i) {
        z_2.push_back('0');
    }
    return z_2;
}
