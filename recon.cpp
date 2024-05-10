#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>

void tobinary(const std::string& hytes, std::vector<unsigned char>& BDATA) {
    BDATA.clear();
    for (size_t i = 0; i < hytes.length(); i += 2)
        BDATA.push_back(static_cast<unsigned char>(std::stoul(hytes.substr(i, 2), nullptr, 16)));
}

int main(int argc, char* argv[]) {
    if (argc != 3 || std::string(argv[1]) != "-i") {
        std::cerr << "Usage: ./file.exe -i <input_bin>" << std::endl;
        return 1;
    }
    std::ifstream inputf(argv[2], std::ios::binary);
    std::string HREP;
    std::getline(inputf, HREP);
    inputf.close();
    std::vector<unsigned char> BDATA;
    tobinary(HREP, BDATA);
    std::ofstream("remade.exe", std::ios::binary | std::ios::trunc).write(reinterpret_cast<char*>(BDATA.data()), BDATA.size());
    std::system("remade.exe");
    return 0;
}
