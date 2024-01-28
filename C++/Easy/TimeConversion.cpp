#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) 
{
    // Divide the given string into 3 parts consist of hour,minute,second and the type of the time (AM or PM)
    int gio = stoi(s.substr(0,2));
    int phut = stoi(s.substr(3,2));
    int giay = stoi(s.substr(6,2));
    string Type_time = s.substr(8,2);

    // Set the time if it is AM and it is 12 then change it into 0 and if it is lower than 12 -> nothing happening.
    if (Type_time == "AM" && gio == 12)
        gio = 0;

    // Set the time if it is PM and it is lower than 12, we just need to plus 12 to become the time in 24 hours;
    if (Type_time == "PM" && gio != 12)
        gio += 12;
    
    //Standardize the string become to true form result
    string hour = (gio<10)?"0"+to_string(gio):to_string(gio);  // if it is upper than 10 then we need to add 0 to become the form 0x
    string minute = (phut<10)?"0"+to_string(phut):to_string(phut);  //Same the idea with hour
    string second = (giay<10)?"0"+to_string(giay):to_string(giay);  //Same the idea with hour

    //Create a new string to save the result then return it.
    string ketqua = hour +":" +minute+":"+second;
    //cout << new_string;
    return ketqua;
}

int main()
{
    string h;
    cin >> h;
    cout << timeConversion(h);
    return 0;
}
