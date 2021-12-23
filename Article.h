#ifndef WAREHOUSE_ARTICLE_H
#define WAREHOUSE_ARTICLE_H

#include <string>
#include "Stock.h"

class Article : public std::error_code {
private:
    // Attributes for Article
    int numberOfArticles;
    int orderDuration;
    double costPrice;
    std::string description;

    // Stock declaration
    Stock stock;


public:
    // Constructors and Destructor
    Article(int numberOfArticles, int orderDuration, double costPrice, std::string description,
            int maximumStock, int consumption, int articleNumber);

    const Stock &getStock() const;

    void setStock(const Stock &stock);

    Article();

    // Getters
    int getNumberOfArticles() const;

    int getOrderDuration() const;

    double getCostPrice() const;

    const std::string &getDescription() const;

    int getMaximumStock() const;

    int getConsumption() const;

    int getArticleNumber() const;

    int getActualStock() const;

    // Setters
    void setNumberOfArticles(int numberOfArticles);

    void setOrderDuration(int orderDuration);

    void setCostPrice(double costPrice);

    void setDescription(const std::string &description);

    void setActualStock(int actualStock);

    void setConsumption(int consumption);

    void setMaximumStock(int maximumStock);

    void setArticleNumber(int articleNumber);

    //Functions
    void toString();

    double totalStockValue();

    std::string orderProposal(int resultFromOrderPoint);

    int orderPoint();

    std::ostream &writeToFile(std::ostream &out);
};


#endif //WAREHOUSE_ARTICLE_H
