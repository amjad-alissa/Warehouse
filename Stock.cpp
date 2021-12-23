#include "Stock.h"

// Constructors
Stock::Stock(int articleNumber, int actualStock, int maximumStock, int consumption) :
        articleNumber(articleNumber),
        actualStock(actualStock),
        maximumStock(maximumStock),
        consumption(consumption) {}

Stock::Stock() {}

// Getters
int Stock::getArticleNumber() const {
    return articleNumber;
}

int Stock::getActualStock() const {
    return actualStock;
}

int Stock::getMaximumStock() const {
    return maximumStock;
}

int Stock::getConsumption() const {
    return consumption;
}

// Setters
void Stock::setArticleNumber(int articleNumber) {
    Stock::articleNumber = articleNumber;
}

void Stock::setActualStock(int actualStock) {
    Stock::actualStock = actualStock;
}

void Stock::setMaximumStock(int maximumStock) {
    Stock::maximumStock = maximumStock;
}

void Stock::setConsumption(int consumption) {
    Stock::consumption = consumption;
}
