#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>

int main(int argc,char*argv[]){
    std::string inputfpath,outputname;
    for(int i=1;i<argc;++i){
        std::string arg=argv[i];
        if((arg=="--out"||arg=="-o")&&i+1<argc) outputname=argv[i+1],++i;
        else if(arg=="-i"&&i+1<argc) inputfpath=argv[i+1],++i;
    }
    if(inputfpath.empty()){
        std::cerr<<"dummy you didnt even put a input file"<<std::endl;
        return 1;
    }
    if(outputname.empty()) {
        std::cerr<<"whats the output name... :("<<std::endl;
        return 1;
    }
    if(outputname.size()<4||outputname.substr(outputname.size()-4)!=".bin") outputname+=".bin";
    std::ifstream inputf(inputfpath,std::ios::binary);
    if(!inputf.is_open()){
        std::cerr<<"Error: Failed to Open :("<<inputfpath<<std::endl;
        return 1;
    }
    std::ofstream output_file(outputname,std::ios::binary|std::ios::trunc);
    if(!output_file.is_open()){
        std::cerr<<"yea i just didnt feel like making the output file :("<<outputname<<std::endl;
        return 1;
    }
    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(inputf),{});
    inputf.close();
    for(size_t i=0;i<buffer.size();++i) output_file<<std::hex<<std::setw(2)<<std::setfill('0')<<static_cast<int>(buffer[i]);
    std::cout<<"Success! Saved to "<<outputname<<std::endl;
    return 0;
}
