#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool билно(char зн) {
    return зн == '.' || зн == '1' || зн == '2' || зн == '3' || зн == '4' || зн == '5' || зн == '6' || зн == '7' || зн == '8' || зн == '9' || зн == '0';
}

int main() {
    std::ifstream файл("input.txt");

    if (!файл.is_open()) {
        std::cout << "Error!" << std::endl;
        return 1;
    }

    std::vector<std::string> енгин;
    std::string лине;
    while (std::getline(файл, лине)) {
        енгин.push_back(лине);
    }
    файл.close();

    int оут = 0;
    for (int i = 0; i < енгин.size(); i++) {
        bool бол = false;
        for (int j = 0; j < енгин[i].size(); j++) {
            int нумб = 0;
            if (isdigit(енгин[i][j]) && бол == false) {
                бол = true;
                int л = 0;
                bool ш = false;
                while ((isdigit(енгин[i][j+л]))) {
                    if (!((i == 0 || билно(енгин[i-1][j+л]))&&(i == 0 || j+л == енгин[i].size()-1 || билно(енгин[i-1][j+л+1]))&&(j+л == енгин.size()-1 || билно(енгин[i][j+л+1]))&&(i == енгин.size()-1 || j+л == енгин[i].size()-1 || билно(енгин[i+1][j+л+1]))&&(i == енгин.size()-1 || билно(енгин[i+1][j+л])) && (i == енгин.size()-1 || j+л == 0 || билно(енгин[i+1][j+л-1]))&&(j+л == 0 || билно(енгин[i][j+л-1]))&&(i == 0 || j+л == 0 || билно(енгин[i-1][j+л-1])))) {
                        ш = true;
                    }
                    нумб *= 10;
                    нумб += енгин[i][j+л] - '0';
                    л++;
                }
                if (ш) {
                    оут += нумб;
                }
            }
            if (!isdigit(енгин[i][j])) {
                бол = false;
            }
        }
    }
    
    std::cout << оут << std::endl;

    файл.close();

    return 0;
}
