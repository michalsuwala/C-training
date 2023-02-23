#include <iostream>
#include <string>
#include <fstream>


struct Image{
    int width, height, bitsPerPixel;
    std::string name;
};


void add(const char *path, Image image){
    std::ofstream file;
    file.open(path, std::fstream::app);
    if(!file.good()){
        perror("Error");
        return;
    }
    file.write((char*)&image, sizeof(image));
    file.close();
}


Image *readi(const char *path){
    std::ifstream file;
    file.open(path);
    if(!file.good()){
        perror("Error");
    }
    Image *res = new Image[100];
    int i = 0;
    while(file.read((char*)&res[i], sizeof(res[0]))){
        i++;
    }
    file.close();
    return res;
}


int main(){
    Image im1;
    im1.bitsPerPixel = 24;
    im1.height = 1024;
    im1.width = 512;
    im1.name = "im1";
    Image im2;
    im2.bitsPerPixel = 24;
    im2.height = 1024;
    im2.width = 511;
    im2.name = "im2";
    Image *res;
    add("ims.txt", im1);
    add("ims.txt", im2);
    res = readi("ims.txt");
    for(int i = 0; i < 2; i++){
        std::cout << res[i].name;
    }
    delete[] res;
    return 0;
}