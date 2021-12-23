#ifndef WAREHOUSE_MAIN_H
#define WAREHOUSE_MAIN_H

void writeDataToObjects(Article *articles, int arraySize, const std::string &sourceFile);
void writeDataToFile(Article *articles, int arraySize);
char * readDataFromFile(const std::string& filePath);
char *getNextWord(std::string &result, char *ptrChar);

#endif //WAREHOUSE_MAIN_H
