#include <iostream>
#include <thread>
#include <map>
#include<string>
#include <chrono>
using namespace std::chrono_literals;

void RefreshForecase (std::map<std::string,int> forecastMap) {
    while(true){
        for(auto& item : forecastMap){
            item.second++;
            std::cout << item.first << " - " << item.second << std::endl;
        }
        std::cout << std::endl;
        std::this_thread::sleep_for(500ms);
    }
}

int main () 
{
    std::map<std::string,int> forecastMap = {
        {"New York", 16},
        {"Mumbai",20},
        {"Berlin",18}
    };
    std::thread bgWorker(RefreshForecase,forecastMap);
    if(bgWorker.joinable()){
        bgWorker.join();
    }

    system("pause>nul");
}