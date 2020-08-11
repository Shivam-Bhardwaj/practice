//
// Created by shivam on 8/10/2020.
//

#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

void padding(string &x, string &y);

bool isSmaller(string x, string y) {
  // Calculate lengths of both string
  int n1 = x.length(), n2 = y.length();

  if (n1 < n2)
    return true;
  if (n2 < n1)
    return false;

  for (int i = 0; i < n1; i++)
    if (x[i] < y[i])
      return true;
    else if (x[i] > y[i])
      return false;

  return false;
}

string operator+(const string &x_, const string &y_);

string operator-(const string &x_, const string &y_) {
  string x = x_;
  string y = y_;
// Before proceeding further, make sure x 
  // is not smaller 
  if (isSmaller(x, y))
    swap(x, y);

  // Take an empty string for storing result 
  string str = "";

  // Calculate length of both string 
  int n1 = x.length(), n2 = y.length();

  // Reverse both of strings 
  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());

  int carry = 0;

  // Run loop till small string length 
  // and subtract digit of x to y 
  for (int i = 0; i < n2; i++) {
    // Do school mathematics, compute difference of 
    // current digits 

    int sub = ((x[i] - '0') - (y[i] - '0') - carry);

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
    int sub = ((x[i] - '0') - carry);

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

string operator*(const string &x, const string &y) {

  if (x.length() < 2) {
    return to_string(((stoi(x) * (stoi(y)))));
  }
  string x_0 = x;
  string y_0 = y;
  padding(x_0, y_0);
  unsigned int n = x_0.length() / 2;
  unsigned int n_ = x_0.length() - n;
  string a = x_0.substr(0, n);
  string b = x_0.substr(n, n_);
  string c = y_0.substr(0, n);
  string d = y_0.substr(n, n_);
  string z_1 = a * c;
  string z_2 = b * d;
  string z_3_1 = (a + b);
  string z_3_2 = (c + d);
  string z_3 = z_3_1 * z_3_2;
  string z_4_1 = (z_3 - z_2);
  string z_4 = z_4_1 - z_1;
  string t1 = (z_1 + string(n_ * 2, '0'));
  string t2 = (z_2);
  string t3 = (z_4 + string(n_, '0'));
  string temp_1 = t1 + t2;
  string temp = temp_1 + t3;
  return temp;
}


int main() {
  string x{"123456"};
  string y{"89"};
//  cout << "x: " << x << " y: " << y << endl;
  string a = "1234567889";
  string b = "1234567889";
  cout << a * b << endl;
//  cout << stoi(a) * stoi(b) << endl;
//  cout << to_string(1234567 * 89) << endl;

  cout << "\nsuccess";
  return 0;
}
//1524249104549916321
//1524157872549916321

//8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184
//8539734223631721465464512134855494934558531398689949919798976484418055645420643000268199666504267909544596295871952806582723184

void padding(string &x, string &y) {
  if (y.length() < x.length()) {
    y = std::string(max(x.length(), y.length()) - y.length(), '0') + y;
  } else {
    x = std::string(max(x.length(), y.length()) - x.length(), '0') + x;
  }
}

string operator+(const string &x_, const string &y_) {
  string x = x_;
  string y = y_;
  if (x.length() > y.length())
    swap(x, y);

  // Take an empty string for storing result 
  string str = "";

  // Calculate length of both string 
  int n1 = x.length(), n2 = y.length();

  // Reverse both of strings 
  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());

  int carry = 0;
  for (int i = 0; i < n1; i++) {
    // Do school mathematics, compute sum of 
    // current digits and carry 
    int sum = ((x[i] - '0') + (y[i] - '0') + carry);
    str.push_back(sum % 10 + '0');

    // Calculate carry for next step 
    carry = sum / 10;
  }

  // Add remaining digits of larger number 
  for (int i = n1; i < n2; i++) {
    int sum = ((y[i] - '0') + carry);
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
