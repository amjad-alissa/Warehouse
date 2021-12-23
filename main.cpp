#include <iostream>
#include <fstream>
#include <string>
#include "Article.h"
#include "main.h"


int main() {

    // The path of the file to read data
    std::string filePathRead = "F:\\SoftwareProjects\\CLionProjects\\C++\\WareHouse\\StockFile.txt";

    // Array of Article objects
    int arraySize = 5;
    Article *articles = new Article[arraySize];


    writeDataToObjects(articles, arraySize, filePathRead);
    writeDataToFile(articles, arraySize);
    //Freeing up the memory
    delete[] articles;
    return 0;
}

// Reading the data from the file into objects
void writeDataToObjects(Article *articles, int arraySize, const std::string &sourceFile) {

    //Reading the data from the file
    char *memoryBlock = readDataFromFile(sourceFile);

    // Pointer to the first char of the file.
    // and we look for the new line character to know where ends the first line
    // which we want to ignore
    char *ptrChar = &memoryBlock[0];
    while ((*ptrChar) != '\n') {
        ++ptrChar;
    }

    // Temporary variables for intermediate computations
    std::string strTemp;
    int intTemp;
    double doubleTemp;
    for (int i = 0; i < arraySize; i++) {

        //Setting articleNumber
        ptrChar = getNextWord(strTemp, ptrChar);
        intTemp = std::stoi(strTemp);
        articles[i].setArticleNumber(intTemp);

        //Setting description
        ptrChar = getNextWord(strTemp, ptrChar);
        articles[i].setDescription(strTemp);

        //Setting both actualStock == numberOfArticles
        ptrChar = getNextWord(strTemp, ptrChar);
        intTemp = std::stoi(strTemp);
        articles[i].setActualStock(intTemp);
        articles[i].setNumberOfArticles(intTemp);

        //Setting maximumStock
        ptrChar = getNextWord(strTemp, ptrChar);
        intTemp = std::stoi(strTemp);
        articles[i].setMaximumStock(intTemp);

        //Setting costPrice
        ptrChar = getNextWord(strTemp, ptrChar);
        doubleTemp = std::stod(strTemp);
        articles[i].setCostPrice(doubleTemp);

        //Setting consumption
        ptrChar = getNextWord(strTemp, ptrChar);
        intTemp = std::stoi(strTemp);
        articles[i].setConsumption(intTemp);

        //Setting orderDuration
        ptrChar = getNextWord(strTemp, ptrChar);
        intTemp = std::stoi(strTemp);
        articles[i].setOrderDuration(intTemp);

//        articles[i].toString();
    }

    //Freeing up the memory
    delete[] memoryBlock;
    std::cout << "Data has been successfully written to the objects!" << std::endl;

}

char *getNextWord(std::string &result, char *ptrChar) {

    result = "";
    char temp;
    //Ignoring tab and new line character before extracting the first character of the word
    while ((*ptrChar) == '\n' || (*ptrChar) == '\t') {
        ++ptrChar;
    }

    // Getting the characters until there is a '\t' tap character
    while (ptrChar != nullptr && (*ptrChar) != '\t') {
        temp = *ptrChar;
        result += temp;
        ++ptrChar;
    }

    return ptrChar;
}

// Reading the data from the file into the main memory
char *readDataFromFile(const std::string &filePath) {
    // declaring and initializing input file stream object
    std::ifstream myFile;
    myFile.open(filePath, std::ios::in | std::ios::binary | std::ios::ate);

    // if opening the file was not successful
    if (!myFile.is_open()) {
        std::cout << "Error while opening the file for reading!" << std::endl;
        myFile.close();
        exit(-1);
    }

    //loading the file content into memory
    std::streampos size;
    char *memoryBlock;

    // Getting the size of the file and allocating memory for the array to store it
    size = myFile.tellg();
    memoryBlock = new char[size];

    // Re-positioning the pointer to be the beginning of the file,
    // because it was positioned at the end of the file when opening it.
    myFile.seekg(0, std::ifstream::beg);

    // Reading the content of the file and closing it
    myFile.read(memoryBlock, size);
    myFile.close();

    return memoryBlock;
}

void writeDataToFile(Article *articles, int arraySize) {

    //Calling the write data to objects(in case changes have been made to the file)

    std::string filePathWrite = "F:\\SoftwareProjects\\CLionProjects\\C++\\WareHouse\\NewStockFile.txt";

    std::ofstream destination;
    destination.open(filePathWrite, std::ios::out | std::ios::binary | std::ios_base::app);
    if (!destination.is_open()) {
        std::cout << "Error while opening the file for writing!" << std::endl;
        destination.close();
        exit(-1);
    } else {
        // This is the first line for the file(Titles of Columns )
        /*destination << "No \t\t\t" << "Description \t\t\t" << "Actual Stock \t\t\t" << "Maximum Stock \t\t\t" <<
        "Cost Price \t\t\t" << "Consumption per Day \t\t\t" << "Order Duration \t\t\t" << "Total Stock Value \t\t\t" <<
        "Order Point \t\t\t" << "Order Proposal \t\t\t\n";*/
        for (int i = 0; i < arraySize; ++i) {
            articles[i].writeToFile(destination);
        }
    }
    std::cout << "Data has been successfully written to the file!" << std::endl;
    destination.close();
}