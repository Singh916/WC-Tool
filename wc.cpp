#include<bits/stdc++.h>
#include<fstream>
#include<string>
#include<iostream>


using namespace std;

void cal_lines(std::ifstream &file) {
    file.clear();
    file.seekg(0,ios::beg);
    int cnt_line=0;
    std::string s;

    while(std::getline(file,s)) {
        cnt_line++;
    }    
    
    std::cout << "Number of lines: " << cnt_line << std::endl;
}

void cal_words(std::ifstream &file) {
    file.clear();  
    file.seekg(0,ios::beg);
    char ch;
    std::string st;
   
    int words=0;

    while(file>>st) {
       words++;
    }   
    
    cout<<"Total number of words are "<<words<<endl;
}

void cal_bytes(std::ifstream &file) {
    file.clear();
    file.seekg(0, std::ios::end); // Move to the end of the file
    std::streampos fileSize = file.tellg(); // Get the file size
    file.seekg(0, std::ios::beg); // Move back to the beginning of the file
    
     if (fileSize < 0) {
        std::cerr << "Error getting file size." << std::endl;
        return ;
    }

    std::cout << "File size: " << fileSize << " bytes" << std::endl;

}

void cal_char(std::ifstream &file) {
    file.clear();
    file.seekg(0,std::ios::beg);
    
    int count_char=0;        
    char ch;

    while(file.get(ch)) {
        count_char++;
    }

    cout<<"Total number of characters "<<count_char<<endl;
}

int main(int argc, char* argv[]) {
    
    if(argc == 1) {
       std::cerr << "Invalid number of arguments" << std::endl;
       return 1;
    }

    else if (argc == 2 ) {
        std::ifstream file(argv[1], std::ios::binary);
        file.seekg(0,std::ios::beg);
        cal_bytes(file);
        cal_lines(file);
        cal_words(file);
    }

    else if(argc == 3) {
        std::ifstream file(argv[2], std::ios::binary);
        
        if (!file.is_open()) {
            std::cerr << "Error opening the file." << std::endl;
            return 1;
        }

        file.clear();
        file.seekg(0,std::ios::beg);

        if(std::strcmp(argv[1],"-c") == 0) {
            cal_bytes(file);
        }
        else if(std::strcmp(argv[1],"-l") == 0) {
            cal_lines(file);
        }
        else if(std::strcmp(argv[1],"-w") == 0) {
            cal_words(file); 
        }
        else {
            cal_char(file);
        }
    }

    // std::ifstream file(argv[2], std::ios::binary);      

    // if (!file.is_open()) {
    //     std::cerr << "Error opening the file." << std::endl;
    //     return 1;
    // }


    // if (std::strcmp(argv[1], "-c") != 0 ) {
    //     std::cerr << "Invalid option. Use -c to count bytes." << std::endl;
    //     return 1;
    // }

    

    // if (std::strcmp(argv[1], "-l") != 0 ) {
    //     std::cerr << "Invalid option. Use -l to count lines." << std::endl;
    //     return 1;
    // }
    
    
    
    // if(std::strcmp(argv[1],"-w") != 0) {
    //     std::cerr<<"Invalid option. Use -w to count words." << std::endl;
    //     return 1;
    // }

    
    
    
    // if(std::strcmp(argv[1],"-m") != 0) {
    //     std::cerr<<"Invalid option. Use -m to count total characters." << std::endl;
    //     return 1;
    // }  

    
    // file.close(); 
    
  

    return 0;
}


