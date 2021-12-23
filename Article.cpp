#include <iostream>
#include <utility>
#include "Article.h"

// Constructor
Article::Article(int numberOfArticles, int orderDuration, double costPrice, std::string description,
                 int maximumStock, int consumption, int articleNumber) :
        numberOfArticles(numberOfArticles),
        orderDuration(orderDuration),
        costPrice(costPrice),
        description(std::move(description)),
        stock(articleNumber, numberOfArticles, maximumStock, consumption) {}

Article::Article() {}

int Article::getArticleNumber() const {
    return stock.getArticleNumber();
}

void Article::setArticleNumber(int articleNumber) {
    stock.setArticleNumber(articleNumber);
}

int Article::getActualStock() const {
    return stock.getActualStock();
}

void Article::setActualStock(int actualStock) {
    stock.setActualStock(actualStock);
}

int Article::getMaximumStock() const {
    return stock.getMaximumStock();
}

void Article::setMaximumStock(int maximumStock) {
    stock.setMaximumStock(maximumStock);
}

int Article::getConsumption() const {
    return stock.getConsumption();
}

void Article::setConsumption(int consumption) {
    stock.setConsumption(consumption);
}

int Article::getNumberOfArticles() const {
    return numberOfArticles;
}

void Article::setNumberOfArticles(int numberOfArticles) {
    Article::numberOfArticles = numberOfArticles;
}

void Article::setOrderDuration(int orderDuration) {
    Article::orderDuration = orderDuration;
}

void Article::setCostPrice(double costPrice) {
    Article::costPrice = costPrice;
}

void Article::setDescription(const std::string &description) {
    Article::description = description;
}

int Article::getOrderDuration() const {
    return orderDuration;
}

double Article::getCostPrice() const {
    return costPrice;
}

const std::string &Article::getDescription() const {
    return description;
}

const Stock &Article::getStock() const {
    return stock;
}

void Article::setStock(const Stock &stock) {
    Article::stock = stock;
}

// Functions
void Article::toString() {

    std::cout << "No: " << getArticleNumber() << " ,Description: " << getDescription() <<
              " ,Actual Stock: " << getNumberOfArticles() << " , Maximum Stock: " << getMaximumStock() <<
              " ,Cost Price: " << getCostPrice() << " Euros" << " ,Consumption per Day: "
              << getConsumption() <<
              " ,Order Duration: " << getOrderDuration() << std::endl;
}

double Article::totalStockValue() {
    return getActualStock() * getCostPrice();
}

std::string Article::orderProposal(int resultFromOrderPoint) {
    std::string result = "Order " + std::to_string(getMaximumStock());
    if (resultFromOrderPoint > 0) {
        return result + " in " + std::to_string(resultFromOrderPoint) + " Days.";
    } else {
        return result + " immediately.";
    }
}

// Calculating the order point
int Article::orderPoint() {
    int reserve = 2;
    int result = ((getActualStock() / getConsumption())) - reserve;
    if (result > getOrderDuration()) {
        // returning how many stocks sufficient for more than the orderDuration
        return result - getOrderDuration();
    } else {
        // returning 0 which means we need to order immediately
        return 0;
    }
}

std::ostream &Article::writeToFile(std::ostream &out) {

    std::string temp;

    out << getArticleNumber() << "\t\t" <<
       getDescription() << "\t\t" <<
       getActualStock() << "\t\t" <<
       getMaximumStock() << "\t\t" <<
       getCostPrice() << "\t\t" <<
       getConsumption() << "\t\t" <<
       getOrderDuration()<< "\t\t" <<
       totalStockValue()<< "\t\t" <<
       orderPoint()<< "\t\t" <<
       orderProposal(orderPoint()) << "\t\t\n";
    return out;
}

