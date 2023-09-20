#include<bits/stdc++.h>
#include<fstream>
#include<string>
#include<iostream>


using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " -c <filename>" << std::endl;
        return 1;
    }

    // if (std::strcmp(argv[1], "-c") != 0 ) {
    //     std::cerr << "Invalid option. Use -c to count bytes." << std::endl;
    //     return 1;
    // }

    if (std::strcmp(argv[1], "-l") != 0 ) {
        std::cerr << "Invalid option. Use -c to count bytes." << std::endl;
        return 1;
    }

    std::ifstream file(argv[2], std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    // file.seekg(0, std::ios::end); // Move to the end of the file
    // std::streampos fileSize = file.tellg(); // Get the file size
    // file.seekg(0, std::ios::beg); // Move back to the beginning of the file
    
    int cnt=0;
    std::string s;

    while(std::getline(file,s)) {
        cnt++;
    }

    // if (fileSize < 0) {
    //     std::cerr << "Error getting file size." << std::endl;
    //     return 1;
    // }

    // std::cout << "File size: " << fileSize << " bytes" << std::endl;
    
    std::cout << "Number of Words: " << cnt << std::endl;

    file.close();

    return 0;
}


