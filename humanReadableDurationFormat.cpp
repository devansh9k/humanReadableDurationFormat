#include <string>
#include <vector>
using namespace std;

string format_duration(int seconds) {
  if (seconds == 0)
    return "now";
  int years = 0;
  int days = 0;
  int hours = 0;
  int min = 0;
  int sec = 0;
  int index = 0 , count = 0;
  string ans = "";
  string laststr = "";


  if (seconds >= 31536000) {
    years = seconds / 31536000;
    seconds = seconds - years * 31536000;
  }
  if (seconds >= 86400) {
    days = seconds / 86400;
    seconds = seconds - days * 86400;
  }
  if (seconds >= 3600) {
    hours = seconds / 3600;
    seconds = seconds - hours * 3600;
  }
  if (seconds >= 60) {
    min = seconds / 60;
    seconds = seconds - min * 60;
  }
  sec = seconds;

  vector<pair<int, string>> t;
  t.push_back(make_pair(years, "year"));
  t.push_back(make_pair(days, "day"));
  t.push_back(make_pair(hours, "hour"));
  t.push_back(make_pair(min, "minute"));
  t.push_back(make_pair(sec, "second"));

  for (int i = 0; i<5; i++) {
    if (t[i].first != 0) {
      if (t[i].first == 1) {
        index = ans.size();
        laststr = to_string(t[i].first) + " " + t[i].second + ", ";
        ans += laststr;
        count++;
      }
      else {
        index = ans.size();
        laststr = to_string(t[i].first) + " " + t[i].second + "s" + ", ";
        ans += laststr;
        count++;
      }
    }
  }
  ans.pop_back();
  ans.pop_back();
  if (count != 1) {
    ans.erase(index, laststr.size());
    ans.pop_back();
    ans.pop_back();

    for (int i = 4; i >= 0; i--) {
      if (t[i].first != 0) {
        if (t[i].first == 1) {
          ans += " and " + to_string(t[i].first) + " " + t[i].second;
        }
        else {
          ans += " and " + to_string(t[i].first) + " " + t[i].second + "s";
        }
        break;
      }
    }
  }
  return ans;
}