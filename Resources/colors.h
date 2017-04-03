#include <map>
#include <string>
#include <iostream>

using namespace std;


class Colors{
private:
  map<const string, int> foreground_color_map;
  map<const string, int> background_color_map;  
  int fg_color;
  int bg_color;
public:
  Colors(){

    foreground_color_map["default"] = 39;
    foreground_color_map["black"] = 30;
    foreground_color_map["red"] = 31;
    foreground_color_map["green"] = 32;
    foreground_color_map["yellow"] = 33;
    foreground_color_map["blue"] = 34;
    foreground_color_map["magenta"] = 35;
    foreground_color_map["cyan"] = 36;
    foreground_color_map["light_gray"] = 37;
    background_color_map["default"] = 49;
    background_color_map["black"] = 40;
    background_color_map["red"] = 41;
    background_color_map["green"] = 42;
    background_color_map["yellow"] = 43;
    background_color_map["blue"] = 44;
    background_color_map["magenta"] = 45;
    background_color_map["cyan"] = 46;
    background_color_map["light_gray"] = 47;
    
    fg_color = foreground_color_map["default"];
    bg_color = background_color_map["default"];    
  }
  
  
  void set_fg(string color){
    cout<<"\033[" << foreground_color_map[color] << "m";
  }
  
  void set_bg(string color){
    cout<<"\033[" << background_color_map[color] << "m";
  }
  
  void reset(){
    fg_color = foreground_color_map["default"];
    bg_color = background_color_map["default"];    
    cout<<"\033[" << foreground_color_map["default"] << "m";
    cout<<"\033[" << background_color_map["default"] << "m";
  }
  
};
