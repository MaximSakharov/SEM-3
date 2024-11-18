#include <iostream>

using namespace std;

class String
{
private:
   char* str;
   int len;
   int my_strlen(char* str_)
   {
      int new_size = 0;
      while (*str_ != '\0')
      {
         ++str_;
         ++new_size;
      }
      return new_size;
   }
public:
   String(char* str_ = nullptr) 
   {
      if (str_) {
         len = my_strlen(str_);
      }
      else {
         len = 0;
      }
      str = new char[len + 1];
      for (int i = 0; i < len; ++i)
         str[i] = str_[i];
      str[len] = '\0';
   }
   String(const String& other_)
   {
      delete[] str;
      len = other_.len;
      str = new char[len + 1];
      for (int i = 0; i < len; ++i)
         str[i] = other_.str[i];
      str[len] = '\0';
   }
   ~String()
   {
      delete[] str;
   }
   String& operator=(const String& other_)
   {
      if (this == &other_)
         return *this;

      delete[] str;
      len = other_.len;
      str = new char[len + 1];
      for (int i = 0; i < len; ++i)
         str[i] = other_.str[i];
      str[len] = '\0';

      return *this;
   }
   char& operator[](int i) const 
   {
      if (i < 0 || i >= len) {
         throw std::out_of_range("Index out of range");
      }
      return str[i];
   }

   char& operator[](int i)
   {
      if (i < 0 || i >= len) 
         throw std::out_of_range("Index out of range");
      return str[i];
   }
   String operator+(const String& other_)
   {
      String new_str;
      new_str.len = len + other_.len;  
      new_str.str = new char[new_str.len + 1];  

      for (int i = 0; i < len; ++i) 
         new_str.str[i] = str[i];
      for (int i = 0; i < other_.len; ++i)
         new_str.str[len + i] = other_.str[i];

      new_str.str[new_str.len] = '\0';

      return new_str;
   }
   int StrLen()
   {
      return len;
   }
   bool operator==(const String& other_)
   {
      if (len != other_.len)
         return false;
      for (int i = 0; i < len + 1; ++i)
         if (str[i] != other_.str[i])
            return false;

      return true;
   }
   bool operator!=(const String& other_)
   {
      return !(*this == other_);
   }
   bool operator<=(const String& other_) const
   {
      int i;

      for (i = 0; str[i] && str[i] == other_[i]; ++i);

      int res = str[i] - other_[i];
      if (res > 0)
         return false;
      else
         return true;
   }

   bool operator>=(const String& other_) const
   {
      int i;

      for (i = 0; str[i] && str[i] == other_[i]; ++i);

      int res = str[i] - other_[i];
      if (res < 0)
         return false;
      else
         return true;
   }

   bool operator<(const String& other_) const
   {
      return !(*this >= other_);
   }

   bool operator>(const String& other_) const
   {
      return !(*this <= other_);
   }

   friend ostream& operator<<(ostream& out, const String& string);

   friend istream& operator>>(istream& in, String& string);
};

ostream& operator<<(ostream& out, const String& string)
{
   out << string.len << " ";

   for (int i = 0; i < string.len; ++i)
      out << string.str[i];

   return out;
}

istream& operator>>(istream& in, String& string)
{
   int value;
   char ch;

   in >> value;
   if (!in.good() || value < 0)
      throw std::invalid_argument("Invalid string length");

   delete[] string.str;
   string.len = value;
   string.str = new char[value + 1];

   in.ignore();

   for (int i = 0; i < value; ++i) 
   {
      in.get(ch);
      if (!in.good())
         throw std::invalid_argument("Invalid character input");
      string.str[i] = ch;
   }

   string.str[value] = '\0';

   return in;
}

int main() {
   char str1_[] = "Hello ";
   char str2_[] = "World";

   String str1(str1_);
   String str2(str2_);

   cout << "str1: " << str1 << endl;
   cout << "str2: " << str2 << endl;

   String str3 = str1 + str2;
   cout << "str1 + str2: " << str3 << endl;

   if (str1 == str2)
      cout << "str1 == str2" << endl;
   else
      cout << "str1 != str2" << endl;

   cout << (str1 == str2) << " " << (str1 != str2) << " " << (str1 <= str2) << " " << (str1 >= str2) << " " << (str1 < str2) << " " << (str1 > str2) << endl;

   String str4;
   str4 = str1;
   cout << "str4 (after assignment from str1): " << str4 << endl;

   try {
      cout << "str1[0]: " << str1[0] << endl;  // Ожидается 'H'
      cout << "str2[4]: " << str2[4] << endl;  // Ожидается 'd'
   }
   catch (const std::out_of_range& e) {
      cout << "Error: " << e.what() << endl;
   }

   String str5;
   cout << "Enter a string length followed by the string itself:" << endl;
   cin >> str5;
   cout << "You entered: " << str5 << endl;

   return 0;
}